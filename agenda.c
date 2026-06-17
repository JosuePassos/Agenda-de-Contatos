#include <stdio.h>
#include <stdlib.h>

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
        printf("Adicionar contatos");
        break;
    case 2:
        printf("Listar contatos");
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
 