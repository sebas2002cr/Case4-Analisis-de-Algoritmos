/*
 * Caso 4 Analisis de algoritmos
 * Estudiantes: 
 *		-Cristhian Esquivel
 *		-Sebastián Obando
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

void crearImagen(int, int);

int main(int argc, char** argv) {


	srand((unsigned int)time(NULL));
    int alto, ancho;
    
    //Creación del patrón en dimensiones de 750x900
    ancho = 900;
    alto = 750;
    cout << endl;

    crearImagen(alto, ancho);
    
    //Creación del patrón en dimensiones de 2000x1200
    ancho = 1200;
    alto = 2000;
    cout << endl;

    crearImagen(alto, ancho);
    
    //Puede descomentar estas lineas si quiere que introducir las dimensiones por medio de la consola
    //cout << "Digite el alto: "; cin >> alto;
    //cout << endl;
    //cout << "Digite el ancho: "; cin >> ancho;
    //crearImagen(alto, ancho);

    return 0;
}


/*
 * Analisis del algoritmo.
 *
 * El algoritmo calcula el 10% de los pixeles a crear y genera puntos de manera "aleatoria" para simular el patrón asignado.
 * El color gris representa un 89% de los pixeles coloreados y representa el fondo de la imagen. Los puntos negros tienen un
 * rango de generación menor y buscan juntarse entre sí para poder mostrar un color negro más intenso.
 *
 * En los comentarios de cada línea se muestran la cantidad de tiempos que requieren
 * F(n) = 48n + 40
 * 
 * n = pAlto * pAncho * 0.1 (o sea, el 10% de la cantidad de píxeles que va a tener el dibujo)
 *
 * O grande = O(n)
 */
void crearImagen(int pAlto, int pAncho)
{
    int randX, randY, cantidadPuntos;
    int random;
    string color = ""; //-->1
    cantidadPuntos = (pAlto*pAncho) * 0.1; //-->3


    int last_black[2];
    last_black[0] = 2 * (pAncho/3); //-->4
    last_black[1] = 2 * (pAlto/3); // --4
    ostringstream cadena;
    cadena << "[\n"; //-->1
    //Creacion de puntos======================================================================================

    //Datos de porciones
    int p50 = cantidadPuntos *0.2; //-->2
    int p50x =(pAncho*0.1); //-->3


    int p20 = cantidadPuntos*0.2; //-->2
    int p20x =(pAlto*0.2); //-->2
    int p20y = (pAlto*0.2); //-->2
    
    
    while (cantidadPuntos > 0)//-->(1 + 47)(n) + 40 => 48(n) + 40
    {
        randX = rand()%pAncho; //-->3
        randY = rand()%pAlto; //-->3
        random = rand()%100; //-->3

        if (random<89.5) //-->1
        {
            int x = rand() % 2;     //-- generate random integer between 0 and 1
            if(x == 0) color = "black";
            else color = "grey";
        }
        else
        {
            do{
                randX = p50x + rand()% ((pAncho/2) -p50x);//-->6
                randY = pAlto/2 + rand()% ((pAlto) - p20y );//-->5

            }while (randX < 0 or randX > pAncho or randY < 0 or randY > pAlto );//-->7
            
            color = "black"; //->1
            last_black[0] = randX; //-->2
            last_black[1] = randY; //-->2
            }

        cadena << "\t\t[" << "\"" << color << "\"," << randX << "," << randY << "]";//-->8
        cantidadPuntos--;//-->2
        cadena << (cantidadPuntos<=0 ? "":",") << endl;//-->4
    }

    cadena << "\t]" << endl; //-->2
    
    //======================================================================================
    //Generar JSON
    ofstream file;
    file.open("JS/resultado.json");//-->1
    file << "{\n";//-->1
    file << "\t\"alto\":" << pAlto << ",\n";//-->3
    file << "\t\"ancho\":" << pAncho << ",\n";//-->3
    file << "\t\"puntos\":" << cadena.str();//-->3

    file << "}"; //-->1
    file.close();//-->1

    cout << "Archivo JSON listo." << endl;//-->1
}


