#ifndef JOGO_H
#define JOGO_H

//Struct dos tipos de fichas
typedef enum{
    FICHA_COMUM = 1,
    FICHA_PORTAL = 2,
    FICHA_EXPLOSIVA = 3,
} Tipo_ficha;

// Struct do jogador
typedef struct {
    int id, quantidade_de_fichas;
    Tipo_ficha tipo_de_ficha;
    char user[100];
} Ficha;

int verificarVitoria(int tabuleiro[6][7], int id);
int verificarEmpate(int tabuleiro[6][7]);
int jogar(int tabuleiro[6][7], int coluna, Ficha *jogador);
void exibirTabuleiro(int tabuleiro[6][7], int id1, int id2);
int Inteiro(int valor);


#endif