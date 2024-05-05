#include <iostream>
#include <math.h>  
#include <algorithm>
using namespace std;
int main(){
	int n,k,sum=0;
	cin>>n>>k;
	int j=n;
	int tab[n];
	for(int i=0;i<n;i++){
		cin>>tab[i];
	}
	sort(tab,tab+n);
	for(int i=0;i<k+1;i++){
		if(tab[j]>=tab[j-1]){
			tab[j]=floor(tab[j]/2);
			
		}
		if(tab[j]<tab[j-1])j--;
	}
	for(int i=0;i<n;i++){
		sum+=tab[i];
	}
	cout<<sum<<endl;
	return 0;
}
