#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_NAME_LENGTH 40
int total_initial_value = 0, current_price = 0, total_initial_value, total_current_value, profit_loss;
float percent_change;
struct stocks
{
    char Stock_name[20];
    int amt;
    int no_of_shares;
} stock_details[10];
struct User
{
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
};

void create_user_profile(struct User *user)
{
    printf("\e[1;34mPlease enter your name:\e[0m ");
    scanf("%s", user->name);

    printf("\e[1;34mPlease enter your age:\e[0m ");
    scanf("%d", &user->age);
    getchar(); // consume newline character

    printf("\e[1;34mPlease enter your email address:\e[0m ");
    fgets(user->email, MAX_NAME_LENGTH, stdin);
    user->email[strcspn(user->email, "\n")] = '\0'; // remove newline character from email
}

void check(char a[20])
{
    // an array of strings
    int y = 0;
    char NSE[15][13] = {"JSWSTEEL", "ONGC", "TATASTEEL", "SBIN", "TECHM", "HDFCBANK", "TCS", "ASIANPAINT", "WIPRO", "ITC", "RELIANCE", "LT", "AXISBANK", "APOLLOHOSP", "HEROMOTOCO"};
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(a, NSE[i]) == 0)
        {
            y += 1;
        }
    }
    if (y == 0)
    {
        printf("enter a valid stock code");
        exit(0);
    }
}

void market_sim()
{
    int num;

    int total_initial_value = 0; // Initialize the variable to zero
    // Display the list of stocks
    printf("\t \033[0;36m--------------------------------------------------\033[0m\n");
    printf("\t \033[0;36m|\t\t National Stock Exchange          |\033[0m\n");
    printf("\t \033[0;36m--------------------------------------------------\033[0m\n");
    printf("\t \033[0;31m| Stock Code  |   Company Name                   |\033[0m\n");
    printf("\t \033[0;36m--------------------------------------------------\033[0m\n");
    printf("\t \033[0;32m| JSWSTEEL    |   JSW Steel                      |\033[0m\n");
    printf("\t \033[0;32m| ONGC        |   Oil and Natural Gas Corporation|\033[0m\n");
    printf("\t \033[0;32m| TATASTEEL   |   Tata Steel Ltd.                |\033[0m\n");
    printf("\t \033[0;32m| SBIN        |   State Bank of India            |\033[0m\n");
    printf("\t \033[0;32m| TECHM       |   Tech Mahindra                  |\033[0m\n");
    printf("\t \033[0;32m| HDFCBANK    |   HDFC Bank Ltd.                 |\033[0m\n");
    printf("\t \033[0;32m| TCS         |   Tata Consultancy Services      |\033[0m\n");
    printf("\t \033[0;32m| ASIANPAINT  |   Asian Paints                   |\033[0m\n");
    printf("\t \033[0;32m| WIPRO       |   Wipro Ltd.                     |\033[0m\n");
    printf("\t \033[0;32m| ITC         |   India Tobacco Company Ltd.     |\033[0m\n");
    printf("\t \033[0;32m| RELIANCE    |   Reliance Industries Ltd.       |\033[0m\n");
    printf("\t \033[0;32m| LT          |   Larsen & Toubro                |\033[0m\n");
    printf("\t \033[0;32m| AXISBANK    |   Axis Bank Ltd.                 |\033[0m\n");
    printf("\t \033[0;32m| APOLLOHOSP  |  Apollo Hospitals Enterprise Ltd.|\033[0m\n");
    printf("\t \033[0;32m| HEROMOTOCO  |   Hero MotoCorp Ltd.             |\033[0m\n");
    printf("\t \033[0;36m--------------------------------------------------\033[0m\n");

    printf("\e[1;33mEnter the number of stocks u have purchased:  \e[0m");
    scanf("%d", &num);
    printf("\e[1;33mPlease tell us which of these stocks you have purchased using the stock codes\e[0m\n");

    // Iterate through the stocks purchased by the user
    for (int i = 0; i < num; i++)
    {
        printf("\e[1;33mEnter the stock you have purchased (code) \t \e[0m");
        scanf("%s", stock_details[i].Stock_name);
        check(stock_details[i].Stock_name);

        // Get the initial value of share and the number of shares purchased
        printf("\e[1;33mEnter the amount invested per share: \t\e[0m");
        scanf("%d", &stock_details[i].amt);
        printf("\n\e[1;33mEnter no of shares you have purchased\t\e[0m");
        scanf("%d", &stock_details[i].no_of_shares);

        // Calculate total initial value of stock
        total_initial_value += (stock_details[i].amt * stock_details[i].no_of_shares);
        percent_change = ((float)rand() / (float)(RAND_MAX)) * 0.2 - 0.1; // random change between -10% and +10%
        current_price += stock_details[i].amt * (1 + percent_change);

        // Calculate total current value of stock and profit/loss
        total_current_value = current_price * stock_details[i].no_of_shares;
    }

    printf("\n\e[1;33mNow let's predict the market performance of your stocks\e[0m\n");

    profit_loss = total_current_value - total_initial_value;

    // Output results
    printf("\e[1;32mInitial value: $%d\e[0m\n", total_initial_value);
    printf("\e[1;32mCurrent value: $%d\e[0m\n", total_current_value);
    printf("\e[1;32mProfit/Loss that you will incur in the period of 365 days: $%d\e[0m\n", profit_loss);
    printf("\e[1;33mThank you for using our System\e[0m\n");

    exit(0);
}

int main()
{
    struct User user;
    int ch;
    srand(time(NULL)); // initialize random seed
    printf("\033[1;34mHello and welcome to our stock market simulation\033[0m\n");
    while (1)
    {

        printf("\033[1;33mWhat would you like to do?\n1.Create your profile\n2.Perform Market Simulation\n3.Exit\n\033[0m");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_user_profile(&user);
            printf("\033[1;32mUser profile created:\n");
            printf("Name: %s\n", user.name);
            printf("Age: %d\n", user.age);
            printf("Email: %s\n\033[0m", user.email);
            break;
        case 2:
            market_sim();
            break;
        case 3:
            exit(0);
        default:
            printf("\033[1;31mINVALID INPUT\n\033[0m");
            break;
        }
    }
    return 0;
}
