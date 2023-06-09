#include <stdio.h>
#include <string.h>

typedef struct Estudiante{
    char nombre[100];
    int edad;
    long int dni;
    int legajo;
}Estudiante;

Estudiante crearEstudiante();
int datosCorrectosEstudiante(Estudiante e);
void mostrarDatosEstudiante(Estudiante e);

typedef struct Materia{
    char nombre[100];
    int nota;
}Materia;

Materia crearMateria();
int datosCorrectosMateria(Materia m);
void mostrarDatosMateria(Materia m);

typedef struct NodoMateria{
    Materia materia;
    Materia sgte;
}NodoMateria;

//void agregarMateria(NodoMateria *lm, int cantMaterias, char nombre[], int codigo);
//void listarMaterias(NodoMateria *materias, int cantMaterias);
//void anotarseEnMateria(Estudiante *estudiante, NodoMateria *materias, int cantMaterias, int codigoMateria);

typedef struct NodoEstudiante{
    Estudiante estudiante;
    struct NodoEstudiante *sgte;
}NodoEstudiante;

typedef struct ListaEstudiantes{
    NodoEstudiante *head;
    int cantEstudiantes;
}ListaEstudiantes;

ListaEstudiantes crearListaEstudiantes();
void agregarEstudiante(ListaEstudiantes *le,NodoEstudiante **cabeza, Estudiante e);
void buscarEstudiantePorNombre(NodoEstudiante **cabeza);
void listarEstudiantes(ListaEstudiantes *le, NodoEstudiante **cabeza);




//NodoEstudiante buscarEstudiantePorRangoEdad(NodoEstudiante *le, int edad_min, int edad_max);
//void eliminarEstudianteLista(NodoEstudiante *le, char nombre[]);
