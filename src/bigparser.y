%code requires{
  #include "ast.hpp"
  #include <iostream>
  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out
  
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union{
    Node* expr;
    std::string *string;
    double number;
    std::vector<Node*> list;
}

%token IDENTIFIER INT_LITERAL STRING_LITERAL FLOAT_LITERAL CHAR_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NEQ_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN 

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR INT VOID 
%token STRUCT ENUM

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR CONTINUE BREAK RETURN

%type <expr> primary_expression unary_expression
%type <expr> additive_expression multiplicative_expression shift_expression
%type <expr> relational_expression equality_expression and_expression 
%type <expr> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <expr> conditional_expression assignment_expression expression constant_expression cast_expression

%type <expr> identifier_list statement

%type <expr> declaration declaration_specifiers init_declarator struct_declaration_list
%type <expr> struct_declaration enum_specifier enum_list enumerator declarator struct_declarator 
%type <expr> specifier_qualifier_list pointer direct_declarator declaration_list

%type <expr> function_definition translation_unit external_declaration

%type <string> type_specifier assignment_operator

%type <expr> if_statement while_statement for_statement switch_statement case_statement
%type <expr> statement_list skip_statement expression_statement compound_statement
%type <expr> top
%type <expr> parameter_declaration 

%type <list> parameter_type_list parameter_list 

%type <number> INT_LITERAL
%type <string> IDENTIFIER CHAR_LITERAL
%type <string> INT VOID

%nonassoc NOELSE
%nonassoc ELSE

%start top

%%

top : translation_unit { g_root = $1; }

translation_unit : external_declaration { $$ = new translation_unit($1);}
                 | translation_unit external_declaration { $$ = new translation_unit($2);}
                 ;

external_declaration : function_definition {$$ = $1;}
                     | declaration 
                     ;

function_definition : type_specifier direct_declarator compound_statement {$$ = new Function(*$1,$2,$3);}
                    ;
                    

// declaration_specifiers direct_declarator '(' parameter_list ')' '{' statement '}'
//                     | declaration_specifiers direct_declarator '('')' '{' statement '}' 
//                     | declaration_specifiers direct_declarator '(' parameter_list ')' ';'
//                     | declaration_specifiers direct_declarator '('')' ';'
//                     ;

primary_expression : IDENTIFIER {$$ = new Variable(*$1);}
                   | INT_LITERAL {$$ = new Constant($1);}
                   | STRING_LITERAL
                   | '(' expression ')'
                   ;

unary_expression : INC_OP unary_expression
                 | DEC_OP unary_expression
                 | unary_operator unary_expression
                 ;

unary_operator : '&'
               | '-'
               | '+'
               | '!'
               | '*'
               ;

cast_expression : unary_expression 
                | '(' type_specifier ')' cast_expression 
                ;

multiplicative_expression : cast_expression {$$ = $1;}
                          | multiplicative_expression '*' cast_expression {$$ = new MultOperator($1, $3);}
                          | multiplicative_expression '/' cast_expression {$$ = new DivOperator($1, $3);}
                          | multiplicative_expression '%' cast_expression {$$ = new ModOperator($1, $3);}
                          ;

additive_expression : multiplicative_expression {$$ = $1;}
                    | additive_expression '+' multiplicative_expression {$$ = new AddOperator($1, $3);}
                    | additive_expression '-' multiplicative_expression {$$ = new SubOperator($1, $3);}
                    ;

shift_expression : additive_expression {$$ = $1;}
                 | shift_expression LEFT_OP additive_expression {$$ = new ShiftLeftOperator($1, $3);}
                 | shift_expression RIGHT_OP additive_expression {$$ = new ShiftRightOperator($1, $3);}
                 ;

relational_expression : shift_expression {$$ = $1;}
                      | relational_expression '<' shift_expression {$$ = new LessThanOperator($1, $3);}
                      | relational_expression '>' shift_expression {$$ = new GreaterThanOperator($1, $3);}
                      | relational_expression LE_OP shift_expression {$$ = new LessThanEqOperator($1, $3);}
                      | relational_expression GE_OP shift_expression {$$ = new GreaterThanEqOperator($1, $3);}
                      ;

equality_expression : relational_expression {$$ = $1;}
                    | equality_expression NEQ_OP relational_expression {$$ = new NotEqualOperator($1, $3);}
                    | equality_expression EQ_OP relational_expression {$$ = new EqualOperator($1, $3);}
                    ;

and_expression : equality_expression {$$ = $1;}
               | and_expression '&' equality_expression {$$ = new AndOperator($1, $3);}
               ;

exclusive_or_expression : and_expression {$$ = $1;}
                        | exclusive_or_expression '^' and_expression {$$ = new XorOperator($1, $3);}
                        ;

inclusive_or_expression : exclusive_or_expression {$$ = $1;}
                        | inclusive_or_expression '|' exclusive_or_expression {$$ = new OrOperator($1, $3);}
                        ;

logical_and_expression : inclusive_or_expression {$$ = $1;}
                       | logical_and_expression AND_OP inclusive_or_expression {$$ = new LogicalAndOperator($1, $3);}
                       ;

logical_or_expression : logical_and_expression {$$ = $1;}
                      | logical_or_expression OR_OP logical_and_expression {$$ = new LogicalOrOperator($1, $3);}
                      ;

conditional_expression : logical_and_expression {$$ = $1;}
                       | conditional_expression '?' expression ':' conditional_expression {$$ = new ConditionalOperator($1, $3);}
                       ;

assignment_expression : conditional_expression {$$ = $1;}
                      | unary_expression '=' assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression MOD_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression MUL_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression ADD_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression SUB_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression DIV_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression AND_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression OR_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      | unary_expression XOR_ASSIGN assignment_expression {$$ = new Assignment($1, $3);}
                      ;

assignment_operator : '=' {$$ = new std::string "eq";}
                    | MOD_ASSIGN {$$ = new std::string "mod";}
                    | MUL_ASSIGN {$$ = new std::string "mul";}
                    | ADD_ASSIGN {$$ = new std::string "add";}
                    | SUB_ASSIGN {$$ = new std::string "sub";}
                    | DIV_ASSIGN {$$ = new std::string "div";}
                    | AND_ASSIGN {$$ = new std::string "andd";}
                    | OR_ASSIGN {$$ = new std::string "orr";}
                    | XOR_ASSIGN {$$ = new std::string "xorr";}
                    ;

expression : assignment_expression {$$ = $1;}
           ;


constant_expression : conditional_expression {$$ = $1;}
                    ;

declaration_specifiers : type_specifier {$$ = $1;}
                       | type_specifier declaration_specifiers {$$ = new Declaration_Specifier($1, $2);}
                       ;

struct_declarator : declarator
                  | type_specifier declarator ':' constant_expression
                  ;

specifier_qualifier_list : type_specifier specifier_qualifier_list
                         ;

struct_declaration : specifier_qualifier_list struct_declaration_list 
                   ;

struct_declaration_list : struct_declaration 
                        | struct_declaration_list struct_declaration
                        ;

declarator : pointer direct_declarator
           | direct_declarator 

direct_declarator : IDENTIFIER {$$ = new Variable(*$1); }
	                | '(' declarator ')' {$$ = $2;}
                  | direct_declarator '[' constant_expression ']'
                  | direct_declarator '[' ']'
                  | direct_declarator '(' parameter_type_list ')' {$$ = new Function($1, $3);} // ??????????? NOT CORRECT
                  | direct_declarator '(' identifier_list ')'
                  | direct_declarator '(' ')' {$$ = $1;}
                  ;

identifier_list : IDENTIFIER {$$ = new Variable(*$1);}
	              | identifier_list ',' IDENTIFIER
	              ;

pointer : '*' 
        | '*' pointer
        ;

declaration : declaration_specifiers ';' 
            ;

declaration_list : declaration 
                 | declaration_list declaration
                 ;

type_specifier : VOID 
               | CHAR
               | INT { $$ = new std::string("int"); }
               | enum_specifier
               | STRUCT
               ;


enum_specifier : ENUM '{' enum_list '}'
               | ENUM IDENTIFIER '{' enum_list '}'
               | ENUM IDENTIFIER
               ;

enum_list: enumerator
         | enum_list ',' enumerator
         ;

enumerator: IDENTIFIER
          | IDENTIFIER '=' constant_expression
          ;

parameter_type_list: parameter_list
	                 ;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	;

//statement
statement : if_statement 
          | while_statement
          | for_statement
          | switch_statement
          | expression_statement {$$ = $1;}
          | skip_statement {$$ = $1;}
          | compound_statement {$$ = $1;}
          ;

if_statement : IF '(' expression ')' statement
	            | IF '(' expression ')' statement ELSE statement
              ;

while_statement : WHILE '(' expression ')' statement
                | DO '{' statement '}' WHILE '(' expression ')'';'
                ;

for_statement : FOR '(' expression_statement expression_statement expression ')' statement
              ;

switch_statement : SWITCH '(' expression ')''{' case_statement '}'
                 | SWITCH '(' expression ')''{' case_statement DEFAULT ':' statement '}'
                 ;

case_statement : CASE constant_expression ':' statement
               | CASE constant_expression ':' statement case_statement
               ;

statement_list : statement {$$ = $1;}
               | statement_list statement {$$ = $2;}
               ;

skip_statement : BREAK ';'
               | CONTINUE ';'
               | RETURN expression_statement {$$ = new ReturnStatement($2); }
               ;

expression_statement : ';'
                     | expression';' {$$ = $1;}
                     ;

compound_statement: '{' statement_list '}' {$$ = $2;}
                  | '{' declaration_list '}'
                  | '{' declaration_list statement_list '}'
                  ;


%%

const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}