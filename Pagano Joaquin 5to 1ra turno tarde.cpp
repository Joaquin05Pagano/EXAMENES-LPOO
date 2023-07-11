#include <stdio.h>
#include <string.h>

int main() {
    int personas, horarioclase, clase, totasist = 0, totgan = 0, nohayalumnos = 1, cupodisp = 0, totcla = 0;
    int cupoclase[4] = {10, 15, 12, 8};
    int asistencia[4][5] = {0};
    char nombreclase[255];

    printf("\nBienvenido al gimnasio del barrio!!!\n");
	printf("\nAqui tiene todas las clases a las que puede asistir en este gimnasio");
	printf("\nLas siguientes disponibles son:\n\ntopride\nzumba\nentrenamiento\nabdominales\n\nAl ingresar los nombres, ingreselos asi como se escribieron, muchas gracias\nIndique las actividades en el orden indicado en todas los horarios\n\n");
    for (horarioclase = 0; horarioclase < 5; horarioclase++) {
        printf("\n\nHorario N%d:\n\n", horarioclase + 1);
        for (clase = 0; clase < 4; clase++) {
            printf("\nIngrese el nombre de la clase: ");
            scanf("%s", nombreclase);  //lee el nombre de la clase
            printf("Ingrese la cantidad de personas que hubo en la clase: ");
            scanf("%d", &personas); //lee el numero de personas en la clase 
            if (personas <= cupoclase[clase]) {
                asistencia[clase][horarioclase]=personas;
                cupoclase[clase] -= personas;   
                totasist += personas;  // se fija si hay espacio en la clase indicada
                if (horarioclase == 2) {
                    totgan += personas * 700;
                } else if (horarioclase < 2) {
                    totgan += personas * (700 * 0.8);   //se hace el calculo de de los descuentos por horario
                } else {
                    totgan += personas * (700 * 1.15);
                }
                cupodisp = 1; //Pone la variable cupodisp en 1
            } else {
                printf("No hay espacio suficiente para la clase '%s' en este horario\n", nombreclase);
            }
        }
        if (!cupodisp) {  //dice si no hay clase en el horario
            printf("No hubo ninguna clase en el horario %d\n", horarioclase + 1); 
        }
    }
    printf("\n----------------INFORMACION FINAL DEL GIMNASIO----------------");
    printf("\n\nIndicacion de las asistencias:\n");
    for (clase = 0; clase < 4; clase++) { // indica las asistencia y las toma
        printf("Clase %d: ", clase + 1);

        for (horarioclase = 0; horarioclase < 5; horarioclase++) {
            totcla += asistencia[clase][horarioclase];
        }
        printf("%d personas\n", totcla);
    }
    printf("\nLas clases sin alumnos asistidos son:\n");
    for (clase = 0; clase < 4; clase++) {   // clase que no tiene alumnos
        
        for (horarioclase = 0; horarioclase < 5; horarioclase++) {
            if (asistencia[clase][horarioclase] > 0) {
                nohayalumnos = 0;
                break;
            }
            }
            if (nohayalumnos) {
            printf("\nclase %d\n", clase + 1); //indica los alumnos por clase
            }
    }
    printf("\nLa ganancia total con el gimnasio entre todas las clases es de: $%d dolares\n", totgan);
    //El total de ganancias generadas con el gim
}

