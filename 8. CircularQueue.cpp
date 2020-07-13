#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class CircularQueue
{
    int front,rear;
    unsigned capacity,size;
    int *A;
public:
    CircularQueue(int capacity=100)
    {
        front=rear=-1;
        size=0;
        this->capacity=capacity;
        A=new int [capacity];
    }
    
    bool isFull()
    {
        if(front==-1)   return rear==capacity-1;
        return (this->rear + 1) % this->capacity == this->front;  //check also if front!=-1
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
        rear=(rear+1)%capacity;
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
        front=(front+1) % capacity;
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
        int i=(front+1)%capacity;
        if(front==-1){   loop(i,0,capacity) cout<<A[i]<<" "; cout<<nl; return; }
        while(i!=(rear+1)%capacity)
        {
            cout<<A[i]<<" ";
            i=(i+1)%capacity;
        }
        cout<<nl;
    }
};

int main()
{
    fast_input;
    tie_off;

    CircularQueue *p=new CircularQueue(6);
    loop(i,0,5)
        p->enqueue(i);
    p->dequeue();
    p->dequeue();
    p->enqueue(6);
    p->enqueue(7);
    p->display();

    cout<<endl<<endl;
    return 0;
}
