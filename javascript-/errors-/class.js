import PromptSync from "prompt-sync";
const prompt = PromptSync();

class ErroDeValidação extends Error {
    constructor(mensagem) {
        super(mensagem);
        this.name = "ErroDeValidação";
    }
}

function calcularAreaTriangulo(base, altura) {
    if (isNaN(base) || isNaN(altura)) {
        throw new Error ("Um número não foi informado");
    }
    if (base <= 0 || altura <= 0) {
        throw new ErroDeValidação("Base e altura devem ser positivas!");
    }
    return (base * altura) / 2;
}

try {
    let x = Number(prompt("Digite a base: "));
    let y = Number(prompt("Digite a altura: "));
    let area = calcularAreaTriangulo(x, y);
    console.log("Área = ", area);
} catch (error) {
    if (error instanceof ErroDeValidação) {
        console.log("Entrada inválida: " + error.message);
    } else {
        console.log("Erro inesperado: " + error.message);
    }
}