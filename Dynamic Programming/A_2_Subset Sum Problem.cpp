/*


Subset Sum Problem
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.


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

int solution(int *arr, int summ, int n) //recursive
{
    if(summ==0) return true;
    if(n==0) return false;
    if(arr[n-1] <= summ)
    {
        return solution(arr, summ-arr[n-1], n-1) || solution(arr, summ, n-1);
    }
    else
    {
        return solution(arr, summ, n-1);
    }
}

int solution_dp(int *arr, int summ, int n) //dynamic programming
{
    
    int dp[n+1][summ+1];
    loop(i,1,summ+1)   dp[0][i]=false;
    loop(i,0,n+1)   dp[i][0]=true;

    loop(i,1,n+1)
    {
        loop(j,1,summ+1)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][summ];
}

int main() 
{ 
    //fast_input;
    size_t n;
    cin>>n;
    int *arr = new int [n];
    int summ;
    loop(i,0,n) cin>>arr[i];
    cin>>summ;
    cout<<solution_dp(arr, summ, n);
    return 0;
}
