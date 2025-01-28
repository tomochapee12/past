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

block : LBRACE declpart usepart RBRACE
      ;

declpart : decls
         ;

decls : decls decl
      | decl
      ;

decl : INT ID SEMI
     | CHAR ID SEMI
     ;

usepart : stmts
        ;

stmts : stmts st
      | st
      ;

st : ID EQ E SEMI
   | ID EQ STRING SEMI
   | block
   ;

E : E PLUS T
  | T
  ;

T : T MULT F
  | F
  ;

F : ID
  | NUM
  ;

%%

#include "lex.yy.c"

int main(void){
  yyparse();
  return 0;
}

