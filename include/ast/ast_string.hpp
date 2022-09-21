#ifndef ast_string_hpp
#define ast_string_hpp
#include "ast_node.hpp"

#include <string>
#include <iostream>
#include<stdio.h>
#include <stdlib.h>

class String
    : public translation_unit
{
public:
    std::string str;

    virtual ~String(){
    }

    String(std::string _str)
        :str(_str)
    {}

    virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
        for (int i = 0; i < str.length(); i++){
            int temp = (int) str[i];
            dst << "li $v0, " << temp + 1 << std::endl;    
        }  
    }
};

#endif