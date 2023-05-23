#include "main.h"

void attach(char* str){
    book tmp;
    tmp.pointer = dlopen(str, RTLD_LAZY);
    char* (*func)();
    *(void**)(&func) = dlsym(tmp.pointer, "name"); //attach init struct
    for(int i = 0; i < 256; i++){
        tmp.name[i] = func()[i];
        if(func()[i] == '\n') break;
    }
    *(void**)(&func) = dlsym(tmp.pointer, "init");
    for(int i = 0; i < 256; i++){
        
        if(func()[i] != ';') 
            tmp.protorype[i] = func()[i];
        else 
            tmp.protorype[i] = '\n';
        if(func()[i] == '\n') break;
    }
    pushBack(&tmp);
}

int main(void){
    command cmd;
    attach("./libs/libbasic.so");
    printf("%s%s", getAt(0)->bk.name, getAt(0)->bk.protorype);
    while(1){
        switch (getCmd(&cmd))
        {
            case 'c':
                void* (*foo)();
                *(void**)(&foo) = dlsym(getAt(0)->bk.pointer, cmd.param1);
                printf("%d\n", (int)foo(atoi(cmd.param2), atoi(cmd.param3)));
                break;
            case 'q': 
                exit(0);
                break;
            default:

                break;
        }
    }
    return 0;
}