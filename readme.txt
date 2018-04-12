这是用不带头结点的单链表实现一个链表栈
实现栈的入栈（头插）、出栈（头删）、取栈顶元素

有个bug：
    收到 SIGABRT 信号
    *** glibc detected *** ./1: free(): invalid pointer错误


修改bug：
    LinkStackTop()函数中，修改了"value=&(head->data);"
