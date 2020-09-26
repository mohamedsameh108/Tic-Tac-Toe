#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1, player2, p, player, computer;
int flag, i, menu;
int main()
{
    printf("Hello Player\nPress 1 to play Single Game\nPress 2 to play Multi Game\n");
    scanf("%d", &menu);
    if (menu == 1)
    {
        single();
    }
    else if (menu == 2)
    {
        multi();
    }
    else
    {
        printf("I didn't understand You\n");
        main();
    }
}
int single()
{
    printf("Choose X or O\n");
    scanf(" %c", &player);
    player = toupper(player);
    if (player == 'X')
    {
        computer = 'O';
        flag = 1;
    }
    else if (player == 'O')
    {
        computer = 'X';
        flag = 1;
    }
    else
    {
        printf("I didn't understand you\nPlease choose again\n");
        single();
    }
    if (flag == 1)
    {
        printf("Ok you will be %c and computer will be %c\n", player, computer);
        sleep(1);
        printf("Let's start\n\n");
        int z = 0;
        for (int x = 0; x < 3; x++)
        {
            printf("\t\t\t\t");
            for (int i = 0; i < 3; i++)
            {
                printf("%c\t", arr[z]);
                z++;
            }
            printf("\n\n\n");
        }
        insert_single();
    }
    return 0;
}
int insert_single()
{
    int cell, num;
    for (int y = 1; y < 10; y++)
    {
        for (int l = 1; l < 2; l++)
        {
            srand(time(0));
            num = (rand() %
                   (9 - 1 + 1)) +
                  1;
        }
        if (y % 2 == !0)
        {
            printf("Enter Cell Number\n");
            scanf("%d", &cell);
            p = player;
            if (arr[(cell - 1)] == 'X' || arr[(cell - 1)] == 'O')
            {
                printf("Wrong choice\n");
                y = y - 1;
            }
            else if (cell < 1 || cell > 9)
            {
                printf("Wrong choice\n");
                y = y - 1;
            }
            else
            {
                arr[(cell - 1)] = p;
                int z = 0;
                for (int x = 0; x < 3; x++)
                {
                    printf("\t\t\t\t");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("%c\t", arr[z]);
                        z++;
                    }
                    printf("\n\n\n");
                }
            }
        }
        else if (y % 2 == 0)
        {
            cell = num;
            if (arr[(cell - 1)] == 'X' || arr[(cell - 1)] == 'O')
            {
                y = y - 1;
            }
            else
            {
                printf("Computer Choose %d\n", num);
                p = computer;
                arr[(cell - 1)] = p;
                int z = 0;
                for (int x = 0; x < 3; x++)
                {
                    printf("\t\t\t\t");
                    for (int i = 0; i < 3; i++)
                    {
                        printf("%c\t", arr[z]);
                        z++;
                    }
                    printf("\n\n\n");
                }
            }
        }
        i = checkwin();
        if (i == 1)
        {
            if (y % 2 == !0)
            {
                printf("You win\n");
                break;
            }
            else if (y % 2 == 0)
            {
                printf("Computer win\n");
                break;
            }
        }
        else if (i == 0)
        {
            printf("Game draw\n");
            break;
        }
    }
    printf("Good Bye");
    sleep(3);
    return 0;
}
int multi()
{
    printf("Player 1, Choose X or O\n");
    scanf(" %c", &player1);
    player1 = toupper(player1);
    if (player1 == 'X')
    {
        player2 = 'O';
        flag = 1;
    }
    else if (player1 == 'O')
    {
        player2 = 'X';
        flag = 1;
    }
    else
    {
        printf("I didn't understand you\nPlease choose again\n");
        multi();
    }
    if (flag == 1)
    {
        printf("Ok player 1 will be %c and player 2 will be %c\n", player1, player2);
        sleep(1);
        printf("Let's start\n\n");
        int z = 0;
        for (int x = 0; x < 3; x++)
        {
            printf("\t\t\t\t");
            for (int i = 0; i < 3; i++)
            {
                printf("%c\t", arr[z]);
                z++;
            }
            printf("\n\n\n");
        }
        insert();
    }
    return 0;
}
int insert()
{
    int cell;
    for (int y = 1; y < 10; y++)
    {
        if (y % 2 == !0)
        {
            printf("Player 1 Enter Cell Number\n");
            scanf("%d", &cell);
            p = player1;
        }
        else if (y % 2 == 0)
        {
            printf("Player 2 Enter Cell Number\n");
            scanf("%d", &cell);
            p = player2;
        }
        if (arr[(cell - 1)] == 'X' || arr[(cell - 1)] == 'O')
        {
            printf("Wrong choice\n");
            y = y - 1;
        }
        else if (cell < 1 || cell > 9)
        {
            printf("Wrong choice\n");
            y = y - 1;
        }
        else
        {
            arr[(cell - 1)] = p;
            int z = 0;
            for (int x = 0; x < 3; x++)
            {
                printf("\t\t\t\t");
                for (int i = 0; i < 3; i++)
                {
                    printf("%c\t", arr[z]);
                    z++;
                }
                printf("\n\n\n");
            }
        }
        i = checkwin();
        if (i == 1)
        {
            if (y % 2 == !0)
            {
                printf("Player 1 win\n");
                break;
            }
            else if (y % 2 == 0)
            {
                printf("Player 2 win\n");
                break;
            }
        }
        else if (i == 0)
        {
            printf("Game draw\n");
            break;
        }
    }
    printf("Good Bye");
    sleep(3);
    return 0;
}
int checkwin()
{
    if (arr[0] == arr[1] && arr[1] == arr[2])
        return 1;

    else if (arr[3] == arr[4] && arr[4] == arr[5])
        return 1;

    else if (arr[6] == arr[7] && arr[7] == arr[8])
        return 1;

    else if (arr[0] == arr[3] && arr[3] == arr[6])
        return 1;

    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;

    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;

    else if (arr[0] == arr[4] && arr[4] == arr[8])
        return 1;

    else if (arr[2] == arr[4] && arr[4] == arr[6])
        return 1;

    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' &&
             arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] != '7' && arr[7] != '8' && arr[8] != '9')

        return 0;
    else
        return -1;
}
