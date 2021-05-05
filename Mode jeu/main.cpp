    #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD point; // COORD est predefinie dans la biblio windwos.h
    point.X = (SHORT)x;
    point.Y = (SHORT)y;
    SetConsoleCursorPosition(H, point);
}

/****************************************************/
void Color(int flags)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, (WORD)flags);
}

/****************************************************/
void loading()
{
    int i;
    long double c;
    int f = 35;
    gotoxy(40, 15);
    Color(4);
    printf("Loading...");
    for (i = 0; i < 18; i++)
    {
        for (c = 0; c < 40000000; c++)
        {
        }
        gotoxy(f, 16);
        Color(1);
        printf("%c", 180);
        f++;
    }
    system("cls");
}
/****************************************************/
void init_stade()
{
    int j;
    int i;
    char ch[71][31];
    for (i = 20; i <= 70; i++)
    {
        for (j = 3; j <= 30; j++)
        {
            if ((i == 20) || (j == 3) || (j == 30) || (i == 70))
            {
                ch[i][j] = 177;
                gotoxy(i, j);
                Color(FOREGROUND_RED);
                printf("%c", ch[i][j]);
            }
        }
    }
}

int main()
{
    //loading();
    while (true)
    {
        char c = '1';
        char c1 = '1';
        char c2 = '1';
        char c3 = '1';
        init_stade();
        gotoxy(30, 8);
        Color(1);
        cout << "****************************** \n"
             << endl;
        gotoxy(29, 9);
        Color(4);
        cout << "Bienvenue dans le jeu Laser TAG \n"
             << endl;
        gotoxy(30, 10);
        Color(1);
        cout << "****************************** \n"
             << endl;
        gotoxy(27, 14);
        Color(3);
        cout << "choisissez un mode de jeu :\n"
             << endl;
        gotoxy(30, 15);
        cout << "1:Match a mort par equipe" << endl;
        gotoxy(30, 16);
        cout << "2:Capture du drapeau \n"
             << endl;
        gotoxy(30, 17);
        fflush(stdin);
        cout << "Choix:  ";
        c = getchar();
        system("cls");
        switch (c)
        {
        case '1':

            while (c1 != '4')
            {
                init_stade();
                gotoxy(30, 8);
                Color(14);
                cout << "****************************** \n"
                     << endl;
                gotoxy(29, 9);
                Color(4);
                cout << "          Match a mort par equipe \n"
                     << endl;
                gotoxy(30, 10);
                Color(14);
                cout << "****************************** \n"
                     << endl;
                gotoxy(27, 14);
                Color(3);
                cout << "choisir l'une des propositions suivantes :\n"
                     << endl;
                c1 = getchar();
                system("cls");
            }
            break;
        case '2':
            while (c2 != '3')
            {
                c3 = 1;
                init_stade();
                gotoxy(30, 8);
                Color(14);
                cout << "****************************** \n"
                     << endl;
                gotoxy(29, 9);
                Color(4);
                cout << "          Capture du drapeau \n"
                     << endl;
                gotoxy(30, 10);
                Color(14);
                cout << "****************************** \n"
                     << endl;
                gotoxy(27, 14);
                Color(1);
                cout << "choisir l'une des propositions suivantes :\n"
                     << endl;
                system("cls");

            }
        }
    }
    return 0;
}


