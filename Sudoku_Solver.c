#include<stdio.h>
#include<windows.h>

void print_puzzle(int puzzle[9][9]);
int valid_move(int puzzle[9][9], int row, int col, int val);
int solve_puzzle(int puzzle[9][9], int row, int col);
void clear_screen();
void color(int color_value);

int puzzle[9][9]=
{
    {1,0,7,0,0,6,4,5,0},
    {0,2,5,3,4,0,0,0,8},
    {0,6,0,0,0,1,0,7,0},
    {0,5,3,0,0,0,0,2,9},
    {6,1,0,0,0,9,8,0,0},
    {0,0,0,6,0,2,0,0,7},
    {0,0,1,0,9,3,2,0,0},
    {0,0,8,0,0,0,0,0,0},
    {0,4,0,0,7,8,5,9,0}
};

int main()
{
    clear_screen();
    color(0x0f);
    printf("\n--------------------------------------------------\n");
    printf("\t!!! WELCOME TO SUDOKU SOLVER !!!");
    printf("\n--------------------------------------------------\n");
    color(0x0c);
    printf("\nOriginal Puzzle ~~~>");
    print_puzzle(puzzle);
    if(solve_puzzle(puzzle, 0, 0))
    {
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        color(0x0c);
        printf("\nSolved Puzzle ~~~>");
        print_puzzle(puzzle);
        color(0x0f);
        printf("\n--------------------------------------------------\n");
        printf("\n\tDeveloped by: SOHAM DEY \n");
        printf("\n--------------------------------------------------\n\n");
    }
    else
    {
        color(0x0f);
        printf("\n--------------------------------------------------\n\n");
        color(0x0c);
        printf("\t!! This Puzzle is not Solvable !!\n");
        color(0x0f);
        printf("\n--------------------------------------------------\n");
    }
    return 0;
}

int solve_puzzle(int puzzle[9][9], int row, int col)
{
    if (col == 9)
    {
        if (row == 8)
        {
            return 1; // Puzzle Solved
        }
        row++;
        col = 0;
    }
    if (puzzle[row][col] > 0)
    {
        return solve_puzzle(puzzle, row, col + 1);
    }
    for (int i=1 ; i<=9 ; i++)
    {
        if (valid_move(puzzle, row, col, i))
        {
            puzzle[row][col] = i;
            if (solve_puzzle(puzzle, row, col + 1))
            {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

int valid_move(int puzzle[9][9], int row, int col, int val)
{
    // valid row
    for(int i=0 ; i<9 ; i++)
    {
        if(puzzle[row][i] == val)
        {
            return 0;
        }
    }
    // valid column
    for(int i=0 ; i<9 ; i++)
    {
        if(puzzle[i][col] == val)
        {
            return 0;
        }
    }
    // valid square
    int r = row - row % 3;
    int c = col - col % 3;
    for(int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            if (puzzle[r+i][c+j] == val)
            {
                return 0;
            }
        }        
    }
    return 1;
}

void print_puzzle(int puzzle[9][9])
{
    color(0x0a);
    printf("\n+-------+-------+-------+");
    for(int row=0; row<9; row++)
    {
        if (row%3 == 0 && row != 0)
        {
            color(0x0a);
            printf("\n|-------+-------+-------|");
        } 
        printf("\n");
        for (int col=0; col<9; col++)
        {
            if (col%3 == 0)
            {
                color(0x0a);
                printf("| ");
            }
            if (puzzle[row][col] != 0)
            {
                color(0x0e);
                printf("%d ",puzzle[row][col]);
            }
            else
            {
                color(0x0a);
                printf("  ");
            }                    
        }
        color(0x0a);
        printf("|");        
    }
    color(0x0a);
    printf("\n+-------+-------+-------+\n");
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