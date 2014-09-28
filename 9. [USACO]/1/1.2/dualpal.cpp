/*
	ID:   zhazira171
	PROG: dualpal
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

bool isPal(int num, int base){
	string s="",t;

	while(num>0){
		s += (char)(num%base+48);
		num /= base;	
	}

	t = s;
	Rev(s);

	return (t==s) ? 1 : 0;
}

int main(){  
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);

	int n,s;

	cin>>n>>s;


	while(n){
		++s;

		int k=0;
        for(int i=2;i<=10;i++)
        	if(isPal(s,i)) k++;

        if(k>1){
        	cout<<s<<"\n";
        	n--;
        }
	}

	return 0;
}