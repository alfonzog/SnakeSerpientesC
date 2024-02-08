/*
 * Juego de serpientes in C
 */

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


int i, j, height = 20, width = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// fruit generation within the boundary
void fruits()
{
    gameover = 0;

    // store height and width
    x = height / 2;
    y = width / 2;
fruitsx:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto fruitsx;
fruitsy:
    fruity = rand() % 20;
    if (fruity == 0)
        goto fruitsy;
    score = 0;
}

void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
            {
                printf("%c", 177);
            }
            else
            {
                if (i == x && j == y)
                    printf("%c", 254);
                else if (i == fruitx
                    && j == fruity)
                    printf("%c", 3);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

void input()
{
    if (_kbhit())
    {
        switch (getch())
        {
        case 's':
            flag = 1;
            break;
        case 'a':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

void logic()
{
    Sleep(3);
    switch (flag)
    {
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }

    // game over
    if (x < 0 || x > height || y < 0 || y > width)
        gameover = 1;

    // snake reaches the fruit and the score gets updated
    if (x == fruitx && y == fruity)
    {
    logicx:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto logicx;

        // generation of new fruit after eating the current one
    logicy:
        fruity = rand() % 20;
        if (fruity == 0)
            goto logicy;
        score += 5;
    }
}

void main()
{
    // boundary generation
    fruits();

    // till the game is over
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
}