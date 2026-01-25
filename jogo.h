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
    int id, fichas_comuns, fichas_portais, fichas_explosivas;
    Tipo_ficha tipo_de_ficha;
    char user[100];
} Ficha;

int verificarVitoria(int tabuleiro[6][7], int id);
int verificarEmpate(int tabuleiro[6][7]);
int jogar(int tabuleiro[6][7], int coluna, Ficha *jogador, int tabuleiro_explosao[6][7]);
void exibirTabuleiro(int tabuleiro[6][7], int id1, int id2, int tabuleiro_explosao[6][7]);
int Inteiro(int valor);
void tentarexplodir(int tabuleiro[6][7], int tabuleiro_explosao[6][7], int i, int j);
void gravidade(int tabuleiro[6][7]);
static void kabum(int tabuleiro[6][7], int tabuleiro_explosao[6][7], int i, int j);
#endif