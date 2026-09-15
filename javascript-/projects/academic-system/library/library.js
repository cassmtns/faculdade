function media (vetor) {

let soma = 0, media = 0;

    for ( let numero of vetor) { soma += numero; }

return media = soma / vetor.length;

}

function maior (vetor) {

let maior = vetor[0];

    for ( let numero of vetor) {

        if (numero > maior) { maior = numero; }

    }

    return maior;

}

function menor (vetor) {

    let menor = vetor[0];

    for ( let numero of vetor) {

        if (numero < menor) { menor = numero; }

    }

    return menor;

}

function amplitude (vetor) {

let maior = vetor[0], menor = vetor[0];

    for ( let numero of vetor) {

        if (numero > maior) { maior = numero; }

    }

     for ( let numero of vetor) {

        if (numero < menor) { menor = numero; }

    }

    return maior - menor;

}

export {

media,
maior,
menor,
amplitude
}