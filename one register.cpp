#include<bits/stdc++.h>
#include <cmath>
using namespace std;
    bool isPerfect(int N)
    {
        if ((sqrt(N) - floor(sqrt(N))) != 0)
            return false;
        return true;
    }
    int bliski(int N)
    {
        if (isPerfect(N))
        {
            return 0; //jest kwadratem
        }

        int aboveN = -1, belowN = -1;
        int n1;

        n1 = N + 1;
        while (true) {
            if (isPerfect(n1)) {
                aboveN = n1;
                break;
            }
            else
                n1++;
        }
 
        n1 = N - 1;
        while (true) {
            if (isPerfect(n1)) {
                belowN = n1;
                break;
            }
            else
                n1--;
        }
 
        int diff1 = aboveN - N;
        int diff2 = N - belowN;
 
        if (diff1 > diff2)
            return -diff2; //tyle do kwadratu na dol np -21
        else
            return diff1; //tyle do kwadratu na gorze np 21
    }
    int potega10(int k){
    	int wynik=1;
    	for(int i=0;i<k;i++){
    		wynik*=10;
		}
		return wynik;
	}
    int liczbacyfr(int n){
    	int cyfry = 0;
    	if(n==0)return 1;
		while(n!=0) {
     		++cyfry; 
     		n /= 10;
		}
		return cyfry;
	}
	bool sorted(int n){
		int cyfry=liczbacyfr(n);
		if(cyfry==1)return true;
		int poprzednia=0;
		int k = 0; 
		int a[cyfry]; 
		while (n) { 
   			a[k++] = n % 10; 
    		n /= 10; 
		}
		for(int i=0;i<cyfry-1;i++){
		//	cout<<a[i]<<" ";
			if(a[i]>a[i+1])return false;
		}
		return true;
	}
    int main()
    {
        int n;
        int nrop=0;
        cin>>n;
        int c=liczbacyfr(n);
		//cout<<endl<<"bliski od n = "<<bliski(n)<<" sorted od n= "<<sorted(n)<<endl;
		while(n>1){
			if(n==2){
				nrop++;
				break;
			}
			if(n==3){
				nrop+=2;
				break;
			}
			if(bliski(n)==0){
					//JEZELI JEST IDEALNA POTEGA
			nrop++;
			n=sqrt(n);
//			cout<<"idealna potega dla n= "<<n<<" nrop = "<<nrop<<endl;	
			continue;
			}
			if(sorted(n)&&n>10){             //JEZELI MA POSORTOWANE LICZBY
//			cout<<"sorted dla n= "<<n<<" nrop = "<<nrop<<endl;
				int zast=n;
       			int k=c-1;
        		int a[c];
        		while (zast) { 
   					a[k--] = zast % 10; 
    				zast /= 10; 
				}
  				sort (a,a+3);
  				int porownanie=bliski(n);
  				int min=porownanie;
  				int nowy=999999;
  				do {
        			for(int i = 0; i<c;i++){
            		cout << a[i];
        			}
        			cout << endl;
        			if(a[0]>0){
						int number = 0;
						for (int i = 0; i < c; i++) {
   							number *= 10;
    						number += a[i];
						}
//						cout<<" numer= "<<number<<endl;
						int odl;
						odl=bliski(number);
						if(abs(odl)<abs(min)||(abs(odl)==abs(min)&&number<nowy)){
								min=odl;
								nowy=number;
						}
					}
  				} while ( next_permutation(a,a+c) );
  				if(min==0){	
				  nrop++;
				  n=sqrt(nowy);		//JEZELI JEST IDEALNA POTEGA
				  nrop++;
				//op.push_back('s');
//				cout<<"wyjscie z posortowanej kiedy jest idealna  n= "<<n<<" nrop = "<<nrop<<" min= "<<min<<endl;
				  continue;
				}
  				if(abs(min)<abs(porownanie)){
  					nrop+=abs(min);
  					//op.push_back('p');
					  n=sqrt(nowy+min);
					  nrop++;
//					  cout<<"wyjscie z posortowanej n= "<<n<<" nrop = "<<nrop<<" min= "<<min<<endl;
					  continue;	
				}
			}
			int czasowa;
			czasowa=bliski(n);
			nrop+=abs(czasowa);
			n=sqrt(czasowa+n);
			nrop++;
//			cout<<"koniec petli  n= "<<n<<" nrop = "<<nrop<<endl;
			
		} 
		nrop++;
		cout<<nrop<<endl;
        return 0;
    }
