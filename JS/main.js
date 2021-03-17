
function readTextFile(file, callback) {
    var rawFile = new XMLHttpRequest();
    rawFile.overrideMimeType("application/json");
    rawFile.open("GET", file, true);
    rawFile.onreadystatechange = function() {
        if (rawFile.readyState === 4 && rawFile.status == "200") {
            callback(rawFile.responseText);
        }
    }
    rawFile.send(null);
}

function show(pData)
{
    var lienzo = document.querySelector("canvas");

    var ancho = pData["ancho"];
    var alto = pData["alto"];
    lienzo.setAttribute("width", ancho);
    lienzo.setAttribute("height", alto);

    console.log("Ancho: ", ancho);
    console.log("Alto: ", alto);

    var contexto = lienzo.getContext("2d");

    var puntos = pData["puntos"];
    var contador = 0;
    for (var i = 0;  i<puntos.length; i++)
    {
        contexto.fillStyle = puntos[i][0];
        contexto.fillRect(puntos[i][1], puntos[i][2], 1, 1);
    }

}

//usage:
readTextFile("resultado.json", function(text){
    var data = JSON.parse(text);
    show(data)
});

