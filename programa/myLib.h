
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

typedef struct
{
	char tutorias[1000];
}clase;

//funcion para comprobar si el usuario habia creado una cuenta anteriormente
int verificamatricula(usuario a,contenido f,opciones m,int *h, FILE *pf);


//funcion para guardar el nombre e apellido del usuario en un fichero,y para  hacer la suma de las longitudes de nombre e apellido
int guarda_nomb_apelli(usuario a,FILE *pf1,FILE *pf2);

//función para guardar la carrera del usuario en un fichero
int seleccioncarrera(usuario a,FILE *pf);

/*función para comprobar si la matricula introducida habia sido ya creada, y al mismo tiempo 
si existe dicha matricula asociar a esta el nombre, apellido, carrera del usuario correspondiente*/
int matriculaexistente(usuario a,contenido f,opciones m,int *x, FILE *pf);

//función que va a imprimir en pantalla las informaciones del usuario tal como su nombre e apellido y su carrera en la universidad
int imprimir_datos_usuario(contenido f,int posicion,FILE *pf1,FILE *pf2,FILE *pf3);

int tutoria(clase a,FILE *pf);
