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

void combine3(LinkedList l1,LinkedList l2,LinkedList l3,LinkedList&l){
    Node*t1=l1.root,*t2=l2.root,*t3=l3.root;
    if(t1->val<t2->val){
        if(t1->val<t3->val){
            Node*n=new Node(t1->val);l.root=n;
            t1=t1->next;
        }
        else{
            Node*n=new Node(t3->val);l.root=n;
            t3=t3->next;
        }
    }
    else{
        if(t2->val<t3->val){
            Node*n=new Node(t2->val);l.root=n;
            t2=t2->next;
        }
        else{
            Node*n=new Node(t3->val);l.root=n;
            t3=t3->next;
        }
    }
    // return;
    Node*temp = l.root;
    while(t1!=NULL||t2!=NULL||t3!=NULL){
        if(t1!=NULL&&t2!=NULL&&t3!=NULL){
            if(t1->val<t2->val){
                if(t1->val<t3->val){
                    Node*n=new Node(t1->val);temp->next=n;
                    t1=t1->next;temp = n;
                }
                else{
                    Node*n=new Node(t3->val);temp->next=n;
                    t3=t3->next;temp = n;
                }
            }
            else{
                if(t2->val<t3->val){
                    Node*n=new Node(t2->val);temp->next=n;
                    t2=t2->next;temp = n;
                }
                else{
                    Node*n=new Node(t3->val);temp->next=n;
                    t3=t3->next;temp = n;
                }
            }
        }
        // else break;
        // if(true)continue;
        else if(t1==NULL){
            if(t2==NULL){
                Node*n=new Node(t3->val);temp->next=n;
                t3=t3->next;temp = n;
            }
            else if(t3==NULL){
                Node*n=new Node(t2->val);temp->next=n;
                t2=t2->next;temp = n;
            }
            else{
                if(t2->val<t3->val){
                    Node*n=new Node(t2->val);temp->next=n;
                    t2=t2->next;temp = n;
                }
                else{
                    Node*n=new Node(t3->val);temp->next=n;
                    t3=t3->next;temp = n;
                }
            }
        }
        // else break;
        // if(true)continue;
        else if(t3==NULL){
            if(t2==NULL){
                Node*n=new Node(t1->val);temp->next=n;
                t1=t1->next;temp = n;
            }
            else if(t1==NULL){
                Node*n=new Node(t2->val);temp->next=n;
                t2=t2->next;temp = n;
            }
            else{
                if(t2->val<t1->val){
                    Node*n=new Node(t2->val);temp->next=n;
                    t2=t2->next;temp = n;
                }
                else{
                    Node*n=new Node(t1->val);temp->next=n;
                    t1=t1->next;temp = n;
                }
            }
        }
        // else break;
        // if(true)continue;
        else if(t2==NULL){
            if(t1==NULL){
                Node*n=new Node(t3->val);temp->next=n;
                t3=t3->next;temp = n;
            }
            else if(t3==NULL){
                Node*n=new Node(t1->val);temp->next=n;
                t1=t1->next;temp = n;
            }
            else{
                if(t1->val<t3->val){
                    Node*n=new Node(t1->val);temp->next=n;
                    t1=t1->next;temp = n;
                }
                else{
                    Node*n=new Node(t3->val);temp->next=n;
                    t3=t3->next;temp = n;
                }
            }
        }
        // temp=temp->next;
    }
}

void combine2(LinkedList l1,LinkedList l2,LinkedList& lx){
    Node*t1=l1.root,*t2=l2.root;
    if(t1->val<t2->val){
        Node*n=new Node(t1->val);lx.root=n;
        t1=t1->next;
    }
    else{
        Node*n=new Node(t2->val);lx.root=n;
        t2=t2->next;
    }
    Node*temp=lx.root;
    while(t1!=NULL||t2!=NULL){
        if(t1!=NULL&&t2!=NULL){
           if(t1->val<t2->val){
                Node*n=new Node(t1->val);temp->next=n;
                t1=t1->next;temp=n;
            }
            else{
                Node*n=new Node(t2->val);temp->next=n;
                t2=t2->next;temp=n;
            }
        }
        if(t1==NULL){
            Node*n=new Node(t2->val);temp->next=n;
            t2=t2->next;temp=n;
        }
        else{
            Node*n=new Node(t1->val);temp->next=n;
            t1=t1->next;temp=n;
        }
    }
}

int main(){
    LinkedList l1,l2,l3,l4;
    vector<int>v1 = {1,5,10,20,22,34};
    vector<int>v2 = {4,6,7,30,90};
    vector<int>v3 = {2,10,16,22,26,30};
    l1.create(v1);l2.create(v2);l3.create(v3);
    l1.print();l2.print();l3.print();

    LinkedList l;
    combine3(l1,l2,l3,l);
    l.print();
    cout<<endl;

    LinkedList lx;
    combine2(l1,l3,lx);
    lx.print();

    return 0;
}