#pragma once

typedef char LinkStackType;

typedef struct LinkNode{
    LinkStackType data; 
    struct LinkNode* next;
} LinkNode;

typedef struct LinkStack{
    LinkNode* head;
    LinkNode* tail;//尾指针
} LinkStack;

//初始化，创建一个空的链表栈
LinkNode* LinkStackInit(LinkNode** phead);
//创建节点
LinkNode* CreateNode(LinkStackType value);
//入栈（头插）
void LinkStackPush(LinkNode** phead,LinkStackType value);
//出栈（头删）
void LinkStackPop(LinkNode** phead);
//取栈顶元素
int LinkStackTop(LinkNode* head,LinkStackType* value);
