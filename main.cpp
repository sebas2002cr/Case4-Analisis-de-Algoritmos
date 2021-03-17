#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define ALTO 100
#define ANCHO 100

void crearImagen(int, int);
void guardarMatriz();

int main(int argc, char** argv) {
	
	crearImagen(ALTO, ANCHO);
	
	cout << "Programa finalizado" << endl;
	return 0;
}

void crearImagen(int pAlto, int pAncho)
{
	int matriz[pAlto][pAncho];
	int randX, randY, cantidadPuntos;
	cantidadPuntos = (pAlto*pAncho) * 0.2;
	
	//cout << "Cantidad de puntos: " << cantidadPuntos << endl; 
	
	
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
	
	//guardarMatriz(matriz, "matriz.txt");
	string cadena = "";
	for (int i=0; i<pAlto; i++)
	{
		cadena += "[";
		for (int j=0; j<pAncho; j++)
		{
			cadena += (matriz[i][j]==1 ? "1":"0");
			cadena += (j==pAncho-1 ? "":",");
		}
		
		cadena += "]\n";
	}
	//cout << cadena << endl;
	ofstream file;
  	file.open("matriz.json");
  	file << "{" + cadena + "}";
  	file.close();
}


