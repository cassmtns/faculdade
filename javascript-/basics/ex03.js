const prompt = require('prompt-sync')();
let use1, use2, use3, media;

use1 = Number(prompt('Digite o uso da CPU em porcentagem: '));
use2 = Number(prompt('Digite o uso da CPU em porcentagem: '));
use3 = Number(prompt('Digite o uso da CPU em porcentagem: '));

media = (use1 + use2 + use3) / 3.0;

console.log('A média de uso de CPU é: ', media, '%');

