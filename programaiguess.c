#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




typedef struct //estructura de nuevo usuario
{
	//el usuario debera dar su nombre,apellidos, nº de matricula y carrera
	char nombre[30];
	char apellido[50];
	int matricula;
	int carrera;
	//longitud del nombre y apellido introducido por el usuario
	int longiapellido,longinombre;
	/*sumalongi corresponde a la suma de las longitudes del nombre y el apellido introducidos 
	por el usuario (añadiendole 1 más correspondiente al espacio entre nombre e apellido)*/
	int sumalongi;
}usuario;

typedef struct //estructura que va a servir para escanear el contenido de los ficheros
{
	//cadena de caracteres de nombres y apellidos --> registro[400]
	char registro[400];
	//vector de los números de matricula --> matricula[100]
	int matricula[100];
	//vector de las carreras de cada alumno --> carrera[100]
	int carrera[100];
	//vector de las longitudes del nombre y apellido de cada alumno registrado --> longiregistro[100]
	int longiregistro[100];	
}contenido;

typedef struct //estructura de las diferentes opciones de menu del programa 
{
	//opcion corresponde a la opcion del menu que va a elegir el usuario una vez abierto el programa
	int opcion;
	//Nos encontramos en el segundo menu, donde las opciones son determinadas por el entero segundaopcion
	int segundaopcion;
	//tercer menu posible donde se dan los diferentes tipos de opciones que hacer en relacion con tus profesores e horarios
	int opcionhorarios;
}opciones;


//funcion para comprobar si el usuario habia creado una cuenta anteriormente
int verificamatricula(usuario a,contenido b,opciones c);

//funcion para hacer la suma de las longitudes de nombre e apellido
int sumalongi(usuario a);


//MAIN principal
int main()
{
	
	FILE *pf1;
	FILE *pf2;
	FILE *pf3;
	FILE *pf4;


int i=0,w=0;

//asignamos componente a las estructuras
usuario alumno;
contenido fichero; 
opciones menu;



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
//alumno esta asociado a la estructura usuario

switch(menu.opcion)
{
		case 1:
	{
		
	/* system("cls") sirve para limpiar de la ventana lo que estaba escrito anteriormente para tener un 
	programa mas legible*/
	system("cls");
	pf3 = fopen("C:/Users/Diego/Desktop/trabajo/matriculas.txt", "r");
if (pf3 == NULL)
{// Si el resultado es NULL mensaje de error
printf("Error al abrir el fichero.\n");
return -1;
}
else
{// Si ha funcionado, comienza escritura
//asociamos al usuario su nombre, apellidos, matricula, y carrera cursada
printf("Numero de matricula:");
scanf("%i",&alumno.matricula);
//recorre el vector matricula[100]
for(w;w<100;w++)
{
	

fscanf(pf3,"%i,",&fichero.matricula[w]);
	/*Si dentro del vector recorrido el programa encuentra una matricula igual 
		a la que se desea registrar entonces el programa imprime que el registro ya existe*/
if (fichero.matricula[w]==alumno.matricula){
			printf("Ya existe registro con esta matricula");
			sleep(2);
			//Al entrar en el case 1 opcion es igual a 1,cambiamos dentro del "if" que opcion sea igual a 2
			menu.opcion=2;
			
		}
	}
	fclose(pf3); // Cerramos fichero

}
	/*Al haber cambiado en el "if" anterior opcion=2 esta sentencia condicional "if" solo sera recorrida
	 si la matricula no existe,descartando asi que se introduzca ningun otro dato y mandando 
	 al usuario al menu principal directamente*/
	if(menu.opcion==1)
	{
	pf3 = fopen("C:/Users/Diego/Desktop/trabajo/matriculas.txt", "a");
		fprintf(pf3, "%i,",alumno.matricula);
			fclose(pf3);
	
	pf1 = fopen("C:/Users/Diego/Desktop/trabajo/nombre.txt", "a");
	printf("Nombre:");
	scanf("%29s",alumno.nombre);
		if (pf1 == NULL)
		{// Si el resultado es NULL mensaje de error
		printf("Error al abrir el fichero.\n");
		return -1;
		}
		else
		{fprintf(pf1, "%s\t",alumno.nombre);
			fclose(pf1);
		}
		
	pf1 = fopen("C:/Users/Diego/Desktop/trabajo/nombre.txt", "a");
	printf("Apellidos:");
	scanf("%49s",alumno.apellido);
		if (pf1 == NULL)
		{// Si el resultado es NULL mensaje de error
		printf("Error al abrir el fichero.\n");
		return -1;
		}
		else
		{fprintf(pf1, "%s,",alumno.apellido);
			fclose(pf1);
		}
	

	//selección de la carrera cursada en la universidad(primer año solo)
	do{	
	system("cls");
	printf("Por ultimo, cual es tu carrera?\n\n\t\t(1)Electrica\t(2)Mecanica\t(3)Quimica Industrial\n\t\t(4)Diseno industrial y desarollo de producto\t(5)Electronica\n");
	scanf("%i",&alumno.carrera);
	/*bucle do while para que el usuario seleccione una de las opciones permitidas como carrera 
	(se queda pillado si se elige otra cosa que un entero)*/
}while((alumno.carrera!=1)&&(alumno.carrera!=2)&&(alumno.carrera!=3)&&(alumno.carrera!=4)&&(alumno.carrera!=5));

pf4 = fopen("C:/Users/Diego/Desktop/trabajo/carreras.txt", "a");
		fprintf(pf4, "%i,",alumno.carrera);
			fclose(pf4);


alumno.sumalongi=sumalongi(alumno);

pf2 = fopen("C:/Users/Diego/Desktop/trabajo/longitudstrings.txt", "a");
		fprintf(pf2, "%i,",alumno.sumalongi);
			fclose(pf2);

}
	}
	break;	
		case 2:
	{
	system("cls");
	/*Si ya se ha creado un usuario anteriormente basta con poner el numero de matricula para asociar
	 el conjunto de datos de un unsuario a su matricula*/

	/*Si la matricula no esta registrada el programa vuelve a enviar al usuario al menu principal,
	si esta registrada se mantiene en el case 2 y abrirá otro switch-case*/
	
	/*posicion nos dará la posicion de la matricula dentro del vector matricula (y la posicion del nº asociado a la carrera)
	matri es la matricula que va a escribir el usuario para comparar con las matrículas ya registradas*/
		int j=0,n=0,posicion; 
	
	printf("Introduce tu numero de matricula");
	scanf("%i",&alumno.matricula);
	
		pf3 = fopen("C:/Users/Diego/Desktop/trabajo/matriculas.txt", "r");
if (pf3 == NULL)
{// Si el resultado es NULL mensaje de error
printf("Error al abrir el fichero.\n");
return -1;
}
else
{
	for(j;j<100;j++)
	{
		fscanf(pf3,"%i,",&fichero.matricula[j]);
		
	if(fichero.matricula[j]!=alumno.matricula)
	{
		/*añadimos un n el cual se suma 1 a si mismo cada vez que la matricula de inicio de sesion
		 no concuerda con ninguna  matricula registrada y guardada en el vector matricula*/
		n++;
	}
	/*Este else solo puede repetirse una vez máximo por que no hay dos matriculas iguales,
	entonces la matricula correpondiente se haya en esta posición j y podremos determinar toda
	 la demas información del usuario gracias a esta posición*/
	else posicion=j;
		
}
	if(n==100)
	{
			/*si la matricula no ha sido registrada el entero n sera igual a 100 porque en ningun momento 
			se habra dado el caso del else posicion=j,n es 100 porque el vector matricula tiene dimension 100*/
		printf("\n\t\tNo existe registro con esa matricula");

	//En ese caso cambiamos opcion por 1 para que se salga de nuevo al menu principal sin pasar por el if de la linea 122
	menu.opcion=1;
	//Simplemente para que al usuario le de tiempo a leer el mensaje
	sleep(3);
}
	fclose(pf3);
	}
	//if descrito anteriormente que solo se cumple cuando la matrícula esta registrada
	if(menu.opcion==2)
	{
	
	
	do{
	system("cls");
	printf("(1)Ver mi ficha\n(2)Donde hay clase\n(3)Tutorias con mis profes\n(4)Volver al menu principal\n");
	scanf("%i",&menu.segundaopcion);
	
		switch (menu.segundaopcion)
		{
			case 1:
				{
					system("cls");
		
			int suma1=0,suma2=0;
			//usamos h para los siguientes for porque al haber utilizado el i antes el programa puede confundirse y hacerse un lio
			int h;
			pf2 = fopen("C:/Users/Diego/Desktop/trabajo/longitudstrings.txt", "r");
			
			
			for(h=0;h<(posicion);h++)
			{	
			fscanf(pf2,"%i,",&fichero.longiregistro[h]);
			/*suma1 es la suma de las longitudes de las cadenas 
			de caracteres de nombre y apellido hasta la del usuario NO INCLUIDO (nos va a servir para cortar 
			los nombres anteriores de manera que el programa solo imprima a partir de el nombre del usuario)*/
				suma1=suma1+fichero.longiregistro[h];
				
			}
		
			fscanf(pf2,"%i,",&fichero.longiregistro[posicion]);
			/*suma2 es la suma de las longitudes de las cadenas 
			de caracteres de nombre y apellido hasta la del usuario INCLUIDO (nos va a servir para cortar 
			los nombres posteriores de manera que el programa deje de imprimir tras el nombre del usuario)*/	
			suma2=suma1+fichero.longiregistro[posicion];
			
			fclose(pf2);
	
			pf1 = fopen("C:/Users/Diego/Desktop/trabajo/nombre.txt", "r");
				//Aqui es donde imprimimos uno por uno los caracteres del intervalo descrito anteriormente para el nombre del usuario
			if (pf1 == NULL)
	{// Si el resultado es NULL mensaje de error
	printf("Error al abrir el fichero.\n");
	return -1;
	}
	else
	{
				for(h=0;h<suma2;h++)
			{
					fscanf(pf1,"%c,",&fichero.registro[h]);
					if(h>=suma1&&h<suma2)
				printf("%c",fichero.registro[h]);
			}}
				fclose(pf1);
			//Aqui es donde imprimimos uno por uno los caracteres del intervalo descrito anteriormente para el apellido del usuario	
				printf("\n");
				
				

		pf4 = fopen("C:/Users/Diego/Desktop/trabajo/carreras.txt", "r");
		//Debemos crear un bucle for que empiece desde 0 para que asigne a cada valor su posicion real en el fscanf 
		for(h=0;h<100;h++){
				fscanf(pf4, "%i,",&fichero.carrera[h]);	
			}
					/*teniendo la posicion de la matricula elegida dentro del vector matricula,
					obtenemos al mismo tiempo la posicion de la carrera elegida por dicho usuario en el vector carrera*/
					switch(fichero.carrera[posicion])
					{
					case 1: printf("Electrica");
						break;
					case 2: printf("Mecanica");
						break;
					case 3: printf("Quimica Industrial");
						break;
					case 4: printf("Diseño industrial y desarollo de producto");
						break;
					case 5: printf("Electronica");               
						break;
					default: printf("NO ES POSIBLE");//No es posible llegar a este default
						break;
					}
							fclose(pf4);
					getch();
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
				}while(menu.opcionhorarios!=3);
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
				
	}while(menu.segundaopcion!=4);
}

	
	}
	break;
		case 3:
	{
	system("cls");
	//aqui el programa presenta un poco en que consiste dicho programa
	printf("TEXTACO DE EXPLICACION\n");
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
  printf ("Son las: %s\ndia %s\n", hora,dia);
//asociamos a la carrera del alumno su horario para poder mostrarle sus clases

return 0;
}

int sumalongi(usuario a){

/*calcula la longitud de el apellido dentro de la cadena alumno.apellido y ese valor de 
longitud lo sumara al del nombre para luego meterlo en el fichero "longitudstrings"*/
a.longiapellido=strlen(a.nombre);
/*calcula la longitud de el nombre dentro de la cadena alumno.nombre y ese valor de 
longitud lo sumara al del apellido para luego meterlo en el fichero "longitudstrings"*/
a.longinombre=strlen(a.apellido);

return (a.longinombre+a.longiapellido+1);//el +1 es contandole un espacio entre el nombre y el apellido
}
