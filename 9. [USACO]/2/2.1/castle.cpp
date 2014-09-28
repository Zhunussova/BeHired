/*
	ID:   zhazira171
	PROG: castle
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

int a[60][60], b[60][60], c[300], sz;
int di[4] = {0,-1,0,1}, dj[4] = {-1,0,1,0};

int dfs(int i,int j,int x, int k){
	b[i][j] = k;
	int ans = 1;

	for(int z=0;z<4;z++)
		if((x&(1<<z))==0){
			int ii = i+di[z], jj = j+dj[z];

			if(!b[ii][jj]) ans += dfs(ii, jj, a[ii][jj], k);
		}

	return ans;
}

int ans, ii, jj, i, j;
char ch, cur;

void upd(){
	ch = cur;
	ii = i;
	jj = j;
	ans = sz;
}

void check(){
	if(sz != ans){
		if(sz > ans) upd();
		return;
	}

	if(j != jj){
		if(j < jj) upd();
        return;
	}

	if(i != ii){
		if(i > ii)  upd();
		return;
	}

	if(cur == 'N') upd();
}

int main(){  
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);

	int n,m;

	cin>>m>>n;
    for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
    		cin>>a[i][j];

    for(i=0;i<n;i++)
    	for(j=0;j<m;j++)
    		if(!b[i][j]){
    			sz ++;
    			c[sz] = dfs(i, j, a[i][j], sz);

    			ans = max(ans, c[sz]);
    		}

    cout<<sz<<"\n"<<ans<<"\n";

    for(i=0;i<n;i++)
    	for(j=0;j<m;j++){
    		if(i && (a[i][j]&2) && b[i-1][j] != b[i][j]){
    			sz = c[b[i-1][j]] + c[b[i][j]];
    			cur = 'N';
    			check();
    		}	
    		else
    			if((j < m-1) && (a[i][j]&4) && (b[i][j+1] != b[i][j])){
    				sz = c[b[i][j+1]] + c[b[i][j]];
    				cur = 'E';
    				check();
    			}
    	}

    cout<<ans<<"\n"<<ii+1<<" "<<jj+1<<" "<<ch<<"\n";

	return 0;
}