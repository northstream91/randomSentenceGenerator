// Author:	Jonas Nordstrom
// Assignment:	Lab 4
// Title:	Random Sentence Generator
// Course:	CSCE343


#include <string>
#include <unordered_map>
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Grammar.h"

using namespace std;

/*
* Constructor for Grammar
*/
Grammar::Grammar() {
	grammars.clear();
}

/*
* Destructor of the Grammar
*/
Grammar::~Grammar() {
}

/*
* Adds a production to our grammar map
*/
void Grammar::addProduction(string nonTerm, string rhs) {
	if (containsNonTerminal(nonTerm)) {
		// It already exists, update the data
		vector<string> temp = grammars[nonTerm];
		temp.emplace_back(rhs);
		grammars[nonTerm] = temp;
	} else {
		// The non-terminal does not exists
		vector<string> temp(1, rhs);
		grammars.insert({nonTerm, temp});
	}
}

/*
* Returns randomly a production of the specified non-terminal
*/
string Grammar::getRandomRHS(string nonTerm) {
	if (containsNonTerminal(nonTerm)) {
		// Non-terminal exists
		int upper = grammars[nonTerm].size();
		if (upper == 0) {
			cout << "Grammar is wrong formatted, no productions for this non-terminal" << endl;
		}
		random_device rd;
		mt19937 re(rd());
		uniform_int_distribution<int> ui(0, upper-1);
		int dice_roll = ui(re);
		return grammars[nonTerm][dice_roll];
	}
	
	// The non terminal does not exists
	return "Grammar::getRandomRHS: ERROR";
}

/*
* Validates if the non-terminal already exists in our map
*/
bool Grammar::containsNonTerminal(string nonTerm) {
	int pos = nonTerm.find('<');
	string cmp1 = nonTerm.substr(pos + 1, nonTerm.find('>', pos + 1));

	for (auto item : grammars) {
		pos = item.first.find('<');
		string cmp2 = item.first.substr(pos + 1, nonTerm.find('>', pos + 1));
		int temp = cmp1.compare(cmp2);
		if (temp == 0) {
			return true;
		}
	}
	// There is no match
	return false;
}
/*
* Returns the number of production of the specified non-terminal
*/
int Grammar::size(string nonTerm) {
	if (containsNonTerminal(nonTerm)) {
		return grammars[nonTerm].size();
	}
	// The non-terminal does not exists
	return 0;
}
/*
* Returns all available non-terminals stored.
*/
vector<string> Grammar::getAllNonTerminals() {
	vector<string> result;
	for (auto item = grammars.begin(); item != grammars.end(); item++) {
		result.emplace_back((string)item->first);
	}

	return result;
}
/*
* Returns all available productions for the specified non-terminal
*/
vector<string> Grammar::getAllProductions(string nonTerm) {
	if (containsNonTerminal(nonTerm)) {
		return grammars[nonTerm];
	} else {
		vector<string> empty;
		return empty;
	}
}
/*
* Prints all grammar of this instance of grammar in a user friendly way
*/
std::ostream& Grammar::operator<<(std::ostream& out) {
	out << "==== Grammar ====" << endl;
	// Loop through all keys in the grammar map
	for (auto item = grammars.begin(); item != grammars.end(); item++) {
		// Print the non-terminal name
		out << item->first << endl;
		// Loop through each production
		for (vector<string>::iterator prod = (item->second).begin(); prod != (item->second).end(); prod++) {
			string sentence = *prod;
			
			// Print the production
			out << "\t" << *prod << endl;
		}
	}
	out << "==== End of Grammar ====" << endl;

	return out;
}
/*
* Prints all grammar of specified grammar in a user friendly way
*/
std::ostream& operator<<(std::ostream& out, Grammar& g) {
	string result = "";
	// Loop through all keys in the grammar map
	for (auto item = g.grammars.begin(); item != g.grammars.end(); item++) {
		// Print the non-terminal name
		out << item->first << endl;
		// Loop through each production
		for (vector<string>::iterator prod = (item->second).begin(); prod != (item->second).end(); prod++) {
			// Print the production
			out << "\t" << *prod << endl;
		}
	}

	return out;
}
