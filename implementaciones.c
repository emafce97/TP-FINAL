#include "headers.h"
#include <stdio.h>
#include <malloc.h>

/*
 * Crea un estudiante
 */
Estudiante crearEstudiante(){

    Estudiante e;

    printf("  Ingrese el nombre: ");
    scanf("%s", e.nombre);

    printf("  Ingrese el DNI: ");
    scanf("%ld", &e.dni);

    printf("  Ingrese la edad: ");
    scanf("%d", &e.edad);

    printf("  Ingrese el legajo: ");
    scanf("%d", &e.legajo);

    return e;
}

/*
 * Verifica si los datos del estudiante son correctos
 */
int datosCorrectosEstudiante(Estudiante e){
    if(strlen(e.nombre) >= 3 && e.dni > 0 && e.edad >= 17 && e.legajo > 0){
        return 1;
    }
    return 0;
}

/*
 * Imprime los datos de un estudiante
 */
void mostrarDatosEstudiante(Estudiante e){
    printf("  - NOMBRE: %s\n  - DNI: %ld\n  - EDAD: %d\n  - LEGAJO: %d\n", e.nombre, e.dni, e.edad, e.legajo);
}

/*
 * Crea una lista de estudiante
 */
ListaEstudiantes crearListaEstudiantes() {
    ListaEstudiantes le;
    le.head = NULL;
    le.cantEstudiantes = 0;
    return le;
}

/*
 * Crea un NodoEstudiante
 */
NodoEstudiante *crearNodoEstudiante(Estudiante e){
    NodoEstudiante *nodo = (NodoEstudiante*) malloc(sizeof(NodoEstudiante));
    nodo->estudiante = e;
    nodo->sgte = NULL;
    return nodo;
}

/*
 * Agrega un estudiante a la lista
 */
void agregarEstudiante(ListaEstudiantes *lista, NodoEstudiante **cabeza, Estudiante e) {

    NodoEstudiante *nuevo = crearNodoEstudiante(e);

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        NodoEstudiante *puntero = *cabeza;
        while(puntero->sgte != NULL){
            puntero = puntero -> sgte;
        }
        puntero -> sgte = nuevo;
    }

    lista->cantEstudiantes++;
}

/*
 * Imprime los datos de cada estudiante cargados en la lista
 */
void listarEstudiantes(ListaEstudiantes *le, NodoEstudiante **cabeza) {
    if (*cabeza == NULL) {
        printf("  --NO HAY ALUMNOS CARGADOS--");
    }else {
        NodoEstudiante *cursor = *cabeza;
        while (cursor != NULL) {
            mostrarDatosEstudiante(cursor->estudiante);
            cursor = cursor -> sgte;
        }
        printf ("  --ESTUDIANTES CARGADOS: %d--\n", le->cantEstudiantes);
    }
}

/*
 * Imprime la cantidad de estudiantes cargados
 */
int cantidadDeEstudiantes(ListaEstudiantes *lista){
    return lista->cantEstudiantes;
}


/*
 * Busca e impreme los datos de un alumno buscado por su nombre
 */
void buscarEstudiantePorNombre(NodoEstudiante **cabeza) {

    char nombre[100];
    printf("  Ingrese el nombre del estudiante: ");
    scanf("%s", nombre);

    NodoEstudiante *cursor = *cabeza;
    Estudiante *buscado = NULL;

    while (cursor != NULL) {
        if (strcmp(cursor->estudiante.nombre, nombre) == 0){
            buscado = &cursor->estudiante;
        }
        cursor = cursor -> sgte;
    }
    if (buscado == NULL) {
        printf("  -El alumno %s no existe--\n", nombre);
    } else {
        mostrarDatosEstudiante(*buscado);
    }
}

/*
 * Busca e imprime los datos de alumnos dentro de un rango de edad
 */
void buscarEstudiantesPorRangoDeEdad(NodoEstudiante **cabeza) {

    int inicio,final;

    printf("Ingrese la edad minima: ");
    scanf("%d", &inicio);
    printf("Ingrese la edad maxima: ");
    scanf("%d", &final);

    NodoEstudiante *puntero = *cabeza;
    printf("Los estudiantes que tienen entre %d y %d anios son:\n", inicio, final);

    while (puntero != NULL) {
        if (puntero -> estudiante.edad >= inicio && puntero->estudiante.edad<= final) {
            mostrarDatosEstudiante(puntero->estudiante);
            printf("----#----#----#----#----#----#\n");
        }
        puntero = puntero->sgte;
    }
}

/*
 * Elimina un estudiante segun el nombre y legajo
 */
void eliminarEstudianteDeLaLista (ListaEstudiantes *le,NodoEstudiante **cabeza) {

    char nombre[100];
    int legajo;
    int eliminado = 0;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombre);
    printf("Ingrese el numero de legajo: ");
    scanf("%d", &legajo);


    if (le->cantEstudiantes == 0) {
        printf("[ERROR]:NO HAY NADA PARA BORRAR\n");
    } else if (le->cantEstudiantes == 1) {
        *cabeza = NULL;
        le->cantEstudiantes--;
    } else {
        NodoEstudiante *aux1 = *cabeza;
        NodoEstudiante *aux2 = NULL;
        while (aux1 != NULL) {
            if (strcmp(aux1->estudiante.nombre, nombre) == 0 && aux1->estudiante.legajo == legajo) {
                if (aux2 != NULL) {
                    aux2->sgte = aux1->sgte;
                } else {
                    *cabeza = aux1->sgte;
                }
                free(aux1);
                eliminado = 1;
                le->cantEstudiantes--;
                break;
            }
            aux2 = aux1;
            aux1 = aux1->sgte;
        }
        if (eliminado == 0) {
            printf("  -El estudiante %s de legajo %d no se encuentra en la lista\n", nombre, legajo);
        } else {
            printf("  -El estudiante %s con legajo %d fue eliminado de la lista\n", nombre, legajo);
        }
    }
}


////lo nuevo
//
//// Al pasar Materia y codigo, las agrega.
//void DarDeAltaMateria(Materia *materias, int *cantidadMaterias, char nombre[], int codigo) {
//    strcpy(materias[*cantidadMaterias].nombre, nombre);
//    materias[*cantidadMaterias].codigo = codigo;
//    (*cantidadMaterias)++;
//}
//// Recorre e imprime las materias disponibles
//void ListarMaterias(Materia *materias, int cantidadMaterias) {
//    printf("materias disponibles:\n");
//    for (int i = 0; i < cantidadMaterias; i++) {
//        printf("%d) %s Codigo: %d\n", i + 1, materias[i].nombre, materias[i].codigo);
//    }
//}
//
//// anota a un estudiante a la materia señalada con su codigo.
//void AnotarseEnMateria(Estudiante *estudiante, Materia *materias, int cantidadMaterias, int codigoMateria) {
//    for (int i = 0; i < cantidadMaterias; i++) {
//        if (materias[i].codigo == codigoMateria) {
//            estudiante->materias = realloc(estudiante->materias, (estudiante->cantidadMaterias + 1) * sizeof(Materia));
//            estudiante->materias[estudiante->cantidadMaterias] = materias[i];
//            (estudiante->cantidadMaterias)++;
//            printf("El estudiante %s se ha anotado en la materia %s.\n", estudiante->nombre, materias[i].nombre);
//            return;
//        }
//    }
//    printf("No se encontro una materia con el codigo %d.\n", codigoMateria);
//}
