#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lexer.h"
#include "HelpFunctions.h"
#include "GeneralConstants.h"

#define KEYWORDS 256



void lexer(char *Temp, FILE *InputFile, Token Tokens[TOKEN_MAX_COUNT], int *TokenCount)
{
char Line[LINE_LENGTH];

KeywordEntry Keywords[KEYWORDS] = 
{
    {"int", TOK_INT},
    {"print", TOK_PRINT}

};


rewind(InputFile);
ClearBuffer(Line);

char Word[LINE_LENGTH];

while (fgets(Line, LINE_LENGTH, InputFile) != NULL) 
{
    ClearBuffer(Word);
    int i = 0;
    int j = 0;



 while (Line[i] != '\n' && Line[i] != 0 && Line[i] != ';') 
 {

    if (Line[i] == ' ') { i++; continue; }
    
    

    
    Word[j] = Line[i];
    i++;
    j++;


 }

Tokens[*TokenCount].Type = TOK_VAR;
        for(int i = 0; i < KEYWORDS; i++)
        {
            
                if(strcmp(Word, Keywords[i].Keyword) == 0)
                {
printf("=%s=", Word);
printf("'%s'", Keywords[i].Keyword);
                 Tokens[*TokenCount].Type = Keywords[i].type;
                }
        }


    ClearBuffer(Word);
    (*TokenCount)++;

            if (Line[i] == ';') 
            {
                Tokens[*TokenCount].Type = TOK_END;
                (*TokenCount)++;
                i++;
                continue;
            }

}
}