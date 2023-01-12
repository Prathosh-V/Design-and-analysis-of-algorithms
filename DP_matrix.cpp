#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void files()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
void solve()
{
    string a,b,s1="",s2="";
    cin>>a>>b;
    ll x,y,max=0,c=1;
    ll m=a.length();
    ll n=b.length();
    ll match=2;
    ll mis_match=-1;
    ll arr[m+1][n+1]={};
    vector<pair<ll,ll>> tb;
    for(ll i=1;i<=m;++i)
    {
        for(ll j=1;j<=n;++j)
        {
            if(a[i-1]==b[j-1]) arr[i][j]=arr[i-1][j-1]+match;
            else
            {
                if(arr[i-1][j-1]>arr[i-1][j] && arr[i-1][j-1]>arr[i][j-1])
                    arr[i][j]=arr[i-1][j-1]+mis_match;
                else if(arr[i-1][j]>arr[i][j-1])
                    arr[i][j]=arr[i-1][j]+mis_match;
                else
                    arr[i][j]=arr[i][j-1]+mis_match;
            }
        }
    }
    for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;++j) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<=n;i++) 
    {
        if(arr[m][i]>=max) 
        {
            x=m;
            y=i;
        }
    }
    tb.push_back(make_pair(x-1,y-1));
    while(1)
    {
        if(arr[x-1][y-1]>=arr[x-1][y] && arr[x-1][y-1]>=arr[x][y-1])
        {
            --x; --y;
        }
        else if(arr[x-1][y]>=arr[x][y-1])
        {
            --x; 
        }
        else --y;
        if(x==0 || y==0) break;
        tb.push_back(make_pair(x-1,y-1));
        ++c;
    }
    for(int i=c-1;i>=0;i--)
    {
        cout<<endl<<tb[i].first<<" "<<tb[i].second;
        if(a[tb[i].first]==b[tb[i].second]) 
        {
            s1+=a[tb[i].first]; s2+=b[tb[i].second];
        }
        else
        {
            if(tb[i].second!=tb[i+1].second) 
            {
                s1+=b[tb[i].second];
                s2+="_";
            }
            else
            {
                s2+=a[tb[i].first];
                s1+="_";
            }
        }
    } 
    cout<<endl<<s1<<" "<<s2;
}
int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
    files();
	solve();
	return 0;
}