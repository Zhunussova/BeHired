/*
	ID:   bigarch1
	PROG: numtri
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

int n,j,i,a[1001][1001],b[1001][1001];

int main(){  
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)  
			cin>>a[i][j];

	b[0][0] = a[0][0];
	for(i=0;i<n-1;i++){
		for(j=0;j<=i;j++){
			b[i+1][j] = max(b[i+1][j],a[i+1][j]+b[i][j]);
            b[i+1][j+1] = max(b[i+1][j+1],a[i+1][j+1]+b[i][j]);		
		}
	}

	j = b[n-1][0];
	for(i=1;i<n;i++)
		j = max(b[n-1][i],j);

	cout<<j<<"\n";

	return 0;
}