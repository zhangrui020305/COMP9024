#include "stdio.h"

void freeLL(NodeT *list) {
   NodeT *p, *temp;

   p = list;
   while (p != NULL) {
      temp = p->next;
      free(p);
      p = temp;
   }
}