/*
	ID:   bigarch1
	PROG: sprime
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

int d[4] = {1,3,7,9},n,k=0;

bool prime(int x){
	for(int i = 2;i*i<=x;i++)
		if(x%i==0) return 0;

	return 1;
}

void f(int v,int s){
	if(v==n) {
		cout<<s<<"\n";
		k++;
	}
	else{
		for(int i=0;i<4;i++){
            int t = s*10+d[i];

			if(prime(t)) f(v+1,t);	
		}
	}
}

int main(){  
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);

	cin>>n;

	f(1,2);
	f(1,3);
	f(1,5);
	f(1,7);

	if(!k) cout<<"\n";

	return 0;
}