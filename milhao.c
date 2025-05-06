#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ERROS 3            // NÃºmero mÃ¡ximo de erros que o jogador pode cometer
#define MAX_NIVEIS 5           // NÃºmero total de nÃ­veis no jogo
#define PERGUNTAS_POR_NIVEL 3  // NÃºmero de perguntas por nÃ­vel

// Matriz de perguntas, onde cada nÃ­vel contÃ©m um conjunto de perguntas
char* perguntas[MAX_NIVEIS][PERGUNTAS_POR_NIVEL] = {
    {
        "Qual e o tamanho de uma variavel do tipo int em C?\nA) 1 byte\nB) 2 bytes\nC) 4 bytes\nD) 8 bytes",
        "O que significa o espaco ocupado por uma variavel na memoria?\nA) Tamanho da variavel\nB) Endereco de memoria\nC) Tipo de dado\nD) Nome da variavel",
        "Quais operadores podem ser usados com uma variavel do tipo float?\nA) +, -, *, /\nB) +, -, /, %\nC) +, *, /\nD) +, -, *, %, &&"
    },
    {
        "Como as operacoes sao executadas em C?\nA) De forma sequencial\nB) De forma condicional\nC) De forma iterativa\nD) De acordo com a prioridade de operadores",
        "Qual representacao binaria do numero 10?\nA) 1001\nB) 1010\nC) 1100\nD) 1111",
        "Como podemos alterar o valor de uma variavel em C?\nA) Usando atribuicao\nB) Usando entrada de dados\nC) Usando o operador '=='\nD) Usando incrementos de loop"
    },
    {
        "Qual operador representa OU logico?\nA) &&\nB) ||\nC) !\nD) &",
        "Como se chama um laco que sempre executa pelo menos uma vez?\nA) for\nB) do-while\nC) while\nD) if",
        "O que e um Enum em C?\nA) Um comando que encerra um programa imediatamente.\nB) Um tipo de laÃ§o de repetiÃ§Ã£o com condiÃ§Ã£o no final.\nC) E um mapeamento de valores interios\nD)  Um operador que compara dois valores diferentes."
    },
    {
        "Qual o significado de Union em C?\nA)Uma funcao que une dois arrays em um so\nB) E um tipo que pode representar dados de tipos diferentes\nC) Uma biblioteca externa para unir variaveis\nD) Um operador logico utilizado para unir condicoes",
        "Qual e o valor padrao de uma variavel nao inicializada?\nA) 0\nB) 1\nC) indefinido\nD) null",
        "Qual comando serve para ler um valor do usuario?\nA) printf\nB) scanf\nC) gets\nD) cin"
    },
    {
        "Qual e o resultado de 10 / 3 em C?\nA) 3.33\nB) 3\nC) 3.0\nD) erro",
        "Qual e a finalidade do operador sizeof?\nA) Comparar\nB) Alocar\nC) Medir tamanho\nD) Somar",
        "Qual o significado de Structs?\nA) Um tipo de dado que permite repetir blocos de cÃ³digo.\nB) Um comando usado para imprimir valores na tela.\nC) Uma estrutura de controle condicional como if ou switch.\nD) Colecao de dado de tipos diferentes"
    }
};

// Matriz de respostas corretas, onde cada nÃ­vel contÃ©m as respostas para as perguntas correspondentes
char respostas[MAX_NIVEIS][PERGUNTAS_POR_NIVEL] = {
    {'C', 'A', 'A'},  
    {'A', 'B', 'A'},  
    {'B', 'B', 'C'},  
    {'B', 'C', 'B'},  
    {'B', 'C', 'D'}   
};



int main() {
    int nivel = 0;      
    int erros = 0;        
    char resposta;        
    int perguntaIndex;    

    srand(time(NULL));   

    printf("\nBem-vindo ao Jogo de Perguntas de Algoritmos!\n");
    printf("Responda corretamente para avancar de nivel. 3 erros e o jogo acaba.\n\n");

    // LaÃ§o que controla o andamento do jogo
    while (nivel < MAX_NIVEIS && erros < MAX_ERROS) {
        perguntaIndex = rand() % PERGUNTAS_POR_NIVEL; 

        printf("Nivel %d:\n", nivel + 1);  
        printf("%s\n", perguntas[nivel][perguntaIndex]);  
        do{
            printf("Sua resposta: ");
            scanf(" %c", &resposta);
            fflush(stdin);
            resposta = toupper(resposta);

            if(resposta != 'A' && resposta != 'B' && resposta != 'C' && resposta != 'D'){
                printf("Resposta invalida! Por favor digite: A, B, C ou D.\n");
            }  
        }while(
            resposta != 'A' && resposta != 'B' && resposta != 'C' && resposta != 'D');        

        // Verifica se a resposta do jogador estÃ¡ correta (considerando maiÃºsculas ou minÃºsculas)
        if (resposta == respostas[nivel][perguntaIndex] || resposta == respostas[nivel][perguntaIndex] + 32) {
            printf("Correto!\n\n");
            nivel++;  
        } else {
            printf("Errado!\n\n");
            erros++;  
        }
    }

    // Verifica se o jogador venceu ou perdeu o jogo
    if (nivel == MAX_NIVEIS) {
        printf("Parabens! Voce venceu o jogo!\n");
    } else {
        printf("Voce perdeu! Numero maximo de erros atingido.\n");
    }

    return 0; 
}
