/*
	ID:   zhazira171
	PROG: ride
	LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>   
#include <cmath>
#include <queue>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int>  pi;
typedef vector<int>    vi;
typedef vector<pi>	   vpi;
typedef vector<vi>	   vvi;
typedef queue<pi> qpi;

const int mod = int(1e9 + 7);
const double PI = acos(-1.0);

#define ones(x) (__builtin_popcount(x))
#define abs(x) ((x) > 0 ? (x) : -(x))
#define sqr(x) ((x)*(x))

#define len length
#define sz size
#define pb push_back
#define mp make_pair
#define s second
#define f first

#define inf 1000000000
#define linf 100000000000ll
#define eps (1e-7)

#define all(c) (c).begin(), (c).end()
#define Sort(c) sort(all(c))
#define Rev(c) reverse(all(c))

string s,t;
int tt,ss,i;

int main ()
{
	freopen ("ride.in", "r", stdin);
	freopen ("ride.out", "w", stdout);

	cin>>s>>t;
	 
	ss = 1;
    for(i=0;i<s.len();i++) ss = ss*((int)s[i]-64)%47;

	tt = 1;
    for(i=0;i<t.len();i++) tt = tt*((int)t[i]-64)%47;

    if(ss==tt) cout<<"GO\n";
    else cout<<"STAY\n";

	return 0;
}
