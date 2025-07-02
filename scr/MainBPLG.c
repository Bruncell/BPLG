#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Structs.h"
#include "Lexer.h"
#include "HelpFunctions.h"


static void GetFileName(char NameOfFile[]);

int main()
{
///VARIABLES
    //ASTNode nodes[NODES_MAX_COUNT];
    int NodeCount = 0;

    Token Tokens[TOKEN_MAX_COUNT];
    int TokenCount = 0;

    char Temp[LINE_LENGTH];
    char NameOfFile[FILE_NAME_LENGTH];
///

    GetFileName(NameOfFile);

    snprintf(Temp, FILE_NAME_LENGTH + 6, "%s.bplg", NameOfFile);
    FILE* InputFile = fopen(Temp, "r");
    if (!InputFile)
    {
        printf("\nFailed to open file!\nMake sure that the file %s exists.\n\n", Temp);
        return 1;
    }

    snprintf(Temp, FILE_NAME_LENGTH + 6, "%s.asm", NameOfFile);
    FILE* OutputFile = fopen(Temp, "w");
    if (!OutputFile)
    {
        printf("\nFailed to read file!\n\n");
        return 1;
    }

lexer(Temp, InputFile, Tokens, &TokenCount);

for(int i = 0; i < TokenCount; i++)
{
printf("\n\n Token: %d \n Type: %d ", i, Tokens[i].Type);
}


return 0;
}

static void GetFileName(char NameOfFile[])
{

    printf("\nEnter file name: ");

    if (scanf("%s", NameOfFile) != 1) 
    {
    printf("\nError entering file name\n");
    return;
    }

}