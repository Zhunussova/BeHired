/*
	ID:   zhazira171
	PROG: clocks
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

short  d[10][9] = {

	{0}, //0
	{1,2,4,5,0},
	{1,2,3,0},
	{2,3,5,6,0},
	{1,4,7,0},
	{2,4,5,6,8,0},
	{3,6,9,0},
	{4,5,7,8,0},
	{7,8,9,0},
	{5,6,8,9,0},
};

string initial="", good = "000000000";

string check(string s){
	string   t = initial;

    for(int i=0;i<s.length();i++){
    	int n = (int)s[i]-48;

     	while(n){
    		for(int j=0;d[i+1][j];j++)
    			t[d[i+1][j]-1] = (char)(((int)(t[d[i+1][j]-1])-48 + 1)%4+48);

     		n--;	
    	}	
    }

    return t;
}

void f(int v,string s){
	int i,n;

	if(v==9){
		if(check(s)==good){
			v = 0;
			for(i=0;i<s.length();i++){
				n = (int)s[i]-48;

				while(n){
					if(v) cout<<" ";
					cout<<i+1;
					v++;
					n--;
				}
			}

			return;
		}
	}
	else{
		f(v+1,s+"0");
		f(v+1,s+"1");
		f(v+1,s+"2");
		f(v+1,s+"3");
	}
}

int main(){  
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);

	int i,n,j;

	for(i=0;i<9;i++){
		cin>>n;

		n = (n/3)%4;
		initial += (char)(n+48);
	}

	f(0,"");

	cout<<"\n";

	return 0;
}