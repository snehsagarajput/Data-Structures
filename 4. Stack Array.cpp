#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

template<class T>
class Stack
{
    int size;
    int top;
    T *a;

public:
    Stack()
    {
        size=MAX;
        top=-1;
        a=new T [size];
    }
    Stack(int x)
    {
        size=x;
        top=-1;
        a=new T [size];
    }
    ~Stack()
    {
        delete [] a;
    }

    bool isEmpty()
    {
        return top==-1;
    }

    bool isFull()
    {
        return top==size-1;
    }

    bool push(T x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow\n";
            return false;
        }
        else
        {
            a[++top]=x;
            return true;
        }
        
    }

    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return T(-1);
        }
        else
        {   
           return a[top--];
        }
    }

    T peek()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return T(-1);
        }
        else
        {
            return a[top];
        }
    }

    void display()
    {
        cout<<"Stack is : \n";
        for(int i=top;i>-1;--i)
        {
            cout<<a[i]<<endl;
        }
        cout<<endl;
    }

    T peek(int index)
    {
        T x=T(-1);
        if(top-index+1<0)
        {
            cout<<"Out Of Bound\n";
        }
        else if(isEmpty())
        {
            cout<<"Stack Underflow\n";
        }
        else
        {
            x=a[top-index+1];
        }
        return x;
    }

};

int main()
{
    Stack<int> *s=new Stack<int>(10);
    for(int i=0;i<10;++i)
        s->push(i*i);
    s->push(12);
    s->display();
    for(int i=0;i<11;++i)
        cout<<s->pop()<<endl;
    cout<<endl<<endl;
    return 0;
}
