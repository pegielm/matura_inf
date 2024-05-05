#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,op=0;
	cin>>n;
	int tab[n],sum=0;
	for(int i=0;i<n;i++){
		cin>>tab[i];
		sum+=tab[i];
	}
	while(1){
		for(int i=0;i<n;i++){
			if(tab[i]%2){
				op++;
				tab[i]--;
				sum--;
			}
		}
		for(int i=0;i<n;i++){
			if(tab[i]>0)break;
			if(i==n-1)goto koniec;
		}
		for(int i=0;i<n;i++){
			tab[i]=tab[i]/2;
			
		}
		sum=sum/2;
		op++;

	}
	koniec:
	cout<<op<<endl;
	
	return 0;
}
