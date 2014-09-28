/*
	ID:   zhazira171
	PROG: crypt1
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

int ans = 0;
int p[6],num[11],par1[5],par2[5];	

void rec(int v){
	int i;	

	if(v==5){
		int c1 = 0, c2 = 0;
        for(i=0;i<3;i++){
        	par1[i] = p[i]*p[4]+c1;
        	par2[i] = p[i]*p[3]+c2;

        	c1 = par1[i]/10;
        	c2 = par2[i]/10;

        	par1[i]%=10;
        	par2[i]%=10;

        	if((!num[par1[i]])||(!num[par2[i]])) break;
        }		

        swap(par1[0],par1[2]);
        swap(par2[0],par2[2]);

        if((i==3)&&(c1==0)&&(c2==0)){
        	par1[3] = par1[2];
        	par1[2] = par1[1]+par2[2];

        	par1[1] = par1[0]+par2[1]+par1[2]/10;
        	par1[2] %= 10;

        	par1[0] = par2[0] + par1[1]/10;

        	par1[1] %=10;

        	for(i=0;i<4;i++)
	        	if((par1[i]>9) || (!num[par1[i]])) break;

	        if(i==4) ans++;
        }
	}
	else
		for(i = 1;i <10;i++)
			if(num[i]){
				p[v] = i;
				rec(v+1);
			}
}

int main(){  
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);

	int n,i,a;

	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		num[a] = 1;
	}

	rec(0);

	cout<<ans<<"\n";
	
	return 0;
}