#include <stdlib.h>
#include "inicio.h"

int alt;//Altura de pe�a que o jogador pode mover
int larg = 5;//Posi��o da pe�a que a pe�a poder� na esquerda ou para a direita
int tabuleiro[25][18] = {0};//Matriz que vai formar o tabuleiro do jogo
int peca[4][4] = {0};//Matriz que vai formar a pe�a jog�vel
int CORPO = 2;//Vai definir o valor a ser preenchido na matriz pe�a
int x, y, i, j;//Essas vari�veis ser�o usadas em diversos loops do tipo for durante a execu��o do programa
int valor;//Esse valor ser� aleat�rio e vai ser usado para definir a pe�a jog�vel
extern ponto;//Essa vari�vel ser� usada para contar os pontos do jogador

inicio()//Fun��o que vai iniciar o jogo, ela ser� chamada mais de uma vez durante a execu��o do programa caso o jogo for reiniciado
{
    limparPeca();//Retira quaisquer valores da matriz peca
    alt = 0;//Define a altura da peca como sendo 0
    srand(time(NULL));
    valor  = 1 + rand()%7;//Sorteia uma peca com valor de 1 a 7(pois sao 7 pe�as)
    escolherPeca();//Escolhe uma pe�a pra ser usada no jogo
    menu();//Mostra o menu do jogo
    ponto=0;//Zera os pontos do jogador
}
