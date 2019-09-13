#include<stdio.h>
#include<stdlib.h>

#define DEBUG 1

// -------------------
// Before they had classes and all these fancy data structures
// the c-style struct (short for structure) was the goto data 
// structure. It's very simple, it's like a table that has fields
// that store data. In this case the person structure has four 
// fields: first, last, age and sex.
// 
typedef struct {
    
    char* first;
    char* last;
    int age;
    int sex;    // 0 = male, 1 = female, 2 = both :)

} p_person;


int main( int argc, char** argv ) {

    // in C all variables should be declared at the beginning of the function (including main)

    int i;
    
    p_person person; // create a struct variable: p_person is data type, person is variable person


    // ------------------------------------------------
    // dynamically allocate memeory to store a 10 element character array
    // where is memory allocated by the malloc function (stack/heap)?
    // where is the char pointer (char*) stored (stack/heap)?
    char* first = malloc( sizeof(char)*10);
    first[0] = 'b';
    first[1] = 'r';
    first[2] = 'e';
    first[3] = 'n';
    first[4] = 't';
    first[5] = '\0';    // '\0' this indicates where the string is terminated

    // ---------------------------
    // Quick question ... how would be create an array that holds 10 p_person elements ??

    printf("-----------------------------------------------\n");

    // ----------------------------
    // why does this not print 5?
    // what does it print, and why ... hmmmm ... interesting??
    // this is a very common mistake made by programmers
    printf("Number of elements in first array = %lu\n", sizeof(first)); 

    // what is printed for index positions past the null terminator?
    for ( i=0; i<10; i++ ) printf("first[%d]=%c\n", i, first[i] ); 

    // ----------------------------
    // let's use our data structure
    person.first = first;
    person.last = "munsell";
    person.age = 44;
    person.sex = 0;

    printf("-----------------------------------------------\n");

    if ( person.sex == 0 )

        printf("first %s, last %s, first initial %c, age %d, male\n", person.first, person.last, person.first[0], person.age );

    else

        printf("first %s, last %s, first initial %c, age %d, female\n", person.first, person.last, person.first[0], person.age);

    person.first[3] = 't';

    printf("first %s\n", person.first);

    // -----------------------------------
    // Concept of a pointer
    // -----------------------------------
    // pointer "points" to a memory location (not the actual value)
    // you may de-reference the pointer (*p) to manipulate the value (weird, right?)

    printf("-----------------------------------------------\n");

    int* p = malloc(sizeof(int));
    int* pp;

    printf("(p) Memory Location [%p] has value = %d\n", p, (*p));

    (*p)=42;

    printf("(p) Memory Location [%p] has value = %d\n", p, (*p));

    (*p)++;

    printf("(p) Memory Location [%p] has value = %d\n", p, (*p));

    pp = p;

    (*pp)++;

    printf("(pp) Memory Location [%p] has value = %d\n", pp, (*pp));
    printf("(p) Memory Location [%p] has value = %d\n", p, (*p));

    // What do you think p++ is doing ???

    // -----------------------------------
    // Open a file and loop through each line
    // -----------------------------------

    printf("-----------------------------------------------\n");

    FILE* fhnd;

    fhnd = fopen( "test.txt", "r" );

    char line[50];

    if ( fhnd != NULL ) {

        while ( fgets( line, sizeof(line), fhnd ) != NULL ) {

            if ( DEBUG ) printf( "%s", line );

        }

    }

    fclose( fhnd );

    // since I malloc'd these variables, I'm responsible for releasing the memory
    // i.e. no garbage collector in the c-language.
    free( first );
    free( p );

    return 0;

} // end main function