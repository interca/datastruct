#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#include<queue>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
//������
typedef struct tree{
    char value;
    struct tree * left;
    struct tree*right;
}Tree;

//������
Tree * creatTree(vector<char>a,int n){
    if(n >= a.size() || a[n] =='#')return NULL;
    Tree * node =  (Tree*)malloc(sizeof(Tree));
    node->value = a[n];
    node->left = creatTree(a,2*n+1);
    node->right = creatTree(a,2*n+2);
    return node;
}

//�������
void printMid(Tree*head){
    if(head == NULL)return;
    printMid(head->left);
    printf("%c ",head->value);
    printMid(head->right);
}

//��������
void printBack(Tree*head){
    if(head == NULL)return;
    printBack(head->left);
    printBack(head->right);
    printf("%c ",head->value);
}

//����
Tree*find(Tree*root,char x){
    if(root == NULL)return NULL;
	if(root ->value == x)return root;
	Tree* left = find(root->left,x);
	Tree* right = find(root->right,x);
	if( left != NULL && left->value == x)return left;
	return right;
}

//��ӡ��
void printfreverse(Tree * head,int n){
	if(head == NULL)return;
	printfreverse(head->right,n + 3);
	for(int  i = 0 ; i < n  ;  i ++)printf(" ");
	printf("--");
	printf("%c",head->value);
	printf("\n");
	printfreverse(head->left,n + 4);
}

//�ǵݹ��ö�ջ�������
void printfByStack(Tree*head){
    stack<Tree*>st;
    while(st.size() >0 || head !=NULL){
        while(head){
            cout<<head->value<<"  ";
            st.push(head);
            head=head->left;
        }
        head = st.top();
        st.pop();
        if(head){
            head = head ->right;
        }
    }
    printf("\n");
}

//����
void printLay(Tree*head){
    queue<Tree*>q;
    q.push(head);
    while(q.size()>0){
        Tree*temp = q.front();
        q.pop();
        printf("%c ",temp->value);
        if(temp -> left !=NULL)q.push(temp->left);
        if(temp -> right !=NULL)q.push(temp ->right);
    }
    printf("\n");
}
//Ҷ��
void printfLeaf(Tree*head){
   if(head ==NULL)return;
   printfLeaf(head->left);
   printfLeaf(head->right);
   if(head->left ==NULL&&head->right ==NULL)cout<<head->value<<" ";

}

//���
int TreeDeep(Tree * head){
    if(head ==NULL)return 0;
	int left   = TreeDeep(head->left);
	int right = TreeDeep(head->right);
	return max(left,right)+1;
}


//�ж���ȫ������
bool judgeTree(Tree * head){
    Tree*temp = head;
	queue<Tree*>q;
    q.push(head);
    int sum =0;
    while(q.size()>0){
        Tree*temp = q.front();
        q.pop();
        sum ++;
        if(temp -> left !=NULL)q.push(temp->left);
        if(temp -> right !=NULL)q.push(temp ->right);
    }
	int h = TreeDeep(temp);
    int count = pow(2,h) - 1;
	return count == sum;
}
int main(){
   int n;
   printf("����n������\n");
   cin>>n;
   vector<char>a(n);
   string s;
   cin>>s;
   for(int i = 0 ;  i <n ; i ++){
       a[i] = s[i];
   }
   Tree*head;
   Tree * node =  (Tree*)malloc(sizeof(Tree));
   node ->value = a[0];
   head= node;
   //�ݹ���
   head->left = creatTree(a,1);
   head->right = creatTree(a,2);
   int h;
   bool c;
    while(1){
	  printf("1-����һ����,2-��ӡ��͹ 3-�ǵݹ������ӡ 4-������� 5- �������  6-���Ҷ��   7-�������  8- �ж���ȫ������\n");
	  int choice;
	  scanf("%d",&choice);
	  Tree * w;
	  switch(choice){
		  case 1:
		    printf("����Ҫ�ҵ���\n");
			char x;
			cin>>x;
		    w = find(head,x);
			if(w == NULL)printf("û���ҵ������\n");
			else printf("�ҵ����������%c\n",w->value);
			break;
         case 2:
           printfreverse(head,0);
           break;
         case 3 :
           printfByStack(head);
           printf("\n");
           break;
         case 4:
         printMid(head);
         printf("\n");
         break;  
        case 5:
           printLay(head);
           break;
        case 6:
           printfLeaf(head);
           printf("\n");
           break;
        case 7:
           h = TreeDeep(head);
           printf("�����%d\n",h);
           break;
        case  8:
           c = judgeTree(head);
           if(c == true)cout<<"����ȫ������\n";
           else cout<<"������ȫ������\n";
           break;   
       }

    }
   return 0;
}