/*
	ID:   zhazira171
	PROG: milk2
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

int d1,d2,i,l,s,st1,st2,n;
vpi a;

int main(){  
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);

	cin>>n;
	for(i=0;i<n;++i){
        cin>>s>>l;

		a.pb(mp(s,1));
		a.pb(mp(l,2));	
	}

	Sort(a);

	s=0;
	st1 = st2 = a[0].fi;
	for(i=0;i<2*n;i++){
		if(s==0) d2 = max(d2,a[i].fi-st2);

		if(a[i].se==1) s++;
		else s--;

        if(s==0){
        	st2 = a[i].fi;
        	d1 = max(d1, a[i].fi-st1);

        	if(i+1<2*n) st1 = a[i+1].fi;
        }			
	}

	cout<<d1<<" "<<d2<<endl;

	return 0;
}