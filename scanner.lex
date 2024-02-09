%{
// #include"tokens.hpp"
#include "node.hpp"
#include "source.tab.hpp"
%}
%option yylineno
%option noyywrap
binop (\+|-|\*|\/)
digit ([0-9])
num (0|[1-9]{digit}*)	
letter ([a-zA-Z])
whitespace ([\t\n\r ])
string \"([^\n\r\"\\]|\\[rnt"\\])+\"
relop (==|!=|<|>|<=|>=)
id {letter}+({letter}|{digit})*
%%
{whitespace};
int {yylval = };
byte return BYTE;
b return B;
bool return BOOL;
and return AND;
or  return OR;
not return NOT;
true return TRUE;
false return FALSE;
return return RETURN;
if return IF;
else return ELSE;
while return WHILE;
break return BREAK;
continue return CONTINUE;
; return SC;
\( return LPAREN;
\) return RPAREN;
"{" return LBRACE;
"}" return RBRACE;
= return ASSIGN;
{relop} return RELOP;
{binop} return BINOP;
{num} return NUM;
{id}  return ID;
{string} return STRING;
. return ERR;
%%
