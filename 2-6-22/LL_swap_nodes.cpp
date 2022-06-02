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
    // 1->2->3->4->5->6->null
    // 1->5->3->4->2->6->null
    void swap_nodes(int key1, int key2){
        Node*p1=NULL,*p2=NULL;
        Node*t1=root,*t2=root;
        while(t1!=NULL&&t1->val!=key1&&t1->val!=key2){p1=t1;t1=t1->next;}
        if(t1==NULL)return;
        t2=t1->next;
        p2=t1;
        while(t2!=NULL&&(t2->val!=key1&&t2->val!=key2)){p2=t2;t2=t2->next;}
        if(t2==NULL)return;
        if(p1!=NULL)p1->next=t2;
        else root=t2;
        if(t1!=p2){
            p2->next=t1;

            p1 = t2->next;
            t2->next = t1->next;
            t1->next = p1;
        }
        else{
            t1->next = t2->next;
            t2->next = t1;
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
    vector<int>v = {1,2,3,4,5,6,7,8,9};
    l.create(v);
    l.print();
    l.swap_nodes(5,6);
    l.print();
    return 0;
}