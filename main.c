#include "main.h"

int main(void){
    command cmd;
    printf("helloworld\n");
    while(1){
        switch (getCmd(&cmd))
        {
            case 'a':
                printf("%d", mul(5, 5));
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