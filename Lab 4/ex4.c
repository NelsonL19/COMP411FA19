#include<stdio.h>
#include<stdlib.h>

#define DEBUG 1

typedef struct {
    
    char* first;
    char* last;
    int age;
    int sex;    // 0 = male, 1 = female, 2 = both :)

} p_struct;

void pass_by_ref( int* p_a );
void pass_by_value( int a );

void print_person_ref( p_struct* p_person );
void print_person_val( p_struct person );


int main( int argc, char** argv ) {

    // in C all variables should be declared at the beginning of the function (including main)
    
    p_struct person; // create a struct variable: p_person is data type, person is variable person

    
    char first[10]; 
    
    first[0] = 'b';
    first[1] = 'r';
    first[2] = 'e';
    first[3] = 'n';
    first[4] = 't';
    first[5] = '\0'; 

    char last[10] = {'m','u','n','s','e','l','l','\0'};

    person.first = first;
    person.last = last;
    person.age = 44;
    person.sex = 0;

    print_person_val( person );
    print_person_ref( &person );
    print_person_val( person );

    pass_by_value( person.age );
    pass_by_ref( &person.age );
    pass_by_value( person.age );

    return 0;

} // end main function

void pass_by_ref( int* p ) {

    (*p)+=2;

    printf("val = %d\n", (*p) );

}

void pass_by_value( int val ) {

    val+=2;

    printf("val = %d\n", val );

}

void print_person_val( p_struct person ) {


    printf("-----------------------------------------------\n");

    person.age = person.age++;
    person.first = "brett";

    printf("first %s, last %s, first initial %c, age %d, ", person.first, person.last, person.first[0], person.age );

    if ( person.sex == 0 )

        printf("male\n");

    else

        printf("female\n");

}

void print_person_ref( p_struct* p_person ) {


    printf("-----------------------------------------------\n");

    // p_person->first[3] = 't';
    p_person->age = 99;

    printf("first %s, last %s, first initial %c, age %d, ", p_person->first, p_person->last, p_person->first[0], p_person->age );

    if ( p_person->sex == 0 )

        printf("male\n");

    else

        printf("female\n");

}