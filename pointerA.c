#include <stdio.h>
void main(){
int i;
int *ptr;
i=10;
ptr=&i;
printf("i 的記憶體位址是:%d  i=%d\n",&i,i);
printf("ptr 的內容是:%d  *ptr=%d\n",ptr,*ptr);
memA(ptr,&i);

printf("i 的記憶體位址是:%d  i=%d\n",&i,i);
}
void memA(int mA,int  *mm){

printf("mA 的內容是:%d  \n",mA);
printf("mm 的內容是:%d  \n",mm);
printf("*mm 的內容是:%d  \n",*mm);
*mm=*mm+1;//指向該記憶體的內容數值+1
}
