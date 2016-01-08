#include "Util.h"
#include <string>
#include <iostream>

using namespace std;

/*
* Constructor of the Util class
*/
Util::Util() {

}

/*
* Destructor of the Util class
*/
Util::~Util() {

}

/*
* Validates a string if it consists of a non-terminal (form <nonTermName>).
* If existing then name of the first non-terminal will be returned
* else an empty string will be returned.
*/
string Util::getFirstNonTerm(string sentence) {
//	cout << " TESTING " << endl;
	size_t pos = sentence.find('<');
	if (pos != string::npos) {
		// non-temrinal was found
		size_t pos2 = sentence.find('>');
		pos2++;
		string val = sentence.substr(pos, pos2 - pos);
		return val;
	}
	// non-terminal was not found
	return "";
}

/*
* Validates if specified non-terminal is in sentence
*/
bool Util::consistsNonTerm(string sentence, string nonTerm) {
	size_t pos = sentence.find(nonTerm);
	if (pos != string::npos) {
		// specified non-terminal was found
		return true;
	}
	// Specified non-terminal was not found
	return false;
}

/*
* Replaces first up coming of the specified non-terminal name with the substring
* to the reference of the sentence.
*/
void Util::replaceNonTerm(string *sentence, string nonTerm, string subString) {
	size_t pos = sentence->find(nonTerm);
	if (pos != string::npos) {
		// The non-terminal was found
		size_t pos2 = sentence->find('>');
		pos2++; // Include '>'
		sentence->replace(pos, pos2 - pos, subString);

		return;
	}
	// The non-terminal was not found
	return;
}
