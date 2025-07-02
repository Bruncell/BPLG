#pragma once

#include "GeneralConstants.h"
#include "Structs.h"

void lexer(char line[LINE_LENGTH], FILE *InputFile, Token Tokens[TOKEN_MAX_COUNT], int *TokenCount);
