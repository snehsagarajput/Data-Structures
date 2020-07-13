#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Queue
{
    int front,rear;
    unsigned capacity,size;
    int *A;
public:
    Queue(int capacity=100)
    {
        front=rear=-1;
        size=0;
        this->capacity=capacity;
        A=new int [capacity];
    }
    
    bool isFull()
    {
        return this->rear == this->capacity - 1;
      //return size==capacity;  
    }
    
    bool isEmpty()
    {
        return this->front == this->rear;
      //return !size;
    }
    
    void enqueue(int val)
    {
        if(isFull())
        {
            cout<<"Already Full\nFailed\n";
            return;
        }
        ++size;
        ++(this->rear);
        A[this->rear]=val;
    }
    
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Empty\n";
            return;
        }
        --size;
        ++(this->front);
    }
    
    int top()
    {
        if(!isEmpty())  return A[rear];
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
        for(int i=front+1;i<rear+1;++i)
        {
            cout<<A[i]<<" ";
        }
        cout<<nl;
    }
};

int main()
{
    fast_input;
    tie_off;

    Queue *p=new Queue(10);
    
    for(int i=0;i<5;++i)
        p->enqueue(i);

    loop(j,0,2)
    {
        p->dequeue();
    }
    
    p->display();
    cout<< p->top();

    cout<<endl<<endl;
    return 0;
}
