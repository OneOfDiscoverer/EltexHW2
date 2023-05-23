#include "main.h"

int main(void){
    command cmd;
    while(1){
        switch (getCmd(&cmd))
        {
            case 'a':
                void *plugin;
                plugin = dlopen("./libs/libbasic.so", RTLD_LAZY);
                char* (*func)();
                *(void**)(&func) = dlsym(plugin, "init"); //attach init struct
                printf("%s\n", func());
                dlclose(plugin);
                break;
            case 'c':
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