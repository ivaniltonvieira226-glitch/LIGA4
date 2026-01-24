#include <stdio.h>
#include <string.h>
#include "jogo.h"


//Função para verificar vitória

int verificarVitoria(int tabuleiro[6][7], int id){
    // verificar horizontalmente
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id && tabuleiro[i][j+1] == id
                && tabuleiro[i][j+2] == id && tabuleiro[i][j+3] == id){
                return id;
            }
        }
        
    }

    // verificar verticalmente
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == id && tabuleiro[i+1][j] == id 
                && tabuleiro[i+2][j] == id && tabuleiro[i+3][j] == id){
                return id;
            }
        }
    }
    
    // verificar diagonal da direita
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id && tabuleiro[i+1][j+1] == id && 
                tabuleiro[i+2][j+2] == id && tabuleiro[i+3][j+3] == id){
                return id;
            }
        }
    }

    // verificar diagonal da esquerda
    for (int i = 3; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id && tabuleiro[i-1][j+1] == id && tabuleiro[i-2][j+2] == id && tabuleiro[i-3][j+3] == id){
                return id;
            }
        }
    }

    return 0;
}


//função para verificar empate
int verificarEmpate(int tabuleiro[6][7]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == 0){
                return 0; 
            }
        }
    }

    return 1;
}
//Sempre valor inteiro

int Inteiro(int valor){
    if (valor != 1){
        while (getchar() != '\n');
        return 1;
    }

    return 0;
}

//Função para jogar

int jogar(int tabuleiro[6][7], int coluna, Ficha *jogador, int tabulerio_explosao[6][7]){
        if (coluna < 1 || coluna > 7){
            return 0;
        }

        //Ficha comum
        if(jogador->tipo_de_ficha == FICHA_COMUM){
        for (int i = 5; i >= 0; i--){
            if (tabuleiro[i][coluna-1] == 0){
                tabuleiro[i][coluna-1] = jogador->id;
                return 1;
            }
        }
        return 0;
    }
        //Ficha portal    
        else if(jogador->tipo_de_ficha == FICHA_PORTAL){
            
            
            // ficha portal substitui a primeira ficha do oponente que encontrar na coluna
            for (int i = 0; i < 6; i++){
                if (tabuleiro[i][coluna-1] != 0){
                    if(tabuleiro[i][coluna-1] != jogador->id){
                        tabuleiro[i][coluna-1] = 0;
                        return 1;
                    }
                    else if(tabuleiro[i][coluna-1] == jogador->id){
                        return 1;
                    }
                }
                else if(i == 5){
                    return 1;
                }  
        }
            return 0;
    }

        //Ficha explosiva
        else if(jogador->tipo_de_ficha == FICHA_EXPLOSIVA){
            
            for (int i = 5; i >= 0; i--){
                if (tabuleiro[i][coluna - 1] == 0){
                    tabuleiro[i][coluna - 1] = jogador->id;

                    tabulerio_explosao[i][coluna - 1] = jogador->id;

                    return 1;
                }
            }
        }

    }    



    //função exibir tabuleiro
    void exibirTabuleiro(int tabuleiro[6][7], int id1, int id2, int tabuleiro_explosao[6][7]){
        printf("============LIG4++============\n");
        printf("\n");
        printf("  1   2   3   4   5   6   7  \n");
        printf("\n");
        for(int i = 0; i < 6; i++){
            printf("|");
            for(int j = 0; j < 7;j++){
                if(id1 == tabuleiro[i][j]){
                    printf(" X");
                    if (tabuleiro_explosao[i][j] != 0){
                        printf("*|");
                    }
                    else{
                    printf(" |");
                }}
                else if(id2 == tabuleiro[i][j]){
                    printf(" O");
                    if (tabuleiro_explosao[i][j] != 0){
                        printf("k|");
                    }
                    else{
                    printf(" |");
                }
                }
                else{
                printf("   |");
                }
            }
            printf("\n");
        } 
        
        printf("-----------------------------\n");
    }

   
    //função tentar explodir
    void tentarexplodir(int tabuleiro[6][7], int tabuleiro_explosao[6][7], int i, int j){
        if (tabuleiro_explosao[i][j] == 0){
            return;
        }

        if (i == 0){
            return;
        }

        int bomba = tabuleiro_explosao[i][j];

        if (tabuleiro[i - 1] [j] == 0 || tabuleiro[i - 1][j] == bomba){
            return;
        }

        kabum(tabuleiro, tabuleiro_explosao, i, j);
}


 // função Kabum
   static void kabum(int tabuleiro[6][7], int tabuleiro_explosao[6][7], int i, int j){
        if (i < 0 || i >= 6 || j < 0 || j >= 7){
            return;
        }

        tabuleiro[i][j] = 0;
        tabuleiro_explosao[i][j] = 0;

        //cordenadas das 8 direções ao redor da bomba
        int tL[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int tC[8] = {0, 0, -1, 1, -1, 1, -1, 1};

        for (int m = 0; m < 8; m++){
            int novoI = i + tL[m];
            int novoJ = j + tC[m];

            if (novoI >= 0 && novoI < 6 && novoJ >= 0 && novoJ < 7){
              if (tabuleiro_explosao[novoI][novoJ] != 0){
                  kabum(tabuleiro, tabuleiro_explosao, novoI, novoJ);
              }

              else{
                    tabuleiro[novoI][novoJ] = 0;
              }
              
            }
        
        }
    }


// gravidade

    void gravidade(int tabuleiro[6][7]){
        for(int j = 0; j < 7; j++){
            for (int i = 5; i > 0; i--){
                if (tabuleiro[i][j] == 0 && tabuleiro[i - 1][j] != 0){
                    int temp = tabuleiro[i - 1][j];
                    tabuleiro[i - 1][j] = 0;
                    tabuleiro[i][j] = temp;
                }
            }
        }
    }