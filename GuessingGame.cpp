/*This code was originally borrowed from the WhatsACreel youtube channel linked here 
www.youtube.com/user/WhatsACreel
It has since been heavily modified, And very little of the original code remains.
The code of his that does remain, Is almost entirely modified.
This has been used for educational purposes only, For learning more things about C++ myself.
I do not claim any copy rights or ownership over the sections of this code which belong to WhatsACreel.
This code will not be sold, I hope you enjoy it! ^-^
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int difficulty = 100;
string input;		// User's input
int lowerBound = 0;		// Lowest possible number left
int upperBound = difficulty + 1; // Highest possible number left
int myGuess = 0;		// My current guess
int	lastGuess = -1;		// My last guess
char name[] = "";

string Yes = "Yes";
string No = "No";

bool ChangeDifficulty() {
	
	cout << "Type in the new difficulty setting please."<<endl<<endl;
	cout << ">";
	cin >> difficulty;
	
	if (difficulty >= 9001) cout << "IT'S OVER NINE THOUSAND!"<<endl<<endl;
	if (difficulty < 9000) cout << "Difficulty now changed to " << difficulty << "!"<<endl<<endl;

}

bool Hiya() {
	while(true) {
	
	cout << "Hiya! What's your name?" << endl << endl;
	cout << ">";
		cin >> name;
		
	cout << "\nIs " <<name<< " the right name?\n\n(Type Yes or No)"<<endl<<endl;
	cout << ">";
	
	cin >> input;
		
		if (input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!")break;
		if (input == "No") cout << "\nI'm sorry! What is the correct name?"<<endl<<endl;
		cout << ">";
			cin >> name;
				break;
		if (input == "no") cout << "\nI'm sorry! What is the correct name?"; 
			cin >> name;
				break;
	}

	
	cout << "\nThe difficulty is currently set at " << difficulty << ", Would you like to change it?" <<endl<<endl;
	cout << ">";
	cin >> input;
		if(input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!") ChangeDifficulty();
		if(input == "No");
		//else if(cout << "I'm sorry! I didn't understand that! Try Yes or No"<<endl<<endl);

	while (true) {
	
	cout << "\nOkay " << name << "! Do you want to play the Number Guessing Game with me?"<<endl<<endl;
	cout <<">";
	
	cin >> input;
	
		if (input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!") return true;
		if (input == "No") return false;
		if (input == "no") return false;
	
	cout << "\nI'm sorry "<<name <<", But, I don't understand that. Please try typing Yes or No."<<endl;
}
}


bool keepplaying() {
	cout << "Oh, Do you want to keep playing?";
	if(input == "No" || input == "no") return false;
	if(input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!") return true;
}

bool ShowStory() {
	//input = No; // Make sure input is not 'y'
	
	cout<<"\nThink of any number between 0 and "<<difficulty<<endl;
	
		cout<<"Have you thought of one?"; // I hate this omg
		cout<<endl<<"\n>";
		cin>>input;
		if(input == "No" || input == "no") keepplaying();
		if(input == "Yes" || input == "yes") return true;
		else if (cout << "I'm sorry "<<name <<"! I didn't understand that! Please try Yes or No"<<endl)ShowStory();

	}

void ResetGame() {
	lowerBound = 0;
	upperBound = difficulty + 1;
	input = "No";
	input = "no";
	}

bool UpdateWorld() {
	myGuess = (lowerBound + upperBound) / 2; // Generate the next guess

	lastGuess = myGuess;
	return true; // All good keep going
	}

void DrawGraphics()	{
	cout<<"\nI think it's "<<myGuess<<"! Am I right?"<<endl;
	cout<<"L: Lower"<<endl;
	cout<<"H: Higher"<<endl;
	cout<<"Yes: Yes!"<<endl<<endl;
	cout<<">";
	}
	
	bool EndGame() {
		cout << "Awww! Goodbye then! I hope to play with you again soon!"<<endl<<endl;
		cin.get();
		//break PlayGame();
		return false;
	}
	
bool GameOverScreen()
	{
	cout<<endl;
	cout << "\nYay! I got it right!" <<endl<<endl;
	cout<<"That was fun "<<name <<"! ^_^\n\nDo you wanna play again?"<<endl<<endl;
	cout << ">";
	cin>>input;

	if(input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!") return true;
	else if (input == "No") return EndGame();
	}
	
void GetInput()	{
	cin>>input; // Read something from the keyboard
	
	// Act on input:
	if(input == "L" || input == "l" || input == "Lower" || input == "lower") upperBound = myGuess;
		else if (input == "H" || input == "h" || input == "Higher" || input == "higher") lowerBound = myGuess;
		else if (input == "Y" || input == "y" || input == "Yes" || input == "yes" || input == "Yes!" || input == "yes!") GameOverScreen();
		else if (cout<< "I'm sorry! I didn't understand that!"<<endl<<endl);
		}

bool PlayGame() {
	ShowStory(); // Show the game story
	
	ResetGame(); // Reset all variables to original values

	while(input != Yes) { // This is the main game loop
		UpdateWorld();
	
		DrawGraphics();
	
		GetInput();
		
		if(input == "Yes") return false;
		}
	
	return GameOverScreen();
	}

int main() {
if(Hiya()) // While they say they want to play
{
	while(PlayGame());	// repeatedly run the game loop
	}
return 0;
}
