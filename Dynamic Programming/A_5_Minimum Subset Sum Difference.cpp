/*


Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11        


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
#define input(ppp,size)   loop(i,0,n) cin>>ppp[i];



int solution_dp(int *arr, int summ, int n) //dynamic programming
{
    
    int dp[n+1][summ+1];
    loop(i,1,summ+1)   dp[0][i]=0;
    loop(i,0,n+1)   dp[i][0]=1;

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
    for(int i=(summ+1)/2;i>=0;++i) 
    //middle summ might be the lowest
    //finding for dp[n] i.e. n elements 
    //having a sum near to summ/2 true
    //it would be minimum
    {
        if(dp[n][i])
            return abs(summ-2*i);
    }
}

int main() 
{ 
    //fast_input;
    size_t n;
    cin>>n;
    int *arr = new int [n];
    input(arr,n);
    int summ = accumulate(arr,arr+n,0);
    cout<<solution_dp(arr, summ, n)<<nl;
    return 0;
}
