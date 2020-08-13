/*


0-1 Knapsack Problem
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).


*/

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0); cin.tie(NULL);
#define loop(i,a,b) for(int i=a;i<b;++i)
#define inf (__builtin_inf())
#define ll long long
#define ul unsigned long
#define ull unsigned long long
#define mod (1e9+7)

#define pairr pair<int,int>
#define all(v) (v).begin(),(v).end() 

#define test(t) uint t; cin>>t; while(t--)
#define print(f,size,x) loop(ppp,0,size) cout<<f[ppp]<<x;
#define print_all(f,x) for(const auto &ppp: f)  cout<<ppp<<x;

int solution(int *w, int *v,int c, int n) //recursive
{
    if(n<1) return 0;
    if(w[n-1]<=c)
    {
        return max(v[n-1]+solution(w, v, c-w[n-1], n-1),solution(w, v, c, n-1));
    }
    else
    {
        return solution(w, v, c, n-1);
    }
}

int solution_dp(int *w, int *v,int c, int n) //dynamic programming
{
    
    int dp[n+1][c+1];
    loop(i,0,c+1)   dp[0][i]=0;
    loop(i,0,n+1)   dp[i][0]=0;

    loop(i,1,n+1)
    {
        loop(j,1,c+1)
        {
            if(w[i-1] <= c)
            {
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][c];
}

int main() 
{ 
    //fast_input;
    size_t n;
    cin>>n;
    int *weights = new int [n];
    int *values = new int [n];
    int capacity;
    cin>>capacity;
    loop(i,0,n) cin>>weights[i];
    loop(i,0,n) cin>>values[i];
    cout<<solution(weights, values, capacity, n);
    return 0;
} 
