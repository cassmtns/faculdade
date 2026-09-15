const prompt = require('prompt-sync')();
let age, total = 0, cont = 0;

do {
    age = Number(prompt('Digite a idade do indivíduo: '));

    while (age < 0 || age > 120) {
        age = Number(prompt('Idade inválida. Digite a idade do indivíduo novamente: '));
    }

    total += age
    cont++;
}

while (age > 0);

cont--;

console.log('A idade média do grupo de indivíduos é: ', total / cont);