#include <stdio.h>

int AA[100];  		// linearized version of A[10][10]
int BB[100];  		// linearized version of B[10][10]
int CC[100];  		// linearized version of C[10][10]
int m;       		// actual size of the above matrices is mxm, where m is at most 10


/* ------- Function proto-types put here  ------------------
  You do not have to use functions, however, this maybe your opportunity
  to get some extra practice :) 
------------------------------------------------------------ */

int main() {

	/* ----------------------------------------
	  Algorithm for lab assignment.
	
	  1.  First, read m (the matrices will then be size mxm).
	  2.  Next, read matrix A followed by matrix B.
	  3.  Compute matrix product.  You will need triple-nested loops for this.
	  4.  Print the result, one row per line, with one (or more) space(s) between
	      values within a row.
	  5.  Exit.
	
	------------------------------------------ */

	// TODO: add code here

int userInputsWidthA[10];
int userInputsLengthA[10]; 
int userInputsWidthB[10]; 
int userInputsLengthB[10]; 


printf("%s\n", "Hello and welcome to the Matrix!");

while (m <= 0 || m > 10) {
	printf("%s\n", "Give me an integer to represent the size of each matrices, from 1 to 10");
	scanf("%d", &m);
}


printf("%s\n", "Give me values to represent the data in the first matrix rows elements");

for (int i = 0; i < m; i++) {
	scanf("%d", &userInputsWidthA[i]);
} 

printf("%s\n", "Give me values to represent the data in the first matrix columns elements");

for (int i = 0; i < m; i++) {
	scanf("%d", &userInputsLengthA[i]);
} 

//AA Creation

for (int i = 0; i < m; i++) {
	AA[i] = userInputsWidthA[i];
}

for (int i = 0; i < m; i++) {
	AA[m+i] = userInputsLengthA[i];
}


for (int i = 0; i < m*m; i++) {
	printf("%d", AA[i]);

	if (i % m != 0) {
		printf("\n"); 
	}

	printf(" "); 
}

printf("%s\n", "Give me values to represent the data in the second matrix rows elements");

for (int i = 0; i < m; i++) {
	scanf("%d", &userInputsWidthB[i]);
} 

printf("%s\n", "Give me values to represent the data in the second matrix columns elements");

for (int i = 0; i < m; i++) {
	scanf("%d", &userInputsLengthB[i]);
} 

//BB Creation

for (int i = 0; i < m; i++) {
	BB[i] = userInputsWidthB[i];
}

for (int i = 0; i < m; i++) {
	BB[m+i] = userInputsLengthB[i];
}







}

/* ------- Function definitions below ------------------ */