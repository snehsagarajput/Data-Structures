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
        cout<<nl;
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

    void shortestPath(int src, int dest)
    {
        if(src==dest)
        {
            cout<<"Path is : "<<src<<"-"<<src<<nl;
            cout<<"Shortest Distance : "<<0<<nl;
            return;
        }
        bool *visited=new bool[v];
        int *path=new int[v];
        memset(path, -1,sizeof(int)*v);
        queue<pair<int,int>> q;
        q.push(make_pair(src,0));
        visited[src]=true;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;++i)
            {
                int node=q.front().first;
                int dist=q.front().second;
                q.pop();
                for(auto j : list[node])
                {
                    
                    if(!visited[j])
                    {
                        visited[j] = true;
                        q.push(make_pair(j,dist+1));
                        path[j]=node;
                    }
                    if(dest==j)
                    {
                        cout<<"Path is : ";
                        int rider=dest;
                        vector<int> sp;
                        while(path[rider]!=-1)
                        {
                            sp.push_back(rider);
                            rider=path[rider];
                        }
                        sp.push_back(src);
                        for_each(sp.rbegin(),sp.rend(),[](int a){cout<<a<<" ";});
                        cout<<nl<<"Shortest Distance : "<<dist+1<<nl;
                        return;
                    }
                }
            }
        }
        //if reach here they are not connected
        cout<<-1<<nl;
    }
};


int main()
{
    int vertices=11;
    Graph *p=new Graph(vertices,'d');
    p->addVertice(0,1);
    p->addVertice(0,2);
    p->addVertice(1,1);
    p->addVertice(1,8);
    p->addVertice(1,2);
    p->addVertice(2,3);
    p->addVertice(2,7);
    p->addVertice(2,4);
    p->addVertice(3,2);
    p->addVertice(3,9);
    p->addVertice(4,3);
    p->addVertice(4,5);
    p->addVertice(5,4);
    p->addVertice(5,10);
    p->addVertice(7,3);
    p->addVertice(7,7);
    p->addVertice(8,7);
    p->addVertice(9,6);
    p->addVertice(10,10);
    p->addVertice(2,2);
    p->addVertice(8,8);
    p->addVertice(1,9);

    p->display();

	p->BFS(1);

    p->shortestPath(2,2);

    
    return 0;
}
