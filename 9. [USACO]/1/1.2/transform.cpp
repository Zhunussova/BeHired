/*
	ID:   zhazira171
	PROG: transform
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

char a[11][11],c[11][11],f[11][11],b[11][11];
int n;

void rot(){
	int i,j;

	for(i=0;i<n;++i){
	    for(j=0;j<n;j++)
	    	c[i][j] = b[j][n-i-1];
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++) b[i][j]=c[i][j];
}

bool ch() {
	int i,j;

	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    	if(b[i][j]!=f[i][j]) return 0;

	return 1;
}

bool func(){
	rot();
	return ch();
}

void ref(){
	int i,j;

    for(i=0;i<n;i++)
    	for(j=0;j<n/2;j++)	swap(b[i][j],b[i][n-j-1]);
}

int main(){  
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	
	int i,j;

	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>f[i][j];

	for(i=1;i<4;i++)
		if(func()){
			cout<<i<<"\n";
			return 0;
		}

	rot();
	ref();

	if(ch()) {
		cout<<4<<"\n";
		return 0;
	}

	for(i=0;i<3;i++)
		if(func()){
			cout<<5<<"\n";
			return 0;
		}

	for(i=0;i<n;i++) 
		for(j=0;j<n;j++)
			b[i][j]=a[i][j];

	if(ch()){
		cout<<6<<"\n";
		return 0;
	}

	cout<<7<<"\n";

	return 0;
}