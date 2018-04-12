#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkstack.h"


//初始化，创建一个空的链表栈
LinkNode* LinkStackInit(LinkNode** phead)
{
    *phead=NULL;
    return *phead;
}

void DestroyNode(LinkNode* node)
{
    free(node);
}

//创建节点
LinkNode* CreateNode(LinkStackType value)
{
    LinkNode* new_node=(LinkNode*)malloc(sizeof(LinkNode));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}

//入栈（头插）
void LinkStackPush(LinkNode** phead,LinkStackType value)
{
    if(phead==NULL)
    {
        return;
    }
    //下面开始入栈，头插
    LinkNode* new_node=CreateNode(value);
    new_node->next=*phead;
    *phead=new_node;
}

//出栈（头删）
void LinkStackPop(LinkNode** phead)
{
    if(phead==NULL)
    {
        return;
    }
    if(*phead==NULL)
    {
        return;
    }
    LinkNode* to_remove=*phead;
    DestroyNode(to_remove);
    *phead=(*phead)->next;
    return;
} 


//取栈顶元素
int LinkStackTop(LinkNode* head,LinkStackType* value)
{
    if(head==NULL)
    {
        return 0;
    }
    
    value=&(head->data);
    printf("取到的栈顶元素是：%c \n",*value);
    return 1;
}


//////////////////////////////////////////////////////////////////////
//以下为测试函数
//////////////////////////////////////////////////////////////////////
void LinkPrintChar(LinkNode* head,const char* msg)
{
    printf("%s\n",msg);
    LinkNode* cur=head;
   for(;cur!=NULL;cur=cur->next) 
    {
        printf("[%c | %p]",cur->data,cur);
    }
   printf("\n");
}
void Test()
{
    printf("===================== %s =================\n",__FUNCTION__);
    LinkNode* head;
    LinkStackInit(&head);
    
    LinkStackPush(&head,'a');
    LinkStackPush(&head,'b');
    LinkStackPush(&head,'c');
    LinkStackPush(&head,'d');
    LinkPrintChar(head,"测试入栈四个元素");

    LinkStackPop(&head);
    LinkPrintChar(head,"出栈一个元素");
    LinkStackPop(&head);
    LinkPrintChar(head,"再出栈一个元素");

    LinkStackType* value=NULL;
    int ret=LinkStackTop(head,value);
    printf("返回值期望是1，实际是：[ %d ]\n",ret);
}

void main()
{
    Test();
    return;
}


