#include "RandomSentenceGenerator.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	RandomSentenceGenerator *gen = new RandomSentenceGenerator("found.g");
	RandomSentenceGenerator *gen2 = new RandomSentenceGenerator("insult.g");
	// Test first grammar
	gen->printGrammar();
	
	cout << "Random Sentence 1: " << endl;
	cout << gen->randomSentence() << endl;
	cout << gen->randomSentence() << endl;
	cout << gen->randomSentence() << endl;
	

	// Test second grammar
	gen2->printGrammar();
	cout << "Random Sentence: " << endl;
	cout << gen2->randomSentence() << endl;
	cout << gen2->randomSentence() << endl;
	cout << gen2->randomSentence() << endl;

	delete gen;
	delete gen2;
	return 0;
}
