#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


extern peca[4][4], tabuleiro[25][18], CORPO, x, y, valor, alt, larg,tempodequeda;
int tempo, ponto;//A vari�vel tempo ir� ser usada para definir o intervalo de tempo necess�rio para que a pe�a des�a no tabuleiro


void reiniciar()//Quando essa fun��o for executada, ir� limpar para que n�o seja mostrado nenhuma nova pe�a nele durante a execu��o do jogo, quando o jogo for reiniciado
{
    for(x = 0; x < 25; x++)
    {
        for(y = 0; y < 18; y++)
        {
            tabuleiro[x][y] = 0;//Est� anulando os valores existentes na matriz tabuleiro
        }
    }
}


int fim()//Quando essa fun��o retornar o valor 1, significa que o jogo terminou, ou seja, a pilha de pe�as alcan�ou o "teto" do tabuleiro
{
    for(x = 1; x < 17; ++x)
    {
        if(tabuleiro[3][x] == 178)
        {
            return 1;
        }
    }
}

int movDireita()//Essa fun��o vai garantir que a pe�a jog�vel n�o atravesse as paredes do tabuleiro para a direita
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if((peca[x][y] == CORPO && tabuleiro[alt+x][larg+y+1] == 219) ||
                    (peca[x][y] == CORPO && tabuleiro[alt+x][larg+y+1] == 178))
            {
                return 1;
            }
        }
    }
}
int movEsquerda()//Essa fun��o vai garantir que a pe�a jog�vel n�o atravesse as paredes do tabuleiro para a esquerda
{
    for(x = 0; x < 4; ++x)
    {
        for(y = 0; y < 4; ++y)
        {
            if((peca[x][y] == CORPO && tabuleiro[alt+x][larg+y-1] == 219)||
                    (peca[x][y] == CORPO && tabuleiro[alt+x][larg+y-1] == 178))
            {
                return 1;
            }
        }
    }
}
void checarColisao()//Essa fun��o diz que, caso haja um colis�o, vai sortear uma pr�xima pe�a jog�vel e tamb�m vai mudar a posi��o onde ela vai aparecer, al�m disso, vai somar um ponto na pontua��o do jogador
{
    if(colisao() == 1)
    {
        alt = -1;
        larg = 5;
        valor = 1 + rand()%7;
        limparPeca();
        escolherPeca();
        ponto++;
    }

}

void jogar()//Essa fun��o far� com a pe�a se locomova no tabuleiro, e � composta por outras fun��es que servem para mostrar o jogo, impedir que a pe�a jog�vel ultrapasse os limites do tabuleiro e decidir se o jogador perdeu ou n�o o jogo.
{
    while(1)//A fun��o est� em loop
    {
        while(!kbhit())//Enquanto o usu�rio n�o digita nada
        {
            if(fim() == 1)//Caso essa condi��o se satisfa�a, o jogo acaba e volta para o inicio.
            {
                system("cls");
                printf("---GAME OVER---\n\n");
                printf("Voce fez: %d pontos\n\n", ponto);
                printf("Aperte qualquer tecla para computar a pontuacao...");
                getch();
                reiniciar();
                system("cls");
                pontuacao(ponto);
            }
            completarLinha();
            Sleep(tempo);
            checarColisao();
            mostrarPecaETabuleiro();
            ++alt;
            tempo = tempodequeda;
        }
        char mov = getch();//Vai receber um comando do usu�rio que pode ser usado para movimentar a pe�a.
        switch(mov)
        {
        case 'p'://P pausa o jogo
            getch();
            break;
        case 'd'://D move para a direita
            if(movDireita()!=1)
            {
                ++larg;
            }
            break;
        case 'a'://A para a esquerda
            if(movEsquerda()!=1)
            {
                --larg;
            }
            break;
        case 's'://S diminui o tempo necess�rio para a pe�a cair, logo, vai fazer ela descer mais rapidamente
            tempo = 50;
            break;
        case 'w'://W vai executar uma fun��o que gira a pe�a.
            if(movDireita()!=1 && movEsquerda()!=1)//Ela nao rotaciona quando encostada nas paredes
            {
                rotacionar();
            }
        }
    }
}
