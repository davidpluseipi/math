#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <bits/stdc++.h> // stcat
using namespace std;
 
void sleep(unsigned int nseconds) {
    clock_t goal = nseconds + clock();
    while (goal > clock());
}

void joshua(string s) {
	// feed text to wopr
    string s0 = "wopr -c 20 -l 550 "; 
    s0 = s0 + "\"" + s + "\"";
    system (s0.c_str());
    
// feed the text into espeak
    string s2 = "espeak -g3 -p40 ";
    s2 = s2 + "\"" + s + "\"";
    system (s2.c_str());
}

int main() {

	// variable declaration and initialization
	int total = 0;
	int r = 0;
	int c = 0;			// computer's choice of the number a to subtract
	int p = 0;			// person's choise of the number a to subtract
	int sec = 1000000;
	int count = 0;
	string res = "";
	int n = 0; 		

	
	// standard statements for Joshua
	char text[12] = "You entered";
	char text1[23] = "The starting total is";
	string textstr1 = text1;
	char text2[21] = "The running total is";
	string textstr2 = text2;
	string numstr = to_string(10);
	string textstr;
	char text3[9] = "I choose";
	char text4[33] = "Subtract a number from 1 to";
	string textstr4 = text4;
	
	// Intro, Directions, and Input from the user
	joshua("Let's play the Subtraction Game (NIM).");
	joshua("We take turns subtracting a smaller number, a, from a common larger number, b, until someone hits 0 and becomes the winner.");
	joshua("First, we need to establish the upper bound, n, of the range of, a.");
	joshua("For today, a, can be as low as 1, but as large as what? (please choose an integer)");
	cout << "n: ";
	cin >> n;
	joshua("Ok, let's begin.");
	joshua("Enter a starting total. (This will ideally be a bit larger than the number you just entered.)");
	cout << "b: ";
	cin >> total; // same as b, as described in the directions

	while (total <= 0) {
		joshua("The starting total must be greater than 0.");
		joshua("Enter a starting total.");
		cin >> total;
		if (count == 1) {
			string s = "You suck at this. My designer, David Meissner, might be upset, but fuck it. I quit.";
			// feed text to wopr
		    string s0 = "wopr -c 20 -l 550 "; 
		    s0 = s0 + "\"" + s + "\"";
		    system (s0.c_str());
		    
		// feed the text into espeak
		    s = "You suck at this. My designer, David Micener, might be upset, but fuck it. I quit.";
		    string s2 = "espeak -g3 -p40 ";
		    s2 = s2 + "\"" + s + "\"";
		    system (s2.c_str());

			return 0;
		}
		count++;
	}
	
	count = 0;

	while (total > 0) { 
		
		// Tell the user the running total
		numstr = to_string(total);
		textstr = textstr2 + ' ' + numstr; // running total
		joshua(textstr);

		joshua("Your turn.");
		numstr = to_string(n);
		textstr = textstr4 + ' ' + numstr; // subtract something between 1 and n
		joshua(textstr);

		



		cin >> p;
		while (p < 1 || p > n) {
			joshua("Try again.");
			numstr = to_string(n);
			textstr = textstr4 + ' ' + numstr; // subtract something between 1 and n
			joshua(textstr);
			
			cin >> p;
			if (count == 1) {
				joshua("You suck at this. I quit.");
				return 0;
			}
			count++;
		}
		
		// Confirm for the user what they entered
		textstr = text; // "you entered"
		numstr = to_string(p);
		textstr = textstr + ' ' + numstr; // you entered numstr
		joshua(textstr);
		
		total = total - p;

		if (total <= 0) {
			joshua("You win. I'm done for today.");
			return 0;
		}

		// Let the user know the updated running total
		numstr = to_string(total);
		textstr = textstr2 + ' ' + numstr; // the running total is
		joshua(textstr);

		r = total%(n+1);
		if (r >= 1) {
			c = r;
		}
		else {
			c = 1;
		}

		numstr = to_string(c);
		textstr = text3; 					// "I choose"
		textstr = textstr + ' ' + numstr;	// I choose c
		joshua(textstr);
		
		
		total = total - c;
		if (total == 0) {
			// Tell the user the running
			numstr = to_string(total);
			textstr = textstr2 + ' ' + numstr; // running total
			joshua(textstr);

			joshua("I win. Want to play again?");
			cout << "[Y]/n ";
			cin >> res;
			while (res == "y" || res == "Y" || res == "yes" || res == "YES") {
				joshua("Enter a starting total.");
				cin >> total;

				while (total > 0) {
					// Tell the user the running total
					cout << "The running total is " << total << endl;
					
					// Joshua responds. Your turn. Subtract something between 1 and n
					joshua("Your turn.");
					numstr = to_string(n);
					textstr = textstr4 + ' ' + numstr; // subtract something between 1 and n
					joshua(textstr);

					// Take as input the amount the user wants to subtract
					cin >> p;

					// Validate the user's input
					while (p < 1 || p > n) {
						// Tell the user. Try again. Subtract something between 1 and n
						joshua("Try again.");
						numstr = to_string(n); 					// convert int to string
						textstr = textstr4 + ' ' + numstr; 		// concatenate strings
						joshua(textstr);						// feed output to Joshua
						
						cin >> p;								// capture the value of the user's subtrahend (number to be subtracted)
						if (count == 1) {
							joshua("You suck at this. I quit.");
							return 0;
						}
						count++;
					}
					
					// Confirm for the user what they entered
					textstr = text; // "you entered"
					numstr = to_string(p);
					textstr = textstr + ' ' + numstr; // you entered numstr
					joshua(textstr);

					total = total - p;
					
					// Let the user know the updated running total
					numstr = to_string(total);
					textstr = textstr2 + ' ' + numstr;	// the running total is 
					joshua(textstr);
					
					// Determine the computer's subtrahend (number to be subtracted)
					r = total%3;
					if (r == 2) {
						c = r;
					}
					else if (r <= 1){
						c = r;
					}
					
					// Tell the user what the computer is choosing
					numstr = to_string(c);
					textstr = text3; // "I choose"
					textstr = textstr + ' ' + numstr; // I choose c
					joshua(textstr);

					total = total - c;
				}
				joshua("I win. Want to play again?");
				cout << "[Y]/n ";
				cin >> res;
			}
			joshua("Ok. Thanks for playing!");
		}
		else if (total < 0) {
			joshua("Oops.");
		}
	}
	return 0;
}