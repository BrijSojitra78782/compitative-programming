// Radhe Radhe
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//-------------------------------------------
using namespace std;

vector<int> dp(100005,-1);

int func(vector<int> v,int n)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int cost=INT_MAX;
    cost = min(cost,func(v,n-1)+abs(v[n]-v[n-1]));
    if(n>1) cost = min(cost,func(v,n-2)+abs(v[n]-v[n-2]));
    return dp[n]=cost;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<func(v,n-1);
}

int32_t main() {

    int t = 1;

    for(int i = 1; i <= t; i++)
    {
        solve();
    }

}