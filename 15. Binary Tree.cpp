#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node()
    {
        key=0;
        left=right=NULL;
    }
};

class Tree
{
    Node *root;
public:
    Tree()
    {
        root=NULL;
    }
    
    void create() //level order insertion
    {
        Node *p;
        queue<Node*> a;
        p=new Node();
        cout<<"Enter Root Val : ";
		int val;
        cin>>val;
		p->key=val;
        root=p;
        a.push(p);
        while(!a.empty())
        {
            //this->levelTraversal();
            p=a.front();
            a.pop();
            int val;
            
            cout<<"Want left child :\n-1 : No\nElse : enter direct val : ";
            cin>>val;
            if(val!=-1)
            {
                p->left=new Node();
                p->left->key=val;
                a.push(p->left);
            }
            
            cout<<"Want right child :\n-1 : No\nElse : enter direct val : ";
            cin>>val;
            if(val!=-1)
            {
                p->right=new Node();
                p->right->key=val;
                a.push(p->right);
            }
        }
        cout<<nl<<nl;
    }
    
    void traversal()
    {
        int choice;
        do
        {
            cout<<"1. Preorder\n2. Inorder\n3.Postorder\n4. LevelOrder\nChoice : ";
            cin>>choice;
        }while(choice<1 || choice>4);
        if(choice==1)   preorderUtils(this->root);
        else if(choice==2) inorderUtils(this->root);
        else if(choice==3)  postorderUtils(this->root);
        else    levelUtils(this->root);
        
        cout<<nl<<nl;
    }
    
    void preorderUtils(Node *p)
    {
        if(p)
        {
            cout<<p->key<<" ";
            preorderUtils(p->left);
            preorderUtils(p->right);
        }
    }
    
    void inorderUtils(Node *p)
    {
        if(p)
        {
            inorderUtils(p->left);
            cout<<p->key<<" ";
            inorderUtils(p->right);
        }
    }
    
    void postorderUtils(Node *p)
    {
        if(p)
        {
            postorderUtils(p->left);
            postorderUtils(p->right); 
            cout<<p->key<<" ";
        }
    }
    
    void levelUtils(Node *root)
    {
        cout<<"\nTree : ";
        Node *p=root;
        queue<Node*> a;
        a.push(p);
        cout<<p->key<<" ";
        while(!a.empty())
        {
            p=a.front();
            a.pop();
            if(p->left) 
            {    
                a.push(p->left);
                cout<<p->left->key<<" ";
            }
            if(p->right) 
            {    
                a.push(p->right);
                cout<<p->right->key<<" ";
            }
        }
        cout<<nl;
    }

    int countNodes()
    {
        queue <Node*> a;
        int ans=0;
        if(!root)   return ans;
        a.push(root);
        while(!a.empty())
        {
            Node *p=a.front();
            a.pop();
            ++ans;
            if(p->left)
            {
                a.push(p->left);
            }
            if(p->right)
            {
                a.push(p->right);
            }
        }
        return ans;
    }
    
    void maxHeight()
    {
        cout<<"Max Height : "<<maxHeightUtils(this->root)-1<<nl;;
    }

    int maxHeightUtils(Node *p)
    {
        if(!p)  return 0;
        int lHeight = maxHeightUtils(p->left);
        int rHeight = maxHeightUtils(p->right);
        return lHeight > rHeight ? lHeight+1 : rHeight+1;
    }
	

     bool childrenSumUtils(Node *p)
    {
        if(!p)  return true;
        if(!p->right && !p->left)   return true;
        int sum=0;
        if(p->left)    sum+=p->left->key;
        if(p->right)    sum+=p->right->key;
        return (p->key==sum) && childrenSumUtils(p->left) && childrenSumUtils(p->right);
    }
    bool childrenSum()
    {
        return childrenSumUtils(this->root);
    }
};

int main()
{
    Tree *p=new Tree();
    p->create();
    cout<<"Count of Nodes : "<<p->countNodes();

    cout<<endl<<endl;
    return 0;
}
