#include <stdio.h>
//MAIN principal
int main()
{
	//opcion corresponde a la opcion del menu que va a elegir el usuario una vez abierto el programa
	int opcion;
/*bucle do while para que se repite siempre el menu hasta
 que el usuario decida lo contrario o pase al segundo menu(tras iniciar sesion)*/
do{
system("cls");
//Este seria el menu inicial
printf("(1)Nuevo usuario\n(2)Iniciar sesion\n(3)En que consiste\n(4)Exit\n");
scanf("%i",&opcion);
switch(opcion)
{
		case 1:
	{
		
	/* system("cls") sirve para limpiar de la ventana lo que estaba escrito anteriormente para tener un 
	programa mas legible*/
	system("cls");
	
	printf("Le pide al usuario el nombre apellidos matricula y carrera");
	getch();
	}
	break;	
		case 2:
	{
	system("cls");
	int segundaopcion;
	
	do{
	system("cls");
	printf("(1)Ver mi ficha\n(2)Donde hay clase\n(3)Tutorias con mis profes\n(4)Volver al menu principal\n");
	scanf("%i",&segundaopcion);
	
		switch (segundaopcion)
		{
			case 1:
				{
					system("cls");
					printf("Muestra la ficha del alumno asociada a su matricula (nombre,apellidos,carrera)");
					getch();
				}
				break;
			case 2:
				{
				
					system("cls");
				int opcionhorarios;
			do{	
			system("cls");
			printf("(1)Clase ahora\n(2)Clase mas tarde\n(3)Menu anterior\n");
				scanf("%i",&opcionhorarios);
					
					switch (opcionhorarios)
					{
						case 1:
							{
							
								system("cls");
							printf("El programa muestra donde tiene clase en ese momento el alumno en un mapa");
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
								printf("Permite volver al menu anterior");
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
				}while(opcionhorarios!=3);
					}
				
				
				break;
			case 3:
				{
					system("cls");
					printf("Muestra los profesores y donde estan sus salas personales( los horarios tambien se pueden implementar),\ntambien se intentara mostrar en un mapa donde se encuentra dicha sala");
					getch();
				}
				break;
			case 4:
				{
					system("cls");
					printf("Permite volver al menu anterior");
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
				
	}while(segundaopcion!=4);
}
	break;
		case 3:
	{
	system("cls");
	printf("aqui el programa presenta un poco en que consiste dicho programa");
	sleep(2);
	printf ("\n\n\t\t\tPress any key to go back to menu\n");
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
}while((opcion!=4));

return 0;
}
