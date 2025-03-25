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
    NodeT *newNode = malloc(sizeof(NodeT));
    newNode->data = v;
    newNode->next = NULL;
    if (list == NULL)
    {
        return newNode;
    }

    NodeT *p = list;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    return list;
}

int main() {
   NodeT *list = NULL; // 初始链表为空
   char input[100];    // 用于存储用户输入
   int value;

   printf("Enter numbers to add to the linked list (non-number to stop):\n");

   while (1) {
      // 读取用户输入
      if (scanf("%s", input) != 1) {
         printf("Input error!\n");
         break;
      }

      // 检查输入是否为数字
      int isNumber = 1;
      for (int i = 0; input[i] != '\0'; i++) {
         if (!isdigit(input[i]) {
            isNumber = 0;
            break;
         }
      }

      // 如果不是数字，终止输入
      if (!isNumber) {
         printf("Non-number input detected. Stopping input.\n");
         break;
      }

      // 将输入转换为整数并添加到链表
      value = atoi(input);
      list = joinLL(list, value);
   }

   // 打印链表
   printf("Linked List: ");
   showLL(list);

   // 释放链表内存
   freeLL(list);

   return 0;
}
