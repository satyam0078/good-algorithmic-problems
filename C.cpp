    #include<bits/stdc++.h>
    #include<string>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll,ll > pii;
    typedef pair<long,pii > piii;
    typedef vector<long long >   VI;
    #define sc1(x) scanf("%lld",&x);
    #define sc2(x,y) scanf("%lld%lld",&x,&y);
    #define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
    #define pb push_back
    #define mp make_pair
    #define ini(x,val) memset(x,val,sizeof(x));
    #define fs first
    #define sc second
    #define MOD 1000000007
    #define inf 999999999999999ll	//long long inf
    #define PI 3.1415926535897932384626

    #define gcd __gcd
    #define tr(contaner, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
    #define PrintCont(cont) {cout<<("\n----------------\n");\
    for(typeof(cont.begin()) it = cont.begin();it!=cont.end();++it) cout<<*it<<" ";cout<<("\n----------------\n");}
    #define all(v) v.begin(),v.end()
    #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

    #define debug(x) cout<<#x<<" :: "<<x<<"\n";
    #define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
    #define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";

    int main()
    {
       // freopen("input.txt","r",stdin);
       // freopen("out.txt","w",stdout);
        ll t,cas=0;
        cin>>t;

        while(t--)
        {
            cas++;
            ll n,ans1=-inf,a[3010];
            bool vis[3010];
            cin>>n;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;i++)
            {
                ll j=i;
                ini(vis,false);
                vis[i]=true;
               ll  k=0;
                while(1)
                {
                    j=a[j];
                    k++;
                    if(vis[j]==true)
                    {
                        break;
                    }
                    vis[j]=true;
                }
                if(j==i)
                {
                    ans1=max(ans1,k);
                }
            }
            //debug(ans1);
            //sec partB
            ini(vis,false);
            ll d[3010];
            ini(d,0);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(a[a[j]]!=j)
                    {
                        d[a[j]]=max(d[a[j]],d[j]+1);
                    }
                }
            }
            ini(vis,false);
            ll ans2=0;
            for(int i=1;i<=n;i++)
            {
                if(a[a[i]]==i&&vis[i]==false)
                {
                    ans2+=(2+d[i]+d[a[i]]);
                    vis[i]=true;
                    vis[a[i]]=true;
                }
            }
            cout<<"Case #"<<cas<<": "<<max(ans1,ans2)<<endl;
        }
        return 0;
    }
