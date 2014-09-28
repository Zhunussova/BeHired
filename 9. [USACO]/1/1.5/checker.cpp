/*
	ID:   bigarch1
	PROG: checker
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

int ans,us[15],n,p[15];
int aa[30],bb[30],a[15][15],b[15][15];

void f(int v){
	if(v>n){
		ans ++;
		if(ans<4){
			cout<<p[1];
			for(int i=2;i<=n;i++)
				cout<<" "<<p[i];
			cout<<endl;
		}
	}
	else{	
		for(int i=1;i<=n;i++)
			if((!us[i])&&(!aa[a[v][i]])&&(!bb[b[v][i]])){
				
				aa[a[v][i]]=bb[b[v][i]] = us[i] = 1;
				
				p[v] = i;
				f(v+1);

				aa[a[v][i]]=bb[b[v][i]] = us[i] = 0;
		}
	}
}

void paint(int x,int y,int k){
	while((x<=n)&&(y<=n)){
		a[x][y] = k;
		x++;
		y++;
	}	
}

void paint2(int x,int y,int k){
	while((x<=n)&&(y>0)){
		b[x][y] = k;
		x++;
		y--;
	}	
}

int main(){  
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);

	cin>>n;

	for(int i=1;i<=n;i++) paint(1,i,i);
	for(int i=2;i<=n;i++) paint(i,1,i+n);

	for(int i=1;i<=n;i++) paint2(1,i,i);
	for(int i=2;i<=n;i++) paint2(i,n,i+n);

	f(1);

	cout<<ans<<"\n";

	return 0;
}