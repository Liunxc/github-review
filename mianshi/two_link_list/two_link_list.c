#include <stdio.h>
#include <stdlib.h>
#include "two_link_list.h"

struct link_node *  createLink(int n)
{
	struct link_node *head;

	head = (struct link_node *)malloc(sizeof(*head));

	head->next = NULL;
	head->pre = NULL;
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

	if (NULL == head->next) {
		node->next = head->next;
		node->pre = head;
		head->next = node;
	} else {
		node->next = head->next;
		head->next->pre = node;
		head->next = node;
		node->pre = head;
	}

	return 0;
}

int deleteNode(struct link_node * head, int n)
{
	struct link_node *p = head->next;
	int tmp;

	while (p) {
		if (p->data == n) {
			p->pre->next = p->next;
			p->next->pre = p->pre;
			tmp = p->data;
			break;
		} else {
			p = p->next;
		}
	}

	if (tmp == n)
		return tmp;

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
