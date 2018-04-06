/*
 * flock.h
 *
 *  Created on: Mar 22, 2018
 *      Author: Garrett Marchese
 */

#ifndef FLOCK_H_
#define FLOCK_H_

#include <iostream>
using namespace std;

/*////////////////////////////////////////////////
				Bird Class: Base Class
////////////////////////////////////////////////*/
class Bird{

	//Public
	public:
		//Constructors
		Bird(); //Default Constructor
		Bird(int x, int y, int z); // Parameterized Constructor
		Bird(const Bird& source); //Copy Constructor


		virtual ~Bird(); //Destructor

		//Operators
		const Bird &operator=(const Bird& source); // Overload Assignment Operator
		//ostream
		friend ostream &operator<<(ostream &os, const Bird &source); // Overload Insertion Operator

		//World Interaction
		virtual void moveInWorld();
		//Access
		virtual int hopDisGetter(); //getter
		virtual int flyDisGetter(); //getter

	//Private
	private:
		virtual ostream& printFunc(ostream &os) const = 0; //Print format for operator <<

		int hopDis;
		int flyDis;
		int disTraveled;

};

/*////////////////////////////////////////////////
		Penguin Class: Derived from Bird
////////////////////////////////////////////////*/
class Penguin: public Bird{

	//Public
	public:
		//Constructors
		Penguin(); //Default Constructor
		//Penguin(const Penguin& source); //Copy Constructor
		~Penguin(); //Destructor

		//World Interaction
		void moveInWorld();

		//Access
		int hopDisGetter(); //getter
		int flyDisGetter(); //getter

	//Private
	private:
		ostream& printFunc(ostream &os) const;
		int hopDis;
		int flyDis;
		int disTraveled;

};

/*////////////////////////////////////////////////
		Hawk Class: Derived from Bird
////////////////////////////////////////////////*/
class Hawk: public Bird{

	public:
		Hawk(); //Default Constructor
		~Hawk(); // Default Destructor

		//World Interaction
		void moveInWorld();

		//Access
		int hopDisGetter(); //getter
		int flyDisGetter(); //getter

	private:
		ostream& printFunc(ostream &os) const;
		int hopDis;
		int flyDis;
		int disTraveled;
};

/*////////////////////////////////////////////////
		Robin Class: Derived from Bird
////////////////////////////////////////////////*/
class Robin : public Bird{

	public:
		Robin();
		~Robin();

		//World Interaction
		void moveInWorld();

		//Access
		int hopDisGetter(); //getter
		int flyDisGetter(); //getter

	private:
		ostream& printFunc(ostream &os) const;
		int hopDis;
		int flyDis;
		int disTraveled;

};

/*////////////////////////////////////////////////
		Crow Class: Derived from Bird
////////////////////////////////////////////////*/
class Crow: public Bird{

	public:
		Crow();
		~Crow();

		//World Interaction
		void moveInWorld();

		//Access
		int hopDisGetter(); //getter
		int flyDisGetter(); //getter

	private:
		ostream& printFunc(ostream &os) const;
		int hopDis;
		int flyDis;
		int disTraveled;
};

/*////////////////////////////////////////////////
		World Class: 
////////////////////////////////////////////////*/
class World{

    public:
		  static int worldWind;
		  static int worldTemp;

};

//add conditions for birds movement in world







#endif /* FLOCK_H_ */
