#include <bits/stdc++.h>
using namespace std;

class DLL;

struct node
{
        node *prev;
        int data;
        node *next;
};

/*
class node
{
public:
    int data;
    node *head;
}
*/

/*
class node
{
    friend class DLL;
    int data;
    node *head;
}
*/

class DLL
{
    int size;
    node *head,*tail;
public:
    DLL()
    {
        head=NULL;
        size=0;
        tail=NULL;
    }

    ~DLL()
    {
        node *p=this->head;
        while(this->head)
        {
            this->head=this->head->next;
            delete p;
            p=this->head;
        }
        delete p;
        cout<<"\n\nDestructed\n\n";
    }

    int displaySize()
    {
        cout<<"Size : "<<this->size<<endl;
    }

    void display()
    {
        int choice=0;
        node *traverse;
        do
        {
            cout<<"1. Forward\n2. Backward\nEnter : ";
            cin>>choice;
        }while(choice!=1 && choice !=2);
        if(choice==1)   traverse=head;
        else traverse=tail;
        if(!traverse)   return;
        cout<<"List is : ";
        while(traverse)
        {
            cout<<traverse->data<<" ";
            if(choice==1)   traverse=traverse->next;
            else traverse=traverse->prev;
        }
        cout<<endl;
    }

    void insert(int val,int index=-1)
    {
        if(index<-1 || index > this->size - 1 && this->size!=0) 
        {  
            cout<<"Failed\n";  
            return;
        }
        if(index==-1)   index=this->size;
        node *p=new node();
        p->data=val;
        if(!index)
        {
            if(this->head==NULL && this->tail==NULL)
            {
                this->head=new node();
                this->head->data=p->data;
                this->head->next=NULL;
                this->head->prev=NULL;
                this->tail=this->head;
            }
            else
            {
                this->tail=this->head;
                p->next=this->head;
                this->head=p;
                this->head->prev=NULL;
                this->tail->prev=this->head;
            }
        }
        else
        {
            node *t=this->head;
            while(t->next)
            {
                if(index<this->size)
                    index--;
                    if(index==0)
                        break;
                t=t->next;
            }
            p->next=t->next;
            t->next=p;
            p->prev=t;
            if(p->next)
                p->next->prev=p;
            else
                this->tail=p;
        }
        ++this->size;
    }

    void reverseLL()
    {
        if(this->size<2) return;
        node *q=this->head,*r;
        this->tail=this->head;
        while(q)
        {
            r=q->next;
            q->next=q->prev;
            q->prev=r;
            q=q->prev;
            if(q!=NULL && q->next==NULL)
                this->head=q;
        }
    }

    void merge(DLL *p,DLL *q)
    {
        node *a=p->head,*b=q->head;
        while(a && b)
        {
            if(a->data < b->data)
            {
                this->insert(a->data);
                a=a->next;
            }
            else if(a->data > b->data)
            {
                this->insert(b->data);
                b=b->next;
            }
            else
            {
                this->insert(a->data);
                this->insert(b->data);
                a=a->next;
                b=b->next;
            }
        }
        while(a)
        {
            this->insert(a->data);
            a=a->next;
        }
        while(b)
        {
            this->insert(b->data);
            b=b->next;
        }
    }
};

int main()
{
    DLL *l1=new DLL();
    for(int i=10;i<10+12;++i)
        l1->insert(i*2+4);
    l1->display();

    DLL *l2=new DLL();
    for(int i=10;i<10+12;++i)
        l2->insert(i*5+14/2+1-10*2);
    l2->display();

    DLL *l3=new DLL();
    l3->merge(l2,l1);
    l3->display();
    
    cout<<endl<<endl;
    return 0;
}
