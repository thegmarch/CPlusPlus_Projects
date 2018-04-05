/*
 * flock.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: Garrett Marchese
 */
#include "flock.h"
#include <iostream>

using namespace std;



/*
 * Constructor for Bird Class
 */
Bird::Bird():hopDis(0),flyDis(0),disTraveled(0){}

/*
 * Parameterized Constructor for Bird Class
 */
Bird::Bird(int hopDistance, int flyDistance, int totDistance)
{
	hopDis = hopDistance;
	flyDis = flyDistance;
	disTraveled = totDistance;
}

/*
 * Copy Constructor for Bird Class
 */
Bird::Bird(const Bird& source)
{
	hopDis = source.hopDis;
	flyDis = source.flyDis;
	disTraveled = source.disTraveled;
	cout << "base class copy constructor" << endl;
}

/*
 * Assignment Overload function for Bird Class
 */
const Bird & Bird::operator = (const Bird& source)
{
	if(this != &source)
	{
		hopDis = source.hopDis;
		flyDis = source.flyDis;
		disTraveled = source.disTraveled;
	}
	return *this;
}

/*
 * Bird Print Function
 */
ostream& Bird::printFunc(ostream &os) const
{
	return os << "Bird can hop: " << hopDis << " ft." << " and can fly: " << flyDis << "ft. " <<
			"Total Distance Traveled: " << disTraveled <<'\n';
}

/*
 * Bird Overload Operator <<
 */
ostream & operator << (ostream &os, const Bird &source)
{

	return source.printFunc(os);
}

/*
 * Destructor for Bird Class
 */
Bird::~Bird()
{
}

/*
 * Hop Distance Getter for Bird Class
 */
int Bird::hopDisGetter()
{
	return hopDis;
}

/*
 * Fly Distance Getter for Bird Class
 */
int Bird::flyDisGetter()
{
	return flyDis;
}

/*
 * Move Function for Bird Class
 */
void Bird::moveInWorld()
{
	disTraveled += hopDisGetter();
	disTraveled += flyDisGetter();
}

/*////////////////////////////////////////////////
				Penguin Class: Derived from Bird
////////////////////////////////////////////////*/
/*
 * Constructor for Bird Class
 */
Penguin::Penguin():Bird(2, 0, 0),hopDis(2),flyDis(0),disTraveled(0){}

/*
 * Default Destructor
 */
Penguin::~Penguin(){}

/*
 * Penguin Print Function
 */
ostream& Penguin::printFunc(ostream &os) const
{
	return os << "Penguin can hop: " << hopDis << " ft." << " and can fly: " << flyDis << "ft. " <<
			"Total Distance Traveled: " << disTraveled <<'\n';
}

/*
 * Peguin hop distance getter
 */
int Penguin::hopDisGetter()
{
	return hopDis;
}


/*
 * Peguin fly distance getter
 */
int Penguin::flyDisGetter()
{
	return flyDis;
}


/*
 * Peguin movement method
 */
void Penguin::moveInWorld()
{
	disTraveled += hopDisGetter();
	disTraveled += flyDisGetter();
}


/*////////////////////////////////////////////////
		Hawk Class: Derived from Bird
////////////////////////////////////////////////*/
/*
 * Default Constructor
 */
Hawk::Hawk():Bird(0, 100, 0),hopDis(0),flyDis(100),disTraveled(0){}

/*
 * Default Destructor
 */
Hawk::~Hawk(){}

/*
 * Hawk Print Function
 */
ostream& Hawk::printFunc(ostream &os) const
{
	return os << "Hawk can hop: " << hopDis << " ft." << " and can fly: " << flyDis << "ft. " <<
			"Total Distance Traveled: " << disTraveled <<'\n';
}

/*
 * Hawk hop distance getter
 */
int Hawk::hopDisGetter()
{
	return 0;
}


/*
 * Hawk fly distance getter
 */
int Hawk::flyDisGetter()
{
	if(World::worldWind <= 40)
	{
		return flyDis;
	}
	else
		return 0;
}

/*
 * Hawk movement method
 */
void Hawk::moveInWorld()
{
	disTraveled += hopDisGetter();
	disTraveled += flyDisGetter();
}


/*////////////////////////////////////////////////
		Robin Class: Derived from Bird
////////////////////////////////////////////////*/

/*
 * Robin Defualt Constructor
 */
Robin::Robin():Bird(1,20,0),hopDis(1),flyDis(20),disTraveled(0){}

/*
 * Rebin Default Destructor
 */
Robin::~Robin(){}

/*
 * Robin Print Function
 */
ostream& Robin::printFunc(ostream &os) const
{
	return os << "Robin can hop: " << hopDis << " ft." << " and can fly: " << flyDis << "ft. " <<
			"Total Distance Traveled: " << disTraveled <<'\n';
}


/*
 * Robin hop distance getter
 */
int Robin::hopDisGetter()
{
	if(World::worldTemp >= 0)
	{
		return hopDis;
	}
	else
		return 0;
}



/*
 * Robin fly distance getter
 */
int Robin::flyDisGetter()
{
	if(World::worldWind <= 20)
	{
		return flyDis;
	}
	else
		return 0;
}



/*
 * Robin movement method
 */
void Robin::moveInWorld()
{
	disTraveled += hopDisGetter();
	disTraveled += flyDisGetter();
}


/*////////////////////////////////////////////////
		Crow Class: Derived from Bird
////////////////////////////////////////////////*/


/*
 * Crow Default Constructor
 */
Crow::Crow():Bird(1,30,0),hopDis(1),flyDis(30),disTraveled(0){}

/*
 * Crow Default Deconstructor
 */
Crow::~Crow(){}

/*
 * Crow Print Function
 */
ostream& Crow::printFunc(ostream &os) const
{
	return os << "Crow can hop: " << hopDis << " ft." << " and can fly: " << flyDis << "ft. " <<
			"Total Distance Traveled: " << disTraveled <<'\n';
}

/*
 * Crow hop distance getter
 */
int Crow::hopDisGetter()
{
	if(World::worldTemp >= 0)
	{
		return hopDis;
	}
	else
		return 0;
}

/*
 * Crow fly distance getter
 */
int Crow::flyDisGetter()
{
	if(World::worldWind <= 25)
	{
		return flyDis;
	}
	else
		return 0;
}

/*
 * Crow movement method
 */
void Crow::moveInWorld()
{
	disTraveled += hopDisGetter();
	disTraveled += flyDisGetter();
}


/*////////////////////////////////////////////////
		World Class:
////////////////////////////////////////////////*/








