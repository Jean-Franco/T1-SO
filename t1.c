#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define mazo "/mnt/c/Users/aevi1/Downloads/mazo"
#define jugador1 "/mnt/c/Users/aevi1/Downloads/jugador1"
#define jugador2 "/mnt/c/Users/aevi1/Downloads/jugador2"
#define jugador3 "/mnt/c/Users/aevi1/Downloads/jugador3"
#define jugador4 "/mnt/c/Users/aevi1/Downloads/jugador4"

typedef struct{
  char color[100];
}colores;
typedef struct{
  char numero[100];
}numeros;

void* crearCartas(){
  //creando las cartas del 0 al 9
  colores *arreglo=(colores *)malloc(sizeof(colores *)*4);
  strcpy(arreglo[0].color,"Azul");
  strcpy(arreglo[1].color,"Rojo");
  strcpy(arreglo[2].color,"Amarillo");
  strcpy(arreglo[3].color,"Verde");
  //printf("mi color es %s\n",arreglo[2].color);
  numeros *arregloDos=(numeros *)malloc(sizeof(numeros)*10);
  strcpy(arregloDos[0].numero,"Cero");
  strcpy(arregloDos[1].numero,"Uno");
  strcpy(arregloDos[2].numero,"Dos");
  strcpy(arregloDos[3].numero,"Tres");
  strcpy(arregloDos[4].numero,"Cuatro");
  strcpy(arregloDos[5].numero,"Cinco");
  strcpy(arregloDos[6].numero,"Seis");
  strcpy(arregloDos[7].numero,"Siete");
  strcpy(arregloDos[8].numero,"Ocho");
  strcpy(arregloDos[9].numero,"Nueve");
  int i;
  int j;
  for (i = 0; i < 10; ++i) {
    for (j = 0; j < 4; j++) {
      if(i==0){
        char nombreArchivo[100];
        strcpy(nombreArchivo,arregloDos[i].numero);
        strcat(nombreArchivo,arreglo[j].color);
        strcat(nombreArchivo,".txt");
        //puts(nombreArchivo);
        FILE* archivo=fopen(nombreArchivo,"w");
      }else{
        //printf("i es %d\n",i);
        //printf("mi numero es %s\n",arregloDos[i].numero);
        char nombreArchivo[100];
        char nombreArchivo2[100];
        strcpy(nombreArchivo,arregloDos[i].numero);
        strcat(nombreArchivo,arreglo[j].color);
        strcpy(nombreArchivo2,nombreArchivo);
        strcat(nombreArchivo,".txt");
        //puts(nombreArchivo);
        FILE* archivo=fopen(nombreArchivo,"w");
        strcat(nombreArchivo2,"2");
        strcat(nombreArchivo2,".txt");
        //puts(nombreArchivo2);
        FILE* archivo2=fopen(nombreArchivo2,"w");
      }
    }
  }
  //creamos los +2 de cada color
  for (i = 0; i < 4; i++) {
    char nombreArchivo[100];
    char nombreArchivo2[100];
    strcpy(nombreArchivo,"+2");
    strcpy(nombreArchivo2,"+2");
    strcat(nombreArchivo,arreglo[i].color);
    strcat(nombreArchivo2,arreglo[i].color);
    strcat(nombreArchivo2,"2");
    strcat(nombreArchivo2,".txt");
    strcat(nombreArchivo,".txt");
    FILE* archivo=fopen(nombreArchivo,"w");
    FILE* archivo2=fopen(nombreArchivo2,"w");
  }
  //creamos los reversas
  for (i = 0; i < 4; i++) {
    char nombreArchivo[100];
    char nombreArchivo2[100];
    strcpy(nombreArchivo,"Reversa");
    strcpy(nombreArchivo2,"Reversa");
    strcat(nombreArchivo,arreglo[i].color);
    strcat(nombreArchivo2,arreglo[i].color);
    strcat(nombreArchivo2,"2");
    strcat(nombreArchivo2,".txt");
    strcat(nombreArchivo,".txt");
    FILE* archivo=fopen(nombreArchivo,"w");
    FILE* archivo2=fopen(nombreArchivo2,"w");
  }
  //creamos las cartas de salto
  for (i = 0; i < 4; i++) {
    char nombreArchivo[100];
    char nombreArchivo2[100];
    strcpy(nombreArchivo,"Salto");
    strcpy(nombreArchivo2,"Salto");
    strcat(nombreArchivo,arreglo[i].color);
    strcat(nombreArchivo2,arreglo[i].color);
    strcat(nombreArchivo2,"2");
    strcat(nombreArchivo2,".txt");
    strcat(nombreArchivo,".txt");
    FILE* archivo=fopen(nombreArchivo,"w");
    FILE* archivo2=fopen(nombreArchivo2,"w");
  }
  //creamos las cartas Colores negras

  FILE* archivo4=fopen("ColoresNegro1.txt","w");
  FILE* archivo3=fopen("ColoresNegro2.txt","w");
  FILE* archivo2=fopen("ColoresNegro3.txt","w");
  FILE* archivo1=fopen("ColoresNegro4.txt","w");
  //creamos las cartas +4 negras
  FILE* archivo5=fopen("+4Negra1.txt","w");
  FILE* archivo6=fopen("+4Negra2.txt","w");
  FILE* archivo7=fopen("+4Negra3.txt","w");
  FILE* archivo8=fopen("+4Negra4.txt","w");
}

int main(int argc, char const *argv[]) {
  struct stat verificar = {0};
  int i, j,r;
  DIR *d;
  struct dirent *sd;
  int cont=0;
  int max=109;
  int min=2;
  srand (time(NULL));
  char directorio[100];
  //aqui verificamos si existe la carpeta mencionada, si no existe, se crea
  if (stat(mazo, &verificar) == -1) {
    mkdir(mazo, 0700);
  }
  if (stat(jugador1, &verificar) == -1) {
    mkdir(jugador1, 0777);
  }
  if (stat(jugador2, &verificar) == -1) {
    mkdir(jugador2, 0777);
  }
  if (stat(jugador3, &verificar) == -1) {
    mkdir(jugador3, 0777);
  }
  if (stat(jugador4, &verificar) == -1) {
    mkdir(jugador4, 0777);
  }
  //se crean las cartas dentro de la carpeta mazo (chdir sirve para mover el proceso del programa a la direccion que se le pase)
  chdir(mazo);
  crearCartas();
  //repartir cartas
  while(cont<4){
    j=0;
    while(j<7){
      i=0;
      r = (rand() % (max + 1 - min)) + min; //random entre min y max incluidos
      d=opendir(mazo); //abrimos el directorio en el que nos encontramos (en este caso Mazo)
      if(d==NULL){
        printf("ERROR FATAL: No se pudo abrir el directorio\n");
        exit(1);
      }
      //iteramos sobre los archivos del directorio que abrimos
      while( (sd=readdir(d)) != NULL ){
        if(r==i){
          //movemos el archivo random al jugador correspondiente
          if (cont==0) {
            char nombreArchivo[100];
            strcpy(nombreArchivo,sd->d_name);
            chdir(jugador1);
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir(mazo);
            remove(nombreArchivo);
          }
          if (cont==1) {
            char nombreArchivo[100];
            strcpy(nombreArchivo,sd->d_name);
            chdir(jugador2);
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir(mazo);
            remove(nombreArchivo);
          }
          if (cont==2) {
            char nombreArchivo[100];
            strcpy(nombreArchivo,sd->d_name);
            chdir(jugador3);
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir(mazo);
            remove(nombreArchivo);
          }
          if (cont==3) {
            char nombreArchivo[100];
            strcpy(nombreArchivo,sd->d_name);
            chdir(jugador4);
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir(mazo);
            remove(nombreArchivo);
          }
        }
        i+=1;
      }
      j+=1;
      max=max-1;
    }
    cont+=1;
  }
  return 0;
}
