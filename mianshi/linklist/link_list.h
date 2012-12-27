#ifndef TWO_LINK_LIST
#define TWO_LINK_LIST

struct link_node
{
	int data;
	struct link_node *next;
};

struct link_node * createLink(int n);
int insertNode(struct link_node * head, int n);
int deleteNode(struct link_node * head, int n);
int showLink(struct link_node * head);
int invertListout(struct link_node * head);
#endif
