#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

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

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 4; j++) {
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
  for (int i = 0; i < 4; i++) {
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
  for (int i = 0; i < 4; i++) {
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
  for (int i = 0; i < 4; i++) {
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
  //aqui verificamos si existe la carpeta mencionada, si no existe, se crea
  struct stat verificar = {0};

  if (stat("/mnt/d/2019-2/so/t1/Mazo", &verificar) == -1) {
    mkdir("/mnt/d/2019-2/so/t1/Mazo", 0700);
  }
  if (stat("/mnt/d/2019-2/so/t1/Jugador1", &verificar) == -1) {
    mkdir("/mnt/d/2019-2/so/t1/Jugador1", 0700);
  }
  if (stat("/mnt/d/2019-2/so/t1/Jugador2", &verificar) == -1) {
    mkdir("/mnt/d/2019-2/so/t1/Jugador2", 0700);
  }
  if (stat("/mnt/d/2019-2/so/t1/Jugador3", &verificar) == -1) {
    mkdir("/mnt/d/2019-2/so/t1/Jugador3", 0700);
  }
  if (stat("/mnt/d/2019-2/so/t1/Jugador4", &verificar) == -1) {
    mkdir("/mnt/d/2019-2/so/t1/Jugador4", 0700);
  }
  //se crean las cartas dentro de la carpeta mazo (chdir sirve para mover el proceso a la direccion que se le pase)
  chdir("/mnt/d/2019-2/so/t1/mazo");
  crearCartas();
  //repartir cartas
  DIR *d;
  struct dirent *sd;
  int cont=0;
  int numCartas=109;
  while(cont<4){
    int j=0;
    numCartas=numCartas-6;
    while(j<7){
      int i=0;
      int random=rand()%numCartas;
      d=opendir("."); //abrimos el directorio en el que nos encontramos (en este caso Mazo)
      if(d==NULL){
        printf("ERROR FATAL: No se pudo abrir el directorio\n");
        exit(1);
      }
      while( (sd=readdir(d)) != NULL ){
        if(random==i){
          //movemos el archivo random al jugador correspondiente
          if (cont==0) {
            char nombreArchivo[100];
            printf("Jugador 1 recibe la carta: \n");
            printf("-> %s \n",sd->d_name);
            strcpy(nombreArchivo,sd->d_name);
            chdir("/mnt/d/2019-2/so/t1/Jugador1");
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir("/mnt/d/2019-2/so/t1/mazo");
            remove(nombreArchivo);
          }
          if (cont==1) {
            char nombreArchivo[100];
            printf("Jugador 2 recibe la carta: \n");
            printf("-> %s \n",sd->d_name);
            strcpy(nombreArchivo,sd->d_name);
            chdir("/mnt/d/2019-2/so/t1/Jugador2");
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir("/mnt/d/2019-2/so/t1/mazo");
            remove(nombreArchivo);
          }
          if (cont==2) {
            char nombreArchivo[100];
            printf("Jugador 3 recibe la carta: \n");
            printf("-> %s \n",sd->d_name);
            strcpy(nombreArchivo,sd->d_name);
            chdir("/mnt/d/2019-2/so/t1/Jugador3");
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir("/mnt/d/2019-2/so/t1/mazo");
            remove(nombreArchivo);
          }
          if (cont==3) {
            char nombreArchivo[100];
            printf("Jugador 4 recibe la carta: \n");
            printf("-> %s \n",sd->d_name);
            strcpy(nombreArchivo,sd->d_name);
            chdir("/mnt/d/2019-2/so/t1/Jugador4");
            FILE *archivo=fopen(nombreArchivo,"w");
            chdir("/mnt/d/2019-2/so/t1/mazo");
            remove(nombreArchivo);
          }
        }
        i+=1;
      }
      j+=1;
    }
    cont+=1;
  }
  return 0;
}
