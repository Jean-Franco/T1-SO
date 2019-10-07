#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

typedef struct{
  char color[100];
}colores;
typedef struct{
  char numero[100];
}numeros;
void crearArchivo(int jugador,char nombreArchivo[]){
  char dirJ1[]="jugador1/";
  char dirJ2[]="jugador2/";
  char dirJ3[]="jugador3/";
  char dirJ4[]="jugador4/";
  char final[100];
  if(jugador==1){
    sprintf(final,"%s%s",dirJ1,nombreArchivo);
    FILE *archivo=fopen(final,"w");
    fclose(archivo);
  }
  if(jugador==2){
    sprintf(final,"%s%s",dirJ2,nombreArchivo);
    FILE *archivo=fopen(final,"w");
    fclose(archivo);
  }
  if(jugador==3){
    sprintf(final,"%s%s",dirJ3,nombreArchivo);
    FILE *archivo=fopen(final,"w");
    fclose(archivo);
  }
  if(jugador==4){
    sprintf(final,"%s%s",dirJ4,nombreArchivo);
    FILE *archivo=fopen(final,"w");
    fclose(archivo);
  }
}

void removerDeMazo(char nombreArchivo[]){
  char final[100];
  char dirMazo[]="mazo/";
  sprintf(final,"%s%s",dirMazo,nombreArchivo);
  remove(final);
}
void removerDeMano(char nombreArchivo[],int jugador){
  char dirJ1[]="jugador1/";
  char dirJ2[]="jugador2/";
  char dirJ3[]="jugador3/";
  char dirJ4[]="jugador4/";
  char final[100];
  if(jugador==1){
    char final[100];
    sprintf(final,"%s%s",dirJ1,nombreArchivo);
    remove(final);
  }
  if(jugador==2){
    char final[100];
    sprintf(final,"%s%s",dirJ2,nombreArchivo);
    remove(final);
  }
  if(jugador==3){
    char final[100];
    sprintf(final,"%s%s",dirJ3,nombreArchivo);
    remove(final);
  }
  if(jugador==4){
    char final[100];
    sprintf(final,"%s%s",dirJ4,nombreArchivo);
    remove(final);
  }
}

void crearCartas(){
  char dirMazo[]="mazo/";
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
        char final[100];
        sprintf(final,"%s%s",dirMazo,nombreArchivo);
        FILE* archivo=fopen(final,"w");
        fclose(archivo);
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
        char final[100];
        sprintf(final,"%s%s",dirMazo,nombreArchivo);
        FILE* archivo=fopen(final,"w");
        fclose(archivo);
        strcat(nombreArchivo2,"2");
        strcat(nombreArchivo2,".txt");
        //puts(nombreArchivo2);
        char final2[100];
        sprintf(final2,"%s%s",dirMazo,nombreArchivo2);
        FILE* archivo2=fopen(final2,"w");
        fclose(archivo2);
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
    char final[100];
    sprintf(final,"%s%s",dirMazo,nombreArchivo);
    FILE* archivo=fopen(final,"w");
    fclose(archivo);
    char final2[100];
    sprintf(final2,"%s%s",dirMazo,nombreArchivo2);
    FILE* archivo2=fopen(final2,"w");
    fclose(archivo2);
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
    char final[100];
    char final2[100];
    sprintf(final,"%s%s",dirMazo,nombreArchivo);
    sprintf(final2,"%s%s",dirMazo,nombreArchivo2);
    FILE* archivo=fopen(final,"w");
    FILE* archivo2=fopen(final2,"w");
    fclose(archivo);
    fclose(archivo2);
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
    char final[100];
    char final2[100];
    sprintf(final,"%s%s",dirMazo,nombreArchivo);
    sprintf(final2,"%s%s",dirMazo,nombreArchivo2);
    FILE* archivo=fopen(final,"w");
    FILE* archivo2=fopen(final2,"w");
    fclose(archivo);
    fclose(archivo2);
  }
  //creamos las cartas Colores negras

  FILE* archivo4=fopen("mazo/ColoresNegro1.txt","w");
  FILE* archivo3=fopen("mazo/ColoresNegro2.txt","w");
  FILE* archivo2=fopen("mazo/ColoresNegro3.txt","w");
  FILE* archivo1=fopen("mazo/ColoresNegro4.txt","w");
  fclose(archivo1);
  fclose(archivo2);
  fclose(archivo3);
  fclose(archivo4);

  //creamos las cartas +4 negras
  FILE* archivo5=fopen("mazo/+4Negra1.txt","w");
  FILE* archivo6=fopen("mazo/+4Negra2.txt","w");
  FILE* archivo7=fopen("mazo/+4Negra3.txt","w");
  FILE* archivo8=fopen("mazo/+4Negra4.txt","w");
  fclose(archivo5);
  fclose(archivo6);
  fclose(archivo7);
  fclose(archivo8);


}

char *Wild(){
  int opcionWild;
  printf("Escoge el color\n\n");
  printf("(0) Rojo\n");
  printf("(1) Azul\n");
  printf("(2) Amarillo\n");
  printf("(3) Verde\n");
  scanf("%d", &opcionWild);
  if(opcionWild==0){
    printf("Se ha cambiado el color a: Rojo\n");
    return "CartaRojo";
  }
  if(opcionWild==1){
    printf("Se ha cambiado el color a: Azul\n");
    return "CartaAzul";
  }
  if(opcionWild==2){
    printf("Se ha cambiado el color a: Amarillo\n");
    return "CartaAmarillo";
  }
  if(opcionWild==3){
    printf("Se ha cambiado el color a: Verde\n");
    return "CartaVerde";
  }
}


void Reverse(){
  printf("Alteraste el orden mundial, turno del jugador anterior.\n");
}


void Mas4(int jugador){
  int cont, i, r;
  int min=2;
  int cantMazo = 0;
  DIR *d =opendir("mazo");
  if (d == NULL){
    printf("ERROR FATAL: No se pudo abrir el directorio.\n");
    exit(1);
  }
  struct dirent *sd;
  while((sd = readdir(d)) != NULL){
    cantMazo ++;
  }
  while(cont < 4){
    r = (rand() % (cantMazo + 1 - min)) + min;
    i = 0;
    while((sd = readdir(d)) != NULL){
      if(r == i){
        crearArchivo(jugador, sd-> d_name);
        removerDeMazo(sd->d_name);
        cantMazo -= 1;
      }
      i++;
    }
    cont++;
  }
  printf("Sacas 4 cartas y tu turno se ha saltado al del siguiente jugador.\n");
}


void Skip(){
  printf("El siguiente jugador no juega\n");
}


void Mas2(int jugador){
  int cont, i, r;
  int min = 2;
  int cantMazo = 0;
  DIR *d;
  d =opendir("mazo");
  if (d == NULL){
    printf("No se pudo abrir el directorio.\n");
    exit(1);
  }
  struct dirent *sd;
  while((sd = readdir(d)) != NULL){
    cantMazo ++;
  }
  while(cont < 2){
    r = (rand() % (cantMazo + 1 - min)) + min;
    i = 0;
    while( (sd = readdir(d)) != NULL){
      if(r == i){
        crearArchivo(jugador, sd-> d_name);
        removerDeMazo(sd->d_name);
        cantMazo -= 1;
      }
      i++;
    }
    cont++;
  }
  printf("El jugador que sigue saca 2 cartas y su turno se ha saltado al del siguiente jugador.\n");

}
//Tira la carta escogida por el jugador y realiza una accion si es que es una carta especial.
char *tirarCarta(char carta[], char cartaJuego[]){ //carta: la que queri tirar y cartaJuego: la que esta en mesa
    char primerosDosChar[3];
    for (int i = 0; i < 2; i++) {
      primerosDosChar[i]=carta[i];
    }
    primerosDosChar[2]='\0';
    if(strcmp(primerosDosChar,"+2") == 0){
      Mas2(1);
      return strcpy(cartaJuego, carta);
    }
    else if( strcmp(primerosDosChar,"+4") == 0){
      Mas4(1);
      return strcpy(cartaJuego, carta);
    }
    else if(strcmp(primerosDosChar,"Co")==0){
      return strcpy(cartaJuego,Wild());
    }
    else if(strcmp(primerosDosChar, "Re")==0){
      Reverse();
    }
    else if(strcmp(primerosDosChar, "Sa")==0){
      Skip();
      return strcpy(cartaJuego, carta);
    }
    else{
      return strcpy(cartaJuego, carta);
    }

}

int ValidarJugada(char carta[], char elegida[]){ //elegida es la carta que tiras
  //siempre: +4, cambio color.
  char primerosDosChar[3];
  for (int i = 0; i < 2; i++) {
    primerosDosChar[i]=elegida[i];
  }
  primerosDosChar[2]='\0';
  if (strcmp(primerosDosChar,"+4")==0) { //caso carta +4
    return 1;
  }
  if (strcmp(primerosDosChar,"Co")==0) { //caso carta Colores
    return 1;
  }


  if( (strcmp(primerosDosChar,"Un")==0) || (strcmp(primerosDosChar,"Do")==0) ){
    char color[5];
    int j=0;
    for (int i = 3; i <7; i++) {
      color[j]=elegida[i];

      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
    }

  if( (strcmp(primerosDosChar,"Tr")==0) || (strcmp(primerosDosChar,"Se")==0) || (strcmp(primerosDosChar,"Oc")==0)  || (strcmp(primerosDosChar,"Ce")==0) ){
    char color[5];
    int j=0;
    for (int i = 4; i <8; i++) {
      color[j]=elegida[i];

      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
  }
  if( (strcmp(primerosDosChar,"Si")==0) || (strcmp(primerosDosChar,"Ci")==0) || (strcmp(primerosDosChar,"Nu")==0) || (strcmp(primerosDosChar,"Sa")==0) || (strcmp(primerosDosChar,"Ca")==0)){
    char color[5];
    int j=0;
    for (int i = 5; i <9; i++) {
      color[j]=elegida[i];

      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
  }

  if (strcmp(primerosDosChar,"Cu")==0) {
    char color[5];
    int j=0;
    for (int i = 6; i <10; i++) {
      color[j]=elegida[i];

      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
  }
  if ((strcmp(primerosDosChar,"Re")==0)) {
    char color[5];
    int j=0;
    for (int i = 7; i <11; i++) {
      color[j]=elegida[i];
      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
  }
  if ((strcmp(primerosDosChar,"+2")==0)) {
    char color[5];
    int j=0;
    for (int i = 2; i <6; i++) {
      color[j]=elegida[i];
      j+=1;
    }
    int M = strlen(color);
    int N = strlen(carta);
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (carta[i + j] != color[j])
                break;
        if (j == M)
            return 1;
    }
  }
  if(strcmp(primerosDosChar,"+2")==0){ //caso +2 == +2
    for (int i = 0; i < 2; i++) {
      primerosDosChar[i]=carta[i];
    }
    primerosDosChar[2]='\0';
    if (strcmp(carta,"+2")==0) {
      return 1;
    }
  }
  if(strcmp(primerosDosChar, "Re")==0){
    for (int i = 0; i < 2; i++) {
      primerosDosChar[i]=carta[i];
    }
    primerosDosChar[2]='\0';
    if (strcmp(carta,"Re")==0) {
      return 1;
    }
  }
  if(strcmp(primerosDosChar, "Sa") == 0){
    for (int i = 0; i < 2; i++) {
      primerosDosChar[i]=carta[i];
    }
    primerosDosChar[2]='\0';
    if (strcmp(carta,"Sa")==0) {
      return 1;
    }
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  printf("                  BIENVENIDOS A UNO\n\n");
  struct stat verificar = {0};
  int i, j,r,cantJ, opcion;
  int turno =1;
  DIR *d;
  DIR *j1, *j2, *j3, *j4;
  struct dirent *sd;
  struct dirent *cartas;
  char carta[100];
  char cartaJugador[100];
  char elegida[100];
  int cont=0;
  int max=109;
  int min=2;
  srand (time(NULL));
  //aqui verificamos si existe la carpeta mencionada, si no existe, se crea
  if (stat("mazo", &verificar) == -1) {
    mkdir("mazo", 0777);
  }
  if (stat("jugador1", &verificar) == -1) {
    mkdir("jugador1", 0777);
  }
  if (stat("jugador2", &verificar) == -1) {
    mkdir("jugador2", 0777);
  }
  if (stat("jugador3", &verificar) == -1) {
    mkdir("jugador3", 0777);
  }
  if (stat("jugador4", &verificar) == -1) {
    mkdir("jugador4", 0777);
  }
  //se crean las cartas dentro de la carpeta mazo
  crearCartas();

  //repartir cartas
  while(cont<4){
    j=0;
    while(j<7){
      i=0;
      r = (rand() % (max + 1 - min)) + min; //random entre min y max incluidos

      d=opendir("mazo");//abrimos el directorio en el que nos encontramos (en este caso Mazo)
      if(d==NULL){
        printf("ERROR FATAL: No se pudo abrir el directorio\n");
        exit(1);
      }
      //iteramos sobre los archivos del directorio que abrimos
      while( (sd=readdir(d)) != NULL ){
        if(r==i){
          //movemos el archivo random al jugador correspondiente
          if (cont==0) {
            crearArchivo(1,sd->d_name);
            removerDeMazo(sd->d_name);
          }
          if (cont==1) {
            crearArchivo(2,sd->d_name);
            removerDeMazo(sd->d_name);
          }
          if (cont==2) {
            crearArchivo(3,sd->d_name);
            removerDeMazo(sd->d_name);
          }
          if (cont==3) {
            crearArchivo(4,sd->d_name);
            removerDeMazo(sd->d_name);
          }
        }
        i+=1;
      }
      j+=1;
      max=max-1;
    }
    cont+=1;
  }






  printf("Cartas repartidas: A jugar\n" );
  while(max > 0){//para que el juego siga mientras hayan cartas en el mazo
    printf("TURNO: %d\n",turno);
    //sacar la carta inicial para empezar el juego
    if(turno == 1){
      i=0;
      r = (rand() % (max + 1 - min)) + min;
      d=opendir("mazo");
      while((cartas = readdir(d)) != NULL){
        if(r ==i){
          strcpy(carta,cartas->d_name);
          removerDeMazo(cartas->d_name);
          max=max-1;
        }
        i++;
      }
      printf("Carta en mesa: %s\n", carta);
      printf("Es tu turno!, que carta quieres jugar?\n");
      j1=opendir("jugador1");
      cantJ = 1;
      while((cartas=readdir(j1)) != NULL){
        strcpy(cartaJugador,cartas->d_name);
        if(strcmp(cartaJugador,".") != 0 && strcmp(cartaJugador,"..") != 0){
          printf("(%d) %s\n",cantJ,cartaJugador);
          cantJ++;
        }
      }
      printf("(0) Sacar carta del mazo.\n");
      printf("(432) Salir del juego.\n");
      //este print muestra la carta superior que esta en la seccion de juego
      printf("Elige la opcion que deseas jugar:");
      scanf("%d", &opcion);
      if (opcion == 432){
        exit(1);
      }
      if (opcion == 0){ //IF PARA SACAR UNA CARTA DEL MAZO
        i=0;
        r = (rand() % (max + 1 - min)) + min; //random entre min y max incluidos
        d=opendir("mazo");//abrimos el directorio en el que nos encontramos (en este caso Mazo)
        if(d==NULL){
          printf("ERROR FATAL: No se pudo abrir el directorio\n");
          exit(1);
        }
        //iteramos sobre los archivos del directorio que abrimos
        while( (sd=readdir(d)) != NULL ){
          if(r==i){
            //movemos el archivo random al jugador correspondiente
            crearArchivo(1,sd->d_name);
            removerDeMazo(sd->d_name);
          }
          i+=1;
        }
        max=max-1;
      }
      else{
        i=0;
        j1=opendir("jugador1");
        while((cartas = readdir(j1)) != NULL){
          if((opcion +1) == i){
            strcpy(elegida,cartas->d_name);
          }
          i++;
        }
        printf("Has decidido jugar la carta: %s\n",elegida);
        int SePuedeOno=ValidarJugada(carta, elegida); //carta es la que está encima en juego, y elegida es la carta que quiere tirar el jugador
        if (SePuedeOno==1){
          tirarCarta(elegida,carta);
          removerDeMano(elegida,1);
        }
        else{
          printf("No puedes jugar esa carta, por favor escoge otra o saca una del mazo.\n");
        }
      }
      turno+=1;
    }else{





      printf("Carta en mesa: %s\n", carta);
      printf("Es tu turno!, que carta quieres jugar?\n");
      j1=opendir("jugador1");
      cantJ = 1;
      while((cartas=readdir(j1)) != NULL){
        strcpy(cartaJugador,cartas->d_name);
        if(strcmp(cartaJugador,".") != 0 && strcmp(cartaJugador,"..") != 0){
          printf("(%d) %s\n",cantJ,cartaJugador);
          cantJ++;
        }
      }
      printf("(0) Sacar carta del mazo.\n");
      printf("(432) Salir del juego.\n");
      //este print muestra la carta superior que esta en la seccion de juego
      printf("Elige la opcion que deseas jugar:");
      scanf("%d", &opcion);
      if (opcion == 432){
        exit(1);
      }
      if (opcion == 0){ //IF PARA SACAR UNA CARTA DEL MAZO
        i=0;
        r = (rand() % (max + 1 - min)) + min; //random entre min y max incluidos
        d=opendir("mazo");//abrimos el directorio en el que nos encontramos (en este caso Mazo)
        if(d==NULL){
          printf("ERROR FATAL: No se pudo abrir el directorio\n");
          exit(1);
        }
        //iteramos sobre los archivos del directorio que abrimos
        while( (sd=readdir(d)) != NULL ){
          if(r==i){
            //movemos el archivo random al jugador correspondiente
            crearArchivo(1,sd->d_name);
            removerDeMazo(sd->d_name);
          }
          i+=1;
        }
        max=max-1;
      }
      else{
        j1=opendir("jugador1");
        i=0;
        while((cartas = readdir(j1)) != NULL){
          if((opcion +1) == i){
            strcpy(elegida,cartas->d_name);
          }
          i++;
        }
        printf("Has decidido jugar la carta: %s\n",elegida);
        int SePuedeOno=ValidarJugada(carta, elegida); //carta es la que está encima en juego, y elegida es la carta que quiere tirar el jugador
        if (SePuedeOno==1){
          tirarCarta(elegida,carta);
          removerDeMano(elegida,1);
        }
        else{
          printf("No puedes jugar esa carta, por favor escoge otra o saca una del mazo.\n");
        }
      }

      turno+=1;
    }
  }



  return 0;
}
