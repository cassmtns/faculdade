#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    float saldo;
} conta;

/*
float criar_conta(int numero, float saldo) {
    printf("Digite o número da conta: ");
    scanf("%d", &numero);

    printf("Digite o saldo da conta: ");
    scanf("%f", &saldo);
}
*/

void deposito(conta x, float valor) {
    x.saldo += valor;
}

void saque(conta y, float valor) {
    if (valor <= y.saldo) {
        y.saldo -= valor;
    }
    else {
        printf("Saldo insuficiente!");
    }
}

float tela(conta z) {
    printf("Conta = %d\n Saldo = %.2f", z.numero, z.saldo);
}

void main() {
    conta main;
    int option;
    float valor;


    printf("Digite o número da conta: ");
    scanf("%d", &main.numero);

    printf("Digite o saldo da conta: ");
    scanf("%f", &main.saldo);

    printf("(1) Depósito\n (2) Saque\n (3) Mostrar valor\n (0) Sair\n");
    scanf("%d", &option);

    printf("(1) Depósito\n (2) Saque\n (3) Mostrar valor\n (0) Sair\n");
    scanf("%d", &option);
    
    do {
        
            switch (option) {

                case 1:
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%f", &valor);
                    deposito(main, valor);
                    break;

                case 2:
                    printf("Digite o valor a ser retirado: ");
                    scanf("%f", &valor);
                    deposito(main, valor);
                    break;

                case 3:
                    tela(main);
                    break;
            }
    }
    // while (option != 1 || option != 2 || option != 3 || option != 4);
    while (option != 0);
}


// 4 funcões
// verificação para menu funcionar sempre que sair de uma opção
// verificação caso as opções 2, 3 e 4 forem escolhidas antes da 1
// validação de valores negativos
