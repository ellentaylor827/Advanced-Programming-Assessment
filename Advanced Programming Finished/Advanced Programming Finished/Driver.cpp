#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> 
#include "Driver.h"

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands
	vector <vector<float>> pointList; //holds all points
	int x = 0; //x coordinate
	int y = 0; //y coordinate
	int h = 0; //height of shape
	int w = 0; //width of shape
	int e = 0; //edge of shape (square)
	int r = 0; //radius of shape (circle)


	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);

		char* cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		//parameters.push_back(strtok(cstr, " "));//splits the string where there is white space

		//checks if no command was entered
		if (userCommand.empty()) {
			parameters.push_back("invalid");
		}

		//tokenizer that splits the command into the individual parameters
		istringstream ss(userCommand); 
		string tempString;

		while (getline(ss, tempString, ' ')) {
			parameters.push_back(tempString);
		}
		
		string command = parameters[0];

		//lambda function that checks whether the correct about of parameters were entered by the user
		auto checkParameters = [parameters](int amount) {
			if (parameters.size() < amount || parameters.size() > amount) {
				return false;
			}
			else
			{
				return true;
			}
		};
		//creates a rectangle object
		if (command.compare("addR") == 0 && checkParameters(5) == true) {
			//sets the dimensions of the shape based on the entered parameters
			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			h = stoi(parameters[3].c_str());
			w = stoi(parameters[4].c_str());

			Rectangle* r = new Rectangle(x, y, h, w);

			shapes.push_back(r); //adds new shape to shape list
			cout << r; //returns all the object information through operator overloading in Shape.h
			
		}
		//creates a square object
		else if (command.compare("addS") == 0 && checkParameters(4) == true) {
			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			e = stoi(parameters[3].c_str());

			Square* s = new Square(x, y, e);
			shapes.push_back(s);
			cout << s;
			
		}
		//creates a circle object
		else if (command.compare("addC") == 0 && checkParameters(4) == true) {
			x = stoi(parameters[1].c_str());
			y = stoi(parameters[2].c_str());
			r = stoi(parameters[3].c_str());

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			cout << c;

		}
		//scales an object
		else if (command.compare("scale") == 0 && checkParameters(4) == true) {

			int shapeNo = stoi(parameters[1].c_str());
			int xScaleAmount = stoi(parameters[2].c_str());
			int yScaleAmount = stoi(parameters[3].c_str());

			//ensures that the index is valid
			if (shapeNo < 1 || shapeNo > shapes.size()) {
				cout << "Invalid shape index" << std::endl;
			}
			else {
				//changes the shape to an object of movable  to access the scale function
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->scale(xScaleAmount, yScaleAmount);
				//changes back to an object of shape so toString can be accessed
				Shape* s = dynamic_cast<Shape*>(shapes[shapeNo - 1]);
				cout << shapes[shapeNo - 1];
			}

		}
		//moves an object
		else if (command.compare("move") == 0 && checkParameters(4) == true) {

			int shapeNo = stoi(parameters[1].c_str());
			int xMoveAmount = stoi(parameters[2].c_str());
			int yMoveAmount = stoi(parameters[3].c_str());

			//ensures that the index is valid
			if (shapeNo < 1 || shapeNo > shapes.size()) {
				cout << "Invalid shape index" << std::endl;
			}
			else
			{
				//changes the shape to an object of movable  to access the move function
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				vector<float> movedCoords = m->move(xMoveAmount, yMoveAmount);
				Shape* s = dynamic_cast<Shape*>(shapes[shapeNo - 1]);
				//resets the x and y coordinate to the new location
				s->leftTop.setx(movedCoords[0]);
				s->leftTop.sety(movedCoords[1]);

				cout << shapes[shapeNo - 1];
			}
		}
		//prints out the data of all shapes that have been created
		else if (command.compare("display") == 0) {
			//tells user if the shape list is empty
			if (shapes.empty()) {
				cout << "Shapes is empty" << endl;
			}
			else
			{
				for (int i = 0; i < shapes.size(); i++) {
					cout << shapes[i] << endl;
				}
			}
			
		}
		//clears all shapes and deletes from memory
		else if (command.compare("clear") == 0) {
			for (int i = 0; i < shapes.size(); i++) {
				delete shapes[i];
			}
			shapes.clear();
			cout << "Shapes cleared!" << endl;
		}
		//catches if a command has been inputted incorrectly
		else if (command.compare("exit") != 0) {
			cout << "Invalid command" << endl;
		}
		parameters.clear(); //clears all parameters so the next Shape's parameters can replace them
		cout << endl << endl;
	}

	cout << "Press any key to continue...";
	getchar();

	return 0;
}