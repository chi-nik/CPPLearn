#include <iostream>
#include <vector>
#include <limits>
#include <map>
class Range{
	public:
		int lower,upper;
		Range(int a, int b): lower{a}, upper{b}{};
		Range(int a): Range(a,a){ std::cout << "Singl<;withe construction with value" << a<< std::endl;}; 
		
		bool contains(const Range& other) const{
			if(other.lower >= lower 
					&& other.lower <= upper 
					&& other.upper <= upper 
					&& other.upper >= lower) return true; 
			return false;
		}
		bool operator==( const Range& other) const{
			return contains(other);
		}
		bool operator<(const Range& other) const {
			return  lower < other.lower ; 
		}

		friend std::ostream& operator<<(std::ostream& s, const Range& n){
			s << "[" <<n.lower << ", " << n.upper << "]";
			return s;
		}
};
class PartialFunction{
	public:
	typedef int (*range_f)(int);
	std::map<Range, range_f> ranges;
	
	void add(Range r, range_f f){
		ranges[r] = f;
	}
	PartialFunction() {
		add(Range(std::numeric_limits<int>::min(),std::numeric_limits<int>::max()), [](int a ){return a;});

	}
	int get(Range r){
		std::cout << "Looking for  " << r << std::endl;
		Range it(r);
		for(auto c=ranges.rbegin(); c != ranges.rend(); ++c){
			std::cout << "Cont " << c->first << std::endl;
			if( c->first.contains(r) ) { std::cout << "FOUND in get " ; it = c->first; break;} 
		}

		//std::cout << it;
		auto v = ranges.at(it)(r.lower);
		return v;
	}
};

struct RangeHasher
{
	std::size_t operator()(const Range& r) const{
		return std::hash<int>()(r.lower);
	}
};

int main(){
	//std::vector<string> input=file_reader("input.txt");
	Range r1(1,2);
	Range r2(10,12);
	Range r4(3,5);
	PartialFunction pf;
	pf.add(r1,[](int a){return 2;});
	pf.add(r2,[](int a){return a+10;});
	pf.add(r4,[](int a){return a+3;});
	std::cout << pf.get(10) << std::endl;
	for(auto c= -10; c<10; ++c){
		std::cout << " | " << c << " " << pf.get(c) << std::endl;
	}
	return 0;
}
