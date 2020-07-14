#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Stack
{
    stack<int> a;
    stack<int> extra;
public:
    void push(int val)
    {
        a.push(val);
        if(extra.empty())
        {
          extra.push(val);
          return;
        }
        else if(val<=extra.top())
        {
          extra.push(val);
        }
    }

    void pop()
    {
      if(a.empty())
      {
          cout<<"Stack is Empty\n";
          return;
      }
      else if(a.top()==extra.top())
      {
          extra.pop();
      }
        a.pop();
    }

    int getMin()
    {
        if(!extra.empty())
      return extra.top();
        else
            return -1;
    }

};

int main()
{
    fast_input;
    tie_off;
    
    Stack *s = new Stack();
    s->push(2);
    s->push(3);
    s->push(2);
    s->push(2);
    s->push(6);
    s->push(1);
    s->push(0);
    s->push(1);
    s->push(3);
    s->push(3);
    
    loop(i,0,10)
      s->pop();
    cout<<(s->getMin())<<nl;

    cout<<endl<<endl;
    return 0;
}
