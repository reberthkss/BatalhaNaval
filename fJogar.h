#ifndef FJOGAR_H_INCLUDED
#define FJOGAR_H_INCLUDED

void game(int linecol[],int mat[10][10],int* pA,int* cpA,int* nT,int* cnT,int* cT,int* ccT,int* sM,int* csM);
void gameR(int linecol[],int mat[10][10],int* pA,int* cpA,int* nT,int* cnT,int* cT,int* ccT,int* sM,int* csM);
int jogada(int linecol[],int opt);
int jogadarR(int linecol[]);
void mostrar(int mat[10][10],int opt,int* pA,int* nT,int* cT,int* sM);

#endif // FJOGAR_H_INCLUDED
