#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <stdio.h>
#include <ctype.h>


using namespace std;



/////////////////////////////////////////////////////
struct destino{
	string nombre;
	int poblacion;
	int ID;
	struct destino * sig;
	struct destino * ant;
	
	struct DestinoObtenerInformacionPrograma * destinoPrimeroSubListaRelacionPrograma;
	
	destino(string nom,int pobla,int id){
	nombre=nom;
	poblacion=pobla;
	sig=NULL;
	ant=NULL;
	ID=id;
	destinoPrimeroSubListaRelacionPrograma=NULL;
	}
}*primeroDestino;

struct DestinoObtenerInformacionPrograma{
	struct DestinoObtenerInformacionPrograma * sig;
	struct programa * destinoEnlacePrograma;
	DestinoObtenerInformacionPrograma(){
	sig=NULL;
	destinoEnlacePrograma=NULL;
	}
};


//////////////////////////////////////////




struct oferta{
	string nombre;
	int ID;
	int tiempoValida;
	string ventajas;
	
	struct oferta * sig;
	
	struct ofertaObtenerInformacionPrograma	* ofertaPrimeroSubListaRelacionPrograma;
	
	
	oferta(string nombr,int identifica,int tiempoVal,string ventaja){
	nombre=nombr;
	ID=identifica;
	tiempoValida=tiempoVal;
	ventajas=ventaja;
	sig=NULL;
	ofertaPrimeroSubListaRelacionPrograma=NULL;	
	}
}*listaPrincipalOfertas;

struct ofertaObtenerInformacionPrograma{
	int cupo;
	struct ofertaObtenerInformacionPrograma * sig;
	struct programa * ofertaEnlacePrograma;
	ofertaObtenerInformacionPrograma(int cup){
	cupo=cup;
	ofertaEnlacePrograma=NULL;
	sig=NULL;
	}
};



/////////////////////////////////////////


struct programa{
	int precio;
	string nombre;
	int IDDestino;
	int IDPrograma;
	
	struct programa * sig;
	
	struct programaObtenerInformacionDestino * programaPrimeroSubListaRelacionDestino;
	
	programa(string nombr,int preci,int idProgra,int idDesti){
	precio=preci;
	nombre=nombr;
	IDDestino=idDesti;
	IDPrograma=idProgra;
	sig=NULL;
	programaPrimeroSubListaRelacionDestino=NULL;
	
	}
}*listaPrincipalProgramas;

struct programaObtenerInformacionDestino{
	struct programaObtenerInformacionDestino * sig;
	struct destino * programaEnlaceDestino;
	
	programaObtenerInformacionDestino(){
	sig=NULL;
	programaEnlaceDestino=NULL;
	}
	
};

///////////////////////////////////////////////

struct circuito{
	
	int cantidadDias;
	string nombre;
	int IDCircuito;
	
	struct circuitoObtenerInformacionDestinos * circuitoSubListaPrimeroDestinos;
	struct circuitoObtenerInformacionProgramas * circuitoSubListaPrimeroProgramas;
	
	struct circuito * sig;
	
	circuito(int cantDias,string nombr,int identifi){
	cantidadDias=cantDias;
	nombre=nombr;
	IDCircuito=identifi;
	sig=NULL;
	circuitoSubListaPrimeroDestinos=NULL;
	
	}
}*listaPrincipalCircuitos;


struct circuitoObtenerInformacionDestinos{
	struct circuitoObtenerInformacionDestinos * sig;
	struct destino * CircuitoEnlaceDestino;
	
	circuitoObtenerInformacionDestinos(){
	sig=NULL;
	CircuitoEnlaceDestino=NULL;
	}
};

struct circuitoObtenerInformacionProgramas{
	struct circuitoObtenerInformacionProgramas * sig;
	struct programa * circuitoEnlacePrograma;
	circuitoObtenerInformacionProgramas(){
	circuitoEnlacePrograma=NULL;
	sig=NULL;
	}
};

/////////////////////////////////////////////////////////

struct usuarios{
	string nombre;
	int ID;
	int edad;
	
	struct usuarios *sig;
	struct UsuarioObtenerInformacionPrograma *usuarioSubListaPrimeroPrograma;
	struct comentario *PrimeroComentario;
	struct UsuarioObtenerInformacionCircuito *usuarioSubListaPrimeroCircuito;
	usuarios(string nombr,int identifi,int eda){
	nombre=nombr;
	ID=identifi;
	edad=eda;
	sig=NULL;
	usuarioSubListaPrimeroPrograma=NULL;
	PrimeroComentario=NULL;
	usuarioSubListaPrimeroCircuito=NULL;	
	}
}*primerUsuario;

struct UsuarioObtenerInformacionPrograma{
	struct UsuarioObtenerInformacionPrograma *sig;
	struct programa *usuarioEnlacePrograma;
	UsuarioObtenerInformacionPrograma(){
	sig=NULL;
	usuarioEnlacePrograma=NULL;
	}
};

struct UsuarioObtenerInformacionComentario{
	struct UsuarioObtenerInformacionComentario * sig;
	struct comentario * usuarioEnlaceComentario;
	UsuarioObtenerInformacionComentario(){
	sig=NULL;
	usuarioEnlaceComentario=NULL;
	} 
};

struct UsuarioObtenerInformacionCircuito{
	struct UsuarioObtenerInformacionCircuito * sig;
	struct circuito * usuarioEnlaceCircuito;
	UsuarioObtenerInformacionCircuito(){
	sig=NULL;
	usuarioEnlaceCircuito=NULL;
	}
};

////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
struct comentario{
	int puntuacion;
	string coment;
	string fecha;
	
	struct  comentario *sig;
	struct programa *enlaceProgramaComentario;
	comentario(int puntua, string comen,string fech){  // fecha esta confuso
	puntuacion=puntua;
	coment=comen;
	fecha=fech;
	sig=NULL;
	enlaceProgramaComentario=NULL;
	}
};






///////////////////////////////////////////////
//////////////////////////////////////////////////
/////////////////////////////////////////////

//Prototipos

//menus
void menuMantenimientoDeDatos();
void menu();
void menuConsultas();
void menuReporteResultados();
void menuAgregarDatos();
void menuOfertasDesicionAccion();

//funciones destinos

void insercionDeDestinos(string,int,int);
void datosAgregadosDeDestinos();
void imprimirAdYAtDestinos();
void agregarNuevoDestino();
struct destino *buscarDestino(int);

//funciones ofertas
void pedirDatosIngresoOfertas();
void insertarOfertas(string ,int ,int ,string );
struct oferta * buscarOfertas(int);
void pedirDatosAsignarOfertasAPrograma();
void asignarOfertasAPrograma(int, int,int);
void cargarListasOfertas();
void imprimirListaOfertas();





// funciones programas

void pedirDatosPrograma();
struct programa * buscarProgramas(int);
void insertarProgramas(string,int,int,int);
void imprimirListasProgramas();
void cargarListasProgramas();
void cambiarPrecioDePrograma();

// funciones circuitos


void pedirDatosCircuito();
struct circuito * buscarCircuitos(int);
void enlazarCircuitoProgramaYCircuitoDestino(int,int);	
void pedirMasProgramasDelCircuito(int);
void cargarDatosCircuitos();
void insertarCircuitosParaCargarDatos(int,int,string,int,int);
void imprimirListaCircuitos();
void llenarInformacionNuevoCircuito(int, string, int);


//funciones usuario
void agregarNuevoUsuario();
struct usuarios *buscarUsuario(int);
void usuariosAgrgadosPorDefecto();
void imprimirUsuariosEnLista();
void agregarProgramaUsuario(int,int);
void agregarUnNuevoCircuitoDeUnUsuarioProcesos(int,int);
void agregarUnNuevoCircuitoDeUnUsuario();
void circuitoDeUsuarioAgregadoPorDefecto();
void agregarNuevoProgramaDeUsuario();
void agregarPorDefectoProgramaDeUsuario();


//funciones comentario

void insertarComentario(int,int,string,int,string);
void datosAgregarComentario(); 
void listaDeComentariosPorDefecto();



//funciones consultas
void consultarDestinosVisitadosPorPersona();//revisar
void imprimirComentarioDePrograma();
void circuitosMasEscogidosPorLosUsuarios();
void imprimirCuposDisponiblesDeOfertas();






//funciones de reporteDeResultados

void imprimirListaDeProgramasSegunDestino();
void imprimirDestinosYProgramasDeUnCircuito();


//eliminar

void borraProgramaXDatos();
void borrarProgramaEnProgramas(int);
void borrarProgramaEnCircuitos(int);
void borrarProgramaEnOfertas(int);
void borrarProgramaEnComentario(int);
void borrarProgramaEnUsuarios(int);
void borrarProgramaEnDestinos(int);

//////////////////////////////////////////////


/////////////////////////////////////////////


////////////////////////////////////////

//CODIGO DESTINOS

struct destino *buscarDestino(int id){
	
	/*Fecha de inicio: 22/08/2015
	Fecha última modificación: 22/08/2015.
	Descripción: busca la identificacion que es enviada por parametro en los diferentes destinos
	que se encuentran en la lista de destinos (primeroDestino) y retorna nulo si no lo encuentra 
	o retorna el nodo con la misma identificacion buscada. 
	parametro: recibe la identificacion de un destino al cual se desea buscar.
	*/
	
	if(primeroDestino == NULL){
	return NULL;
	}
	else{
	struct destino *temp= primeroDestino;
	while(temp != NULL){
	if(temp->ID ==id){
	return temp;
	}
	temp= temp->sig;	
	}
	}
	return NULL;
}


void agregarNuevoDestino(){
	
	/*Fecha de inicio: 22/08/2015
	Fecha última modificación: 22/08/2015.
	Descripción: le solicita al usuario que ingrese datos especificos necesarios
	para la creacion de un destino. utiliza el toupper para cambiar la primera 
	letra del nombre digitado por el usuario a una letra mayuscula en caso de ser minuscula 
	una vez terminada la solicitud de datos se envia a otra funcion insercionDeDestinos y 
	se le envia el nombre del destino, la identificacion y la cantidad de poblacion. 
	parametro: ninguno.
	*/
	
	string palabra;
	int id;
	cout<<"\n\n**************************** Agregar Destino ******************************\n\n";
	cout<<"\nDigite el nombre del destino a crear: "<<endl;
	cin>>palabra;
	int i=0;
  	palabra[i]=(toupper(palabra[i]));
  	cout<<endl;
  	cout<<"escriba la identificacion: "<<endl;
  	cin>>id;
	if(palabra==""){
	cout<<"\nERROR esta vacio"<<endl;	
	menuAgregarDatos();
	
	}
	
	struct destino *resultado=buscarDestino(id);  
	if(resultado == NULL ){
	int pobla;
	cout<<"\nDigite la poblacion del destino a crear: \n";
	cin>>pobla;
	insercionDeDestinos(palabra,id,pobla);
	
	}
	else{
	cout<<"ERROR. No se puede insertar "<<palabra<<endl;
	menu();
	}
	cout<<"\nSe ha agragado exitosamente. ";
	imprimirAdYAtDestinos();
	menuAgregarDatos();
}

void insercionDeDestinos(string nombreDelDestino,int id,int pobla){
	
	/*Fecha de inicio: 22/08/2015
	Fecha última modificación: 24/08/2015.
	Descripción:crea un nuevo nodo tipo destino y compara su nombre con el resto de los que se 
	encuentran en la lista acomodando a este en orden alfabetico. 
	parametro: recibe el nombre del destino: nombreDelDestino, la identificacion del destino: id,
	y la cantidad de poblacion: pobla.
	*/
	
	struct destino *nuevoDestino= new destino(nombreDelDestino,pobla,id);
	string nombreDelDestinoRepuesto= nombreDelDestino;
	if(primeroDestino==NULL){
	primeroDestino= nuevoDestino;
	
	}
	else if(primeroDestino->sig == NULL){
	if(primeroDestino->nombre < nombreDelDestino and primeroDestino->nombre != nombreDelDestino){
	primeroDestino->sig = nuevoDestino;
	nuevoDestino->ant= primeroDestino;	
	}
	else if(primeroDestino->nombre > nombreDelDestino and primeroDestino->nombre != nombreDelDestino){
	nuevoDestino->sig= primeroDestino;
	primeroDestino->ant= nuevoDestino;
	primeroDestino= nuevoDestino;	
	}	
	}
	else{
	struct destino *cont= primeroDestino;
	while(cont->sig!= NULL){
	struct destino *conta= cont->sig;
	if(nombreDelDestino < cont->nombre and nombreDelDestino != cont->nombre){
	nuevoDestino->sig= cont;
	cont->ant= nuevoDestino;
	primeroDestino= nuevoDestino;
	break;
	}
	else if(nombreDelDestino> cont->nombre and nombreDelDestino < conta->nombre
	or nombreDelDestino == cont->nombre ){
	cont->sig= nuevoDestino;
	nuevoDestino->ant= cont;
	nuevoDestino->sig= conta;
	conta->ant = nuevoDestino;
	break;
	}
	else if(conta->sig == NULL){
	conta->sig=nuevoDestino;
	nuevoDestino->ant=conta;
	break;	
	}
	cont= cont->sig;
	}
	}
}




void datosAgregadosDeDestinos(){
	
	/*Fecha de inicio: 24/08/2015
	Fecha última modificación: 24/08/2015.
	Descripción:datos por defecto para que se introduzcan el la lista de destinos. 
	parametro: ninguno.
	*/
	
	insercionDeDestinos("America",1,1000);
	insercionDeDestinos("Uruguay",2,2000);
	insercionDeDestinos("Estados unidos",3,3000);
	insercionDeDestinos("Chile",4,40000);
	insercionDeDestinos("Managua",5,500000);
	insercionDeDestinos("Europa",6,6000);
	insercionDeDestinos("Oceania",7,7000);
	insercionDeDestinos("Polonia",8,300000);
	
}

void imprimirAdYAtDestinos(){
	
	/*Fecha de inicio: 24/08/2015
	Fecha última modificación: 24/08/2015.
	Descripción:imprime la informacion basica de los destinos que se encuentran 
	en la lista de destinos. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n****************** Lista de todos los destinos ***************\n\n";
	struct destino *temp= primeroDestino;
	if(primeroDestino== NULL){
	cout<<"\tlista vacia"<<endl;
	menu();
	}
	while(temp->sig!= NULL){
	cout<<"\nNombre: "<<temp->nombre<<endl;
	cout<<"\nIdentificacion: "<<temp->ID<<endl;
	cout<<"\nPoblacion: "<<temp->poblacion<<endl<<endl;
	temp= temp->sig;
	}
	cout<<"\nNombre: "<<temp->nombre<<endl;
	cout<<"\nIdentificacion: "<<temp->ID<<endl;
	cout<<"\nPoblacion: "<<temp->poblacion<<endl<<endl;
	cout<<"\n\n........... fin de todos los destinos .............\n\n";
}
//////////////////////////////////////////////////////


//CODIGO OFERTAS

void pedirDatosIngresoOfertas(){
	//input: datos ingrados por el usuario
	//output: envio de informacion al metodo de ingreso de ofertas, mensaje informativo para el usuario
	//restriction: la variable tempOferta debe ser diferente de NULL, ya que la oferta no debe existir previamente
	//description: la funcion se encarga de pedir todos los datos necesarios para la creacion de un oferta,
	//				si el ID ingresado es el mismo a un ID situado en la lista de ofertas, se evitara el ingreso de la 
	//				misma, sino se enviara la informacion al metodo de ingreso de oferta
	
	string nombreOferta;
	int ID;
	
	int tiempoValido;
	string ventajas;
	cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
	cout<<"Nombre Oferta: ";
	cin>>nombreOferta;
	cout<<"Identificacion: ";
	cin>>ID;
	cout<<"tiempo Valido: ";
	cin>>tiempoValido;
	cout<<"Ventajas: ";
	cin>>ventajas;
	
	
	struct oferta * tempOferta= buscarOfertas(ID);
	
	
	if(tempOferta!=NULL){
		cout<<"\n\nLa oferta ya existe\n";
		menuAgregarDatos();
	}
	else{
	
		insertarOfertas(nombreOferta,ID,tiempoValido,ventajas);
		cout<<"\n\nOferta creada con exito\n\n";
		
		cout<<"\n\n\nPrueba de imprimir";
		imprimirListaOfertas();
		menuAgregarDatos();
	}
}




struct oferta * buscarOfertas(int IDQueBuscar){
	
	//input: ID de la oferta obtenida con anterioridad
	//output: retorno de informacion al temporal del cual fue llamado
	//restriction:
	//description: realiza un recorrido de la lista de ofertas buscando el ID obtenido por parametro, si lo encuentra
	//				retorna la posicion en memoria de su localzacion sino retorna NULL

	
	if(listaPrincipalOfertas==NULL){
		return NULL;
	}
	else{
	
		struct oferta * temp = listaPrincipalOfertas;
	
	
		do{
			if(IDQueBuscar==temp->ID){
				return temp;
			}
			else{
				temp=temp->sig;
			}
		}while(temp!=listaPrincipalOfertas);
	
		return NULL;
	}
}

void insertarOfertas(string nombreOferta,int ID,int tiempoValido,string ventajas){

	//input: datos necesarios para la creacion de la oferta obtenidos con anterioridad
	//output: creacion de la oferta, se realiza un enlace de un nuevo nodo a la lista principal
	//restriction:
	//description: crear un nuevo enlace en memoria y lo enlaza a la lista principal de ofertas 
	//				mediante la utilizacion de punteros

	struct oferta *	nn=new oferta(nombreOferta,ID,tiempoValido,ventajas);
	
	if(listaPrincipalOfertas==NULL){
		listaPrincipalOfertas=nn;
		listaPrincipalOfertas->sig=nn;
	}
	else{
		struct oferta * temp=listaPrincipalOfertas;
	
		while(temp->sig!=listaPrincipalOfertas){
			temp=temp->sig;
			}
		temp->sig=nn;
		nn->sig=listaPrincipalOfertas;
	}
}


void imprimirListaOfertas(){
	//input: 
	//output: impresion en pantalla de la lista de ofertas
	//restriction:
	//description: realiza un recorrido de la lista principal de ofertas, y va imprimiendo la informacion de cada nodo,
	//			conforme avanza el temporal

	struct oferta * temp=listaPrincipalOfertas;
	cout<<"\n\n*****************************Listas de Ofertas*****************************\n\n";
	do{
		cout<<"Nombre: "<<temp->nombre<<endl;
		cout<<"Identificacion: "<<temp->ID<<endl;
		cout<<"Tiempo Valido: "<<temp->tiempoValida<<endl;
		cout<<"Ventajas: "<<temp->ventajas<<endl;
		cout<<"\n\n";
		
		temp=temp->sig;
		
	
	}while(temp!=listaPrincipalOfertas);
}



void pedirDatosAsignarOfertasAPrograma(){
	
	//input: informacion necesaria para enlazar una oferta a un programa obtenida mediante "cin"
	//output: envio de la informacion al metodo de enlace de
	//restriction: la oferta y el programa deben existir en memoria
	//description: obtiene la informacion del usuario y verifica la autentidad de la misma para el posterior envio
	//				de esta ala funcion de enlace de oferta a programa

	int IDOferta;
	int IDPrograma;
	int cupo;
	cout<<"Digite la identificacion de la oferta: ";
	cin>>IDOferta;
	cout<<"Digite la identificacion del programa: ";
	cin>>IDPrograma;
	cout<<"Digite el cupo de la oferta para el programa: ";
	cin>>cupo;
	
	
	struct oferta * tempHayOferta = buscarOfertas(IDOferta);  
	
	//no esta todavia prototipo hasta corregir
	struct programa * tempHayPrograma = buscarProgramas(IDPrograma);
	
	if(tempHayOferta== NULL or tempHayPrograma==NULL){
		cout<<"\n\nDatos inconsistentes.....Intente de nuevo";
		menuOfertasDesicionAccion();
	
	}
	else{
		cout<<"\nOferta asignada con exito\n";
		asignarOfertasAPrograma(IDOferta,IDPrograma,cupo);
		menu();
	
	}
	
}

void asignarOfertasAPrograma(int idOferta, int idPrograma,int cupo){

	//input: informacion necesaria para enlazar ofertas con programas obtenidas en metodos anteriores de recoleccion de datos
	//output: enlace de la oferta a un programa asi como el establecimiento del cupo
	//restriction:
	//description: localiza las posiciones en memoria de oferta y programa y realiza un enlace mediante los punteros
	//				de la sub lista, ademas crea en memoria la capacidad de cupo de la oferta en relacion al programa
	
	struct oferta * posicionOferta = buscarOfertas(idOferta);  
	struct programa * posicionPrograma = buscarProgramas(idPrograma);
	
	

	struct ofertaObtenerInformacionPrograma * nn = new ofertaObtenerInformacionPrograma(cupo);
	nn->ofertaEnlacePrograma=posicionPrograma;
	nn->sig=posicionOferta->ofertaPrimeroSubListaRelacionPrograma;
	posicionOferta->ofertaPrimeroSubListaRelacionPrograma=nn;

	
}



void cargarListasOfertas(){
	
	//input: 
	//output: creacion de ofertas por defecto para la comprobacion de los metodos
	//restriction:
	//description: crea datos por defecto para el almacenamento de los mismos en memoria,  de tal manera que se pueda 
	//			trabajar con los mismos desde el primer momento de ejecucion del programa

	
	insertarOfertas("A",1,23,"Mitad Precio");
	insertarOfertas("B",2,10,"Niños gratis");
	insertarOfertas("C",3,50,"2 por 1");
	insertarOfertas("D",4,20,"Rebaja 25%");
	insertarOfertas("E",5,3,"Mujeres mitad precio");
	insertarOfertas("F",6,1,"Mujeres y Niños mitad precio");
	insertarOfertas("G",7,30,"Niños Gratis");
	insertarOfertas("H",8,60,"Mitad Precio");
	insertarOfertas("I",9,23,"3 personas por 2");
	
	
	asignarOfertasAPrograma(1,1,30);
	asignarOfertasAPrograma(1,2,15);
	asignarOfertasAPrograma(1,3,45);
	asignarOfertasAPrograma(2,5,89);
	asignarOfertasAPrograma(4,6,200);
	asignarOfertasAPrograma(2,3,66);
	asignarOfertasAPrograma(3,4,23);
	asignarOfertasAPrograma(4,5,5);
	
}
//FIN CODIGO OFERTAS 


/////////////////////////////////////////////////////////



// CODIGO PROGRAMA



void pedirDatosIngresoPrograma(){ 
	//input: datos ingrados por el usuario
	//output: envio de informacion al metodo de ingreso de programas, mensaje informativo para el usuario sobre estado del proceso
	//restriction: la variable tempDestino debe ser diferente de NULL y tempPrograma igual a null, 
	//				ya que la oferta no debe existir previamente
	//description: la funcion se encarga de pedir todos los datos necesarios para la creacion de un programa,
	//				si el ID ingresado es el mismo a un ID situado en la lista de programas, se evitara el ingreso de la 
	//				misma, sino se enviara la informacion al metodo de ingreso de programa


	string nombrePrograma; 
	int precio; 
	int IDPrograma; 
	int IDdestino; 


	cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
	cout<<"Nombre Programa: ";
	cin>>nombrePrograma;
	cout<<"Precio: ";
	cin>>precio;
	cout<<"Identificacion Programa: ";
	cin>>IDPrograma;
	cout<<"Identificacion Destino: ";
	cin>>IDdestino;	
	
	struct destino * tempDestino= buscarDestino(IDdestino);  // revisar si pusos destinos o destino
	
	struct programa * tempPrograma = buscarProgramas(IDPrograma);
	
	if(tempDestino!=NULL && tempPrograma==NULL){
		insertarProgramas(nombrePrograma,precio,IDPrograma,IDdestino);
		cout<<"\n\nPrograma creado con exito\n\n";
		
		
		// prueba impresion lista
		
		imprimirListasProgramas();
		menuAgregarDatos();
	
	}
	else{
	cout<<"\n\nDatos inconclusos.. Intente de nuevo\n";
	menuAgregarDatos();	
	
	}
}

struct programa * buscarProgramas(int IDPrograma){
	//input: ID del programa obtenida con anterioridad
	//output: retorno de informacion al temporal del cual fue llamado
	//restriction:
	//description: realiza un recorrido de la lista de programas buscando el ID obtenido por parametro, si lo encuentra
	//				retorna la posicion en memoria de su localzacion sino retorna NULL



	if(listaPrincipalProgramas==NULL){
		return NULL;
	}
	else{
		struct programa * temp=listaPrincipalProgramas;
		while(temp!=NULL){
			if(temp->IDPrograma==IDPrograma){
				return temp;
			}
			else{
				temp=temp->sig;
			}
		}
		return NULL;
	}
	
}


void cargarListasProgramas(){

	//input: 
	//output: creacion de programas por defecto para la comprobacion de los metodos
	//restriction:
	//description: crea datos por defecto para el almacenamento de los mismos en memoria,  de tal manera que se pueda 
	//			trabajar con los mismos desde el primer momento de ejecucion del programa



	insertarProgramas("Combo_1",35000,1,1);
	insertarProgramas("Combo_2",75000,2,2);
	insertarProgramas("Combo_3",65000,3,3);
	insertarProgramas("Combo_4",15000,4,4);
	insertarProgramas("Combo_5",25000,5,5);
	insertarProgramas("Combo_6",67000,6,6);
	insertarProgramas("Combo_7",30000,7,7);
	insertarProgramas("Combo_8",23000,8,8);
	insertarProgramas("Combo_9",35000,9,8);
	
}


void insertarProgramas(string nombrePrograma,int precio,int IDPrograma,int IDdestino){

	//input: datos necesarios para la creacion deel programa obtenidos con anterioridad
	//output: creacion del programa, se realiza un enlace de un nuevo nodo a la lista principal
	//restriction:
	//description: crear un nuevo enlace en memoria y lo enlaza a la lista principal de programas 
	//				mediante la utilizacion de punteros

	struct programa *nn = new programa(nombrePrograma,precio,IDPrograma,IDdestino);
	
	nn->sig=listaPrincipalProgramas;
	listaPrincipalProgramas=nn;
	
	
	
	struct destino * tempDestino= buscarDestino(IDdestino);  
	struct programa * tempPrograma = buscarProgramas(IDPrograma);
	
	
	//enlace programa-destino
	struct programaObtenerInformacionDestino * nn1 = new programaObtenerInformacionDestino();
	
	nn1->programaEnlaceDestino=tempDestino;
	
	nn1->sig=tempPrograma->programaPrimeroSubListaRelacionDestino;
	
	tempPrograma->programaPrimeroSubListaRelacionDestino=nn1;
	
	
	//enlace destino-programa
	
	struct DestinoObtenerInformacionPrograma * nn2 = new DestinoObtenerInformacionPrograma();
	
	nn2->destinoEnlacePrograma=tempPrograma;
	
	nn2->sig=tempDestino->destinoPrimeroSubListaRelacionPrograma;
	
	tempDestino->destinoPrimeroSubListaRelacionPrograma=nn2;
}

void imprimirListasProgramas(){

	//input: 
	//output: impresion en pantalla de la lista de programas
	//restriction:
	//description: realiza un recorrido de la lista principal de programas, y va imprimiendo la informacion de cada nodo,
	//			conforme avanza el temporal

	struct programa * temp =listaPrincipalProgramas;
	
	cout<<"\n\n********************************Listas de Programas*******************************************\n\n";
	
	while(temp!=NULL){
		cout<<temp->nombre<<endl;
		cout<<temp->precio<<endl;
		cout<<temp->IDPrograma<<"\n ---------------------------------\n";
		temp=temp->sig;
	}
}


void cambiarPrecioDePrograma(){
	
	//input:  datos necesarios para cambiar un precio de programa, ingresados por el usuario
	//output: realizacion de un cambio de precio por el nuevo ungresado por el usuario, notificaciones del proceso
	//restriction: el programa debe existir en memoria
	//description: realiza un recorrido de la lista principal de programas hasta encontrar el indicado, 
	//			si lo encuentra realiza el cambio utilizando el temporal sino realiza notificacion del fallo

	int idProgramaCambiar;
	
	cout<<"\nDigite la identificacion del Programa: ";
	cin>>idProgramaCambiar;
	
	
	struct programa * tempPrograma = listaPrincipalProgramas;
	while(tempPrograma!=NULL){
		if(tempPrograma->IDPrograma==idProgramaCambiar){
			int nuevoPrecio;
			cout<<"Precio Anterior: "<<tempPrograma->precio<<endl;
			cout<<"\nDigite el nuevo precio: ";
			cin>>nuevoPrecio;
			tempPrograma->precio=nuevoPrecio;
			cout<<"\n\n---Dato cambiado con exito: ---";
			cout<<"\nNuevo Precio: "<<tempPrograma->precio<<endl;
			return;
		
		}
		else
		tempPrograma=tempPrograma->sig;
	}
	
	if(tempPrograma==NULL){
		cout<<"\nEl programa no existe....Intente de nuevo ";
		menuAgregarDatos();	
	}

}

///////////////////////////////////////////////////////////////////////////



//CODIGO CIRCUITOS





void cargarDatosCircuitos(){

	//input: 
	//output: creacion de circuitos por defecto para la comprobacion de los metodos
	//restriction:
	//description: crea datos por defecto para el almacenamento de los mismos en memoria,  de tal manera que se pueda 
	//			trabajar con los mismos desde el primer momento de ejecucion del programa
	
	llenarInformacionNuevoCircuito(5,"Alpinista",1);
	enlazarCircuitoProgramaYCircuitoDestino(1,1);
	
	llenarInformacionNuevoCircuito(5,"Viajero",2);
	enlazarCircuitoProgramaYCircuitoDestino(2,2);
	
	llenarInformacionNuevoCircuito(5,"America",3);
	enlazarCircuitoProgramaYCircuitoDestino(3,3);
	
	llenarInformacionNuevoCircuito(5,"Conoce_Asia",4);
	enlazarCircuitoProgramaYCircuitoDestino(4,4);
	
	llenarInformacionNuevoCircuito(5,"Conoce_Africa",5);
	enlazarCircuitoProgramaYCircuitoDestino(5,5);
	
	llenarInformacionNuevoCircuito(5,"Viaje_de_Familia",6);
	enlazarCircuitoProgramaYCircuitoDestino(6,6);
	
	llenarInformacionNuevoCircuito(5,"Conoce_America_Latina",7);
	enlazarCircuitoProgramaYCircuitoDestino(7,7);
	
	llenarInformacionNuevoCircuito(5,"Conoce_Europa",8);
	enlazarCircuitoProgramaYCircuitoDestino(8,8);
	enlazarCircuitoProgramaYCircuitoDestino(8,3);
	enlazarCircuitoProgramaYCircuitoDestino(8,1);
	
	llenarInformacionNuevoCircuito(5,"Verano_Soleado",9);
	enlazarCircuitoProgramaYCircuitoDestino(9,8);
	enlazarCircuitoProgramaYCircuitoDestino(9,5);
	enlazarCircuitoProgramaYCircuitoDestino(9,4);
	
}


void pedirDatosCircuito(){
	
	//input: datos ingresados por el usuario
	//output: envio de informacion al metodo de creacion de memoria y enlace de nodos, mensaje informativo para el 
	//			usuario sobre estado del proceso
	//restriction: la variable tempCircuito debe ser diferente de NULL y tempPrograma igual a null, 
	//				ya que el circuito debe existir previamente
	//description: la funcion se encarga de pedir todos los datos necesarios para la creacion de un circuito,
	//				si el ID ingresado es el mismo a un ID situado en la lista de circuitos, se evitara el ingreso de la 
	//				misma, sino se enviara la informacion a los demas metodos de creacion de circuito para 
	//				continuar el proceso


	int precio;
	int cantiDiasViaje;
	string nombreCircuito;
	int identificacionCircuito;
	int identificacionPrograma;
	
	cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
	cout<<"Nombre Circuito: ";
	cin>>nombreCircuito;
	cout<<"Cantidad Dias: ";
	cin>>cantiDiasViaje;
	cout<<"Identificacion Circuito: ";
	cin>>identificacionCircuito;	
	cout<<"Identificacion Programa Agregar Circuito: ";
	cin>>identificacionPrograma;
	struct circuito * tempCircuito= buscarCircuitos(identificacionCircuito);
	struct programa * tempPrograma=buscarProgramas(identificacionPrograma);
	
	if(tempCircuito!=NULL or tempPrograma==NULL){
		cout<<"\nDatos inconclusos...Intente de nuevo\n";
		menuAgregarDatos();
	}
	
	else{


		llenarInformacionNuevoCircuito(cantiDiasViaje,nombreCircuito,identificacionCircuito);	
		enlazarCircuitoProgramaYCircuitoDestino(identificacionCircuito,identificacionPrograma);
		pedirMasProgramasDelCircuito(identificacionCircuito);
	}
}

void llenarInformacionNuevoCircuito(int cantiDiasViaje,string nombreCircuito,int identificacionCircuito){
	//input: datos ingresados por el usuario
	//output: creacion de un espacio en memoria, y enlace de la misma en la lista principal
	//restriction: 
	//description: la funcion se encarga de enlazar un nuevo nodo de tipo estructura circuito a la lista 
	//				principal de la misma
	
	struct circuito * nn = new circuito(cantiDiasViaje,nombreCircuito,identificacionCircuito);
	nn->sig=listaPrincipalCircuitos;
	listaPrincipalCircuitos=nn;
}


void pedirMasProgramasDelCircuito(int identificacionCircuito){
	//input: identificacion del circuito
	//output: enlace continuo de programas al circuito, hasta ue el usuario indique lo contrario
	//restriction:  programa debe existir en memoria con anterioridad
	//description: la funcion se encarga de ser un menu intermediario , para el continuo llamado de funciones
	//				de enlazamiento con programas y la continua interaccion con el usuario
	//				hasta que este decida lo contrario
	

	int opcion;
	cout<<"\n1. Enlazar otro programa al circuito";
	cout<<"\n2. No agregar otro programa \n";
	cout<<"opcion: ";
	cin>>opcion;
	
	if(opcion==1){
		int identifiPrograma;
		cout<<"\nDigite la identificacion del programa: ";
		cin>>identifiPrograma;
		
		struct programa *tempPrograma = buscarProgramas(identifiPrograma);
		
		if(tempPrograma==NULL){   //falta restricion de no enlazar programas que ya estan enlazados
			cout<<"      "<<tempPrograma->IDPrograma<<endl;
			cout<<"\nDatos inconclusos\n";
			pedirMasProgramasDelCircuito(identificacionCircuito);
		}	
		
		else{
		
			enlazarCircuitoProgramaYCircuitoDestino(identificacionCircuito,identifiPrograma);
			pedirMasProgramasDelCircuito(identificacionCircuito);
		}
	
	}
	
	else if(opcion==2){
		cout<<"\nCircuito creado con exito\n";
		
		//Prueba de impresion de listas Circulares
	
		imprimirListaCircuitos();
		menuAgregarDatos();
	}
	else{
		cout<<"\nDigite lo que esta en pantalla\n";
		pedirMasProgramasDelCircuito(identificacionCircuito);
	}
}

void enlazarCircuitoProgramaYCircuitoDestino(int identificacionCircuito,int identificacionPrograma){


	//input: datos necesarios para la creacion del circuito obtenidos con anterioridad
	//output: creacion del circuito, se realiza un enlace al programa y al destino al que pertenece este
	//restriction:
	//description: crea nuevas nodos de tipo sublista para enlazarlos con el nodo deseado segun datos del usuario
	
	struct circuito * posicionCircuito= buscarCircuitos(identificacionCircuito);
	struct programa * posicionPrograma=buscarProgramas(identificacionPrograma);
	
	
	struct circuitoObtenerInformacionProgramas * nn = new circuitoObtenerInformacionProgramas();
	nn->circuitoEnlacePrograma=posicionPrograma;
	nn->sig=posicionCircuito->circuitoSubListaPrimeroProgramas;
	posicionCircuito->circuitoSubListaPrimeroProgramas=nn;
	
	
	struct programaObtenerInformacionDestino * tempProgramaDestino = posicionPrograma->programaPrimeroSubListaRelacionDestino;
	
	int identificacionDestinoDelDestino= tempProgramaDestino->programaEnlaceDestino->ID;
	struct destino * tempDestino = buscarDestino(identificacionDestinoDelDestino);
	struct circuitoObtenerInformacionDestinos * nn2 = new circuitoObtenerInformacionDestinos();
	nn2->CircuitoEnlaceDestino=tempDestino;
	nn2->sig = posicionCircuito->circuitoSubListaPrimeroDestinos;
	posicionCircuito->circuitoSubListaPrimeroDestinos=nn2;
	
}



struct circuito * buscarCircuitos(int IDBuscarCircuito){
	
	//input: ID del circuito obtenida con anterioridad
	//output: retorno de informacion al temporal del cual fue llamado
	//restriction:
	//description: realiza un recorrido de la lista de ircuitos buscando el ID obtenido por parametro, si lo encuentra
	//				retorna la posicion en memoria de su localzacion sino retorna NULL


	struct circuito * temp = listaPrincipalCircuitos;
	
	if(temp==NULL){
		return NULL;
	}
	else{
	
		while(temp!=NULL){
			if(temp->IDCircuito==IDBuscarCircuito){
				return temp;
			}
			else{
				temp=temp->sig;
			}
		}
		return NULL;
	}
}


void imprimirListaCircuitos(){
	
	//input: 
	//output: impresion en pantalla de la lista de circuitos
	//restriction:
	//description: realiza un recorrido de la lista principal de circuitos, y va imprimiendo la informacion de cada nodo,
	//			conforme avanza el temporal

	struct circuito * tempCircuito = listaPrincipalCircuitos;
	
	if(tempCircuito==NULL){
		cout<<"\nNo hay circuitos\n";
	}
	else{
		cout<<"\n**************************************Lista de Circuitos*******************************************\n";
		while(tempCircuito!=NULL){
			cout<<"\n/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /\n\n";
			cout<<"\n______Circuito_____\n";
			cout<<"Nombre: "<<tempCircuito->nombre<<endl;
			cout<<"Cantidad Dias: "<<tempCircuito->cantidadDias<<endl;
			cout<<"Identidicacion del Circuito: "<<tempCircuito->IDCircuito<<endl;
			cout<<"\nProgramas del Circuito: \n\n";
			
			struct circuitoObtenerInformacionProgramas * tempEnlaceCircuitoPrograma = tempCircuito->circuitoSubListaPrimeroProgramas;
			
			while(tempEnlaceCircuitoPrograma!=NULL){
				cout<<"Nombre: "<<tempEnlaceCircuitoPrograma->circuitoEnlacePrograma->nombre<<endl;
				cout<<"Precio: "<<tempEnlaceCircuitoPrograma->circuitoEnlacePrograma->precio<<endl;	
				cout<<"Identificacion del Destino: "<<tempEnlaceCircuitoPrograma->circuitoEnlacePrograma->IDDestino<<endl;
				cout<<"Identificacion del Programa: "<<tempEnlaceCircuitoPrograma->circuitoEnlacePrograma->IDPrograma<<"\n\n";
				cout<<"- - - - - - - - - - - - - - - - \n\n";
				tempEnlaceCircuitoPrograma=tempEnlaceCircuitoPrograma->sig;
				
			}
			
			tempCircuito=tempCircuito->sig;
			
			
		}
	}
	
}



//FIN CODIGO CIRCUITO

///////////////////////////////////////////////////////////////////


//CODIGO USUARIOS

void imprimirUsuariosEnLista(){
	
	/*Fecha de inicio: 27/08/2015
	Fecha última modificación: 27/08/2015.
	Descripción:imprime la informacion basica de todos los usuarios que se encuentran 
	en la lista de usuarios del sistema. 
	parametro: ninguno.
	*/
	
	struct usuarios *temp= primerUsuario;
	if(primerUsuario== NULL){
	cout<<"\tlista vacia"<<endl;
	menu();
	}
	while(temp->sig!= NULL){
	cout<<"\t\t\t\t"<<temp->nombre<<endl;
	cout<<"\nNombre: "<<temp->nombre<<endl;
	cout<<"Identificacion: "<<temp->ID<<endl;
	cout<<"Edad: "<<temp->edad<<endl<<endl;
	temp= temp->sig;	
	}
	cout<<"\nNombre: "<<temp->nombre<<endl;
	cout<<"Identificacion: "<<temp->ID<<endl;
	cout<<"Edad: "<<temp->edad<<endl<<endl;
	cout<<"\n\n~~~~~~~~~~~~~~~~ Fin de lista de usuarios ~~~~~~~~~~~~~~~~~~~~~\n\n";
	menu();
}

struct usuarios *buscarUsuario(int id){
	
	/*Fecha de inicio: 26/08/2015
	Fecha última modificación: 27/08/2015.
	Descripción: busca la identificacion que es enviada por parametro en los diferentes usuarios
	que se encuentran en la lista de usuarios (primerUsuario) y retorna nulo si no lo encuentra 
	o retorna el nodo con la misma identificacion buscada. 
	parametro: recibe la identificacion de un usuario al cual se desea buscar.
	*/
	
	if(primerUsuario == NULL){
	return NULL;
	}
	else{
	struct usuarios *temp= primerUsuario;
	while(temp != NULL){
	if(temp->ID ==id){
	return temp;
	}
	temp= temp->sig;	
	}
	}
	return NULL;
}

void agregarUsuariosEnLista(string nombreUsuario,int identificacion,int edadUsuario){
	
	/*Fecha de inicio: 26/08/2015
	Fecha última modificación: 27/08/2015.
	Descripción:crea un nuevo nodo tipo usuario y compara su nombre con el resto de los que se 
	encuentran en la lista acomodando a este en orden alfabetico. 
	parametro: recibe el nombre del usuario: nombreUsuario, la identificacion del usuario: identificacion,
	y la edad del usuario: edadUsuario.
	*/
	
	struct usuarios *nuevoUsuario= new usuarios(nombreUsuario,identificacion,edadUsuario);
	if(primerUsuario == NULL){
	primerUsuario= nuevoUsuario;
	}
	else if(nombreUsuario< primerUsuario->nombre){
	nuevoUsuario->sig= primerUsuario;
	primerUsuario= nuevoUsuario;
	}
	
	else{
	
	struct usuarios *temp= primerUsuario;
	while(temp->sig != NULL){
	if(nombreUsuario >= temp->nombre and nombreUsuario < temp->sig->nombre){
	nuevoUsuario->sig=temp->sig;
	temp->sig= nuevoUsuario;
	return;
	}
	
	temp= temp->sig;
	}
	temp->sig= nuevoUsuario;
	
	}
}



//Lista simple con inserción ordenada por nombre
void DatosAgregarNuevoUsuario(){
	
		/*Fecha de inicio: 26/08/2015
	Fecha última modificación: 26/08/2015.
	Descripción: le solicita al usuario que ingrese datos especificos necesarios
	para la creacion de un usuario. utiliza el toupper para cambiar la primera 
	letra del nombre digitado por el usuario a una letra mayuscula en caso de ser minuscula 
	una vez terminada la solicitud de datos se envia a otra funcion agregarUsuariosEnLista y 
	se le envia nombre Usuario,identificacion,edad Usuario.
	Lista simple con inserción ordenada por nombre. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^ Agregar Usuario. ^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
	string nombreUsuario;
	int identificacion;
	int edadUsuario;
	
	cout<<"\nEscriba el nombre del usuario: ";
	cin>>nombreUsuario;
	int i=0;
  	nombreUsuario[i]=(toupper(nombreUsuario[i]));
	cout<<"\nEscriba la identificacion del usuario: ";
	cin>>identificacion;
	cout<<"\nEscriba la edad del usuario: ";
	cin>>edadUsuario;
	
	struct usuarios *resultado=buscarUsuario(identificacion);  
	if(resultado == NULL ){
	agregarUsuariosEnLista(nombreUsuario,identificacion,edadUsuario);
	cout<<"\nSe ha agragado exitosamente.\n";
	}
	else{
	cout<<"no se puede insertar "<<nombreUsuario<<" ya que este esta repetido o ha ocurrido un error"<<endl;	
	menu();
	}
}



void usuariosAgrgadosPorDefecto(){
	
	/*Fecha de inicio: 27/08/2015
	Fecha última modificación: 27/08/2015.
	Descripción:datos por defecto para que se introduzcan el la lista de usuarios del sistema. 
	parametro: ninguno.
	*/
	
	agregarUsuariosEnLista("Maria",1,51);
	agregarUsuariosEnLista("Pablo",2,43);
	agregarUsuariosEnLista("Laura",3,19);
	agregarUsuariosEnLista("Andres",4,23);
	agregarUsuariosEnLista("Felipe",5,34);
	agregarUsuariosEnLista("Zelenia",6,36);
	agregarUsuariosEnLista("Jonathan",7,80);
	agregarUsuariosEnLista("Alexa",8,56);
	agregarUsuariosEnLista("Alexa",9,37);
	agregarUsuariosEnLista("Enriqueto",10,35);
}


void agregarProgramaUsuario(int id,int idPrograma){
	
	/*Fecha de inicio: 29/08/2015
	Fecha última modificación: 30/08/2015.
	Descripción:agrega un programa en la sublista de programas que posee un usuario. 
	parametro: identificacion del usuario: id y la identificacion del programa:idPrograma.
	*/
	
	struct usuarios *persona= buscarUsuario(id);
	if(persona== NULL){
	cout<<"ERROR. Datos inconclusos\n";
	menu();
	}
	else{
	
	struct programa *programaEncontrado= buscarProgramas(idPrograma);
	if(programaEncontrado == NULL){
	cout<<"ERROR. Datos inconclusos\n";
	menu();	
	}
	else{
	struct UsuarioObtenerInformacionPrograma *tempPrograma= persona->usuarioSubListaPrimeroPrograma;
	while(tempPrograma != NULL){
	if(tempPrograma->usuarioEnlacePrograma->IDPrograma == idPrograma){
	cout<<"\nEste programa ya esta disponible en la lista del usuario.\n";
	menu();	
	}
	tempPrograma= tempPrograma->sig; 	
	}
	struct UsuarioObtenerInformacionPrograma *nuevoPrograma= new UsuarioObtenerInformacionPrograma();
	nuevoPrograma->sig= persona->usuarioSubListaPrimeroPrograma;
	nuevoPrograma->usuarioEnlacePrograma= programaEncontrado;
	persona->usuarioSubListaPrimeroPrograma= nuevoPrograma;
	
	}
	}
}


void agregarNuevoProgramaDeUsuario(){
	
	/*Fecha de inicio: 29/08/2015
	Fecha última modificación: 29/08/2015.
	Descripción:solicita al usuario que digite la idenificacion del usuario y la del programa
	a comprar y lo envia por parametro a otra funcion agregarProgramaUsuario para efectuar las
	operaciones correspondientes. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n----------------------Agragar un programa al usuario--------------\n\n";
	int id;
	cout<<"\nDigite el id del usuario: \n";
	cin>>id;
	int idPrograma;
	cout<<"\nDigite la identificacion del programa al que desea ir: \n";
	cin>>idPrograma;
	agregarProgramaUsuario(id,idPrograma);
	cout<<"Se ha agregado exitosamente.\n";	
	menu();
}


void agregarPorDefectoProgramaDeUsuario(){
	/*Fecha de inicio: 30/08/2015
	Fecha última modificación: 30/08/2015.
	Descripción:datos enviados a una funcion para que esta los agregue a la sublista
	de programas del usuario. 
	parametro: ninguno.
	*/
	agregarProgramaUsuario(1,5);
	agregarProgramaUsuario(1,3);
	agregarProgramaUsuario(1,8);
	agregarProgramaUsuario(1,4);
	agregarProgramaUsuario(3,1);
	agregarProgramaUsuario(3,5);
	agregarProgramaUsuario(6,3);
	agregarProgramaUsuario(6,8);
	agregarProgramaUsuario(6,4);
	agregarProgramaUsuario(6,1);
}


void agregarUnNuevoCircuitoDeUnUsuarioProcesos(int identUsuario,int identCircuito){
	
	/*Fecha de inicio: 5/09/2015
	Fecha última modificación: 6/09/2015.
	Descripción: agrega a la sublista de circuitos del usuario con la identidad solicitada el circuito
	que posee la misma identidad digitada por el usuario. 
	parametro: recibe la identificacion del usuario y la identificacion del circuito.
	*/
	
	struct usuarios *tempUsuario= buscarUsuario(identUsuario);
	struct circuito *tempCircuito= buscarCircuitos(identCircuito);
	if(tempUsuario == NULL or tempCircuito == NULL){
	cout<<"\nERROR. datos inconclusos\n";
	menu();
	}
	else{
	
	struct UsuarioObtenerInformacionCircuito *circuitoNoRepetido= tempUsuario->usuarioSubListaPrimeroCircuito;
	while(circuitoNoRepetido != NULL){
	struct circuito *CircuitoUsuario= circuitoNoRepetido->usuarioEnlaceCircuito;
	if(CircuitoUsuario->IDCircuito == tempCircuito->IDCircuito){
	cout<<"\nERROR. Este circuito ya se encuentra disponible en la lista del usuario.\n";
	menu();
	}
	circuitoNoRepetido= circuitoNoRepetido->sig;
	}
	struct UsuarioObtenerInformacionCircuito *nuevoCircuito= new UsuarioObtenerInformacionCircuito();
	nuevoCircuito->sig= tempUsuario->usuarioSubListaPrimeroCircuito;
	tempUsuario->usuarioSubListaPrimeroCircuito= nuevoCircuito;
	nuevoCircuito->usuarioEnlaceCircuito= tempCircuito;
	}
}

/////////////////////////////////////////////
void agregarUnNuevoCircuitoDeUnUsuario(){
	
	/*Fecha de inicio: 5/09/2015
	Fecha última modificación: 5/09/2015.
	Descripción: solicita al usuario la informacion necesaria para poder ingresar un nuevo circuito
	a la sublista de cierto usuario. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n....................Agregar Un Nuevo Circuito Para Un Usuario................\n\n";
	int identUsuario;
	int identCircuito;
	cout<<"\nDigite la identificacion del usuario: \n";
	cin>>identUsuario;
	cout<<"\nIngrese la identificacion de el circuito al cual desea comprar: \n";
	cin>>identCircuito;
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(identUsuario,identCircuito);
	cout<<"\nEl circuito fue agregado a la lista de circuitos del usuario.\n";

}


void circuitoDeUsuarioAgregadoPorDefecto(){
	
	/*Fecha de inicio: 6/09/2015
	Fecha última modificación: 6/09/2015.
	Descripción:datos enviados por defecto a una funcion para que esta se encargue de agregar a
	los circuitos comprados por cierto usuario. 
	parametro: ninguno.
	*/
	
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(2,5);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(7,5);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(1,5);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(1,8);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(1,4);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(2,4);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(2,8);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(3,4);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(6,8);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(7,4);
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(8,8);	
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(9,8);	
	agregarUnNuevoCircuitoDeUnUsuarioProcesos(8,1);
	
}


/////////////// FIN CODIGO USUARIOS /////////////

/////////////////////////////////

//CODIGO COMENTARIO

void listaDeComentariosPorDefecto(){
	
	/*Fecha de inicio: 2/09/2015
	Fecha última modificación: 24/08/2015.
	Descripción:datos enviados a una funcion para que esta los agregue a la sublista
	de comentarios del usuario. 
	parametro: ninguno.
	*/
	
	insertarComentario(1,1,"02/03/2015",8,"Bonito_paseo");
	insertarComentario(2,2,"02/04/2015",7,"Interesante_muy_divertido");
	insertarComentario(3,1,"04/05/2015",2,"me_parece_muy_caro");
	insertarComentario(1,2,"28/06/2015",7,"todo_muy_ordenado_e_impecable");
	insertarComentario(2,4,"23/08/2015",9,"lo_recomiendo");
	insertarComentario(3,6,"18/08/2015",9,"muy_bueno_amigos_lo_recomiendo");
	insertarComentario(4,8,"20/09/2015",2,"no_vayan_es_muy_feo");
	insertarComentario(5,4,"04/09/2015",8,"es_divertido_y_barato_lo_recomiendo");
	insertarComentario(6,1,"09/09/2015",8,"vayan_es_super_divertido");
	insertarComentario(1,5,"07/09/2015",7,"un_vieje_exelente");
	
}

void insertarComentario(int idPrograma,int idenUsuario,string fecha,int calificacionUsuario,string comentarioUsuario){
	
	/*Fecha de inicio: 2/09/2015
	Fecha última modificación: 2/09/2015.
	Descripción:inserta a un nuevo nodo de tipo comentario en la lista de comentarios del usuario
	correspondiente. 
	parametro: recibe la identificacion del programa, la identificacion del usuario, 
	la fecha en la que se realizó el comentario, la calificacion dada por el usuario, y el comentario
	escrito por el usuario.
	*/
	
	struct programa *tempPrograma= buscarProgramas(idPrograma);
	struct usuarios *tempUsuario= buscarUsuario(idenUsuario);
	if(tempPrograma==NULL or tempUsuario==NULL){
	cout<<"ERROR. No se puede insertar ya que se encuentran algunos datos inconclusos.\n";
	menu();
	}
	struct comentario *nuevoComentario= new comentario(calificacionUsuario,comentarioUsuario,fecha);
	nuevoComentario->sig = tempUsuario->PrimeroComentario;
	tempUsuario->PrimeroComentario = nuevoComentario;
	nuevoComentario->enlaceProgramaComentario = tempPrograma;

}
void datosAgregarComentario(){
	
	/*Fecha de inicio: 2/09/2015
	Fecha última modificación: 2/09/2015.
	Descripción:solicita al usuario que digite la informacion necesaria para poder crear un nuevo 
	comentario del usuario dirigido a cirto programa. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n----------------- Comentarios -----------------------------\n\n";
	int idPrograma;
	int idenUsuario;
	string fecha;
	int calificacionUsuario;
	string comentarioUsuario;
	cout<<"\nDigite la fecha: \n";
	cin>>fecha;
	cout<<"\nDigite el comentario todo pegado separarado por mayuscuals o guion bajo: \n";
	cin>>comentarioUsuario;
	cout<<"\nDigite una calificacion del uno al diez para este programa: \n";
	cin>>calificacionUsuario;
	if(calificacionUsuario >10 or calificacionUsuario < 1){
	cout<<"\nERROR solo calificacion del uno al diez\n";
	menu();
	}
	cout<<"\nDigite el id del programa: \n";
	cin>>idPrograma;
	cout<<"\nDigite el id del usuario: \n";
	cin>>idenUsuario;
	insertarComentario(idPrograma,idenUsuario,fecha,calificacionUsuario,comentarioUsuario);
	cout<<"\nse ha agregado exitosamente\n";
	menu();
	}



///FIN CODIGO COMENTARIOS/////
/////////////////////////////////////////////



///////////////////////////////////////////////
//CODIGO CONSULTAS


//  1.	Consultar los destinos visitados por una persona X.


void consultarDestinosVisitadosPorPersona(){
	/*Fecha de inicio: 2/09/2015
	Fecha última modificación: 3/09/2015.
	Descripción: el metodo solicita al usuario que digite la identificacion del usuario
	al cual se desea realizar la consulta. una vez comprobados se recorre la sublista de programas
	del usuario y se verifica la identificacion del destino de cada programa del usuario y se imprime
	la informacion de el destino del cual proviene el programa que se encuentra asociado al usuario.
	parametro: ninguno.
	*/
	
	cout<<"\n\n______________ Consultar Destinos Visitados Por Una Persona ______________\n\n";
	int iden;
	cout<<"\nDigite el ID de la persona a la cual desea que se realice la consulta: ";
	cin>>iden;
	struct usuarios *tempUsuarios= buscarUsuario(iden);
	if(tempUsuarios == NULL){
	cout<<"\nERROR no se pudo encontrar al usuario.\n";
	menu();
	}
	else{
	struct UsuarioObtenerInformacionPrograma *tempEnlaceSublistaProgramas=tempUsuarios->usuarioSubListaPrimeroPrograma;
	if(tempEnlaceSublistaProgramas == NULL){
	cout<<"\nERROR. Datos inconclusos. Es probable que la persona no tenga programas comprados.\n";
	menu();
	}
	while(tempEnlaceSublistaProgramas != NULL){
	struct programa *programaDeUsuario= tempEnlaceSublistaProgramas->usuarioEnlacePrograma;	
	struct destino *recorridoDestino= primeroDestino;
	while(recorridoDestino != NULL){
	if(recorridoDestino->ID == programaDeUsuario->IDDestino){
	cout<<"Nombre del destino: "<<recorridoDestino->nombre<<endl;
	cout<<"Identificacion del destino: "<<recorridoDestino->ID<<endl<<endl;
	}
	recorridoDestino= recorridoDestino->sig;
	}
	
	tempEnlaceSublistaProgramas= tempEnlaceSublistaProgramas->sig;
	}	
	}
	menu();
}


//  2.	Consultar los comentarios de un programa X.
void imprimirComentarioDePrograma(){
	
	/*Fecha de inicio: 3/09/2015
	Fecha última modificación: 4/09/2015.
	Descripción:primeramente solicita al usuario que digite la identificacion del programa que 
	desea realizar la consulta. la funcion recorre la sublista a todos los usuarios del
	sistema y las sublistas de comentarios de cada usuario e imprime los comentarios que esten
	enlazados al programa que posee la identificacion digitada por el usuario. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n~~~~~~~~~~~~~~~~ imprimir Comentarios De Un Programa ~~~~~~~~~~~~~~\n\n ";
	int idDePrograma;
	cout<<"\nDigite la identificacion del programa al cual desea imprimir los comentarios: \n";
	cin>>idDePrograma;
	struct programa *tempPrograma= buscarProgramas(idDePrograma);
	int suma= 0;
	if(tempPrograma == NULL){
	cout<<"\nNo se encuentra el programa\n";
	menu();
	}
	else{
	struct usuarios *tempUsuario= primerUsuario;
	while(tempUsuario != NULL){
	struct comentario *temComentario= tempUsuario->PrimeroComentario;
	while(temComentario != NULL){
	if(temComentario->enlaceProgramaComentario == tempPrograma){
	suma++;
	cout<<"Usuario: "<<tempUsuario->nombre<<endl<<"\t\t\t"<<temComentario->coment<<endl;
	
	}
	
	temComentario= temComentario->sig;
	}
	
	tempUsuario= tempUsuario->sig;
	}
	}
	if(suma == 0){
		cout<<"\nEl programa no posee comentarios\n";
	}
	menu();
}


//3.	Cuáles son los circuitos más escogidos por los usuarios.
void circuitosMasEscogidosPorLosUsuarios(){
	
	/*Fecha de inicio: 5/09/2015
	Fecha última modificación: 6/09/2015.
	Descripción: la funcion realiza un recorrido por toda la sublista de circuitos comprados por los 
	usuarios de todos los usuarios y mediante un contador, cuenta las veces y compara a esta con las veces
	que se ha comprado los diferentes circuitos y de esta manera delimita los tres primeros lugares de
	los circuitos mas comprados por los usuarios.
	parametro: ninguno.
	*/
	
	int suma= 0; //contador que irá sumando cada vez que se encuentra el circuito
	int cont= 0; 

	//numeros para comparar cual se ha repetido mas veces	
	int numeroUno= 0;
	int numeroDos= 0;
	int numeroTres= 0;
	
	//para almacenar a los nodeos de los circuitos mas comprados
	struct circuito *tempCircuitoEvaluacion;
	struct circuito *primerLugar;
	struct circuito *segundoLugar;
	struct circuito *tercerLugar;
	
	while(cont < 3){
	
	struct circuito *circuitoTemp= listaPrincipalCircuitos;
	while(circuitoTemp != NULL){
		suma= 0;
		struct usuarios *persona= primerUsuario;
		while(persona != NULL){
			struct UsuarioObtenerInformacionCircuito *tempEsCircuito= persona->usuarioSubListaPrimeroCircuito;
			while(tempEsCircuito != NULL){
				if(tempEsCircuito->usuarioEnlaceCircuito == circuitoTemp){
					suma++;
				}
				tempEsCircuito= tempEsCircuito->sig;
			}
	
		persona=persona->sig;
		}
	
	
	if(suma > numeroUno){
	numeroUno= suma;
	primerLugar= circuitoTemp;
	
	}
	else if(suma == numeroUno and circuitoTemp != primerLugar){
	struct circuito *auxiliar= segundoLugar; 
	numeroTres= numeroDos;
	tercerLugar= auxiliar;
	numeroDos= suma;
	segundoLugar= circuitoTemp;
	
	}
	
	
	else if(suma < numeroUno and suma > numeroDos){
	numeroDos= suma;
	segundoLugar= circuitoTemp;
	
	
	}
	else if(suma == numeroDos and circuitoTemp != segundoLugar and circuitoTemp != primerLugar){
	numeroTres= suma;
	tercerLugar= circuitoTemp;
	
	}
	else if(suma < numeroDos and suma > numeroTres){
	numeroTres= suma;
	tercerLugar= circuitoTemp;
	

	}
	
	circuitoTemp= circuitoTemp->sig;
	} 	

	
	cont++;
	}
	cout<<"\n\n-------------------Tres primeros Lugares------------------------------\n\n";
	cout<<"\nPrimer lugar:\n";
	cout<<"\nNombre: "<<primerLugar->nombre<<endl<<"identificacion: "<<primerLugar->IDCircuito<<endl;
	cout<<"\nSegundo lugar:\n";
	cout<<"\nNombre: "<<segundoLugar->nombre<<endl<<"identificacion: "<<segundoLugar->IDCircuito<<endl;
	cout<<"\nTercer lugar:\n";
	cout<<"\nNombre: "<<tercerLugar->nombre<<endl<<"identificacion: "<<tercerLugar->IDCircuito<<endl;
	cout<<"\n\n----------------------------FIN-----------------------------\n\n";
}



// numero 4 imprimir Cupos Disponibles De Ofertas

void imprimirCuposDisponiblesDeOfertas(){

	//input: 
	//output: impresion en pantalla de los cupos de las ofertas segun cada uno de los programas
	//restriction:
	//description: realiza un recorrido de la lista principal de ofertas, y va imprimiendo la informacion de cada nodo,
	//			ademas de realizar un recorrido de cada sublista perteneciente a cada nodo de la oferta, impriendo la informacion de 
	//			cada uno de los elementos de las mismas
	
	struct oferta * tempRecorrido = listaPrincipalOfertas;
	
	if(tempRecorrido==NULL){
		cout<<"\nNo hay ofertas Disponibles ";
		menuConsultas();
	}
	else{
		cout<<"\n******************** Lista de Ofertas ***************************\n";
		cout<<"\n********************                  ***************************\n";
		
		do{
		
			cout<<"\nNombre: "<<tempRecorrido->nombre<<endl;
			cout<<"ID: "<<tempRecorrido->ID<<endl;
			cout<<"Tiempo Valida: "<<tempRecorrido->tiempoValida<<endl;
			cout<<"Ventajas: "<<tempRecorrido->ventajas<<endl;
			cout<<"\n\n";
			
			struct ofertaObtenerInformacionPrograma * tempResorridoSublista = tempRecorrido->ofertaPrimeroSubListaRelacionPrograma;
			
			while(tempResorridoSublista!=NULL){
				cout<<"Cupo Disponible de la Oferta del Programa : "<<tempResorridoSublista->ofertaEnlacePrograma->nombre<<" : "<<tempResorridoSublista->cupo;
				cout<<"\n\n";
				tempResorridoSublista=tempResorridoSublista->sig;	
			}
			tempRecorrido=tempRecorrido->sig;
			cout<<"\n\n--------------------------------\n\n";
			
		}while(tempRecorrido!=listaPrincipalOfertas);
		menuConsultas();
	}
	
}

///////////////////////////////////////////

//CODIGO REPORTE DE RESULTADOS

//numero 2
void imprimirListaDeProgramasSegunDestino(){

	//input: datos ingresados por el usuario
	//output: impresion en pantalla de los programas de un destino en especifico escogido por el usuario
	//restriction:
	//description: realiza un recorrido de la lista principal de destino hasta identificar el adecuado, y realiza un recorrido
	//				de la sub lista que posee el nodo, recorriendo los programas con los que este relacionado el destino
	//				se realiza una impresion de datos durante el recorrido


	int identificacionDestino;
	cout<<"\nDigite la identificacion del destino\n";
	cout<<"identificacion: ";
	cin>>identificacionDestino;
	
	struct destino * tempDestino = buscarDestino(identificacionDestino);
	
	if(tempDestino==NULL){
		cout<<"\nDestino no encontrado..... Intente de nuevo\n";
		menuReporteResultados();
	}
	else{
		cout<<"\n\n-------Destino: ---------------\n\n";
		cout<<"Nombre Destino: "<<tempDestino->nombre<<endl;
		cout<<"Identificacion: "<<tempDestino->ID<<endl;
		cout<<"Poblacion: "<<tempDestino->poblacion<<endl;
		
		struct DestinoObtenerInformacionPrograma * tempPrograma = tempDestino->destinoPrimeroSubListaRelacionPrograma;
		cout<<"\n--------Programas: -----------\n\n";
		while(tempPrograma!=NULL){
			cout<<"Nombre: "<<tempPrograma->destinoEnlacePrograma->nombre<<endl;
			cout<<"precio: "<<tempPrograma->destinoEnlacePrograma->precio<<endl;
			cout<<"Identificacion: "<<tempPrograma->destinoEnlacePrograma->IDPrograma<<"\n\n/  /  /  /  /  /  /  /  /  /  /\n\n";
			tempPrograma=tempPrograma->sig;
		
		}
		menuReporteResultados();
	
	}
}



// numero 4


void imprimirProgramasDeOferta(){


	//input: datos ingresados por el usuario
	//output: impresion en pantalla de los programas de una oferta en especifico escogido por el usuario
	//restriction:
	//description: realiza un recorrido de la lista principal de ofertas hasta identificar el adecuado, y realiza un recorrido
	//				de la sub lista que posee el nodo, recorriendo los programas con los que este relacionado el destino
	//				se realiza una impresion de datos durante el recorrido


	int IdOferta;
	cout<<"\nDigite la identificacion de la oferta: ";
	cin>>IdOferta;
	
	struct oferta * tempOferta = buscarOfertas(IdOferta);
	if(tempOferta==NULL){
		cout<<"\nLa Oferta no existe\n";
	}
	
	else{
	
		cout<<"\n/ / / / / / / / Informacion Oferta / / / / / / / / / \n\n";
		cout<<"\nNombre: "<<tempOferta->nombre<<endl;
		cout<<"Identificacion Oferta: "<<tempOferta->ID<<endl;
		cout<<"Tiempo Valida: "<<tempOferta->tiempoValida<<endl;
		cout<<"Ventanjas: "<<tempOferta->ventajas<<endl;
		
		
		cout<<"\n\n- - - - - - Programas de la Oferta - - - - - - - - \n\n";
		struct ofertaObtenerInformacionPrograma * tempPrograma = tempOferta->ofertaPrimeroSubListaRelacionPrograma;
		if(tempPrograma==NULL){
			cout<<"\nNo existen ofertas relacionadas para esa oferta\n";
			menuReporteResultados();
		}
		else{
		
		
			while(tempPrograma!=NULL){
				cout<<"\n=  =  =  =  =  =\n";
				cout<<"\nNombre: "<<tempPrograma->ofertaEnlacePrograma->nombre<<endl;
				cout<<"Identificacion Programa: "<<tempPrograma->ofertaEnlacePrograma->IDPrograma<<endl;
				cout<<"Precio Programa: "<<tempPrograma->ofertaEnlacePrograma->precio<<endl;
				
				tempPrograma=tempPrograma->sig;
			}
			menuReporteResultados();
		} 
	}
	
}


//numero 6

void imprimirDestinosYProgramasDeUnCircuito(){


	//input: datos ingresados por el usuario
	//output: impresion en pantalla de los programas y los destinos de un circuito en especifico escogido por el usuario
	//restriction:
	//description: realiza un recorrido de la lista principal de circuitos hasta identificar el adecuado, y realiza un recorrido
	//				de la sub listas que posee el nodo, recorriendo los programas y los destinos con los que este relacionado el circuito,
	//				se realiza una impresion de datos durante el recorrido



	int identificacionCircuito;
	cout<<"\nDigite la identificacion del circuito: \n";
	cin>>identificacionCircuito;
	
	struct circuito * tempCircuito = buscarCircuitos(identificacionCircuito);
	
	if(tempCircuito==NULL){
		cout<<"\nEl circuito no existe....Intente de nuevo\n";
		menuReporteResultados();
	}
	
	else{
	
		cout<<"\n-----------------------------------Circuito: ------------------------------------\n\n";
	
		cout<<"Nombre Circuito: "<<tempCircuito->nombre<<endl;
		cout<<"Cantidad Dias: "<<tempCircuito->cantidadDias<<endl;
		cout<<"Identificacion: "<<tempCircuito->IDCircuito<<endl;
		
		
		cout<<"/ / / / / / / Destinos: / / / / / / / / \n\n";
		
		struct circuitoObtenerInformacionDestinos * tempDestino = tempCircuito->circuitoSubListaPrimeroDestinos;
		
		
		if(tempDestino==NULL){
		
			cout<<"ESTA NULO LA LISTA DE DESTINOS";
		}
		
		while(tempDestino!=NULL){
			cout<<"\n-------------------------\n";
			cout<<"Nombre Destino: "<<tempDestino->CircuitoEnlaceDestino->nombre<<endl;
			cout<<"Poblacion: "<<tempDestino->CircuitoEnlaceDestino->poblacion<<endl;
			cout<<"Identificacion: "<<tempDestino->CircuitoEnlaceDestino->ID<<endl;
			cout<<"\n-------------------------\n";
			tempDestino=tempDestino->sig;
		}
		
		cout<<"\n\n/ / / / / / / Programas: / / / / / / / / / \n\n";
		
		struct circuitoObtenerInformacionProgramas * tempPrograma = tempCircuito->circuitoSubListaPrimeroProgramas;
		
		while(tempPrograma!=NULL){
		
			cout<<"\n-------------------------\n";
			cout<<"Nombre Programa: "<<tempPrograma->circuitoEnlacePrograma->nombre<<endl;
			cout<<"Identificacion Programa: "<<tempPrograma->circuitoEnlacePrograma->IDPrograma<<endl;
			cout<<"Precio: "<<tempPrograma->circuitoEnlacePrograma->precio<<endl;
			cout<<"\n-------------------------\n";
			tempPrograma=tempPrograma->sig;
		}
		
		menuReporteResultados();
	}
}

/////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////

//borrar programas
void borrarProgramaEnDestinos(int id){
	
	/*Fecha de inicio: 7/09/2015
	Fecha última modificación: 7/09/2015.
	Descripción: borra el enlace que tiene el destino con el programa a borrar en caso de que el 
	destino esté relacionado con este. recorre todas las sublistas de programas de todos los destinos
	para borrar todos los enlaces de cierto destino a este programa 
	parametro: recibe la identificacion del programa.
	*/
	
	struct destino *tempDestino= primeroDestino;
	while(tempDestino != NULL){
		if(tempDestino->destinoPrimeroSubListaRelacionPrograma == NULL){
		tempDestino= tempDestino->sig;
		break;
	}
	if( tempDestino->destinoPrimeroSubListaRelacionPrograma->destinoEnlacePrograma->IDPrograma == id){
		if(tempDestino->destinoPrimeroSubListaRelacionPrograma->sig != NULL){
			tempDestino->destinoPrimeroSubListaRelacionPrograma=tempDestino->destinoPrimeroSubListaRelacionPrograma->sig;
			struct programa *tt= tempDestino->destinoPrimeroSubListaRelacionPrograma->destinoEnlacePrograma;
		}
		else{
			tempDestino->destinoPrimeroSubListaRelacionPrograma= NULL;
		}
	}
	
	else if(tempDestino->destinoPrimeroSubListaRelacionPrograma->sig != NULL){
		struct DestinoObtenerInformacionPrograma *anterior= tempDestino->destinoPrimeroSubListaRelacionPrograma;
		struct DestinoObtenerInformacionPrograma *actual= tempDestino->destinoPrimeroSubListaRelacionPrograma->sig;	
		
		while(actual->sig != NULL){
			if(actual->destinoEnlacePrograma->IDPrograma == id){
			anterior->sig= actual->sig;
			delete actual;	
			}
			actual= actual->sig;
			anterior= anterior->sig;
		}
		if(actual->destinoEnlacePrograma->IDPrograma == id){
			
			anterior->sig= NULL;
			delete actual;
		}
	}
	tempDestino= tempDestino->sig;	
	}
}

void borrarProgramaEnUsuarios(int id){
	
	/*Fecha de inicio: 8/09/2015
	Fecha última modificación: 8/09/2015.
	Descripción: borra el enlace que tiene el usuario con el programa a borrar en caso de que el 
	usuario esté relacionado con este. recorre todas las sublistas de programas de todos los usuarios
	para borrar todos los enlaces de cierto usuario a este programa 
	parametro: recibe la identificacion del programa.
	*/
	
	struct usuarios *tempUsuario= primerUsuario;
	while(tempUsuario != NULL){
	
	if(tempUsuario->usuarioSubListaPrimeroPrograma != NULL){
	
	if( tempUsuario->usuarioSubListaPrimeroPrograma->usuarioEnlacePrograma->IDPrograma == id){
	if(tempUsuario->usuarioSubListaPrimeroPrograma->sig != NULL){
	tempUsuario->usuarioSubListaPrimeroPrograma =tempUsuario->usuarioSubListaPrimeroPrograma->sig;
	
	}
	else{
	tempUsuario->usuarioSubListaPrimeroPrograma= NULL;
	}
	}
	else if(tempUsuario->usuarioSubListaPrimeroPrograma->sig != NULL){
	struct UsuarioObtenerInformacionPrograma *anterior= tempUsuario->usuarioSubListaPrimeroPrograma;
	struct UsuarioObtenerInformacionPrograma *actual= tempUsuario->usuarioSubListaPrimeroPrograma->sig;	
	
	while(actual->sig != NULL){
	if(actual->usuarioEnlacePrograma->IDPrograma == id){
	anterior->sig= actual->sig;
	}
	actual= actual->sig;
	anterior= anterior->sig;
	}
	if(actual->usuarioEnlacePrograma->IDPrograma == id){
	anterior->sig= NULL;
	}
	}	
	}
	tempUsuario= tempUsuario->sig;	
	}
}

void borrarProgramaEnComentario(int id){
	
	/*Fecha de inicio: 8/09/2015
	Fecha última modificación: 8/09/2015.
	Descripción: borra el comentario que se encuentre asociado al programa a borrar
	de cierto usuario. recorre toda la lista de los usuarios del sistema y la sublista de comentarios
	de cada usuario verificando y borrando los que esten enlazados al programa. 
	parametro: recibe la identificacion del programa.
	*/
	
	struct usuarios *tempUsuario= primerUsuario;
	while(tempUsuario != NULL){
		
	if(tempUsuario->PrimeroComentario != NULL){
	if( tempUsuario->PrimeroComentario->enlaceProgramaComentario->IDPrograma == id){
	if(tempUsuario->PrimeroComentario->sig != NULL){
	tempUsuario->PrimeroComentario =tempUsuario->PrimeroComentario->sig;
		
	}
	else{
	tempUsuario->PrimeroComentario= NULL;
	}
	}
	else if(tempUsuario->PrimeroComentario->sig != NULL){
	struct comentario *anterior= tempUsuario->PrimeroComentario;
	struct comentario *actual= tempUsuario->PrimeroComentario->sig;	
	
	while(actual->sig != NULL){
	if(actual->enlaceProgramaComentario->IDPrograma == id){
	
	anterior->sig= actual->sig;
	
	}	
	actual= actual->sig;
	anterior= anterior->sig;
	}
	if(actual->enlaceProgramaComentario->IDPrograma == id){
	anterior->sig= NULL;	
	}
	}	
	}
	tempUsuario= tempUsuario->sig;	
	}
}

void borrarProgramaEnOfertas(int id){
	
	/*Fecha de inicio: 8/09/2015
	Fecha última modificación: 9/09/2015.
	Descripción: borra el enlace que tiene la oferta con el programa a borrar en caso de que la 
	oferta esté relacionado con este. recorre todas las sublistas de programas de todos las ofertas
	para borrar todos los enlaces de cierta oferta a este programa 
	parametro: recibe la identificacion del programa.
	*/
	
	struct oferta *tempOferta= listaPrincipalOfertas;
	while(tempOferta->sig != listaPrincipalOfertas){	
	if(tempOferta->ofertaPrimeroSubListaRelacionPrograma != NULL){
	if(tempOferta->ofertaPrimeroSubListaRelacionPrograma->ofertaEnlacePrograma->IDPrograma == id){
	if(tempOferta->ofertaPrimeroSubListaRelacionPrograma->sig != NULL){
	tempOferta->ofertaPrimeroSubListaRelacionPrograma =tempOferta->ofertaPrimeroSubListaRelacionPrograma->sig;
	}
	else{
	tempOferta->ofertaPrimeroSubListaRelacionPrograma= NULL;
	}
	}
	else if(tempOferta->ofertaPrimeroSubListaRelacionPrograma->sig != NULL){
	struct ofertaObtenerInformacionPrograma *anterior=tempOferta->ofertaPrimeroSubListaRelacionPrograma;
	struct ofertaObtenerInformacionPrograma *actual= tempOferta->ofertaPrimeroSubListaRelacionPrograma->sig;	
	
	while(actual->sig != NULL){
	if(actual->ofertaEnlacePrograma->IDPrograma == id){
	anterior->sig= actual->sig;
	}	
	actual= actual->sig;
	anterior= anterior->sig;
	}
	if(actual->ofertaEnlacePrograma->IDPrograma == id){
	anterior->sig= NULL;	
	}
	}	
	}
	tempOferta= tempOferta->sig;	
	}
}

void borrarProgramaEnCircuitos(int id){
	
	/*Fecha de inicio: 9/09/2015
	Fecha última modificación: 9/09/2015.
	Descripción: borra el enlace que tiene el circuito con el programa a borrar en caso de que el 
	circuito esté relacionado con este. recorre todas las sublistas de programas de todos los circuitos
	para borrar todos los enlaces de cierto circuito a este programa 
	parametro: recibe la identificacion del programa.
	*/
	
	struct circuito *tempCircuito= listaPrincipalCircuitos;
	while(tempCircuito != NULL){	
	if(tempCircuito->circuitoSubListaPrimeroProgramas != NULL){
	if(tempCircuito->circuitoSubListaPrimeroProgramas->circuitoEnlacePrograma->IDPrograma == id){
	if(tempCircuito->circuitoSubListaPrimeroProgramas->sig != NULL){
	tempCircuito->circuitoSubListaPrimeroProgramas =tempCircuito->circuitoSubListaPrimeroProgramas->sig;
	}
	else{
	tempCircuito->circuitoSubListaPrimeroProgramas= NULL;
	}
	}
	else if(tempCircuito->circuitoSubListaPrimeroProgramas->sig != NULL){
	struct circuitoObtenerInformacionProgramas *anterior=tempCircuito->circuitoSubListaPrimeroProgramas->sig;
	struct circuitoObtenerInformacionProgramas *actual= tempCircuito->circuitoSubListaPrimeroProgramas->sig;	
	
	while(actual->sig != NULL){
	if(actual->circuitoEnlacePrograma->IDPrograma == id){
	anterior->sig= actual->sig;
	break;	
	}	
	actual= actual->sig;
	anterior= anterior->sig;
	}
	if(actual->circuitoEnlacePrograma->IDPrograma == id){
	anterior->sig= NULL;
	}
	}	
	}
	tempCircuito= tempCircuito->sig;	
	}
}

void borrarProgramaEnProgramas(int id){
	
	/*Fecha de inicio: 9/09/2015
	Fecha última modificación: 9/09/2015.
	Descripción: recorre toda la lista de programas del sistema y al encontrar al programa
	es borrado de la lista. 
	parametro: recibe la identificacion del programa.
	*/
	
	if(listaPrincipalProgramas->IDPrograma == id){
	if(listaPrincipalProgramas->sig == NULL){
	listaPrincipalProgramas= NULL;
	}
	else{
	listaPrincipalProgramas= listaPrincipalProgramas->sig;
	}
	}
	struct programa *anterior= listaPrincipalProgramas;
	struct programa *actual= listaPrincipalProgramas->sig;
	
	while(actual->sig != NULL){
	if(actual->IDPrograma == id){
	anterior->sig= actual->sig;	
	}
	actual= actual->sig;
	anterior= anterior->sig;
	}
	if(actual->IDPrograma == id){
	anterior->sig= NULL;
	}
	
}

void borraProgramaXDatos(){
	
	/*Fecha de inicio: 7/09/2015
	Fecha última modificación: 7/09/2015.
	Descripción: pide al usuario los datos necesarios para poder borrar a un programa de la lista de 
	todos los programas del sistema. 
	parametro: ninguno.
	*/
	
	cout<<"\n\n******************* Borrar programas *****************************\n\n";
	int id;
	cout<<"\nIngrese la identificacion del programa que desea borrar: \n";
	cin>>id;
	struct programa *progrmaEncontrado= buscarProgramas(id);
	if(progrmaEncontrado == NULL){
	cout<<"\nERROR. datos inconclusos.\n";
	menu();
	}
	else{
	borrarProgramaEnDestinos(id);
	borrarProgramaEnUsuarios(id);
	borrarProgramaEnComentario(id);
	borrarProgramaEnOfertas(id);
	borrarProgramaEnCircuitos(id);
	borrarProgramaEnProgramas(id);
	cout<<"\nEl programa ha sido borrado exitosamente.\n";
	}
	menu();	
}





/////////////////////////////////////////////////////////////////////////



void menu(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes funciones de todo el sistema. 
	parametro: ninguno.
	*/
	
	int opcion=0;
	cout<<"\n*************************************\n";
	cout<<"1. Mantenimiento de datos\n";
	cout<<"2. Consultas.\n";
	cout<<"3. Reportes de Resultados\n";
	cout<<"opcion: ";
	cin>>opcion;

	if(opcion==1){
	menuMantenimientoDeDatos();
	}
	
	else if(opcion==2){
	menuConsultas();
	}
	
	else if(opcion==3){
	menuReporteResultados();
	}
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menu();
	}	
}


void menuMantenimientoDeDatos(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes acciones en el sistema en el manteni-
	miento de datos. 
	parametro: ninguno.
	*/
	
	int opcion;
	cout<<"\n--  --  --  --  --  --  --  --  --  --  --  --\n";
	cout<<"1. Agregar Datos\n";
	cout<<"2. Eliminar Datos\n";
	cout<<"3. Modificar Datos\n";
	cout<<"4. Atras\n";
	cout<<"opcion:  ";
	cin>>opcion;

	if(opcion==1){	
	menuAgregarDatos();
	}
	
	else if(opcion==2){
	borraProgramaXDatos();
	
	}
	
	else if(opcion==3){	
	cambiarPrecioDePrograma();
	menu();
	
	}
	
	else if(opcion==4){	
	menu();
	}
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menu();
	}	
}


void menuAgregarDatos(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes funciones para agregar datos a las distintas 
	funciones del sistema. 
	parametro: ninguno.
	*/
	
	int opcion;
	
	cout<<"\n--  --  --  --  --  --  --  --  --  --  --  --\n";
	cout<<"1. Agregar Destinos\n";
	cout<<"2. Agregar Ofertas\n";
	cout<<"3. Agregar Programas\n";
	cout<<"4. Agregar Circuitos\n";
	cout<<"5. Agregar Usuarios\n";
	cout<<"6. Agregar nuevo programa para el usuario\n";	
	cout<<"7. Agregar nuevo circuito para el usuario\n";
	cout<<"8. Agregar Comentario\n";
	cout<<"9. Atras\n";
	cout<<"opcion:  ";
	cin>>opcion;

	if(opcion==1){	
	agregarNuevoDestino();
	}
	
	else if(opcion==2){
	menuOfertasDesicionAccion();
	}
	
	else if(opcion==3){	
	pedirDatosIngresoPrograma();
	}
	
	else if(opcion==4){	
	pedirDatosCircuito();	
	}
	
	else if(opcion==5){	
	DatosAgregarNuevoUsuario();
	imprimirUsuariosEnLista();
	}
	
	if(opcion==6){	
	agregarNuevoProgramaDeUsuario();
	}
	
	else if(opcion==7){	
	agregarUnNuevoCircuitoDeUnUsuario();
	menuAgregarDatos();
	}
	
	else if(opcion==8){
	datosAgregarComentario();
	menuAgregarDatos();
		
	}
	
	else if(opcion==9){	
	menu();
	}
	
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menu();
	}	
}

void menuOfertasDesicionAccion(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes funciones de una oferta. 
	parametro: ninguno.
	*/
	
	int opcion;
	cout<<"\n--  --  --  --  --  --  --  --  --  --  --  --\n";
	cout<<"1. Crear Oferta\n";
	cout<<"2. Asignar oferta a programa\n";
	cout<<"3. Atras\n";
	cout<<"opcion: ";
	cin>>opcion;

	if(opcion==1){	
	pedirDatosIngresoOfertas();
	}
	
	
	else if(opcion==2){	
	pedirDatosAsignarOfertasAPrograma();
	}

	else if(opcion==3){	
	menuAgregarDatos();	
	}
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menu();
	}

	
}
void menuConsultas(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes funciones de consultas. 
	parametro: ninguno.
	*/
	
	int opcion;
	cout<<"\n--  --  --  --  --  --  --  --  --  --  --  --\n";
	cout<<"1. Destinos Visitados Por Persona X\n";
	cout<<"2. Comentarios\n";
	cout<<"3. Top Circuitos\n";
	cout<<"4. Cupos de Ofertas Disponibles\n";
	cout<<"5. Atras\n";
	cout<<"opcion:  ";
	cin>>opcion;

	if(opcion==1){
	consultarDestinosVisitadosPorPersona();	
	}
	
	else if(opcion==2){	
	imprimirComentarioDePrograma();
	menu();
	}
	
	else if(opcion==3){	
	circuitosMasEscogidosPorLosUsuarios();
	menu();
	}
	
	else if(opcion==4){	
	imprimirCuposDisponiblesDeOfertas();	
	}
	
	
	else if(opcion==5){	
	menu();
	}
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menuConsultas();
	}	
}

void menuReporteResultados(){
	
	/*Fecha de inicio: 20/08/2015
	Fecha última modificación: 8/09/2015.
	Descripción: menu para poder realizar las diferentes funciones de reporte de resultados. 
	parametro: ninguno.
	*/
	
	int opcion;
	
	cout<<"\n--  --  --  --  --  --  --  --  --  --  --  --\n";
	cout<<"1. Destinos Disponibles\n";
	cout<<"2. Lista de Programas Segun Destino\n";
	cout<<"3. Ofertas Disponibles\n";
	cout<<"4. Lista de Programas Segun Ofertas\n";
	cout<<"5. Circuitos Disponibles\n";
	cout<<"6. Lista de destinos del Circuitos y su programa\n";
	cout<<"7. Atras\n";

	cout<<"opcion:  ";
	cin>>opcion;

	if(opcion==1){	
	imprimirAdYAtDestinos();
	menuReporteResultados();
	}
	
	else if(opcion==2){
	imprimirListaDeProgramasSegunDestino();
	
	}
	
	else if(opcion==3){	
	imprimirListaOfertas();	
	menuReporteResultados();
	}
	
	else if(opcion==4){	
	imprimirProgramasDeOferta();	
	}
	
	else if(opcion==5){	
	imprimirListaCircuitos();
	menuReporteResultados();	
	}
	
	else if(opcion==6){
	imprimirDestinosYProgramasDeUnCircuito();	
	}
	
	else if(opcion==7){	
	menu();
	}
	
	else{
	cout<<"\n\nDigite lo que esta en pantalla\n";	
	menu();
	}	
}

int main() {
	datosAgregadosDeDestinos();
	cargarListasProgramas();
	cargarListasOfertas();
	usuariosAgrgadosPorDefecto();
	cargarDatosCircuitos();
	listaDeComentariosPorDefecto();
	circuitoDeUsuarioAgregadoPorDefecto();
	agregarPorDefectoProgramaDeUsuario();
	
	menu();
	
	
	return 0;
	
}

