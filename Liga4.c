#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id, quantidade_de_fichas;
    char user[100];
} Ficha;


//Função para verificar vitória

int verificarVitoria(int tabuleiro[6][7], int id1, int id2){
    // verificar horizontalmente
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i][j+1] == id1 && tabuleiro[i][j+2] == id1 && tabuleiro[i][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i][j+1] == id2 && tabuleiro[i][j+2] == id2 && tabuleiro[i][j+3] == id2){
                return id2;
            }
        }
        
    }

    // verificar verticalmente
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i+1][j] == id1 && tabuleiro[i+2][j] == id1 && tabuleiro[i+3][j] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i+1][j] == id2 && tabuleiro[i+2][j] == id2 && tabuleiro[i+3][j] == id2){

                return id2;
            }
        }
    }
    // verificar diagonal da direita

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i+1][j+1] == id1 && tabuleiro[i+2][j+2] == id1 && tabuleiro[i+3][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i+1][j+1] == id2 && tabuleiro[i+2][j+2] == id2 && tabuleiro[i+3][j+3] == id2){
                return id2;
            }
        }
    }

    // verificar diagonal da esquerda
    for (int i = 5; i >= 3; i--){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i-1][j+1] == id1 && tabuleiro[i-2][j+2] == id1 && tabuleiro[i-3][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i-1][j+1] == id2 && tabuleiro[i-2][j+2] == id2 && tabuleiro[i-3][j+3] == id2){
                return id2;
            }
        }
    }
}



//Função para jogar

int jogar(int tabuleiro[6][7], Ficha jogador){
    int coluna;
    while(1){
        printf("%s, escolha uma coluna de 1 a 7 para colocar a sua ficha: ", jogador.user);
        scanf("%d", &coluna);
        if (coluna < 1 || coluna > 7){
            printf("Coluna inválida. Tente novamente.\n");
            continue;
        }
        for (int i = 5; i >= 0; i--){
            if (tabuleiro[i][coluna-1] == 0){
                tabuleiro[i][coluna-1] = jogador.id;
                return 1;
            }
        }
        printf("Coluna cheia. Tente novamente.\n");
}
    
    }


    //função exibir tabuleiro
    void exibirTabuleiro(int tabuleiro[6][7]){
        printf("============LIG4++============\n");
        printf("\n");
        printf("  1   2   3   4   5   6   7  \n");
        printf("\n");
        for(int i = 0; i < 6; i++){
            printf("|");
            for(int j = 0; j < 7;j++){
                printf(" %d |",tabuleiro[i][j]);
            }
            printf("\n");
        } 
        
        printf("-----------------------------\n");
    }




int main() {
   int tema;

   srand(time(NULL));
   printf("Bem vindo ao Liga4!\n");
   puts("O jogo consiste em alinhar 4 peças na horizontal, vertical ou diagonal para vencer.");

   while(1){
   printf("Escolha o tema do jogo:\n1 - Individual(Player contra o computador)\n2 - Dois players\n3 - Simulado(computador contra computador)\n4 - Sair\n");
   scanf("%d", &tema);
   int tabuleiro[6][7] = {0};

    Ficha jogador1, jogador2;
    jogador1.id = 1;
    jogador2.id = 2;

     // Lógica para o tema individual
    if (tema == 1){
        printf("Tema Individual selecionado.\n");
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        strcpy(jogador2.user, "Computador");
        jogador1.quantidade_de_fichas = 21;
        jogador2.quantidade_de_fichas = 21;

        while(1){
            exibirTabuleiro(tabuleiro);
            jogar(tabuleiro, jogador1);
            jogador1.quantidade_de_fichas--;
            if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador1.id){
                exibirTabuleiro(tabuleiro);
                printf("Parabéns %s! Você venceu!\n", jogador1.user);
                break;
            }
            jogar(tabuleiro, jogador2);
            jogador2.quantidade_de_fichas--;
            if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro);
                printf("O %s venceu! Tente novamente.\n", jogador2.user);
                break;
            }
        }
          


        // Lógica para o tema dois players

    } else if (tema == 2){
        printf("Tema Dois players selecionado.\n");
    } else if (tema == 3){
        printf("Tema Simulado selecionado.\n");
        // Lógica para o tema simulado
    } else if (tema == 4){
        printf("Encerrando o jogo.\n");
        break;
    }

        }
   return 0;
}