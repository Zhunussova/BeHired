/*
	ID:   zhazira171
	PROG: ariprog
	LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

const int mod = int(1e9+7);
const double PI = acos(-1.0);

#define ones(x) (__builtin_popcount(x))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sqr(x) ((x)*(x))

#define len length
#define sz size
#define mp make_pair
#define pb push_back
#define f first
#define s second

#define inf 1000000000
#define linf 1000000000000ll
#define eps (1e-7)

#define Fill(a,x) memset(a,x,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define Sort(c) sort(all(c))
#define Rev(c) reverse(all(c))

const int maxN = 125000;

int n,a[32000];
short prime[maxN+10];
int ok = 0;
vpi ans;

bool check(int st, int dif){
	int i = 1;

	while(i < n){
		i++;

		st += dif;
		if((st>maxN) || (prime[st]==0))  return 0;
    }

    ok ++;

    return 1;
}

int main(){  
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);

	int m,i,j,sz=0;

	cin>>n>>m;

	for(i=0;i<=m;i++)
		for(j=i;j<=m;j++){
			a[sz] = sqr(i)+sqr(j);
			if(!prime[a[sz]]){
				prime[a[sz]] = 1;
				sz++;
			}
		}

	sort(a,a+sz);

	for(i=0;i<=sz-n;i++)
		for(j=i+1;j<sz;j++)
			if(a[i]!=a[j])
				if(check(a[i],a[j]-a[i])) ans.pb(mp(a[j]-a[i],a[i]));	
				
	Sort(ans);

	if(ans.size()==0) cout<<"NONE\n";
	else
		for(i=0;i<ans.sz();i++) cout<<ans[i].s<<" "<<ans[i].f<<"\n";

	return 0;
}