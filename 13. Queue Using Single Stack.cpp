#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Queue
{
    stack<int> a;
public:
    void enqueue(int val)
    {
        a.push(val);
    }
    
    bool deletelast(stack<int> &a)
    {
        if(a.empty())
            return false;
        int x=a.top();
        a.pop();
        bool val=deletelast(a);
        if(val)
            a.push(x);
        return true;
    }
    void dequeue() 
    {
        if(a.empty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        deletelast(a);
    }
    
    void displayUtil(stack<int> a)
    {
        if(a.empty())
            return;
        int x=a.top();
        a.pop();
        displayUtil(a);
        cout<<x<<" ";
    }
    void display()
    {
        displayUtil(a);
    }
};

int main()
{
    fast_input;
    tie_off;
    
    Queue *p=new Queue();
    loop(i,0,10)
        p->enqueue(i+1);
    loop(i,0,5)
        p->dequeue();
    loop(i,10,20)
        p->enqueue(i+1);
    loop(i,0,10)
        p->dequeue();
    p->display();
    cout<<endl<<endl;
    return 0;
}
