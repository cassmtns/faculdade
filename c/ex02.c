#include <stdio.h>

int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } 
  
  else {
    return 0;
  }
}

int main() {

    int n;
    printf("Digite um número n: ");
    scanf("%d", &n);

    int result = sum(n);
    printf("Soma dos n primeiros números inteiros: %d\n", result);

    return 0;
}