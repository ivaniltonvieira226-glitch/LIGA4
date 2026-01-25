#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jogo.h"



int main() {
   int tema, rodadas = 0;

   srand(time(NULL));
   printf("Bem vindo ao Liga4!\n");
   printf("O jogo consiste em alinhar 4 peças na horizontal, vertical ou diagonal para vencer.\n");
   while(1){
   printf("Escolha o tema do jogo:\n1 - Individual(Player contra o computador)\n2 - Dois players\n3 - Simulado(computador contra computador)\n4 - Sair\n");
   scanf("%d", &tema);

   int tabuleiro[6][7] = {0};
   int tabuleiro_explosivo[6][7] = {0};


    Ficha jogador1, jogador2;
    jogador1.id = 1;
    jogador2.id = 2;
    jogador1.fichas_comuns = 21;
    jogador2.fichas_comuns = 21;
    jogador1.fichas_portais = 0;
    jogador2.fichas_portais = 0;
    jogador1.fichas_explosivas = 0;
    jogador2.fichas_explosivas = 0;
    
    // Logica para o tema individual
    if (tema == 1){
        
        printf("Tema Individual selecionado.\n");
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        strcpy(jogador2.user, "Computador");

        while(1){

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
            int coluna, inteiro;
            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);
            
            do{
                inteiro = scanf("%d", &coluna);
                if(Inteiro(inteiro)){
                    printf("Digite um valor inteiro.\n");
                }
                else if(!jogar(tabuleiro, coluna, &jogador1, tabuleiro_explosivo)){
                printf("Coluna inválida ou cheia. Tente novamente.\n");
                }
                else{
                    break;
                }
            } while(1);


            jogador1.fichas_comuns--;

            //Logica para verificar vitória do player 1
            if (verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Parabéns %s! Você venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.fichas_comuns);
                break;
            }
            //Logica para verificar empate
            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            // Logica da jogada do computador
            int colunaComputador;
            do{
            colunaComputador = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, colunaComputador, &jogador2, tabuleiro));

            jogador2.fichas_comuns--;

            if (verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro,jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("O %s venceu! Tente novamente.\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.fichas_comuns);
                break;
            }
            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }
        }
        

    // Lógica para o tema dois players
    } else if (tema == 2){
        printf("Tema Dois players selecionado.\n");

        printf("Iniciando o jogo Player vs Player...\n");
        printf("Digite o nome do jogador 1: ");
        scanf("%s", jogador1.user);
        printf("Digite o nome do jogador 2: ");
        scanf("%s", jogador2.user);

        while(1){

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
            int coluna, inteiro;

            //Logica para usar outras fichas do jogador 1
            
            printf("1.Comum = %d\n2.Portal = %d\n3.Explosiva = %d\n\n", jogador1.fichas_comuns, jogador1.fichas_portais, jogador1.fichas_explosivas);
            printf("Escolha qual ficha vai usar:\n");
           
           do{
            scanf("%d", &jogador1.tipo_de_ficha);
            
            if (jogador1.tipo_de_ficha < 1 || jogador1.tipo_de_ficha > 3){
                printf("Opção inválida. Tente novamente.\n");

            }
            // verifica se o jogador possui fichas portais ou explosivas

            else if (jogador1.tipo_de_ficha == 2 && jogador1.fichas_portais <= 0){
                printf("Você não possui fichas portais. Escolha outra ficha.\n");
            }
            else if (jogador1.tipo_de_ficha == 3 && jogador1.fichas_explosivas <= 0){
                printf("Você não possui fichas explosivas. Escolha outra ficha.\n");
            }

            else{
                break;
            }
           } while(1);

            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);

            do{
            inteiro = scanf("%d", &coluna);
            if(!jogar(tabuleiro, coluna, &jogador1, tabuleiro_explosivo)){
                printf("\nColuna inválida ou cheia. Tente novamente.\n");
            }
        
            else { break;}
            } while(1);

            //logica da explosão
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 7; j++){
                    tentarexplodir(tabuleiro, tabuleiro_explosivo, i, j);
                }
            }

            // for na gravidade para poder aplicar varias vezes
            for (int j = 0; j < 6; j++){
                gravidade(tabuleiro);
            }

            jogador1.fichas_comuns--;

            if (verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("%s, Você venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.fichas_comuns);
                break;
            }

            if(verificarEmpate(tabuleiro) || (jogador1.fichas_comuns <= 0 && jogador2.fichas_comuns <= 0)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);

            //Logica para usar outras fichas do jogador 2
            
            printf("1.Comum = %d\n2.Portal = %d\n3.Explosiva = %d\n", jogador2.fichas_comuns, jogador2.fichas_portais, jogador2.fichas_explosivas);
            printf("Escolha qual ficha vai usar:\n");

            do{
            scanf("%d", &jogador2.tipo_de_ficha);
             if (jogador2.tipo_de_ficha < 1 || jogador2.tipo_de_ficha > 3){
                
                printf("Opção inválida. Tente novamente.\n");
            }
            else if (jogador2.tipo_de_ficha == 2 && jogador2.fichas_portais <= 0){
                printf("Você não possui fichas portais. Escolha outra ficha.\n");
            }
            else if (jogador2.tipo_de_ficha == 3 && jogador2.fichas_explosivas <= 0){
                printf("Você não possui fichas explosivas. Escolha outra ficha.\n");
            }
            else{
                break;
            }
           } while(1);

            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador2.user);

            do{
            inteiro = scanf("%d", &coluna);
                if(!jogar(tabuleiro, coluna, &jogador2, tabuleiro_explosivo)){
                printf("\nColuna inválida ou cheia. Tente novamente.\n");
                }
                else{
                    break;
                }
            } while(1);
            //logica da explosão do jogador 2
            for (int i = 0; i < 6; i++){
                for (int j = 0; j < 7; j++){
                    tentarexplodir(tabuleiro, tabuleiro_explosivo, i, j);
                }
            }
            // for na gravidade para poder aplicar varias vezes
            for (int j = 0; j < 6; j++){
            gravidade(tabuleiro);
            }

            jogador2.fichas_comuns--;

             if (verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("%s, Você venceu!\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.fichas_comuns);
                break;
            }

            if (verificarEmpate(tabuleiro) || (jogador1.fichas_comuns <= 0 && jogador2.fichas_comuns <= 0)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }
            rodadas++;
            if (rodadas % 5 == 0){
                jogador1.fichas_portais++;
                jogador2.fichas_portais++;
                jogador1.fichas_explosivas++;
                jogador2.fichas_explosivas++;
            }
        }   
    }
    else if (tema == 3){
        printf("Tema Simulado selecionado.\n");
        printf("Inciando Computador1 vs Computador2...\n");
        strcpy(jogador1.user, "Computador");
        strcpy(jogador2.user, "Komputer");

        while(1){
            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
            int coluna_Computador, coluna;

            do{
            coluna_Computador = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna_Computador, &jogador1, tabuleiro_explosivo));

            jogador1.fichas_comuns--;

            if(verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("%s, Você Venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.fichas_comuns);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate!. O tabuleiro está cheio.\n");
                break;
            }

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
            do{
            coluna = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna, &jogador2, tabuleiro_explosivo));
            

            jogador2.fichas_comuns--;

            if(verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("%s, Você Venceu!\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.fichas_comuns);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id, tabuleiro_explosivo);
                printf("Empate!. O tabuleiro está cheio.\n");
                break;
            }

        }
    }  
    else if (tema == 4){
        printf("Encerrando o jogo.\n");
        break;
    }

        }
   return 0;
}