#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

unsigned static int SCORE = 0;
unsigned int HEIGHT = 20;
unsigned int WIDTH = 50;
static int tmpA = 0;
static int tmpS = 0;
static int tmpW = 0;
static int tmpD = 0;
int direction = 0;
int gameOver = 0;
int initPosX = 25;
int initPosY = 10;
int foodX = rand() % 20;
int foodY = rand() % 20;

void generateFood()
{
    foodX = rand() % 30;
    foodY = rand() % 10;
    for (int i = 0; i < foodY; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < foodX; i++)
    {
        cout << " ";
    }
    cout << "$";
}

void createGame()
{
    if (initPosX >= 50 || initPosY >= 20)
    {

        cout << "Game Over...";
        gameOver = 1;
        return;
    }

    else if (initPosX == 0 || initPosY == 0)
    {
        cout << "Game Over...";
        gameOver = 1;
        return;
    }

    system("cls");
    for (int i = 0; i < WIDTH; i++)
    {
        cout << "*";
    }
    cout << endl;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (j == 0 || j == WIDTH - 1)
            {
                cout << "*";
            }
            else if (i == foodY && j == foodX)
            {
                cout << "$";
            }
            else
            {
                cout << " ";
            }
            if (j == WIDTH - 1)
            {
                cout << endl;
            }
        }
    }
    for (int i = 0; i < WIDTH; i++)
    {
        cout << "*";
    }
}

void MoveSnake()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            direction = 1;
            tmpA++;
            break;
        case 's':
            direction = 2;
            tmpS++;
            break;
        case 'd':
            direction = 3;
            tmpD++;
            break;
        case 'w':
            direction = 4;
            tmpW++;
            break;
        case 'q':
            gameOver = 1;
            break;
        }
    }
}

void drawSnake()
{
    system("cls");

    if (direction == 1)
    {
        initPosX--;
        for (int i = 0; i < initPosY; i++)
        {
            cout << endl;
        }
        for (int i = 0; i < (initPosX - tmpA); i++)
        {
            cout << " ";
        }
        cout << "0";
        if (initPosX == foodX && initPosY == foodY)
        {
            generateFood();
            SCORE++;
        }
        return;
    }
    else if (direction == 2)
    {
        initPosY++;
        for (int i = 0; i < (initPosY + tmpS); i++)
        {
            cout << endl;
        }
        for (int i = 0; i < initPosX; i++)
        {
            cout << " ";
        }
        cout << "0";
        if (initPosX == foodX && initPosY == foodY)
        {
            generateFood();
            SCORE++;
        }
        return;
    }
    else if (direction == 3)
    {
        initPosX++;
        for (int i = 0; i < initPosY; i++)
        {
            cout << endl;
        }
        for (int i = 0; i < (initPosX + tmpD); i++)
        {
            cout << " ";
        }
        cout << "0";
        if (initPosX == foodX && initPosY == foodY)
        {
            generateFood();
            SCORE++;
        }
        return;
    }
    else if (direction == 4)
    {
        initPosY--;
        for (int i = 0; i < (initPosY - tmpW); i++)
        {
            cout << endl;
        }
        for (int i = 0; i < initPosX; i++)
        {
            cout << " ";
        }
        cout << "0";
        if (initPosX == foodX && initPosY == foodY)
        {
            generateFood();
            SCORE++;
        }
        return;
    }
    for (int i = 0; i < initPosY; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < initPosX; i++)
    {
        cout << " ";
    }
    cout << "0";
    if (initPosX == foodX && initPosY == foodY)
    {
        generateFood();
        SCORE++;
    }
}

int main()
{
    int start = 1;

    while (gameOver != 1)
    {
        createGame();
        drawSnake();
        MoveSnake();
    }

    if (gameOver == 1)
    {
        cout << "GAME OVER..." << endl;
        cout << "Score is: " << SCORE;
    }
}