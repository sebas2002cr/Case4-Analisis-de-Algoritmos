#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void crearImagen(int, int);

int main(int argc, char** argv) {


srand((unsigned int)time(NULL));
    int alto, ancho;

    //cout << "Digite el alto: "; cin >> alto;
    //cout << endl;
    //cout << "Digite el ancho: "; cin >> ancho;
    ancho = 650;
    alto = 700;
    cout << endl;

    crearImagen(alto, ancho);

    return 0;
}

void crearImagen(int pAlto, int pAncho)
{
    int randX, randY, cantidadPuntos;
    int random;
    string color = "";
    cantidadPuntos = (pAlto*pAncho) * 0.1;


    int last_black[2];
    last_black[0] = 2 * (pAncho/3);
    last_black[1] = 2 * (pAlto/3);
    ostringstream cadena;
    cadena << "[\n";
    //Creaci�n de puntos======================================================================================

    //Datos de porciones
    int p50 = cantidadPuntos *0.2;
    int p50x =(pAncho*0.1);


    int p20 = cantidadPuntos*0.2;
    int p20x =(pAlto*0.2);
    int p20y =(pAlto*0.2);
    //cout<< "p50: "<<p50<<endl;
    while (cantidadPuntos > 0)
    {
        randX = rand()%pAncho;
        randY = rand()%pAlto;
        random = rand()%100;

        if (random<89.5)
        {
            int x = rand() % 2;     //-- generate random integer between 0 and 1
            if(x == 0) color = "black";
            else color = "Grey";

        }
        else
                {
                    do{
                       // randX = p50x + rand()% ((pAncho) -p50x);
                       // randY = pAlto/2 + rand()% ((pAlto) - p20y )  ;
                        randX =  rand()% ((pAncho) -1);
                        randY =  rand()% ((pAlto) -1)  ;

                    }while (randX < 0 or randX > pAncho or randY < 0 or randY > pAlto );


                    color = "black";

                    last_black[0] = randX;
                    last_black[1] = randY;


                    do{
                         randX = p50x + rand()% ((pAncho/2) -p50x);
                         randY = pAlto/2 + rand()% ((pAlto) - p20y )  ;
                        //randX =  rand()% ((pAncho) -1);
                        //randY =  rand()% ((pAlto) -1)  ;

                    }while (randX < 0 or randX > pAncho or randY < 0 or randY > pAlto );


                    color = "black";

                    last_black[0] = randX;
                    last_black[1] = randY;


                }





        cadena << "\t\t[" << "\"" << color << "\"," << randX << "," << randY << "]";
        cantidadPuntos--;
        cadena << (cantidadPuntos<=0 ? "":",") << endl;
    }

    cadena << "\t]" << endl;
   /* while (cantidadPuntos > 0)
    {
        randX = p50x + rand()% ((pAncho/2+1) -p50x);
        randY = p20x + rand()% ((pAlto/2+1) - p20x )  ;
        random = rand()%100;

        if (random<70)
        {
            color = "gray";
        }
        else
        {
            do{
                randX =  last_black[0] + (-10 + rand()%20);
                randY =  last_black[1] + (-10 + rand()%20);
            }
            while (randX < 0 or randX > pAncho or randY < 0 or randY > pAlto);


            color = "black";

            last_black[0] = randX;
            last_black[1] = randY;
        }
        cadena << "\t\t[" << "\"" << color << "\"," << randX << "," << randY << "]";
        cantidadPuntos--;
        cadena << (p50<=0 ? "":",") << endl;
    }

    cout<< "cantidadPuntos: "<< cantidadPuntos <<endl;
    cout<< "p60: "<< p50 <<endl;
    cout<< "p20: "<< p20 <<endl;
    cout<< "p50x: "<< p50x <<endl;
    cout<< "p20x: "<< p20x <<endl;
    cout<< "RandomX: "<< randX <<endl;
    cout<< "RandomY: "<< randY <<endl;
    cadena << "\t]" << endl;
*/
    //======================================================================================
    //Generar JSON
    ofstream file;
    //"/Users/sebastianobandopaniagua/Desktop/Analisis de Algoritmos/Caso4/Case4-Analisis-de-Algoritmos/JS/resultado.json"
    file.open("JS/resultado.json");
    file << "{\n";
    file << "\t\"alto\":" << pAlto << ",\n";
    file << "\t\"ancho\":" << pAncho << ",\n";
    file << "\t\"puntos\":" << cadena.str();

    file << "}";
    file.close();

    cout << "Archivo JSON listo." << endl;
}


