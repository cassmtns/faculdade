#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    float saldo;
} conta;

conta depositar(conta x, float deposito) {
    x.saldo += deposito;
    return x;
}

conta sacar(conta y, float saque) {
    if (saque <= y.saldo) {
        y.saldo -= saque;
    }
    else {
        printf("Saldo insuficiente!\n");
    }
    return y;
}

void imprimir(conta z) {
    printf("Conta = %d\nSaldo = %.2f\n", z.numero, z.saldo);
}

void main() {
    conta main;
    int option;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &main.numero);

    printf("Digite o saldo da conta: ");
    scanf("%f", &main.saldo);
    
    do {
        printf("(1) Depósito (2) Saque (3) Mostrar valor (0) Sair\n");
        scanf("%d", &option);
        
            switch (option) {

                case 1:
                    printf("Digite o valor a ser adicionado: ");
                    scanf("%f", &valor);
                    main = depositar(main, valor);
                    break;

                case 2:
                    printf("Digite o valor a ser retirado: ");
                    scanf("%f", &valor);
                    main = sacar(main, valor);
                    break;

                case 3:
                    imprimir(main);
                    break;

                case 0:
                    printf("Saindo...\n");
                    break;

                default:
                    printf("Opção inválida, digite novamente!");
                    break;
            }
    }
    while (option != 0);
}
