// Simple C program to draw a rotating square withough using GLUT


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PI 3.14159265358979323846

// Function to draw a square
void drawSquare(int x, int y, int length, int angle)
{
    // Calculate the coordinates of the square
    int x1 = x + length * cos(angle * PI / 180);
    int y1 = y + length * sin(angle * PI / 180);
    int x2 = x1 + length * cos((angle + 90) * PI / 180);
    int y2 = y1 + length * sin((angle + 90) * PI / 180);
    int x3 = x2 + length * cos((angle + 180) * PI / 180);
    int y3 = y2 + length * sin((angle + 180) * PI / 180);
    int x4 = x3 + length * cos((angle + 270) * PI / 180);
    int y4 = y3 + length * sin((angle + 270) * PI / 180);

    // Draw the square
    printf("\033[%d;%dH", y, x);
    printf("\033[1;31m");
    printf("x");
    printf("\033[%d;%dH", y1, x1);
    printf("\033[1;31m");
    printf("x");
    printf("\033[%d;%dH", y2, x2);
    printf("\033[1;31m");
    printf("x");
    printf("\033[%d;%dH", y3, x3);
    printf("\033[1;31m");
    printf("x");
    printf("\033[%d;%dH", y4, x4);
    printf("\033[1;31m");
    printf("x");
}

// Driver code
int main()
{
    // Clear the screen
    system("clear");

    // Draw the square
    int x = 10, y = 10, length = 10, angle = 0;
    while (1) {
        drawSquare(x, y, length, angle);
        angle += 1;
        usleep(100000);
        system("clear");
    }

    return 0;
}

