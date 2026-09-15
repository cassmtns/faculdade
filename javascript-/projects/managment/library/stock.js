function buscarProdutos (vetor, nome) {

let posicao=0, ind=0;

    for (let posi=0; posi <= vetor.length; posi++) {

        if (vetor[posi] == nome) { posicao = posi; ind = 1; }

        if (ind != 1) { posicao = -1; }
    }

return posicao+1;
}

function menorQuantidade (vetor1, vetor2) {

let menor = 10000000, i, nome;

    for ( i = 0; i < vetor2.length; i++)

        if (vetor2[i] < menor) { 

            nome = vetor1[i];
            menor = vetor2[i];
        }

return nome;
}

function consultarQuantidade (produtos, quantidades, nome) {
    for (let i = 0; i < produtos.length; i++) {
        if (produtos[i] == nome) {

            return quantidades[i];
        }
    }
}

function calcularTotal (quantidades) {
    
let total = 0;

    for( let i=0; i < quantidades.length; i++) {
        total += quantidades[i];
    }

return total;
}

export {

calcularTotal,
menorQuantidade,
consultarQuantidade,
buscarProdutos
};