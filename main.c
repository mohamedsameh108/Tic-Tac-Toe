#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag;
    char player1, player2;
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
        flag = 0;
    }
    if (flag == 1)
    {
        printf("Ok player 1 will be %c and player 2 will be %c\n", player1, player2);
        sleep(1);
        printf("Let's start\n\n");
        game();
    }
    else if (flag == 0)
    {
        main();
    }
    return 0;
}
int game()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int z = 0;
    for (int x = 0; x < 3; x++)
    {
        printf("\t\t\t\t");
        for (int i = 0; i < 3; i++)
        {
            printf("%d\t", arr[z]);
            z++;
        }
        printf("\n\n\n");
    }
    return 0;
}
