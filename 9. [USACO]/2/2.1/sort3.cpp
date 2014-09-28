/*
	ID:   zhazira171
	PROG: sort3
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

const int N = 1010;

int i,j,n,cnt[N],a[N],ans;

int main(){  
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);

	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		
		cnt[a[i]]++;
	}

	for(i=0;i<cnt[1];i++)
		if(a[i] == 2){
			for(j=cnt[1];j<cnt[1]+cnt[2];j++)
				if(a[j] == 1){
					ans ++;
					swap(a[i],a[j]);
					break;
				}
		}
		else
			if(a[i] == 3){
				for(j=cnt[1]+cnt[2]; j<n;j++)
					if(a[j] == 1){
						ans++;
						swap(a[i],a[j]);
						break;
					}
			}

	 for(i=cnt[1];i<cnt[1]+cnt[2];i++)
	 	if(a[i] == 3){
	 		for(j=cnt[1]+cnt[2]; j<n;j++)
	 			if(a[j] == 2){
	 				swap(a[i],a[j]);
	 				ans++;
	 				break;
	 			}
	 	}

	 j = cnt[1];
     for(i=0;i<cnt[1];i++)
     	if(a[i]!=1){
     		while(a[j]!=1) j++;

     		ans++;
     		swap(a[i],a[j]);
     		j++;
     	}

    j = cnt[1]+cnt[2];
    while(i<cnt[1]+cnt[2]){
    	if(a[i]!=2){
    		while(a[j]!=2) j++;

    		ans++;
    		swap(a[i],a[j]);
    		j++;
    	}

    	i++;
    }

    cout<<ans<<"\n";

	return 0;
}