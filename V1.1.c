//Gabriel_Gonzalez_S2, Gabriela_Herrera_S1, Alejandro_Lobos_S2
/*-------------------------------------------------------*/
#include <stdio.h>
//Maximo de voletos por compra, o pagar toda la sala
#define MaxVol 5
#define FIL 10 
#define COL 10
/*-------------------------------------------------------*/
void PelisMenu();
void horarios();
void horas(int hora);
void SumaTotalVoletos(int Val);
void menu();
/*-------------------------------------------------------*/
//Crearemos una estructuraa que guarde los asientos asientos usados y ademas, para cada asiento guarde la persona que le corresponde, o 1 rut para mas de un asiento
struct UsuarioData{
  /*Aqui se guardaran los datos de fila y columna por rut
  basicamente, cada vez que el usuario solicite un boleto, se le solicitara su rut y asiento.*/

  unsigned rut; 
  unsigned asiento;
}; 
/*A continuacion creamos una estructura que permita guardar los datos de cada una de las peliculas, y almacenarlos en memoria*/
struct peliculas{ 
  struct UsuarioData Usuario[MaxVol] ;
};
int user_input(struct UsuarioData Barbie[], int pos){
  printf("\nIngrese datos de usuario %d\n", pos+1);
  printf("Rut: \n"); int a = scanf("%d", &Barbie[pos].rut);
  printf("Asiento: \n"); int b = scanf("%d", &Barbie[pos].asiento);
  return b;
  //Regresamos el valor de los asientos para poder utilizarlo mas adelante
}
/*-------------------------------------------------------*/

/*-------------------------------------------------------*/
int main(){
  int opcion;
  int peli;
  int hora;


  while (1){
    menu();
    if (scanf("%d", &opcion) != 1) {
        // Si no se pudo leer un número, limpiamos el bufer de entrada
        while(getchar() != '\n');
        printf("Error, por favor ingrese un numero\n ");
        continue; // Saltamos al siguiente ciclo del bucle
    }
// verificamos que lo ingresado sea correcto
    if (opcion < 1 || opcion > 4){
      printf("Error, por favor ingrese un numero entre 1 y 4.\n");
    }
    else {
      switch (opcion) {
        /*-------------------------------------------------------*/
        //Caso 1 de salida, no tocar
        case 1: 
          printf("Has salido del programa\n"); 
          return 0;
        
        /*-------------------------------------------------------*/
        /*-------------------------------------------------------*/
        //opcion comprar entradas
        case 2: 
          printf("Opcion 2\n"); 
          PelisMenu();
          scanf("%d", &peli);
          switch (peli){
            case 1:
                horarios(); 
                printf("\n Seleccione un horario: ");
                scanf("%d", &hora);
                horas(hora);
                break;
        
            case 2: 
                horarios(); 
                printf("\n Seleccione un horario: ");
                scanf("%d", &hora);
                horas(hora);
                break;
            case 3: 
                horarios(); 
                printf("\n Seleccione un horario: ");
                scanf("%d", &hora);
                horas(hora);
                break;
            case 4: 
                horarios(); 
                printf("\n Seleccione un horario: ");
                scanf("%d", &hora);
                horas(hora);
                break;
            case 5: 
              printf("Regresando al menu principal\n"); 
              break;
             case 6: 
              printf("Has salido\n"); 
              return 1;
            default: 
              printf("Ingrese un numero correcto\n");
          }
          break;
        /*-------------------------------------------------------*/
        /*-------------------------------------------------------*/
        /*Opcciones para modificar las peliculas ya existentes, Se creara una estructura para las peliculas, que guardara una serie de peliculas de base, 4 en total, y se podran cambiar estas peliculas gracias a borrar y agregar*/
        case 3: 
          printf("Opcion Borrar pelicula\n"); 
          break;
        case 4: 
          printf("Opcion Agregar pelicula\n"); 
          break;
        default: 
          printf("Ingrese un número correcto\n");
        /*-------------------------------------------------------*/
      }
    }
  }
  return 0;
}
/*-------------------------------------------------------*/
//Se crean void menus, para poder imprimir por pantalla las selecciones posibles para el usuario.
void menu(){
  printf("\n |1| Salir\n |2| Compra de entradas\n |3| Borrar pelicula\n |4| Agregar pelicula\n seleccione que desea realizar: ");
}
void PelisMenu() {
  printf("\nPeliculas disponibles.\n");
  printf("1. Barbie: $4.400 \n");
  printf("2. Oppenheimer: $4.400\n");
  printf("3. Elementos: $4.400 \n");
  printf("4. Megalodon: $4.400 \n");
  printf("5. Volver al menu principal \n");
  printf("6. Salir \n");
  printf("\nIngrese Pelicula:");
}
void horarios() {
  printf("Horarios peliculas:\n ");
  printf("1 --> 10:00\n 2 --> 12:30\n 3 --> 15:00\n 4 --> 17:00\n 5 --> 19:30\n 6 --> 21:00\n 7. Volver al menu Principal");
}
/*-------------------------------------------------------*/
//Void de funciones.
/*-------------------------------------------------------*/
void horas(int hora) {
    int num_Personas = 0;
  switch(hora){
    case 1: printf("10:00");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            struct peliculas Barbie;
            for (int i = 0;i<num_Personas;i++){
              user_input(Barbie.Usuario, i);
            };
            break;
    case 2: printf("12:30");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            break;
    case 3: printf("15:00");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            break;
    case 4: printf("17:00");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            break;
    case 5: printf("19:30");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            break;
    case 6: printf("21:00");
            printf("\nIngrese el numero de personas: ");
            scanf("%d",&num_Personas);
            SumaTotalVoletos(num_Personas);
            break;
    case 7: printf("Volviendo al menu");
            break;
    default: printf("Seleccione una opcion correcta");         break;
  }
} //Un switch para cada hora disponible
/*-------------------------------------------------------*/
/*-------------------------------------------------------*/
void SumaTotalVoletos(int Val){
    int suma = 0;
    int valor_entrada = 4400;
    for (int i = 1; i <= Val; i++){
        suma = suma + valor_entrada;
        }
    printf("El valor total de sus entradas sera de: %d\n ¿Paga con efectivo, debito, o credito?", suma);
  
} //Suma de los boletos totales
/*-------------------------------------------------------*/
//Crear una matriz (o varias) capas(es) de guardad los datos de voletos en memoria.
/* Funcion para agregar rut y asiento a la estructura, y de la estructura se sacaran los datos de asientos 1 por 1 con un ciclo for, para poder seleccionarlos en la matriz que se usara mas adelante.*/

