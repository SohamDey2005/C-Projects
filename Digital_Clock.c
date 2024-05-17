#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void fill_time(char*, int);
void fill_date(char*);
int input_choice();
void clear_screen();

int main()
{
    char time[50], date[100];
    int choice = input_choice();  

    while(1)
    {
        fill_time(time,choice);
        fill_date(date);
        clear_screen();
        printf("\n--------------------------------------------------\n");
        printf("\nCurrent Time: %s\n",  time);
        printf("Date: %s\n",  date);
        printf("\nDeveloped by: SOHAM DEY \n");
        printf("\n--------------------------------------------------\n");
        sleep(1);
    }
    return 0;
}

void clear_screen() 
{
    #ifdef _WIN32
    {
        system("cls");
    }
    #else
    {
        system("clear");
    }
    #endif  
}

int input_choice()
{
    int choice;
    printf("\nChoose the time format: ");
    printf("\n1. 24 Hour Format");
    printf("\n2. 12 Hour Format (Default)");
    printf("\nMake a Choice (1/2): ");
    scanf("%d",&choice);
    return choice; 
}

void fill_time(char* buffer, int choice)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    if (choice == 1)
    {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    }
    else
    {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void fill_date(char* buffer)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, 100, "%A [%B %d %Y]", current_time);

}