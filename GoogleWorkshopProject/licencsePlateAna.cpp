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

bool compLen(string &a, string &b)
{
	return (a.size() < b.size());
}

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
/*
	for(auto &i: dictionary)
	{
		cout << i << endl;
		count++;
	}
	cout << count << endl;
*/
	while(invalidLicensePlateFound)
	{

		cout << "Please Enter License Plate 5-7 characters: ";
		cin >> inputLicensePlate;
		count = inputLicensePlate.length();
		cout << count << endl;
		//regex_match(inputLicensePlate,m,letter);
		//mcount = m.size();
		//cout << m.length() << endl;
		if((count >= 6 && count <= 8))
		{
		//	cout << "valid string" << endl;
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
/*	for(auto &z: plateChars)
	{
		cout << letFreq[z] << endl;
	}
	*/
	bool checkCharInWord = false;
	for(auto &j: dictionary)
	{
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
		if(checkCharInWord)
		{
			potWords.push_back(j);
		}
	}

	int pcount = 0;
	/*for(auto &y: potWords)
	{
		cout << y << endl;
		pcount++;
	}*/
	cout << pcount << endl;
	sort(potWords.begin(), potWords.end(),compLen);
	cout << potWords[0];

	return 0;
}


















