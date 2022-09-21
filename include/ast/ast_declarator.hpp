#ifndef ast_declarator_hpp
#define ast_declarator_hpp
#include "ast_node.hpp"
#include "ast_parameter.hpp"

#include <string>
#include <iostream>
#include <math.h>

class Declarator
	: public translation_unit
{
private:
	Node* dec;

public:
	virtual ~Declarator(){
		delete dec;
	}

	Declarator (Node* _dec)
		: dec(_dec)
	{}

	virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
		dec -> Compile(dst, program, destination);
	}
};

class Declaration_Specifier // int a, int b
		: public translation_unit
{
private:
		std::string type;
		Node* iden;

public:
	virtual ~Declaration_Specifier(){
		delete iden;
	}

	Declaration_Specifier(std::string _type, Node* _iden)
		: type(_type), iden(_iden)
	{ }

	virtual void Compile (std::ostream&dst, Context &program, int destination) const override{
		program.typeSpec = type;
		program.type = initialize;
		program.assign = true;
		iden -> Compile(dst, program, destination);
	}
};

class Direct_Declarator
		: public translation_unit
{
private:
		Node* declarator;
		ParameterList* list;

public:
		virtual ~Direct_Declarator(){
			delete declarator;
		}

		Direct_Declarator(Node* _declarator, ParameterList* _paramList)
			: declarator(_declarator), list(_paramList)
		{}

		virtual void Compile (std::ostream &dst, Context &program, int destination){
			declarator -> Compile(dst, program, destination);
			if (list != NULL){
            	list -> Compile(dst, program, destination);
        	}
		}
};

class VarDeclaration //a=1
	:public translation_unit
{
public:
	std::string type;
	Node* iden;
	Node* value;


	virtual ~VarDeclaration(){
		delete iden;
		delete value;
	}

	VarDeclaration(Node* _iden, Node* _value)
		:iden(_iden), value(_value)
	{ type = "int"; }

	VarDeclaration(std::string _type, Node* _iden, Node* _value)
		:type(_type), iden(_iden), value(_value)
	{}

	virtual void Compile (std::ostream &dst, Context &program, int destination) const override{
		value -> Compile(dst, program, destination);
		program.typeSpec = type;
		
		program.type = constructor;
		dst << "#HERE" <<program.typeSpec << std::endl;
		program.assign = true;
		iden -> Compile(dst, program, destination);
	}
};


#endif
