#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define nao_implementada() \
printf("\n-> Linha %d, %s nao implementada ainda!!\n", __LINE__, __FUNCTION__), exit(0)

#define INICIAL 2

// Inicialização da listaU
listaU *nova_lista_vazia_usuario() {
    listaU *u = (listaU*) malloc(sizeof(listaU));
    u->usuarios = NULL;
    u->tamanho = 0;
    u->capacidade = 0;
    return u;
}

// Inicialização da listaE
listaE *nova_lista_vazia_email() {
    listaE *e = (listaE*) malloc(sizeof(listaE));
    e->emails = NULL;
    e->tamanho = 0;
    e->capacidade = 0;
    return e;
}

// Criação de uma nova struct usuario com seus dados
usuario caixa_nova_usuario(int idUsuario){
	usuario usuarioN;
	usuarioN.idUsuario = idUsuario;
	return usuarioN;
}

// Criação de uma nova struct email com seus dados
email caixa_nova_email(int idEmail, int idDestinatario, int prioridade, char* msg){
	email emailN;
	emailN.idEmail = idEmail;
	emailN.idDestinatario = idDestinatario;
	emailN.prioridade = prioridade;
	emailN.conteudo = (char*)malloc(sizeof(char)*1024);
	strcpy(emailN.conteudo, msg);
	return emailN;
}

// Verificação da listaU, se é vazia
bool vazia_usuario(listaU *u) {
    if(u == NULL)
        return true;
    else
        return u->tamanho <= 0;
}

// Verificação da listaE, se é vazia
bool vazia_email(listaE *e) {
    if(e == NULL)
        return true;
    else
        return e->tamanho <= 0;
}

// Inserindo dados ao final da listaU
void insere_no_fim_usuario(listaU *u, usuario x) {
	int cont = 0;
	// Verificação se já existe um ID que deseja ser inserido na listaU
	for(int i = 0; i < u->tamanho; i++) {
		if(u->usuarios[i].idUsuario == x.idUsuario) {
			printf("\n-> Id já existe!\n");
			cont = 1;
		}
	}	
	// Caso já exista um usuário, ele irá pular essa condição, caso contrário, ele irá criar o usuário
	if(cont != 1){
		// Caso não exista nenhum usuário cadastrado, o sistema irá alocar espaço para a struct
		if(u->usuarios == NULL) {
			u->usuarios = (usuario*)malloc(sizeof(usuario)*INICIAL);
			u->capacidade = INICIAL;
		} else {
			// Caso já exista usuários cadastrados na struct, o sistema irá adicionar mais espaço para um novo usuário
			if(u->tamanho + 1 > u->capacidade) {
				int nt = (u->capacidade*2) * sizeof(usuario);
				u->usuarios = realloc(u->usuarios, nt);
				u->capacidade = u->capacidade * 2;
			}
		}
		// Adicionando um novo usuário
		u->tamanho += 1;
		u->usuarios[u->tamanho - 1] = x;
		printf("\n-> Id cadastrado com sucesso!\n");
	}
}

// Inserindo dados ao final da listaE
void insere_no_fim_email(listaU *u, listaE *e, email x) {
	int cont = 0;
	// Verificação se existe um ID para ser entregue um email ao ID destinatário
	for(int i = 0; i < u->tamanho; i++) {
		if(u->usuarios[i].idUsuario == x.idDestinatario) {
			cont = 1;
		}
	}	
	// Caso exista um ID destinatário, o sistema irá executar a condição para envio do email, caso contrário, ele irá pular essa condição
	if(cont == 1){
		// Caso não exista nenhum email cadastrado, o sistema irá alocar espaço para a struct
		if(e->emails == NULL) {
			e->emails = (email*)malloc(sizeof(email)*INICIAL);
			e->capacidade = INICIAL;
		} else {
			// Caso já exista emails cadastrados na struct, o sistema irá adicionar mais espaço para um novo usuário
			if(e->tamanho + 1 > e->capacidade) {
				int nt = (e->capacidade*2) * sizeof(email);
				e->emails = realloc(e->emails, nt);
				e->capacidade = e->capacidade * 2;
			}
		}
		// Adicionando um novo email
		e->tamanho += 1;
		e->emails[e->tamanho - 1] = x;
		printf("\n-> Email enviado com sucesso!\n");
	}else{
		printf("\n-> Id destinatário não existe!\n");
	}
}

// Consultando dados da listaE
void consultar_email(listaE *e, int idIndice){
	int cont = 0;
	// Contador para verificar se existe email(s) para o ID destinatário
	for(int i = 0; i < e->tamanho; i++) {
		if(e->emails[i].idDestinatario != idIndice) {
			cont++;
		}
	}
	// Caso não exista email(s), irá exibir uma mensagem de erro, caso contrário, irá ler e apagar o email lido
	if(cont == e->tamanho){ 
		printf("\n-> Não existe email para esse usuário!\n");
	}else {
		int prioridade = -1, posicao = 0;
		// Verifica o email de maior prioridade e antigo do usuário ID
		for(int i = 0; i < e->tamanho; i++) {
			if(e->emails[i].idDestinatario == idIndice && e->emails[i].prioridade > prioridade ){
				prioridade = e->emails[i].prioridade;
				posicao = i;
			}
		}
		// Adiciona o email selecionado na struct emailR
		email emailR = e->emails[posicao];
		// Exibi o email recebido
		printf("\n-> Email recebido : %s", emailR.conteudo);
		// Remove o email lido do usuário ID
		retira_email(e, 0, posicao, &emailR);
	}
}

// Retirando dados da listaU
bool retira_usuario(listaU *u, listaE *e, int idIndice) {
	int posicao, cont = 0;
	// Verificando se o usuário existe, caso exista, salva sua posição
	for(int i = 0; i < u->tamanho; i++) {
		if(idIndice == u->usuarios[i].idUsuario) { 
			posicao = i; 
		}else { cont++; }
	}
	// Caso o usuário não exista, exibira erro, caso contrário, irá remover o usuário
	if(cont == u->tamanho || vazia_usuario(u)) {
		printf("\n-> Id não existe!\n");
		return false;
	}else{
		int cont = 1;
		// Verificação se existe email(s) para o usuário que será removido, caso tenha, irão ser apagados
		for(int j = 0; j < cont; j++){
            for(int i = 0; i < e->tamanho; i++) {
                if(e->emails[i].idDestinatario == u->usuarios[posicao].idUsuario){
                    email emailR = e->emails[i];
					// Removendo email do usuário
                    retira_email(e, 1, i, &emailR);
					// Contagem de email(s) removidos
					cont++;
                }
            }
        }
		// Exibindo o total de email(s) removidos do usuário
		printf("\n-> %d Email(s) removido(s) com sucesso!", cont-1);
		// Removendo o usuário solicitado da listaU
		for (int i = posicao; i < u->tamanho - 1; i++){
			u->usuarios[i] = u->usuarios[i+1];
		}
		u->tamanho--;
		printf("\n-> Id removido com sucesso!\n");

		return true;
	}
}

// Retirando dados da listaE
bool retira_email(listaE *e, int cont, int idIndice, email *it) {
	// Verificando se existe o email solicitado 
	if(e->emails[idIndice].idEmail != it->idEmail || vazia_email(e)) {
		printf("\n-> Email não existe!\n");
		return false;
	}else{
		// Removendo o email solicitado da listaE
		for (int i = idIndice; i < e->tamanho - 1; i++){
			e->emails[i] = e->emails[i+1];
		}
		e->tamanho--;
		if(cont == 0){
			printf("\n-> Email removido com sucesso!\n");
		}
		return true;
	}
}

// Imprimindo dados da listaU
void imprime_usuario(listaU *u) {
	//Verifica se possui dados para serem exibidos
    if(vazia_usuario(u)) { return; }
	//Exibindo usuários cadastrados no final da execução
	printf("\n-> Usuários cadastrados : ");
    printf("%d", u->usuarios[0].idUsuario);
    for(int i = 1; i < u->tamanho; i++) {
        printf(", %d", u->usuarios[i].idUsuario);
    }
}

// Imprimindo dados da listaE
void imprime_email(listaE *e) {
	//Verifica se possui dados para serem exibidos
    if(vazia_email(e)) { return; }
	//Exibindo email(s) cadastrados no final da execução
	printf("\n-> Email(s) cadastrados");
    printf("\n-> Email : %d - Destinatário : %d - Prioridade : %d - Assunto : %s\n", e->emails[0].idEmail, e->emails[0].idDestinatario, e->emails[0].prioridade, e->emails[0].conteudo);
    
	for(int i = 1; i < e->tamanho; i++) {
        printf("-> Email : %d - Destinatário : %d - Prioridade : %d - Assunto : %s\n", e->emails[i].idEmail, e->emails[i].idDestinatario, e->emails[i].prioridade, e->emails[i].conteudo);
    }
}

// Desalocando dados da listaU
void desaloca_lista_usuario(listaU *u) {
    if(u == NULL) { return; }
	free(u->usuarios);
    free(u);
}

// Desalocando dados da listaE
void desaloca_lista_email(listaE *e) {
    if(e == NULL) { return;}
	free(e->emails);
	free(e);
}
