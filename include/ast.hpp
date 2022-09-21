#ifndef ast_hpp
#define ast_hpp

#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "ast/ast_node.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_expression.hpp"
#include "ast/ast_function.hpp"
#include "ast/ast_statement.hpp"
#include "ast/ast_declarator.hpp"
#include "ast/ast_parameter.hpp"
#include "ast/ast_array.hpp"
#include "ast/ast_string.hpp"



const extern Node* parseAST();

#endif
