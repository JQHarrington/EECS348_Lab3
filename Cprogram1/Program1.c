/*
 * Program1.c
 *
 *  Created on: Feb 11, 2023
 *      Author: Jared Harrington
 */

#include <stdio.h>

const char months[12][10] = {
    "January", 
    "February", 
    "March",
    "April", 
    "May", 
    "June", 
    "July", 
    "August", 
    "September", 
    "October", 
    "November", 
    "December"
    };

void salesreport(const float *nums) {
    int num = 0;
    printf("Monthly sales report for 2022:\n");
    printf("\n%-10s\tSales\n\n", "Month");
    for (num = 0; num < 12; ++num) 
    {
        printf("%-10s\t$%.2f\n", months[num], nums[num]);
    }
}

void minimum(const float *nums) {
    float current = 0;
    float min = nums[0];
    int min_month = 0;
    
    for (int num=0; num<=11; ++num) {
        current = nums[num];
        if (current <= min) {
            min = current;
            min_month = num;
        }
    }
    printf("Minimum sales:\t$%.2f\t(%s)\n", min, months[min_month]);
}

void maximum(const float *nums) {
    float current = 0;
    float max = nums[0];
    int max_month = 0;
    
    for (int num=0; num<=11; ++num) {
        current = nums[num];
        if (current >= max) {
            max = current;
            max_month = num;
        }
    }
    printf("Maximum sales:\t$%.2f\t(%s)\n", max, months[max_month]);
}

void average(const float *nums) {
    float total = 0;

    for (int num=0; num<=11; ++num) {
        total = total + nums[num];
    }
    float avg = total / 12;
    printf("Average sales:\t$%.2f\n", avg);
}

void sixmonthaverage(const float *nums) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int a=0; a<=6; ++a) {
        float total = 0;
        for (int b=0; b<=5; ++b)
            total = total + nums[a+b];
        float avg = total / 6;
        printf("%-10s\t-\t%-10s\t($%.2f)\n", months[a], months[a+5], avg);
    }
}

void highest_lowest(const float *nums) {
    printf("\nSales Report(Highest to Lowest):\n");
    printf("\n%-10s\tSales\n\n", "Month");
    int sortedlist[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int temp = 0;
    int num = 0;
    
    for (int a=0; a<=11; ++a) {
        for (int b=0; b<11-a; ++b) {
            if (nums[sortedlist[b]] > (nums[sortedlist[b+1]])) {
                temp = sortedlist[b];
                sortedlist[b] = sortedlist[b+1];
                sortedlist[b+1] = temp;
            }
        }
    }
    
    for (int i=11; i>=0; --i) {
        num = sortedlist[i];
        printf("%-10s\t$%.2f\n", months[num], nums[num]);
    }
}

int main() {
    float nums[12] = {};
    

    FILE *fptr;

    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num = 0;
    while (!feof(fptr))
    {
        if (ferror(fptr))
        {
            printf("Error reading file.\n");
            return 1;
        }
        for (num = 0; num < 12; num++)
        {
            fscanf(fptr, "%f", &nums[num]);
        }
    }
    fclose(fptr);

    salesreport(nums);

    printf("\nSales Summary:\n");
    minimum(nums);
    maximum(nums);
    average(nums);
    
    sixmonthaverage(nums);

    highest_lowest(nums);

    return 0;
}