#include <bits/stdc++.h>
using namespace std;

class Stack;
class node
{
    int data;
    node *next;
    friend class Stack;
    node()
    {
        data=0;next=NULL;
    }
};

class Stack
{
    node *top;
public:
    Stack()
    {
        top=NULL;
    }
    ~Stack()
    {
        if(!top) return;
        node *p=top;
        while(top)
        {
            top=top->next;
            delete p;
        }
        delete p;
    }

    bool isEmpty()
    {
        return top==NULL;
    }

    bool isFull()
    {
        return NULL==new node;
    }

    bool push(int x)
    {
        node *p=new node;
        if(p==NULL)
        {
            cout<<"Stack Overflow\n";
            return false;
        }
        else
        {
            p->data=x;
            p->next=top;
            top=p;
            return true;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        else
        {   
           node *p=top;
           int x=p->data;
           top=top->next;
           delete p;
           return x;
        }
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {
        cout<<"Stack is : \n";
        for(node *i=top;i!=NULL;i=i->next)
        {
            cout<<i->data<<endl;
        }
        cout<<endl;
    }

    int peek(int index)
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        node *p=top;
        while(p && --index)
        {
            p=p->next;
        }
        if(!p)
        {
            cout<<"Out of Bound\n";
            return -1;
        }
        else
        {
            return p->data;
        }
        
    }

};

int main()
{
    Stack *s=new Stack();
    for(int i=0;i<10;++i)
        s->push(i*i);
    s->push(12);
    s->display();
    for(int i=0;i<9;++i)
        cout<<s->pop()<<endl;

    cout<<endl<<endl;
    return 0;
}
