#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> /* this library makes macros true and false
so we can use them instead of using 1 and 0 which makes the code less
readable
*/ 
#include <string.h> /* helps with comparing strings and other useful
stuff regarding strings
*/

#define numOfWords 10
#define maxLengthOfWord 25
#define numOfMaxIncorrectGuesses 6


const char* words[numOfWords] = {
  "chair",
  "alphabet",
  "twitch",
  "cow",
  "pinterest",
  "water",
  "university",
  "twitter",
  "gym",
  "notebook"
};

void printHangman(int numOfIncorrectGuesses) {
    /*
    printed is a boolean value that i initialized
    to false. the if statement below check if the printed value
    is false (!printed) and then the if statements run. the if statement
    prints the starting part of the hangman once and at the end of it
    i set the printed value to true so the code doesn't run more than
    once.
    Since printed is static, it stays true even on the next function
    call so if i call the function again somewhere the starting part of the hangman won't be printed but just the body parts.
    As I tried to play with it I can't make it to work and the
    hangman gets printed every time without the starting parts:(
    
    */
  static bool printed = false;
  if (!printed) {
    printf(" _________\n");
    printf(" |/      |\n");
    printed = true;
  }

  printf(" |      %s\n", numOfIncorrectGuesses > 0 ? " O" : " ");
  printf(" |     %s%s%s\n", numOfIncorrectGuesses > 2 ? "/" : " ", numOfIncorrectGuesses > 1 ? "|" : " ", numOfIncorrectGuesses > 3 ? "\\" : " ");
  printf(" |      %s\n", numOfIncorrectGuesses > 4 ? "|" : " ");
  printf(" |     %s %s\n", numOfIncorrectGuesses > 5 ? "/" : " ", numOfIncorrectGuesses > 6 ? "\\" : " ");
  printf("_|___ %s\n", numOfIncorrectGuesses == 7 ? "\\" : " ");
}




int main(void) {
  srand(time(NULL));
  const char* word = words[rand() % numOfWords]; // gets a random
                                                 // word from the array
  int wordLength = strlen(word); //strlen calculates the length of a                               string

  char guesses[30];
  int numOfGuesses = 0;
  int numOfIncorrectGuesses = 0;

  char showWord[60];  //we will use this array to show the word with                      underscores
  for (int i = 0; i < wordLength; i++) {
    showWord[i] = '_';
  }
  showWord[wordLength] = '\0'; // \0 is a null character 
                               //  indicates the end of a string
                               
                               
// loop the game until the user's incorrect guess is smaller than the max guesses allowed 
while (numOfIncorrectGuesses < numOfMaxIncorrectGuesses) {
  printHangman(numOfIncorrectGuesses);

  printf("Word: ");
  for (int i = 0; i < wordLength; i++) {
    printf("%c ", showWord[i]);
  }
  printf("\n");

  printf("Letters you have guessed: ");
  for (int i = 0; i < numOfGuesses; i++) {
    printf("%c ", guesses[i]);
  }
  printf("\n");
  printf("Enter a letter or directly guess the word: ");
/*
The code below
reads a letter from the user and stores it in the input array.

if statement checks if the length of the string is equal to 1, which 
means that the user has entered a letter If this is the 
case, the program assigns the first character in the input array to the 
letter variable.
The strchr function is used to search for the occurrance of the letter in the guesses array. If letter is found in guesses, the strchr function will return a value that is not NULL, and the code will print a message that the letter is already guessed and it will continue to the next iteration of the loop.
If the letter is not found in guesses, it will be added to the end of the guesses array and numberOfGuesses will be increased by 1. 
ex: lets say numbOfGuesses is 3 and letter is 'b'.
First it will asign the value of b at index 3 in the guesses array.
Then it will increment the numOfGuesses value by 1 so it becomes 4.
since ++ is a post increment operator.




*/
  char input[maxLengthOfWord];
  scanf("%s", input);

  if (strlen(input) == 1) {
    char letter = input[0];
    if (strchr(guesses, letter) != NULL) {
      printf("You have already guessed that letter.\n");
      continue;
    }

    guesses[numOfGuesses++] = letter;
/*
Checks if a letter a user types in is containted in the word, by
looping through all the chars seperatlely in the word and sets found
to true.
if it's not found (!found yields false) then the number of incorrect guesse is incremented by 1.
*/
    bool isfound = false;
    for (int i = 0; i < wordLength; i++) {
      if (word[i] == letter) {
        showWord[i] = letter;
        isfound = true;
      }
    }

    if (!isfound) {
      numOfIncorrectGuesses++;
    }
  } else {
   
/* then we use the following to code to take the case if the user enters a full word as a input and its not a letter. strcmp returns 0 if
both strings are equal and copies the word to showWord. In our case the user input and the word. If they are not the number of incorrect guesses is incremented(the lives of the player go down).
*/

    if (strcmp(input, word) == 0) {
      strcpy(showWord, word);
    } else {
      numOfIncorrectGuesses++;
    }
  }
// compares them if they are equal it yirelds 0 so we print a message
// that we won the game
  if (strcmp(word, showWord) == 0) {
    printf("Congrats! You won! The word was: %s.\n", word);
    return 0;
  }
}
// if the above if statments yields false then the below code is executed meaning it will print the hangman with the correct number of  numOfIncorrectGuesses and display a lose message.
printHangman(numOfIncorrectGuesses);
printf("Sorry:( ! You lost! The word was: %s.\n", word);
return 0;
}



