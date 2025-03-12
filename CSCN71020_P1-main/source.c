#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M_PI 3.142

// check if sides form a valid triangle 
int validTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// calculate angles of the triangle using cosine rule
void calculateTriangle_Angles(double a, double b, double c) {
    double x, y, z;
    x = acos((b * b + c * c - a * a) / (2 * b * c)) * (180 / M_PI);
    y = acos((a * a + c * c - b * b) / (2 * b * c)) * (180 / M_PI);
    z = 180 - x - y;

    printf("The triangle angles: x = %.4f, y = %.4f, z = %.4f\n", z, y, z);
}

void get_triangle_input() {
    double a, b, c;
    printf("Enter three values for the sides of a triangle(in the format 1, 2, 3): ");

    if (scanf("%lf, %lf, %lf", & a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
        printf("Invalid input! Enter positive numbers");
        exit(EXIT_FAILURE);
    }

    if (validTriangle(a, b, c)) {
        printf("The values entered are valid sides of a triangle.\n");
        calculateTriangle_Angles(a, b, c);
    }
    else {
        printf("The values entered are invalid sides of a triangle.\n");
    }

}

void get_rectangle_input() {

}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n1. Triangle Feature\n2. Rectangle Feature\n3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input!");
            exit(EXIT_FAILURE);
        }

        switch (choice) {
        case 1:
            get_triangle_input();
            exit(EXIT_FAILURE);
        case 2: 
            get_rectangle_input();
            exit(EXIT_FAILURE);
        default:
            printf("Invalid choice. Try again.\n");
        }
           
        
    }
    return 0;
}
