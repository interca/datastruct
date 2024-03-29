#include<stdio.h>
#include<stdlib.h>
int size1=0;
int size2=0;
int max1=0;
int max2=0;

//插入1
char *insert1(char *l,char value){
   if(size1==max1){
       int n=2*sizeof(l)/sizeof(l[0]);
       char* help=(char*)malloc(sizeof(char));
        for(int i=0;i<size1;i++){
            help[i]=l[i];
        }
      max1=n;
      help[size1]=value;
      size1++;
      return help;
   }else {
      l[size1++]=value;
      return l;
   }
}

//插入2
char *insert2(char *l,char value){
   if(size2==max2){
       int n=2*sizeof(l)/sizeof(l[0]);
       char* help=(char*)malloc(sizeof(char));
        for(int i=0;i<size1;i++){
            help[i]=l[i];
        }
        max2=n;
      help[size2]=value;
      size2++;
   }else {
      l[size2++]=value;
      return l;
   }
}

//查找
int find(char*l,char value){
  int index=0;
  for(int i=0;i<sizeof(l)/sizeof(l[0]);i++){
      if(l[i]==value)return i;
  }
  return -1;
}

//删除表1
char* delete1(char *l,char value){
    int index=-1;
    int n=sizeof(l)/sizeof(l[0]);
    for(int i=0;i<n;i++){
        if(l[i]==value){
            index=i;
            break;
        }
    }
    if(index==-1)return l;
    for(int i=index;i<n-1;i++){
        l[i]=l[i+1];
    }
    size1--;
    return l;
}



//删除表1
char* delete2(char *l,char value){
    int index=-1;
    int n=sizeof(l)/sizeof(l[0]);
    for(int i=0;i<n;i++){
        if(l[i]==value){
            index=i;
            break;
        }
    }
    if(index==-1)return l;
    for(int i=index;i<n-1;i++){
        l[i]=l[i+1];
    }
    size2--;
    return l;
}
//打印
void printlist(char*l,int size){
    for(int i=0;i<size;i++){
        printf("%c",l[i]);
    }
    printf("\n");
}

char *merge(char *l1,char *l2){
    char *l3=(char*)malloc(sizeof(l1)+sizeof(l2));
    int index1=0;
    int index2=0;
    int index3=0;
    while(index1<size1&&index2<size2){
        if(l1[index1]<l2[index2]){
           l3[index3++]=l1[index1++];
        }else {
            l3[index3++]=l2[index2++];
        };
    }
    while(index1<size1){
         l3[index3++]=l1[index1++];
    }

    while(index2<size2){
          l3[index3++]=l2[index2++];
    }
    return l3;
}
int main(){
    max1=2;
    max2=2;
    size1=0;
    size2=0;
    char* l1=(char*)malloc(2);
    char* l2=(char*)malloc(2);
    char *l3;
    char value;
    while(1){
        int choice;
        printf("1-插入表1,2-插入表2,3-删除表1,4-删除表2,5-在表1查找元素,6-在表2查找元素,7-合并,8-遍历1,9-遍历2 10-遍历3\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
              printf("输入要插入的数\n");
              scanf("%c",&value);
              insert1(l1,value);
              break;
            case 2:
               printf("输入要插入的数\n");
               scanf("%c",&value);
               insert2(l2,value);
               break;
            case 3:
               printf("输入要删除的数\n");
               scanf("%c",&value);
              l1= delete1(l1,value);
               break;  
            case 4:
               printf("输入要删除的数\n");
               scanf("%c",&value);
               l2=delete2(l2,value);
               break; 
            case 5:
               printf("输入要查找的数\n");
               scanf("%c",&value);
               value=find(l1,value);
               if(value==-1)printf("没有这个元素\n");
               else printf("位置是%d\n",value);
               break; 
           case 6:
               printf("输入要查找的数\n");
               scanf("%c",&value);
               value=find(l2,value);
               if(value==-1)printf("没有这个元素\n");
               else printf("位置是%d\n",value);
               break;   
           case 7:
              l3=merge(l1,l2);
               break;
           case 8:
             printlist(l1,size1);
             break;
           case 9:
              printlist(l2,size2);
              break;
           case 10:
              printlist(l3,size1+size2);
              break;                    
        }
    }
    return 0;
}