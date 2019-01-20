#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern peca[4][4];
extern CORPO;
extern valor;

escolherPeca()//Preenche a matriz peca com o valor da vari�vel CORPO, mas apenas nas posi��es da matriz que representam o formato da pe�a, pois futuramente o programa ir� verificar onde existe esse valor na matriz e imprimir� um s�mbolo da pe�a na tela, na posi��o que a pe�a jog�vel est�.
{
    switch(valor)//Ele vai escolher a pe�a baseado na vari�vel, que recebeu um valor aleat�rio de 1 a 7.
    {
    case 1:
        peca[2][2] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 2:
        peca[2][1] = CORPO;
        peca[2][2] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 3:
        peca[2][1] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 4:
        peca[2][2] = CORPO;
        peca[2][3] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        break;
    case 5:
        peca[3][0] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 6:
        peca[2][3] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
        peca[3][3] = CORPO;
        break;
    case 7:
        peca[2][1] = CORPO;
        peca[2][2] = CORPO;
        peca[3][1] = CORPO;
        peca[3][2] = CORPO;
    }
}

