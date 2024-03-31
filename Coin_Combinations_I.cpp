// Radhe Radhe
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//-------------------------------------------
using namespace std;
using namespace __gnu_pbds;
//-------------------------------------------
typedef long long int ll;
#define int long long
#define double long double
#define fastio() ios_base: :sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PI 3.141592653589793238462
const int M = 1e9+7;
//-------------------------------------------
int mod_add(int a, int b, int m) {return (a + b) % m;}
vector<int> dp(1000001,0);

void solve()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-v[j]>=0)
            {
                dp[i]=mod_add(dp[i],dp[i-v[j]],M); // getting TLE in this for 4 testcases
                // dp[i]+=dp[i-v[j]]; // not getting TLE
                // dp[i]%=M; // not getting TLE
            }
        }
    }
    cout<<dp[x]<<endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("error.in","w", stderr);
    auto start = std::chrono::high_resolution_clock::now();
#endif
    //fastio();
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++)
    {
        solve();
    }


#ifndef ONLINE_JUDGE
    auto stop = std::chrono::high_resolution_clock::now(); 
    double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;
#endif
}