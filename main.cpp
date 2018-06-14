#include <iostream>
#include <map>

using namespace std;

//Print out each pair of a seqsuence
void printSequence(map<int,int> &sequence)
{
	map<int,int>::iterator i;
	for(i = sequence.begin(); i != sequence.end(); i++){
		cout << "(" << i->first << "," << i->second << ") ";
	}
	cout << " " << endl;
}

//Print out last pair of a seqsuence
// i-- set the pointer to last pair of a seqsuence
void printLastPair(map<int,int> &sequence){
	map<int,int>::iterator i;
	i = sequence.end();
	i--;
	cout << "(" << i->first << "," << i->second << ") ";
}

//Print out last pair of a seqsuence
void printFirstPair(map<int,int> &sequence){
	map<int,int>::iterator i;
	i = sequence.begin();
	cout << "(" << i->first << "," << i->second << ") ";
}

//Print out the modified sequence
void printModifiedSequence(map<int,int> &sequence, int &factor_n)
{
	map<int,int>::iterator i;
	unsigned int sizeOfSubSeq = sequence.size();
	unsigned int factor;
	factor = factor_n;
	if(sizeOfSubSeq < 3){
		map<int,int>::iterator i;
		for(i = sequence.begin(); i != sequence.end(); i++){
			cout << "(" << i->first << "," << i->second << ") ";
		}
	}else{
		if(factor > sizeOfSubSeq){
			printFirstPair(sequence);
			printLastPair(sequence);
		}else{
			int temp = sizeOfSubSeq/factor;
			for( ; temp > 0; temp--){
				i = sequence.begin();
				cout << "(" << i->first << "," << i->second << ") ";
				for(int j = factor; j > 1 ; j--){
					sequence.erase (i);
					i++;
				}
				factor++;
			}
			if(sequence.size() < 2){
				printLastPair(sequence);
			}else{
				printFirstPair(sequence);
				printLastPair(sequence);
			}
		}
	}
}

int main ()
{
	int y = 0, factor = 0;
	map<int,int> initialSequence, subSequence;
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
	
	printSequence(initialSequence);
	cout << "Enter a N factor (n > 2):" << endl;
	cin >> factor;
	if(factor <= 2)
	cout << "Incorrect insert!" << endl;
	else{
		for(map<int,int>::iterator i = initialSequence.begin(); i != initialSequence.end(); i++){
			if(i != initialSequence.begin()){
				if(y == i->second){
					subSequence.emplace(i->first, i->second);
				}else{
					printModifiedSequence(subSequence, factor);
					subSequence = map<int,int>();
					y = i->second;
					subSequence.emplace(i->first, i->second);
				}
			}else{
				y = i->second;
				subSequence.emplace(i->first, i->second);
			}		
		}
		printModifiedSequence(subSequence, factor);
		subSequence = map<int,int>();
	}	
	return 0;
}
