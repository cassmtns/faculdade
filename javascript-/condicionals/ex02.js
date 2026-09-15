const prompt = require('prompt-sync')();
let option, total = 0;

option = String(prompt('(S, N) Cor metálica R$ 2.200,00 '));

if (option == 'S' || option == 's') {
    total += 2200;
}

else if (option == 'N' || option == 'n') {
    total;
}

else {
    console.log('Opção inválida!');
}


option = String(prompt('(S, N) Carregamento por indução: R$ 890,00 '));

if (option == 'S' || option == 's') {
    total += 890;
}

else if (option == 'N' || option == 'n') {
    total;
}

else {
    console.log('Opção inválida!');
}

option = String(prompt('(S, N) Estribo lateral: R$ 2.516,32 '));

if (option == 'S' || option == 's') {
    total += 2516.32;
}

else if (option == 'N' || option == 'n') {
    total;
}

else {
    console.log('Opção inválida!');
}

option = String(prompt('(S, N) Suporte para bicicleta: R$ 3.159,90 '));

if (option == 'S' || option == 's') {
    total += 3159;
}

else if (option == 'N' || option == 'n') {
    total;
}

else {
    console.log('Opção inválida!');
}

console.log('Valor total =', total);

/*
exemplo com ternário

option = String(prompt('(S, N) Cor metálica R$ 2.200,00'));

option == 'S' ? total += 2200 : console.log('Opção inválida');
option == 'N' ? total : total;

option = String(prompt
option = String(prompt
option = String(prompt
*/