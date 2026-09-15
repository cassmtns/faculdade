const prompt = require('prompt-sync')();
let tab, inicio, fim;

tab = Number(prompt('Tabuada desejada: '));
while (tab < 0) {
    tab = Number(prompt('Tabuada inválida, digite novamente: '));
}

inicio = Number(prompt('Digite o início da tabuada: '));
fim = Number(prompt('Digite o fim da tabuada: '));
while (fim < inicio) {
    fim = Number(prompt('O valor final não pode ser menor que o valor inicial. Digite novamente: '));
}

for (let i = inicio; i <= fim; i++) {
    console.log(tab, 'x', i, '=', tab * i);
}