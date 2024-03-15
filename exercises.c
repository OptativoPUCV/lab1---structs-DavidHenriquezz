#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  
  int max = arr[0];

  for (int i = 1 ; i < size ; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {

  int arr_rev[size];
  int pos = size - 1;
  for (int i = 0 ; i < size ; i++){
    arr_rev[pos] = arr[i];
    pos--;
  }

  for (int i = 0 ; i < size ; i++){
    arr[i] = arr_rev[i];
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/

int *filterEvenNumbers(int arr[], int size, int *newSize) {

  int * arr_par = NULL;
  int size_par = 0;
  for (int i = 0 ; i < size ; i++){
    if (arr[i] %2 == 0){
      size_par++;
    }
  }

  arr_par = (int*)malloc((size_par) * sizeof(int));
  
  for (int i = 0 ; i < size ; i++){

    if (arr[i] % 2 == 0){
      arr_par[size_par] = arr[i];
      size_par++;
    }
  }
  *newSize = size_par;
  return arr_par;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/

int compare(const void *a, const void *b){
  int *PtrA = (int *)a;
  int *PtrB = (int *)b;

  if (*PtrA > *PtrB) return 1;
  return 0;
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {

  for (int i= 0 ; i < size1 ; i++){
    result[i] = arr1[i];
  }
  for (int i = size1 ; i < size1 + size2 ; i++){
    result[i] = arr2[i - size1];
  }

  qsort(result, size1 + size2, sizeof(int), compare);
  
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/

int compare_rev(const void *a, const void *b){
  int *PtrA = (int *)a;
  int *PtrB = (int *)b;

  if (*PtrA < *PtrB) return 1;
  return 0;
}

int esDes (int arr[], int size, int arr_ordenado[]){
  
  qsort(arr_ordenado, size, sizeof(int), compare_rev);

  for (int i = 0 ; i < size ; i++){
    if (arr[i] != arr_ordenado[i]){
      return 0;
    }
  }
  return 1;
}

int checkSorted(int arr[], int size) {
  
  int arr_comp[size];

  for (int i = 0 ; i < size ; i++){
    arr_comp[i] = arr[i];
  }
  qsort(arr_comp, size, sizeof(int), compare);

  for (int i = 0 ; i < size ; i++){
    if (arr_comp[i] != arr[i]){
      if (esDes(arr, size, arr_comp) == 1) return -1;
      else return 0;
    }
  }
  return 1;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) {
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
                      }

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
  
  Nodo *lista = NULL;

  for (int i = 0 ; i < size ; i++){
    lista = (Nodo*)malloc(sizeof(Nodo));
    lista->numero = arr[i];
    if (i == size - 1){
      lista->siguiente = NULL;
    }
  }
  return lista;
}
