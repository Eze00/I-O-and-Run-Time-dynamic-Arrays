/*
 * assignment3.cpp
 *
 *  Created on: Feb 24, 2020
 *      Author: Ezedine Kargougou
 *      Description: this will take user inputs and depending on those inputs, will perform some
 *       			 calculations to it. It can also sort whether it's numbers or letters. it can
 *       			 also delete whatever letter the user wants it to delete.
 */

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


float calculateAverage(int* numberList, int size);
int oneD_Math();
int pickChoice();
int pickChoice2();
int singleD_charProcessing();
int twoD_charProcessing();
int medianFinder(int* arr, int size);
int unique_NoneUnique(int* arr, int size, int index);
int randomNumbers(int min, int max);
int getFrequencyOf(char* letters, int size, char item);
char getRandomChar();
void fillArray(char* letters, int size);
void removeCharacter(char* letters, int size, char item);
void sortArray(char* charArr, int size);
void sortArray2(int* intArr, int size);
void menu();

int main(int argc, char* argv[]){
	srand(time(0)); // This helps the games run smoothly. only needs to call it once, before the random generator function
	menu(); // this calls to the menu. From there, most of the program is ran
	return 0;
} // ends the main function

void menu(){
	int userInput;
	cout << "Welcome to Assignment 3!\nMenu:\n";
	cout << "1- 1D Match\n2- Single Dimension Character Processing\n3- Two-D Character Processing\n4- Exit\n";
	cout << "Choose an option: ";
	cin >> userInput;

	while ((userInput != 1 && userInput && userInput != 2 && userInput != 3 && userInput != 4) || userInput == 0 )
	{ // safety check for when user inputs an undesirable option
		cout << "\nInvalid input. Please choose from the following options:" << endl;
		cout << "1- 1D Match\n2- Single Dimension Character Processing\n3- Two-D Character Processing\n4- Exit\n";
		cout << "Choose an option: " << endl;
		cin >> userInput;
	} // ends the while loop

	if (userInput == 1){ // this takes the user to the first option
		oneD_Math();
	}else if (userInput == 2){ // this takes the user to the second option
		singleD_charProcessing();
	}else if (userInput == 3){ // this takes the user to the third option
		twoD_charProcessing();
	}else if (userInput == 4){ // this ends the program and prompts the user a goodbye message because we're nice like that
		cout << "Goodbye!" << endl;
	}
} // ends the menu function

int oneD_Math(){
	int *ezePointer; // the array that stores the chars
	// declaring the variable that i'll use in the methods
	float range;
	int arrSize;
	int min;
	int max;
	int median;
	int uniques = 0;
	int nonUniques = 0;
	// this is the values that will be passed to the dynamically allocated array

	cout << "Enter size: ";
	cin >> arrSize;
	cout << "Min: ";
	cin >> min;
	cout << "Max: ";
	cin >> max;

	ezePointer = new int[arrSize]; // sets the size equal to the user's need
	for (int i = 0; i < arrSize; i++){ // Initializing the array to contain null characters
		ezePointer[i] = '\0';
	}
	for (int i = 0; i < arrSize; i++) { // this sets the bounds of the array to the user's wishes
		*(ezePointer+i) = randomNumbers(min, max);
	}

	 sortArray2(ezePointer, arrSize);
	// adding to  the array
	cout << "[";
	for (int i = 0; i < (arrSize+1); i++){
		if (i == (arrSize - 1)){
			break;
		}
		cout << *(ezePointer + i) << " , ";
	}
	 // this gets the last index printed out and then adds the bracket
	cout << ( ezePointer[arrSize-1]);
	cout << "]";

	for(int i = 0; i <arrSize; i++)
	{
		if(unique_NoneUnique(ezePointer, arrSize, i)){  // if unique, the function returns 1 and increments it
			uniques++;
		}
		else{ // else, it just returns the non unique, or 0 and increments non Unique
			nonUniques++;
		}
	}// ends the for loop


	 range = calculateAverage(ezePointer, arrSize); // this calls the average method, calculate the average and returns it in float form
	 median =  medianFinder(ezePointer, arrSize); //ezePointer[arrSize/2];
	 cout << "\nAverage: " << range << endl;
	 cout << "Median: " << median << endl;
	 cout << "Uniques: " << uniques << endl;
	 cout << "Non-Uniques: " << nonUniques << endl;


	delete[] ezePointer; // deletes the pointer. frees up memory
	return 0;
} // end the oneD_Match method

void sortArray2(int* intArr, int size){// void because it doesn't need to return anything
	int tempInt;
	for (int i = 0; i < size; i++){
		for (int j = i +1; j < size; j++){
			if(intArr[i] > intArr[j]){ // this is where the comparison happens
				// this code is the swapping of the values
				tempInt = intArr[i];
				intArr[i] = intArr[j];
				intArr[j] = tempInt;
			}
		}
	}
}

int singleD_charProcessing(){
	char* ezePointer2; // this is the array that will hold char arrays
	//declaring the variable for this function
	char userPick;
	int userInput;
	int userChoice1;
	int returner;

	cout << "\nHow many characters? ";
	cin >> userInput;
	ezePointer2 = new char[userInput]; // dynamically allocated array that holds the user's input as the size
	for (int i = 0; i < userInput; i++){ // Initializing the array to contain null characters
		ezePointer2[i] = '\0';
	}


	// this code will print out the character array
	cout << "\nFilling the array!" << endl;
	fillArray(ezePointer2, userInput); // this calls the fillArray method, passes these information and gets a return array full of chars
	for (int i = 0; i < userInput; i++){ // this then prints said array
		cout << ezePointer2[i];
	}


    userChoice1 = pickChoice();
	while(userChoice1 != 4){
		if (userChoice1 == 1) {
			cout << "\nWhat letter? ";
			cin >> userPick;
			cout << "\nUser pick " << userPick << endl;
			returner = getFrequencyOf(ezePointer2, userInput,
					putchar(std::tolower(userPick))); // hard coded the user's letter to be lower case;
			// To display the array to the user
			for (int i = 0; i < userInput; i++) {
				cout << ezePointer2[i];
			}
			cout << "\nThere are ";
			cout << returner;
			cout << " of the letter " << userPick << endl;
		}


		else if (userChoice1 == 2) {
			int input2 = 0;
			do { // do while loop to keep asking the user if they want to keep removing letters
			cout << "\nWhat letter?";
			cin >> userPick;
			removeCharacter(ezePointer2, userInput,putchar(std::tolower(userPick))); // hard coded the user's letter to be lower case;
			for (int i = 0; i < userInput; i++) { // To display the array to the user
				cout << ezePointer2[i];
			}
			cout << "\n\nAfter removing the letter " << userPick << ":\n" << endl;
			for (int i = 0; i < userInput; i++) {
				cout << ezePointer2[i];
			}
			cout << "\nPress 1 to remove another letter and 0 if you would like to stop";
			cin >> input2;
			while ((input2 != 0 && input2 != 1) || input2 > 2)
			{
				cout << "\nPress 1 to remove another letter and 0 if you would like to stop";
				cin >> input2;
			}
			}
			while(input2 == 1);

			 if(input2 == 0){
				// code it to go to the main menu
				menu();
			}
		}


		else if (userChoice1 == 3) {
			cout << "\nSorting!" << endl;
			sortArray(ezePointer2, userInput);
			for (int i = 0; i < userInput; i++) { // To display the array to the user
				cout << ezePointer2[i];
			}
		}


		userChoice1 = pickChoice();

	} // end of the while loop
	return 0;
} // end of the method

int twoD_charProcessing(){
	char** bigArr;
	int arrLength=0;
	int stringSize=0;
	int userChoose = 0;

	cout << "\nHow many strings do you want to enter? ";
	cin >> arrLength;
	cout << "\nWhat is the max size of the string? ";
	cin >> stringSize;
	bigArr = new char*[arrLength];

	for(int i = 0; i < arrLength; i++){
		bigArr[i] = new char[stringSize];
		// Initializing the array to contain null characters
		for (int j = 0; j < stringSize; j++){
			bigArr[i][j] = '\0';
		} // inner for loop ender
	}// outer for loop ender


	string storer;
	getline (cin, storer); // stores the first string. this way, it won't skip the first string
	// setting chars to the array
	for (int i = 0; i < arrLength; i++) {
		cout << "Enter string " << i + 1 << " : ";
		getline (cin, storer); // stores the second string and then iterate and stores the remaining
		for (int j = 0; j < stringSize; j++){
			bigArr[i][j] = storer[j];
		}
	}

	userChoose = pickChoice2();
	char item;
	while (userChoose != 3)
	{
		if(userChoose == 1){
			cout << "\nWhat letter? ";
			cin >> item;
			for(int i = 0; i < arrLength; i++){
				int tracker = 0; // tracker and it increases every time there is a repeated number
				tracker += getFrequencyOf(bigArr[i],stringSize, item);
				cout <<bigArr[i] << " - " << tracker << endl;
			}
			userChoose = pickChoice2();
		}

		else if(userChoose == 2){
			cout << "\nWhat letter? ";
			cin >> item;
			for(int i = 0; i < arrLength; i++){
				removeCharacter(bigArr[i],stringSize, item); // this calls the method and removes whatever matches with the item
				cout <<bigArr[i] << endl; // outputs the results
			}
			userChoose = pickChoice2();
		}

		else if(userChoose == 3){ // deletes the array and moves on to the main menu
			for(int j = arrLength-1; j >= 0; j--){
				delete[] bigArr[j];
			}
			delete[] bigArr;
			menu();
		}

	}

	userChoose = pickChoice2();

	// deletes the array
	for(int j = arrLength-1; j >= 0; j--){
		delete[] bigArr[j];
	}
	delete[] bigArr;
	return 0;
}

// random number generator
int randomNumbers(int min, int max){
	int randNumb;
	randNumb = (rand() % (max - min + 1)) + min;
	return randNumb;
}

float calculateAverage(int* numberList, int size){
	// just adds the numbers up together and at the end, divides it by the size
	float sum = 0.0000;
	float average = 0.0000 ;
	for (int i = 0; i < size; i++) {
		sum += *(numberList + i);
	}
	average = sum / size;
	return average;
  }

char getRandomChar(){
	string alphabet = "abcdefghijklmnopqrstuvwxyz"; // every possible alphabet
	int rand = randomNumbers(0, 25);
	return alphabet[rand];
}

void fillArray(char* letters, int size){
	for (int i = 0; i < size; i++) {
		letters[i] = getRandomChar(); // iterating through however much the size is and filling them with random letters
	}
}

int getFrequencyOf(char* letters, int size, char item){ // every time there is a letter that matches with the letter the user wants, it increments
	int numbOfMatch = 0;
	for (int i = 0; i < size; i++) {
		if (letters[i] == item) {
			numbOfMatch++;
		}
	}
	return numbOfMatch;
}

void removeCharacter(char* letters, int size, char item){
	// iterating thru the size
	for (int i = 0; i < size; i++) {
		while (letters[i] == item) { // every time there's a match with the user's letter
			int j;
			for (j = i + 1; j < size; j++) { // go to the next address and move one back
				letters[j - 1] = letters[j];
			}
			letters[j - 1] = '\0'; // set the last index to null
		}
	}
}

// shell short that sorts the characters
void sortArray(char* charArr, int size){// void because it doesn't need to return anything
	char tempChar;
	int charSpace;
	int j;
	for (charSpace = (size/2); charSpace > 0; charSpace = (charSpace/2)) { // divides the size by 2 and will keep doing so as long as the character doesn't equal 0
		for (int i = charSpace; i < size; i++){ // i will equal the character and will store whatever is in that address into a temporary character
			 tempChar = charArr[i];
			 /* the j must equal the i  but must either be equal to the character and the index at j minus that char must be greater the the value of the
			  temporary character. inside the loop you set index j equal to the index of j minus the character. then outside the outer for loop but still inside the
			  loop the array at index j equals the temporary character from the first for loop */
			for (j = i; j >= charSpace && (charArr[j-charSpace] > tempChar); j =(j-charSpace)){
				charArr[j] = charArr[j-charSpace];
			}
			charArr[j] = tempChar;
		}
	}
}

int unique_NoneUnique (int* arr, int size, int index){
	for(int i= 0; i < index; i++){
		if(i != index && arr[index] == arr[i]){ // when i and the index match and their values match it returns a zero
			return 0;
		}
	}
	return 1;
}

int pickChoice(){ // this functions seems useless but it helps me take the user back to the menu
	int userChoice;
	cout << "\n\nWhat would you like to do? ";
	cout << "\n1.\tCheck frequency of a letter\n2.\tRemove a letter\n3.\tSort\n4.\tReturn to Main Menu" << endl;
	cout << ">> ";
	cin >> userChoice;

	while (userChoice != 1 && userChoice != 2 && userChoice != 3&& userChoice != 4) { // safe-check for when the user enters undesired inputs
		cout << "\nInvalid input. Please choose from the following: " << endl;
		cout << "1.\tCheck frequency of a letter\n2.\tRemove a letter\n3.\tSort\n4.\tReturn to Main Menu" << endl;
		cout << ">> ";
		cin >> userChoice;
	}

	// just takes the user all the way back to the main menu
	if (userChoice == 4) {
		menu();
	}

	// this return helps the singleD_charProcessing. it feeds it what the user wants to do next
	return userChoice;
}

int medianFinder(int* arr, int size){ // finds the median. just returns the divided size of the array by 2
	int theMedian;
	theMedian = arr[size/2]; // takes the size and divides it by 2
	return theMedian;
}

int pickChoice2(){
	int chooser;
	cout << "what would you like to do?";
	cout << "\n1.\tCheck frequency of a letter\n2.\tRemove a letter\n3.\tReturn to Main Menu\n>>? ";
	cin >> chooser;
	while(chooser != 1 && chooser != 2 && chooser != 3){ // safety check for when the user inputs an undesired option
		cout << "\nIncorrect input. Please choose from the following:" << endl;
		cout << "\n1.\tCheck frequency of a letter\n2.\tRemove a letter\n4.\tReturn to Main Menu\n>>? ";
		cin >> chooser;
		if(chooser == 4){ // if the input is three then it takes the user to the main menu
			menu();
		}
	} // while ender
	return chooser;
}



