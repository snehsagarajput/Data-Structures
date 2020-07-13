#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Queue
{
    stack<int> a,b;
public:
    void enqueue(int val)
    {
        a.push(val);
    }

    void dequeue() 
    {
        if(b.empty())
        {
            if(a.empty())
            {
                cout<<"Queue is Empty\n";
                return;
            }
            else
            {
                while(!a.empty())
                {
                    b.push(a.top());
                    a.pop();
                }
            }
        }
        cout<<b.top()<<nl;
        b.pop();
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
    loop(i,0,15)
        p->dequeue();
    cout<<endl<<endl;
    return 0;
}
