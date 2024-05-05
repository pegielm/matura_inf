#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int tab[n];
	for(int i=0;i<n;i++){
		cin>>tab[i];
	}
	sort(tab,tab+n);
	int suma=0;
	for(int i=0;i<n;i++){
		if(i<k){
			suma+=9;
		}
		else{
			suma+=tab[i];
		}
	}
	cout<<suma<<endl;
	return 0;
}
