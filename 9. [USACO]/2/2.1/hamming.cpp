/*
	ID:   zhazira171
	PROG: hamming
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

#define bit(x,i) (x & (1<<i))

int d,n,b;
vector<int> ans;

bool check(int x,int y){
	int c = 0,i;

	for(i = 0;i<b;i++) if(bit(x,i) != bit(y,i)) c++;

	return (c>=d);
}

void f(int x){
	int i;

	if(ans.size() == n){
      	cout<<ans[i];
       	for(i=1;i<ans.size();i++){
       	    if(i%10==0) cout<<"\n";
       	    else cout<<" ";
       		
       		cout<<ans[i];
 		}	

 		return;
	}
	else{
		for(i=0;i<ans.size();i++) 
			if(!check(ans[i], x)) break;

		if(i==ans.size())	ans.pb(x);

		f(x+1);
	}
}

int main(){  
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);

	cin>>n>>b>>d;

	f(0);

	cout<<"\n";

	return 0;
}