%%
"{"                     { return LBRACE; }
"}"                     { return RBRACE; }
"int"                   { return INT; }
"char"                  { return CHAR; }
[a-zA-Z][a-zA-Z0-9]*    { return ID; }
";"                     { return SEMI; }
"="                     { return EQ; }
"+"                     { return PLUS; }
"*"                     { return MULT; }
\"[a-zA-Z0-9]+\"        { return STRING; }
[0-9]+                  { return NUM; }
[ \t\n]+                { /* */ }
.                       { /* */ }
