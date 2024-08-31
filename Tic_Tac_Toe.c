#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#define BOARD_SIZE 3 

void input_mode();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);
void color(int color_value);

typedef struct
{
    int player;
    int player_X;
    int player_O;
    int computer;
    int draw;
} Score;

int mode;
Score score = {.player = 0, .player_X = 0, .player_O = 0, .computer = 0, .draw = 0};

int main()
{
    srand(time(NULL));
    int choice;
    input_mode();
    do
    {
        play_game();
        color(0x0a);
        printf("Play Again? (1 for YES, 0 for NO): ");
        color(0x0f);
        scanf("%d", &choice); 
    } while (choice == 1);
    printf("--------------------------------------------------\n");
    color(0x0e);
    printf("\t~~~ THANKS FOR PLAYING ~~~");
    color(0x0f);
    printf("\n--------------------------------------------------\n");
    printf("\n\tDeveloped by: SOHAM DEY \n");
    printf("\n--------------------------------------------------\n");
    return 0;
}

void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE] =
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char current_player = rand() % 2 == 0 ? 'X' : 'O';
    print_board(board);
    if (mode == 1 || mode == 2 )
    {
        while (1)
        {
            if (current_player == 'X')
            {
                player_move(board, 'X');
                print_board(board);
                if (check_win(board, 'X'))
                {
                    score.player++;
                    print_board(board);
                    color(0x0e);
                    printf("Congratulations!! You have Won...");
                    color(0x0f);
                    printf("\n--------------------------------------------------\n");
                    return;
                }
                current_player = 'O';
            }
            else
            {
                computer_move(board);
                print_board(board);
                if (check_win(board, 'O'))
                {
                    score.computer++;
                    print_board(board);
                    color(0x0b);
                    printf("Sorry!! Computer has Won...");
                    color(0x0f);
                    printf("\n--------------------------------------------------\n");
                    return;
                }
                current_player = 'X';
            }
            if (check_draw(board))
            {
                score.draw++;
                print_board(board);
                color(0x0c);
                printf("It's a Draw!!\n");
                color(0x0f);
                return;
            }
        }
    }

    if (mode == 3)
    {
        while (1)
        {
            if (current_player == 'X')
            {
                player_move(board, 'X');
                print_board(board);
                if (check_win(board, 'X'))
                {
                    score.player_X++;
                    print_board(board);
                    color(0x0e);
                    printf("Congratulations!! Player 1 has Won...");
                    color(0x0f);
                    printf("\n--------------------------------------------------\n");
                    return;
                }
                current_player = 'O';
            }
            else
            {
                player_move(board, 'O');
                print_board(board);
                if (check_win(board, 'O'))
                {
                    score.player_O++;
                    print_board(board);
                    color(0x0b);
                    printf("Congratulations!! Player 2 has Won...");
                    color(0x0f);
                    printf("\n--------------------------------------------------\n");
                    return;
                }
                current_player = 'X';
            }
            if (check_draw(board))
            {
                score.draw++;
                print_board(board);
                color(0x0c);
                printf("It's a Draw!!\n");
                color(0x0f);
                return;
            }
        }
    }   
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col)
{
    return !(row<1 || col<1 || row>3 || col>3 || board[row-1][col-1] != ' ');
}

void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    if (mode == 1 || mode == 2)
    {
        int row, col;
        do
        {
            color(0x0e);
            printf("Player's Turn~~~>");
            printf("\nEnter Row and Column (1-3):\n");
            color(0x0f);
            scanf("%d", &row);
            scanf("%d", &col);
        } while (!is_valid_move(board, row, col));
        row--;
        col--;
        board[row][col]= player;
    }

    if (mode == 3)
    {
        int row, col;
        do
        {
            if (player == 'X')
            {
                color(0x0e);
                printf("Player 1's Turn~~~>");
                printf("\nEnter Row and Column (1-3) for %c:\n", player);
            }
            if (player == 'O')
            {
                color(0x0b);
                printf("Player 2's Turn~~~>");
                printf("\nEnter Row and Column (1-3) for %c:\n", player);
            }
            color(0x0f);
            scanf("%d", &row);
            scanf("%d", &col);
        } while (!is_valid_move(board, row, col));
        row--;
        col--;
        board[row][col]=player;
    }
}

void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Play for Immediate Win
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                if (check_win(board, 'O'))
                {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Play for Immediate Block
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'X';
                if (check_win(board, 'X'))
                {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    if (mode == 2)
    {
        // Play for Center if Available
        if (board[1][1] == ' ')
        {
            board[1][1] = 'O';
            return;
        }

        // Play for Corner if Available
        int corner[4][2] = 
        {
            {0, 0},
            {0, 2},
            {2, 0},
            {2, 2}
        };
        for (int i=0 ; i<4 ; i++)
        {
            if (board[corner[i][0]][corner[i][1]] == ' ')
            {
                board[corner[i][0]][corner[i][1]] = 'O';
                return;
            }
        }
    }

    // Play for First Available Move
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player)
{
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
            return 1;
        }
    }
    return 0;       
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    clear_screen();
    color(0x0f);
    printf("--------------------------------------------------\n");
    printf("\t~~~ Welcome to The Tic-Tac-Toe Game ~~~");
    printf("\n--------------------------------------------------\n");
    if (mode == 1 || mode == 2)
    {
        color(0x0e);
        printf("\t    X");
        color(0x0f);
        printf(" |");
        color(0x0a);
        printf("\t   S C O R E");
        color(0x0f);
        printf("    |");
        color(0x0b);
        printf(" O");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        color(0x0e);
        printf("Player:");
        printf(" %d", score.player);
        color(0x0f);
        printf("     |     ");
        color(0x0c);
        printf("Draw:");
        printf(" %d", score.draw);
        color(0x0f);
        printf("     |     ");
        color(0x0b);
        printf("Computer:");
        printf(" %d", score.computer);
        color(0x0f);
        printf("\n--------------------------------------------------\n");
    }
    if (mode == 3)
    {
        color(0x0e);
        printf("\t    X");
        color(0x0f);
        printf(" |");
        color(0x0a);
        printf("\t   S C O R E");
        color(0x0f);
        printf("    |");
        color(0x0b);
        printf(" O");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        color(0x0e);
        printf("Player 1:");
        printf(" %d", score.player_X);
        color(0x0f);
        printf("   |     ");
        color(0x0c);
        printf("Draw:");
        printf(" %d", score.draw);
        color(0x0f);
        printf("     |   ");
        color(0x0b);
        printf("Player 2:");
        printf(" %d", score.player_O);
        color(0x0f);
        printf("\n--------------------------------------------------\n");
    }
    for (int i=0 ; i<BOARD_SIZE ; i++)
    {
        printf("\n");
        for (int j=0 ; j<BOARD_SIZE ; j++)
        {
            if (board[i][j] == 'X')
            {
                color(0x0e);
                printf(" %c ", board[i][j]);                
            }
            else if (board[i][j] == 'O')
            {
                color(0x0b);
                printf(" %c ", board[i][j]);                
            }
            else
            {
                printf("   ");
            }
            if (j < BOARD_SIZE - 1)
            {
                color(0x0a);
                printf("|");
            }
        }
        if (i < BOARD_SIZE - 1)
        {
            color(0x0a);
            printf("\n---+---+---");            
        }
    }
    if (mode == 1 || mode == 2)
    {
        color(0x0f);
        printf("\n\n--------------------------------------------------\n");
        color(0x0e);
        printf("X~~~> PLAYER");
        color(0x0f);
        printf("          |          ");
        color(0x0b);
        printf("O~~~> COMPUTER");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
    }
    if (mode == 3)
    {
        color(0x0f);
        printf("\n\n--------------------------------------------------\n");
        color(0x0e);
        printf("X~~~> PLAYER 1");
        color(0x0f);
        printf("         |         ");
        color(0x0b);
        printf("O~~~> PLAYER 2");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
    } 
}

void input_mode()
{   
    while (1)
    {
        clear_screen();
        color(0x0f);
        printf("--------------------------------------------------\n");
        color(0x0c);
        printf("\t~~~ Welcome to The Tic-Tac-Toe Game ~~~");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        printf("\nSelect Mode--->\n");
        color(0x0a);
        printf("\n1. Computer ");
        color(0x0b);
        printf("(NORMAL Mode)");
        color(0x0a);
        printf("\n2. Computer ");
        color(0x0b);
        printf("(HARDCORE Mode)");
        color(0x0a);
        printf("\n3. Player Mode ");
        color(0x0b);
        printf("(TWO)");
        color(0x0f);
        printf("\n\n--------------------------------------------------\n");
        printf("Enter your Choice:\n");
        scanf("%d",&mode);
        if (mode == 1 || mode == 2 || mode == 3)
        {
            break;
        }
    }
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