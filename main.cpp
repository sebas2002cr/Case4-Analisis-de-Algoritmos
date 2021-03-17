#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void crearImagen(int, int);

int main(int argc, char** argv) {
	
	int alto, ancho;
	
	cout << "Digite el alto: "; cin >> alto;
	cout << endl;
	cout << "Digite el ancho: "; cin >> ancho;
	cout << endl;
	
	crearImagen(alto, ancho);
	
	cout << "Archivo JSON listo." << endl;
	return 0;
}

void crearImagen(int pAlto, int pAncho)
{
	int matriz[pAlto][pAncho];
	int randX, randY, cantidadPuntos;
	cantidadPuntos = (pAlto*pAncho) * 0.1;
	//======================================================================================
	while (cantidadPuntos > 0)
	{
		randX = rand()%pAncho;
		randY = rand()%pAlto;
		
		if (matriz[randY][randX] != 1)
		{
			matriz[randY][randX] = 1;
			cantidadPuntos--;
		}
		else
		{
			continue;
		}
	}
	
	//======================================================================================
	//Generar JSON
	string cadena = "[\n";
	for (int i=0; i<pAlto; i++)
	{
		cadena += "\t\t\t[";
		for (int j=0; j<pAncho; j++)
		{
			cadena += (matriz[i][j]==1 ? "1":"0");
			cadena += (j==pAncho-1 ? "":",");
		}
		
		cadena += (i==pAlto-1 ? "]\n":"],\n");
	}
	cadena += "\t]\n";
	//cout << cadena << endl;
	ofstream file;
  	file.open("matriz.json");
  	file << "{\n";
  	file << "\t\"alto\":" << pAlto << ",\n";
  	file << "\t\"ancho\":" << pAncho << ",\n";
  	file << "\t\"matriz\":" << cadena;
  	
  	file << "}";
  	file.close();
}


