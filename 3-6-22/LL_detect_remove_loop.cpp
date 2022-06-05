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

    int length_iterative(){
        Node*temp=root;
        int cnt=0;
        while(temp!=NULL){temp=temp->next;cnt++;}
        return cnt;
    }

    void create_loop(){
        int l = length_iterative();
        int x_random = rand()%l;
        Node*temp=root;
        while(x_random--)temp=temp->next;
        Node*y = temp;
        while(y->next!=NULL)y=y->next;
        y->next = temp;
    }

    bool isLoop(){
        Node*slow=root,*fast=root;
        if(root!=NULL)slow=slow->next;
        else return false;
        if(slow!=NULL)fast=fast->next->next;
        else return false;
        while(fast!=NULL && fast->next!=NULL && slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==fast)return true;
        return false;
    }

    void remove_loop(){
        Node*slow=root,*fast=root;
        slow=slow->next;fast=fast->next->next;
        while(slow!=fast){slow=slow->next;fast=fast->next->next;}
        Node*x= root;
        while(x->next!=slow->next){x=x->next;slow=slow->next;}
        slow->next=NULL;
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
    vector<int>v = {1,2,3,4,5,6,7,8,9,10};
    l.create(v);
    l.print();
    l.create_loop();
    l.remove_loop();
    l.print();
    return 0;
}