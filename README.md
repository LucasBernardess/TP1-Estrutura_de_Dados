# Simulador de Servidor de Emails

Este projeto é uma simulação de um servidor de emails que oferece suporte ao gerenciamento de contas e entrega de emails. Ele foi projetado para verificar o correto funcionamento do servidor em várias situações. O sistema permite aos usuários criar contas, remover contas, entregar emails e consultar emails em suas caixas de entrada.

## Sumário

- [Objetivo](#objetivo)
- [Descrição](#descrição)
- [Começando](#começando)
- [Utilização](#utilização)
- [Estruturas de Dados](#estruturas-de-dados)
- [Contribuições](#contribuições)

## Objetivo

O objetivo deste projeto é implementar um simulador de um servidor de email que possa lidar com o gerenciamento de contas e a entrega de emails. O foco da simulação é garantir que o sistema funcione corretamente ao realizar várias operações no servidor.

## Descrição

Neste servidor de email simulado, as seguintes operações são suportadas:

- **Criar uma Nova Conta de Usuário:** Esta operação cria uma caixa de entrada vazia para um novo usuário. Mensagens enviadas para esse usuário serão armazenadas em sua caixa de entrada. O número de contas de usuário não é fixo, e a memória deve ser alocada e liberada dinamicamente.

- **Remover Conta de Usuário:** Esta operação remove a conta de um usuário e exclui todas as mensagens em sua caixa de entrada.

- **Entregar Email:** Esta operação envia um email para um usuário especificado. O email é armazenado na caixa de entrada do usuário com base na prioridade. Mensagens com prioridade mais alta são armazenadas antes das mensagens com prioridade mais baixa. Se dois emails tiverem a mesma prioridade, o primeiro recebido é armazenado primeiro.

- **Consultar Email:** Esta operação permite a um usuário recuperar a próxima mensagem em sua caixa de entrada de acordo com a prioridade. A mensagem recuperada é removida da caixa de entrada.

## Começando

Para começar com este projeto, você precisará de um compilador C (por exemplo, GCC) para compilar e executar a simulação.

## Utilização

Para executar a simulação, crie um arquivo de texto contendo as operações a serem realizadas (por exemplo, `input.txt`). Cada linha no arquivo deve representar uma operação. As operações suportadas são as seguintes:

- `CADASTRA ID`: Cria uma nova conta de usuário com o ID especificado.
- `REMOVE ID`: Remove uma conta de usuário com o ID especificado.
- `ENTREGA ID PRI MSG FIM`: Entrega um email para o usuário com o ID, prioridade e mensagem especificados.
- `CONSULTA ID`: Consulta o próximo email na caixa de entrada do usuário com o ID especificado.

## Estruturas de Dados

O projeto utiliza Tipos Abstratos de Dados (TADs) para representar mensagens e caixas de entrada. É importante garantir que as mensagens sejam armazenadas de acordo com a prioridade e que as caixas de entrada sejam gerenciadas eficientemente.

## Contribuições

Este projeto é de código aberto e as contribuições são bem-vindas. Se você deseja contribuir, siga as diretrizes de contribuição do projeto e abra uma solicitação de pull.
