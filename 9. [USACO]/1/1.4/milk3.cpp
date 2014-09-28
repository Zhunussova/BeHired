/*
	ID:   zhazira171
	PROG: milk3
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

int num(int x,int y,int z){
	return 10000*x+100*y+z;
}

int a,b,c;
map<int,bool> m;
set<int> st;

void func(int x,int y,int z){
	int k = num(x,y,z);	

	if(m[k]) return;

	m[k] = 1;

	if(x>0){
		k = min(b-y,x);
    	if(y<b) func(x-k,y+k,z);

    	k = min(c-z,x);
    	if(z<c) func(x-k,y,z+k);
    }
    if(y>0){
    	k = min(a-x,y);
    	if(x<a) func(x+k,y-k,z);

    	k = min(c-z,y);
    	if(z<c) func(x,y-k,z+k);
    }
    if(z>0){
    	k = min(a-x,z);
    	if(x<a) func(x+k,y,z-k);

		k = min(b-y,z);                          
    	if(y<b) func(x,y+k,z-k);
    }

    if(x == 0) st.insert(z);
}

int main(){  
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);

	cin>>a>>b>>c;

	func(0,0,c);

	a = 0;
	while(!st.empty()){
		if(a) cout<<" ";
		cout<<*st.begin();
		st.erase(st.begin());
		a++;
	}

	cout<<"\n";

	return 0;
}