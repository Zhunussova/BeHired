/*
	ID:   zhazira171
	PROG: calfflac
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

char ret(char c){
	if(c>='A' && c<='Z') return (char)(c-'A'+'a');
	if(c>='a' && c<='z') return c;

	return '#';
}

string s,t;
char c;
vector<int> a;

int i,l,r,m,in,pal[20100];

int main(){  
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);


	s=t="";
	while(cin.get(c)){
		if(c=='\n') s+='$';
		else		s+=c;

		c = ret(c);
		if(c!='#'){
		    a.pb(s.length()-1);
            t+=c;				
		}
	}

	for(i=0;i<t.length();i++){
		l = i-1;
		r = i+1;

		while((l>=0)&&(r<t.length())){
			if(t[l]!=t[r]) break;

			l--;
			r++;
		}

		pal[i] = r-l-1;
	}

	in = 0;
	for(i=1;i<t.length();i++)
		if(pal[i]>pal[in]) in = i;

	m = pal[in];

	pal[0]=1;
	for(i=1;i<t.length();i++)
		if(t[i]==t[i-1]){
			l = i-2;
			r = i+1;

			while((l>=0)&&(r<t.length())){
				if(t[l]!=t[r]) break;

				l--;
				r++;
			}

            pal[i] = r-l-1;
		}	
		else pal[i] = 1;

	r = 1;
	for(i=0;i<t.length();i++)
		if(pal[i]>m){
			r = 0;
			in = i;
			m = pal[i];
		}

	cout<<m<<endl;

	m /= 2;

	l = in - m;
	if(r) r = in + m;
	else r = in + m - 1;

	for(i = a[l]; i <= a[r]; i++)
		if(s[i] == '$') cout<<'\n';
		else cout<<s[i];

	cout<<endl;	

	return 0;
}
