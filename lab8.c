#include<stdio.h>

// global variable
char pattern[32] = {0};

// function prototype
void bingen(unsigned int n, unsigned int N );


int main( int argc, char** argv ) {

		unsigned int N = 0;
		// in this lab you can assume the user enters
		// a positive number that is less than 32.
		// that is, no error checking is necessary
		printf( "Enter the number of bits (N): ");
		scanf("%u", &N );

		unsigned int n = N;
		pattern[N+1] = '\n'; // Null terminate the string
		bingen( n, N );

		return 0;

} // end main 


// implementation of prototype
void bingen( unsigned int n, unsigned N ) {

	if ( n > 0 ) {

        pattern[N-n] = '0';
        bingen( n - 1, N );

        pattern[N-n] = '1';
        bingen( n - 1, N );

    } else printf( "%s\n", pattern );

} // end bingen