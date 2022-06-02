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

    int length_recursive(Node*n,int k=0){
        if(n==NULL)return k;
        return length_recursive(n->next,k+1);
    }

    int length_iterative(){
        Node*temp=root;
        int cnt=0;
        while(temp!=NULL){temp=temp->next;cnt++;}
        return cnt;
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
    vector<int>v = {1,2,3,4,5};
    l.create(v);
    cout<<"Recursive - "<<l.length_recursive(l.root)<<endl;
    cout<<"Iterative - "<<l.length_iterative()<<endl;
    return 0;
}