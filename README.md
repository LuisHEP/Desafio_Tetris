🎮 Gerenciador de Fila de Peças (Estilo Tetris)
Este projeto implementa um sistema de fila circular para simular a geração e manipulação de peças, semelhante ao funcionamento de um jogo estilo Tetris.

📌 Funcionalidades
Geração de peças aleatórias (I, O, T, L) com ID sequencial.
Estrutura de dados baseada em fila circular:
Enqueue → Inserir nova peça.
Dequeue → Jogar/remover peça.
Visualização em tempo real da fila de peças.
Menu interativo no terminal para realizar ações.
🛠️ Estruturas principais
Peca
Representa uma peça com:

char nome → Tipo da peça (I, O, T, L).
int id → Identificador único.
FilaPecas
Fila circular com:

Peca pecas[TAMANHO_FILA] → Vetor de peças.
int frente → Índice do início da fila.
int tras → Índice do final da fila.
int tamanho → Número de elementos atuais na fila.
📋 Menu de opções
1 - Jogar peça (dequeue)
2 - Inserir nova peça (enqueue)
0 - Sair
🚀 Como executar
Compile o código:
gcc main.c -o jogo
Execute o programa:
./jogo
🔍 Exemplo de execução
Fila de pecas
[I 0] [L 1] [T 2] [O 3] [I 4] 

Opcoes de acao:
1 - Jogar peca (dequeue)
2 - Inserir nova peca (enqueue)
0 - Sair
Escolha uma opcao: 1

Peca jogada: [I 0]
📚 Conceitos aplicados
Estrutura de dados: Fila Circular.
Uso de struct em C.
Manipulação de vetores e ponteiros.
Geração de números aleatórios com rand().
Interação com usuário via menu no console.
