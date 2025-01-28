%{
#include "list.h"

listtype head;
listtype tail;

#undef YYSTYPE
#define YYSTYPE char*
int yylex();
int yyerror(char const *);
%}

%token LBRACE RBRACE
%token INT CHAR
%token ID
%token SEMI
%token EQ
%token STRING
%token NUM
%token PLUS
%token MULT
%%

program : block
        ;

block : { addlist(&tail, "", block); }
        LBRACE declpart usepart RBRACE
        { print(head, tail); deleteblock(&tail); }
      ;

declpart : decls
         ;

decls : decls decl
      | decl
      ;

decl : INT ID SEMI
       {
         listtype tmp;
         tmp = searchIDblock(tail, $2);
         if (tmp != NULL){
           printf("%s has already been declared!\n", $2);
           exit(1);
         }
         addlist(&tail, $2, integer);
       }
     | CHAR ID SEMI
       {
         listtype tmp;
         tmp = searchIDblock(tail, $2);
         if (tmp != NULL){
           printf("%s has already been declared!\n", $2);
           exit(1);
         }
         addlist(&tail, $2, character);
       }
     ;

usepart : stmts
        ;

stmts : stmts st
      | st
      ;

st : ID EQ E SEMI
     {
       listtype tmp;
       tmp = searchID(head, tail, $1);
       if (tmp == NULL){
         printf("%s is not declared!\n", $1);
         exit(1);
       }
       if (tmp->type != integer){
         printf("%s is unable to be asigned non-integer value!\n", $1);
         exit(1);
       }
     }
   | ID EQ STRING SEMI
     {
       listtype tmp;
       tmp = searchID(head, tail, $1);
       if (tmp == NULL){
         printf("%s is not declared!\n", $1);
         exit(1);
       }
       if (tmp->type != character){
         printf("%s is unable to be asigned non-character value!\n", $1);
         exit(1);
       }
     }
   | block
   ;

E : E PLUS T
  | T
  ;

T : T MULT F
  | F
  ;

F : ID
    {
      listtype tmp;
      tmp = searchID(head, tail, $1);
      if (tmp == NULL){
        printf("%s is not declared!\n", $1);
        exit(1);
      }
      if (tmp->type != integer){
        printf("%s is not declared as integer!\n", $1);
        exit(1);
      }
    }
  | NUM
  ;

%%

#include "list.c"

#include "lex.yy.c"

int main(void){
  initlist(&head, &tail);
  yyparse();
  print(head, tail);
  return 0;
}

#include "yywraperror.c"

