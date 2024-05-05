#include <iostream>
#include <stdlib.h>   
#include <time.h> 
#include <algorithm>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
/*bool wczytaj(string nazwa){
	ifstream dane;
	dane.open(nazwa);
	if(!dane.good()){
		return false;
	}
	while(true){
		char kod;
		dane>>kod;
		if(!dane.fail()){
			cout<<endl<<kod;
		}
		else{
			break;
		}
		
	}
	return true;
	
}
*/
int main(){

double number;
number=0.123128371293;
cout<<number-(fmod(number,0.001));

return 0;
}

