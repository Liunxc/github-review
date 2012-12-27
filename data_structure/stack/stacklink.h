//#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef char type;

typedef enum {
	false,
	true
} bool;

struct stack_node
{
	type data;
	struct stack_node *next;
};

int push(struct stack_node *node, struct stack_node *sp);
struct stack_node *pop(struct stack_node *sp);
bool isempty(struct stack_node *sp);
//int resrsion(const char *str);
