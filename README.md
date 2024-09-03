#include <stdio.h>

int main (void)
{
    // insert code here...
    int day,month,year;

    printf("Enter Year, Month and Day as YYYY,M,DD\n");

    scanf("%4d%d%2d", &year, &month, &day);

    if (year >= 1901 && year <= 2299 &&
        month >= 1 && month <= 12 &&
        day >= 0 && day <= 31)
    {
        int century = year/100;

        /* making a century table for calculation*/

        switch(century)
        {
            case 19:
                century=0;
                break;
            case 20:
                century=6;
                break;
            case 21:
                century=4;
                break;
            case 22:
                century=2;
                break;
        }

        int last2_of_year= year % 100;

        /* Last 2 digits of the year entered*/

        int last2_div_4 =  last2_of_year/4;

        switch (month)
        {
            case 1:
                month=0;
                break;

            case 2:
                month=3;
                break;
            case 3:
                month=3;
                break;
            case 4:
                month=6;
                break;
            case 5:
                month=1;
                break;
            case 6:
                month=4;
                break;
            case 7:
                month=6;
                break;
            case 8:
                month=2;
                break;
            case 9:
                month=5;
                break;
            case 10:
                month=0;
                break;
            case 11:
                month=3;
                break;
            case 12:
                month=5;
                break;
         }


        int total_num = (century+ last2_of_year +day +month +last2_div_4)%7;

        switch (total_num) 
        {
            case 0:
            printf("Sunday");
                break;
            case 1:
            printf("Monday");
                break;
            case 2:
            printf("Tuesday");
                break;
            case 3:
            printf("Wednesday");
                break;
            case 4:
            printf("Thursday");
                break;
            case 5:
            printf("Friday");
                break;
            case 6:
            printf("Saturday");
                break;
        }

        printf("%d ,%d, %d, is a %d", year,month,day,total_num);
        }
        else
        {
            printf("invalid\n");
        }



    return 0;

    }
