#include "main.h"

void attach(char* str, char* name){
    book tmp;
    memset(&tmp, 0, sizeof(tmp));
    memcpy(&tmp.name, name, STR_LEN); //notsafety copy!
    tmp.pointer = dlopen(str, RTLD_LAZY);
    char* (*func)();
    if(func = dlsym(tmp.pointer, "init")){
        memcpy(&tmp.protorype, func(), STR_LEN); //notsafety copy!
        pushBack(&tmp);
    }
    else 
        printf("plugin not exist \"init\" %s\n", name);
}

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
                    double (*foo)(double, double);
                    foo = 0;
                    int i = 0;
                    while(1){
                        list* ptr;
                        ptr = getAt(i++);
                        if(!ptr)
                            break;
                        if(foo = dlsym(ptr->bk.pointer, cmd.param1))
                            break;
                    }
                    if(foo) {
                        printf("%.2f\n", foo(atof(cmd.param2), atof(cmd.param3)));
                    }
                    else 
                        printf("func not found in active lib's\n");
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