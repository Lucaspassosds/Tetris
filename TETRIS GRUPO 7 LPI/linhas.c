#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern alt;
extern larg;
extern x;
extern y;
extern tabuleiro[25][18];
extern ponto;


void apagar(int linha)//Se essa fun��o for chamada, vai apagar uma linha no tabuleiro, e a linha anterior vai assumir o lugar da linha que acabou de ser apagada. Ela recebo como argumento um valor que represanta a linha que vai ser apagada.
{
    for(x = linha; x > 1; --x)
    {
        for(y = 1; y < 17; ++y)
        {
            tabuleiro[x][y] = tabuleiro[x-1][y];

        }
    }
    ponto=ponto+10;//Caso isso aconte�a, o jogador ganha 10 pontos.
}

void completarLinha()//Essa fun��o vai verificar se uma linha da matriz tabuleiro foi preenchida com pe�as, caso for, ela executar� uma fun��o que apaga essa linha.
{
    int linha, col;
    for(linha = 0; linha < 24; ++linha)//Esse for s� vai at� a linha 24, pois a linha seguinte � o ch�o. E o ch�o n�o pode ser apagado pela fun��o apagar
    {
        int contarCorpo = 0;
        for(col = 1; col < 17; ++col)//O mesmo serve para as paredes que ficam na direita e esquerda, elas n�o precisam ser apagadas.
        {
            if(tabuleiro[linha][col] == 178)
                ++contarCorpo;
            if(contarCorpo == 16)
            {
                apagar(linha);
            }
        }
    }
}
