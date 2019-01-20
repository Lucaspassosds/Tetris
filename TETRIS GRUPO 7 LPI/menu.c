int tempodequeda;//Essa vari�vel ir� ser respons�vel por definir o tempo padr�o que a pe�a levar� para cair, e pode ser ajustado pela dificuldade do jogo.

void capa()//Essa fun��o � puramente est�tica, mostra o nome do jogo.
{
    printf("--------------------------------------------------------\n");
    printf("----------------------TETRIS----------------------------\n");
    printf("--------------------------------------------------------\n\n\n");
}
void dificuldade()//Se essa fun��o for executada, o usu�rio ter� a op��o de escolher a dificuldade do jogo
{
    char decisao;
    system("cls");
    printf("Escolha a dificuldade:\n1)Facil\n2)Medio\n3)Dificil\n");
    decisao=getch();
    if(decisao==49)//Verifica se o usu�rio digitou o n�mero 1
        tempodequeda=400;
    else if(decisao=50)//Verifica se o usu�rio digitou o n�mero 2
        tempodequeda=270;
    else if(decisao=51)//Verifica se o usu�rio digitou o n�mero 3
        tempodequeda=75;
    else
        tempodequeda=400;//Caso o usu�rio n�o digite nenhum desses tr�s n�meros, o jogo por padr�o define a dificuldade como sendo F�CIL.

}
void decisoes(){//Essa fun��o vai receber uma informa��o do usu�rio, que ser� usada para executar a op��o do menu que ele escolheu.
   char decisao;
   while(1){
       decisao=getch();
       if(decisao==49)//Se o usu�rio escolheu para INICIAR, o jogo vai requisitar uma dificuldade e, quando est� for dada, iniciar� o jogo.
       {
           system("cls");
           dificuldade();
           jogar();
       }
       else if(decisao==50)
       {
           system("cls");
           Ranking();
       }
       else if(decisao==51)
       {
           system("cls");
           printf("FIM DE JOGO");
           exit(0);//Se o usu�rio escolheu SAIR, o programa fecha, retornando 0.
       }
   }
}
void menu()//Essa fun��o vai, primeiramente, mostrar as instru��es do jogo e, ap�s uma pausa, ir� mostras as op��es do Menu, depois vai executar uma fun��o que vai deixar o usu�rio escolher uma op��o
{
    capa();
    printf("       ATENCAO       \n");
    printf("-->Utilize as teclas A e D para mover a peca na tela.\n-->W para girar a peca.\n-->S para descer a peca mais rapidamente\n\n");
    system("pause");
    system("cls");
    capa();
    printf("1)INICIAR\n2)RANKING\n3)SAIR");
    decisoes();
}



