#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern x;
extern y;
extern peca[4][4];
extern alt;
extern larg;
extern tabuleiro[25][18];
extern i;
extern j;
extern CORPO;

void imprimirNoTabuleiro()//Essa fun��o, quando executada, vai fazer com o ch�o do tabuleiro aumente nas posi��es da pe�a, quando a mesma colidir, de maneira que agora a pe�a jog�vel vai empilhar no ch�o e virar o ch�o, para que a pr�xima pe�a jog�vel possa ser empilhada nela, j� que as pe�as jog�veis apenas colidem no ch�o
{
    for( i = 0; i < 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            if(peca[i][j] == CORPO)
            {
                tabuleiro[alt+i-1][larg + j] = 178;
            }
        }
    }
}

int colisao()//Essa fun��o vai conferir se embaixo da pe�a jog�vel existe um ch�o, caso exista, ela vai colidir e executar a fun��o acima, ela tamb�m ir� retornar o valor para ser usado como parametro em outras fun��es do programa
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if(peca[x][y] == CORPO && tabuleiro[alt+x][larg+y] == 178)
            {
                imprimirNoTabuleiro();
                return 1;
            }
        }
    }
}

void gotoxy(int x, int y)//A fun��o gotoxy move o cursor para as posi��es x e y, determinadas como argumento quando a fun��o � chamada, ela foi usada no jogo para imprimir a pe�a jog�vel em posi��es diferentes, simulando sua movimenta��o
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
mostrarPecaETabuleiro()//Essa fun��o serve para visualizar o jogo na tela, pois ela imprime as paredes do tabuleiro, o ch�o do tabuleiro, e tamb�m a pe�a jog�vel na sua posi��o determinada.
{
    system("cls");
    for(x = 0; x < 25; ++x)
    {
        for(y = 0; y < 18; ++y)
        {
            if(x == 24)
                tabuleiro[x][y] = 178;
            else if (y == 0 || y == 17)
                tabuleiro[x][y] = 219;
            printf("%c", tabuleiro[x][y]);
        }
        putchar('\n');
    }

    int var = alt;

    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if(peca[x][y] == CORPO)
            {
                gotoxy(larg+y, var+x);
                printf("%c", 219);

            }
        }
        gotoxy(larg+y, var+x+1);
    }
}

