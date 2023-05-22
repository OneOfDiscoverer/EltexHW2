#ifndef _COMMAND_H
#define _COMMAND_H

#ifndef STR_LEN
#define STR_LEN 16
#endif

#include <stdio.h>

struct command
{
    char param0[STR_LEN];
    //COMMAND_INS;  
}typedef command;


char getCmd(command* cmd);

#endif