/*
 * licensePlateAna.cpp
 *
 *  Created on: Apr 5, 2018
 *      Author: Garrett Marchese
 */

#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
 * Sort word by length: Sorting by length will also maintain alphabetical order
 */
bool compLen(string &a, string &b)
{
	return (a.size() < b.size());
}

/*
 * Find frequency of letter in string 
 */
int findFreq(string &a, char &b)
{
	int count = 0;
	for(auto &i:a)
	{
		if(i == b)
		{
			count++;
		}
	}
	return count;
}

int main(){

	ifstream File("dictFile.txt");
	string word;
	int count = 0;
	string inputLicensePlate;
	string plateChars;
	bool invalidLicensePlateFound = true;
	//regex letter("a-z");
	//smatch m;
	//int mcount;
	//Read dictionary data from file into vector
	vector<string> dictionary;
	vector<string> potWords;
	unordered_map<char, int> letFreq;
	
	while(File >> word)
	{
		dictionary.push_back(word);
	}

	while(invalidLicensePlateFound)
	{

		cout << "Please Enter License Plate 5-7 characters in length with a few letters: ";
		cin >> inputLicensePlate;
		count = inputLicensePlate.length();
		cout << count << endl;
		//regex_match(inputLicensePlate,m,letter); // playing around with regex
		//mcount = m.size();
		//cout << m.length() << endl;
		
		// Accept strings that are 6 to 8 characters in length
		if((count >= 6 && count <= 8))
		{
			for(auto &i: inputLicensePlate)
				{
					if(isalpha(i))
						plateChars += i;
				}
			if(plateChars.length() > 0)
				invalidLicensePlateFound = false;
		}
	}

	cout << plateChars << endl;
	for(auto &z: plateChars)
	{
		letFreq[z]++;
	}
	
	bool checkCharInWord = false;
	
	//For each word in dictionary check if there is a letter frequency match
	for(auto &j: dictionary)
	{
		//Verify letter frequency in license plate matches that of the word in dictionary
		for(auto &i: plateChars)
		{
			if((j.find(i) != -1) && (findFreq(j,i) >= letFreq[i]))
			{
				checkCharInWord = true;
			}
			else
			{
				checkCharInWord = false;
				break;
			}
		}
		//Letter frequency match, at to potential words to return 
		if(checkCharInWord)
		{
			potWords.push_back(j);
		}
	}

	int pcount = 0;
	
	cout << pcount << endl;
	sort(potWords.begin(), potWords.end(),compLen);
	cout << potWords[0];

	return 0;
}


















