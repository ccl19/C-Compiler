%code requires{
  #include "ast.hpp"
  #include <iostream>
  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out
  
  int yylex(void);
  void yyerror(const char *);
}

%union{
    Node* expr;
    std::string *string;
    double number;
    CompoundStatement* statementList;
    ParameterList* paramList;
    translation_unit* extDec;
    FunctionList* functionList;
    PrimExpression* primList;
    EnumStatement* enumList;
}

%token IDENTIFIER INT_LITERAL STRING_LITERAL FLOAT_LITERAL CHAR_LITERAL
%token INC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NEQ_OP
%token AND_OP OR_OP SIZEOF DEC_OP

%token CHAR INT FLOAT UNSIGNED
%token ENUM DOUBLE

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR BREAK RETURN

%type <expr> primary_expression unary_expression 
%type <expr> additive_expression multiplicative_expression shift_expression
%type <expr> relational_expression equality_expression and_expression 
%type <expr> exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <expr> conditional_expression expression function_call

%type <expr> enum_specifier enumerator 
%type <expr> direct_declarator

%type <expr> function_definition external_declaration 

%type <expr> if_statement while_statement for_statement switch_statement case_statement
%type <expr> skip_statement expression_statement
%type <expr> top statement brackets function_declarator statementCASE
%type <expr> parameter_declaration sizeOf break 
%type <string> type_specifier

%type <statementList> compound_statement compound_statementCASE
%type <paramList> parameter_list
%type <primList> primary_expression_list
%type <extDec> translation_unit
%type <functionList> functions
%type <enumList> enumerator_list

%type <number> INT_LITERAL FLOAT_LITERAL
%type <string> IDENTIFIER CHAR_LITERAL STRING_LITERAL

%start top

%%


top : translation_unit { g_root = $1; }

translation_unit : external_declaration { $$ = new translation_unit($1);}
                 | translation_unit external_declaration { $$ -> addExtDec($2);}
                 ;

external_declaration : function_definition { $$ = $1; }
                     | function_declarator {$$ = $1;}
                     ;

functions : function_definition {$$ = new FunctionList($1);}
          | functions function_definition {$$ -> addFuncList($2);}

function_definition : type_specifier direct_declarator brackets {$$ = new Function(*$1,$2,$3);}
                    | type_specifier direct_declarator '(' parameter_list ')' brackets {$$ = new Function(*$1,$2,$4,$6);}
                    | type_specifier direct_declarator '('')' brackets {$$ = new Function(*$1,$2,$5);}
                    ;

function_declarator : type_specifier direct_declarator '('')' ';'  {$$ = new FunctionDeclaration($2);}
                    | type_specifier direct_declarator '('parameter_list')' ';'  {$$ = new FunctionDeclaration($2,$4);}
                    | type_specifier direct_declarator '[' INT_LITERAL ']' ';'{$$ = new Array(*$1, $2, $4, false, true);}
                    | enum_specifier {$$ =$1;}
                    ;

type_specifier : INT { $$ = new std::string("int");}
               | FLOAT { $$ = new std::string("float");}
               | CHAR { $$ = new std::string("char");}
               | UNSIGNED { $$ = new std::string("unsigned");}
               | DOUBLE { $$ = new std::string("double");}
               ;


direct_declarator : IDENTIFIER  {$$ = new Variable(*$1);}
                  ;

parameter_list : parameter_declaration {$$ = new ParameterList($1);}
               | parameter_list ',' parameter_declaration {$$ -> AddParam($3);}
               ;

brackets : '{' compound_statement '}' {$$ = $2;}
         ;

compound_statement : statement {$$ = new CompoundStatement($1);}
                   | compound_statement statement {$$ -> AddStatement($2);}
                   | compound_statement '{' compound_statement '}'
                   ;

statement : skip_statement {$$ = $1;}
          | expression_statement {$$ = $1;}
          | if_statement {$$ = $1;}
          | while_statement {$$ = $1;}
          | for_statement {$$ = $1;}
          | case_statement {$$ = $1;}
          | switch_statement {$$ = $1;}
          | break {$$ = $1;}
          ;

statementCASE : skip_statement {$$ = $1;}
              | expression_statement {$$ = $1;}
              | if_statement {$$ = $1;}
              | while_statement {$$ = $1;}
              | for_statement {$$ = $1;}
              | switch_statement {$$ = $1;}
              | break {$$ = $1;}
              ;

compound_statementCASE : statementCASE {$$ = new CompoundStatement($1);}
                       | compound_statementCASE statementCASE {$$ -> AddStatement($2);}
                       | compound_statementCASE '{' compound_statementCASE '}'
                       ;

if_statement : IF '(' expression ')' '{' compound_statement '}' {$$ = new IfElseStatement($3, $6, NULL);}
	           | IF '(' expression ')' '{' compound_statement '}' ELSE '{' compound_statement '}' {$$ = new IfElseStatement($3, $6, $10);}
             ;

while_statement : WHILE '(' expression ')' '{' compound_statement '}' {$$ = new WhileStatement($3, $6, false);}
                | DO '{' compound_statement '}' WHILE '(' expression ')'';' {$$ = new WhileStatement($7, $3, true);}
                | WHILE '(' expression ')' '{' '}' {$$ = new WhileStatement($3, false);}
                ;

for_statement :  FOR '(' expression_statement expression_statement expression ')' '{' compound_statement '}' {$$ = new ForStatement($3,$4,$5,$8);}
              |  FOR '(' expression_statement expression_statement expression ')' '{''}' {$$ = new ForStatement($3,$4,$5);}
              ;

skip_statement : RETURN expression_statement {$$ = new ReturnStatement($2);}
               ;

switch_statement : SWITCH '(' expression ')' brackets {$$ = new SwitchStatement($3, $5);}
                 ;


case_statement : CASE expression ':' compound_statementCASE {$$ = new CaseStatement($2, $4);}
               | DEFAULT ':' compound_statementCASE {$$ = new DefaultStatement($3);}
               ;

break : BREAK ';' {$$ = new Break();}

expression_statement : ';'
                     | expression';' {$$ = $1;}
                     ;
                     
expression : direct_declarator '=' expression {$$ = new VarDeclaration($1,$3);}
           | INT_LITERAL {$$ = new Constant("int",$1);}
           | FLOAT_LITERAL {$$ = new Constant("float",$1);}
           | CHAR_LITERAL{$$ = new String(*$1);}
           | type_specifier direct_declarator {$$ = new Declaration_Specifier(*$1, $2);}
           | conditional_expression {$$ = $1;}
           | function_call {$$ = $1;}
           | direct_declarator  {$$ = $1;}
           | type_specifier direct_declarator '=' logical_or_expression {$$ = new VarDeclaration(*$1, $2, $4);}
           | type_specifier direct_declarator '[' INT_LITERAL ']' {$$ = new Array(*$1, $2, $4, true, false);}
           | direct_declarator '[' expression ']' '=' logical_or_expression {$$ = new ArrayAssignment($1, $3, $6);}
           | direct_declarator '[' expression ']' {$$ = $1;}
           | sizeOf {$$ = $1;}
           ;

enum_specifier : ENUM '{' enumerator_list '}' ';' {$$ = new Enum($3);}
               | ENUM IDENTIFIER '{' enumerator_list '}' ';' {$$ = new Enum(*$2,$4);}
               | ENUM IDENTIFIER {$$ = new Enum (*$2);}
               ;

enumerator_list : enumerator {$$ = new EnumStatement($1);}
                | enumerator_list ',' enumerator {$$ -> AddEnum($3);}
                ;

enumerator : direct_declarator {$$ = $1;}
           | direct_declarator '=' expression {$$ = new VarDeclaration($1,$3);}
           ;

sizeOf : SIZEOF '(' direct_declarator ')' {$$ = new SizeOf($3);}
       | SIZEOF '(' type_specifier ')' {$$ = new SizeOfInst(*$3);}
       ;
           
primary_expression_list : primary_expression {$$ = new PrimExpression($1);}
                        | primary_expression_list ',' primary_expression {$$ -> AddExpr($3);}
                        ;

function_call : IDENTIFIER '(' ')' {$$ = new FunctionCall(*$1);}
              | IDENTIFIER '(' primary_expression_list ')' {$$ = new FunctionCall(*$1,$3);}
              ;

parameter_declaration : type_specifier direct_declarator {$$ = new Parameter(*$1,$2);}
                      ;


primary_expression : INT_LITERAL {$$ = new Constant("int", $1);}
                   | FLOAT_LITERAL {$$ = new Constant("float", $1);}
                   | IDENTIFIER {$$ = new Variable(*$1);}
                   | direct_declarator '[' expression ']' {$$ = $1;}
                   | '(' expression ')'
                   ;

unary_expression : unary_expression INC_OP {$$ = new IncrementOperator($1);}
                 | unary_expression INC_OP {$$ = new DecrementOperator($1);}
                 | unary_operator unary_expression {$$ = $2;}
                 | primary_expression {$$ = $1;}
                 ;

unary_operator : '&'
               | '-'
               | '+'
               | '!'
               | '*'
               ;

multiplicative_expression : unary_expression {$$ = $1;}
                          | multiplicative_expression '*' unary_expression {$$ = new MultOperator($1, $3);} 
                          | multiplicative_expression '/' unary_expression {$$ = new DivOperator($1, $3);}
                          | multiplicative_expression '%' unary_expression {$$ = new ModOperator($1, $3);} 

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

conditional_expression : logical_or_expression {$$ = $1;}
                       | conditional_expression '?' compound_statement ':' compound_statement {$$ = new ConditionalOperator($1, $3, $5);}
                       ;

%%

const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
