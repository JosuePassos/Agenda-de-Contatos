#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    int escolha;
 
    do{
    printf("SEJA BEM-VINDO A LISTA DE CONTATOS\n");
 
    printf("\nO que deseja fazer?\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Consultar contato pelo nome\n");
    printf("4 - Excluir contato\n");
    printf("5 - Sair\n");
    scanf("%i", &escolha);
 
   
        switch(escolha){
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
        printf("morra");
        break;
    default:
        printf("Valor inválido");
   
         
    }
    } while (escolha < 1 || escolha > 5 );
    return 0;
}
 