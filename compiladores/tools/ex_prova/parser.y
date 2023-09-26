%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* yyin; // Add the external declaration for yyin

extern int yylex();
extern int yylineno;
extern char* yytext;

void yyerror(const char* message);
%}

%token IF THEN ELSE END REPEAT UNTIL READ WRITE ID NUMBER ASSIGN SEMICOLON
%token LPAREN RPAREN REL_OP ADD_OP MUL_OP

%%

program : cmd_seq
        ;

cmd_seq : cmd
        | cmd_seq SEMICOLON cmd
        ;

cmd : if_cmd
    | repeat_cmd
    | assign_cmd
    | read_cmd
    | write_cmd
    ;

if_cmd : IF exp THEN cmd_seq END
       | IF exp THEN cmd_seq ELSE cmd_seq END
       ;

repeat_cmd : REPEAT cmd_seq UNTIL exp
           ;

assign_cmd : ID ASSIGN exp
           ;

read_cmd : READ ID
         ;

write_cmd : WRITE exp
          ;

exp : simple_exp
    | simple_exp REL_OP simple_exp
    ;

simple_exp : term
           | simple_exp ADD_OP term
           ;

term : factor
     | term MUL_OP factor
     ;

factor : LPAREN exp RPAREN
       | NUMBER
       | ID
       ;

%%

void yyerror(const char* message) {
     fprintf(stderr, "Syntax error at line %d: %s. Token: %s\n", yylineno, message, yytext);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open input file.\n");
        return 1;
    }

    yyin = file;

    int result = yyparse();

    fclose(file);

    if (result == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}
