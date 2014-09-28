/*
	ID:   zhazira171
	PROG: beads
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

int n,i,r,b;
string s;
vpi v;

int main(){  
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);

	cin>>n>>s;

	for(i=0;i<n;i++)
		if(s[i]=='r') r++;
		else 
			if(s[i]=='b') b++;

	if(b && r){
		i=0;
		while(s[i]=='w') i++;

		r = n-1;

		if(s[i]=='b'){
			while(s[r]!='r') r--;
		}
		else{
			while(s[r]!='b') r--;
		}

		string t = s.substr(r+1);
		reverse(t.begin(),t.end());
		s = t+s.substr(0,r+1);

		b = n-1;
		r = n-1;
		for(i=n-2;i>=0;i--)
			if(s[i]!='w'){
				if(s[i]!=s[r]){
					v.pb(mp(b,r));
                    r = i;
				}

				b=i;
			}

	   v.pb(mp(b,r));
	   Rev(v);

	   if(v.sz()==2){
	   		cout<<n<<endl;
	   		return 0;
	   }

	   n = v.sz()-1;

	   r = max(v[0].se+1+v[n].se-v[n].fi+v[n].fi-v[n-1].se,max(v[2].fi,v[0].fi+v[n].se-v[n-2].se));

	   if(v.sz()==3){
	   		cout<<r<<endl;
	   		return 0;
	   }

	   r = max(r,v[n].fi-1-v[n-3].se);
	   for(i=1;i<n-1;i++) r = max(r,v[i+2].fi-v[i-1].se-1);

	   cout<<r;
	} 
	else cout<<n;

	cout<<"\n";

	return 0;
}