#include <stdio.h>

int main( int argc, char** argv ) {

    printf("Please Select a Shape!\n");
    printf("1: Circle\n");
    printf("2: Rectangle\n");
    printf("3: Triangle\n");
    



    int i;
    scanf("%d", &i);
    
    switch (i) {
        case 1:
            printf("You Selected Circle\n");
            printf("Please insert a Radius!\n");
            double r;
            scanf("%lf", &r);
            
            double areaCircle = r * r * 3.14;
            printf("The Area of your Circle is: %.1f\n", areaCircle);

            break;


            
        case 2:
            printf("\nYou Selected Rectangle\n");
            
            printf("Please insert a Length!\n");
            double l;
            scanf("%lf", &l);
            
            printf("Please insert a Width!\n");
            double w;
            scanf("%lf", &w);

            double areaRectangle = l * w;
            printf("The Area of your Rectangle is: %.1f\n", areaRectangle);
            break;
            
        case 3:
            printf("\nYou Selected Triangle\n");
            
            double b;
            printf("Please insert a Base!\n");
            scanf("%lf", &b);

            double h;
            printf("Please insert a Height!\n");
            scanf("%lf", &h);
            
            double areaTriangle = 0.5 * b * h;
            printf("The Area of your Triangle is: %.1f\n", areaTriangle);
            break;
            
        default:
            printf("Please Select a Integer from 1 to 3!\n");
            break;
    }
    
    printf("Thank you, See you Later!\n");
    printf("\n");



	return 0;
	
}

