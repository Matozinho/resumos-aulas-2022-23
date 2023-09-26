%option noyywrap
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "parser.tab.h"

  int lineno = 1; // initialize to 1
  void ret_print(char *token_type);
  void yyerror();
%}


alpha       [a-zA-Z]
digit       [0-9]

ID          ({alpha}|_)({alpha}|{digit}|_)*
NUMBER      {digit}+(\.{digit}+)?

%%

"if"        {  ret_print("IF"); return IF; }
"then"      {  ret_print("THEN"); return THEN; }
"else"      {  ret_print("ELSE"); return ELSE; }
"end"       {  ret_print("END"); return END; }
"repeat"    {  ret_print("REPEAT"); return REPEAT; }
"until"     {  ret_print("UNTIL"); return UNTIL; }
"read"      {  ret_print("READ"); return READ; }
"write"     {  ret_print("WRITE"); return WRITE; }

"("         {  ret_print("LPAREN"); return LPAREN; }
")"         {  ret_print("RPAREN"); return RPAREN; }
";"         {  ret_print("SEMICOLON"); return SEMICOLON; }

":="        {  ret_print("ASSIGN"); return ASSIGN; }
"<"|"="     {  ret_print("REL_OP"); return REL_OP; }
"+"|"-"     {  ret_print("ADD_OP"); return ADD_OP; }
"*"|"/"     {  ret_print("MUL_OP"); return MUL_OP; }

{ID}        {  ret_print("ID"); return ID; }
{NUMBER}    { ret_print("NUMBER"); yylval = atof(yytext); return NUMBER; }

"\n"            { lineno += 1; }

[ \t\r\f]+          /* eat up whitespace */
.               { yyerror("Unrecognized character"); }

%%

void ret_print(char *token_type){
    printf("yytext: %s\ttoken: %s\tline: %d\n", yytext, token_type, lineno);
}
 
//void yyerror(char *message){
//    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
//    exit(1);
//}
 
//int main(int argc, char *argv[]){
//    yyin = fopen(argv[1], "r");
//    yylex();
//    fclose(yyin);
//    return 0;
//}
