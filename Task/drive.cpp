#include <iostream>
#include <string>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "movable.h"

using std::cout;
using std::cin;
using std::endl;

// Function to split a string into a vector of substrings based on a delimiter
void splitString(std::string str, std::string delimiter, std::vector<std::string>& parameters) {
	if (str.empty()) {
		return; // If the string is empty, return an empty vector
	}
	
	int start = 0; // Initialize the start position for the substring
	do {
		int i = str.find(delimiter, start); // Find the position of the delimiter in the string
		if (i == std::string::npos) {
			break; // If the delimiter is not found, break out of the loop
		}
		int length = i - start; // Calculate the length of the substring
		parameters.push_back(str.substr(start, length)); // Push the substring into the vector
		start += (length + delimiter.size()); // Update the start position for the next substring
	} while (true);

	parameters.push_back(str.substr(start)); // Push the last substring into the vector
}

// Function to check if the number of arguments passed in is equal to the expected number of arguments
bool checkArguments(std::vector<std::string>& arguments, int args) {
	// If the number of arguments passed in is not equal to the expected number of arguments
	if (arguments.size() != args + 1) { 
		cout << "Arguments Error: Incorrect amount of arguments, this command requires "
			<< args << "arguments." << endl;
		return false; // Print an error message and return false
	} return true; // If the number of arguments passed in is equal to the expected number of arguments, return true
}

// Overloading the function in the case of a range of allowed arguments
bool checkArguments(std::vector<std::string>& arguments, int min_args, int max_args) {
	if (arguments.size() < min_args + 1 || arguments.size() > max_args + 1) {
		cout << "Arguments Error: Incorrect amount of arguments, this command requires between "
			<< min_args << "and " << max_args << "arguments." << endl;
		return false;
	} return true;
}

int main() {
	// Initialize variables to store user input and created shapes
	std::string userCommand;
	std::vector<Shape*> shapes;
	std::vector<std::string> parameters;

	while (userCommand.compare("exit") != 0) // Continuously prompt the user for a command until "exit" is entered
	{
		double x, y, h, w, e, r, xm, ym;

		cout << "Enter the command: "; // Prompt the user to enter a command

		getline(cin, userCommand); // Read the user input into the userCommand variable

		splitString(userCommand, " ", parameters); // Split the user input into a vector of substrings

		std::string command = parameters[0]; // Store the first substring (the command) in a separate variable

		if (command.compare("addR") == 0) { // Check the command and perform the corresponding action
			if (!checkArguments(parameters, 4)) { // Check if the number of arguments passed in is correct
				break;
			}

			// Get the necessary arguments to create the rectangle
			x = stod(parameters[1]);
			y = stod(parameters[2]);
			h = stod(parameters[3]);
			w = stod(parameters[4]);

			Rectangle* r = new Rectangle(x, y, w, h); // Create a new rectangle object and add it to the shapes vector
			shapes.push_back(r);
			cout << *r << endl; // Print the rectangle object
		}
		else if (command.compare("addS") == 0) {
			if (!checkArguments(parameters, 3)) { // Check if the number of arguments passed in is correct
				break;
			}
			
			// Get the necessary arguments to create the square
			x = stod(parameters[1]);
			y = stod(parameters[2]);
			e = stod(parameters[3]);

			Square* s = new Square(x, y, e); // Create a new square object and add it to the shapes vector
			shapes.push_back(s);
			cout << *s << endl; // Print the square object
		}
		else if (command.compare("addC") == 0) {
			if (!checkArguments(parameters, 3)) { // Check if the number of arguments passed in is correct
				break;
			}
			
			// Get the necessary arguments to create the circle
			x = stod(parameters[1]);
			y = stod(parameters[2]);
			r = stod(parameters[3]);

			Circle* c = new Circle(x, y, r); // Create a new circle object and add it to the shapes vector
			shapes.push_back(c);
			cout << *c << endl; // Print the circle object

		}
		else if (command.compare("scale") == 0) {
			if (!checkArguments(parameters, 2, 3)) { // Check if the number of arguments passed in is within the correct range
				break;
			}

			// Get the shape number and scaling factor(s)
			int shapeNo = stoi(parameters[1]);
			ym = stod(parameters[2]);
			if (parameters.size() > 3) { 
				xm = stod(parameters[3]);

				// Get the shape object and scale it
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]); 
				m->scale(xm, ym); 
			}
			else {
				// Get the shape object and scale it
				Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->scale(ym); 
			}

			cout << shapes[shapeNo - 1]->toString() << endl; // Print the scaled shape
		}
		else if (command.compare("move") == 0) { // Check if the number of arguments passed in is correct
			if (!checkArguments(parameters, 3)) {
				break;
			}

			// Get the shape number and movement coordinates
			int shapeNo = stoi(parameters[1]);
			x = stod(parameters[2]);
			y = stod(parameters[3]);

			// Get the shape object and move it
			Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);

			cout << shapes[shapeNo - 1]->toString() << endl; // Print the moved shape
		}
		else if (command.compare("display") == 0) { 
			// Iterate through the shapes vector and print each shape
			for (auto shape : shapes) {
				cout << shape->toString() << endl;
			}
		}
		else if (command.compare("clear") == 0) {
			shapes.clear(); // Clear the shapes vector
			cout << "Cleared shapes." << endl;
		}

		parameters.clear(); // Clear the parameters vector
		cout << endl << endl;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
