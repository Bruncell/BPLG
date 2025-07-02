#pragma once

#include "GeneralConstants.h"


typedef enum 
{
    TOK_INT,   //0
    TOK_PRINT, //1
    TOK_VAR,   //2
    TOK_END    //3


} TokenType;

typedef struct 
{
    TokenType Type;
    char TokenValue[LINE_LENGTH];
    int TokenNumValue;

} Token;

typedef struct 
{
    char Keyword[LINE_LENGTH];
    TokenType type;
} KeywordEntry;



