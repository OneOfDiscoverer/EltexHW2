#include "main.h"

void attach(char* str, char* name){
    book tmp;
    memset(&tmp, 0, sizeof(tmp));
    tmp.pointer = dlopen(str, RTLD_LAZY);
    memcpy(&tmp.name, name, STR_LEN);
   /* for(int i = 0; i < STR_LEN; i++){
        tmp.name[i] = name[i];
        if(!name[i]){
            break;
        } 
    }*/
    char* (*func)();
    *(void**)(&func) = dlsym(tmp.pointer, "init");
    
    if(func){
        memcpy(&tmp.protorype, func(), STR_LEN);
        /*char *symbol;
        symbol = func();
        for(int i = 0; i < STR_LEN; i++){
            if(symbol[i] == '\n')
                break;
            if(symbol[i] == ';') 
                tmp.protorype[i] = '\n';
            else
                tmp.protorype[i] = symbol[i];
        }*/
        pushBack(&tmp);
    }
    else 
        printf("wrong plugin format in %s\n", name);
}

/*void* search(char* name){
    tmpPtr = getAt(0);
    for(int b = 0; b < sizeof(tmpPtr->bk)/STR_LEN; b++){
        int result = 0;
        char* ptr = (char*)&tmpPtr->bk + STR_LEN*b;
        for(int j = 0; j < STR_LEN; j++){
            result += *(cmd.bk.firstName+j) - *(ptr+j);
        }
        if(!result)
            printUser(&tmpPtr->bk, i);
    }
    tmpPtr = getAt(++i);
}*/

int main(void){
    command cmd;
    while(1){
        switch (getCmd(&cmd))
        {
            case 'a':{
                    DIR *dir;
                    dir = opendir("./libs/");
                    struct dirent *de;
                    while (de = readdir(dir)) {
                        if (!strcmp((de->d_name) + strlen(de->d_name) - 3, ".so")){
                            char tmpstr[STR_LEN] = "./libs/";
                            int i = 0;
                            while(1){
                                list* tmp = getAt(i++);
                                if(!tmp) {
                                    strcat(tmpstr, de->d_name);
                                    attach(tmpstr, de->d_name);
                                    break;
                                }
                                if(!strcmp(tmp->bk.name, de->d_name))
                                    break;
                            }
                            
                            
                        }
                    }         
                    closedir(dir);
                    break;
                }
            case 'l':{
                    int i = 0;
                    while(1){
                        list* tmp = getAt(i++);
                        if(!tmp) 
                            break;
                        printf("%s\n%s\n", tmp->bk.name, tmp->bk.protorype);
                    }
                    break;
                }
            case 'c':{
                void* (*foo)();
                foo = dlsym(getAt(1)->bk.pointer, cmd.param1);
                if(foo) 
                    printf("%d\n", foo(atoi(cmd.param2), atoi(cmd.param3)));
                else 
                    printf("wrong name\n");
                break;
            }
            case 'q':{
                list* tmp;
                int i = 0;
                while(1){
                    tmp = getAt(i++);
                    if(!tmp) 
                        break;
                    dlclose(tmp->bk.pointer);
                    remove_at(i);
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