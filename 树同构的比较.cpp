#include<stdio.h>
#define null -1;

typedef struct tree{      //�ṹ�幹���� 
	char  value;
	int left;
	int right;
}T;
int main(){
	struct tree T1[10];
	struct tree T2[10];
	int treeroot(struct tree T3[10],int n);
	int Isomerphic(int R1,int R2,T T1[],T T2[]);
	int root1,root2;
	int imprise;
	int n;
	
	printf("����N��\n");
	scanf("%d",&n);
	getchar();
	printf("�����һ����\n"); 
	int R1=treeroot(T1,n);
	printf("%d\n",R1);
	printf("����ڶ�����\n");
	getchar();
	int R2=treeroot(T2,n);
	printf("%d\n",R2);
	imprise=Isomerphic(R1,R2,T1,T2);
	if(imprise==1)printf("������ͬ��\n");
	else printf("��������ͬ��\n");
	return 0;
} 
int treeroot(struct tree T3[10],int n){   //����������Ϣ���ҷ��ظ����±� 
	int root;
	int i;
	int check[20];
	for(i=0;i<n;i++)check[i]=0;
	char c1,c2;
	if(n){
		for(i=0;i<n;i++){
			scanf("%c",&T3[i].value);
			scanf("%c",&c1);
			scanf("%c",&c2);
			if(c1!='-'){
				T3[i].left=c1-'0';
				check[T3[i].left]=1;
			}
			else T3[i].left=-1;
			if(c2!='-'){
				T3[i].right=c2-'0';
				check[T3[i].right]=1;
			}
	    	else T3[i].right=-1;
		}
	 }
 		for(i=0;i<n;i++){
			printf("��ֵ=%c",T3[i].value);
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%d\n",check[i]);
		if(check[i]==0){
	      root=i;break;}
	   }
	return i;
}
	int Isomerphic(int R1,int R2,struct tree T1[10],struct tree T2[10]){     //�ж��������ǲ���ͬ�����õݹ� 
	    printf("1");
		if((R1==-1)&&(R2==-1)) 
		      return 1;
		if(((R1==-1)&&(R2!=-1))||((R1!=-1)&&(R2==-1)))
		      return 0;
		if(T1[R1].value!=T2[R2].value)
		       return 0;
		if((T1[R1].left==-1)&&(T2[R2].left==-1))
			return Isomerphic(T1[R1].right,T2[R2].right,T1,T2);
		if((T1[R1].right==-1)&&(T2[R2].right==-1))
			return Isomerphic(T1[R1].left,T2[R2].left,T1,T2);
		if((T1[R1].left!=-1)&&(T2[R2].left!=-1)&&((T1[T1[R1].left].value)==(T2[T2[R2].left].value)))
			return (Isomerphic(T1[R1].left,T2[R2].left,T1,T2)&&Isomerphic(T1[R1].right,T2[R2].right,T1,T2));
		else  return (Isomerphic(T1[R1].left,T2[R2].right,T1,T2)&&Isomerphic(T1[R1].right,T2[R2].left,T1,T2));	
	}

