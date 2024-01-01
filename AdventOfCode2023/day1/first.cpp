#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "file_reader.h"

using namespace std;
typedef vector<pair<string,int>>  map_si;
static map_si translation, r_translation; 

class  CandidateComputer {
	public:
		struct Candidate{
			int v;
			int ind;
			bool isBest = false;

			friend ostream& operator<<(ostream& s, const Candidate& b);

			bool isBestCandidate(string w, bool last=false){
				cout << "Len of " << w << w.length() << endl;
				int indForBest = (last) ? w.length()-1 : 0;
				return isBest || ind == indForBest;
			}
		};

		Candidate cb;
		Candidate ce;

		const string original;
		string working;

		CandidateComputer(string a): original(a), working(a) { };

	void findDigits(){
		//move LR
		int i=0;
		for ( auto c : original ) {
			if (isdigit(c)) {
				cb.v = (c - '0') ;
				cb.ind =  i;
				break;
			}
			i++;
		}

		i = original.length()-1;
		string reversed_original(original.crbegin(), original.crend());

		for ( auto c : reversed_original) {
			if (isdigit(c)) {
				ce.v = (c - '0');
				ce.ind = i;
				break;
			}
			i--;
		}
		cout << "i: " << i <<endl;
		cout << cb << ce << endl;

	}

	int findTranslation(string s, bool reverse=false) {
		
		string ss;
		(reverse) ? ss.assign(s.crbegin(), s.crend()) : ss.assign(s);
		auto iter_obj =  (!reverse) ? translation : r_translation ;

		for(auto a: (!reverse) ? translation : r_translation ){
			if(ss.compare(0,a.first.length(), a.first) == 0) {
				return a.second;
			}
		}
		return -1;

	}
	int main_algorithm() {
		findDigits();
		cout << "CB: " << cb << endl;
		while (!(cb.isBestCandidate(working) && ce.isBestCandidate(working, true))) {
			if (!cb.isBestCandidate(working)) {
				int res = findTranslation(working);
				if ( res != -1) 
				{ 
					cb.v = res;
					cb.ind = 0;
					cb.isBest = true;
				}
				else 
				{
					working.erase(0,1);
					cb.ind--;
					ce.ind--;
				}
			}
			cout << "CB: " << cb;
			cout << "CE: " << ce; 
			if ( !ce.isBestCandidate(working, true)) {
				int res = findTranslation(working, true);
				if ( res != -1) 
				{ 
					ce.v = res;
					ce.ind = -100;
					ce.isBest = true;
				}
				else
				{
					working.pop_back();
				}
			}
			cout << working << endl;
		};
		cout << "newBest: " << cb;
		cout << "newBest: " << ce;

		return (cb.ind == ce.ind) ? cb.v*11 : cb.v*10+ce.v;
		//56908
		//56017 <- reverse back search
		//55990 <- front search
	}

};

ostream& operator<<(ostream& s, const CandidateComputer::Candidate& b)
{
	s << "v: " << b.v << " | " << "[" << b.ind << "]" << endl;
	return s;
};


int main(){
	vector<string> input = file_reader("input1.txt");
	translation = {
		{"one",1},
		{"two",2},
		{"three",3},
		{"four",4},
		{"five",5},
		{"six",6},
		{"seven",7},
		{"eight",8},
		{"nine",9}
	};

	for ( auto i: translation ) {
		// reverse digit strings for backward search
		string ts(i.first.rbegin(), i.first.rend());
		r_translation.push_back({ts,i.second});
	}

	int result_sum=0;
	for (auto entry: input) {
		CandidateComputer cc(entry);
		result_sum += cc.main_algorithm();
	}

	cout << "result_sum "  << result_sum << endl;

}
