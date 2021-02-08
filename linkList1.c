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
int ask,check;
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
        pnew=create();//產生一個新的節點
        if(head==NULL )
        { //head接地

            head=pnew; //head指向新node
            //pnew->next=NULL; //first node的next指向NULL
            continue; //跳出，回到上部的while
        }
        p1=head; //p1指向第一個node
        p2=head->next; //p2指向第二個node
        while(p2!=NULL) //p2沒接地時
        {

            p1=p2; //p1和p2同時偏移

            p2=p2->next;


         }
        p1->next=pnew;
    }
    if(ask==2) //ask==2時，執行刪除動作
    {
        check=-1;//若未找到要刪除的資料就將CHECK設為-1
        printf("輸入要刪除的數值>");//使用者輸入想刪除的值
        scanf("%d",&del); //掃到del儲存起來
        if(head==NULL) //完全沒有node直接印出不存在
        {
            printf("%d不存在",del);
            continue; //跳回上部while
        }
         if(head->data==del&&head->next==NULL) //只有一個NODE且又符合要刪除的條件
        {
            free(head);//釋放HEAD記憶體
            head=NULL;//設為空list
            check=1;//設為找到並已刪除資料
            continue; //跳回上部while
        }

        p1=head; //p1指向第一個node
        p2=head->next; //p2指向第二個node


        while(p2!=NULL) //p2沒接地時
        {
             if(p1->data==del&&p1==head)//當p1值等於欲刪除的值且p1是HEAD
            {

                head=p2;//p2設為新head
                free(p1); //釋放p1的空間
                check=1;//設為找到並已刪除資料
                break; //打斷本while
            }
            if(p2->data==del)//當p2值等於欲刪除的值
            {
                p1->next=p2->next;//p1的next直接跳過p2接p2的next,刪除P2節點
                free(p2); //釋放p2的空間
                check=1;//設為找到並已刪除資料
                break; //打斷本while
            }
            //繼續比對下一筆資料
            p1=p2; //p1和p2同時偏移，設定下一筆資料位址

            p2=p2->next;
        }

        if(check==-1){

         printf("%d不存在!!!",del);//p2接地時印出不存在
        }

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
    temp=(struct node *)malloc(sizeof(struct node));//配置記憶體，使temp指向一個新空間
    temp->data=n; //新空間中的data值等於n
    temp->next=NULL; //next接地
    return temp; //傳回temp所指向的位址
}
