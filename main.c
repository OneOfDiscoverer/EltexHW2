#include "main.h"

void attach(char* str, char* name){
    book tmp;
    tmp.pointer = dlopen(str, RTLD_LAZY);
    for(int i = 0; i < 256; i++){
        tmp.name[i] = name[i];
        if(!name[i]){
            break;
        } 
    }
    char* (*func)();
    *(void**)(&func) = dlsym(tmp.pointer, "init");
    if(func){
        for(int i = 0; i < 256; i++){
            if(func()[i] == ';') 
                tmp.protorype[i] = '\n';
            else if(func()[i] == '\n' || !func()[i]) 
                break;
            else
                tmp.protorype[i] = func()[i];
        }
        pushBack(&tmp);
    }
    else 
        printf("wrong plugin format in %s\n", name);
}

int main(void){
    command cmd;
    DIR *dir;
    dir = opendir("./libs/");
    struct dirent *de;
    while ( ( de = readdir(dir) ) ) {
        if (!strcmp((de->d_name) + strlen(de->d_name) - 3, ".so")){
            char tmpstr[256] = "./libs/";
            strcat(tmpstr, de->d_name);
            attach(tmpstr, de->d_name);
        }
    }         
    closedir(dir);
    while(1){
        switch (getCmd(&cmd))
        {
            case 'l':
                {
                    list* tmp;
                    int i = 0;
                    while(1){
                        tmp = getAt(i++);
                        if(!tmp) 
                            break;
                        printf("%s\n%s\n", tmp->bk.name, tmp->bk.protorype);
                    }
                    break;
                }
            case 'c':
                void* (*foo)();
                foo = dlsym(getAt(1)->bk.pointer, cmd.param1);
                if(foo) 
                    printf("%d\n", foo(atoi(cmd.param2), atoi(cmd.param3)));
                else 
                    printf("wrong name\n");
                break;
            case 'q':{
                list* tmp;
                int i = 0;
                while(1){
                    tmp = getAt(i++);
                    if(!tmp) 
                        break;
                    dlclose(tmp->bk.pointer);
                }
                exit(0);
                break;
            } 
            default:

                break;
        }
    }
    return 0;
}