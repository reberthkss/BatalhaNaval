#include<stdio.h>
#include <stdlib.h>
#include"fPosicionar.h"
#include"fJogar.h"

int main()
{
    // tabuleiro A - tabuleiro B
    int tA[10][10],tB[10][10];
    int gameover = 1,gameover2 = 1;
    int cont = 0;
    int contpA1 = 1,contnT1 = 2, contcT1 = 3, contsM1 = 4;
    int contpA2 = 1,contnT2 = 2, contcT2 = 3, contsM2 = 4;
    int contpA3 = 0,contnT3 = 0, contcT3 = 0, contsM3 = 0;
    int contpA4 = 0,contnT4 = 0, contcT4 = 0, contsM4 = 0;
    int winner = -1;
    //linha e coluna
    int lEc[2];

    limparVet(tA);
    limparVet(tB);


    while(gameover)
    {

        int opt;

        printf("\t\t\t\tBEM VINDO\n");
        printf("\t\t\t      BATALHA Naval\n");

        printf("\n\t\t\t\t   MENU\n");
        printf("\t\t\t***************************\n");
        printf("\t\t\t*                         *\n");
        printf("\t\t\t*     [1] INICIAR JOGO    *\n");
        printf("\t\t\t*     [2] SAIR            *\n");
        printf("\t\t\t*                         *\n");
        printf("\t\t\t***************************\n");
        printf("\t\t\tDigite sua escolha: ");
        scanf("%i",&opt);
        switch(opt)
        {
        case 1:
            posicionar(tA,0);
            posicionar(tB,1);
            while(gameover2)
            {
                cont = 0;
                while(cont < 2)
                {
                    //mostrar(int* mat[10][10],int opt,int* pA,int* nT,int* cT,int* sM);

                    mostrar(tA,0,&contpA1,&contnT1,&contcT1,&contsM1);

                    mostrar(tB,1,&contpA2,&contnT2,&contcT2,&contsM2);

                    switch(cont)
                    {
                /*jogador 1*/   case 0:
                        /*linhaEcoluna, jogador01*/

                        jogada(lEc,0);

                        game(lEc,tB,&contpA2,&contpA3,&contnT2,&contnT3,&contcT2,&contcT3,&contsM2,&contsM3);

                        break;
                /*jogador 2*/   case 1:
                        jogada(lEc,1);
                        // game(lEc,tA,&contpA2,&contnT2,&contcT2,&contsM2);
                        game(lEc,tA,&contpA1,&contpA4,&contnT1,&contnT4,&contcT1,&contcT4,&contsM1,&contsM4);
                        break;
                    }





                    cont++;

                }
            }
            break;
        case 2:
            gameover = 0;
            break;
        }

        if(winner == 0)
        {
            printf("O JOGADOR VENCEDOR FOI O JOGADOR 01!!! PARABENS!\n");

            printf("VOLTANDO AO MENU PRINCIPAL...");

        }
        else
        {
            if(winner == 1)
            {
                printf("O JOGADOR VENCEDOR FOI O JOGADOR 02!!! PARABENS!\n");

                printf("VOLTANDO AO MENU PRINCIPAL...");

            }
        }
    }

    return 0;

}
