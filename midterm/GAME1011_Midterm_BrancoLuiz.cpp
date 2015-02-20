#include <iostream>
#include <ctime>
#include <string>
#define NUMCOLORS 5
using namespace std;

string colors[NUMCOLORS] = { "green","yellow","purple","white","brown" };

class Pirate {
protected:
	string name;
	string favColor;
public:
	int numParrots;
  // Use this function for the last question to make class abstract!!!
  // You will also need to add a special keyword to make it abstract...
	virtual void buyParrot() = 0;

	// A friendly function prototype belongs here... What exactly? That's for you to figure out!
	void printParrot(string b) {
    this->numParrots++;
		cout << this->name << " purchases a " << b << " parrot!\n";
	}

	void buyParrot(int n) {
    for (int i = 0; i < n; ++i) {
      this->buyParrot();
    }
  }

};

class SadPirate : public Pirate {
public:
  using Pirate::buyParrot;
	SadPirate(string n, int numP)
	{
    name = n;
    numParrots = numP;
		favColor = "blue";
	}
	virtual void buyParrot() {
		string retParrot;
		int makeFav = rand() % 3;
		if (makeFav == 1) {
			retParrot = this->favColor;
    } else {
			int parrotIndex = rand() % NUMCOLORS;
			retParrot = colors[parrotIndex];
		}
    Pirate::printParrot(retParrot);
	}
};

/*
	Create the AngryPirate class here.
*/

class AngryPirate : public Pirate {
public:
  AngryPirate(string n, int numP) {
    name = n;
    numParrots = numP;
    favColor = "red";
  }

	virtual void buyParrot() {
		string retParrot;
		int makeFav = rand() % 2;
		if (makeFav == 1) {
			retParrot = "red";
    } else {
      retParrot = "orange";
		}
    Pirate::printParrot(retParrot);
	}
};

/*
	Create the overloaded operator+ function here.
*/
int operator+(int n, Pirate &pirate) {
  return n + pirate.numParrots;
}

int main() {
	srand((unsigned)time(NULL));

  SadPirate sad = SadPirate("Jack", 1);
  AngryPirate angry = AngryPirate("Barbossa", 3);

  sad.buyParrot();
  sad.Pirate::buyParrot(5);
  angry.buyParrot();

	cout << "Yar! Two parrots fly down onto the sad pirate's ship...\n";
	cout << "Jack now has " << 2 + sad << " parrots.\n";

	return 0;
}
