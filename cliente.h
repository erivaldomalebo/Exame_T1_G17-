#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_STR 100

typedef struct c
{
    char name[MAX_STR];
    struct c *prox;
} Cliente;

#endif
