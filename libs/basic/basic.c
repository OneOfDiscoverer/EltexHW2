#include "basic.h"

char* init(void){
    return PROTOTYPES;
}

double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

double divide(double a, double b){
    if(b == 0) 
        return __DBL_MAX__;
    return a / b;
}