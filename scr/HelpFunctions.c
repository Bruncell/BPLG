#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HelpFunctions.h"
#include "GeneralConstants.h"

void ClearBuffer(char bufer[LINE_LENGTH])
{
    for(int i = 0; i < LINE_LENGTH; i++)
    {
    bufer[i] = 0;
    }
}
