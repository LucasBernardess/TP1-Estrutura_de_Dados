#include <stdbool.h>

// Iniciação das variáveis da struct usuario
typedef int idUsuario;

// Iniciação das variáveis da struct email
typedef int idEmail;
typedef int idDestinatario;
typedef int prioridade;
typedef char conteudo;

// Inicialização da struct usuario
typedef struct {
    idUsuario idUsuario;
} usuario;

// Inicialização da struct listaU
typedef struct {
    usuario *usuarios;
    int tamanho, capacidade;
} listaU;

// Inicialização da struct email
typedef struct {
    idEmail idEmail;
    idDestinatario idDestinatario;
    prioridade prioridade;
    conteudo *conteudo;
} email;

// Inicialização da struct listaE
typedef struct {
    email *emails;
    int tamanho, capacidade;
} listaE;

// Funções da Struct ListaU
listaU *nova_lista_vazia_usuario();
usuario caixa_nova_usuario(int idUsuario);
bool vazia_usuario(listaU *u);
void insere_no_fim_usuario(listaU *u, usuario x);
bool retira_usuario(listaU *u, listaE *e, int idIndice);
void imprime_usuario(listaU *u);
void desaloca_lista_usuario(listaU *u);

// Funções da Struct ListaE
listaE *nova_lista_vazia_email();
email caixa_nova_email(int idEmail, int idDestinatario, int prioridade, char* conteudo);
bool vazia_email(listaE *e);
void insere_no_fim_email(listaU *u, listaE *e, email x);
void consultar_email(listaE *e, int idIndice);
bool retira_email(listaE *e, int cont, int idIndice, email *it);
void imprime_email(listaE *e);
void desaloca_lista_email(listaE *e);
