#include <vector>
#include <map>
#include "../headers/HanoiTowers.h" 
//using namespace std;
Towers::Towers() {
	for (int i = 4; i > 0; --i)
		A.push(i);
}
void Towers::mv(char s, char  d, rng r ) {

	// std::map<Pile, std::vector<int>& > t = { {Pile::A, &A},{Pile::B, &B}, {Pile::C, &C} };
	 std::map<char, std::stack<int>* > t = { {'A', &A}, {'B', &B}, {'C', &C} };

	 if (r.single) {
		 t[d]->push(t[s]->top());
		 t[s]->pop();
	 }
	 else // mutliple
	 {
		 switch (s) {
		 case 'A':
			 switch (d) {
				 //case 'A':
				 case 'B':
					 mv('A', 'C', rng(r.from - 1));
					 mv('A', 'B', rng(r.from , r.from));
					 mv('C', 'B', rng(r.from - 1)); 
					 break;
				 case 'C':
					 mv('A', 'B', rng(r.from - 1));
					 mv('A', 'C', rng(r.from , r.from));
					 mv('B', 'C', rng(r.from - 1));
					 break;

			 }
			 break;
		 case 'B':
			 switch (d) {
				 case 'A': 
					 mv('B', 'C', rng(r.from - 1));
					 mv('B', 'A', rng(r.from, r.from));
					 mv('C', 'A', rng(r.from - 1));
					 break;
				 //case 'B':
				 case 'C':
					 mv('B', 'A', rng(r.from - 1));
					 mv('B', 'C', rng(r.from, r.from));
					 mv('A', 'C', rng(r.from - 1));
					 break;

			 }
			 break;
		 case 'C':
			 switch (d) {
				 case 'A':
					 mv('C', 'B', rng(r.from - 1));
					 mv('C', 'A', rng(r.from, r.from));
					 mv('B', 'C', rng(r.from - 1));
					 break;
				 case 'B':
					 mv('C', 'A', rng(r.from - 1));
					 mv('C', 'B', rng(r.from, r.from));
					 mv('A', 'B', rng(r.from - 1));
					 break;
				 //case 'C':

			 }
			 break;
		 }


	 }

 
}

std::vector<int> Towers::asvec(std::stack<int> s) {
	auto a = s._Get_container(); 
	std::vector<int> stack_contents(a.begin(), a.end());

	return stack_contents;
}
