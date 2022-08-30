#include<stdio.h>
void change(int *a);
void chang(int *a);
int main(){
	int a;
	change(&a);
	printf("%d",a);
	return 0;
} 
void change(int *a){
	*a=1;
	chang(a);
}
void chang(int *a){
	*a=10;
}
