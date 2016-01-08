#include <string>
#include <fstream>
#include "Grammar.h"
#include "Util.h"

using namespace std;

#ifndef _RandomSentenceGenerator_
#define _RandomSentenceGenerator_
class RandomSentenceGenerator {
	private:
		Grammar *grammar;
		Util *helper;
		bool readFileAndAddGrammar(string fileName);
		string sentenceGenerator(string nonTerm);
	public:
		RandomSentenceGenerator(string fileName);
		~RandomSentenceGenerator();
		string randomSentence();
		void printGrammar();
};
#endif
