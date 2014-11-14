#include<stdio.h>
#include<stdlib.h>
typedef struct child
{
    int num;
    struct child * next;
}child;

child * init_child(child * head, int n)
{
    int i;
    child * temp, * cur;

    //构造一个环形链表
    for (i = 1; i <= n; i++)
    {
        temp = (child *)malloc(sizeof(child));
        temp->num = i;
        if (i == 1)   //只有一个人的时候
        {
            head = temp; //让头指针指向分配的内存空间
            head->next = temp; //指向自己
            cur = head;        //记录当前，方便下面的操作
        }
        else
        {
            cur->next = temp;
            temp->next = head;
            cur = temp;
        }
    }
    return head;
}

void show_nu(child * head)
{
    child * cur;
    cur = head;
    printf("孩子们的编号为：\n");
    while (cur->next != head)       //在打印循环链表最后一个数时，判断成立，所以需要下面的printf()语句
    {
        printf("%d\t", cur->num);
        cur = cur->next;
    }
    printf("%d\n", cur->num);
}

/*
target 从第几个人开始数
num 数到编号为几的出列
*/ 
void start_game(child * head, int target, int num)
{
    child * tail; //跳到循环链表的最后一节点个位置, tail 的下一个节点就是head
    tail = head;
    int i;
    while (tail->next != head)
    {
        tail = tail->next;
    }
    
    //处理从第几个人开始数，让头指针head指向那个人
    for (i = 1; i < target; i++)  //头指针只需移动(target - 1)次
    {
        head = head->next;
        tail = tail->next;
    }
    
    //下面就是移动head和tail指针了，将不幸的孩子从循环链表中踢去
    //tail和head每移动一次相当于数2下，自己数不用移动;移动2次相当于数3下
    printf("被踢掉的编号为:\n");
    while (head != tail)
    {
        for (i = 1; i < num; i++)
        {
            head = head->next;
            tail = tail->next;
        }
        //移动完后，将head指向的那个删掉
       printf("%d\t", head->num);
       head = head->next;
       tail->next = head;
    }
    printf("\n最后留下的编号为: %d\n", head->num);
}

int main()
{
    child * head;  
    int total; //小孩的总数
    int target; //出列的数字
    int num;    //数到哪个编号出列
    printf("约瑟夫问题。\n");
    printf("请输入小孩的个数？孩子会从1到n进行编号：");
    scanf("%d", &total);
    printf("从编号几开始数：");
    scanf("%d", &target);
    printf("数到哪个编号出列：");
    scanf("%d", &num);

    //初始化,构造一个循环链表
    head = init_child(head, total);
    //打印小孩的编号
    show_nu(head);
    //开始最重要的操作了,要出列的小孩就遭殃了
    start_game(head, target, num);
    return 0;
}
