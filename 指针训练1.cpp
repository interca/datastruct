#include<stdio.h>
int  change();
int main(){
	//void change(int *b);
	int a=1;
	printf("%d\n",a);
	a=change();
	printf("%d",a);
	return 0;
}
int  change(){
	return 10;
}
