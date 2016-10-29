/*
Will Jackson	wjbear@gmail.com
10/27/2016
David Keathly
Homework 3 Trapezoid Drawer
*/

#include <iostream>
#include <cmath>
using namespace std;

bool basecheck(int base, int compbase, int which_base);
int trapprint (int tbase, int bbase);
void traparea (int tbase, int bbase, int height);
int main()
{
	int tbase = 0, bbase = 0, height = 0;
	//Top base length, bottom base length, height
	bool bvalid;
	//Used to check the output of basecheck function
	const int TOP = 0;
	const int BOT = 1;
	//Special stuff to make basecheck work, explained later


	cout << "CSCE 1030 002, Will Jackson, wj0044, wjbear@gmail.com \n";
	cout << "Please enter an odd number between 1 and 21 for the length of the top base of your trapezoid. \n";
	cin >> tbase; //Getting initial user input
	bvalid = basecheck(tbase, 0, TOP); // Ran with TOP becuase this is the top base. compbase doesn't matter right now
	
	while (!(bvalid)) //Reprompt the user if they did it wrong
	{
		cout << "The number you entered is invalid, please select an odd number between 1 and 21. \n";
		cin >> tbase;
		bvalid = basecheck(tbase, 0, TOP); //Ran with TOP because this is the top base. compbase doesnt matter right now
	}


	cout << "Enter an odd number between " << tbase + 2 << " and 23 for the length of the bottom base of your trapezoid. \n";
	cin >> bbase; //Repeating above steps now with bottom base
	bvalid = basecheck(bbase, tbase, BOT); //Now compbase is used to make sure bottom is longer than top

	while (!(bvalid)) //Reprompt the user if they did it wrong
	{
		cout << "The number you entered is invalid, please select an odd number between " << tbase + 2 << " and 23. \n";
		cin >> bbase;
		bvalid = basecheck(bbase, tbase, BOT); //Ran with BOT because this is the bottom base
	}


	height = trapprint(tbase, bbase);
	traparea(tbase, bbase, height);

	return 0;
}


/*
Function: Base Check
Parameters: an int representing the length of one base of a trapezoid, an int
	representing the other base, an int telling the function which base it is
	supposed to check
Return: A bool representing the validity of the base
Description: This determines user input validity
*/

bool basecheck (int base, int compbase, int which_base)
{

	if (which_base = 0) //If the function is checking the top base. NOTE: this means we can ignore compbase
	{
		if ((base % 2 == 1)&&(base >= 1)&& (base <= 21)){ //If they did it right the function returns true
			return true;
		}
		else{ //If they did it wrong return false
			return false;
		}
	}
	else //If the function is checking bottom base
	{
		if ((base % 2 == 1)&&(base > compbase)&&(base <= 23)) //This means they did it right
		{
			return true;
		}
		else //This means they did it wrong
		{
			return false;
		}
	}
}


/*
Function: Trapezoid Print
Parameters: An int representing the top base of a trapezoid and an int
	representing the bottom base of the trapezoid
Return: Height of the trapezoid (NOTE: That's why this is not a void function)
Description: Draws a trapezoid
*/

int trapprint (int tbase, int bbase)
{
	int rowloop = 0, n = 0, row_width = 0, height = 0;
	//Keeps track of the row being drawn, looper variable, keeps track of the width of the row being drawn
	char draw;
	//What to draw with
	cout << "Please input a single character to draw your trapezoid with. \n";
	cin >> draw; //Get the character to draw with
	cout << endl << endl;
	
	
	n = bbase;
	do //Figure out the height
	{
		n = n - 2;
		height ++;
	} while (n >= tbase);
	
	
	row_width = tbase;
	for (rowloop = 0; rowloop < height; rowloop ++)
	{
		for (n = 0; n < (bbase - row_width)/2; n++)
		{
			cout << " ";
		}
		for (n = 0; n < row_width; n++)
		{
			cout << draw;
		}
		row_width = row_width + 2;
		cout << endl;
	}
	cout << endl;
	return height;
}


/*
Function: Trapezoid Area
Parameters: An int representing the length of the top base, an int
	representing the length of the bottom base, an int representing the
	height of the trapezoid
Return: None
Description: Calculates and prints the area of the trapezoid
*/

void traparea (int tbase, int bbase, int height)
{
	int area = 0;
	area = (height*(tbase + bbase))/2;
	cout << "The area of the trapezoid is " << area << " units^2 \n";
}
