#include <stdio.h>
//necesario para system("cls")
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "myLib.h"


//MAIN principal
int main()
{
	
	FILE *pf1;
	FILE *pf2;
	FILE *pf3;
	FILE *pf4;
	FILE *pf5;


int i=0;

system("COLOR 3F");
//asignamos componente a las estructuras
//alumno esta asociado a la estructura usuario
usuario alumno;

contenido fichero; 

opciones menu;

clase etsidi;


/*el usuario debera dar su nombre,apellidos, nº de matricula y carrera 
(estos corresponden a los siguientes enteros y strings definidos)*/

/*bucle do while para que se repite siempre el menu hasta
 que el usuario decida lo contrario o pase al segundo menu(tras iniciar sesion)*/
do{
/* system("cls") sirve para limpiar de la ventana lo que estaba escrito anteriormente para tener un 
	programa mas legible*/
system("cls");
//Este seria el menu inicial
printf("(1)Nuevo usuario\n(2)Iniciar sesion\n(3)En que consiste\n(4)Exit\n");
scanf("%i",&menu.opcion);

switch(menu.opcion)
{
		case 1:
	{
	/* system("cls") sirve para limpiar de la ventana lo que estaba escrito anteriormente para tener un 
	programa mas legible*/
	system("cls");
	menu.opcion=verificamatricula(alumno,fichero,menu,&alumno.matricula,pf3);
	
	/*Al haber cambiado en el "if",dentro de la funcion verificamatricula, menu.opcion=2 esta sentencia condicional "if" solo sera recorrida
	 si la matricula no existe,descartando asi que se introduzca ningun otro dato y mandando 
	 al usuario al menu principal directamente*/
	if(menu.opcion==1)
	{
	pf3 = fopen("matriculas.txt", "a");
		fprintf(pf3, "%i,",alumno.matricula);
			fclose(pf3);
	
	//En esta función se guardan el nombre e apellido en un fichero y se cuenta la longitud de estas para meterlas en otro fichero
	guarda_nomb_apelli(alumno,pf1,pf2);

	//Aqui se realiza la seleccion de la carrera por parte del usuario y sera guardado en un fichero
	seleccioncarrera(alumno,pf4);
}
	}
	break;	
		case 2:
	{
	system("cls");
	/*Si ya se ha creado un usuario anteriormente basta con poner el numero de matricula para asociar
	 el conjunto de datos de un un usuario a su matricula*/

	/*Si la matricula no esta registrada el programa vuelve a enviar al usuario al menu principal,
	si esta registrada se mantiene en el case 2 y abrirá otro switch-case*/
	
	/*posicion nos dará la posición de la matricula dentro del vector matricula (y la posicion del nº asociado a la carrera)
	matri es la matricula que va a escribir el usuario para comparar con las matrículas ya registradas*/
	int posicion;
	
	menu.opcion=matriculaexistente(alumno,fichero,menu,&posicion,pf3);

	//if descrito en la funcion anterior que solo se cumple cuando la matrícula esta registrada
	if(menu.opcion==2)
	{
	
	
	do{
	system("cls");
	printf("(1)Ver mi ficha\n(2)Donde hay clase\n(3)Tutorias con mis profes\n(4)Saber dia y hora\n(5)Volver al menu principal\n");
	scanf("%i",&menu.segundaopcion);
	
		switch (menu.segundaopcion)
		{
			case 1:
				{
					system("cls");
		
		
		imprimir_datos_usuario(fichero,posicion,pf1,pf2,pf4);
		
				}
				break;
			case 2:
				{
				
					system("cls");
				
			do{	
			system("cls");
			printf("(1)Clase ahora\n(2)Clase mas tarde\n(3)Menu anterior\n");
				scanf("%i",&menu.opcionhorarios);
					
					switch (menu.opcionhorarios)
					{
						case 1:
							{
							
								system("cls");
							printf("El programa muestra donde tiene clase el alumno \nen ese instante en un mapa");
							getch();
						}
							break;
						case 2:
						{	system("cls");
							printf("El programa muestra donde tiene clase el alumno \ndespues de la clase que tiene en ese instante en un mapa");
							getch();
						}
							break;
						case 3:
							{
								system("cls");
								printf("Estas volviendo al menu anterior");
								sleep(2);
							}
							break;
						default:
							{
							system("cls");
							printf("no existe esta opcion");
							sleep(2);
						}
							break;
					}
				}while(menu.opcionhorarios!=3);
					}
				
				
				break;
			case 3:
				{
					system("cls");
					tutoria(etsidi,pf5);
					getch();
				}
				break;
			case 4:
				{
					system("cls");
					
		//funciona como reloj que nos da la hora local

		/* funcion time que recibe como parametro un puntero nulo
		 --> devuelve el tiempo en una variable de tipo time_t*/
 		 time_t t=time(0);
  		/*funcion localtime recime como parametro un puntero 
  		t de variable time_t --> devuelve un puntero (horalocal) hacia la estructura de tipo tm*/
  		struct tm *local=localtime(&t);
  		//definimos una cadena de caracteres dodne se va a almacenar la informacion final
  		char hora[10];
 		 char dia[10];
  
  		/*funcion strftime con 1º parametro la cadena definida,2º su longitud,
  		3º cadena de formateo implementada con #include <time.h>  
	  	y 4º el puntero que señala la estructura que contiene el tiempo que queremos formatear*/
	  strftime(hora, 99, "%H:%M:%S",local );
		  strftime(dia,9,"%A",local);
 		 //finalmente imprimimos la cadena de caracteres hora
  		printf ("\nHora: %s\n\nDia: %s\n", hora,dia);
		//asociamos a la carrera del alumno su horario para poder mostrarle sus clases		
		getch();
				}
			break;
			case 5:
				{
					system("cls");
					printf("Estas volviendo al menu anterior");
					sleep(2);
				}
				break;
			default:
				{
				system("cls");
				printf("no existe esta opcion");
				sleep(2);
			}
				break;
					}
				
	}while(menu.segundaopcion!=5);
}

	
	}
	break;
		case 3:
	{
	system("cls");
	//aqui el programa presenta un poco en que consiste dicho programa
	printf("Bienvenido al programa ETSIDI Maps, este programa te permitira\nen un primer lugar crear un usuario, e iniciar sesion en ocasiones\nposteriores. Tendras asi acceso a tus datos y, depiendo  de tu carrera,\na la localizacion de tus futuras clases o los despachos de tus profesores.\n");
	//sleep usado para que el mensaje siguiente se vea mas estetico al aparecer mas tarde
	sleep(2);
	printf ("\n\t\t\tPress any key to go back to menu\n");
	//espera a que una tecla sea pulsada para salir del case
	getch();
	}
	break;
		case 4:
		/*no hay nada en este case, solo que es necesario que sea definida para
		 que el programa no la detecte como una opcion inexistente, os va a servir para finalizar el programa*/
	break;
		default:
	printf("Esa opcion no existe\n");
	sleep(2);
	break;
}
//el programa continua hasta que la tecla pulsada sea el 4(EXIT)
}while((menu.opcion!=4));



return 0;
}
