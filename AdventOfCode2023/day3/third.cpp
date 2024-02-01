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
	if (symbol.s.sym != '*') continue;

	auto unique_nums = g.GetUniqueNums(g.GetRegion(symbol,1));
	if((int) unique_nums.size() == 2) {
		int gear_ratio=unique_nums[0].num*unique_nums[1].num;
		sum = sum + gear_ratio;
		cout << "  sum" << sum << endl;;
	}
}
cout << "Sum: " << sum;


}

