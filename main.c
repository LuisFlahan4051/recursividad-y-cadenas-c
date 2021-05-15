#include <stdio.h>
#include <stdlib.h> // <-- EXIT SUCCESS
#include <wchar.h> // <-- Carácteres especiales
#include <locale.h> // <-- Determina la localidad y zonas horarias. (LC_ALL). Para los acentos.
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h> // <-- Manejo tipoc. Conversion de un caracter a mayusculas o minusculas.
#define LC LC_ALL
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void llenar_datos_aleatorios(int arreglo[], int tamanio, int limiteAleatorioInferior, int limiteAleatorioSuperior)
{
    for (int i = 0; i < tamanio; i++)
    {
        arreglo[i] = rand() % (limiteAleatorioSuperior + 1 - limiteAleatorioInferior);
    }
}

int impresion_arreglo_recursivo(int arreglo[], int tamanio, int posicionInicial){
    printf("%d ",arreglo[posicionInicial]);
    if(posicionInicial>=tamanio-1){
        return 0;
    }
    impresion_arreglo_recursivo(arreglo,tamanio,++posicionInicial);
}

void programa1(){
    int desde = 0, hasta = 10, aux = 0;

    printf(ANSI_COLOR_YELLOW"\nIngrese el tamaño del arreglo:\n> "ANSI_COLOR_RESET);
    int tamanio = 0;
    scanf("%d", &tamanio);
    int arreglo[tamanio];
    


    printf(ANSI_COLOR_YELLOW"\n1)Aleatorios.\n2)Ingresar valores.");
    printf("\nIngrese la opción:\n> "ANSI_COLOR_RESET);
    int opcion = 0;
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        llenar_datos_aleatorios(arreglo, tamanio, desde, hasta);    
        break;
    case 2:
        for (int i = 0; i < tamanio; i++)
        {
            printf(ANSI_COLOR_YELLOW"\nIngrese el valor %d:\n> "ANSI_COLOR_RESET, i+1);
            scanf("%d",&aux);
            arreglo[i] = aux;
        }
        break;
    default:
        break;
    }

    printf(ANSI_COLOR_MAGENTA"\nArreglo:\n"ANSI_COLOR_RESET);
    
    impresion_arreglo_recursivo(arreglo,tamanio,0);
    //Impresión en forma iterativa.
    /*for (int i = 0; i < tamanio; i++)
    {
        printf("%d ",arreglo[i]);
    }*/
    printf("\n");
}

int invertir_arreglo(int arreglo[], int tamanio, int posicionInicial){
    int destino = abs(posicionInicial - tamanio); //Entrega el absoluto pero aumentado en 1
    int aux = arreglo[posicionInicial];
    int aux2 = arreglo[destino-1];
    arreglo[posicionInicial] = aux2;
    arreglo[destino-1] = aux;

    if (posicionInicial >= (tamanio / 2)-1)
    return 0;
    
    invertir_arreglo(arreglo, tamanio, ++posicionInicial);
}

void programa2(){
    int tamanio = 10;
    int arreglo[tamanio];
    llenar_datos_aleatorios(arreglo, tamanio, 0, 10);
    
    printf(ANSI_COLOR_MAGENTA"\nArreglo original:\n"ANSI_COLOR_RESET);
    impresion_arreglo_recursivo(arreglo,tamanio,0);
    printf("\n");


    invertir_arreglo(arreglo,tamanio,0);
    printf(ANSI_COLOR_MAGENTA"\nArreglo invertido:\n"ANSI_COLOR_RESET);
    impresion_arreglo_recursivo(arreglo, tamanio, 0);
    printf("\n");

}

int invertir_cadena(char string[], int tamanio, int posicionInicial){
    int destino = abs(posicionInicial - tamanio); //Entrega el absoluto pero aumentado en 1
    int aux = string[posicionInicial];
    int aux2 = string[destino - 1];
    string[posicionInicial] = aux2;
    string[destino - 1] = aux;

    if (posicionInicial >= (tamanio / 2) - 1)
        return 0;

    invertir_cadena(string, tamanio, ++posicionInicial);
}

void programa3(){
    char string[20];
    printf(ANSI_COLOR_YELLOW"\nIngrese una cadena, no más de 20 caracteres:\n> "ANSI_COLOR_RESET);
    scanf("%s",&string);
    
    //printf("\nTamaño: %d Cadena:%s\n",strlen(string),string);
    //printf("\nTamaño: %d Caracter:%c\n", strlen(string), string[0]);
    invertir_cadena(string, strlen(string), 0);
    
    printf(ANSI_COLOR_MAGENTA"\nCadena Inversa:\n"ANSI_COLOR_RESET);
    printf("%s\n",string);
}

int convertir_cadena_a_minusculas(char string[], int tamanio, int posicionInicial){
    string[posicionInicial] = tolower(string[posicionInicial]);
    if (posicionInicial >= tamanio - 1)
    {
        return 0;
    }
    convertir_cadena_a_minusculas(string, tamanio, ++posicionInicial);
}

void programa4(){
    printf(ANSI_COLOR_YELLOW"\nIngrese una cadena, no más de 20 caracteres:\n> "ANSI_COLOR_RESET);
    char string[20];
    scanf("%s",&string);

    convertir_cadena_a_minusculas(string, strlen(string), 0);
    printf(ANSI_COLOR_MAGENTA"\nCadena areglada:"ANSI_COLOR_RESET);
    printf("\n%s", string);

    char stringInvertida[20];
    strcpy(stringInvertida, string);
    
    invertir_cadena(stringInvertida,strlen(stringInvertida),0);
    
    printf(ANSI_COLOR_MAGENTA"\nCadena Inversa:"ANSI_COLOR_RESET);
    printf("\n%s", stringInvertida);

    //printf("\nEstado: %d\n", strncmp(string, stringInvertida, strlen(string)));
    if(strncmp(string, stringInvertida, strlen(string) != 0)){
        printf(ANSI_COLOR_RED"\nNo es una palabra políndroma.\n"ANSI_COLOR_RESET);
    }else{
        printf(ANSI_COLOR_GREEN"\nEs una palabra políndroma.\n"ANSI_COLOR_RESET);
    }
}

int main(){
    setlocale(LC, ""); // Hibilita los carácteres de la zona.
    srand(time(NULL)); // Fija una semilla para utilizar rand.

    printf("\n1)Imprimir arreglo.\n2)Invetir arreglo.\n3)Invertir cadena.\n4)Palíndromos.");
    printf("\nIngresa la opción a probar:\n> ");
    int opcion;
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        programa1();
        break;
    case 2:
        //printf("%d\n", 7/2); --> 3
        programa2();
        break;
    case 3:
        programa3();
        break;
    case 4:
        programa4();
        /*
        printf(ANSI_COLOR_RED "This text is RED!" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_GREEN "This text is GREEN!" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_YELLOW "This text is YELLOW!" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_BLUE "This text is BLUE!" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_CYAN "This text is CYAN!" ANSI_COLOR_RESET "\n");*/
        break;
    default:
        break;
    }

    return EXIT_SUCCESS;
}