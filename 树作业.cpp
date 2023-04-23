#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#include<queue>
#include<stack>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
//定义树
typedef struct tree{
    char value;
    struct tree * left;
    struct tree*right;
}Tree;

//构建树
Tree * creatTree(vector<char>a,int n){
    if(n >= a.size() || a[n] =='#')return NULL;
    Tree * node =  (Tree*)malloc(sizeof(Tree));
    node->value = a[n];
    node->left = creatTree(a,2*n+1);
    node->right = creatTree(a,2*n+2);
    return node;
}

//中序遍历
void printMid(Tree*head){
    if(head == NULL)return;
    printMid(head->left);
    printf("%c ",head->value);
    printMid(head->right);
}

//后续遍历
void printBack(Tree*head){
    if(head == NULL)return;
    printBack(head->left);
    printBack(head->right);
    printf("%c ",head->value);
}

//查找
Tree*find(Tree*root,char x){
    if(root == NULL)return NULL;
	if(root ->value == x)return root;
	Tree* left = find(root->left,x);
	Tree* right = find(root->right,x);
	if( left != NULL && left->value == x)return left;
	return right;
}

//打印凹
void printfreverse(Tree * head,int n){
	if(head == NULL)return;
	printfreverse(head->right,n + 3);
	for(int  i = 0 ; i < n  ;  i ++)printf(" ");
	printf("--");
	printf("%c",head->value);
	printf("\n");
	printfreverse(head->left,n + 4);
}

//非递归用堆栈先序遍历
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

//层序
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
//叶子
void printfLeaf(Tree*head){
   if(head ==NULL)return;
   printfLeaf(head->left);
   printfLeaf(head->right);
   if(head->left ==NULL&&head->right ==NULL)cout<<head->value<<" ";

}

//深度
int TreeDeep(Tree * head){
    if(head ==NULL)return 0;
	int left   = TreeDeep(head->left);
	int right = TreeDeep(head->right);
	return max(left,right)+1;
}


//判断完全二叉树
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
   printf("输入n个数字\n");
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
   //递归树
   head->left = creatTree(a,1);
   head->right = creatTree(a,2);
   int h;
   bool c;
    while(1){
	  printf("1-查找一个数,2-打印凹凸 3-非递归先序打印 4-中序遍历 5- 层序遍历  6-输出叶子   7-树的深度  8- 判断完全二叉树\n");
	  int choice;
	  scanf("%d",&choice);
	  Tree * w;
	  switch(choice){
		  case 1:
		    printf("输入要找的数\n");
			char x;
			cin>>x;
		    w = find(head,x);
			if(w == NULL)printf("没有找到这个数\n");
			else printf("找到了这个数是%c\n",w->value);
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
           printf("深度是%d\n",h);
           break;
        case  8:
           c = judgeTree(head);
           if(c == true)cout<<"是完全二叉树\n";
           else cout<<"不是完全二叉树\n";
           break;   
       }

    }
   return 0;
}