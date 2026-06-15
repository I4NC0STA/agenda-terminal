#include <stdio.h>
#include <string.h>

#define MAX 50

struct Contato {
    char nome[50];
    char telefone[20];
};

int main() {
    struct Contato agenda[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n+------------------------------------+\n");
        printf("|               AGENDA               |\n");
        printf("+------------------------------------+\n");
        printf("| [1] Inserir Contato                |\n");
        printf("|------------------------------------|\n");
        printf("| [2] Mostrar Contatos               |\n");
        printf("|------------------------------------|\n");
        printf("| [3] Buscar Contato                 |\n");
        printf("|------------------------------------|\n");
        printf("| [4] Buscar Binaria                 |\n");
        printf("|------------------------------------|\n");
        printf("| [5] Apagar por Nome                |\n");
        printf("|------------------------------------|\n");
        printf("| [6] Apagar por Posicao             |\n");
        printf("|------------------------------------|\n");
        printf("| [7] Informacoes                    |\n");
        printf("|------------------------------------|\n");
        printf("| [8] Numero de contatos             |\n");
        printf("|------------------------------------|\n");
        printf("| [9] Espaco disponivel              |\n");
        printf("|------------------------------------|\n");
        printf("| [0] Sair                           |\n");
        printf("+------------------------------------+\n");
        printf("> ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                if (total < MAX) {
                    printf("Nome: ");
                    scanf(" %[^\n]", agenda[total].nome);

                    printf("Telefone: ");
                    scanf(" %[^\n]", agenda[total].telefone);

                    total++;
                    printf("Contato adicionado!\n");
                } else {
                    printf("Agenda lotada\n");
                }
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum Contato\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        printf("\n[%d]\n", i);
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Telefone: %s\n", agenda[i].telefone);
                    }
                }
                break;

            case 3: {
                char busca[50];
                int achou = 0;

                printf("Digite o Nome: ");
                scanf(" %[^\n]", busca);

                for (int i = 0; i < total; i++) {
                    if (strcmp(agenda[i].nome, busca) == 0) {
                        printf("Nome: %s\n", agenda[i].nome);
                        printf("Telefone: %s\n", agenda[i].telefone);
                        achou = 1;
                        break;
                    }
                }

                if (!achou) {
                    printf("Nao encontrado\n");
                }
                break;
            }

            case 4: {

                struct Contato temp;
                for (int i = 0; i < total - 1; i++) {
                    for (int j = i + 1; j < total; j++) {
                        if (strcmp(agenda[i].nome, agenda[j].nome) > 0) {
                            temp = agenda[i];
                            agenda[i] = agenda[j];
                            agenda[j] = temp;
                        }
                    }
                }

                int inicio = 0, fim = total - 1, meio;
                char busca[50];
                int achou = 0;

                printf("Digite o Nome: ");
                scanf(" %[^\n]", busca);

                while (inicio <= fim) {
                    meio = (inicio + fim) / 2;
                    int comp = strcmp(agenda[meio].nome, busca);

                    if (comp == 0) {
                        printf("Nome: %s\n", agenda[meio].nome);
                        printf("Telefone: %s\n", agenda[meio].telefone);
                        achou = 1;
                        break;
                    } else if (comp < 0) {
                        inicio = meio + 1;
                    } else {
                        fim = meio - 1;
                    }
                }

                if (!achou) {
                    printf("Zero Resultados\n");
                }
                break;
            }

            case 5: {
                char nome[50];
                int achou = 0;

                printf("Apagar Contato: ");
                scanf(" %[^\n]", nome);

                for (int i = 0; i < total; i++) {
                    if (strcmp(agenda[i].nome, nome) == 0) {

                        for (int j = i; j < total - 1; j++) {
                            agenda[j] = agenda[j + 1];
                        }

                        total--;
                        printf("Apagado\n");
                        achou = 1;
                        break;
                    }
                }

                if (!achou) {
                    printf("Nao Encontrado\n");
                }
                break;
            }

            case 6: {
                int pos;

                printf("Posicao: ");
                scanf("%d", &pos);

                if (pos >= 0 && pos < total) {
                    for (int i = pos; i < total - 1; i++) {
                        agenda[i] = agenda[i + 1];
                    }
                    total--;
                    printf("Apagado\n");
                } else {
                    printf("Posicao invalida\n");
                }
                break;
            }

            case 7:
                printf("Total de Contatos: %d\n", total);
                printf("Espaco Livre: %d\n", MAX - total);
                break;

            case 8:
                printf("Numero de contatos: %d\n", total);
                break;

            case 9:
                printf("Voce pode adicionar mais %d contatos\n", MAX - total);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
