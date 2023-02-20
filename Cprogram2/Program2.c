/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Jared Harrington
 */

#include <stdio.h>

const int point_amounts[5] = {8,7,6,3,2};

void possiblepoints(int sum, int jumper, int breakdown[5]) {
    int points;
    int max;
    int temp1;
    int temp2;

    if (jumper > 4) {
        if (sum == 0) {
            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", breakdown[0], breakdown[1], breakdown[2], breakdown[3], breakdown[4]);
        }
        return;
    }
    points = point_amounts[jumper];
    max = sum / points;
    for (int num=max; num>=0; --num) {
        temp1 = num * points;
        temp2 = sum - temp1;
        breakdown[jumper] = num;
        possiblepoints(temp2, jumper + 1, breakdown);
    }
    

}

int main() {
    int breakdown[5];
    int score;
    printf("Enter 0 or 1 to Stop\n");
    printf("Enter an NFL score: ");
    scanf("%d", &score);
    
    if (score <= 1) {
        return 0;
    }

    printf("\n\nPossible combinations of scoring plays:\n");
    possiblepoints(score, 0, breakdown);
    return 0;
}