#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct {
    int id;
    char user[100];
} Ficha;


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
    if (tema == 1){
        printf("Tema Individual selecionado.\n");
        // Lógica para o tema individual
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        strcpy(jogador2.user, "Computador");
        

        // exibir tabuleiro
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