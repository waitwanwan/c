#include<stdio.h>
#include<malloc.h>
struct node//node的結構設立
{
int data;
struct node *next;
};
struct node *create();//新node產生之外部函式
int main(void)
{
int ask;
int del;
struct node *head,*pnew,*p1,*p2;
head=NULL;
ask=-1;
printf("☆☆----Linked List----(鏈結串列)☆☆\n");
while(ask!=0) //ask==0時結束程式
{ //設立指令
    printf("\n◇指令:結束鍵入0，新增鍵入1，刪除鍵入2，列出鍵入3>");
    scanf("%d",&ask);
    if(ask<0 || ask>3) //在指令之外要求使用者重新輸入
    {
        printf("請重新輸入!!!\n");
        continue;
    }
    if(ask==1) //ask==1時新增資料
    {
        pnew=create();//產生一個新的節點(有依大小排序)
        if(head==NULL || head->data > pnew->data)
        { //head接地或單一node時的值大於欲新增的node的值
            pnew->next=head; //新node的next指向head所指的node
            head=pnew; //head指向新node
            continue; //跳出，回到上部的while
        }
        p1=head; //p1指向第一個node
        p2=head->next; //p2指向第二個node
        while(p2!=NULL) //p2沒接地時
        {
            if(p2->data>pnew->data)//當p2的node值大於新node的值時
            {
                pnew->next=p2;//新node的next指向p2
                p1->next=pnew;//p1的next指向新node
                break; //打斷前一個while
            }
                p1=p2; //p1和p2同時偏移
                p2=p2->next;
        }
        p1->next=pnew; //當p2接地時，p1的next直接接到新node
    }
    if(ask==2) //ask==2時，執行刪除動作
    {
        printf("輸入要刪除的數值>");//使用者輸入想刪除的值
        scanf("%d",&del); //掃到del儲存起來
        if(head==NULL) //完全沒有node直接印出不存在
        {
            printf("%d不存在",del);
            continue; //跳回上部while
        }
        p1=head; //p1指向第一個node
        p2=head->next; //p2指向第二個node
        if(p1->data==del) //當第一個node的值等於欲刪除的node值
        {
            head=p2; //head直接指向p2(第二個node)
            free(p1); //釋放第一個node的空間
            continue; //跳回外部while
        }
        while(p2!=NULL) //p2沒接地時
        {
            if(p2->data==del)//當p2值等於欲刪除的值
            {
                p1->next=p2->next;//p1的next直接跳過p2接p2的next
                free(p2); //釋放p2的空間
                break; //打斷本while
            }
            p1=p2; //p1,p2同時偏移
            p2=p2->next;
        }
        printf("%d不存在!!!",del);//p2接地時印出不存在
    }
    if(ask==3) //ask==3執行列印
    {
        p1=head; //p1指向第一個node
        while(p1!=NULL) //當p1不是空的的時
        {
            printf("%d\n",p1->data);//印出
            p1=p1->next; //跳到第二個節點
        }
    }
}
return(0);
}

struct node *create() //新節點產生之外部函式
{
    int n;
    struct node *temp; //宣告一個temp指標
    printf("鍵入數值>"); //使用者輸入
    scanf("%d",&n); //存回n
    temp=(struct node *)malloc(sizeof(struct node));//temp指向一個新空間
    temp->data=n; //新空間中的data值等於n
    temp->next=NULL; //next接地
    return temp; //傳回temp所指向的位址
}
