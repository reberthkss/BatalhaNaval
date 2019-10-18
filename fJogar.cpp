#include "fJogar.h"
#include"fPosicionar.h"
#include<stdio.h>
#include<stdlib.h>


void mostrar(int mat[10][10],int opt,int* pA,int* nT,int* cT,int* sM)
{
    printf("\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(int i = 0 ; i < 10 ; i++)
    {
        printf("%i ",i);
        for(int j = 0; j < 10 ; j++)
        {
            switch(mat[i][j])
            {
            case -1:
                if(i == 0 && j == 9)
                {
                    printf("X \t\t\t\t%s",toString(opt));
                }
                else
                {
                    if(i == 1 && j == 9)
                    {
                        printf("X \t\t\t PORTA-AVIAO RESTANTE: %i",(*pA));
                    }
                    else
                    {
                        if(i == 2 && j == 9)
                        {
                            printf("X \t\t\t NAVIO-TANQUE RESTANTE: %i",(*nT));
                        }
                        else
                        {
                            if(i == 3 && j ==9)
                            {
                                printf("X \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*cT));
                            }
                            else
                            {
                                if(i == 4 && j == 9)
                                {
                                    printf("X \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*sM));
                                }
                                else
                                {
                                    printf("X ");
                                }
                            }
                        }
                    }
                }
                break;
            case -2:
                if(i == 0 && j == 9)
                {
                    printf(". \t\t\t\t%s",toString(opt));
                }
                else
                {
                    if(i == 1 && j == 9)
                    {
                        printf(". \t\t\t PORTA-AVIAO RESTANTE: %i",(*pA));
                    }
                    else
                    {
                        if(i == 2 && j == 9)
                        {
                            printf(". \t\t\t NAVIO-TANQUE RESTANTE: %i",(*nT));
                        }
                        else
                        {
                            if(i == 3 && j ==9)
                            {
                                printf(". \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*cT));
                            }
                            else
                            {
                                if(i == 4 && j == 9)
                                {
                                    printf(". \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*sM));
                                }
                                else
                                {
                                    printf(". ");
                                }
                            }
                        }
                    }
                }
                break;
            default:
                if(i == 0 && j == 9)
                {
                    printf("_ \t\t\t\t%s",toString(opt));
                }
                else
                {
                    if(i == 1 && j == 9)
                    {
                        printf("_ \t\t\t PORTA-AVIAO RESTANTE: %i",(*pA));
                    }
                    else
                    {
                        if(i == 2 && j == 9)
                        {
                            printf("_ \t\t\t NAVIO-TANQUE RESTANTE: %i",(*nT));
                        }
                        else
                        {
                            if(i == 3 && j ==9)
                            {
                                printf("_ \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*cT));
                            }
                            else
                            {
                                if(i == 4 && j == 9)
                                {
                                    printf("_ \t\t\t CONTRA-TORPEDEIRO RESTANTE: %i",(*sM));
                                }
                                else
                                {
                                    printf("_ ");
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        printf("\n");
    }


}

int jogada(int linecol[],int opt)
{

    printf("\t\t\t %s EH QUEM JOGA AGORA!!!\n",toString(opt));
    printf("ESCOLHA A POSICAO DO TABULEIRO DO %s PARA REALIZAR O ATAQUE!!\n",toString(opt-1));
    printf("LINHA[0-9]: ");
    scanf("%i",&linecol[0]);
    printf("COLUNA[0-9]: ");
    scanf("%i",&linecol[1]);

    return linecol[2];
}

void game(int linecol[],int mat[10][10],int* pA,int* cpA,int* nT,int* cnT,int* cT,int* ccT,int* sM,int* csM)
{

    switch(mat[linecol[0]][linecol[1]])
    {
    case -1:
        printf("VOCE JA ATACOU ESTA POSICAO!! NAO HA NADA AQUI\n!!");
        break;
    case 0:
        printf("VOCE NAO ACERTOU NENHUMA EMBARCACAO!!!\n");
        mat[linecol[0]][linecol[1]] = -2;

        break;
    case 1:
        printf("VOCE ACERTOU UMA EMBARCACAO!!!\n");

        mat[linecol[0]][linecol[1]] = -1;
        (*cpA)++;

        printf("%i",*cpA == 4);
        if((*cpA) == 4)
        {

            if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]-1] == -1 && mat[linecol[0]][linecol[1]-2] == -1 && mat[linecol[0]][linecol[1]-3] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]+1] == -1 && mat[linecol[0]][linecol[1]+2] == -1 && mat[linecol[0]][linecol[1]+3] == -1)
            {
                printf("VOCE DETRUIU UM PORTA AVIOES!!");
                (*pA)--;
            }
            else
            {
                if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]-1][linecol[1]] == -1 && mat[linecol[0]-2][linecol[1]] == -1 && mat[linecol[0]-3][linecol[1]] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]+1][linecol[1]] == -1 && mat[linecol[0]+2][linecol[1]] == -1 && mat[linecol[0]+3][linecol[1]] == -1)
                {
                    printf("VOCE DESTRIU UM PORTA-AVIOES!!");
                    (*pA)--;
                }
            }
        }
        break;
    case 2:

        printf("VOCE ACERTOU UMA EMBARCACAO!!!\n");

        mat[linecol[0]][linecol[1]] = -1;





        if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]-1] == -1 && mat[linecol[0]][linecol[1]-2] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]+1] == -1 && mat[linecol[0]][linecol[1]+2] == -1)
        {
            printf("VOCE DETRUIU UM NAVIO TANQUE!!");
            (*nT)--;
        }
        else
        {
            if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]-1][linecol[1]] == -1 && mat[linecol[0]-2][linecol[1]] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]+1][linecol[1]] == -1 && mat[linecol[0]+2][linecol[1]] == -1)
            {
                printf("VOCE DESTRIU UM NAVIO TANQUE!!");
                (*nT)--;
            }
        }
        break;
    case 3:
        printf("VOCE ACERTOU UMA EMBARCACAO!!!\n");

        mat[linecol[0]][linecol[1]] = -1;





        if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]-1] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]][linecol[1]+1] == -1)
        {
            printf("VOCE DETRUIU UM CONTRA-TORPEDEIRO!!");
            (*cT)--;
        }
        else
        {
            if(mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]-1][linecol[1]] == -1 || mat[linecol[0]][linecol[1]] == -1 && mat[linecol[0]+1][linecol[1]] == -1)
            {
                printf("VOCE DESTRIU UM CONTRA-TORPEDEIRO!!");
                (*cT)--;
            }
        }
        break;
    case 4:
        printf("VOCE ACERTOU UMA EMBARCACAO!!!\n");

        mat[linecol[0]][linecol[1]] = -1;

        printf("VOCE DETRUIU UM SUBMARINO!!");
        (*sM)--;
        break;
    }
}
