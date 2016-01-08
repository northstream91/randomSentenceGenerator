#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#ifndef _Grammar_
#define _Grammar_
class Grammar {
	private:
		unordered_map<string, vector<string>> grammars;
	public:
		Grammar();
		~Grammar();
		void addProduction(string nonTerm, string rhs);
		string getRandomRHS(string nonTerm);
		bool containsNonTerminal(string nonTerm);
		int size(string nonTerm);
		vector<string> getAllNonTerminals();
		vector<string> getAllProductions(string nonTerm);
		std::ostream& operator<<(std::ostream& output);
		friend std::ostream& operator<<(std::ostream& output, Grammar& g);
};
#endif
