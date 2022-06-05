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

    void merge(Node*s1,Node*e1,Node*s2,Node*e2){
        // to be completed   
    }

    void mergeSort(Node*start,Node*end){
        if(start==end)return;
        Node*slow=start,*fast=start;
        while(fast!=end && fast->next!=end)
            {slow=slow->next;fast=fast->next->next;}
        mergeSort(start,slow);
        mergeSort(slow->next,end);

        merge(start,slow,slow->next,end);
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
    vector<int>v = {22,16,26,2,10,30,5,4,8};
    l.create(v);
    l.print();
    return 0;
}