/*
	ID:   zhazira171
	PROG: holstein
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

vector<int> cur,ans;
int n,ca[30];

//int t=0;

void print(){
//	cout<<++t<<endl;
	int i;
	for(i=0;i<cur.size();i++) cout<<cur[i]<<" ";
	cout<<endl;
	for(i=0;i<n;i++) cout<<ca[i]<<" ";
	cout<<endl;
	for(i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	cout<<endl<<"---------------------------------------------------------\n";
	cout<<endl;
}

void eq(){
	int i;

	//print();

	for(i=0;i<cur.size();i++) ans[i] = cur[i];

	while(ans.size()!=i) ans.pop_back();
}

void check(){
	Sort(cur);

	if(cur.size() < ans.size()){
		eq();
		return;
	}

	for(int i=0;i<cur.size();i++) 
		if(cur[i] > ans[i]) return;
		else
			if(cur[i] < ans[i]){
				eq();
				return;
			}
}

int v[30], a[16][30], k;

void f(int i){
	
	if(cur.size() > ans.size()) return;

	int j;

	for(j = 0;j<n;j++)
		if(ca[j] < v[j]) break;

	if(j==n){
		check();
		return;
	}

	if(i==k) return;

    f(i+1);

    for(j=0;j<n;j++)  	ca[j] += a[i][j];
    cur.pb(i);

    f(i+1);

    cur.pop_back();
    for(j=0;j<n;j++)  	ca[j] -= a[i][j];
}

int main(){  
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);

	int i,j;

	cin>>n;
	for(i=0;i<n;i++) cin>>v[i];

	cin>>k;
	for(i=0;i<k;i++){
		for(j=0;j<n;j++) cin>>a[i][j];
		ans.pb(i);
	}

	f(0);

	cout<<ans.size();
	for(i=0;i<ans.size();i++) cout<<" "<<ans[i]+1;
	cout<<"\n";
    
	return 0;
}