#include "command.h"

char getCmd(command* cmd){
    int i = 0;
    int const size = sizeof(command);
    char* ptr = (char*)cmd;
    for(int i = 0; i < size; i++){
        *((char*)cmd + i) = 0;
    }
    while((i < STR_LEN) && ((ptr + i) < ((char*)cmd + size))){
        char tmp = (char)fgetc(stdin);
        if(tmp == '\n')
            break;
        if(tmp == ' ') {
            i = 0;
            ptr = ptr + STR_LEN;
            continue;
        }
        *(ptr + i) = tmp;
        i++;
    }
    return *(char*)cmd;
}