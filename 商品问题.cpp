#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<fstream>
#include<sstream>
#include <codecvt>
using namespace std;
typedef struct node{
  //是否是叶子节点
  int  isleaf;
  //名称
  string name;
  //价格
  int  price;
  //父节点指针
  struct node* parent = NULL;
  //子节点
  struct node* child = NULL;
  //    
  struct  node* brother = NULL;
  //保质期     
  int date;
  //是否进口
  int isinport;
  //父节点分类名称
  string parentName;
}Node;
Node * head;

//获取当前目录下的所有商品(叶子节点)
void getAllNode(Node * root,vector<Node*>&v){
   if(root == NULL)return;
    while(root){
       if(root->child == NULL)v.push_back(root);
       getAllNode(root->child,v);
       root = root ->brother; 
    }
}

//获取当前目录下的分类
void getAllChildType(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        v.push_back(root ->name);
        root = root->brother;
    }
}

//找到名字位name的某个商品
Node*findNode(Node*root,string name){
   if(root == NULL)return NULL;
   if(root ->name == name)return root;
   while(root){
       if(root ->name == name)return root;
       Node * k = findNode(root->child,name);
       if(k != NULL)return k;
       root = root ->brother; 
   }
   return root;
}

//添加商品
void addNode(Node n){
    Node * node = new Node();
    node->parent = NULL;
    node->child = NULL;
    node->brother = NULL;
    node ->isleaf = n.isleaf;
    node ->name = n.name;
    node ->price = n.price;
    node ->date = n.date;
    node ->isinport = n.isinport;
    node -> parentName = n.parentName;
    Node * root = head;
    //找到他的父节点
    Node * p = findNode(root,node->parentName);
    node ->parent = p;
    if(p ->child == NULL){
        p ->child = node;
    }else {
        p = p ->child;
        while(p ->brother){
            p = p->brother;
        }
        p ->brother  = node;
      }
}

//初始化函数
void init(){
   Node * root = new  Node();
   root->parent = NULL;
   root->child = NULL;
   root->brother = NULL;
   root->isleaf = 0;
   root->name = "超市"; 
   root->price = 0;
   root->date = 0;
   root->isinport = 0;
   root->parentName = "超市";
   head = root;
   Node a = {0,"食物",0,NULL,NULL,NULL,0,0,"超市"};
   Node b = {0,"电器",0,NULL,NULL,NULL,0,0,"超市"};
   Node c = {0,"肉",0,NULL,NULL,NULL,0,0,"食物"};
   Node d = {0,"菜",0,NULL,NULL,NULL,0,0,"食物"};
   Node e = {0,"牛肉",1,NULL,NULL,NULL,100,0,"肉"};
   Node f = {0,"羊肉",1,NULL,NULL,NULL,20,0,"肉"};
   Node g = {0,"胡萝卜",1,NULL,NULL,NULL,10,0,"菜"};
   Node h = {0,"卷心菜",1,NULL,NULL,NULL,5,0,"菜"};
   Node i = {0,"手机",0,NULL,NULL,NULL,0,0,"电器"};
   Node j = {0,"电脑",0,NULL,NULL,NULL,0,0,"电器"};
   Node k = {0,"小米手机",1000,NULL,NULL,NULL,100000,0,"手机"};
   Node m = {0,"华为手机",100,NULL,NULL,NULL,100000,0,"手机"};
   Node n = {0,"苹果电脑",100,NULL,NULL,NULL,10000,0,"电脑"};
   Node o = {0,"华硕电脑",1,NULL,NULL,NULL,20000,0,"电脑"};
   vector<Node>v = {a,b,c,d,e,f,g,h,i,j,k,m,n,o};
   //for(int i = 0; i < v.size() ; i ++){
     //addNode(v[i]);
  // }
   //读取商品信息
    ifstream infile("good.txt");
    string line;
    vector<vector<string>> data;
    //读入边
    while (getline(infile, line)) {
        istringstream iss(line);
        vector<string> row;
        string val;
        while (iss >> val) {
            row.push_back(val);
        }
        data.push_back(row);
    }
    for(auto k : data){
        for(auto s : k){
            cout<<s<<"   ";
        }
        cout<<endl;
        Node w = {stoi(k[0]),k[1],stoi(k[2]),NULL,NULL,NULL,stoi(k[3]),stoi(k[4]),k[5]};
        addNode(w);
    }
}

//获取当前目录的信息
void view(Node*root){
  cout<<"当前商品信息是:"<<root->name<<endl;
  //获取当前商品类型的所有子分类
  vector<string>v1;
  //获取当前商品的所有叶子节点，也就是具体商品
  vector<Node*>v2;
  getAllNode(root->child,v2);
  getAllChildType(root->child,v1);
  if(v1.size() == 0){
      cout<<"当前目录没有子分类"<<endl;
      return ;
  }
  cout<<"当前目录下有以下子分类:"<<endl;
  for(int i = 0 ; i < v1.size() ; i ++){
    cout<<v1[i]<<endl;
  }
  cout<<endl;
  cout<<"当前目录下的所有商品有:"<<endl;
  for(int i = 0 ;i < v2.size() ; i ++){
      cout<<"商品名称:"<<v2[i] -> name<<endl;
      cout<<"商品价格:"<<v2[i] -> price<<endl;
      cout<<"保质期:"<<v2[i] -> date<<endl;
     if(v2[i] -> isinport == 0)cout<<"非进口"<<endl<<endl;
     else cout<<"进口"<<endl<<endl;
  }
  cout<<endl;
}

//切换到上一层目录
Node * changePreviousDirectory(Node * root){
   if(root ->name == "超市"){
       //已经是根目录
       cout<<"已经是根目录"<<endl;
       return root;
   }else {
       cout<<"切换成功"<<endl;
       root = root ->parent;
   }
}

//切换到下一层目录
Node * changeNextDirectory(Node*root){
   if(root->child == NULL){
       cout<<"已经到页目录"<<endl;
       return root;
   }else {
       cout<<"切换成功"<<endl;
       root = root ->child;
   }
}

//切换到任意目录
Node * changeAnyDirectory(Node * root){
   string s;
   cout<<"输入要切换的目录名称:";
   cin>>s;
   Node * k = findNode(root,s);
   if(k == NULL){
       cout<<"没有这个目录"<<endl;
   }else {
       cout<<"切换成功"<<endl;
       return k;
   }
}

//添加商品信息
void addGood(){
    cout<<"sss"<<endl;
   Node  root;
   root.parent = NULL;
   root.child = NULL;
   root.brother = NULL;
   root.isleaf = 0;
   root.name = "超市"; 
   root.price = 0;
   root.date = 0;
   root.isinport = 0;
   root.parentName = "超市";
   cout<<"是否是叶子节点 0-不是  1-是:";
   cin>>root.isleaf;
   cout<<endl;
   cout<<"商品名称:";
   cin>>root.name;
   cout<<endl;
   cout<<"商品价格:";
   cin>>root.price;
   cout<<endl;
   cout<<"商品保质期:";
   cin>>root.date;
   cout<<endl;
   cout<<"是否进口 0-非进口 1-进口:";
   cin>>root.isinport;
   cout<<"上一层目录的名字:";
   cin>>root.parentName;
   cout<<endl;
   addNode(root);
}


//打折
void onSale(Node * root,double x){
   if(root == NULL)return;
   while(root){
       root->price *= x;
       onSale(root ->child,x);
       root = root ->brother;
   }
}

//保质期低于90天
void findGoodLessN(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        if(root->child == NULL && root ->date < 90)v.push_back(root ->name);
        findGoodLessN(root->child,v);
        root = root ->brother;
    }
}


//进口
void findInportGood(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        if(root->child == NULL && root ->date < 90 && root ->isleaf == 1)v.push_back(root ->name);
        findInportGood(root->child,v);
        root = root ->brother;
    }
}
int main(){
  //初始化
  init();
  int choice;
  Node*root = head;
  while(1){
    cout<<"       ---------------------超市管理系统------------------------   "<<endl<<endl;
    cout<<"1-浏览当前目录内容"<<endl;
    cout<<"2-切换到上一级目录"<<endl;
    cout<<"3-切换到下一句目录"<<endl;
    cout<<"4-切换到根目录"<<endl;
    cout<<"5-切换到任意目录"<<endl;
    cout<<"6-添加商品目录或者信息"<<endl;
    cout<<"7-查询某个商品"<<endl;
    cout<<"8-当前目录下所有商品打折"<<endl;
    cout<<"9-查询保质期少于90天的商品"<<endl;
    cout<<"10-查询所有进口商品"<<endl;
    cout<<"11-修改某个商品"<<endl;
    cout<<"12-写入文件"<<endl;
    cout<<"13-退出"<<endl;
    cout<<"输入选择:";
    cin>>choice;
    cout<<endl;
    if(choice == 1){
       view(root);
    }else if(choice == 2){
        root = changePreviousDirectory(root);
    }else if(choice == 3){
        root = changeNextDirectory(root);
    }else if(choice == 4){
        root = head;
        cout<<"切换成功"<<endl;
    }else if(choice == 5){
       root = changeAnyDirectory(root);
    }else if(choice == 6){
       addGood();
    }else if(choice == 7){
        cout<<"输入商品名称:";
        string s;
        cin>>s;
        Node *k = findNode(head,s);
        //只有叶子节点才是具体商品
        if(k == NULL || k->child != NULL){
           cout<<"没有找到此商品"<<endl;
        }else {
            cout<<"商品名称:"<<k->name<<endl;
            cout<<"商品价格:"<<k->price<<endl;
            cout<<"保质期:"<<k->date<<endl;
            if(k ->isinport == 0)cout<<"非进口"<<endl;
            else cout<<"进口"<<endl;
        }
    }else if(choice == 8){
        cout<<"输入打折力度:";
        int x;
        cin>>x;
        cout<<endl;
        if(root ->child == NULL){
            root ->price *= (int)x*0.1;
        }
        onSale(root ->child,x*0.1);
        cout<<"打折成功"<<endl;
    }else if(choice == 9){
        vector<string>v;
        findGoodLessN(head,v);
        if(v.size() == 0){
            cout<<"没有保质期小于90天的"<<endl;
        }else {
            cout<<"保质期低于90天的商品有:"<<endl;
            for(int i = 0 ;i < v.size() ; i ++){
               cout<<v[i]<<endl;
             }
        }
    }else if(choice == 10){
        vector<string>v;
        findInportGood(head,v);
         if(v.size() == 0){
            cout<<"没有进口商品"<<endl;
        }else {
            cout<<"进口商品有:"<<endl;
            for(int i = 0 ;i < v.size() ; i ++){
               cout<<v[i]<<endl;
             }
        }
    }else if(choice == 11){
        cout<<"输入商品名称:";
        string s;
        cin>>s;
        Node *k = findNode(head,s);
        if(k == NULL){
            cout<<"没有这个商品"<<endl;
        }else {
           cout<<"修改商品名称:"<<endl;
           cin>>k -> name;
           cout<<"修改商品价格:"<<endl;
           cin>>k -> price;
           cout<<"修改商品保质期:"<<endl;
           cin>>k -> date;
           cout<<"修改商品进口信息 0-非进口 1-进口:"<<endl;
           cin>>k -> isinport;
        }
    }
  }
}