import promptSync from 'prompt-sync';
const prompt = promptSync();

import * as estoque from "./biblioteca/estoque.js"
let i = 0, produto = [], quantidade = [], confirm, opc, nome, resultado;

do {
    produto[i] = String(prompt("Digite o nome do produto: ")).toUpperCase()

    quantidade[i] = Number(prompt("Digite a quantidade do produto: "))
        while ( quantidade[i] < 0 ) {

           quantidade[i] = Number(prompt("Digite a quantidade do produto novamente: ")) 
        }

    confirm = Number(prompt("Deseja adicionar algo mais? (1) SIM (0) NÃO: "))
        while (confirm != 0 && confirm != 1) {

            confirm = Number(prompt("Digite uma opção válida! (1) SIM (0) NÃO: "))
        }
    
    if (confirm == 1) {
        i++;
    }
} while (confirm == 1);

do {
console.log('\n===MENU===\n[1] Buscar produtos\n[2] Consultar quantidade\n[3] Consultar menor quantidade em estoque\n[4] Consultar total de itens\n[0] Sair\n==========')
opc = Number(prompt('digite a opção que deseja: '))
    while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 0) {

        console.log('\n===MENU===\n[1] Buscar produtos\n[2] Consultar quantidade\n[3] Consultar menor quantidade em estoque\n[4] Consultar total de itens\n[0] Sair\n==========')
        opc = Number(prompt('digite uma opção válida! : '))
    }

switch (opc) {

    case 1: 
        nome = String(prompt('digite o nome do produto: ')).toUpperCase()
        resultado = estoque.buscarProdutos(produto, nome);
        console.log('Posição do produto:', resultado);
    break;
    
    case 2: 
        nome = String(prompt('digite o nome do produto: ')).toUpperCase()
        resultado = estoque.consultarQuantidade(produto, quantidade, nome);
        console.log('Quantidade do produto:', resultado);
    break;
    
    case 3: 
        resultado = estoque.menorQuantidade(produto, quantidade);
        console.log('Menor estoque do produto:', resultado);
    break;

    case 4: 
        resultado = estoque.calcularTotal(quantidade);
        console.log('Total de estoque:', resultado);
    break;

}

} while (opc != 0)

console.log('saindo...')