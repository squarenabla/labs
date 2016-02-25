#define VOWELS "aeiou"

#include <cctype>
#include <cstring>

#include <istream>
#include <ostream>
#include <iostream>

#include <algorithm>
#include <vector>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::vector;
using std::cin;
using std::cout;

bool space(char c){
	return isspace(c);
}

bool not_space(char c){
	return !isspace(c);
}

bool last_vowel(string str){
	return strchr("aeiou", tolower(str.back())) != NULL;
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	
	while (i != str.end()) {
		// ignore leading blanks
		i = std::find_if(i, str.end(), not_space);
		// find end of next word
		iter j = std::find_if(i, str.end(), space);
		// copy the characters in [i, j)
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

template<typename T>
void printData(ostream &out, const vector<T> data){
	for(unsigned int i=0; i<data.size(); ++i){
		if(data[i].size()!=0){
			out<<data[i]<<std::endl;
		}
	}
	return;
}

int main(){

	string text;
	std::getline(cin, text);

	vector<string> words = split(text);
	vector<string> result(words.size());

	std::remove_copy_if (words.begin(),words.end(),result.begin(),last_vowel);

	printData(cout, result);

	return 0;
}