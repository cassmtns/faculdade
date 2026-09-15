#include <stdio.h>

float elevado(int x, int n) {
    if (n == 1) {
        return x;
    }

    else {
        return x * elevado(x, n -1);
    }
}

int main() {
    int x, n;
    printf("Digite o primeiro número: ");
    scanf("%d", &x);

    printf("Digite o segundo número: ");
    scanf("%d", &n);

    float resultado = elevado(x, n);
    printf("Resultado = %.2f\n", resultado);

    return 0;
}






/* exemplo utilizado a função pow()
double elevado(int x, int n) {
    return pow(x, n);
}

int main() {
    int x, n;
    printf("Digite o primeiro número: ");
    scanf("%d", &x);

    printf("Digite o segundo número: ");
    scanf("%d", &n);

    double resultado = elevado(x, n);
    printf("Resultado = %.2f\n", resultado);

    return 0;
}

*/