#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct //estructura de nuevo usuario
{
	//el usuario debera dar su nombre,apellidos, nº de matricula y carrera
	char nombre[30];
	char apellidos[50];
	int matricula;
	int carrera;
}usuario;

//funcion para comprobar si el usuario habia creado una cuenta anteriormente
int matricula(usuario c,int a);

char carrera(usuario c);

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
//alumno esta asociado a la estructura usuario
usuario alumno;
switch(opcion)
{
		case 1:
	{
		
	/* system("cls") sirve para limpiar de la ventana lo que estaba escrito anteriormente para tener un 
	programa mas legible*/
	system("cls");
	//asociamos con la estructura de nuevo usuario su nombre, apellidos, matricula, y carrera cursada
	
	printf("Nombre:");
	scanf(" %29s", alumno.nombre);
	printf("Apellidos:");
	scanf("%49s", alumno.apellidos);
	printf("Numero de matricula:");
	scanf("%i", &alumno.matricula);

	//selecion de la carrera cursada en la universidad(primer año solo)
	do{	
	system("cls");
	printf("Por ultimo, cual es tu carrera?\n\n\t\t(1)Electrica\t(2)Mecanica\t(3)Quimica Industrial\n\t\t(4)Diseno industrial y desarollo de producto\t(5)Electronica\n");
	scanf("%i",&alumno.carrera);
	//bucle do while para que el usuario seleccione una de las opciones permitidas como carrera 
}while((alumno.carrera!=1)&&(alumno.carrera!=2)&&(alumno.carrera!=3)&&(alumno.carrera!=4)&&(alumno.carrera!=5));
	}
	break;	
		case 2:
	{
	system("cls");
	/*Si ya se ha creado un usuario anteriormente basta con poner el numero de matricula para asociar
	 el conjunto de datos de un unsuario a su matricula*/

	//Si la matricula no esta registrada el programa vuelve a enviar al usuario al menu princpal,sino se sale del do while con la informacion que tiene
	opcion= matricula(alumno,opcion);
	
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
}while((opcion!=4)&&(opcion!=2));



//funciona como reloj que nos da la hora local

/* funcion time que recibe como parametro un puntero nulo
 --> devuelve el tiempo en una variable de tipo time_t*/
  time_t t=time(0);
  /*funcion localtime recime como parametro un puntero 
  t de variable time_t --> devuelve un puntero (horalocal) hacia la estructura de tipo tm*/
  struct tm *horalocal=localtime(&t);
  //definimos una cadena de caracteres dodne se va a almacenar la informacion final
  char hora[100];
  
  /*funcion strftime con 1º parametro la cadena definida,2º su longitud,
  3º cadena de formateo implementada con #include <time.h>  
  y 4º el puntero que señala la estructura que contiene el tiempo que queremos formatear*/
  strftime(hora, 99, "%H:%M:%S",horalocal );
  //finalmente imprimimos la cadena de caracteres hora
  printf ("Son las: %s\n", hora);
}
//asociamos a la carrera del alumno su horario para poder mostrarle sus clases
	
		switch(alumno.carrera)
{
	
	case 1:
		
		
		qwert[]={"Electrica"};
		break;
	case 2:
		printf("mecanica");
		break;
	case 3:
		printf("quimica");
		break;
	case 4:
		printf("diseño ind");
		break;
	case 5:
		printf("electronica");
		break;
	default:
		printf("ESTE DEFAULT ES IMPOSIBLE");
		break;
}

return 0;
}

int matricula(usuario c,int a) //al entrar en esta funcion a=2 que es el la opcion 2(case 2)
{ 	
	int matri;
printf("Introduce tu numero de matricula");
	scanf("%i",&matri);
	if(c.matricula!=matri)
	{
		/*si la matricula de la estructura no concuerda con la que matricula que pone el 
		usuario quiere decir que no se han creado aun los datos correspondientes a esa matricula*/
		printf("\n\t\tNo existe registro con esa matricula");
	//en ese caso cambiamos a(que corresponde a opcion) por 1 para que aun no se salga de el bucle do while
	a=1;
	}
	//para que al usuario le de tiempo a leer el mensaje
	sleep(3);
	
	return a;
}


	

