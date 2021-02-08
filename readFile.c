#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    FILE *fPtr;//檔案指標

    char s[100];//讀取字元上限
    char k[50];//輸入字元上限

    scanf("%s",&k);//鍵盤讀取

    fPtr = fopen("test.txt", "r+");//開啟檔案取得指標，並設為可讀寫
    if (!fPtr) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
    fseek(fPtr, 0, SEEK_END);//將字元指標指到字元末端
    fputs(k,fPtr);//從字元末端加入新字元
    rewind(fPtr);//將指標移到字元前端
    while(fgets(s,sizeof(s), fPtr)!=NULL) {

        printf(s);
    }
    printf("\n");

    fclose(fPtr);

    return 0;
}

