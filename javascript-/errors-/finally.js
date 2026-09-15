import PromptSync from "prompt-sync";
const prompt = PromptSync();

try {
    let n = Number(prompt("Digite um número: "));
    if (isNaN(n)) {
        throw new Error("Valor inválido!");
    }
    console.log("Número válido: " + n);
} catch (error) {
    console.log("Erro: " + error.message);
}