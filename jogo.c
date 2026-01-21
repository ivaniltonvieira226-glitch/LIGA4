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

int jogar(int tabuleiro[6][7], int coluna, Ficha *jogador){
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
                        tabuleiro[i][coluna-1] = jogador->id;
                        return 1;
                    }
                    
                    // ficha portal não pode substituir a própria ficha
                    else if(i != 0){
                        if (tabuleiro[i - 1][coluna - 1] == 0){
                            tabuleiro[i - 1][coluna - 1] = jogador->id;
                            return 1;
                        }
                    }
                }

                // se não encontrar nenhuma ficha abaixo, ele some e gasta uma jogada
                else if(i == 5){
                    return 1;
                }  
        }
            return 0;
    }

        //Ficha explosiva


    }    



    //função exibir tabuleiro
    void exibirTabuleiro(int tabuleiro[6][7], int id1, int id2){
        printf("============LIG4++============\n");
        printf("\n");
        printf("  1   2   3   4   5   6   7  \n");
        printf("\n");
        for(int i = 0; i < 6; i++){
            printf("|");
            for(int j = 0; j < 7;j++){
                if(id1 == tabuleiro[i][j]){
                    printf(" X |");
                }
                else if(id2 == tabuleiro[i][j]){
                    printf(" O |");
                }
                else{
                printf(" - |");
                }
            }
            printf("\n");
        } 
        
        printf("-----------------------------\n");
    }

   