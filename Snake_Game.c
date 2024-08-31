#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>

#define HEIGHT 15
#define WIDTH 30

void setup();
void draw();
void input();
void logic();
void clear_screen();
void instruction();
void color(int color_value);

enum Direction 
{
  UP, 
  DOWN,
  LEFT,
  RIGHT,
  STOP
};

enum Direction dir;
int score;
int fruit_x, fruit_y;
int head_x, head_y;
int tail_length;
int tail_x[100];
int tail_y[100];

int main()
{
  srand(time(NULL));
  setup();
  instruction();
  if (getch())
  {
    while (1)
    {
      draw();
      input();
      logic();
      int sleep_time = 5000000 / (score != 0 ? score : 10);
      usleep(sleep_time);
    }
  }
  color(0x0f);
  return 0;
}

void setup()
{
  head_x = WIDTH / 2;
  head_y = HEIGHT / 2;
  fruit_x = rand() % WIDTH;
  fruit_y = rand() % HEIGHT;
  dir = STOP;
  score = 0;
  tail_length = 0;
}

void draw()
{
  clear_screen();
  color(0x0f);
  printf("--------------------------------------------------\n");
  printf("\t~~~ Welcome to The Snake Game ~~~");
  printf("\n--------------------------------------------------\n");
  printf("\n");
  for (int i = 0; i <= WIDTH + 2; i+=2) 
  {
    color(0x0a);
    printf("* ");
  }
  for (int i = 0; i <= HEIGHT; i++) 
  {
    color(0x0a);
    printf("\n*");
    for (int j = 0; j <= WIDTH; j++) 
    {
      if (i == head_y && j == head_x) 
      {
        color(0x0e);
        printf("O");
      } 
      else if (i == fruit_y && j == fruit_x) 
      {
        color(0x04);
        printf("A");
      } 
      else 
      {
        int tail_found = 0;
        for (int k = 0; k < tail_length; k++) 
        {
          if (tail_x[k] == j && tail_y[k] == i) 
          {
            color(0x0e);
            printf("O");
            tail_found = 1;
            break;
          }
        }
        if (!tail_found) 
        {
          printf(" ");
        }
      }
    }
    color(0x0a);
    printf("*");
  }
  printf("\n");
  for (int i = 0; i <= WIDTH + 2; i+=2) 
  {
    color(0x0a);
    printf("* ");
  }
  color(0x0f);
  printf("\n\n--------------------------------------------------\n");
  color(0x0a);
  printf("Score: ");
  color(0x0b);
  printf("%d", score);
  color(0x0f);
  printf("\n--------------------------------------------------\n");
  color(0x0f);
  printf("Press");
  color(0x0b);
  printf(" 'X' ");
  color(0x0f);
  printf("to");
  color(0x0b);
  printf(" 'QUIT' ");
  color(0x0f);
  printf("the Game\n");
}

void input()
{
  if (kbhit())
  {
    switch (getch())
    {
      case 'a':
      case 'A':
        dir = LEFT;
        break;
      case 's':
      case 'S':
        dir = DOWN;
        break;
      case 'd':
      case 'D':
        dir = RIGHT;
        break;
      case 'w':
      case 'W':
        dir = UP;
        break;
      case 'x':
      case 'X':
        color(0x0f);
        printf("--------------------------------------------------\n");
        color(0x0e);
        printf("\t~~~ THANKS FOR PLAYING ~~~");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        printf("\n\tDeveloped by: SOHAM DEY \n");
        printf("\n--------------------------------------------------\n");
        exit(0);
      default:
        break;
    }
  }
}

void logic()
{
  for (int i = tail_length - 1; i >= 0; i--) 
  {
    tail_x[i] = tail_x[i-1];
    tail_y[i] = tail_y[i-1];
  }
  tail_x[0] = head_x;
  tail_y[0] = head_y;
  switch (dir)
  {
    case UP:
      head_y--;
      break;
    case DOWN:
      head_y++;
      break;
    case LEFT:
      head_x--;
      break;
    case RIGHT:
      head_x++;
      break;
    case STOP:
      break;
  }
  if (head_x < 0) 
  {
    head_x = WIDTH;
  } 
  else if (head_x > WIDTH) 
  {
    head_x = 0;
  }
  if (head_y < 0) 
  {
    head_y = HEIGHT;
  } 
  else if (head_y > HEIGHT) 
  {
    head_y = 0;
  }
  for (int i = 0; i < tail_length; i++) 
  {
    if (tail_x[i] == head_x && tail_y[i] == head_y) 
    {
      color(0x0f);
      printf("\nYou have hit the Tail of the SNAKE. GAME OVER !!!");
      printf("\n--------------------------------------------------\n");
      color(0x0e);
      printf("\t~~~ THANKS FOR PLAYING ~~~");
      color(0x0f);
      printf("\n--------------------------------------------------\n");
      printf("\n\tDeveloped by: SOHAM DEY \n");
      printf("\n--------------------------------------------------\n");
      exit(0);
    }
  }
  if (head_x == fruit_x && head_y == fruit_y) 
  {
    score += 10;
    tail_length++;
    fruit_x = rand() % WIDTH;
    fruit_y = rand() % HEIGHT;
  }
}

void instruction()
{
  clear_screen();
  color(0x0f);
  printf("--------------------------------------------------\n");
  color(0x0c);
  printf("\t~~~ Welcome to The Snake Game ~~~");
  color(0x0f);
  printf("\n--------------------------------------------------\n");
  printf("\nInstructions to be followed~~~>\n\n");

  color(0x0a);
  printf("Press");
  color(0x0b);
  printf(" 'A' ");
  color(0x0a);
  printf("to move the Snake to the");
  color(0x0b);
  printf(" 'LEFT'\n");

  color(0x0a);
  printf("Press");
  color(0x0b);
  printf(" 'S' ");
  color(0x0a);
  printf("to move the Snake to the");
  color(0x0b);
  printf(" 'DOWN'\n");

  color(0x0a);
  printf("Press");
  color(0x0b);
  printf(" 'D' ");
  color(0x0a);
  printf("to move the Snake to the");
  color(0x0b);
  printf(" 'RIGHT'\n");

  color(0x0a);
  printf("Press");
  color(0x0b);
  printf(" 'W' ");
  color(0x0a);
  printf("to move the Snake to the");
  color(0x0b);
  printf(" 'UP'\n");

  color(0x0a);
  printf("Press");
  color(0x0b);
  printf(" 'X' ");
  color(0x0a);
  printf("to");
  color(0x0b);
  printf(" 'QUIT' ");
  color(0x0a);
  printf("the Game\n");
  color(0x0f);
  printf("\n--------------------------------------------------\n");
  color(0x0f);
  printf("Press");
  color(0x0b);
  printf(" 'ENTER' ");
  color(0x0f);
  printf("to Continue...\n");
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

void color(int color_value)
{
  HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(H, color_value);
}