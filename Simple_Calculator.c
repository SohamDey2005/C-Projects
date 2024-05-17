#include<stdio.h>
#include<math.h>

double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double modulus(int, int);
double power(double, double);
void print_menu();

int main()
{
    int choice;
    double first, second, result;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);

        if (choice == 7)
        {
            printf("\n--------------------------------------------------\n");
            printf("\nDeveloped by: SOHAM DEY \n");
            printf("\n--------------------------------------------------\n");
            break;
        }

        if (choice < 1 || choice > 7)
        {
            fprintf(stderr, "\nInvalid Menu Choice.\n");
            printf("\n--------------------------------------------------\n");
            printf("\nDeveloped by: SOHAM DEY \n");
            continue;
        }

        printf("\nPlease...Enter the First Number: ");
        scanf("%lf",&first);
        printf("Please...Enter the Second Number: ");
        scanf("%lf",&second);

        switch (choice)
        {
        case 1: // Add
        {
            result = addition(first, second);
            break; 
        }   
        case 2: // Subtract
        {
            result = subtraction(first, second);
            break;
        }
        case 3: // Multiply
         {
            result = multiplication(first, second);
            break;
        }
        case 4: // Divide
        {
            result = division(first, second);
            break;
        }
        case 5: // Modulus
        {
            result = modulus(first,second);
            break;
        }
        case 6: // Power
        {
            result = power(first, second);
            break;
        }  
        }

        if (!isnan(result))
        {
            printf("\nResult of Operation is: %0.2lf\n",result);
            printf("\n--------------------------------------------------\n");
            printf("\nDeveloped by: SOHAM DEY \n");
        }  

    }
    return 0;
}

void print_menu()
{
    printf("\n--------------------------------------------------\n");
    printf("\nWelcome to Simple Calculator\n");
    printf("\nChoose one of the following options: ");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow...Enter your Choice: ");
}

double addition(double a, double b)
{
    return a + b;
}

double subtraction(double a, double b)
{
    return a - b;
}

double multiplication(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "\nInvalid Argument for Division\n");
        printf("\n--------------------------------------------------\n");
        printf("\nDeveloped by: SOHAM DEY \n");
        return NAN;
    }
    else
    {
        return a / b;
    }
}

double modulus(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "\nInvalid Argument for Modulus\n");
        printf("\n--------------------------------------------------\n");
        printf("\nDeveloped by: SOHAM DEY \n");
        return NAN;
    }
    else
    {
        return a % b;
    }
}

double power(double a, double b)
{
    return pow(a, b);
}