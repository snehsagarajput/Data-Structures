#include <bits/stdc++.h>
using namespace std;

class LL;

struct node
{
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
    friend class LL;
    int data;
    node *head;
}
*/

class LL
{
    int size;
    node *head;
public:
    LL()
    {
        head=NULL;
        size=0;
    }

    ~LL()
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
        if(!this->head)   return;
        node *p=this->head;
        cout<<"List is : ";
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    void insert(int val,int index=-1)
    {
        if(index<-1 || index > this->size - 1) 
        {  
            cout<<"Failed\n";  
            return;
        }
        if(index==-1)   index=this->size;
        node *p=new node();
        p->data=val;
        if(!index)
        {
            if(this->head==NULL)
            {
                this->head=new node();
                this->head->data=p->data;
                this->head->next=NULL;
            }
            else
            {
                p->next=this->head;
                this->head=p;
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
        }
        ++this->size;
    }

    void reverseLL()
    {
        if(this->size<2) return;
        node *r=NULL,*q=NULL,*p=this->head;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        this->head=q;
    }

    void recursiveLLreverse()
    {
        recursive(this->head);
    }
    void recursive(node *p=NULL,node *q=NULL)
    {
        if(p)
        {
            recursive(p->next,p);
            p->next=q;
        }
        else
            this->head=q;
    }

    void merge(LL *p,LL *q)
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
    LL *l1=new LL();
    for(int i=0;i<10;i+=2)
        l1->insert(i+1);
    cout<<"L1: ";
    l1->display();

    LL *l2=new LL();
    for(int i=0;i<15;i+=3)
        l2->insert(i);
    cout<<"L2 :";
    l2->display();

    LL *l3=new LL();
    l3->merge(l1,l2);
    l3->display();

    delete l1;
    delete l2;
    delete l3;


    cout<<endl<<endl;
    return 0;
}
