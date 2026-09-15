const prompt = require('prompt-sync')();
let gb = prompt('Digite quantos GB estão sendo utilizados: ');

console.log('A quantidade de GB restante é: ', 100 - gb);
