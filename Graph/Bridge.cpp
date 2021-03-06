#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define MOD             1000000007
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);

#define LL              long long
#define ULL              unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define TC              int t;cin >> t;FOR(tc,1,t)
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)


#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

const int N=1000000;

vector<int>V[N+5];
bool vis[N+5];
int discover[N+5];
int low[N+5];
int pr[N+5];
vector<pii>br;

void dfs(int u)
{
    static int time = 0;
    vis[u] = 1;
    discover[u] = low[u] = ++time;

    for(int v : V[u]){
        if(!vis[v]){
            pr[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(low[v]>discover[u]){
                br.push_back({u,v});
            }
        }
        else if(pr[u]!=v){
            low[u] = min(low[u],discover[v]);
        }
    }
}

int main()
{
    MEM(pr,-1);
    FastRead
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].pb(v);
        V[v].pb(u);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    for(int i = 0;i<br.size();i++){
        cout << br[i].ff << " " << br[i].ss << endl;
    }
}
