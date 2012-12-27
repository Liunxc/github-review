#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

struct link_node * createLink(int n)
{
	struct link_node *head;

	head = (struct link_node *)malloc(sizeof(*head));

	head->next = NULL;
	head->data = n;

	while (n) {
		insertNode(head, 0);
		n--;
	}

	return head;
}

int insertNode(struct link_node * head, int n)
{
	struct link_node *node;

	node = (struct link_node *)malloc(sizeof(*node));
	if (NULL == node) {
		return -1;
	}

	if (n == 0) {
		node->data = random() % 100;
	} else {
		node->data = n;
	}

	node->next = head->next;
	head->next = node;

	return 0;
}

int showLink(struct link_node * head)
{
	struct link_node *p = head->next;

	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}

	printf("\n");

	return 0;
}

int invertListout(struct link_node * head)
{
	struct link_node *sp, *node;

	if (NULL == head->next) {
		return -1;
	}
	sp = head->next;
	head->next = NULL;

	while (sp) {
		node = sp;
		sp = sp->next;
		node->next = head->next;
		head->next = node;
	}

	return 0;
}
