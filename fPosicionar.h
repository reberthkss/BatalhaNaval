#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED



void setArs(int* pA,int* nT,int* cT,int* sM);
int menuP();
int acao(int opt, int* gameover);
void posicionar(int tab[10][10],int opt);
void posicionarR(int tab[10][10]);
void limparVet(int mat[10][10]);
char* toString(int opt);

#endif // FUNCOES_H_INCLUDED
