#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Inicialização do sistema
int main(int argc, char* argv[]){

    // Verificação dos argumentos inseridos na compilação do sistema
    if (argc != 2) {
        printf("ERRO - Argumentos errados, informe apenas o arquivo de entrada");
        return 1;
    }
    
    // Inicialização das listas
    listaU *u = nova_lista_vazia_usuario();
    listaE *e = nova_lista_vazia_email();
    assert(u != NULL && u->tamanho == 0);
    assert(e != NULL && e->tamanho == 0);

    // Iniciação das variáveis e do arquivo txt
    FILE *arq;
    char *linha = NULL, *funcao = NULL, *msg = NULL;
    int id, idEmail = 0, prioridade, MAX = 1024;
    msg = (char*) malloc(sizeof(char)*MAX);
    linha = (char*) malloc(sizeof(char)*MAX);
    funcao = (char*) malloc(sizeof(char)*MAX);
    
    // Abertura do arquivo txt
    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        printf("\n-> Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("\n-> Iniciando...\n");
    }

    // Verificação de leitura do arquivo txt e dos menus de opções do sistema
    while ((fgets(linha, MAX, arq)) != NULL) {
        // Leitura da opção + o ID de do usuário
        strcpy(funcao,strtok(linha," "));
        id = atoi(strtok(NULL," "));

        // Leitura das opções selecionadas para apoiar no entendimento da execução
        printf("\n-> Opção selecionada: %s e ID: %d", funcao, id);

        // Escolha CADASTRA e suas execuções
        if(strcmp(funcao, "CADASTRA") == 0){
            // Criação da struct usuario com seus dados
            usuario user = caixa_nova_usuario(id);
            
            // Puxando a execução da função insere_no_fim_usuario, para adicionar um usuário na listaU
            insere_no_fim_usuario(u, user);

        // Escolha REMOVE e suas execuções
        }else if(strcmp(funcao, "REMOVE") == 0){
            // Puxando a execução da função retira_usuario, para remoção do usuário da listaU
            retira_usuario(u, e, id);

        // Escolha ENTREGA e suas execuções
        }else if(strcmp(funcao, "ENTREGA") == 0){
            // Leitura da prioridade e da msg para a entrega do email do usuário id
            prioridade = atoi(strtok(NULL," ")); 
            strcpy(msg,strtok(NULL,""));
            int tamanho = strlen(msg);

            // Função de finalização da msg para o usuário
            if (tamanho >= 5) {
                msg[tamanho - 2] = 'F';
                msg[tamanho - 3] = 'I';
                msg[tamanho - 4] = 'M';
                msg[tamanho - 5] = '\0';
            }

            // Puxando a execução da função caixa_nova_email, para criação da struct email com seus dados
            email email = caixa_nova_email(idEmail, id, prioridade, msg);
            idEmail++;

            // Puxando a execução da função insere_no_fim_email, para adicionar o email na listaE
            insere_no_fim_email(u, e, email);

        // Escolha CONSULTA e suas execuções
        }else if(strcmp(funcao, "CONSULTA") == 0){
            email emailC;
            // Puxando a execução da função consulta_email, para leitura do email do usuário id, na listaE
            consultar_email(e, id);
        }
    }
    // Fechamento do arquivo txt
    fclose(arq);

    // Imprimindo os dados das listas para confirmação da execução do sistema
    imprime_usuario(u);
    imprime_email(e);
    printf("\n-> Obrigado por usar nossos serviços\n\n");

    // Desalocação dos dados, para limpeza de memória 
    desaloca_lista_usuario(u);
    desaloca_lista_email(e);
    free(linha);
    free(funcao);
    free(msg);

    //Fim
    return 0;
}