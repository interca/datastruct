#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数组扩容函数
char * expension(char * s,int n){
    char * help =(char*)malloc(sizeof(s)*n);
    int i  = 0;
    for(i = 0;i<strlen(s);i++){
        help[i] = s[i];
    }
    help[i] = '\0';
    return help; 
}
//插入函数
char* insert(char *string1,char *string2,int n){
    char help[n+10];
    //保存string2前n个字符
    for(int i  = 0;i < n; i++){
        help[i] = string2[i];
    }
    //计算出string1最大容量
    int m = sizeof(string1)/sizeof(string1[0]);
    //容量不够就扩容
    if(m<strlen(string1)+n){
        string1 = expension(string1,n);
    }
    int index = strlen(string1);
    int i = 0;
    for(i = 0;i< n ;i++){
        string1[i+index] = help[i];
    }
    string1[i+index] = '\0';
    printf("插入%s\n",string1);
    return string1;
}

//匹配函数
char* find(char *string1,char *string3,int m){
    for(int i = 0;i<strlen(string1);i++){
        int sum = 0;
        for(int j = 0;j<strlen(string3); j++){
            if(string1[i] == string3[j])sum++;
            else break;
        }
        if(sum == strlen(string3)){
            printf("找到,匹配位置是%d\n",i);
            return string1;
        }
    }
    //没有匹配到
    int count = sizeof(string1)/sizeof(string1[0]);
    if(count<strlen(string3)+strlen(string1)){
        string1 = expension(string1,strlen(string3));
    }
    //保存m位置后的string1字符
    char help[strlen(string1)];
    for(int i = m ;i<strlen(string1);i++){
        help[i-m] = string1[i]; 
    }

    int index = m;
    for(int i = 0;i < strlen(string3); i++){
       string1[index++] = string3[i];
    }
    for(int i = 0;i<strlen(help);i++){
        string1[index++] = help[i];
    }
    string1[index] = '\0';
    return string1;
}

//初始化字符串
void start(char *string){
   scanf("%s",string);
}
int main(){
    //读取字符串
    char *string1 = (char*)malloc(sizeof(1000));
    char *string2 = (char*)malloc(sizeof(1000));
    char *string3 = (char*)malloc(sizeof(1000));
    start(string1);
    getchar();
    start(string2);
    getchar();
    start(string3);
    int choice;
    int n ;
    int m ;
    while(1){
        printf("1-将s2的前n个字符插入s1后面,2-寻找s3在s1中的位置,3-字符串1,4-输出字符串2,5-输出字符串3\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               printf("输入n:\n");
               scanf("%d",&n); 
              string1 = insert(string1,string2,n);
                break;

            case 2:
               printf("输入m:\n");
               scanf("%d",&m);
              string1 =  find(string1,string3,m);
               break;

            case 3:
                printf("字符串1:%s\n",string1);
                break;

            case 4:
               printf("字符串2:%s\n",string2);
               break;

            case 5:
               printf("字符串3:%s\n",string3);          
        }
    }
    return 0;
}