#ifndef JOGO_H
#define JOGO_H

typedef struct {
    int id, quantidade_de_fichas;
    char user[100];
} Ficha;

int verificarVitoria(int tabuleiro[6][7], int id);
int verificarEmpate(int tabuleiro[6][7]);
int jogar(int tabuleiro[6][7], int coluna, int id);
void exibirTabuleiro(int tabuleiro[6][7], int id1, int id2);
int Inteiro(int valor);


#endif