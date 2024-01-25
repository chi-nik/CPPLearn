#pragma once
class Symbol {
	//Symbol
	public:
		char sym{'.'};
	//	static Symbol Empty;
		Symbol(char c): sym{c}{
		//	DLOG("[Created] Symbol ", c, this)
			sym=c;
		}
	
};
