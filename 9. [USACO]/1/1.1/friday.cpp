/*
	ID:   zhazira171
	PROG: friday
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

int mon[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int y){
    if(((y%4==0)&&(y%100))||(y%400==0)) return 1;

    return 0;
}

int y,m,d,w,week[7],n,i;

int main(){  	
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);

	cin>>n;

	if(n){

        d = 1;
        m = 1;
        y = 1900;
        w = 0;

        while (true){
        	if(d==13) week[w] ++;
            

            if((d==31)&&(m==12)&&(y==1900+n-1)) break;

            d++;
            w++;
            w%=7;
            if(d>mon[m]){
            	d = 1;
            	m++;

            	if(m>12){
            		m = 1;
            		y ++;

            		if(isLeap(y)) mon[2]=29;
            		else mon[2] = 28;
            	}
            }
        }
	}

	for(i=0;i<6;i++) cout<<week[(i+5)%7]<<" ";
	cout<<week[4]<<"\n";

	return 0;
}