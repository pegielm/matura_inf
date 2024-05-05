#include <bits/stdc++.h>
using namespace std;
int equivalentBase4(string bin)
{
    if (bin.compare("00") == 0) 
        return 0;
    if (bin.compare("01") == 0) 
        return 1;
    if (bin.compare("10") == 0) 
        return 2;
    return 3; 
}
bool podzielne(string bin)
{
    int l = bin.size();
    int k=0;
	if(l=1&&bin.at(0)=='1')return 1;
    if (l % 2 != 0)

        bin = '0' + bin;

    int odd_sum, even_sum = 0;

    int isOddDigit = 1;
    for (int i = 0; i<bin.size(); i+= 2)
    {
        if (isOddDigit)
            odd_sum += equivalentBase4(bin.substr(i, 2));
        else
            even_sum += equivalentBase4(bin.substr(i, 2));       
        isOddDigit ^= 1; 
    }
      
    if(abs(odd_sum - even_sum) ==0)   
    	return false;
    if (abs(odd_sum - even_sum) % 5 == 0)
        return true;

    return false;
              
}
int podciag(string bin,int start,int koniec){
	int n=bin.size();
}
int main(){
	int n;
	int k=0;
	string num,x;
	cin>>num;
	n=num.size();
	cout<<podzielne(num);
//	if(podzielne(num)){
//		cout<<1<<" cala liczba podzielna"<<endl;
//		return 0;
//	}

	
	
//	cout<<k<<endl;

	return 0;
}

