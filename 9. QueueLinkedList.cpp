#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

struct Node
{
    int data;
    Node *next;
    Node()
    {
        data=0;
        next=NULL;
    }
};

class QueueLL
{
    unsigned size;
    Node *front,*rear;
public:
    QueueLL()
    {
        front=rear=NULL;
        size=0;
    }
    
    bool isEmpty()
    {
        return rear==NULL && front==NULL;
    }
    
    void enqueue(int val)
    {
        Node *p=new Node();
        if(p==NULL)
        {
            cout<<"Queue Full";
            return;
        }
        ++size;
        p->data=val;
        p->next=NULL;
        if(front==NULL)
        {
            front=rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Empty\n";
            return;
        }
        --size;
        Node *p=front;
        if(front->next==NULL)//only one node
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
        delete p;
    }
    
    int top()
    {
        if(!isEmpty())  return rear->data;
        else return -1;
    }
    
    void display()
    {
        if(isEmpty())
        {
            cout<<"Empty\n";
            return;
        }
        cout<<"Queue is : ";
        for(Node *p=front;p!=NULL;p=p->next)
            cout<<p->data<<" ";
        cout<<nl;
    }
};

int main()
{
    fast_input;
    tie_off;

    QueueLL *p=new QueueLL();
    p->enqueue(10);
    p->dequeue();
    p->enqueue(10);
    p->enqueue(10);
    p->enqueue(10);
    
    p->display();

    cout<<endl<<endl;
    return 0;
}
