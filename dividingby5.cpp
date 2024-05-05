#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <string>
using namespace std;
double intlog(double base, unsigned long long x) {
    return (double)(log(x) / log(base));
}
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}
string obcinajzera(string bin){
	int n=bin.size();
	for(int i=0;i<n;i++){
		if(bin[i]=='1'){
			return(bin.substr(i,n-1));
		}
	}
	return "0";
}
bool greaterthan(string first,string second){
	int n;
	n=makeEqualLength(first,second);
	for(int i=0;i<n;i++){
		if(first[i]=='1'&&second[i]=='0')return true; //first wiekszy
		if(first[i]=='0'&&second[i]=='1')return false;
	}
	return true ; //sa rowne
}
bool potega(string bin){
//cout<<"dzielenie :"<<bin;
	if(bin[0]=='0')return false;
	if(bin.size()==0)return false;
	if(bin[bin.size()-1]=='0')return false;
	if(bin.size()==1&&bin[0]=='1')return true;
	string dividend=bin;
	string divisor="101";
	string quotient;
	string por;
	int k;
	do{
	quotient="0";
	int i=0;
	while(greaterthan(dividend,divisor)){
		por=dividend.substr(i,3);
//cout<<"dividend: "<<dividend<<" quotient: "<<quotient<<" i: "<<i<<" por: "<<por<<endl;
			
			if(por=="101"){
				dividend.replace(i,3,"000");
				quotient.push_back('1');
			}
			else if(por=="110"){
				dividend.replace(i,3,"001");
				quotient.push_back('1');
			}
			else if(por=="111"){
				dividend.replace(i,3,"010");
				quotient.push_back('1');
			}
			else if(i>0&&dividend[i-1]=='1'){
				if(por=="000")
				dividend.replace(i-1,4,"0011");
				if(por=="001")
				dividend.replace(i-1,4,"0100");
				if(por=="010")
				dividend.replace(i-1,4,"0101");
				if(por=="011")
				dividend.replace(i-1,4,"0111");
				quotient.push_back('1');
				//dividend.replace(i-1,1,"0");
			}
			else{
				quotient.push_back('0');
			}
		i++;
		k=i;
	}
	for(int i=0;i<dividend.size()-k-2;i++){
		quotient.push_back('0');
	}
//cout<<"wyjscie z dzielenia dividend: "<<dividend<<" quotient: "<<quotient<<" i: "<<i<<" por: "<<por<<endl;
	if(obcinajzera(dividend)!="0"){
		return false;
	}
	if(obcinajzera(dividend)=="0" && obcinajzera(quotient)=="1"){
		return true;
	}
	dividend=obcinajzera(quotient);	
	}while(1);
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
//	cout<<greaterthan("00000000000101","101")<<endl<<endl;
string st;
cin>>st;
//cout<<"potega st "<<potega(st)<<endl;
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
