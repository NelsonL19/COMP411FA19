// only the stdio.h header file is allowed in this lab
#include<stdio.h>

int main( int argc, char** argv ) {
	// Lab 3 - have fun!

printf("Hello and Welcome to drome, the Palindrome!\n");
printf("Enter a String between 2 and 10 characters:\n");

char input[11];
scanf("%10s", input);
int length = -1; 
for (int i = 0; i < 11; i++) {
	if (i < 2) {
		if (input[i] == '\0') {
		printf("The inserted string is less than two characters, please retry:\n");
		scanf("%10s", input);
		i = -1;
	}

	}

}
	

for (int i = 0; i < 11; i++) {
	if (input[i] != '\0') {
		length++;
	}
	
	if (input[i] =='\0') {
		i = 20;
	}
	
}



printf("The Entered String is: ");
	printf("%s",input);		
	printf("\n");


while ((getchar()) != '\n');
//This is clearing out the input buffer



char replace; 
printf("Do you wish to replace a character in your string (y/n):\n");
scanf("%c", &replace);


if (replace == 121) {

while ((getchar()) != '\n');
//This is clearing out the input buffer


printf("What current character are you trying to replace:\n");
char replc; 
scanf("%c", &replc);


printf("What new character would you like to replace:\n");

while ((getchar()) != '\n');
//This is clearing out the input buffer

char newc; 
scanf("%c", &newc);


//Replacement Loop

for (int i = 0; i < 11; i++) {

	if (replc == input[i]) {
		input[i] = newc;
	}

}

}


//Palindrome Check

int r = length;
int palin = 1;

for (int i = 0; i < length; i++) {
	 if (input[i] != input[r]) 
        { 
         palin = 0;
         

        } 

        r--;
 } 


// Final Print Statements

if (palin == 1) {
	printf("This String is a Palindrome: ");
	printf("%s",input);		
	printf("\n");
} else {
	printf("This String is not a Palindrome: ");
	printf("%s",input);		
	printf("\n");
}


printf("Have a Good Day!\n");
	return 0;
}
