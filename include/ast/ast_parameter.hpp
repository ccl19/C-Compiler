#ifndef ast_parameter_hpp
#define ast_parameter_hpp
#include "ast_node.hpp"

#include <string>
#include <iostream>
#include <math.h>
#include <vector>


class ParameterList
    :public translation_unit
{
public:
    Node* parameter;
    std::vector <Node*> paramlist;

    virtual ~ParameterList (){
        delete parameter;
        paramlist.clear();
    }

    ParameterList (Node* _parameter)
        :parameter(_parameter)
    {
        paramlist.push_back(parameter);
    }

    ParameterList *AddParam(Node* parameter){
        paramlist.push_back(parameter);
        return this;
    }

    virtual void Compile(std::ostream &dst, Context &program, int destination) const override{
        for (int i = 0; i<paramlist.size(); i++){
            program.type = param;
            program.assign = true;
            program.paramNum = paramlist.size();
            dst << "#PARAMETERLIST" << std::endl;
            paramlist[i] -> Compile(dst, program, destination);
        }
    }
};

class Parameter // int a, int b
	: public translation_unit
{
private:
	std::string type;
	Node* iden;

public:
	virtual ~Parameter(){
		delete iden;
	}

	Parameter(std::string _type, Node* _iden)
		: type(_type), iden(_iden)
	{ }

	virtual void Compile (std::ostream&dst, Context &program, int destination) const override{
		program.type = param;
		program.assign = true;
        program.typeSpec = type;
        dst << "#PARAMETER" << std::endl;
        dst << "#NUM: " << program.paramNum << std::endl;
		iden -> Compile(dst, program, destination);
	}
};

#endif
