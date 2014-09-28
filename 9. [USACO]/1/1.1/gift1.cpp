/*
	ID:   zhazira171
	PROG: gift1
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
#define se

#define inf 1000000000
#define linf 1000000000000ll
#define eps (1e-7)

#define Fill(a,x) memset(a,x,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define Sort(c) sort(all(c))
#define Rev(c) reverse(all(c))

int n,i,in[11],j,fin[11],giv,k;
string s[11],t;
map<string,int> m;

int main(){  	
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i];
		m[s[i]] = i;
	}

    for(i=0;i<n;i++){
    	cin>>t;
    	j = m[t];
    	cin>>in[j]>>k;
    	
    	fin[j] += in[j];

    	if(k){
        	giv = in[j]/k;
        	fin[j] -= giv*k;

        	while(k){
        		cin>>t;
        		fin[m[t]]+=giv;
        		k--;
        	}
    	}
	}	

	for(i=0;i<n;i++){
		cout<<s[i]<<" "<<fin[i]-in[i]<<"\n";
	}

	return 0;
}