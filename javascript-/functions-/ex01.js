const prompt = require('prompt-sync')();

function calcularPrecoComDesconto (preco, percentual) {
    return preco - (preco * percentual / 100);
}

let preco = Number(prompt('Digite o preço do produto: '));
let percentual = Number(prompt('Digite o percentual de desconto: '));

let result = calcularPrecoComDesconto(preco, percentual);
console.log('Preço com desconto:', result);
 