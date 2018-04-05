/*
 * main.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: Garrett Marchese
 */

#include <iostream>
#include "flock.h"
#include <vector>
using namespace std;


//Initialization of world features
int World::worldTemp = 0;
int World::worldWind = 10;

int main(){

	cout << World::worldTemp << ' ' << World::worldWind << endl;
	World::worldTemp = 20;
	World::worldWind = 12;
	cout << World::worldTemp << ' ' << World::worldWind << endl;

	vector<Bird*> squad;

	Penguin b1;
	Hawk h1;
	Robin r1;
	Crow c1;

	/*
	cout << "Hawk Stuffff" << endl;
	cout << h1;
	cout << "Penguin One Characteristics: " << endl;
	cout << b1.hopDisGetter() << " " << b1.flyDisGetter() << endl;
*/
	//cout << "Penguin Two Characteristics: " << endl;
	//cout << b2.hopDisGetter() << " " << b2.flyDisGetter() << endl;

	squad.push_back(new Penguin);
	squad.push_back(new Robin);
	squad.push_back(new Hawk);
	squad.push_back(new Crow);
	squad[0] = &b1;
	squad[1] = &r1;
	squad[2] = &h1;
	squad[3] = &c1;
	cout << "Peep Squad: " << endl;

	cout << "This is the first movement in the world" << endl;
	//Movement In world given current world attributes
	for(auto& i: squad)
	{
		//cout << i.hopDisGetter() << " " << i.flyDisGetter() << endl;
		 i->moveInWorld();
	}
	//Print results
	for(auto& i: squad)
	{
		//cout << i.hopDisGetter() << " " << i.flyDisGetter() << endl;
		 cout << *i << endl;
	}

	//World Change
	World::worldTemp = -10;
	World::worldWind = 30;

	cout << "This is the Second movement in the world" << endl;
	for(auto& i: squad)
	{
		//cout << i.hopDisGetter() << " " << i.flyDisGetter() << endl;
		 i->moveInWorld();
	}

	//Print results
	for(auto& i: squad)
	{
		//cout << i.hopDisGetter() << " " << i.flyDisGetter() << endl;
		 cout << *i << endl;
	}


	for(unsigned int i = 0; i < squad.size(); ++i)
	{
		delete squad[i];
	}
	squad.clear();
	cout << squad.size();
	//return 0;
}
