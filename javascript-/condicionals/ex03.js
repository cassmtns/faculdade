const prompt = require('prompt-sync')();
let code, qtd, total;

code = Number(prompt('Digite o código do produto: (1001) (1324) (987) (6548) '));
qtd = Number(prompt('Digite a quantidade desejada: '));

switch (code) {
    case 1001:
        total = 5.32 * qtd;
        break;

    case 1324:
        total = 6.45 * qtd;
        break;

    case 987:
        total = 3.42 * qtd;
        break;

    case 6548:
        total = 2.37 * qtd;
        break;

    default:
        console.log('Código inválido!');
}

console.log('Total a ser pago = R$ ', total);