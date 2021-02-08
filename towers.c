//河內塔遞迴練習
#include <stdio.h>
int main(){
int n;
int i=0;
printf("請輸入套環個數：");
scanf("%d",&n);
printf("\n開始搬移：\n");
towers(n,'A','B','C',&i);
printf("移動%d個套環共需%d個步驟",n,i);

}
void towers(int n,char X,char Y,char Z,int *Pri){
*Pri=*Pri+1;

if(n==1){
    printf("套環 1 從 %C 柱移動到 %C 柱\n", X, Z);
    return ;
}

else {
    towers(n-1,X,Z,Y,Pri);
    printf("套環 %d 從 %C 柱移動到 %C 柱\n",n, X, Z);
    towers(n-1,Y,X,Z,Pri);

}



}

