/*
	ID:   zhazira171
	PROG: palsquare
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

int n;

char toChar(int x){
	return ((x<10) ? (char)(x+48) : (char)(x+55));
}

string toBase(int x){
	
	string ans="";
	
	while(x>0){
		ans += toChar(x%n);
		x /= n;		
	}

	return ans;
}

int main(){  
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);

	cin>>n;

	for(int i=1;i<=300;i++){
		string n1 = toBase(i), n2 = toBase(i*i), t = n2;
		Rev(t);
		Rev(n1);

		if(n2 == t) cout<<n1<<" "<<t<<endl;
	}

	return 0;
}