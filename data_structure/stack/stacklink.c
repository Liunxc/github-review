#include "stacklink.h"

int push(struct stack_node *node, struct stack_node *sp)
{
	node->next = sp->next;
	sp->next = node;
	return 0;
}

struct stack_node *pop(struct stack_node *sp)
{
	struct stack_node *node;

	if (isempty(sp)) {
		printf("stack is empty!\n");
		return NULL;
	}
	node = sp->next;
	sp->next = node->next;
	return node;
}

bool isempty(struct stack_node *sp)
{
	if (NULL == sp->next)
		return true;

	return false;
}

int resrsion(const char *str)
{
	struct stack_node *sp = NULL, *node, *spw, *out;
	sp = (struct stack_node *)malloc(sizeof(*node));
	spw = (struct stack_node *)malloc(sizeof(*node));

	while (*str) {
		node = (struct stack_node *)malloc(sizeof(*node));
		if (NULL == node) {
			perror("maaloc");
			return -1;
		}

		node->data = *str++;
		node->next = NULL;
		push(node, sp);
	 }

	while (!isempty(sp)) {
		 do {
			node =(struct stack_node *)malloc(sizeof(*node));
			if (NULL == node) {
				perror("maaloc");
				return -1;
		}
			 node = pop(sp);
			 push(node, spw);
		} while (node->data != ' ');

		do {
			out = pop(spw);
			printf("%c", out->data);
			free(out);
		 } while (!isempty(spw));
	 }

     printf("\n");

	 return 0;
}
