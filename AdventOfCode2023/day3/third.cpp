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
cout << *g.grid[9][16].n << endl;
//Symbol s1('v');
//cout << s1.sym << "@ " << &s1 << endl;;
//C a(2,3, std::move(s1));
//cout << a << endl;


}

