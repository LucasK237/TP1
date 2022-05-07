/*Implementar en C un programa que permita reconocer y clasificar las distintas de constantes enteras de C
(Decimal, Octal, Hexadecimal).
El mismo deberá leer palabras separadas por “,” (carácter centinela) de un archivo de entrada (entrada.txt)
y generar un archivo de salida (salida.txt)
donde indique qué tipo de constante entera es cada palabra leída o si no fue reconocida.
El programa debe contemplar la implementación de un autómata finito determinístico (AFD) para el reconocimiento
y clasificación de palabras según estado final. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int automata[7][6] = {
    {1, 2, 2, 6, 6, 6},
    {5, 5, 6, 6, 3, 6},
    {2, 2, 2, 6, 6, 6},
    {4, 4, 4, 4, 6, 6},
    {4, 4, 4, 4, 6, 6},
    {5, 5, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6}
};
/*int siguienteEstado(int estado, int columna);
int evaluarCaracter(FILE *entrada, FILE *salida, int estado, char caracter);
int evaluarPalabra(FILE *entrada, FILE *salida);
int escribirResultado(int estado, FILE *salida);
int evaluarArchivo();*/

void inicializar(char[],int);
void leerCadena(FILE *archivo, char temp[30]);
void escribirCadena(FILE *, char[]);
char* reconocerCadena(char v[]);

int main()
{
    printf("asd \n");
    FILE *archivoEntrada = fopen("entrada.txt", "r"); // Despues cambiar nombre de archivo a "entrada.txt"
    FILE *archivoSalida;
	//archivoSalida = fopen("salida.txt", "w");
    if (archivoEntrada == NULL)
    {
        printf("No tiene nada el archivo");
        exit(1);
    }
    
	char temp[30];
	inicializar(temp,30);
	 
	char aux;

    aux = 'z';
    for (int j = 0; aux != ','; j++)
    {
        aux = fgetc(archivoEntrada);
        if (aux != ',')
        {
            temp[j] = aux;
        }
    }

    printf("%s", temp);
	
	escribirCadena(archivoSalida,temp);

    fclose(archivoEntrada);
    
    
    return 0;
}

void inicializar(char vector[], int tam){
	for(int i = 0; i<tam; i++){
		vector[i]= '\0';
	}
}


void escribirCadena(FILE *salida, char v[]){ //escribe una cadena en un archivo CONSULTAR!!!1!!11
	salida = fopen("salida.txt", "w");  
	fputs(v,salida);    
	fclose(salida);

}


char* reconocerCadena(char v[]){
	char caracter = v[0];
	char* tipoCadena;
	switch(caracter){
		case '0':  // q1     llamar a otra funcion?
        break;
		default: tipoCadena = "NO RECONOCIDA";
	};

	switch(caracter){
		case '1': case '2': case '3': case '4': case '5': case '6': case '7':  // q1     llamar a otra funcion?
        break;
		default: tipoCadena = "NO RECONOCIDA";
	};

}




/*void leerCadena(FILE* archivo, char tempo[]){
    char aux;

    while(!feof(archivo)){
        aux = 'z';
        for(int j=0;aux !=',';j++){
            aux = fgetc(archivo);
            if(aux != ','){
                tempo[j] = aux;
            }
        }
    }
    printf("%c",tempo[0]);
}   */