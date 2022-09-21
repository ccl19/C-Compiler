%option noyywrap
%option yylineno

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */
#include <stdio.h>
#include <iostream>
#include "parser.tab.hpp"
#include <string>

// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}

D                   [0-9]
L                   [a-zA-Z]
H			           [a-fA-F0-9]
E			           [Ee][+-]?{D}+
FS			           (f|F|l|L)
IS			           (u|U|l|L)* 

/* FS: float suffix */
/* IS: int suffix */

%%

"int"           {return (INT);}
"double"        {return (DOUBLE);}
"float"         {return (FLOAT);}
"unsigned"      {return (UNSIGNED);}
"while"         {return (WHILE);}
"if"            {return (IF);}
"else"          {return (ELSE);}
"enum"          {return (ENUM);}
"break"         {return (BREAK);}   
"default"       {return (DEFAULT);}   
"for"           {return (FOR);}
"switch"        {return (SWITCH);}
"case"          {return (CASE);}
"char"          {return (CHAR);}
"return"        {return (RETURN);}
"sizeof"        {return (SIZEOF);}

"&&"            {return (AND_OP);}
"||"            {return (OR_OP);}
"++"            {return (INC_OP);}
"--"            {return (DEC_OP);}
">>"			    {return (RIGHT_OP);}
"<<"			    {return (LEFT_OP);} 
"=="			    {return (EQ_OP);}
"!="			    {return (NEQ_OP);}
"<="			    {return (LE_OP);}
">="			    {return (GE_OP);}

"."             {return ('.');}
","             {return (',');}
":"             {return (':');}
";"             {return (';');}
"("             {return ('(');}
")"             {return (')');}
"["             {return ('[');}
"]"             {return (']');}
"{"             {return ('{');}
"}"             {return ('}');}
"+"             {return ('+');}
"-"             {return ('-');}  
"*"             {return ('*');}      
"/"             {return ('/');}
"="             {return ('=');}
"%"             {return ('%');}
"!"             {return ('!');}
">"             {return ('>');}
"<"             {return ('<');}
"^"			    {return ('^');}
"|"			    {return ('|');}
"?"			    {return ('?');}
"&"			    {return ('&');}

{L}({L}|{D})*		         {yylval.string = new std::string(yytext); return(IDENTIFIER);}

0[xX]{H}+{IS}?		         {yylval.number = stod(std::string(yytext)); return(INT_LITERAL);}
0{D}+{IS}?		            {yylval.number = stod(std::string(yytext)); return(INT_LITERAL);}
{D}+{IS}?		            {yylval.number = stod(std::string(yytext)); return(INT_LITERAL);}

{D}+{E}{FS}?		         {yylval.number = stod(std::string(yytext)); return(FLOAT_LITERAL);}
{D}*"."{D}+({E})?{FS}?	   {yylval.number = stod(std::string(yytext)); return(FLOAT_LITERAL);}
{D}+"."{D}*({E})?{FS}?	   {yylval.number = stod(std::string(yytext)); return(FLOAT_LITERAL);}

L?\"(\\.|[^\\"])*\"	      {return(STRING_LITERAL);}

\'(\\.|[^\\"])*\'	         {return(CHAR_LITERAL);}



[ \t\v\n\f]		            { }
.			                  { }


%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}