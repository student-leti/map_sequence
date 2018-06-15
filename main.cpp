#include <iostream>
#include <map>

using namespace std;

int main ()
{
	int y = 0, factor = 0, n = 0, printedKey = 0;
	map<int,int> initialSequence;
	map<int,int>::iterator i;
	initialSequence[1] = 10;
	initialSequence[2] = 11;
	initialSequence[3] = 11;
	initialSequence[4] = 11;
	initialSequence[5] = 11;
	initialSequence[6] = 10;
	initialSequence[7] = 11;
	initialSequence[8] = 11;
	initialSequence[9] = 11;
	initialSequence[10] = 11;
	initialSequence[11] = 11;
	initialSequence[12] = 11;
	initialSequence[13] = 11;
	initialSequence[14] = 10;
	cout << "Initial sequence:";
	for(i = initialSequence.begin(); i != initialSequence.end(); i++){
		cout << "(" << i->first << "," << i->second << ") ";
	}
	cout<< "\nInsert factor:";
	cin >> factor;
	i = initialSequence.begin();
	cout << "\nResult sequence:";
	while(i != initialSequence.end()){
		if(i != initialSequence.begin()){
			if(i->second != y){
				y = i->second;
				i--;
				if((i != initialSequence.begin()) &
					(n > 1) &
					(printedKey != i->first)){
					cout << "(" << i->first << "," << i->second << ") ";
				}
				i++;
				n = 1;
				printedKey = i->first;
				cout << "-(" << i->first << "," << i->second << ") ";
			}else{
				n++;
				if(n%factor == 0){
					printedKey = i->first;
					cout << "*(" << i->first << "," << i->second << ") ";
				}
			}
		}else{
			y = i->second;
			n++;
			printedKey = i->first;
			cout << "(" << i->first << "," << i->second << ") ";
		}
		i++;
	}
return 0;
}
