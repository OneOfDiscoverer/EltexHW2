#ifndef _COMMAND_H
#define _COMMAND_H

#ifndef STR_LEN
#define STR_LEN 256
#endif

#include <stdio.h>

struct command
{
    char param0[STR_LEN];
    char param1[STR_LEN];
    char param2[STR_LEN];
    char param3[STR_LEN];
}typedef command;


char getCmd(command* cmd);

#endif