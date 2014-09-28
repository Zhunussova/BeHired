/*
	ID:   zhazira171
	PROG: barn1
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

int m,s,c,ans,a[210],i,b[210];


int main(){  
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	cin>>m>>s>>c;
	for(i = 0; i < c; i++) cin>>a[i];

	sort(a, a+c);

	ans = c;
	s = 0;
	for(i=1;i<c;i++)
		if(a[i]-a[i-1]>1) b[s++] = a[i]-a[i-1]-1;

	sort(b,b+s);

	c = s+1;

	i=0;
    while(c > m){
    	c--;
    	ans += b[i++];
   	} 

   	cout<<ans<<endl;

	return 0;
}