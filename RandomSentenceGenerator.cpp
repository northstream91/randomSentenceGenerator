#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "RandomSentenceGenerator.h"
#include "Grammar.h"
#include "Util.h"

using namespace std;

/*
* Constructor of this class. Will parse the file
* params: string fileName which is the file name to the file to read
*/
RandomSentenceGenerator::RandomSentenceGenerator(string fileName) {
	cout << "Random Sentence Generator constructor called" << endl;
	grammar = new Grammar();
	helper = new Util();
	// Read file
	readFileAndAddGrammar(fileName);
}

/*
* Destructor
*/
RandomSentenceGenerator::~RandomSentenceGenerator() {
	delete grammar;
	delete helper;
}

/*
* Returns a random string from the grammar
*/
string RandomSentenceGenerator::randomSentence() {
	return sentenceGenerator("<start>");
}

/*
* Prints all the grammar in a user friendly way
*/
void RandomSentenceGenerator::printGrammar() {
	cout << *grammar << endl;
}

bool RandomSentenceGenerator::readFileAndAddGrammar(string fileName) {
	cout << "Opening file..." << endl;
	fstream file;
	file.open(fileName, std::fstream::in);

	char next;
	char trash[128];
	// Loop through each grammar in the file and make sure there is no error
	while (file.good()) {
		// Get next character to see if it is a '{'
		if (file.get() == '{') {
			// A grammar is starting here
			char name[128];
			// Get also the less than sign
			file.getline(trash, 128);
			// Get the name of the grammar
			file.getline(name, 128);

			string line;
			getline(file, line, '}');
			string prod;
			int pos = 0;
			int to = 0;
			to = line.find(";", pos);

			// Loop through all producations
			while((to + 1) < line.length() && to != string::npos) {
				prod = line.substr(pos, to - pos);
				prod.erase(std::remove(prod.begin(), prod.end(), '\t'), prod.end());
				prod.erase(std::remove(prod.begin(), prod.end(), '\n'), prod.end());
				prod.erase(std::remove(prod.begin(), prod.end(), '\r'), prod.end());
		
				grammar->addProduction(name, prod);

				pos += to - pos + 1;
				to = line.find(";", pos);
			}
		}
	}

	file.close();

	return true;
}
/*
* Generates sentence randomly
*/
string RandomSentenceGenerator::sentenceGenerator(string nonTerm) {
	string sentence = grammar->getRandomRHS(nonTerm);
	nonTerm = helper->getFirstNonTerm(sentence);

	// Loop til we don't have any non-terminals left
	while (nonTerm != "") {
		helper->replaceNonTerm(&sentence, nonTerm, sentenceGenerator(nonTerm));

		nonTerm = helper->getFirstNonTerm(sentence);
	}

	return sentence;
}
