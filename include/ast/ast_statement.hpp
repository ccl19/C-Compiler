#ifndef ast_statement_hpp
#define ast_statement_hpp
#include "ast_node.hpp"

#include <string>
#include <iostream>
#include <math.h>
#include <vector>


class ReturnStatement
    :public translation_unit
{
private:
    Node* arg;

public:
    virtual ~ReturnStatement(){
        delete arg;
    }

    ReturnStatement(Node* _arg)
        :arg(_arg)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        if (arg != NULL){
            dst << "#RETURN" << std::endl;
            arg -> Compile(dst, program, destination);
            
            if (program.swcase){
                dst << "b RETURN1" << std::endl;
                dst << "nop" << std::endl;
            }


            else{
                dst << "#RETURN" << std::endl;
                
                dst << "move $sp, $fp" << std::endl;
                if (program.returnCall){
                    dst << "lw $31, " << program.callPointer << "($sp)" << std::endl;
                }
                int frameOffset = program.returnStack - 4;
                dst << "lw $fp, " << frameOffset << "($sp)" << std::endl;
                dst << "addiu $sp, $sp, " << program.returnStack << std::endl;
                dst << "jr $31" << std::endl;
                dst << "nop" << std::endl;
            }
        }
        program.returnCall = false;
    }
};

class CompoundStatement
    :public translation_unit
{
public:
    Node* arg;
    std::vector <Node*> statement;

    virtual ~CompoundStatement (){
        for (int i = 0; i < statement.size(); i++){
            delete statement.at(i);
        }
    }

    CompoundStatement(Node* _arg)
        :arg(_arg)
    {
        statement.push_back(arg);
    }

    CompoundStatement *AddStatement(Node* arg){
        statement.push_back(arg);
        return this;
    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        for(int i=0; i<statement.size(); i++){
            statement[i] -> Compile(dst, program, destination);
        }
    }
};

class IfElseStatement
    :public translation_unit
{
public:
    Node* arg;
    CompoundStatement* ifstatlist;
    CompoundStatement* elsestatlist;

    virtual ~IfElseStatement (){
        delete arg;
        delete ifstatlist;
        delete elsestatlist;
    }

    IfElseStatement(Node* _arg, CompoundStatement* _ifstatlist, CompoundStatement* _elsestatlist)
        :arg(_arg), ifstatlist(_ifstatlist), elsestatlist(_elsestatlist)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        if (arg != NULL){
            std::string ELSE = "ELSE" + makeUniqLabel();
            std::string ENDIF = "ENDIF" + makeUniqLabel();


            arg -> Compile(dst, program, destination); //destination is a mem location that stores arg value
            dst << "lw $t0, " << destination << "($sp)" << std::endl;
            if (elsestatlist != NULL){
                dst << "beq $t0, $0, " << ELSE << std::endl;
            }
            else {
                dst << "beq $t0, $0, " << ENDIF << std::endl;
            }
            dst << "nop" <<std::endl;

            ifstatlist -> Compile(dst, program, destination);
            dst << "j " << ENDIF << std::endl;
            dst << "nop" <<std::endl;
            
            if (elsestatlist != NULL){
                dst << ELSE << ": " << std::endl;
                elsestatlist -> Compile(dst, program, destination);
                dst << "nop" <<std::endl;
            }
            dst << ENDIF << ": " <<std::endl;
        }
    }
};

class WhileStatement
    :public translation_unit
{
public:
    Node* arg;
    CompoundStatement* statlist;  
    bool hasdo;  


    virtual ~WhileStatement (){
        delete arg;
        delete statlist;
    }

    WhileStatement(Node* _arg, CompoundStatement* _statlist, bool _hasdo)
        :arg(_arg), statlist(_statlist), hasdo(_hasdo)
    {}

    WhileStatement(Node* _arg, bool _hasdo)
        :arg(_arg), hasdo(_hasdo)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        if (arg != NULL){
            std::string START = "STARTWHILE" + makeUniqLabel();
            std::string ENDWHILE = "ENDWHILE" + makeUniqLabel();

            if(hasdo){
                statlist -> Compile(dst, program, destination);
            }
            destination = program.currentOffset + 8;

            dst << "#WHILE" << std::endl;
            dst << START << ": " << std::endl;
            arg -> Compile(dst, program, destination);
            dst << "lw $t0, " << destination << "($sp)" << std::endl;
            dst << "beq $t0, $0, " << ENDWHILE << std::endl;
            dst << "nop" <<std::endl;
            if (statlist != NULL){
                statlist -> Compile(dst, program, destination);
            }
            dst << "bne $t0, $0, " << START << std::endl;
            dst << "nop" <<std::endl;
            dst << ENDWHILE << ": " <<std::endl;
        }
    }
};

class ForStatement
    :public translation_unit
{
public:
    Node* arg1;
    Node* arg2;
    Node* arg3;
    CompoundStatement* statlist; 

    virtual ~ForStatement(){
        delete arg1;
        delete arg2;
        delete arg3;
        delete statlist;
    }

    ForStatement(Node* _arg1, Node* _arg2, Node* _arg3, CompoundStatement* _statlist)
        : arg1(_arg1), arg2(_arg2), arg3(_arg3), statlist(_statlist)
    {}
    ForStatement(Node* _arg1, Node* _arg2, Node* _arg3)
        : arg1(_arg1), arg2(_arg2), arg3(_arg3)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string START = "STARTFOR" + makeUniqLabel();
        std::string END = "ENDFOR" + makeUniqLabel();
        if (arg2 != NULL){
             if (arg1 != NULL){
                 arg1 -> Compile(dst, program, destination);
             }
             dst << START << ": " <<std::endl;
             arg2 -> Compile(dst, program, destination);
             dst << "beq $v0, $0, " << END << std::endl;
             dst << "nop" <<std::endl;
             if (statlist!= NULL){
                statlist -> Compile(dst, program, destination);
             }
             arg3 -> Compile(dst, program, destination);
             dst << "j " << START << std::endl;
             dst << "nop" <<std::endl;
             dst << END << ": " << std::endl;
        }
    }
};

class SwitchStatement
    :public translation_unit
{
private:
    Node* value;
    Node* statlist;

public:
    virtual ~SwitchStatement(){
        delete value;
    }

    SwitchStatement(Node* _value, Node* _statlist)
        :value(_value), statlist(_statlist)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        program.assign = true;
        program.type = switc;
        value -> Compile(dst, program, destination);

        statlist -> Compile (dst, program, destination);
    }
};

class CaseStatement
    :public translation_unit
{
private:
    Node* value;
    CompoundStatement* statlist;

public:
    virtual ~CaseStatement(){
        delete value;
    }

    CaseStatement(Node* _value, CompoundStatement* _statlist)
        :value(_value), statlist(_statlist)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        dst << "#CASESTART" << std::endl;
        program.swcase = true;
        std::string CASE = "CASE" + makeUniqLabel();
        std::string CASENOT = "CASENOT" + makeUniqLabel();
        dst << "lw $t0, " << program.switchOffset << "($fp)" << std::endl;
        dst << "###OFFSET" << program.switchOffset << std::endl;
        value -> Compile(dst, program, destination);
        program.swcase = false;
        
        dst << "beq $t0, $v0, " << CASE << std::endl;
        dst << "nop" << std::endl;
        dst << "bne $t0, $v0, " << CASENOT << std::endl;
        dst << "nop" << std::endl;

        dst << CASE << ":" << std::endl;
        statlist -> Compile(dst, program, destination);
        dst << CASENOT << ":" << std::endl;
    }
};

class Break
    :public translation_unit
{
public:
    Break(){}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        dst << "#BREAK" << std::endl;
        dst << "b DEFAULT1" << std::endl;
        dst << "nop" << std::endl;
    }
};

class DefaultStatement
    :public translation_unit
{
private:
    CompoundStatement* statlist;

public:
    virtual ~DefaultStatement(){
        delete statlist;
    }

    DefaultStatement (CompoundStatement* _statlist)
        :statlist(_statlist)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        dst << "#DEFAULT" << std::endl;
        statlist -> Compile(dst, program, destination);
        dst << "DEFAULT1:" << std::endl;
    }
};


class EnumStatement
    :public translation_unit
{
public:
    Node* arg;
    std::vector <Node*> statement;

    virtual ~EnumStatement (){
        for (int i = 0; i < statement.size(); i++){
            delete statement.at(i);
        }
    }

    EnumStatement(Node* _arg)
        :arg(_arg)
    {
        statement.push_back(arg);
    }

    EnumStatement *AddEnum(Node* arg){
        statement.push_back(arg);
        return this;
    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
            for(int i=0; i<statement.size(); i++){
                program.type = enumer;
                program.assign = true;
                statement[i] -> Compile(dst, program, destination);
            }
    }
};

class Enum
    :public translation_unit
{
private: 
    std::string iden;
    EnumStatement* enumlist;

public:
    virtual ~Enum(){
        delete enumlist;
    }

    Enum(std::string _iden)
        :iden(_iden), enumlist(NULL)
    {}
    
    Enum(std::string _iden, EnumStatement* _enumlist)
        :iden(_iden), enumlist(_enumlist)
    {}

    Enum(EnumStatement* _enumlist)
        :enumlist(_enumlist)
    {}

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        dst << "#CREATE ENUM:" << iden << std::endl;
        program.enumer = true;
        program.bindings.insert(std::pair<std::string, int32_t>(iden, program.currentOffset));
        if (enumlist != NULL){
            enumlist -> Compile(dst, program, destination);
        }
    }
};

#endif
