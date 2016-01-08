#include <string>

using namespace std;

#ifndef _Util_
#define _Util_
class Util {
	private:
		
	public:
		Util();
		~Util();	
		string getFirstNonTerm(string sentence);
		bool consistsNonTerm(string sentence, string nonTerm);
		void replaceNonTerm(string *sentence, string nonTerm, string subString);
};	
#endif
