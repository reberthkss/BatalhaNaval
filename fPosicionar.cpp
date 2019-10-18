#include"fPosicionar.h";
#include<stdio.h>
#include<stdlib.h>
#include <iostream>



struct arsenal
{
    int pA;
    int nT;
    int cT;
    int sM;
};

void setArs(int* pA,int* nT, int* cT, int* sM)
{

    *pA = 1;
    *nT = 2;
    *cT = 3;
    *sM = 4;
}

char* toString(int opt)
{

    if(opt == 0)
    {
        return "JOGADOR 01";
    }
    else
    {
        return "JOGADOR 02";
    }
}

void posicionar(int tab[10][10],int opt)
{
    // porta avioes - navios tanque - contra torpedeiros - submarinos
    int pA[4],nT[3],cT[2],sM[1];


    struct arsenal jog1;
    setArs(&jog1.pA,&jog1.nT,&jog1.cT,&jog1.sM);

    int jogada;
    int peca;
    int i;
    int menu2;
    int ver = 0;
    int lixo;


    while(jog1.pA > 0  || jog1.nT > 0 || jog1.cT > 0 || jog1.sM > 0)
    {
        int direcao,contVet = 0,contHor = 0;
        int linha = 0;
        int coluna = 0;

        //Isso aqui vai virar uma funcao, não sei ainda como passar matriz para uma função


        printf("*****************************\n");
        printf("*           LEGENDA         *\n");
        printf("* _ = VAZIO                 *\n");
        printf("* # = PORTA-AVIOES          *\n");
        printf("* $ = NAVIOS-TANQUE         *\n");
        printf("* @ = CONTRA-TORPEDEIROS    *\n");
        printf("* * = SUBMARINO             *\n");
        printf("*****************************\n");
        printf("%s\n",toString(opt));
        printf("   0  1  2  3  4  5  6  7  8  9\n");
        for(i = 0 ; i < 10 ; i++)
        {
            printf("%i ",i);
            for(int j = 0; j < 10 ; j++)
            {
                switch(tab[i][j])
                {
                case 0:
                    printf("|_|");
                    break;
                case 1:
                    printf("|#|");
                    break;
                case 2:
                    printf("|$|");
                    break;
                case 3:
                    printf("|@|");
                    break;
                case 4:
                    printf("|*|");
                    break;
                }
            }
            printf("\n");
        }
        //até aqui
        printf("**************************************************\n");
        printf("*         PECAS DISPONIVEIS PARA O %s    *\n",toString(opt));
        printf("*  [0] PORTA AVIOES.                    QTD:  %i  *\n",jog1.pA);
        printf("*  [1] NAVIOS-TANQUE.                   QTD:  %i  *\n",jog1.nT);
        printf("*  [2] CONTRA-TORPEDEIROS.              QTD:  %i  *\n",jog1.cT);
        printf("*  [3] SUBMARINOS.                      QTD:  %i  *\n",jog1.sM);
        printf("**************************************************\n");
        printf("%s, de 0 - 3 digite a opcao da peca a ser posicionada: ",toString(opt));
        scanf("%i",&peca);

        switch(peca)
        {
        case 0:
            printf("PECA ESCOLHIDA: PORTA-AVIOES\n");

            if(jog1.pA == 0)
            {
                printf("VOCE NAO TEM NENHUM PORTA-AVIAO EM SEU ARSENAL!! VOLTANDO.... \n");
                menu2 = scanf("%i",&lixo);
                break;
            }
            printf("DIGITE A LINHA QUE VOCE DESEJA POSICIONAR O PORTA-AVIAO: ");
            scanf("%i",&linha);

            printf("\n");
            printf("DIGITE A COLUNA QUE VOCE DESEJA POSICIONAR O PORTA-AVIAO: ");
            scanf("%i",&coluna);
            printf("\n");



            printf("VOCE DESEJA POSICIONAR NA VERTICAL OU NA HORIZONTAL? ");
            printf("[0] VERTICAL [1] HORIZONTAL: ");
            scanf("%i", &direcao);

            if(direcao == 0)
            {
                contVet = 4;
                i = 0;
            }
            else
            {
                contHor = 4;
                i = 0;
            }

            if(contVet + linha >= 10 || contHor + coluna >= 10)
            {
                ver = 1;
            }

            for(i = 0 ; i < contVet ; i++)
            {
                if(tab[linha+i][coluna] != 0)
                {
                    ver = 1;
                }
            }
            for(i = 0 ; i < contHor ; i++)
            {
                if(tab[linha][coluna+i] != 0)
                {
                    ver = 1;
                }
            }

            if(ver)
            {
                printf("NAO EH POSSIVEL POSICIONAR O PORTA-AVIAO POIS ELE\n");
                printf("ULTRAPASSA O LIMITE DO TABULEIRO OU SOBREPOE UMA PECA\n");
                printf("VOLTANDO... DIGITE QUALQUER TECLA");
                ver = 0;
            }
            else
            {
                i = 0;
                if(contVet > 0)
                {
                    while(contVet != 0)
                    {
                        tab[linha+i][coluna] = 1;
                        contVet--;
                        i++;
                    }
                }
                else
                {
                    while(contHor != 0)
                    {
                        tab[linha][coluna+i] = 1;
                        contHor--;
                        i++;
                    }
                }
                jog1.pA--;
            }
            break;
        case 1:

            printf("PECA ESCOLHIDA: NAVIO-TANQUE\n");

            if(jog1.nT == 0)
            {
                printf("VOCE NAO TEM NENHUM NAVIO-TANQUE EM SEU ARSENAL!! VOLTANDO.... \n");
                menu2 = scanf("%i",&lixo);
                break;
            }
            printf("DIGITE A LINHA QUE VOCE DESEJA POSICIONAR O NAVIO-TANQUE: ");
            scanf("%i",&linha);

            printf("\n");
            printf("DIGITE A COLUNA QUE VOCE DESEJA POSICIONAR O NAVIO-TANQUE: ");
            scanf("%i",&coluna);
            printf("\n");



            printf("VOCE DESEJA POSICIONAR NA VERTICAL OU NA HORIZONTAL? ");
            printf("[0] VERTICAL [1] HORIZONTAL: ");
            scanf("%i", &direcao);

            if(direcao == 0)
            {
                contVet = 3;
                i = 0;
            }
            else
            {
                contHor = 3;
                i = 0;
            }

            if(contVet + linha >= 10 || contHor + coluna >= 10)
            {
                ver = 1;
            }

            for(i = 0 ; i < contVet ; i++)
            {
                if(tab[linha+i][coluna] != 0)
                {
                    ver = 1;
                }
            }
            for(i = 0 ; i < contHor ; i++)
            {
                if(tab[linha][coluna+i] != 0)
                {
                    ver = 1;
                }
            }

            if(ver)
            {
                printf("NAO EH POSSIVEL POSICIONAR O NAVIO-TANQUE POIS ELE\n");
                printf("ULTRAPASSA O LIMITE DO TABULEIRO OU SOBREPOE UMA PECA\n");
                printf("VOLTANDO... DIGITE QUALQUER TECLA");
                ver = 0;
            }
            else
            {
                i = 0;
                if(contVet > 0)
                {
                    while(contVet != 0)
                    {
                        tab[linha+i][coluna] = 2;
                        contVet--;
                        i++;
                    }
                }
                else
                {
                    while(contHor != 0)
                    {
                        tab[linha][coluna+i] = 2;
                        contHor--;
                        i++;
                    }
                }
                jog1.nT--;
            }
            break;
        case 2:
            printf("PECA ESCOLHIDA: CONTRA-TORPEDEIRO\n");

            if(jog1.cT == 0)
            {
                printf("VOCE NAO TEM NENHUM CONTRA-TORPEDEIRO EM SEU ARSENAL!! VOLTANDO.... \n");
                menu2 = scanf("%i",&lixo);
                break;
            }
            printf("DIGITE A LINHA QUE VOCE DESEJA POSICIONAR O CONTRA-TORPEDEIRO: ");
            scanf("%i",&linha);

            printf("\n");
            printf("DIGITE A COLUNA QUE VOCE DESEJA POSICIONAR O CONTRA-TORPEDEIRO: ");
            scanf("%i",&coluna);
            printf("\n");



            printf("VOCE DESEJA POSICIONAR NA VERTICAL OU NA HORIZONTAL? ");
            printf("[0] VERTICAL [1] HORIZONTAL: ");
            scanf("%i", &direcao);

            if(direcao == 0)
            {
                contVet = 2;
                i = 0;
            }
            else
            {
                contHor = 2;
                i = 0;
            }

            if(contVet + linha >= 10 || contHor + coluna >= 10)
            {
                ver = 1;
            }

            for(i = 0 ; i < contVet ; i++)
            {
                if(tab[linha+i][coluna] != 0)
                {
                    ver = 1;
                }
            }
            for(i = 0 ; i < contHor ; i++)
            {
                if(tab[linha][coluna+i] != 0)
                {
                    ver = 1;
                }
            }

            if(ver)
            {
                printf("NAO EH POSSIVEL POSICIONAR O CONTRA-TORPEDEIRO POIS ELE\n");
                printf("ULTRAPASSA O LIMITE DO TABULEIRO OU SOBREPOE UMA PECA\n");
                printf("VOLTANDO... DIGITE QUALQUER TECLA");
                menu2 = scanf("%i",&lixo);
                ver = 0;
            }
            else
            {
                i = 0;
                if(contVet > 0)
                {
                    while(contVet != 0)
                    {
                        tab[linha+i][coluna] = 3;
                        contVet--;
                        i++;
                    }
                }
                else
                {
                    while(contHor != 0)
                    {
                        tab[linha][coluna+i] = 3;
                        contHor--;
                        i++;
                    }
                }
                jog1.cT--;
            }
            break;
        case 3:
            printf("PECA ESCOLHIDA: SUBMARINO\n");

            if(jog1.sM == 0)
            {
                printf("VOCE NAO TEM NENHUM SUBMARINO EM SEU ARSENAL!! VOLTANDO.... \n");
                menu2 = scanf("%i",&lixo);
                break;
            }
            printf("DIGITE A LINHA QUE VOCE DESEJA POSICIONAR O SUBMARINO: ");
            scanf("%i",&linha);

            printf("\n");
            printf("DIGITE A COLUNA QUE VOCE DESEJA POSICIONAR O SUBMARINO: ");
            scanf("%i",&coluna);
            printf("\n");



            printf("VOCE DESEJA POSICIONAR NA VERTICAL OU NA HORIZONTAL? ");
            printf("[0] VERTICAL [1] HORIZONTAL: ");
            scanf("%i", &direcao);

            if(direcao == 0)
            {
                contVet = 1;
                i = 0;
            }
            else
            {
                contHor = 1;
                i = 0;
            }


            for(i = 0 ; i < contVet ; i++)
            {
                if(tab[linha+i][coluna] != 0)
                {
                    ver = 1;
                }
            }
            for(i = 0 ; i < contHor ; i++)
            {
                if(tab[linha][coluna+i] != 0)
                {
                    ver = 1;
                }
            }

            if(ver)
            {
                printf("NAO EH POSSIVEL POSICIONAR O SUBMARINO POIS ELE\n");
                printf("ULTRAPASSA O LIMITE DO TABULEIRO OU SOBREPOE UMA PECA\n");
                printf("VOLTANDO... DIGITE QUALQUER TECLA");
                menu2 = scanf("%i",&lixo);
                ver = 0;
            }
            else
            {
                i = 0;
                if(contVet > 0)
                {
                    while(contVet != 0)
                    {
                        tab[linha+i][coluna] = 4;
                        contVet--;
                        i++;
                    }
                }
                else
                {
                    while(contHor != 0)
                    {
                        tab[linha][coluna+i] = 4;
                        contHor--;
                        i++;
                    }
                }
                jog1.sM--;
            }
            break;
        case 4:
            //pA
            tab[0][9] = 1;
            tab[1][9] = 1;
            tab[2][9] = 1;
            tab[3][9] = 1;
            //nT1
            tab[4][7] = 2;
            tab[4][8] = 2;
            tab[4][9] = 2;
            //nT2
            tab[3][0] = 2;
            tab[3][1] = 2;
            tab[3][2] = 2;

            //cT1
            tab[9][8] = 3;
            tab[9][9] = 3;
            //cT2
            tab[8][1] = 3;
            tab[9][1] = 3;
            //cT3
            tab[5][0] = 3;
            tab[5][1] = 3;

            //sM1
            tab[6][0] = 4;
            //sM2
            tab[7][0] = 4;
            //s3
            tab[8][0] = 4;
            //sM4
            tab[9][0] = 4;


            jog1.pA = 0;
            jog1.nT = 0;
            jog1.cT = 0;
            jog1.sM = 0;
            break;

        }
    }
}


void limparVet(int mat[10][10])
{
    //limpa matriz
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            mat[i][j] = 0;
        }
    }
}
