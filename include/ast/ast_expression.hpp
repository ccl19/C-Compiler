#ifndef ast_expression_hpp
#define ast_expression_hpp
#include "ast_node.hpp"

#include <string>
#include <iostream>
#include <math.h>


class Expression
    :public translation_unit
{
private:
    Node* expression;
    Node* left;
    Node* right;
    std::string name;

public:
    virtual ~Expression()
    {
        delete expression;
    }

    Expression(){}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        expression -> Compile(dst,program, destination);
    }
};

class Assignment
    :public Expression
{
public:
    Node* left;
    Node* right;

    virtual ~Assignment(){
        delete left;
        delete right;
    }

    Assignment(Node* _left, Node* _right)
        : left(_left), right(_right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override {
        right -> Compile (dst, program, destination);
        program.assign = true;
        program.type = assignment;
        left -> Compile(dst, program, destination);
    }
};

class PrimExpression
    :public translation_unit
{
public:
    Node* expression;
    std::vector <Node*> primaryExpressions;

    virtual ~PrimExpression (){
        for (int i = 0; i < primaryExpressions.size(); i++){
            delete primaryExpressions.at(i);
        }
    }

    PrimExpression(Node* _expression)
        : expression(_expression)
    {
        primaryExpressions.push_back(expression);
    }

    PrimExpression *AddExpr(Node* expression){
        primaryExpressions.push_back(expression);
        return this;
    }

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        for (int i = 0; i < primaryExpressions.size(); i++){
            primaryExpressions.at(i) -> Compile (dst, program, destination);
        }   
    }  
};


class Constant
    :public Expression
{
private:
    std::string type;
    double num;

public:
    virtual ~Constant(){

    }

    Constant(std::string _type, double _num)
        : type(_type), num(_num)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        program.currentOffset += 4;
        if (type == "int"){
            dst << "#CONST" << std::endl;
            static int i = 0;
            std::vector<std::string> argReg = {"$a0", "$a1", "$a2", "$a3"}; 
            if (program.ext_params){
                if (i < 4){
                    dst << "li " << argReg.at(i) << ", " << num << std::endl;
                }
                else{
                    destination = i*4;
                    dst << "li $v0, " << num << std::endl;
                    dst << "sw $v0, "<< destination << "($sp)" << std::endl;
                }
                i++;
            }
            else{
                if (program.enumer){
                    int number = (int) num;
                    program.enumprints.push_back("li $v0, " + std::to_string(number));
                }
                else{
                    dst << "li $v0, " << num << std::endl;
                }
                if (!program.swcase)
                    if (program.paramNum > 0){
                        dst << "sw $v0, " << program.currentOffset - 8 << "($fp)" << std::endl;
                    }
                    else{ 
                        if (program.enumer){
                            program.enumprints.push_back("sw $v0, " + std::to_string(destination) + "($fp)");
                        }
                        else{
                            dst << "sw $v0, " << destination << "($fp)" << std::endl;
                        }
                    }
            }
        }
        else if (type == "float"){
            dst << "#FLOAT" << std::endl;
            dst << "li.s $f0, " << num << std::endl;
            dst << "swc1 $f0, " << destination << "($fp)" << std::endl;
        }
    }
};

class Variable
    :public Expression
{
private:
    std::string iden;
    std::vector <Node*> params_list;
public:
    virtual ~Variable()
    {}

    Variable(std::string _iden)
        :iden(_iden)
    {
        AddCount();
    }

    virtual std::string getIden() {
        return iden;
    }

    void print_Iden(){
        std::cout<< iden << std::endl;
    }

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        if (program.funcCall){
            program.bindings.insert(std::pair<std::string, int32_t> (iden, program.currentOffset));
            program.currentOffset += 4;
            program.bindings[iden] = program.currentOffset;
        }
        if (program.assign){
            switch (program.type){
                case initialize:
                { // create a new variable
                    program.varSize.insert(std::pair<std::string, std::string> (iden, program.typeSpec));
                    program.bindings.insert(std::pair<std::string, int32_t> (iden, program.currentOffset));
                    program.currentOffset += 4;
                    program.bindings[iden] = program.currentOffset;
                    if (program.typeSpec == "int"){  
                        dst << "#EXPR_INITIALIZE NAME: " << iden << std::endl;
                        dst << "lw $v0, " << program.bindings[iden] << "($fp)" << std::endl;
                    }
                    else if (program.typeSpec == "float"){  
                        dst << "#EXPR_INITIALIZE NAME: " << iden << std::endl;
                        dst << "lwc1 $f0, " << program.bindings[iden] << "($fp)" << std::endl;
                    }
                    break;
                }
                case call:
                {
                    dst << "#EXP_CALL" << std::endl;
                    dst << ".globl " << iden << std::endl;
                    break;
                }
                case function:
                { // declares a function
                    program.functionnum ++;
                    dst << "#EXP_FUNCTION" << std::endl;
                    int stackSize = -(getCount()+program.function_count) * 4 - 28;
                    program.returnStack = -stackSize;
                    dst << "#func _ count: " << program.function_count << std::endl;
                    program.stackPointer = stackSize;
                    int frameOffset = -stackSize - 4;
                    program.callPointer = frameOffset - 4;
                    dst << ".globl " << iden << std::endl;
	                dst << iden << ":" << std::endl;
                    dst << "addiu $sp, $sp, " << stackSize << std::endl; // allocate stack
                    dst << "sw $fp, " << frameOffset << "($sp)" << std::endl; // store previous frame pointer on stack
                    if (program.funcCall|| program.functionnum>1){
                        dst << "sw $31, " << program.callPointer << "($sp)" << std::endl; // store return address on stack
                    }
                    dst << "move $fp, $sp" << std::endl; // create new frame pointer

                    program.function_count += 4;
                    dst << "#func _ count: " << program.function_count << std::endl;

                    if (program.enumer){
                        for (int i = 0; i < program.enumprints.size(); i++){
                            dst << program.enumprints.at(i) << std::endl;
                        }
                    }
                    program.enumer = false;

                    break;
                }
                case constructor:
                { // assigning a variable
                    program.bindings.insert(std::pair<std::string, int32_t>(iden, program.currentOffset));
                    program.currentOffset += 4;
                    destination = program.bindings[iden];
                    dst << "#EXP_CONST" << std::endl;
                    if (program.typeSpec == "int"){
                        dst << "#IDEN: " << iden << std::endl;
                        if (program.enumer){
                            program.enumprints.push_back("sw $v0, " + std::to_string(program.bindings[iden]) + "($fp)");
                        }
                        else{
                            dst << "sw $v0, " << program.bindings[iden] << "($fp)" << std::endl;
                        }
                    }
                    else if (program.typeSpec == "float"){
                        dst << "#IDEN: " << iden << std::endl;
                        dst << "swc1 $f0, " << destination << "($fp)" << std::endl;
                    }
                    break;
                }
                case param:
                { // used for function parameters
                    dst << "#PARAM NAME: " << iden << std::endl;
                    program.bindings.insert(std::pair<std::string, int32_t>(iden, program.currentOffset));
                    destination = program.currentOffset;
                    program.bindings[iden] = destination;
                    program.currentOffset += 4;
                    static int i = 0;
                    std::vector<std::string> argReg = {"$a0", "$a1", "$a2", "$a3"};
                    std::vector<std::string> floatReg = {"$f12", "$f14", "$a2", "$a3"};
                    dst << "#EXP_PARAMS" << std::endl;
                    if (program.typeSpec == "int"){
                        if (i < 4){
                            dst << "sw " << argReg[i]<< ", "<< destination << "($fp)" << std::endl;
                        }
                    }
                    else if (program.typeSpec == "float"){
                        if (i < 2){
                            dst << "swc1 " << floatReg[i] << ", " << destination << "($fp)" << std::endl;
                        }
                        else if (i >= 2 && i < 4){
                            dst << "sw " << floatReg[i] << ", " << destination << "($fp)" << std::endl;
                        }
                    }
                    else if (program.typeSpec == "double"){
                        program.currentOffset += 4;
                        dst << "#des: " << destination << std::endl;
                        if (i < 2){
                            dst << "sdc1 " << floatReg[i] << ", " << destination << "($fp)" << std::endl;
                        }
                        else if (i >= 2 && i < 4){
                            dst << "sw " << floatReg[i] << ", " << destination << "($fp)" << std::endl;
                        }
                    }
                    i++;
                    break;
                }
                case array:
                {    //used for arrays
                    if (program.arrGlobal){
                        dst << iden << ": " << std::endl;
                    }
                    program.bindings.insert(std::pair<std::string, int32_t> (iden, program.currentOffset));
                    program.bindings[iden] = program.currentOffset;
                    dst << "#EXPR_ARRAY: " << iden << std::endl;
                    destination = program.bindings[iden];
                    dst << "lw $v0, " << destination << "($fp)" << std::endl;
                    break;
                }
                case sizeOf:
                {
                    std::string type = program.varSize[iden];
                    if (type == "int"){
                        dst << "li $v0, 4" << std::endl;       
                    }
                    else if (type == "float"){
                        dst << "li $v0, 4" << std::endl;   
                    }
                    else if (type == "char"){
                        dst << "li $v0, 1" << std::endl;   
                    }
                    else if (type == "unsigned"){
                        dst << "li $v0, 4" << std::endl;   
                    }
                    break;
                }
                case increment:
                {
                    dst << "#INCREMENT" << std::endl;
                    dst << "lw $v0, " << program.bindings[iden] << "($fp)" << std::endl;
                    dst << "nop" << std::endl;
                    dst << "addiu $v0, $v0, 1" <<std::endl;
                    dst << "sw $v0, " << program.bindings[iden] << "($fp)" << std::endl ;
                    break;
                }
                case decrement:
                {
                    dst << "#DECREMENT" << std::endl;
                    dst << "lw $v0, " << program.bindings[iden] << "($fp)" << std::endl;
                    dst << "nop" << std::endl;
                    dst << "addiu $v0, $v0, -1" <<std::endl;
                    dst << "sw $v0, " << program.bindings[iden] << "($fp)" << std::endl ;
                    break;
                }
                case switc:
                {
                    program.switchOffset = program.bindings[iden];
                    break;
                }
                case enumer:
                {
                    program.bindings.insert(std::pair<std::string, int32_t>(iden, program.currentOffset));
                    break;
                }
                case none:
                {
                    break;
                }
            }
            program.assign = false;
            program.type = none;
        }

        else {
            if (program.funcCall){}
            else if (program.bindings.count(iden)>0){
                dst << "#VAR" << std::endl;
                if (program.typeSpec == "int"){
                    dst << "lw $v0, " << program.bindings[iden] << "($sp)" << std::endl;
                    dst << "sw $v0, " << destination << "($sp)" << std::endl;
                }
                else if (program.typeSpec == "float"){
                    dst << "lwc1 $f0, " << program.bindings[iden] << "($sp)" << std::endl;
                    dst << "swc1 $f0, " << destination << "($sp)" << std::endl;
                }
                else if (program.typeSpec == "double"){
                    dst << "ldc1 $f0, " << program.bindings[iden] << "($sp)" << std::endl;
                    static int i = 0;
                    dst << "sdc1 $f0, " << destination + 4*i << "($sp)" << std::endl;
                    i++;
                }
            }
            else{
                dst << "Variable not found" << std::endl;
            }
        }
    }
};

class SizeOf
    :public Expression
{
private:
    Node* iden;

public:
    virtual ~SizeOf(){
        delete iden;
    } 

    SizeOf(Node* _iden)
        :iden(_iden)
    {}

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        program.type = sizeOf;
        program.assign = true;
        iden -> Compile(dst, program, destination);
    }

};

class SizeOfInst
    :public Expression
{
private:
    std::string type;

public:
    virtual ~SizeOfInst(){
    } 

    SizeOfInst(std::string _type)
        :type(_type)
    {}

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        if (type == "int"){
            dst << "li $v0, 4" << std::endl;       
        }
        else if (type == "float"){
            dst << "li $v0, 4" << std::endl;   
        }
        else if (type == "char"){
            dst << "li $v0, 1" << std::endl;   
        }
        else if (type == "unsigned"){
            dst << "li $v0, 4" << std::endl;   
        }
    }

};

class ExpressionInitialiser
    :public Expression
{
private:
    Node* var;
    Node* oper;

public:
    virtual ~ExpressionInitialiser(){
        delete var;
        delete oper;
    }

    ExpressionInitialiser(Node* _var, Node* _oper)
        :var(_var), oper(_oper)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{   
    }
};




#endif
