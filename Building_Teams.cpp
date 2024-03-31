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
#define pb          push_back
#define eb          emplace_back
#define pf          push_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define vvi         vector<vector<int>> 
#define mii         map<int, int>
#define si          set<int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
// #define x           first
// #define y           second
/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return mod_add(arr[0],0, b);} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} //only for prime m
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*--------------------------------------------------------------------------------------------------------------------------*/
int ncr(int n, int r) {if(r > n - r) r = n - r;int ans = 1;int i;for(i = 1; i <= r; i++) {ans *= n - r + i;ans /= i;}return ans;}
int fact[1000005];
void count_fact(){int i,x=1;fact[0]=1;for(int i=1;i<1000005;i++){x=mod_mul(x,i,M);fact[i]=x;}}

const int MAXN=100002;
vector<bool> ans(MAXN),vis(MAXN,false);
vector<int> v[MAXN];
bool POSSIBLE;

void dfs(int vertex,int parent=0)
{
    for(auto child : v[vertex])
    {
        if(vertex!=parent)
        {
            if(!vis[child])
            {
                ans[child] = !ans[vertex];
                vis[child] = true;
                dfs(child,vertex);
            }
            else
            {
                if(ans[child]==ans[vertex])
                {
                    POSSIBLE=false;
                }
            }
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    POSSIBLE=true;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            dfs(i);
        }
    }
    if(!POSSIBLE)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<(ans[i]?2:1)<<" ";
        }
    }
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