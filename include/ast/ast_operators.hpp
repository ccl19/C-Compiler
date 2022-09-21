#ifndef ast_operators_hpp
#define ast_operators_hpp
#include "ast_node.hpp"
#include "ast_statement.hpp"

#include <string>
#include <iostream>
#include <math.h>

class Operator
    : public Node
{
private:
    Node* left;
    Node* right;
    Node* cond;

public:
    virtual ~Operator()
    {
        delete left;
        delete right;
    }

    Operator(Node* _cond)
        : cond(_cond)
    {}

    Operator(Node* _left, Node* _right)
        : left(_left), right(_right)
    {}

    Operator(Node* _condition, Node* _expr1, Node* _expr2)
        : left(_condition), right(_expr1), cond(_expr2)
    {}

    virtual const char *getOpcode() const =0;

    Node* getLeft() const
    { return left; }

    Node* getRight() const
    { return right; }

    Node* getCond() const
    { return cond; }  

    virtual void Compile(std::ostream &dst, Context &program, int destination) const {};
};

class AddOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "+"; 
    }

public:
    AddOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;
        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        if (program.typeSpec == "int"){
            dst << "#ADDINT" << std::endl;
            dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
            dst << "move $t0, $v0" << std::endl;

            dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
            dst << "nop" << std::endl;
            dst << "addu $v0, $t0, $v0" << std::endl;
            dst << "sw $v0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "float"){
            dst << "#ADDFLOAT" << std::endl;
            dst << "lwc1 $f0, " << destinationL << "($sp)" << std::endl;

            dst << "lwc1 $f2, " << destinationR << "($sp)" << std::endl;
            dst << "nop" << std::endl;
            dst << "add.s $f0, $f0, $f2" << std::endl;
            dst << "swc1 $f0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "double"){
            dst << "#ADDDOUBLE" << std::endl;
            dst << "ldc1 $f0, " << destinationL << "($sp)" << std::endl;

            dst << "ldc1 $f2, " << destinationR + 4 << "($sp)" << std::endl;
            dst << "add.d $f0, $f2, $f0" << std::endl;
            dst << "sdc1 $f0, " << destination << "($sp)" << std::endl;
        }
    }
};

class SubOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "-"; 
    }

public:
    SubOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        if (program.typeSpec == "int"){
            dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
            dst << "move $t0, $v0" << std::endl;

            dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
            dst << "subu $v0, $t0, $v0" << std::endl;
            dst << "sw $v0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "float"){
            dst << "lwc1 $f2, " << destinationL << "($sp)" << std::endl;

            dst << "lwc1 $f0, " << destinationR << "($sp)" << std::endl;
            dst << "sub.s $f0, $f0, $f2" << std::endl;
            dst << "swc1 $f0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "double"){
            dst << "#SUBDOUBLE" << std::endl;
            dst << "ldc1 $f0, " << destinationL << "($sp)" << std::endl;

            dst << "ldc1 $f2, " << destinationR << "($sp)" << std::endl;
            dst << "nop" << std::endl;
            dst << "sub.d $f0, $f0, $f2" << std::endl;
            dst << "sdc1 $f0, " << destination << "($sp)" << std::endl;
        }
    }
};

class MultOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "*"; 
    }

public:
    MultOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        if (program.typeSpec == "int"){
            dst << "#MULINT" <<std::endl;
            dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
            dst << "move $t0, $v0" << std::endl;

            dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
            dst << "mul $v0, $t0, $v0" << std::endl;
            dst << "sw $v0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "float"){
            dst << "#MULFLOAT" <<std::endl;
            dst << "lwc1 $f2, " << destinationL << "($sp)" << std::endl;

            dst << "lwc1 $f0, " << destinationR << "($sp)" << std::endl;
            dst << "mul.s $f0, $f2, $f0" << std::endl;
            dst << "swc1 $f0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "double"){
            dst << "#MULTDOUBLE" << std::endl;
            dst << "ldc1 $f0, " << destinationL << "($sp)" << std::endl;

            dst << "ldc1 $f2, " << destinationR + 4 << "($sp)" << std::endl;
            dst << "mul.d $f0, $f2, $f0" << std::endl;
            dst << "sdc1 $f0, " << destination << "($sp)" << std::endl;
        }
    }
};

class DivOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "/"; 
    }

public:
    DivOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        if (program.typeSpec == "int"){
            dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
            dst << "move $t0, $v0" << std::endl;

            dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
            dst << "div $t0, $v0" << std::endl;
            dst << "mflo $v0" << std::endl;
            dst << "sw $v0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "float"){
            dst << "#DIVFLOAT" <<std::endl;
            dst << "lwc1 $f2, " << destinationL << "($sp)" << std::endl;

            dst << "lwc1 $f0, " << destinationR << "($sp)" << std::endl;
            dst << "div.s $f0, $f2, $f0" << std::endl;
            dst << "swc1 $f0, " << destination << "($sp)" << std::endl;
        }
        else if (program.typeSpec == "double"){
            dst << "#DIVDOUBLE" << std::endl;
            dst << "ldc1 $f0, " << destinationL << "($sp)" << std::endl;

            dst << "ldc1 $f2, " << destinationR << "($sp)" << std::endl;
            dst << "nop" << std::endl;
            dst << "div.d $f0, $f0, $f2" << std::endl;
            dst << "sdc1 $f0, " << destination << "($sp)" << std::endl;
        }
    }
};

class ModOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "%"; 
    }

public:
    ModOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "div $t0, $v0" << std::endl;
        dst << "mfhi $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};


class OrOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "|"; 
    }

public:
    OrOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "or $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class AndOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "&"; 
    }

public:
    AndOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "and $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class XorOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "|"; 
    }

public:
    XorOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "xor $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class LogicalAndOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "&&"; 
    }

public:
    LogicalAndOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string tru = "AND" + makeUniqLabel();
        std::string fake = "AND" + makeUniqLabel();
        std::string end = "AND_END" + makeUniqLabel();
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;

        dst << "beq $t0, $0, " << fake << std::endl;
        dst << "nop" << std::endl;
        dst << "beq $v0, $0, " << fake << std::endl;
        dst << "nop" << std::endl;

        dst << "li $v0, 0x1" << std::endl;
        dst << "j " << tru << std::endl;

        dst << fake << ": " << std::endl;
        dst << "move $v0, $0" << std::endl;
        dst << "j " << end << std::endl;

        dst << tru << ": " << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl;
        dst << "j " << end << std::endl;

        dst << end << ": " << std::endl;
    }
    
};

class LogicalOrOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "||"; 
    }

public:
    LogicalOrOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string tru = "OR" + makeUniqLabel();
        std::string fake = "OR" + makeUniqLabel();
        std::string end = "OR_END" + makeUniqLabel();
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;

        dst << "bne $t0, $0, " << tru << std::endl;
        dst << "nop" << std::endl;
        dst << "bne $v0, $0, " << tru << std::endl;
        dst << "nop" << std::endl;

        dst << fake << ": " << std::endl;
        dst << "move $v0, $0" << std::endl;
        dst << "j " << end << std::endl;

        dst << tru << ": " << std::endl;
        dst << "li $v0, 0x1" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl;
        dst << "j " << end << std::endl;

        dst << end << ": " << std::endl;
    }
};

class ShiftLeftOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "<<"; 
    }

public:
    ShiftLeftOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "sll $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class ShiftRightOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return ">>"; 
    }

public:
    ShiftRightOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "sra $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class LessThanOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "<"; 
    }

public:
    LessThanOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "slt $v0, $t0, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class GreaterThanOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return ">"; 
    }

public:
    GreaterThanOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}


    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "slt $v0, $v0, $t0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};


class LessThanEqOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "<="; 
    }
public:
    LessThanEqOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string equal = "EQUAL" + makeUniqLabel();
        std::string end = "LESSEND" + makeUniqLabel();
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
    
        dst << "slt $v0, $t0, $v0" << std::endl;
        dst << "beq $t0, $v0, " << equal << std::endl;
        dst << "j " << end << std::endl;

        dst << equal << ": " << std::endl;
        dst << "li $v0, 0x1" << std::endl;

        dst << end << ": " << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class GreaterThanEqOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return ">="; 
    }
public:
    GreaterThanEqOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string equal = "EQUAL" + makeUniqLabel();
        std::string end = "GREATEND" + makeUniqLabel();
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
    
        dst << "slt $v0, $v0, $t0" << std::endl;
        dst << "beq $t0, $v0, " << equal << std::endl;
        dst << "j " << end << std::endl;

        dst << equal << ": " << std::endl;
        dst << "li $v0, 0x1" << std::endl;

        dst << end << ": " << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class NotEqualOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override { 
        return "!="; 
    }
public:
    NotEqualOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "xor $v0, $t0, $v0" << std::endl;
        dst << "sltu $v0, $zero, $v0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class EqualOperator
    :public Operator
{
protected:
    virtual const char* getOpcode() const override {
        return "==";
    }
public:
    EqualOperator(Node* _left, Node* _right)
        : Operator(_left, _right)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        int destinationL = program.currentOffset;
        int destinationR = program.currentOffset + 4;
        program.currentOffset += 8;

        getLeft() -> Compile(dst, program, destinationL);
        getRight() -> Compile(dst, program, destinationR);

        dst << "lw $v0, " << destinationL << "($sp)" << std::endl;
        dst << "move $t0, $v0" << std::endl;

        dst << "lw $v0, " << destinationR << "($sp)" << std::endl;
        dst << "seq $v0, $v0, $t0" << std::endl;
        dst << "sw $v0, " << destination << "($sp)" << std::endl ;
    }
};

class ConditionalOperator
    :public translation_unit
{
private:
    CompoundStatement* expr1;
    CompoundStatement* expr2;
    Node* condition;

public:
    ConditionalOperator(Node* _condition, CompoundStatement*  _expr1, CompoundStatement*  _expr2)
        : condition(_condition), expr1(_expr1), expr2(_expr2)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        std::string tru = "COND" + makeUniqLabel();
        std::string fake = "COND" + makeUniqLabel();
        std::string end = "COND" + makeUniqLabel();

        condition -> Compile(dst, program, destination);

        dst << "lw $t0, " << destination << "($sp)" << std::endl;
        dst << "beq $t0, $0 " << fake << std::endl;
        dst << "nop" << std::endl;

        expr1 -> Compile(dst, program, destination);
        dst << "j " << end << std::endl;

        dst << fake << ": " << std::endl;
        expr2 -> Compile(dst, program, destination);
      
        dst << end << ": " << std::endl;
    }
};


class IncrementOperator
    :public translation_unit
{
public:
    Node* condition;
    virtual ~IncrementOperator(){}
    
    IncrementOperator(Node* _condition)
        : condition(_condition)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        destination = program.currentOffset;
        program.currentOffset += 8;

        program.assign = true;
        program.type = increment;
        condition -> Compile(dst, program, destination);
        program.type = none;
    }
};

class DecrementOperator
    :public translation_unit
{
public:
    Node* condition;
    virtual ~DecrementOperator(){}
    
    DecrementOperator(Node* _condition)
        : condition(_condition)
    {}
    
    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        destination = program.currentOffset;
        program.currentOffset += 8;

        program.assign = true;
        program.type = decrement;
        condition -> Compile(dst, program, destination);
        program.type = none;
    }
};

#endif
