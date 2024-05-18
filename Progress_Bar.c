#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

const int Bar_Length = 100;
const int Max_Tasks = 10;

typedef struct
{
    int id;
    int progress;
    int step;
} Task;

void display_bar(Task t);
void clear_screen();

int main()
{
    Task tasks[Max_Tasks];
    srand(time(NULL));

    for (int i = 0; i < Max_Tasks; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = 0;
    }

    int tasks_incomplete = 1;

    while (tasks_incomplete)
    {
        tasks_incomplete = 0;
        clear_screen();

        for (int i = 0; i < Max_Tasks; i++)
        {
            tasks[i].step = rand() % 5 + 1;
            tasks[i].progress += tasks[i].step;

            if (tasks[i].progress > 100)
            {
                tasks[i].progress = 100;
            }
            else
            {
                tasks_incomplete = 1;
            }
            display_bar(tasks[i]);     
        }
        sleep(2);
    }

    printf("\n\nAll Tasks Completed!\n");
    printf("\n--------------------------------------------------\n");
    printf("\nDeveloped by: SOHAM DEY \n");
    printf("\n--------------------------------------------------\n\n");   
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

void display_bar(Task t)
{
    float bars_to_show = (Bar_Length * t.progress) / 100;
    if (t.id < 10)
    {
        printf("\nTask %d:  [", t.id);
    }
    else
    {
        printf("\nTask %d: [", t.id);
    }
    for (int i = 0; i < Bar_Length; i++)
    {
        if (i < bars_to_show)
        {
            printf("=");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %d%%", t.progress);
}