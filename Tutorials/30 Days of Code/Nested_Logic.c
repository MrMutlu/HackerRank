#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int day1, month1, year1, day2, month2, year2;
    int fine = 0;
    scanf("%d %d %d", &day1, &month1, &year1);
    scanf("%d %d %d", &day2, &month2, &year2);

    if(year1 == year2)
    {
        if(month1 <= month2)
        {
            if (day1 <= day2) {
                fine = 0;
            }
            else {
                fine = 15 * abs(day1 - day2);
            }
        }
        else {
            fine = 500 * abs(month2 - month1);
        }
    }
    else if (year1 < year2) {
        fine = 0;
    }
    else {
        fine = 10000;
    }
    
    printf("%d", fine);
    
    return 0;
}

