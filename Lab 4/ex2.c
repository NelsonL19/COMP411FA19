#include<stdio.h>
#include<stdlib.h>

#define DEBUG 1

typedef struct {
    
    char* first;
    char* last;
    int age;
    int sex;    // 0 = male, 1 = female, 2 = both :)

} p_struct;

// ---------------------------------
// defining function proto-types. Basically, the name of the function,
// what does it return (in this case nothing, i.e. void), and what are 
// the data types of each argument (in this case one argument that is 
// a p_struct pointer )

void print_person( p_struct* );


int main( int argc, char** argv ) {

    // in C all variables should be declared at the beginning of the function (including main)

    char* first = malloc( sizeof(char)*10);
    first[0] = 'b';
    first[1] = 'r';
    first[2] = 'e';
    first[3] = 'n';
    first[4] = 't';
    first[5] = '\0';    // '\0' this indicates where the string is terminated
    
    p_struct person; // create a struct variable: p_person is data type, person is variable person

    person.first = first;
    person.last = "munsell";
    person.age = 44;
    person.sex = 0;

    // --------------------
    // let's use our function
    // 
    // why do we use an ampersand (&)?

    print_person( &person );

    // why is the first name character change preserved in our struct
    // after the function returns?
    printf("first %s ... hmmmm ....\n", person.first);

    free( person.first );
    
    return 0;

} // end main function

// now, let's define (implement) our function prototype
// Question, what is the p_struct argument pointing at (data/location)?
void print_person( p_struct* p_person ) {


    printf("-----------------------------------------------\n");

    // why do we use '->'' and not '.' here?
    printf("first %s, last %s, first initial %c, age %d, ", p_person->first, p_person->last, p_person->first[0], p_person->age );

    if ( p_person->sex == 0 )

        printf("male\n");

    else

        printf("female\n");

    p_person->first[3] = 't';

    printf("first %s, last %s\n", p_person->first, p_person->last);

}