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
    void insert_head(int val){
        Node*n=new Node(val);
        n->next=root;
        root=n;
    }
    void insert_mid(int val,int prev_val){ // insert after prev_val
        Node*temp=root;
        Node*n=new Node(val);
        while(temp!=NULL&&temp->val!=prev_val)temp=temp->next;
        if(temp!=NULL){
            n->next=temp->next;
            temp->next=n;
        }
    }
    void insert_end(int val){
        Node*n=new Node(val);
        if(root==NULL){root=n;return;}
        Node*temp=root;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=n;
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
    l.insert_head(2);
    l.insert_head(1);
    l.insert_end(4);
    l.insert_mid(3,2);
    l.insert_end(5);
    l.print();
    return 0;
}