/*
	ID:   zhazira171
	PROG: preface
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


string letters  = "IVXLCDM";
int a[7];

void upd(int times, int index){
	if(times == 9){
		a[index+2] ++;
		a[index] ++;
		/* for example,
		 
			IX = 9;
            XC = 90;
            CM = 900;

		*/
		return;
 	}	

    if(times > 4){
    	a[index + 1] ++;
    	a[index] += times%5;
		/* for example,
		 
			V, VI, VII, VIII
			L, LX, LXX, LXXX
            D, DC, DCC, DCCC

		*/
		return;
    }

    if(times == 4){
    	a[index] ++;
    	a[index+1] ++;

    	return;
    }

    a[index] += times;
}

void update( int n){

	if(!n) return;

	a[6] += n/1000;

	n %= 1000;
	upd(n/100, 4);

	n %= 100;
	upd ( n/10, 2);

	n %= 10;
	upd ( n, 0);
}

int main(){  
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);

	int n;

	cin>>n;

	while(n){
		update(n);
		n--;
	}

	for(int i=0;i<7;i++)
		if(a[i]) cout<<letters[i] <<" "<<a[i]<<"\n";

	return 0;
}