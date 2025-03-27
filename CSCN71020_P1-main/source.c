#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "source.h"

#define M_PI 3.142
#define EPSILON 1e-6

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

    if (scanf("%lf, %lf, %lf", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
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

//calculate distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

//checks if the 4 sides form a rectangle using rounding
int is_rectangle(double p1, double p2, double p3, double p4, double diag1, double diag2) {
    double epilson = 1e-6;
    return (fabs(p1 - p3) < epilson &&
        fabs(p2 - p4) < epilson &&
        fabs(diag1 - diag2) < epilson);

}

// Check if all points are in a straight line
int is_straight_line(double x[], double y[]) {
    if ((fabs(x[0] - x[1]) < EPSILON && fabs(x[1] - x[2]) < EPSILON && fabs(x[2] - x[3]) < EPSILON) ||
        (fabs(y[0] - y[1]) < EPSILON && fabs(y[1] - y[2]) < EPSILON && fabs(y[2] - y[3]) < EPSILON)) {
        printf("The points are in a straight line and do not form a rectangle.\n");
        return 1; // Indicates a straight line issue
    }
    return 0; // Points are not in a straight line
}

// Check for duplicate points
int has_duplicate_points(double x[], double y[]) {
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (fabs(x[i] - x[j]) < EPSILON && fabs(y[i] - y[j]) < EPSILON) {
                printf("Duplicate points detected at (%.2f, %.2f). Each point must be unique.\n", x[i], y[i]);
                return 1; // Duplicate found
            }
        }
    }
    return 0; // No duplicates
}

// sort points in the correct order
void sortRectangle_point(double x[], double y[]) {
    double minX = x[0], minY = y[0], maxX = x[0], maxY = y[0];
    for (int i = 1; i < 4; i++) {
        if (x[i] < minX) minX = x[i];
        if (x[i] > maxX) maxX = x[i];
        if (y[i] < minY) minY = y[i];
        if (y[i] > maxY) maxY = y[i];
    }

    //assign sorted points
    x[0] = minX; y[0] = minY; //bottom left
    x[1] = maxX; y[1] = minY; //bottom right 
    x[2] = maxX; y[2] = maxY; //top right
    x[3] = minX; y[3] = maxY; //top left

}

//get the users input for 4 points and determine if they form a rectangle
void get_rectangle_input() {
    double x[4], y[4];

    printf("Enter four points (x y) in the following order:\n");
    printf("Point 1: Bottom-left corner\n");
    printf("Point 2: Bottom-right corner\n");
    printf("Point 3: Top-right corner\n");
    printf("Point 4: Top-left corner\n");
    printf("Please enter each point as an x y pair (e.g., '2 3' for x=2, y=3):\n");

    for (int i = 0; i < 4; i++) {
        while (1) {
            printf("Point %d: ", i + 1);
            if (scanf("%lf %lf", &x[i], &y[i]) != 2) {
                printf("Invalid input. Enter valid coordinates in the format 'x y'.\n");
                while (getchar() != '\n');//clear input buffer
                continue;
            }
            break;
        }
    }

    // Check for duplicate points
    if (has_duplicate_points(x, y)) {
        return; // Stop execution if duplicates exist
    }

    // Check if points are in a straight line
    if (is_straight_line(x, y)) {
        return; // Stop execution if points form a straight line
    }

    //calculate distances of sequential points
    double p1 = distance(x[0], y[0], x[1], y[1]);
    double p2 = distance(x[1], y[1], x[2], y[2]);
    double p3 = distance(x[2], y[2], x[3], y[3]);
    double p4 = distance(x[3], y[3], x[0], y[0]);

    //calculate diagonals
    double diag1 = distance(x[0], y[0], x[2], y[2]);
    double diag2 = distance(x[1], y[1], x[3], y[3]);

    //calculate perimeter
    double perimeter = p1 + p2 + p3 + p4;
    printf("Perimeter of the shape: %.2f\n", perimeter);

    if (is_rectangle(p1, p2, p3, p4, diag1, diag2)) {
        double area = p1 * p2;
        printf("The points form a rectangle. Area: %.2f\n", area);
    }
    else {
        printf("The points do not form a rectangle.\n");
    }

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
        case 3:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }


    }
    return 0;
}
