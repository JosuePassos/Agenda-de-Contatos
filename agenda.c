#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char nome[50];
        char numero[20];
    } contatos; 
    
    contatos agenda[100];
    int totalContatos = 0;
    
void adicionarContato(){

if (totalContatos >= 100) {
        printf("Agenda cheia!\n");
        return;
    }
    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);
    
    printf("Digite o numero do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].numero);
    printf("\n");
    printf("!Contato adicionado com sucesso!\n");
    
    totalContatos++;
}
void listarContato(){

    int i;
    
    printf("Lista de contatos\n");
    
        if (totalContatos == 0){
            printf("\nsem contatos\n");
        } else{
            for (i = 0;i < totalContatos; i++){
                printf("Nome: %s / Numero: %s\n", agenda[i].nome, agenda[i].numero);
            }
        }
            
}
void consultarContato(){
    
    char buscaNome[50];

    printf("Digite o nome do contato que deseja consultar: ");
    scanf(" %[^\n]", buscaNome);
    int i;
    
    for (i = 0; i < totalContatos; i++) {
        if (strcmp(buscaNome, agenda[i].nome) == 0) {
            printf("\nNome: %s / Numero: %s\n", agenda[i].nome, agenda[i].numero);
            return;
        }
    }
    printf("\n%s Não foi encontrado\n", buscaNome);   
}
void excluirContato(){
    char excluiNome[50];
    int i, j;
    
    printf("Digite o nome do contato que deseja excluir: ");
    scanf(" %[^\n]", excluiNome);
    
    for (i = 0; i < totalContatos; i++) {
        if (strcmp(excluiNome, agenda[i].nome) == 0) {
            for (j = i; j < totalContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            totalContatos--;
            printf("\nContato excluido com sucesso!\n");
            return;
        }
    }
    printf("\n%s Não foi encontrado\n", excluiNome);
}

int main()
{
 
    int opcao;


    printf("SEJA BEM-VINDO A LISTA DE CONTATOS\n");

    do{
 
    printf("\nO que deseja fazer?\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Consultar contato pelo nome\n");
    printf("4 - Excluir contato\n");
    printf("5 - Sair\n");
    scanf("%i", &opcao);
 
   
        switch(opcao){
    case 1:
        adicionarContato();
        break;
    case 2:
        listarContato();
        break;
    case 3:
        consultarContato();
        break;
    case 4:
        excluirContato();
        break;
    case 5:
        printf("Saindo...");
        break;
    default:
        printf("Valor inválido");
   
         
    }
    } while (opcao != 5);
    return 0;
}
    