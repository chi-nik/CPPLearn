#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include "../headers/HanoiTowers.h" 
//using namespace std;
Towers::Towers(int initialStack) {
	for (int i =  initialStack; i > 0; --i)
		A.push(i);
}
void Towers::mv(char s, char  d, rng r ) {
	std::cout << toString();

	// std::map<Pile, std::vector<int>& > t = { {Pile::A, &A},{Pile::B, &B}, {Pile::C, &C} };
	 std::map<char, std::stack<int>* > t = { {'A', &A}, {'B', &B}, {'C', &C} };

	 if (r.single) {
		 t[d]->push(t[s]->top());
		 t[s]->pop();
	 }
	 else // mutliple
	 {
		 std::string abc = "ABC";
		 abc.erase(abc.find(s), 1);
		 abc.erase(abc.find(d), 1);
		 char o = abc[0];

		 mv(s, o, rng(r.from - 1));
		 mv(s, d, rng(r.from , r.from));
		 mv(o, d, rng(r.from - 1)); 
	 }

 
}

std::string Towers::toString() {
	auto Av  = asvec(A);
	auto Bv  = asvec(B);
	auto Cv  = asvec(C);
	std::ostringstream repr;
	for (int i = 9; i >= 0; --i) {
		std::string av, bv, cv;

		av = i < Av.size() ? std::string(Av[i], '0' + Av[i]) : "";
		bv = i < Bv.size() ? std::string(Bv[i], '0' + Bv[i]) : "";
		cv = i < Cv.size() ? std::string(Cv[i], '0' + Cv[i]) : "";
		repr << std::setw(10) << std::right << av << '|' << std::setw(10) << std::left << av;
		repr << std::setw(10) << std::right << bv << '|' << std::setw(10) << std::left << bv;
		repr << std::setw(10) << std::right << cv << '|' << std::setw(10) << std::left << cv;
		repr << std::endl;
	}
	repr << std::endl;

	return repr.str();


}
std::vector<int> Towers::asvec(std::stack<int> s) {
	auto a = s._Get_container(); 
	std::vector<int> stack_contents(a.begin(), a.end()); 
	return stack_contents;
}
/*
int main()
{
	Towers tow(9);
	tow.mv('A', 'C', Towers::rng{9,1});
	std::cout << tow.toString();

	return 0;

}
*/

