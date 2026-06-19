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
    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);
    
    printf("Digite o numero do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].numero);
    printf("\n");
    printf("!Contato adicionado com sucesso!\n");
    
    totalContatos++;
}
void listarContato(){
    
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
    int i = 0;
    
    if (strcmp(buscaNome, agenda[i].nome)== 0){
        printf("\nNome: %s / Numero: %s\n", agenda[i].nome, agenda[i].numero);
    } else {
        printf("\n%s Não foi encontrado\n", buscaNome);
    }
}
void excluirContato();

int main()
{
 
    int opcao, i;


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
        printf("Consultar contato pelo nome");
        break;
    case 4:
        printf("Excluir contato");
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
    