#include "stdio.h"

typedef struct node {
   int data;
   struct node *next;
} NodeT;

void freeLL(NodeT *list) {
   NodeT *p, *temp;

   p = list;
   while (p != NULL) {
      temp = p->next;
      free(p);
      p = temp;
   }
}

// to modified
void showLL(NodeT *list) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      printf("%6d", p->data);
}

// NodeT *joinLL(NodeT *list, int v): returns a pointer to the linked list obtained by appending a new element with data v at the end of list.
NodeT *joinLL(NodeT *list, int v) {
    NodeT *newNode = malloc(sizeof())
}

void main() {

}