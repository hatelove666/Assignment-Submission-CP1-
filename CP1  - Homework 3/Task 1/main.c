#include <stdio.h>
#include <stdbool.h>


int main(void) {
 
  char userInput[20]; 
int currentFloor = 0;  
// put the program in a while loop until the player wants to exit
  while (true) { 
    printf("You are on floor: %i\n", currentFloor);
    printf("Enter your destination (G, 1, 2, 3, 4, 5) or enter Q to exit the elevator: ");
        scanf("%s", userInput); 
/* checks if the second element in the userInput array is not null, that means that the user has entered more than one character and the
input is invalid(ex: asd, as, -3 (input is a string and thus -3 are 2 characters). Then goes back to ask for input again

*/
    if (userInput[1] != '\0') { 
      printf("Invalid input. Please enter a correct floor number or Q to exit the elevator.\n");
            continue; 
    }
// checks if the user entered Q and it breaks the loop, exits
// the elevator and prints a message.
    if (userInput[0] == 'Q') { 
      break;
    } 
  /*
  checks if the user entered G, and since the elevator starts
  at the 0 floor(ground floor) it prints a message that the elevator
  is already at the ground floor
  */
    else if (userInput[0] == 'G') { 
      if (currentFloor == 0) { 
         printf("You are already on the ground floor !!\n");
           continue; 
      }
         currentFloor = 0;
    } 
 /* If the player enteres a value between 1 and 5 it is considered a
 valid input since is only one character but we handle the other inputs
 who also consist one character(ex:8, s) in the else statment after where
 we just print an error message to the player to enter a valid input.
 We convert the input of the user to a compatible integer value by
 subtracting the ASCII value of '0' and store it in the destination variable.We use this variable to compare the currentFloor
 and the destionation floor. I used help from stack overflow
 to find this out because i couldn't figure out how to convert it.

 
 */
    else if (userInput[0] >= '1' && userInput[0] <= '5') { 
      int destination = userInput[0] - '0'; 
      if (destination == currentFloor) { 
        printf("You are already on floor %i !!\n", currentFloor);
           continue; 
      }
      currentFloor = destination;
    } else { 
        printf("Invalid input. Please enter a correct floor number or Q to exit the elevator.\n");
      continue;
    }

printf("Going to floor %i .........\n", currentFloor);
  }

       printf("You have successfully exited the elevator.\n");

  return 0;
}
