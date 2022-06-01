#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next=NULL;
    }
};

class LinkedList{
public:
    Node*root=NULL;
    void create(vector<int>v){
        if(v.size()==0){root=NULL;return;}
        Node*n=new Node(v[0]); root=n;
        Node*temp=root;
        for(int i=1;i<v.size();++i){
            Node*n1=new Node(v[i]);
            temp->next=n1;
            temp=n1;
        }
    }

    void delete_head(){
        if(root==NULL)return;
        Node*temp = root;
        root=root->next;
        delete temp;
    }

    void delete_end(){
        if(root==NULL)return;
        if(root->next==NULL){
            Node*temp=root;root=NULL;
            delete temp;
            return;
        }
        Node*temp=root;
        while(temp->next->next!=NULL) temp = temp->next;
        Node*t=temp->next;
        temp->next=NULL;
        delete t;
    }

    void delete_mid(int val){
        Node*temp=root;
        Node*prev=NULL;
        while(temp!=NULL&&temp->val!=val){prev=temp;temp=temp->next;}
        if(temp==NULL)return;
        if(temp==root){delete_head();}
        else{
            prev->next = temp ->next;
            delete temp;
        }
    }

    void print(){
        Node*temp=root;
        cout<<"Linked List --->> ";
        while(temp!=NULL){
            cout<<temp->val<<", ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList l;
    vector<int>v = {1,2,3,4,5,6,7,8};
    l.create(v);
    l.delete_end();   // 8
    l.delete_mid(4);  // 4
    l.delete_head();  // 1
    l.delete_mid(6);  // 6
    l.delete_head();  // 2
    l.print();
    return 0;
}