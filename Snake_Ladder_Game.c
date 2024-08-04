#include<stdio.h> 
#include<stdlib.h> 
#include<time.h>
#include<unistd.h>
#include<windows.h>

int roll_dice();
void logic();
int player_move(int current_player, int roll);
void print_board();
void clear_screen();
void instruction();
void color(int color_value);

int player1 = 0, player2 = 0;
int flag1 = 0, flag2 = 0;
int count1 = 0, count2 = 0;
int val1 = 0, val2 = 0;

int main() 
{
    srand(time(NULL));
    instruction();
    clear_screen();
    logic();
    color(0x0f);      
    return 0;
}

int roll_dice()
{
    return rand() % 6 + 1;
}

void logic()
{
    print_board();
    color(0x0f);
    printf("\nPress 'ENTER' to Continue...");
    getchar();
    sleep(1);
    clear_screen();
    int current_player = rand() % 2 == 0 ? 1 : 2;
    int won = 0;
    while (!won) 
    {
        int count1  = 0, count2 = 0;
        print_board();
        color(0x0e);
        printf("\nPlayer %d",current_player);
        color(0x0f);
        printf("'s Turn !!");
        printf("\nPress 'ENTER' to Roll the Dice..."); 
        getchar();
        printf("Your Dice is Rolling...Please Wait !!\n");
        sleep(1);
        clear_screen();
        int roll = roll_dice();
        if (roll == 0)
        {
            roll = roll_dice();
        }        
        print_board();
        color(0x0f);
        printf("\nRolled!! You have got");
        color(0x0e);
        printf(" '%d' ", roll);
        color(0x0f);
        printf("in it !!");
        printf("\nPress 'ENTER' to Continue...");
        getchar();

        if (roll == 1 && current_player == 1 && flag1 == 0)
        {
            flag1 = 1;
        }
        if (roll == 1 && current_player == 2 && flag2 == 0)
        {
            flag2 = 1;
        }
        sleep(1);
        clear_screen();  
        if (current_player == 1 && flag1 == 2) 
        {
            while (roll == 6)
            {
                if (count1 == 0)
                {
                    val1 = player1;
                }
                count1++;
                if (count1 < 3)
                {
                    print_board();
                    color(0x0e);
                    printf("\nCongrats!! You will get another CHANCE to Roll the Dice...\n");
                    player1 = player_move(player1, roll);
                    color(0x0f);
                    printf("-------------------------------------------------------------");
                    printf("\nPress 'ENTER' to Roll the Dice..."); 
                    getchar();
                    printf("Your Dice is Rolling...Please Wait !!\n");
                    sleep(1);
                    clear_screen();
                    roll = roll_dice();
                    print_board();
                    color(0x0f);
                    printf("\nRolled!! You have got");
                    color(0x0e);
                    printf(" '%d' ", roll);
                    color(0x0f);
                    printf("in it !!");
                    printf("\nPress 'ENTER' to Continue...");
                    getchar();
                    clear_screen();
                }
                else
                { 
                    print_board();
                    color(0x0e);
                    printf("\nSORRY!! You have Rolled Consecutive THREE 6's...\n");
                    printf("\nYour MOVES will not get COUNTED !!\n");
                    player1 = val1;
                    count1 = 0;
                    color(0x0f);
                    printf("-------------------------------------------------------------");
                    printf("\nPress 'ENTER' to Continue...");
                    getchar();
                    clear_screen();
                    break;                                       
                }
            }
            if (roll != 6)
            {
                player1 = player_move(player1, roll);            
                color(0x0f);           
                print_board();
                clear_screen();
            }
            
            if (player1 == 100) 
            { 
                print_board();
                color(0x0e);
                printf("\n\t\t  !! Player 1 Wins !!");
                color(0x0f);
                printf("\n-------------------------------------------------------------\n");
                color(0x0a);
                printf("\t\t~~~ THANKS FOR PLAYING ~~~");
                color(0x0f);
                printf("\n-------------------------------------------------------------\n");
                printf("\n\t\tDeveloped by: SOHAM DEY \n");
                printf("\n-------------------------------------------------------------\n\n"); 
                won = 1; 
            } 
        }
        if (current_player == 2 && flag2 == 2)
        { 
            while (roll == 6)
            {
                if (count2 == 0)
                {
                    val2 = player1;
                }
                count2++;
                if (count2 < 3)
                {
                    print_board();
                    color(0x0e);
                    printf("\nCongrats!! You will get another CHANCE to Roll the DICE...\n");
                    player2 = player_move(player2, roll);
                    color(0x0f);
                    printf("-------------------------------------------------------------");
                    printf("\nPress 'ENTER' to Roll the Dice..."); 
                    getchar();
                    printf("Your Dice is Rolling...Please Wait !!\n");
                    sleep(1);
                    clear_screen();
                    roll = roll_dice();
                    print_board();
                    color(0x0f);
                    printf("\nRolled!! You have got");
                    color(0x0e);
                    printf(" '%d' ", roll);
                    color(0x0f);
                    printf("in it !!");
                    printf("\nPress 'ENTER' to Continue...");
                    getchar();
                    clear_screen();
                }
                else
                {
                    print_board();
                    color(0x0e);
                    printf("\nSORRY!! You have Rolled Consecutive THREE 6's...\n");
                    printf("\nYour MOVES will not get COUNTED !!\n");
                    color(0x0f);
                    printf("-------------------------------------------------------------");
                    player2 = val2;
                    count2 = 0;
                    printf("\nPress 'ENTER' to Continue...");
                    getchar();
                    clear_screen();
                    break;                                        
                }
            }
            if (roll != 6)
            {
                player2 = player_move(player2, roll);
                color(0x0f);
                print_board();
                clear_screen();
            }
            
            if (player2 == 100) 
            {
                print_board();
                color(0x0e);
                printf("\n\t\t  !! Player 2 Wins !!");
                color(0x0f);
                printf("\n-------------------------------------------------------------\n");
                color(0x0a);
                printf("\t\t~~~ THANKS FOR PLAYING ~~~");
                color(0x0f);
                printf("\n-------------------------------------------------------------\n");
                printf("\n\t\tDeveloped by: SOHAM DEY \n");
                printf("\n-------------------------------------------------------------\n\n"); 
                won = 1; 
            } 
        }
        current_player = (current_player == 1) ? 2 : 1; 
    }
}

int player_move(int current_player, int roll) 
{ 
    int new_position = current_player + roll;
    int snakes_and_ladders[101];  
    for (int i = 0; i <= 100; i++) 
    { 
        snakes_and_ladders[i] = 0; 
    }
    // Snake
    snakes_and_ladders[98] = -19;
    snakes_and_ladders[95] = -20;
    snakes_and_ladders[93] = -20;
    snakes_and_ladders[87] = -51;
    snakes_and_ladders[64] = -4;
    snakes_and_ladders[62] = -19;
    snakes_and_ladders[54] = -20;
    snakes_and_ladders[17] = -10;

    // Ladder
    snakes_and_ladders[80] = 19;
    snakes_and_ladders[72] = 19;
    snakes_and_ladders[28] = 56;
    snakes_and_ladders[51] = 16;
    snakes_and_ladders[21] = 21;
    snakes_and_ladders[1] = 37;
    snakes_and_ladders[9] = 22;
    snakes_and_ladders[4] = 10;

    int new_square = new_position + snakes_and_ladders[new_position];  
    if (new_square > 100) 
    { 
        return current_player;
    }  
    return new_square; 
}

void print_board() 
{
    color(0x0f);
    printf("-------------------------------------------------------------\n");
    printf("\t~~~ Welcome to The Snake and Ladder Game ~~~");
    printf("\n-------------------------------------------------------------\n");
    instruction();

    if (player1 != 0 && flag1 == 2)
    {
        color(0x0e);
        printf("\nPlayer 1 ");
        color(0x0f);
        printf("is now at Square : ");
        color(0x0e);
        printf("%d\n", player1);
    }
    else if (player1 == 0 && flag1 == 1)
    {
        flag1 = 2;
        color(0x0e);
        printf("\nPlayer 1 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" INSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }
    else if (player1 == 0 && flag1 == 2)
    {
        flag1 = 2;
        color(0x0e);
        printf("\nPlayer 1 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" INSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }
    else
    {
        color(0x0e);
        printf("\nPlayer 1 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" OUTSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }
    
    if (player2 != 0 && flag2 == 2)
    {
        color(0x0e);
        printf("\nPlayer 2 ");
        color(0x0f);
        printf("is now at Square : ");
        color(0x0e);
        printf("%d\n", player2);
    }
    else if (player2 == 0 && flag2 == 1)
    {
        flag2 = 2;
        color(0x0e);
        printf("\nPlayer 2 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" INSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }
    else if (player2 == 0 && flag2 == 2)
    {
        flag2 = 2;
        color(0x0e);
        printf("\nPlayer 2 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" INSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }
    else
    {
        color(0x0e);
        printf("\nPlayer 2 ");
        color(0x0f);
        printf("is");
        color(0x0e);
        printf(" OUTSIDE ");
        color(0x0f);
        printf("the BOARD\n");
    }

    color(0x0f);
    printf("\n-------------------------------------------------------------\n"); 
    int board[101]; 
    for (int i = 1; i <= 100; i++) 
    { 
        board[i] = i; 
    }  
    int alt = 0;  
    int iterLR = 101;  
    int iterRL = 80; 
    int val = 100;
    color(0x02);
    printf("\n+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n");    
    while (val--) 
    {
        if (val%1 == 0)
        {
            color(0x02);
            printf("| ");
        }
        if (alt == 0) 
        {             
            iterLR--; 
            if (iterLR == player1) 
            { 
                if (board[iterLR] < 10)
                {
                    color(0x0f);
                    printf("#P1 ", board[iterLR]);
                }
                else if (board[iterLR] < 100)
                {
                    color(0x0f);
                    printf("#P1 ", board[iterLR]);
                }
                else
                {
                    color(0x0f);
                    printf("#P1 ", board[iterLR]);                    
                }
            } 
            else if (iterLR == player2) 
            {
                if (board[iterLR] < 10)
                {
                    color(0x0f);
                    printf("#P2 ", board[iterLR]);
                }
                else if (board[iterLR] < 100)
                {
                    color(0x0f);
                    printf("#P2 ", board[iterLR]);
                }
                else
                {
                    color(0x0f);
                    printf("#P2 ", board[iterLR]);                    
                } 
            } 
            else
            {
                if (board[iterLR] < 10)
                {
                    if (board[iterLR] == 1 || board[iterLR] == 9 || board[iterLR] == 4)
                    {
                        color(0x0e);
                        printf("  %d ", board[iterLR]);
                    }
                    else
                    {
                        color(0x0b);
                        printf("  %d ", board[iterLR]);
                    }                    
                }
                else if (board[iterLR] < 100)
                {
                    if (board[iterLR] == 98 || board[iterLR] == 95 || board[iterLR] == 93 || board[iterLR] == 87 || board[iterLR] == 64 || board[iterLR] == 62 || board[iterLR] == 54 || board[iterLR] == 17)
                    {
                        color(0x0c);
                        printf(" %d ", board[iterLR]);
                    }
                    else if (board[iterLR] == 80 || board[iterLR] == 72 || board[iterLR] == 28 || board[iterLR] == 51 || board[iterLR] == 21)
                    {
                        color(0x0e);
                        printf(" %d ", board[iterLR]);
                    }
                    else
                    {
                        color(0x0b);
                        printf(" %d ", board[iterLR]);
                    }                   
                }
                else
                {
                    color(0x0b);
                    printf("%d ", board[iterLR]);                    
                }
            }
            if (iterLR % 10 == 1) 
            {
                color(0x02);
                printf("|");
                printf("\n+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n"); 
                alt = 1; 
                iterLR -= 10; 
            } 
        } 
        else 
        { 
            iterRL++; 
            if (iterRL == player1) 
            {
                if (board[iterRL] < 10)
                {
                    color(0x0f);
                    printf("#P1 ", board[iterRL]);
                }
                else if (board[iterRL] < 100)
                {
                    color(0x0f);
                    printf("#P1 ", board[iterRL]);
                }
                else
                {
                    color(0x0f);
                    printf("#P1 ", board[iterRL]);                    
                } 
            } 
            else if (iterRL == player2) 
            {
                if (board[iterRL] < 10)
                {
                    color(0x0f);
                    printf("#P2 ", board[iterRL]);
                }
                else if (board[iterRL] < 100)
                {
                    color(0x0f);
                    printf("#P2 ", board[iterRL]);
                }
                else
                {
                    color(0x0f);
                    printf("#P2 ", board[iterRL]);                    
                }
            } 
            else
            {
                if (board[iterRL] < 10)
                {
                    if (board[iterRL] == 1 || board[iterRL] == 9 || board[iterRL] == 4)
                    {
                        color(0x0e);
                        printf("  %d ", board[iterRL]);
                    }
                    else
                    {
                        color(0x0b);
                        printf("  %d ", board[iterRL]);
                    }                    
                }
                else if (board[iterRL] < 100)
                {
                    if (board[iterRL] == 98 || board[iterRL] == 95 || board[iterRL] == 93 || board[iterRL] == 87 || board[iterRL] == 64 || board[iterRL] == 62 || board[iterRL] == 54 || board[iterRL] == 17)
                    {
                        color(0x0c);
                        printf(" %d ", board[iterRL]);
                    }
                    else if (board[iterRL] == 80 || board[iterRL] == 72 || board[iterRL] == 28 || board[iterRL] == 51 || board[iterRL] == 21)
                    {
                        color(0x0e);
                        printf(" %d ", board[iterRL]);
                    }
                    else
                    {
                        color(0x0b);
                        printf(" %d ", board[iterRL]);
                    }                    
                }
                else
                {
                    color(0x0b);
                    printf("%d ", board[iterRL]);                    
                }
            }  
            if (iterRL % 10 == 0) 
            {
                color(0x02);
                printf("|"); 
                printf("\n+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+\n"); 
                alt = 0; 
                iterRL -= 30; 
            } 
        } 
        if (iterRL == 10)
        { 
            break;
        }
    }
    color(0x0f);
    printf("\n-------------------------------------------------------------");   
}

void instruction()
{
  color(0x0f);
  printf("\tInstructions to be followed~~~>\n\n");
  color(0x0c);
  printf("\tSNAKE~~~>");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("LADDER~~~>\n\n");

  color(0x0c);
  printf("\t98");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("79");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("80");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("99");
  printf("\n");
  
  color(0x0c);
  printf("\t95");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("75");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("72");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("91");
  printf("\n");

  color(0x0c);
  printf("\t93");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("73");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("51");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("67");
  printf("\n");

  color(0x0c);
  printf("\t87");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("36");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("28");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("84");
  printf("\n");

  color(0x0c);
  printf("\t64");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("60");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("21");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("42");
  printf("\n");

  color(0x0c);
  printf("\t62");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("19");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("09");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("31");
  printf("\n");

  color(0x0c);
  printf("\t54");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("34");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("04");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("14");
  printf("\n");

  color(0x0c);
  printf("\t17");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0c);
  printf("07");
  color(0x0f);
  printf("\t|\t");
  color(0x0e);
  printf("01");
  color(0x0f);
  printf(" ~~~> ");
  color(0x0e);
  printf("38");
  printf("\n");

  color(0x0f);
  printf("\n#P1 ~~~> PLAYER 1\t|\t#P2 ~~~> PLAYER 2");
  printf("\n-------------------------------------------------------------\n");
    
  color(0x0b);
  printf("\tFIRST TO REACH '100'");
  color(0x0e);
  printf(" ~~~> ");
  color(0x0b);
  printf("WINS THE GAME !!");
  color(0x0f);
  printf("\n-------------------------------------------------------------\n");

  color(0x0b);
  printf("\tROLL '1'(ONE)");
  color(0x0e);
  printf(" ~~~> ");
  color(0x0b);
  printf("TO START THE GAME !!");
  color(0x0f);
  printf("\n-------------------------------------------------------------\n");
  
  color(0x0b);
  printf("\tROLL '6'(SIX)");
  color(0x0e);
  printf(" ~~~> ");
  color(0x0b);
  printf("TO GET AN EXTRA CHANCE !!");
  color(0x0f);
  printf("\n-------------------------------------------------------------\n");
    
  color(0x0b);
  printf("\tROLLING '3' CONSECUTIVE '6'(SIX)");
  color(0x0e);
  printf(" ~~~> ");
  color(0x0b);
  printf("NOT COUNTED !!");
  color(0x0f);
  printf("\n-------------------------------------------------------------\n");
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