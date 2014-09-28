/*
	ID:   zhazira171
	PROG: milk
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
#define fi first
#define se second

#define inf 1000000000
#define linf 1000000000000ll
#define eps (1e-7)

#define Fill(a,x) memset(a,x,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define Sort(c) sort(all(c))
#define Rev(c) reverse(all(c))

int n,m,ans;
pi a[5010];

int main(){  
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);

	cin>>n>>m;

	for(int i=0;i<m;i++) 
		cin>>a[i].fi>>a[i].se;

	sort(a,a+m);

    for(int i=0;i<m;i++){
    	if(n>=a[i].se){
    		n -= a[i].se;
    		ans += a[i].se*a[i].fi;	
    	}
    	else{
            ans += a[i].fi*n;
            n = 0;
    	}

    	if(!n) break;
    }

    cout<<ans<<endl;

	return 0;
}