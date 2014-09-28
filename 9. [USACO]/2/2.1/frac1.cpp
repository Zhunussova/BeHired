/*
	ID:   zhazira171
	PROG: frac1
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

int nod(int a,int b){
	while((a>0)&&(b>0))
		if(a>b) a%=b;
		else b%=a;

	return a+b;
}

vector<pair<double, pair<int,int> > > a;
int i,j,n;

int main(){  
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);

	cin>>n;

	cout<<"0/1\n";

	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(nod(i,j) == 1) a.pb(mp(1.0*i/j, mp(i,j)));

	Sort(a);

	for(i=0;i<a.size();i++) cout<<a[i].s.f<<"/"<<a[i].s.s<<"\n";

	return 0;
}         	