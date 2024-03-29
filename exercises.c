#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) {
  if (arr == NULL || size <= 0) {
    return 0;
  }

  int mayor = arr[0];
  for (int i = 0; i < size; i++) {
    if (arr[i] > mayor) {
      mayor = arr[i];
    }
  }

  return mayor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {


  if (arr == NULL || size <= 0) {
    return;
  }
/*
  int *arrNuevo;
  arrNuevo = malloc(size * sizeof(int));

  int indice = 0;
  for (int i = size - 1; i >= 0; i--) {
    arrNuevo[indice] = arr[i];
    indice++;
  }

  for (int j = 0; j < size; j++) {
    arr[j] = arrNuevo[j];
  }*/


  /*

  if (arr == NULL || size <= 0) {
    return;
  }

  int inicio = 0;
  int fin = size - 1;

  while (inicio < fin) {
    int temp = arr[inicio];
    arr[inicio] = arr[fin];
    arr[fin] = temp;

    inicio++;
    fin--;
  }*/   

  int temp;
  for(int i=0; i < size / 2; i++) {
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) {
  if (arr == NULL || size <= 0) {
    return NULL;
  }

  int *nuevoArreglo;
  nuevoArreglo = malloc(size * sizeof(int));

  *newSize = 0;

  //int indice = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      nuevoArreglo[(*newSize)++] = arr[i];
      //indice++;
      //*newSize += 1;
    }
  }

  // no "indice + 1" por que se suma uno al final
  //*newSize = indice;
  return nuevoArreglo;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) {

  if (arr1 == NULL || arr2 == NULL || size1 <= 0 || size2 <= 0) {
    return;
  }

  int i = 0, j = 0, k = 0;

  while (i < size1 && j < size2) {
    if (arr1[i] <= arr2[j]) {
      result[k++] = arr1[i++];
    } else {
      result[k++] = arr2[j++];
    }
  }

  //Se copian los elementos ya que pueden terminar de procesarse uno antes que otro

  while (i < size1) {
    result[k++] = arr1[i++];
  }

  while (j < size2) {
    result[k++] = arr2[j++];
  }
}

  /*
  Ejercicio 5: Comprobación de Ordenación
  Descripción: Escribe una función que tome un arreglo y su tamaño,
  y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
    0 si no está ordenado, y -1 si está ordenado en orden descendente.
  */
int checkSorted(int arr[], int size) {
  if (arr == NULL || size <= 0)
    return 0; // Manejo de casos especiales

  bool ascendant = true;
  bool descendant = true;

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      ascendant = false;
    }
    if (arr[i] < arr[i + 1]) {
      descendant = false;
    }
  }

  if (ascendant) {
        return 1;
  }

  if (descendant) {
        return -1;
  }


  return 0;
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

  Autor autor;
  autor.anioNacimiento = anioNacimiento;
  strcpy(autor.nombre, nombreAutor);

  libro->anioPublicacion = anioPublicacion;
  libro->autor = autor;
  strcpy(libro->titulo, titulo);
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
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  if (arr == NULL || size <= 0) return NULL; 

  Nodo* cabeza = NULL;
  Nodo* actual = NULL;
  Nodo* nuevoNodo = NULL;

  for (int i = 0; i < size; i++) {
      nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
      if (nuevoNodo == NULL) {
          return NULL;
      }

      nuevoNodo->numero = arr[i];
      nuevoNodo->siguiente = NULL;

      if (cabeza == NULL) {
          cabeza = nuevoNodo;
      } else {
          actual->siguiente = nuevoNodo;
      }

      actual = nuevoNodo;
  }

  return cabeza; 
}
