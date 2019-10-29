#include <stdio.h>

int AA[100];  		// linearized version of A[10][10]
int BB[100];  		// linearized version of B[10][10]
int CC[100];  		// linearized version of C[10][10]
int m;       		// actual size of the above matrices is mxm, where m is at most 10
int product; 


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

printf("%s\n", "Hello and welcome to the Matrix!");

while (m <= 0 || m > 10) {
	printf("%s\n", "Give me an integer to represent the size of each matrices, from 1 to 10");
	printf("%s", "m = ");
	scanf("%d", &m);
}


int passA;
int passB;

for (int i = 0; i < m*m; i++){
	printf("%s", "AA[" );
	printf("%d", i);
	printf("%s", "] = ");
	AA[i] = scanf("%d", &passA);

	printf("%s", "BB[" );
	printf("%d", i);
	printf("%s", "] = ");
	BB[i] = scanf("%d", &passB);
}

if (m == 1) {
	printf("\n");
	CC[0] = passA * passB;
	printf("%s", "CC[" );
	printf("%d", 0);
	printf("%s", "] = ");
	printf("%d", CC[0]);

		printf("\n");
		return(0);
}







for (int i = 0; i < m-1; i++) {
	for (int j = 0; j < m-1; j++) {
		for (int k = 0; k < m; k++) {
			product = product +(AA[i] * BB[k]);
		}
		CC[i] = CC[i] + AA[i+j] * BB[i+j+1];
	}
	CC[i] = product;	
}

printf("\n");

for (int i = 0; i < m*m; i++){
	printf("%s", "CC[" );
	printf("%d", i);
	printf("%s", "] = ");
	printf("%d", CC[i]);
	printf("\n");


}



}
/* ------- Function definitions below ------------------ */