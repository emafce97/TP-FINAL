#include <stdio.h>
#include "headers.h"

void runMenu(){

    ListaEstudiantes le = crearListaEstudiantes();
    // ListaMaterias lm = crearListaMaterias();
    Estudiante e;
    int opcion;

    do{
        printf("-- MENU PRINCIPAL --\n");
        printf(" 1 - Estudiantes.\n");
        printf(" 2 - Materias.\n");
        printf(" 0 - Salir.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) { // MENU PRINCIPAL

            case 1:
                printf("-- MENU ESTUDIANTES --\n");
                printf(" 1.1 - Agregar Estudiante.\n");
                printf(" 1.2 - Buscar Estudiante.\n");
                printf(" 1.3 - Listar Estudiantes.\n");
                printf(" 1.4 - Salir del Menu.\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion);

                switch (opcion) { // MENU DE ESTUDIANTES
                    case 1:
                        e = crearEstudiante();
                        if(datosCorrectosEstudiante(e)){
                            agregarEstudiante(&le,&le.head, e);
                            printf("  --Estudiante agregado--\n");
                        }else{
                            printf("  [ERROR]: DATOS ERRONEOS");
                        }
                        break;
                    case 2: // ELECCION PARA OPCION 2 DEL MENU PARA ESTUDIANTES
                        printf("\n-- BUSCAR ESTUDIANTES --\n");
                        printf(" 1.2.1 - Buscar por Nombre\n");
                        printf(" 1.2.2 - Buscar por Rango de Edad\n");
                        printf(" 1.2.3 - Salir del Menu\n");
                        printf("Ingrese una opcion: ");
                        scanf("%d", &opcion);

                        switch(opcion){ // PARA ELEGIR ENTRE LAS OPCION DE BUSCAR ALUMNOS
                            case 1:
                                buscarEstudiantePorNombre(&le.head);
                                break;
                            case 2: // ELECCION PARA OPCION 2 DEL MENU DE BUSQUEDA DE ALUMNOS POR EDAD
                                printf("Has elegido la opcion para buscar un alumno/s por edad\n");
                                printf("FUNCION PARA BUSCAR ALUMNO/S POR EDAD - NO IMPLEMENTADA AUN\n");
                                break;
                            case 3:
                                printf("Saliendo...\n");
                                break;
                            default:
                                printf("Opcion invalida.\n");
                                break;
                        }break;

                    case 3:
                        listarEstudiantes(&le, &le.head);
                        break;
                    case 5:
                        printf("Saliendo del Menu...\n");
                        break;
                    default:
                        printf("Opcion invalida.\n");
                        break;
                }break;



                // MENU PARA OPCION 2 (MATERIAS)
            case 2: // ELECCION PARA OPCION 2 DEL MENU PRINCIPAL
                printf("\n-- MATERIAS --\n");
                printf("2.1-Agregar Materia.\n");
                printf("2.2-Anotarse a Materia.\n");
                printf("2.3-Rendir una Materia.\n");
                printf("2.4-Mostrar lista de Materias.\n");
                printf("2.5-Salir del Menu.\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion);
                // Creo que va un getchar

                switch (opcion) {
                    case 1:
                        printf("Has elegido la opcion para agregar una materia\n");
                        printf("FUNCION PARA AGREGAR UNA MATERIA - NO IMPLEMENTADA AUN\n");
                        break;
                    case 2:
                        printf("Has elegido la opcion para anotarse a una materia\n");
                        printf("FUNCION PARA ANOTARSE A UNA MATERIA - NO IMPLEMENTADA AUN\n");
                        break;
                    case 3:
                        printf("Has elegido la opcion para rendir una materia\n");
                        printf("FUNCION PARA RENDIR UNA MATERIA - NO IMPLEMENTADA AUN\n");
                        break;
                    case 4:
                        printf("Has elegido la opcion para mostrar la lista de materias\n");
                        printf("FUNCION PARA MOSTRAR LA LISTA DE MATERIAS - NO IMPLEMENTADA AUN\n");
                        break;
                    case 5:
                        printf("Saliendo del Menu...\n");
                        break;
                    default:
                        printf("Opcion invalida.\n");
                        break;
                }break;


                // OPCION 3 PARA CERRAR EL PROGRAMA
            case 3:
                printf("Saliendo del menu...\n");
                break;
            default: // SI NO ES NINGUNA DE LOS CASOS PLANTEADO QUE DEVUELVA OPCION INVALIDA
                printf("Opcion invalida.\n");
                break;
        } // CIERRE DEL SWITCH PRINCIPAL
    } while (opcion != 0);
}
