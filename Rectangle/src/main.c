#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double height = 10.5, width = 20.7;
    double perimeter = 0;
    double area = 0;
 
    printf("arg0 is %s\narg1 is %s\narg2 is %s\n", argv[0], argv[1], argv[2]);
 
    if (argc == 3) {
        char *endptr;
        
        height = strtod(argv[1], &endptr);
        if(*endptr != '\0') {
            printf("Invalid double: %s\n", argv[1]);
            return 1;
        }
        
        width = strtod(argv[2], &endptr);
        if(*endptr != '\0') {
            printf("Invalid double: %s\n", argv[2]);
            return 1;
        }
    }
    
    perimeter = (height + width) * 2;
    area = height * width;
    
    printf("The perimeter of a rectangle with height %.2f and width %.2f is %.2f\n", height, width, perimeter);
    printf("The area of a rectangle with height %.2f and width %.2f is %.2f\n", height, width, area);
}
