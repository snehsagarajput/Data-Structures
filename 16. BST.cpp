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
    Node(int k=0)
    {
        key=k;
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
    
    void traversal(int choice=4)
    {
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


	Node *searchBSTutils(Node *p ,int k)
	{
		if(!p) return NULL;
		if(p->key == k)	return p;
		else if(p->key < k)	return searchBSTutils(p->right, k);
		else 	return searchBSTutils(p->left, k);
	}
	void searchBST(int k)
	{	
		Node *p=searchBSTutils(this->root, k);
		if(p)	cout<<"Found\n";
		else cout<<"Not Found\n";
	} 

	void iterativeSearchBST(int val)
	{
		Node *p=root;
		while(p)
		{
			if(p->key == val)
			{	
				cout<<"Found\n";
				break;
			}
			else if(val<p->key)	p=p->left;
			else p=p->right;
		}
		if(!p)	cout<<"Not Found\n";
	}

	void insertBSTutils(Node *p, Node *q, int val)
	{
		if(!p && !q)
		{
			root=new Node(val);
			return;
		}
		else if(!p)
		{
			if(q->key < val)
			{
				q->right=new Node(val);
			}
			else
				q->left=new Node(val);
			return;
		}
		else if(p->key == val)	return;
		else if(p->key < val)	insertBSTutils(p->right, p, val);
		else insertBSTutils(p->left, p, val);
	}
	void insertBST(int val)
	{
		insertBSTutils(this->root,	NULL, val);
	}
};

int main()
{
    Tree *p=new Tree();
    vector<int> a={1,2,3,5,2,4,1,3,4,5,7,5,3,5,7,34,435,456,23,8,9};
    for(auto i:a)
		p->insertBST(i);
	p->traversal();

    cout<<endl<<endl;
    return 0;
}
