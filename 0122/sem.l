%%
"{" { return LBRACE; }
"}" { return RBRACE; }
"int" { return INT; }
"char" { return CHAR; }
[a-zA-Z][a-zA-Z0-9]* { char* tmp = malloc(strlen(yytext)+1);
                       if (tmp == NULL){
                         printf("memory error!\n");
                         exit(1);
                       }
                       strcpy(tmp, yytext);
                       yylval = tmp;
                       return ID;
                     }
";"                  { return SEMI; }
"="                  { return EQ; }
"+"                  { return PLUS; }
"*"                  { return MULT; }
\"[a-zA-Z0-9]+\"     { return STRING; }
[0-9]+               { return NUM; }
[ \t\n]+             { /* */ }
.                    { /* */ }
