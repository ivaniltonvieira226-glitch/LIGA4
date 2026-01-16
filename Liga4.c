#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
    int id;
    char user[100];
} Ficha;

int verificarVitoria(int tabuleiro[6][7], Ficha user1, Ficha user2){
    // verificar horizontalmente
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == user1.id && tabuleiro[i][j+1] == user1.id && tabuleiro[i][j+2] == user1.id && tabuleiro[i][j+3] == user1.id){
                return user1.id;
            }
            if (tabuleiro[i][j] == user2.id && tabuleiro[i][j+1] == user2.id && tabuleiro[i][j+2] == user2.id && tabuleiro[i][j+3] == user2.id){
                return user2.id;
            }
        }
        
    }

    // verificar verticalmente
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == user1.id && tabuleiro[i+1][j] == user1.id && tabuleiro[i+2][j] == user1.id && tabuleiro[i+3][j] == user1.id){
                return user1.id;
            }
            if (tabuleiro[i][j] == user2.id && tabuleiro[i+1][j] == user2.id && tabuleiro[i+2][j] == user2.id && tabuleiro[i+3][j] == user2.id){

                return user2.id;
            }
        }
    // verificar diagonal da direita

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == user1.id && tabuleiro[i+1][j+1] == user1.id && tabuleiro[i+2][j+2] == user1.id && tabuleiro[i+3][j+3] == user1.id){
                return user1.id;
            }
            if (tabuleiro[i][j] == user2.id && tabuleiro[i+1][j+1] == user2.id && tabuleiro[i+2][j+2] == user2.id && tabuleiro[i+3][j+3] == user2.id){
                return user2.id;
            }
        }
    }
}
    // verificar diagonal da esquerda
    for (int i = 6; i >= 3; i--){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == user1.id && tabuleiro[i-1][j+1] == user1.id && tabuleiro[i-2][j+2] == user1.id && tabuleiro[i-3][j+3] == user1.id){
                return user1.id;
            }
            if (tabuleiro[i][j] == user2.id && tabuleiro[i-1][j+1] == user2.id && tabuleiro[i-2][j+2] == user2.id && tabuleiro[i-3][j+3] == user2.id){
                return user2.id;
            }
        }
    }

}




int main() {
   int tabuleiro[6][7] = {0};
   int tema;

   srand(time(NULL));
   printf("Bem vindo ao Liga4!\n");
   puts("O jogo consiste em alinhar 4 peças na horizontal, vertical ou diagonal para vencer.");

   while(1){
   printf("Escolha o tema do jogo:\n1 - Individual(Player contra o computador)\n2 - Dois players\n3 - Simulado(computador contra computador)\n4 - Sair\n");
   scanf("%d", &tema);

    Ficha jogador1, jogador2;
    jogador1.id = 1;
    jogador2.id = 2;
    jogador1.id = 1;
    jogador2.id = 2;
    if (tema == 1){
        printf("Tema Individual selecionado.\n");
        // Lógica para o tema individual
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        jogador1.id = 1;
        jogador2.user[0] = "Kamputer";
        jogador2.id = 2;



    } else if (tema == 2){
        printf("Tema Dois players selecionado.\n");
        // Lógica para o tema dois players
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