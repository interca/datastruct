#include<stdio.h>
#include<stdlib.h> 
int main(){
	int*p=(int*)malloc(sizeof(int));
	*p=1;
	int *q=p;
	int *h=q;
	printf("%d",*h);
}
