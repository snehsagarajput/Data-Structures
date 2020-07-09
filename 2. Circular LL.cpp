#include <bits/stdc++.h>
using namespace std;

class CLL;

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

class CLL
{
    int size;
    node *head;
public:
    CLL()
    {
        head=NULL;
        size=0;
    }

    ~CLL()
    {
        node *p=this->head;
        if(!p)  return;
        do
        {
            this->head=this->head->next;
            delete p;
            p=this->head;
        }while(p!=this->head);
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
        do
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        while(p!=this->head);
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
                this->head->next=this->head;
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
            do
            {
                t=t->next;
            }
            while(t->next!=this->head);
            p->next=t->next;
            t->next=p;
        }
        ++this->size;
    }

    void recursiveLLreverse()
    {
        node* last=this->head;
        while(last->next!=this->head)
            last=last->next;
        recursive(this->head,last);
    }
    void recursive(node *p=NULL,node *q=NULL)
    {
        static node *last=q;
        static int flag =0;
        if(p!=last->next || flag==0)
        {
            flag=1;
            recursive(p->next,p);
            p->next=q;
        }
        else
        {
            flag=0;
            this->head=q;
        }
    }

};

int main()
{
    CLL *l=new CLL();
    for(int i=0;i<2;++i)
        l->insert(i*5/3);
    l->display();
    l->recursiveLLreverse();
    l->display();

    delete l;

    cout<<endl<<endl;
    return 0;
}
