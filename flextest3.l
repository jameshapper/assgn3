%{
# include <stdio.h> 
# include "hashtest.h"
%}

LET [A-Za-z_]
DIG [0-9] 
WS [ \t\r\n]
PUNC [~‘!@#$%^&*()_+-={}|\\\[\]:;\"\’<>,./?]

%% 

{LET}+"’"({LET}+)           { hasher(yytext); } 
{LET}+                      { hasher(yytext); }
{LET}+{DIG}+                { hasher(yytext); }
{PUNC}+                     {}
{WS}+                       {}
<<EOF>>                     { return -1; }
.                           {}

%% 

int main(void) { 
    yylex();
    
    // printf("hash1: %u \n", hasher(yytext));
}
