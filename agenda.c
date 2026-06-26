#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char nome[50];
        char numero[20];
    } contatos;

    contatos agenda[100];
    int totalContatos = 0;
    int lerLinha(FILE *arquivo, char *destino, int tamanho) {
    if (fgets(destino, tamanho, arquivo) == NULL) return 0;
    destino[strcspn(destino, "\n")] = '\0';
    return 1;
}


void salvarArquivo() {
    FILE *arquivo;
    int i;
    arquivo = fopen("agenda.txt", "w");
    if (arquivo == NULL) {
        printf("não foi possivel salvar arquivo.\n");
        return;
    }
    for (i = 0; i < totalContatos; i++) {
        fprintf(arquivo, "%s\n%s\n", agenda[i].nome, agenda[i].numero);
    }
    fclose(arquivo);
}

void adicionarContato(){

if (totalContatos >= 100) {
        printf("Agenda cheia!\n");
        return;
    }
    printf("Digite o nome do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);

    printf("Digite o numero do contato: ");
    scanf(" %[^\n]", agenda[totalContatos].numero);
    int i;
    for (i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[totalContatos].numero, agenda[i].numero) == 0) {
            printf("\nNumero ja cadastrado!\n");
            return;
        }
    }
    printf("\n");
    printf("!Contato adicionado com sucesso!\n");

    totalContatos++;
    salvarArquivo();
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
            salvarArquivo();
            return;
        }
    }
    printf("\n%s Não foi encontrado\n", excluiNome);
}
void carregarArquivo() {
    FILE *arquivo;
    arquivo = fopen("agenda.txt", "r");
    if (arquivo == NULL) return;

    totalContatos = 0;
    while (totalContatos < 100) {
        if (!lerLinha(arquivo, agenda[totalContatos].nome, 50)) break;
        if (!lerLinha(arquivo, agenda[totalContatos].numero, 20)) break;
        totalContatos++;
    }
    fclose(arquivo);
}

int main()
{

    int opcao;

    carregarArquivo();

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
