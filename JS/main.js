
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
    contexto.fillStyle = "black";

    var matriz = pData["matriz"];

    //var contador = 0;
    for (var y=0; y<ancho; y++)
    {
        for (var x=0; x<alto; x++)
        {
            if (matriz[x][y] == 1)
            {
                //contexto.fillStyle = "black";
                contexto.fillRect(y, x, 1, 1);
                //contador++;
            }
            /*
            else
            {
                contexto.fillStyle = "cyan";
            }*/
            
        }
    }

    //console.log("Contador: ",contador);
}

//usage:
readTextFile("matriz.json", function(text){
    var data = JSON.parse(text);
    show(data)
});

