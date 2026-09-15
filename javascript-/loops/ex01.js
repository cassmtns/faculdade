const prompt = require('prompt-sync')();
let cont, contpar = 0, contimp = 0, num;

for (cont = 0; cont < 10; cont++) {
    num = Number(prompt('Digite um código: '))

    while (num <= 0) {
        num = Number(prompt('Código inválido. Digite o código novamente: '))
    }

    if (num % 2 == 0) {
        contpar++;
    }

    else {
        contimp++;
    }
}

console.log('Quantidade de códigos pares: ', contpar);
console.log('Quantidade de códigos ímpares: ', contimp);