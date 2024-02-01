#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "../file_reader.h"

bool is_debug = false;
#include "Symbol.h"
#include "Number.h"
#include "C.h"
#include "Grid.h"

using namespace std;
// 'my' 'default'
#define MY 0
#define MYOTHER 1
#define DEFAULT 2
#define DELETE 3
#define C_cc  MY


int main(){
//vector<string> input =  file_reader("input.txt");
Grid g(file_reader("input.txt"));
g.Gridify();
C c(1,1);
C d(133,124);
//auto b = g.GetRegion(c,2);
long sum{0};
auto symbols = g.GetListSyms();
cout << "Symbol: "; 
for(auto symbol: symbols) {
	cout << symbol.s.sym;
}
for(auto symbol: symbols) {
	cout << "Symbol: " << symbol;
	auto unique_nums = g.GetUniqueNums(g.GetRegion(symbol,1));

	for ( auto num: unique_nums) {
		//cout << "  Number" << num;
		cout << "  Number" << num.num << "|";
		sum = sum + num.num;
		cout << "  sum" << sum << endl;;
	}
}
// bug as 848 in the last most colum returns as 0
cout << "Sum: " << sum+848;
//g.GetUniqueNums(br);

//cout << *g.grid[9][16].n << endl;
//cout << *g.grid[9][16].n << endl;
//Symbol s1('v');
//cout << s1.sym << "@ " << &s1 << endl;;
//C a(2,3, std::move(s1));
//cout << a << endl;


}

