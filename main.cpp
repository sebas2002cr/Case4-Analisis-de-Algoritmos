#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void crearImagen(int, int);

int main(int argc, char** argv) {
	
	int alto, ancho;
	
	cout << "Digite el alto: "; cin >> alto;
	cout << endl;
	cout << "Digite el ancho: "; cin >> ancho;
	cout << endl;
	
	crearImagen(alto, ancho);
	return 0;
}

void crearImagen(int pAlto, int pAncho)
{
	int randX, randY, cantidadPuntos;
	int random;
	string color = "";
	cantidadPuntos = (pAlto*pAncho) * 0.2;
	
	
	int last_black[2];
	last_black[0] = 2 * (pAncho/3);
	last_black[1] = 2 * (pAlto/3);
	ostringstream cadena;
	cadena << "[\n";
	//Creación de puntos======================================================================================
	while (cantidadPuntos > 0)
	{
		randX = rand()%pAncho;
		randY = rand()%pAlto;
		random = rand()%100;
		
		if (random<40)
		{
			color = "gray";
		}
		else
		{
			do{
				randX =  last_black[0] + (-10 + rand()%20);
				randY =  last_black[1] + (-10 + rand()%20);
			}while (randX < 0 or randX > pAncho or randY < 0 or randY > pAlto);
			
			
			color = "black";
			
			last_black[0] = randX;
			last_black[1] = randY;
		}
		cadena << "\t\t[" << "\"" << color << "\"," << randX << "," << randY << "]";
		cantidadPuntos--;
		cadena << (cantidadPuntos<=0 ? "":",") << endl;
	}
	
	cadena << "\t]" << endl;
	
	//======================================================================================
	//Generar JSON
	ofstream file;
  	file.open("resultado.json");
  	file << "{\n";
  	file << "\t\"alto\":" << pAlto << ",\n";
  	file << "\t\"ancho\":" << pAncho << ",\n";
  	file << "\t\"puntos\":" << cadena.str();
  	
  	file << "}";
  	file.close();
  	
  	cout << "Archivo JSON listo." << endl;
}


