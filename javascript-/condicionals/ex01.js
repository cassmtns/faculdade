const prompt = require('prompt-sync')();
let age, name;

name = String(prompt('Digite seu nome: '));
age = Number(prompt('Digite sua idade: '));

age >= 18 ? console.log(name, 'tem', age, 'anos e é maior de idade') : console.log(name, 'tem', age, 'anos e não é maior de idade');
