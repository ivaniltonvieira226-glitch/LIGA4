#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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
   printf("Escolha o tema do jogo:\n1 - Individual(Player contra o computador)\n2 - Dois players\n3 - Simulado(computador contra computador)\n 4 - Sair\n");
   scanf("%d", &tema);

    Ficha jogador1, jogador2;
    
    if (tema == 1){
        printf("Tema Individual selecionado.\n");
        // Lógica para o tema individual

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
        printf("Tema inválido. Encerrando o jogo.\n");
        break;
    }

        }
   return 0;
}