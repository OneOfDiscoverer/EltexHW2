#ifndef _BASIC_H
#define _BASIC_H

#define PROTOTYPES "int add(int a, int b);int sub(int a, int b);int mul(int a, int b);int divide(int a, int b);\n"

char str[256] = PROTOTYPES;

char* init(void);

int add(int a, int b);

int sub(int a, int b);

int mul(int a, int b);

int divide(int a, int b);

#endif