/*
	ID:   zhazira171
	PROG: packrec
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

int ans = inf;
set<pi> st;

void check(int x,int y){

	int s = x*y;

	if(s>ans) return;

	if(x>y) swap(x,y);

	if(s<ans){
		ans = s;
		st.clear();
	}

	st.insert(mp(x,y));
}

pi a[5],b[5];
int p[5];

void solve(int x){
	
	int i;

	for(i=0;i<4;i++) b[i] = a[p[i]];

	for(i=0;i<4;i++)	
		if((x&(1<<i)) != 0) swap(b[i].f,b[i].s);

	//first

	x = 0;
	int y = 0;
	for(i=0;i<4;i++){
		x = max(x, b[i].f);
		y += b[i].s;
	}

	check(x,y);

    //second

    x = y = 0;
    for(i=0;i<3;i++){
    	x = max(x,b[i].f);
    	y += b[i].s;
    }

    x += b[3].f;
    y = max(y,b[3].s);

    check(x,y);


    //third

    x = y = 0;
    
    for(i=0;i<2;i++){
    	x  = max(b[i].f,x);
    	y += b[i].s;
    }

    x +=  b[3].f;
    x = max(x, b[2].f);

    y = max(y, b[3].s);
    y += b[2].s;

    check(x,y);

    //forth

    x = max(b[0].f, max( b[3].f, b[1].f+b[2].f));
    y = b[0].s+b[3].s + max(b[1].s,b[2].s); 

    check(x,y);

    //fifth

    x = max(b[0].f+b[1].f, max(b[2].f,b[3].f));
    y = max(b[0].s,b[1].s) + b[2].s+ b[3].s;

    check(x,y);

    //six

    x = max(b[0].f+b[1].f, b[2].f+b[3].f);

    if(b[1].f>=b[2].f+b[3].f) y = max(b[0].s,max(b[2].s,b[3].s)+b[1].s);
    else
    	if(b[1].f == b[3].f) y = max(b[1].s+b[3].s,b[0].s+b[2].s);
    	else
    	if(b[1].f>b[3].f) y = max(b[0].s+b[2].s,max(b[2].s,b[3].s)+b[1].s);
    	else
    		if(b[3].f<b[0].f+b[1].f) y = max(b[0].s+b[2].s,max(b[1].s,b[0].s)+b[3].s);
    		else y = max(max(b[0].s,b[1].s)+b[3].s,b[2].s); 

    check(x,y);

}

vpi rez;

bool add(pi d){

	for(int i=0;i<rez.size();i++)
		if(d!=rez[i])
			if(d.f>=rez[i].f){
				if(d.s>=rez[i].s) return 1;
			}
			else break;

	return 0;

}

int main(){  
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);

	int i;

	for(i=0;i<4;i++){
		p[i] = i;

		cin>>a[i].f>>a[i].s;
	}

	do{
		for(i=0;i<16;i++) solve(i);
	}
	while(next_permutation(p,p+4));

	cout<<ans<<endl;
	while(!st.empty()){
		rez.pb(*(st.begin()));
		st.erase(st.begin());
	}

	for(i=1;i*i<=ans;i++)
		if(ans%i==0) if(add(mp(i,ans/i))) rez.pb(mp(i,ans/i));

	for(i=0;i<rez.size();i++)
		cout<<rez[i].f<< " "<<rez[i].s<<"\n";

	return 0;
}