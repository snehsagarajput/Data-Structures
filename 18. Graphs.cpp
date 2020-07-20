#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

class Graph
{
    int v;
    vector<vector<int>> list;
public:
    Graph(int n)
    {
        v=n;
        list.reserve(v);
    }
    
    void addVertice(int u, int v)
    {
        list[u].push_back(v);
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
		if(	!visited[init]	)
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
	}
	void DFS(int init=0)
	{
		bool *visited=new bool[v];
		memset(visited,0,sizeof(bool)*v);
		DFSutils(visited, init);
	}
};


int main()
{
    Graph *p=new Graph(4);
    p->addVertice(0,1);
    p->addVertice(0,2);
    p->addVertice(1,2);
    p->addVertice(2,0);
	p->addVertice(2,3);
	p->addVertice(3,3);
    
    p->display();

	p->DFS(2);
    
    
    return 0;
}
