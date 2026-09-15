/*
try {
    var resultado = numero + 10;
} catch (error) {
    console.log(error.name);
    console.log(error.message);
}
*/

try {
    let lista = []
    lista.push(1); // TypeError: a lista é null
    console.log(lista);
} catch (error) {
    console.log(error.name); // TypeError
    console.log(error.message);
}