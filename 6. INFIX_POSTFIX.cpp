#include <bits/stdc++.h>
using namespace std;

#define datatype char

class Stack;
class node
{
    datatype data;
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

    bool push(datatype x)
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

    datatype pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow\n";
            return -1;
        }
        else
        {   
           node *p=top;
           datatype x=p->data;
           top=top->next;
           delete p;
           return x;
        }
    }

    datatype peek()
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

    datatype peek(int index)
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

bool isBalanced(string s)
{
    Stack *p=new Stack();
    for(auto i:s)
    {
        if(i=='(' || i=='{' || i=='[')  p->push(i);
        else if(i==')' || i=='}' || i==']')
        {
            if(p->isEmpty())    return false;
            datatype x=i-p->pop();
            if(x<1 || x>2)  return false;
        }
    }
    return p->isEmpty()?true:false;
}

int outPrecedence(const char c)
{
    if(c=='+' || c=='-')    return 1;
    else if(c=='*' || c=='/')   return 3;
    else if(c=='^') return 6;
    else if(c=='(') return 7;
    else /*if(c==')')*/  return 0;
}
int inPrecedence(const char c)
{
    if(c=='+' || c=='-')    return 2;
    else if(c=='*' || c=='/')   return 4;
    else if(c=='^') return 5;
    else if(c=='(') return 0;
}
bool isOperator(const char i)
{
    return (i=='+' || i=='-' || i=='*' || i=='/' || i=='(' || i==')');
}

string infixToPostfix(string s)
{
    string postfix="";
    Stack *p=new Stack();
    //p->push('#');
    int index=0;
    while(index<s.size())
    {
        char i=s[index];
        if(isOperator(i))
        {
            if(p->isEmpty() || outPrecedence(i)>inPrecedence(p->peek()))
            {
                p->push(i);
                index++;
            }
            else if(outPrecedence(i)<=inPrecedence(p->peek()))
            {
                if(i==')')
                {
                    while(p->peek()!='(')
                    {
                        if(p->isEmpty())
                        {    
                            cout<<"Invalid expression";
                            return "";
                        }
                        postfix += p->pop();
                    }
                    p->pop(); //pop '('
                    ++index;
                }
                else
                {
                    postfix += p->pop();   
                }
            }
        }
        else
        {
            postfix += i;
            index++;
        }
    }
    while(!p->isEmpty()) 
    {
       postfix += p->pop();
    }
    return postfix;
}

int main()
{

    string s="((a+b)*c)-d^e^f";
    cout<<infixToPostfix(s);
    
    cout<<endl<<endl;
    return 0;
}
