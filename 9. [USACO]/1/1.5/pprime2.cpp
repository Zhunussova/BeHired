/*
	ID:   zhazira171
	PROG: pprime
	LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <cstring>
#include <sstream>
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

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define inf 1000000000
#define linf 1000000000000ll
#define eps (1e-7)

bool isPrime(int x){
	for(int i = 2;i*i<=x;i++) if(x%i==0)  return 0;

	return 1;
}

int toNum(string s){
	int t = 0;

	for(int i = 0;i<s.length();i++) t = t*10+(int)s[i]-48;

	return t;
}

vector<string> a[9];
string num[10] = {"0","1","2","3","4","5","6","7","8","9"};
int i,j,s,t;

int main(){  
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);

	a[0].pb("");

	for(i=0;i<10;i++) a[1].pb(num[i]);


	for(i=2;i<9;i++)
		for(s = 0;s<10;s++)
			for(j=0;j<a[i-2].size();j++) a[i].pb(num[s]+a[i-2][j]+num[s]);

	cin>>s>>t;
	for(i=1;i<9;i++)
		for(j=0;j<a[i].size();j++)
			if(a[i][j][0]!='0'){
				int cur = toNum(a[i][j]);
			
				if((s<=cur)&&(cur<=t))
					if(isPrime(cur)){
						a[0][0] = "@";
						cout<<cur<<"\n";
					}

				if(cur>t) return 0;
			}

	 if(a[0][0]=="") cout<<"\n";
			
	return 0;
}