/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:

clear()- To clear the stream.
str()- To get and set string object whose content is present in the stream. 
operator <<- Add a string to the stringstream object. 
operator >>- Read something from the stringstream object.

*/


/**
 * Examples:

1. Count the number of words in a string
*/

// C++ program to count words in
// a string using stringstream.
#include <iostream>
#include <sstream>
#include<string>
using namespace std;

int countWords(string str)
{
	// Breaking input into word
	// using string stream

	// Used for breaking words
	stringstream s(str);

	// To store individual words
	string word;

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

// Driver code
int main()
{
	string s = "geeks for geeks geeks "
			"contribution placements";
	cout << " Number of words are: " << countWords(s);
	return 0;
}


/*
2. Print frequencies of individual words in a string
Input: Geeks For Geeks Quiz Geeks Quiz Practice Practice
Output: For -> 1
             Geeks -> 3
             Practice -> 2
             Quiz -> 2

Input: Word String Frequency String
Output: Frequency -> 1
              String -> 2
              Word -> 1    
*/

// C++ program to demonstrate use
// of stringstream to count
// frequencies of words.


void printFrequency(string st)
{
	// Each word it mapped to
	// it's frequency
	map<string, int>FW;

	// Used for breaking words
	stringstream ss(st);

	// To store individual words
	string Word;

	while (ss >> Word)
		FW[Word]++;

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << "-> "
			<< m->second << "\n";
}

// Driver code
int main()
{
	string s = "Geeks For Geeks Ide";
	printFrequency(s);
	return 0;
}
