#include "basic.h"

int add(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mul(int a, int b){
    return a * b;
}

int divide(int a, int b){
    if(b == 0) 
        return __INT32_MAX__;
    return a / b;
}