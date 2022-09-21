#ifndef ast_function_hpp
#define ast_function_hpp
#include "ast_node.hpp"
#include "ast_parameter.hpp"
#include "ast_expression.hpp"

#include <string>
#include <iostream>
#include <math.h>

typedef const Node* NodePtr;

class Function
    : public translation_unit
{
public:
    std::string type; //type
    Node* func_decl; //name of function
    ParameterList* list; // list of params
    Node* statements;  //body of function
    std::string name;

//constructor
    Function (std::string _type, Node* _direct_declarator, ParameterList* _list, Node* _statements)
        : type(_type), func_decl(_direct_declarator), list(_list),statements(_statements)
    {}

    Function (std::string _type, Node* _direct_declarator, Node* _statements)
        : type(_type), func_decl(_direct_declarator), statements(_statements)
    {}
 
//destructor
    virtual ~Function(){
        delete statements;
        delete func_decl;
        delete list;
    }

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        program.currentOffset = 0;
        program.assign = true;
        program.type = function;
        func_decl -> Compile (dst, program, destination);
        if (list != NULL){
            list -> Compile(dst, program, destination);
        }
        statements -> Compile (dst, program, destination);
    }
};

class FunctionCall //return g();
    : public translation_unit
{
private:
    std::string iden;
    PrimExpression* expr;
    
public:
    virtual ~FunctionCall(){
    }

    FunctionCall(std::string _iden)
        :iden(_iden)
    {}

    FunctionCall(std::string _iden, PrimExpression* _expr)
        :iden(_iden), expr(_expr)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        program.returnCall = true;
        if (expr!=NULL){
            program.ext_params = true;;
            expr -> Compile(dst, program, destination);
        }
        dst << "jal " << iden << std::endl;
        dst << "nop" << std::endl;
    }
};

class FunctionDeclaration // int g();
    : public translation_unit
{
private:
    Node* iden;
    ParameterList* params;
public:
    virtual ~FunctionDeclaration(){
        delete iden;
        delete params;
    }

    FunctionDeclaration(Node* _iden)
        :iden(_iden)
    {}

    FunctionDeclaration(Node* _iden, ParameterList* _params)
        :iden(_iden), params(_params)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        program.assign = false;
        program.type = function;
        program.funcCall = true;
        iden -> Compile(dst, program, destination); 
        if (params != NULL){
            params -> Compile (dst, program, destination);
        }
    }
};

class FunctionList
    : public translation_unit
{
public:
    Node* func;
    std::vector<Node*> funcList;

    virtual ~FunctionList(){
        delete func;
        for (int i = 0; i<funcList.size(); i++){
            delete funcList[i];
        }
    }

    FunctionList(Node* _func)
        :func(_func)
    {
        funcList.push_back(func);
    }

    FunctionList addFuncList(Node* func){
        funcList.push_back(func);
        return this;
    }

    virtual void Compile (std::ostream& dst, Context &program, int destination) const override{
        for(int i=0; i<funcList.size(); i++){
                funcList[i] -> Compile(dst, program, destination);
        }
    }
};
    
#endif