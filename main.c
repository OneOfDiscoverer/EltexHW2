#include "main.h"

void attach(char* str){
    
}

int main(void){
    command cmd;
    while(1){
        void *plugin;
        switch (getCmd(&cmd))
        {
            case '+':
                {
                    book tmp;
                    char* str;
                    plugin = dlopen("./libs/libbasic.so", RTLD_LAZY);
                    char* (*func)();
                    *(void**)(&func) = dlsym(plugin, "name"); //attach init struct
                    str = func();
                    for(int i = 0; i < 256; i++){
                        tmp.name[i] = str[i];
                        if(str[i] == '\n') break;
                    }
                    *(void**)(&func) = dlsym(plugin, "init");
                    str = func();
                    for(int i = 0; i < 256; i++){
                        tmp.protorype[i] = str[i];
                        if(str[i] == '\n') break;
                    }
                    pushBack(&tmp);
                    printf("%s%s\n", tmp.name, tmp.protorype);
                }
                break;
            case 'c':
                break;
            case 'q': 
                exit(0);
                break;
            default:
                int (*foo)(int, int);
                *(void**)(&foo) = dlsym(plugin, cmd.param0);
                printf("%d\n", foo(atoi(cmd.param1), atoi(cmd.param2)));
                break;
        }
    }
    return 0;
}