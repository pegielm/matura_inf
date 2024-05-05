#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
long double intlog(unsigned long long x) {
    return (long double)(log(x) / log(5));
}
bool potega(string bin){
	if(bin[0]=='0')return false;
	unsigned long long number;
	number = strtoull (bin.c_str (),NULL,2);
	if(number==1)return true;
	if(number==0)return false;
	if(fmod(intlog(number),1)==0)return true;
	return false;
}
int rek(int l, int p, string bin){

    if(l == p) return 0;

    while (l <= p && not potega(bin.substr(l,p-l))){
        l++;
    }
    if(l>=p){
	 return -1;
	}
    int a = rek(0, l, bin);
    if (a == -1){
	 return -1;
	}
    return a+1;


    }
int main(){
string st;
cin>>st;
if(potega(st)){
cout<<1<<endl;	
return 0;
}
if(st[0]=='0'){
	cout<<-1<<endl;
	return 0;
}

cout<<rek(0,st.size(),st)<<endl;

   return 0;
}
