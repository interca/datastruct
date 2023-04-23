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

//ͷ���
Tree *head;

//��������������
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

//Ѱ�ҹؼ���
void search(int x){
    Tree * h = head;
    while(h !=NULL){
        if(x > h ->value)h = h->right;
        else if(x < h->value)h = h->left;
        else {
            cout<<"�ҵ���"<<endl;
            return;
        }
    }
    cout<<"û���ҵ�"<<endl;
}

void midSearch(Tree*root){
    if(root== NULL)return;
    midSearch(root->left);
    cout<<root->value<<" ";
    midSearch(root->right);
}


//���������ֵ
 int findmax(Tree *root){
    while(root->right!=NULL)root=root->right;
    return root->value;
}


//ɾ��
Tree* del(Tree*root,int x){
   Tree*temp = (Tree*)malloc(sizeof(Tree));
   if(root == NULL)return root;
   //�ݹ�ɾ����ߺ��ұ�
   if(root->value > x)root->left = del(root->left,x);
   else if(root ->value <x)root->right = del(root->right,x);
   //Ҫɾ���Ľ���Ǳ����
   else {
       //�ҵ�������ֵ����ɾ����ֵ
     if(root->left !=NULL && root->right !=NULL){
         temp->value = findmax(root->left);
         root->value = temp->value;
         root->left = del(root->left,temp->value);
     }else {
         //�����ǰ��Ҷ�ӽ��
        if(root->left == NULL)root = root->right;
        else root = root->left;
     }
   }
   return root;
}
int main(){
    vector<int>a = {3,-1,10,-2,0,7,12,-3,1,4};
    //������
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
        printf("1-�ҹؼ��� ,2-�����������  3-ɾ���ؼ���\n");
        cin>>c;
        switch(c){
            case 1 : 
              cout<<"����Ҫ���ҵĹؼ���"<<endl;
              cin>>x;
              search(x);
              break;
            case 2:
              midSearch(head);
              cout<<endl;
              break;
            case 3:
             cout<<"����Ҫɾ���Ĺؼ���"<<endl;
             cin>>x;
              del(head,x); 
              break;
        }
    }
}
