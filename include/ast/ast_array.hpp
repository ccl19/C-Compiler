#ifndef ast_array_hpp
#define ast_array_hpp
#include "ast_node.hpp"

#include <string>
#include <iostream>
#include <math.h>

class Array
    :public translation_unit
{
private:
    std::string type;
    Node* name;
    int size;
    Node* expr;
    bool initial;
    bool global;

public:
    virtual ~Array(){
        delete name;
        delete expr;
    }

    Array (std::string _type, Node* _name, int _size, bool _initial, bool _global)
        :type(_type), name(_name), size(_size), initial(_initial), global(_global)
    {}

    Array (Node* _name, int _size, Node* _expr, bool _initial, bool _global)
        :name(_name), size(_size), expr(_expr), initial(_initial), global(_global)
    {}

    Node* getName(){
        return name;
    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        dst << "#ARRAY" << std::endl;

        const int start = program.currentOffset;
        program.arraySize = 4 * size;
        program.stackPointer = program.currentOffset;
        program.currentOffset = program.currentOffset + program.arraySize;
        
        if (global){
            program.arrGlobal = true;
            program.assign = true;
            name -> Compile(dst, program, destination);
        }

        if (initial){
            program.type = array;
            program.assign = true;
            name -> Compile(dst, program, destination);
            program.assign = false;
            name -> Compile(dst, program, destination);
        }

    }
};


class ArrayAssignment
    :public translation_unit
{
private:
    Node* name;
    Node* size;
    Node* expr;

public:
    virtual ~ArrayAssignment(){
        delete name;
        delete expr;
        delete size;
    }

    ArrayAssignment (Node* _name, Node* _size, Node* _expr)
        :name(_name), size(_size), expr(_expr)
    {}

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        const int start = program.currentOffset;
        dst << "#ARRAYASSIGNMENT" << std::endl;
        std::string identity = name -> getIden();
        // start
        dst << "li $t0, " << program.bindings[identity] << std::endl;
        size -> Compile(dst, program, destination);
        dst << "li $t1, 4" << std::endl;
        // size of array
        dst << "mul $v0, $t1, $v0" << std::endl;

        dst << "add $t2, $v0, $sp" << std::endl;
        dst << "add $t3, $t0, $t2" << std::endl;
        dst << "move $v0, $t3" << std::endl;
        dst << "sw $v0, " << program.currentOffset << "($fp)" << std::endl;
        int stackArray = program.currentOffset;

        expr -> Compile(dst, program, destination);

        dst << "lw $t1, " << stackArray << "($fp)" << std::endl;
        dst << "sw $v0, 0($t1)" << std::endl;
        // destination = program.currentOffset + 4*size;
        // name -> Compile(dst, program, destination);

        // std::string identity = name -> getIden();
        // dst << "li $t0, " << program.bindings[identity] << std::endl;
        // size -> Compile(dst, program, destination);
        // dst << "li $t1, 4" << std::endl;
        // dst << "#SIZE OF ARRAY" << std::endl;
        // dst << "mul $v0, $t1, $v0" << std::endl;

        // dst << "add $t2, $v0, $sp" << std::endl;
        // dst << "add $t3, $t0, $t2" << std::endl;
        // dst << "move $v0, $t3" << std::endl;
        // dst << "sw $v0, " << program.currentOffset << "($fp)" << std::endl;

        // expr -> Compile(dst, program, destination);
        
        // program.assign = true;
        // program.type = array; 
        // // destination = program.currentOffset + 4*size;
        // name -> Compile(dst, program, destination);
    }
};




#endif
