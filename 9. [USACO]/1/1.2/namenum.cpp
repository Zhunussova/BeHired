/*
	ID:   zhazira171
	PROG: namenum
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

string num(string s){
	string rez = "";

	for(int i=0;i<s.length();i++)
		if(s[i]>='A' && s[i]<='C') rez+="2";
		else
			if(s[i]<='F') rez+="3";
			else
				if(s[i]<='I') rez+="4";
				else 
					if(s[i]<='L') rez+="5";
					else
						if(s[i]<='O') rez+="6";
						else
							if(s[i]<='S') rez+="7";
							else 
								if(s[i]<='V') rez+="8";
								else rez+="9";

	return rez;
}

int main(){  
	ofstream fout("namenum.out");
	ifstream fin("namenum.in"), fdict("dict.txt");

	string serial,s;
	int len;

	fin>>serial;

	len = serial.length();

	bool ok = false;
	while(fdict >> s){
		if((len == s.length())&&(num(s)==serial)){
			ok = true;

			fout<<s<<endl;
		}
	}

	if(!ok) fout<<"NONE"<<endl;

	return 0;
}

string serializeName(const string &in){
 string ret = "";
 for(int i = 0; i < in.length(); ++i){
  if(in[i] == 'Q' || in[i] == 'Z')
   return "1";
  if(in[i] < 'Q')
   ret += ((in[i] - 'A') / 3) + '2';
  else
   ret += ((in[i] - 'Q') / 3) + '7';
 }
 return ret;
}
