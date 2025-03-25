#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

typedef struct node
{
    int data;
    struct node *next;
} NodeT;

void freeLL(NodeT *list)
{
    NodeT *p, *temp;

    p = list;
    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
}

// to modified
void showLL(NodeT *list)
{
    NodeT *p;
    for (p = list; p != NULL; p = p->next)
        printf("%6d", p->data);
}

// NodeT *joinLL(NodeT *list, int v): returns a pointer to the linked list obtained by appending a new element with data v at the end of list.
NodeT *joinLL(NodeT *list, int v)
{
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

void main()
{
    NodeT *list = NULL; // 初始链表为空
    char input[100];    // 用于存储用户输入
    int value;
    while (1)
    {
        printf("Enter an integer: ");
        scanf("%d", &value);
        if (!isdigit(value))
        {
            list = joinLL(list, value);
        }
        else {
            break;
        }
    }

    // 打印链表
    printf("Linked List: ");
    showLL(list);

    // 释放链表内存
    freeLL(list);
}
