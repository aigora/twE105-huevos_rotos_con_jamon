#include <stdio.h>
#include <string.h>
#include "myLib.h"

int verificamatricula(usuario a,contenido f,opciones m,int *h, FILE *pf){
int w=0;
		pf = fopen("C:/Users/Diego/Desktop/trabajo/matriculas.txt", "r");
if (pf == NULL)
{// Si el resultado es NULL mensaje de error
printf("Error al abrir el fichero.\n");
return -1;
}
else
{// Si ha funcionado, comienza escritura
//asociamos al usuario su nombre, apellidos, matricula, y carrera cursada
printf("Numero de matricula:");
scanf("%i",&a.matricula);
//recorre el vector matricula[100]
for(w;w<100;w++)
{
	

fscanf(pf,"%i,",&f.matricula[w]);
	/*Si dentro del vector recorrido el programa encuentra una matricula igual 
		a la que se desea registrar entonces el programa imprime que el registro ya existe*/
if (f.matricula[w]==a.matricula){
			printf("Ya existe registro con esta matricula");
			sleep(2);
			//Al entrar en el case 1 opcion es igual a 1,cambiamos dentro del "if" que opcion sea igual a 2
			m.opcion=2;
			
		}
	}
	fclose(pf); // Cerramos fichero	
}
*h=a.matricula;
return m.opcion;
}


int guarda_nomb_apelli(usuario a,FILE *pf1,FILE *pf2)
{
		pf1 = fopen("C:/Users/Diego/Desktop/trabajo/nombre.txt", "a");
	printf("Nombre:");
	scanf("%29s",a.nombre);
		if (pf1 == NULL)
		{// Si el resultado es NULL mensaje de error
		printf("Error al abrir el fichero.\n");
		return -1;
		}
		else
		{fprintf(pf1, "%s\t",a.nombre);
			fclose(pf1);
		}
		
	pf1 = fopen("C:/Users/Diego/Desktop/trabajo/nombre.txt", "a");
	printf("Apellidos:");
	scanf("%49s",a.apellido);
		if (pf1 == NULL)
		{// Si el resultado es NULL mensaje de error
		printf("Error al abrir el fichero.\n");
		return -1;
		}
		else
		{fprintf(pf1, "%s,",a.apellido);
			fclose(pf1);
		}
	
/*calcula la longitud de el apellido dentro de la cadena alumno.apellido y ese valor de 
longitud lo sumara al del nombre para luego meterlo en el fichero "longitudstrings"*/
a.longiapellido=strlen(a.nombre);
/*calcula la longitud de el nombre dentro de la cadena alumno.nombre y ese valor de 
longitud lo sumara al del apellido para luego meterlo en el fichero "longitudstrings"*/
a.longinombre=strlen(a.apellido);

a.sumalongi=(a.longinombre+a.longiapellido+1);//el +1 es contandole un espacio entre el nombre y el apellido

pf2 = fopen("C:/Users/Diego/Desktop/trabajo/longitudstrings.txt", "a");
		fprintf(pf2, "%i,",a.sumalongi);
			fclose(pf2);

}


	
int seleccioncarrera(usuario a,FILE *pf){

	//selección de la carrera cursada en la universidad(primer año solo)
	do{	
	system("cls");
	printf("Por ultimo, cual es tu carrera?\n\n\t\t(1)Electrica\t(2)Mecanica\t(3)Quimica Industrial\n\t\t(4)Diseno industrial y desarollo de producto\t(5)Electronica\n");
	scanf("%i",&a.carrera);
	/*bucle do while para que el usuario seleccione una de las opciones permitidas como carrera 
	(se queda pillado si se elige otra cosa que un entero)*/
}while((a.carrera!=1)&&(a.carrera!=2)&&(a.carrera!=3)&&(a.carrera!=4)&&(a.carrera!=5));

pf = fopen("C:/Users/Diego/Desktop/trabajo/carreras.txt", "a");
		fprintf(pf, "%i,",a.carrera);
			fclose(pf);
}

	
int	matriculaexistente(usuario a,contenido f,opciones m,int *x,FILE *pf){

	/*volvemos a poner posicion dentro de la función para que se entienda mejor*/
		int j=0,n=0,posicion; 
	
	printf("Introduce tu numero de matricula");
	scanf("%i",&a.matricula);
	
		pf = fopen("C:/Users/Diego/Desktop/trabajo/matriculas.txt", "r");
if (pf == NULL)
{// Si el resultado es NULL mensaje de error
printf("Error al abrir el fichero.\n");
return -1;
}
else
{
	for(j;j<100;j++)
	{
		fscanf(pf,"%i,",&f.matricula[j]);
		
	if(f.matricula[j]!=a.matricula)
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
	m.opcion=1;
	//Simplemente para que al usuario le de tiempo a leer el mensaje
	sleep(3);
		}
	fclose(pf);
}
*x=posicion;
return m.opcion;
}

int imprimir_datos_usuario(contenido f,int posicion,FILE *pf1,FILE *pf2,FILE *pf3){
	
	int suma1=0,suma2=0;
			//usamos h para los siguientes "for"
			int h;
			pf2 = fopen("C:/Users/Diego/Desktop/trabajo/longitudstrings.txt", "r");
			
			
			for(h=0;h<(posicion);h++)
			{	
			fscanf(pf2,"%i,",&f.longiregistro[h]);
			/*suma1 es la suma de las longitudes de las cadenas 
			de caracteres de nombre y apellido hasta la del usuario NO INCLUIDO (nos va a servir para cortar 
			los nombres anteriores de manera que el programa solo imprima a partir de el nombre del usuario)*/
				suma1=suma1+f.longiregistro[h];
				
			}
		
			fscanf(pf2,"%i,",&f.longiregistro[posicion]);
			/*suma2 es la suma de las longitudes de las cadenas 
			de caracteres de nombre y apellido hasta la del usuario INCLUIDO (nos va a servir para cortar 
			los nombres posteriores de manera que el programa deje de imprimir tras el nombre del usuario)*/	
			suma2=suma1+f.longiregistro[posicion];
			
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
					fscanf(pf1,"%c,",&f.registro[h]);
					if(h>=suma1&&h<suma2)
				printf("%c",f.registro[h]);
			}}
				fclose(pf1);
			//Aqui es donde imprimimos uno por uno los caracteres del intervalo descrito anteriormente para el apellido del usuario	
				printf("\n");
				
				
		//Aqui pf3 corresponde realmente a la direccion de puntero pf4 en el programa principal
		pf3 = fopen("C:/Users/Diego/Desktop/trabajo/carreras.txt", "r");
		//Debemos crear un bucle for que empiece desde 0 para que asigne a cada valor su posicion real en el fscanf 
		for(h=0;h<100;h++){
				fscanf(pf3, "%i,",&f.carrera[h]);	
			}
					/*teniendo la posicion de la matricula elegida dentro del vector matricula,
					obtenemos al mismo tiempo la posicion de la carrera elegida por dicho usuario en el vector carrera*/
					switch(f.carrera[posicion])
					{
					case 1: printf("Electrica");
						break;
					case 2: printf("Mecanica");
						break;
					case 3: printf("Quimica Industrial");
						break;
					case 4: printf("Disenho industrial y desarrollo de producto");
						break;
					case 5: printf("Electronica");               
						break;
					default: printf("NO ES POSIBLE");//No es posible llegar a este default
						break;
					}
							fclose(pf3);
					getch();
}
