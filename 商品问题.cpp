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
  //�Ƿ���Ҷ�ӽڵ�
  int  isleaf;
  //����
  string name;
  //�۸�
  int  price;
  //���ڵ�ָ��
  struct node* parent = NULL;
  //�ӽڵ�
  struct node* child = NULL;
  //    
  struct  node* brother = NULL;
  //������     
  int date;
  //�Ƿ����
  int isinport;
  //���ڵ��������
  string parentName;
}Node;
Node * head;

//��ȡ��ǰĿ¼�µ�������Ʒ(Ҷ�ӽڵ�)
void getAllNode(Node * root,vector<Node*>&v){
   if(root == NULL)return;
    while(root){
       if(root->child == NULL)v.push_back(root);
       getAllNode(root->child,v);
       root = root ->brother; 
    }
}

//��ȡ��ǰĿ¼�µķ���
void getAllChildType(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        v.push_back(root ->name);
        root = root->brother;
    }
}

//�ҵ�����λname��ĳ����Ʒ
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

//�����Ʒ
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
    //�ҵ����ĸ��ڵ�
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

//��ʼ������
void init(){
   Node * root = new  Node();
   root->parent = NULL;
   root->child = NULL;
   root->brother = NULL;
   root->isleaf = 0;
   root->name = "����"; 
   root->price = 0;
   root->date = 0;
   root->isinport = 0;
   root->parentName = "����";
   head = root;
   Node a = {0,"ʳ��",0,NULL,NULL,NULL,0,0,"����"};
   Node b = {0,"����",0,NULL,NULL,NULL,0,0,"����"};
   Node c = {0,"��",0,NULL,NULL,NULL,0,0,"ʳ��"};
   Node d = {0,"��",0,NULL,NULL,NULL,0,0,"ʳ��"};
   Node e = {0,"ţ��",1,NULL,NULL,NULL,100,0,"��"};
   Node f = {0,"����",1,NULL,NULL,NULL,20,0,"��"};
   Node g = {0,"���ܲ�",1,NULL,NULL,NULL,10,0,"��"};
   Node h = {0,"���Ĳ�",1,NULL,NULL,NULL,5,0,"��"};
   Node i = {0,"�ֻ�",0,NULL,NULL,NULL,0,0,"����"};
   Node j = {0,"����",0,NULL,NULL,NULL,0,0,"����"};
   Node k = {0,"С���ֻ�",1000,NULL,NULL,NULL,100000,0,"�ֻ�"};
   Node m = {0,"��Ϊ�ֻ�",100,NULL,NULL,NULL,100000,0,"�ֻ�"};
   Node n = {0,"ƻ������",100,NULL,NULL,NULL,10000,0,"����"};
   Node o = {0,"��˶����",1,NULL,NULL,NULL,20000,0,"����"};
   vector<Node>v = {a,b,c,d,e,f,g,h,i,j,k,m,n,o};
   //for(int i = 0; i < v.size() ; i ++){
     //addNode(v[i]);
  // }
   //��ȡ��Ʒ��Ϣ
    ifstream infile("good.txt");
    string line;
    vector<vector<string>> data;
    //�����
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

//��ȡ��ǰĿ¼����Ϣ
void view(Node*root){
  cout<<"��ǰ��Ʒ��Ϣ��:"<<root->name<<endl;
  //��ȡ��ǰ��Ʒ���͵������ӷ���
  vector<string>v1;
  //��ȡ��ǰ��Ʒ������Ҷ�ӽڵ㣬Ҳ���Ǿ�����Ʒ
  vector<Node*>v2;
  getAllNode(root->child,v2);
  getAllChildType(root->child,v1);
  if(v1.size() == 0){
      cout<<"��ǰĿ¼û���ӷ���"<<endl;
      return ;
  }
  cout<<"��ǰĿ¼���������ӷ���:"<<endl;
  for(int i = 0 ; i < v1.size() ; i ++){
    cout<<v1[i]<<endl;
  }
  cout<<endl;
  cout<<"��ǰĿ¼�µ�������Ʒ��:"<<endl;
  for(int i = 0 ;i < v2.size() ; i ++){
      cout<<"��Ʒ����:"<<v2[i] -> name<<endl;
      cout<<"��Ʒ�۸�:"<<v2[i] -> price<<endl;
      cout<<"������:"<<v2[i] -> date<<endl;
     if(v2[i] -> isinport == 0)cout<<"�ǽ���"<<endl<<endl;
     else cout<<"����"<<endl<<endl;
  }
  cout<<endl;
}

//�л�����һ��Ŀ¼
Node * changePreviousDirectory(Node * root){
   if(root ->name == "����"){
       //�Ѿ��Ǹ�Ŀ¼
       cout<<"�Ѿ��Ǹ�Ŀ¼"<<endl;
       return root;
   }else {
       cout<<"�л��ɹ�"<<endl;
       root = root ->parent;
   }
}

//�л�����һ��Ŀ¼
Node * changeNextDirectory(Node*root){
   if(root->child == NULL){
       cout<<"�Ѿ���ҳĿ¼"<<endl;
       return root;
   }else {
       cout<<"�л��ɹ�"<<endl;
       root = root ->child;
   }
}

//�л�������Ŀ¼
Node * changeAnyDirectory(Node * root){
   string s;
   cout<<"����Ҫ�л���Ŀ¼����:";
   cin>>s;
   Node * k = findNode(root,s);
   if(k == NULL){
       cout<<"û�����Ŀ¼"<<endl;
   }else {
       cout<<"�л��ɹ�"<<endl;
       return k;
   }
}

//�����Ʒ��Ϣ
void addGood(){
    cout<<"sss"<<endl;
   Node  root;
   root.parent = NULL;
   root.child = NULL;
   root.brother = NULL;
   root.isleaf = 0;
   root.name = "����"; 
   root.price = 0;
   root.date = 0;
   root.isinport = 0;
   root.parentName = "����";
   cout<<"�Ƿ���Ҷ�ӽڵ� 0-����  1-��:";
   cin>>root.isleaf;
   cout<<endl;
   cout<<"��Ʒ����:";
   cin>>root.name;
   cout<<endl;
   cout<<"��Ʒ�۸�:";
   cin>>root.price;
   cout<<endl;
   cout<<"��Ʒ������:";
   cin>>root.date;
   cout<<endl;
   cout<<"�Ƿ���� 0-�ǽ��� 1-����:";
   cin>>root.isinport;
   cout<<"��һ��Ŀ¼������:";
   cin>>root.parentName;
   cout<<endl;
   addNode(root);
}


//����
void onSale(Node * root,double x){
   if(root == NULL)return;
   while(root){
       root->price *= x;
       onSale(root ->child,x);
       root = root ->brother;
   }
}

//�����ڵ���90��
void findGoodLessN(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        if(root->child == NULL && root ->date < 90)v.push_back(root ->name);
        findGoodLessN(root->child,v);
        root = root ->brother;
    }
}


//����
void findInportGood(Node * root,vector<string>&v){
    if(root == NULL)return;
    while(root){
        if(root->child == NULL && root ->date < 90 && root ->isleaf == 1)v.push_back(root ->name);
        findInportGood(root->child,v);
        root = root ->brother;
    }
}
int main(){
  //��ʼ��
  init();
  int choice;
  Node*root = head;
  while(1){
    cout<<"       ---------------------���й���ϵͳ------------------------   "<<endl<<endl;
    cout<<"1-�����ǰĿ¼����"<<endl;
    cout<<"2-�л�����һ��Ŀ¼"<<endl;
    cout<<"3-�л�����һ��Ŀ¼"<<endl;
    cout<<"4-�л�����Ŀ¼"<<endl;
    cout<<"5-�л�������Ŀ¼"<<endl;
    cout<<"6-�����ƷĿ¼������Ϣ"<<endl;
    cout<<"7-��ѯĳ����Ʒ"<<endl;
    cout<<"8-��ǰĿ¼��������Ʒ����"<<endl;
    cout<<"9-��ѯ����������90�����Ʒ"<<endl;
    cout<<"10-��ѯ���н�����Ʒ"<<endl;
    cout<<"11-�޸�ĳ����Ʒ"<<endl;
    cout<<"12-д���ļ�"<<endl;
    cout<<"13-�˳�"<<endl;
    cout<<"����ѡ��:";
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
        cout<<"�л��ɹ�"<<endl;
    }else if(choice == 5){
       root = changeAnyDirectory(root);
    }else if(choice == 6){
       addGood();
    }else if(choice == 7){
        cout<<"������Ʒ����:";
        string s;
        cin>>s;
        Node *k = findNode(head,s);
        //ֻ��Ҷ�ӽڵ���Ǿ�����Ʒ
        if(k == NULL || k->child != NULL){
           cout<<"û���ҵ�����Ʒ"<<endl;
        }else {
            cout<<"��Ʒ����:"<<k->name<<endl;
            cout<<"��Ʒ�۸�:"<<k->price<<endl;
            cout<<"������:"<<k->date<<endl;
            if(k ->isinport == 0)cout<<"�ǽ���"<<endl;
            else cout<<"����"<<endl;
        }
    }else if(choice == 8){
        cout<<"�����������:";
        int x;
        cin>>x;
        cout<<endl;
        if(root ->child == NULL){
            root ->price *= (int)x*0.1;
        }
        onSale(root ->child,x*0.1);
        cout<<"���۳ɹ�"<<endl;
    }else if(choice == 9){
        vector<string>v;
        findGoodLessN(head,v);
        if(v.size() == 0){
            cout<<"û�б�����С��90���"<<endl;
        }else {
            cout<<"�����ڵ���90�����Ʒ��:"<<endl;
            for(int i = 0 ;i < v.size() ; i ++){
               cout<<v[i]<<endl;
             }
        }
    }else if(choice == 10){
        vector<string>v;
        findInportGood(head,v);
         if(v.size() == 0){
            cout<<"û�н�����Ʒ"<<endl;
        }else {
            cout<<"������Ʒ��:"<<endl;
            for(int i = 0 ;i < v.size() ; i ++){
               cout<<v[i]<<endl;
             }
        }
    }else if(choice == 11){
        cout<<"������Ʒ����:";
        string s;
        cin>>s;
        Node *k = findNode(head,s);
        if(k == NULL){
            cout<<"û�������Ʒ"<<endl;
        }else {
           cout<<"�޸���Ʒ����:"<<endl;
           cin>>k -> name;
           cout<<"�޸���Ʒ�۸�:"<<endl;
           cin>>k -> price;
           cout<<"�޸���Ʒ������:"<<endl;
           cin>>k -> date;
           cout<<"�޸���Ʒ������Ϣ 0-�ǽ��� 1-����:"<<endl;
           cin>>k -> isinport;
        }
    }
  }
}