#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef struct tree{
    int value;
    struct tree * left;
    struct tree*right;
}Tree;

//头结点
Tree *head;

//创建二插搜索树
Tree* creatTree(Tree*root,int value){
   if(root == NULL){
       Tree*node = (Tree*)malloc(sizeof(Tree));
       node->left = node->right = NULL;
       node->value = value;
       return node;
   }
   if(root->value < value)root->right = creatTree(root->right,value);
   else root->left = creatTree(root->left,value);
   return root;
}

//寻找关键字
void search(int x){
    Tree * h = head;
    while(h !=NULL){
        if(x > h ->value)h = h->right;
        else if(x < h->value)h = h->left;
        else {
            cout<<"找到了"<<endl;
            return;
        }
    }
    cout<<"没有找到"<<endl;
}

void midSearch(Tree*root){
    if(root== NULL)return;
    midSearch(root->left);
    cout<<root->value<<" ";
    midSearch(root->right);
}


//找左边最大的值
 int findmax(Tree *root){
    while(root->right!=NULL)root=root->right;
    return root->value;
}


//删除
Tree* del(Tree*root,int x){
   Tree*temp = (Tree*)malloc(sizeof(Tree));
   if(root == NULL)return root;
   //递归删除左边和右边
   if(root->value > x)root->left = del(root->left,x);
   else if(root ->value <x)root->right = del(root->right,x);
   //要删除的结点是本结点
   else {
       //找到左边最大值并且删除改值
     if(root->left !=NULL && root->right !=NULL){
         temp->value = findmax(root->left);
         root->value = temp->value;
         root->left = del(root->left,temp->value);
     }else {
         //如果当前是叶子结点
        if(root->left == NULL)root = root->right;
        else root = root->left;
     }
   }
   return root;
}
int main(){
    vector<int>a = {3,-1,10,-2,0,7,12,-3,1,4};
    //构造树
    for(int i = 0 ; i < a.size() ; i ++){
        if(head == NULL){
            Tree*node = (Tree*)malloc(sizeof(Tree));
            node->left = node->right = NULL;
            node->value = a[i];
            head = node;
        }else if(head->value < a[i]){
            head->right = creatTree(head->right,a[i]);
        }else head->left  = creatTree(head->left,a[i]);
    }
    int x;
    int c;
    while(true){
        printf("1-找关键字 ,2-树的中序遍历  3-删除关键字\n");
        cin>>c;
        switch(c){
            case 1 : 
              cout<<"输入要查找的关键字"<<endl;
              cin>>x;
              search(x);
              break;
            case 2:
              midSearch(head);
              cout<<endl;
              break;
            case 3:
             cout<<"输入要删除的关键字"<<endl;
             cin>>x;
              del(head,x); 
              break;
        }
    }
}
