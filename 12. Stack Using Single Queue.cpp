#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Stack
{
    queue<int> a;
public:
    void push(int val)
    {
        int n=a.size();
        a.push(val);
        while(n--)
        {
            a.push(a.front());
            a.pop();
        }
    }

    void pop() 
    {
        if(a.empty())
        {
            cout<<"Stack is Empty"<<nl;
            return;
        }
        a.pop();
    }
    
    int top()
    {
        if(!a.empty())
        {
            return a.front();
        }
        cout<<"Stack is Empty\n";
        return -1;
    }
};

int main()
{
    fast_input;
    tie_off;
    
    Stack *p=new Stack();
    loop(i,0,3)
        p->push(i+1);
    loop(j,0,1)
        p->pop();
    loop(i,0,3)
        p->push(i+1);
    loop(j,0,4)
        p->pop();
    cout<<p->top()<<nl;
    
    cout<<endl<<endl;
    return 0;
}
