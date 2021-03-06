#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Funciones.h"
#define TRUE 0
#define FALSE 1
#define TAM 10

void SelecionarMenu(void){

	setbuf(stdout,NULL);

	printf("ingrese una opcion \n");
	printf("[1] - DAR DE ALTA \n");
	printf("[2] - MODIFICAR DATOS \n");
	printf("[3] - ELIMINAR ID \n");
	printf("[4] - CREAR PEDIDO DE RECOLECCION  \n");
	printf("[5] -  PROCESAR PEDIDOS \n");
	printf("[6] -  MOSTRAR LOS CLIENTES QUE DEBEN \n");
	printf("[7] -  MOSTRAR LOS PEDIDOS PENDIENTES \n");
	printf("[8] -  MOSTRAR LOS PEDIDOS PROCESADOS \n \n");
	printf("[9] -  MOSTRAR LOS PEDIDOS POR DIRECCION  \n");
	printf("10 \n");

}


int InicializarClientes(Clientes* muestra, Pedido* clientes, int tam){

	setbuf(stdout,NULL);

	int retorno;
	retorno = -1;

	if(muestra != NULL && tam>=0 && clientes !=NULL ){
		for (int i = 0; i < tam; i++) {
			muestra[i].isEmpty = TRUE;
			clientes[i].isEmpty = TRUE;
			clientes[i].PedidosCompletados = 0;
			clientes[i].PedidosPendientes=0;

		}
		retorno = 0;
	}


	return retorno;

}

//1--------------------------------------------------------------------------------------------------------!!
int AniadirCliente(Clientes* muestra, int tamanio, int id, char empresa[],char localidad[], int cuit, char direccion[]){
	 setbuf(stdout,NULL);
	int retorno ;
	retorno = -1;

	if(muestra != NULL && tamanio >= 0 && id >= 0){

     for ( int i = 0;  i < tamanio; ++ i) {
    	 if( muestra[i].isEmpty == TRUE ){

			muestra[i].idCliente = id;
			strcpy(muestra[i].Empresa, empresa);
			strcpy(muestra[i].localidad, localidad);
			strcpy(muestra[i].direccion, direccion);
			muestra[i].cuit = cuit;
			muestra[i].isEmpty = FALSE;

			retorno = 0;

			break;

			}
		}
	}

return retorno;
}
//--------------------------------------------------------------------------------------------------------!!
void MostrarDatos(Clientes* muestra, int tamanio){
	if(muestra != NULL && tamanio >= 0 ){
	for ( int i = 0;  i < tamanio;  i++) {

		if(muestra[i].isEmpty == FALSE){
			printf("El ID  %d \n",muestra[i].idCliente);
			printf("El nombre del Cliente es %s \n",muestra[i].Empresa);
			printf("La localidad del Cliente es %s \n",muestra[i].localidad);
			printf("La direccion del Cliente es %s \n",muestra[i].direccion);
			printf("El cuit del Cliente es %d \n",muestra[i].cuit);


		}

	 }
	}
}



//2--------------------------------------------------------------------------------------------------------!!
void ModificarDatosCliente(Clientes* muestra, int tam, int idModificar){


	for ( int i = 0;  i < tam;  i++) {
		if(muestra[i].idCliente == idModificar){
			printf("ingrese la nueva direccion");
			fflush(stdin);
			gets(muestra[i].direccion);

			printf("ingrese la nueva localidad");
			fflush(stdin);
			gets(muestra[i].localidad);
		}

	}

}

//3--------------------------------------------------------------------------------------------------------!!
void ElimiarCliente(Clientes* muestra, int tam, int idEliminar){
	int Respuesta;
	for ( int i = 0;  i < tam;  i++) {

		if(muestra[i].idCliente == idEliminar){
			printf("Esta seguro que quiere eliminar? 1- si  2- no");
			fflush(stdin);
			scanf("%d",&Respuesta);

			if(Respuesta == 1){

				muestra[i].isEmpty = TRUE;
		}else {
			puts("no se elimino .... ");
		}


		}
	}



}

//4--------------------------------------------------------------------------------------------------------!!
int PedidoRecoleccion(Clientes* muestra, Pedido* clientes, int tam ){
	int retorno;
	int id;
	int kilos;
	int kilosNuevos;
	retorno = 0;
	if(muestra != NULL &&  tam >= 0 ){

		printf("Ingrese el id : ");
		fflush(stdin);
		scanf("%d",&id);




		for ( int i = 0;  i < tam;  i++) {

			if(clientes[i].isEmpty == TRUE && muestra[i].idCliente == id){


				printf("Ingrese los kilos : ");
				fflush(stdin);
				scanf("%d",&kilos);

				clientes[i].idCliente = id;
				clientes[i].idCliente = id;
				clientes[i].kilos = kilos;
				clientes[i].PedidosPendientes = 1;
				clientes[i].isEmpty = FALSE ;
				retorno = 1 ;

				break;

			}else{
				if(clientes[i].isEmpty == FALSE && clientes[i].idCliente == id  ) {
					printf("Ingrese los kilos : ");
					fflush(stdin);
					scanf("%d",&kilosNuevos);

					clientes[i].kilos += kilosNuevos;
					clientes[i].PedidosPendientes ++;
				}

			}
		}


}
	return retorno;
}
//6--------------------------------------------------------------------------------------------------------!!
void ImprimirClientes(Clientes* muestra, Pedido* clientes, int tam){



	if(muestra != NULL &&clientes!= NULL && tam >= 0 ){


		for ( int i = 0;  i < tam;  i++) {
			if(clientes[i].isEmpty == FALSE && muestra[i].isEmpty == FALSE){

				MostrarDatos(muestra,  tam);
				puts("\n");
				printf("lA ID RECOLECCION ES %d \n",clientes[i].idCliente);
				printf("LOS PEDIDOS PENDIENTES SON  %d \n",clientes[i].PedidosPendientes);
				puts("ESTADO ES ****PENDIENTE**** \n");
				puts("\n-----------------------------------------------------");



		}
		}


	}



}
//7--------------------------------------------------------------------------------------------------------!!
void MostrarPedidosPendientes(Clientes* muestra, Pedido* clientes, int tam){

	if(muestra != NULL &&clientes!= NULL && tam >= 0 ){


		for ( int i = 0;  i < tam;  i++) {
			if(clientes[i].isEmpty == FALSE && muestra[i].isEmpty == FALSE){


				printf("\nEl ID  %d \n",muestra[i].idCliente);
				printf("El CUit del cliente es %d \n",muestra[i].cuit);
				printf("La direccion  del cliente es %s \n",muestra[i].direccion);
				printf("los kilos totales que debe es de %d \n",clientes[i].kilos);


		}
		}


	}

}
//9--------------------------------------------------------------------------------------------------------!!
void MostrarPorDireccion(Clientes* muestra, Pedido* clientes, int tam){

	char direccion[20];
	int i;
	int SumaPedidos = 0;


	printf("ingrese la direccion");
	fflush(stdin);
	gets(direccion);

	for (i = 0; i < tam; i++) {

		if(strcmp(muestra[i].direccion, direccion)==0){
			SumaPedidos += clientes[i].PedidosPendientes;
			break;

		}else{
			if(strcmp(muestra[i].direccion, direccion)!=0){
			puts("No existe nadie con esa Direccion");
			break;
			}
		}

	}

	if(SumaPedidos>0){
	printf("LOS PEDIDOS PENDIENTES CON ESA DIRECCION SON  %d \n",SumaPedidos);
	}else{
		if(SumaPedidos<=0){

		puts("LOS PEDIDOS PENDIENTES CON ESA DIRECCION SON  CERO \n");
	}

	}
	}

int ProcesarResiduos(Clientes* muestra, Pedido* clientes, int tam){

	int id;
	int i;
	int kilosAuxiliar;
	int prolipropileno=0 ;
	int kilosalta;
	int kilosBAJA;
	int KilosTOTALTOTAL;

	int kilosTotales;




	printf("ingresar el id del pedido a Procesar");
	scanf("%d",&id);

	for (i = 0; i < tam; ++i) {
		if (clientes[i].isEmpty == FALSE && clientes[i].idCliente==id){


			kilosTotales = clientes[i].kilos;

			kilosalta = IngresarEntero("ingrese la cantidad de polietileno de alta Intensidad",0,kilosTotales) ;
			KilosTOTALTOTAL = kilosTotales-kilosalta;
			printf("Cantidad de Kilos restantes %d \n",KilosTOTALTOTAL);


			kilosBAJA= IngresarEntero("ingrese la cantidad de polietileno de Baja Intensidad",0,KilosTOTALTOTAL )  ;
			KilosTOTALTOTAL -= kilosBAJA;
			printf("Cantidad de Kilos restantes %d \n",KilosTOTALTOTAL);

			kilosAuxiliar = IngresarEntero("ingrese la cantidad de prolipropileno",0,KilosTOTALTOTAL) ;
			KilosTOTALTOTAL -= kilosAuxiliar;
			prolipropileno += KilosTOTALTOTAL;
			printf("Cantidad de Kilos restantes %d \n",KilosTOTALTOTAL );

			clientes[i].isEmpty = TRUE;
			clientes[i].kilos = TRUE;
			clientes[i].estado = FALSE;
			clientes[i].PedidosPendientes = 0;
			clientes[i].PedidosCompletados ++;






		}
		}
return prolipropileno ;
	}

//8--------------------------------------------------------------------------------------------------------!!
void MostrarPedidosProcesados(Clientes* muestra, Pedido* clientes, int tam){
	if(muestra != NULL && clientes!= NULL && tam >= 0 ){
	for (int i = 0; i < tam; ++i) {
		if (clientes[i].PedidosCompletados>=0 && clientes[i].isEmpty == TRUE && clientes[i].estado == FALSE){



			printf("el id %d \n",clientes[i].idCliente);
			printf("los pedidos prosesados son %d \n",clientes[i].PedidosCompletados);
			break;




		}else{
			printf("NO TIENE PEDIDOS PROCESADOS \n");
			break;
		}
		}

		}
	}

//10--------------------------------------------------------------------------------------------------------!!
void PromedioCliente(Clientes* muestra, Pedido* clientes, int cantidadCliente,int polipropileno){

	float promedio;
	promedio = (float)cantidadCliente /(float) polipropileno;

	printf("El promedio del polipropileno por cliente es de: %f",promedio);




}
//--------------------------------------------------------------------------------------------------------!!
int IngresarEntero(char mensaje[],int min,int max)
{
    setbuf(stdout, NULL);

    int numero;

    do{
    printf(mensaje);

    scanf("%d",&numero);
    }while(numero <= min || numero >= max);

    return numero;
}
