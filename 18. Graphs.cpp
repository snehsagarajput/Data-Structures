#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)
#define inf numeric_limits<double>::infinity()


class Graph
{
    int v;
    vector<vector<int>> list;
    char type;//d: directed ||||||| u: undirected
public:
    Graph(int n,char t='u')
    {
        type=t;
        v=n;
        list.reserve(v);
    }
    
    void addVertice(int u, int v)
    {
        list[u].push_back(v);
        if(type=='u' && u!=v)
            list[v].push_back(u);
    }
  
    void display()
    {
        for(int i=0;i<v;++i)
        {
            cout<<i<<" :";
            for(auto j: list[i])
            {
                    cout<<j<<" ";
            }
            cout<<nl;
        }
    }

	void BFS(int init=0)
	{
		cout<<nl;
		bool *visited=new bool[v];
		memset(visited, false, v*sizeof(bool));
		queue<int> q;
		q.push(init);
		visited[init]=1;
		while(!q.empty())
		{
			int s=q.front();
			q.pop();
			cout<<s<<" ";
			for(auto i : list[s])
			{
				if(!visited[i])
				{
					visited[i]=1;
					q.push(i);
				}
			}
		}
		cout<<nl;
	}

	void DFSutils(bool *visited, int init)
	{   
	        cout<<init<<" ";
			visited[init]=1;
			for(auto i : list[init])
			{
				if(!visited[i])
				{
					DFSutils(visited, i);
				}
			}
	}
	void DFS()
	{
		bool *visited=new bool[v];
		memset(visited,0,sizeof(bool)*v);
        for(int i=0;i<v;i++)
            if(!visited[i])
		        DFSutils(visited, i);
	}
    
    
    bool isCycleUtils(bool *visited, int init ,int parent)
	{
	    if(!visited[init])
	    {
    	    visited[init]=1;
    	    for(auto i : list[init])
    		{
    		        if(visited[i] && i!= parent)
    		            return true;
    		        if(!visited[i]  && isCycleUtils(visited, i, init))
    		            return true;
    		}
	    }
        return false;
	}

    bool isDirectedCycleUtils(bool *visited,int init, bool *recStack)    
	{
        if(!visited[init])
        {
            visited[init]=true;
            recStack[init]=true;
            for(auto i: list[init])
            {
                if(visited[i] && recStack[i])
                    return true;
                if(!visited[i] && isDirectedCycleUtils(visited, i, recStack))
                    return true;
            }
        }
        recStack[init]=false;
        return false;
    }

    bool isCycle()
	{
		bool *visited=new bool[v];
		memset(visited,0,sizeof(bool)*v);
        if(type=='u')
        {   
            for(int i=0;i<v;++i)
                if(!visited[i] && isCycleUtils(visited, i , -1))
                    return true;
            return false;
        }
        else if(type=='d')
        {
            bool *recStack=new bool[v];
		    memset(recStack,0,sizeof(bool)*v);
            for(int i=0;i<v;++i)
                if(isDirectedCycleUtils(visited, i , recStack))
                    return true;
            return false;
        }
    }
};


int main()
{
    int vertices=6;
    Graph *p=new Graph(vertices,'d');
    p->addVertice(0,1);
    p->addVertice(1,2);
    p->addVertice(2,3);
    p->addVertice(1,4);
    p->addVertice(4,5);
    p->addVertice(5,0);
    
    p->display();

	p->DFS();
    
    cout<<nl<<p->isCycle()<<nl;
    
    return 0;
}
