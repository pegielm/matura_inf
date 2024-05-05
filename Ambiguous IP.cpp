#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstring>
using namespace std;
int power(int podstawa,int wykladnik){
	int wynik=1;
	for(int i=0;i<wykladnik;i++){
		wynik=wynik*podstawa;
	}
	return wynik;
}
int liczba(int tab[],int index,int n){
	if(tab[index]==0&&n>1)return -1; // jezeli zaczyna sie od 0 i ma wiecej niz jedna cyfre
	int potega = power(10,n);
	int wynik=0;
	for(int i=0;i<n;i++){
		potega=potega/10;
		wynik+=tab[index+i]*potega;
		
	}
	return wynik;
}
int main(){
	string ip;
	cin>>ip;
  	int n = ip.size();
  	if(n<4 || n>12){
  		cout<<"NO"<<endl;
		  return 0;	
	}
 	char char_array[n];
 	strcpy(char_array, ip.c_str());
 	int tab[n];
    for (int i = 0; i < n; i++){
	    tab[i]=char_array[i]-'0';   
	}
	/////liczba(tab,0,1); liczba od indeksu 0, 1 cyfra
	int numi,numj,numk,numl;
	for(int i=0;i<3;i++){ //0 do i
	numi=liczba(tab,0,i+1);
//	cout<<"i = "<<i<<" numi= "<<numi<<endl;
	if(0<=numi && numi<=255){
	
		for(int j=0;j<3;j++){ //i+1 do i+j
		numj=liczba(tab,i+1,j+1);
//		cout<<"j = "<<j<<" numj= "<<numj<<endl;
		if(0<=numj && numj<=255){
			
			for(int k=0;k<3;k++){ //i+j+1 do i+j+k
			numk=liczba(tab,i+j+2,k+1);
//			cout<<"k = "<<k<<" numk= "<<numk<<endl;
			if(0<=numk && numk<=255){
				
				for(int l=0;l<3;l++){//i+j+k+1 do i+j+k+l
				numl=liczba(tab,i+j+k+3,l+1);
//				cout<<"l = "<<l<<" numl= "<<numl<<endl;
				if(0<=numl && numl<=255){
					if(i+j+k+l+4==n){
						cout<<numi<<"."<<numj<<"."<<numk<<"."<<numl<<endl;
					}
				}	
				}
			}
			}
		}
		}
	}
	}
	
	return 0;
}
