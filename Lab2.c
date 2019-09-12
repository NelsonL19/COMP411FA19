#include <stdio.h>

int main( int argc, char** argv ) {

	printf("Hello and Welcome to Bubble Sort!\n");
    int arrLength;
    arrLength = 0;
    
    while (arrLength < 2 || arrLength > 10) {
        if (arrLength < 2 || arrLength > 10){
            printf("Select a value between 2 and 10: \n");
            scanf("%d", &arrLength);
        }

         if (arrLength < 2 || arrLength > 10){
            printf("Unsupported Value, please select a new one!\n");
        }

    }

    int arrSort[arrLength]; 

    for (int i = 0; i < arrLength; i++) {
        printf("Select a value for Array Position ");
        printf("%d", i);
        printf("\n");

        scanf("%d", &arrSort[i]);
    }



   for (int i = 0; i <= arrLength - 2; i++) {
    for (int j = 0; j <= arrLength - 2 - i; j++) {

        if (arrSort[j+1] < arrSort[j]) {
            int sort1;
            int sort2;

            sort1 = arrSort[j];
            sort2 = arrSort[j+1];

            arrSort[j] = sort2;
            arrSort[j+1] = sort1;

        }

    }
   } 

   printf("The entered values sorted in non-decreasing order are: \n");
   for (int i = 0; i < arrLength; i++) {
    printf("%d", arrSort[i]);

    if (i < arrLength -1){
    printf(", ");
    }


   }

    printf("\n");


   printf("Thank you for Sorting, Goodbye!\n");
	return 0;

}
