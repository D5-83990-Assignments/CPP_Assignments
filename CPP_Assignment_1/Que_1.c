#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate)
{
    ptrDate->day = 7;
    ptrDate->month = 3;
    ptrDate->year = 2024;
}

void printDateOnConsole(struct Date* ptrDate)
{
    printf("\n");
    printf("Date = %d/%d/%d",ptrDate->day,ptrDate->month,ptrDate->year);
    printf("\n\n");
}

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter the day : ");
    scanf("%d",&ptrDate->day);
    printf("Enter the month : ");
    scanf("%d",&ptrDate->month);
    printf("Enter the year : ");
    scanf("%d",&ptrDate->year);
}

int main()
{
    struct Date D1;
    int choice;
    initDate(&D1);
    do
    {
        printf("\n");
        printf("1. Accept Date\n");
        printf("2. Display Date\n");
        printf("0. EXIT\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            acceptDateFromConsole(&D1);
            break;

        case 2:
            printDateOnConsole(&D1);
            break;
        
        default:
            printf("Invalid.....\n");
            break;
        }
        
    }while(choice  != 0);

    return 0;
}