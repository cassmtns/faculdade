const prompt = require('prompt-sync')();
let digit, c, d, u, inv, sum, result;

digit = Number(prompt('Digite o número da conta corrente: '));

c = Math.trunc(digit/100);
d = Math.trunc(digit%100/10);
u = Math.trunc(digit%10);

// console.log('Digit = ', + digit + '; c  ') ???????????????????? porra é essa
console.log('Digit = ', digit, 'c = ', c, 'd = ', d, 'u = ', u);
console.log(`Digit = ${digit}; c = ${c}; d = ${d}; u = ${u}`);
// console.log(typeof(digit)); ---> exibe o tipo do número

inv = u * 100 + d * 10 + c;
sum = digit + inv;
console.log('Soma = ', sum);

c = Math.trunc(sum/100);
d = Math.trunc(sum%100/10);
u = Math.trunc(sum%10);
sum = c + d * 2 + u * 3;
result = sum % 10;

console.log(digit, '-', result);