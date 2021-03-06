#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Funciones.h"
#define TRUE 0
#define FALSE 1
#define TAM 10
int main(void) {
	setbuf(stdout,NULL);

	char Empresa[10];
	char Localidad[10];
	char Direccion[10];
	int Cuit;
	int polipropileno ;
	int id=0;
	int idModificar;
	int idEliminar;
	Clientes muestra[TAM];
	Pedido clientes[TAM];
	InicializarClientes( muestra, clientes, TAM);
	int opcion;

	SelecionarMenu();
	do{
	scanf("%d",&opcion);



		switch (opcion) {
			case 1:

				id++;

				printf("Ingresar La Empresa ");
				fflush(stdin);
				gets(Empresa);

				printf("Ingresar la localidad ");
				fflush(stdin);
				gets(Localidad);

				printf("Ingresar la Direccion ");
				fflush(stdin);
				gets(Direccion);

				printf("Ingresar el cuit ");
				fflush(stdin);
				scanf("%d",&Cuit);

				if(AniadirCliente(muestra, TAM, id, Empresa, Localidad,Cuit,Direccion) == 0){
					puts("cliente cargado exitosamente");
				}else {
					puts("no se puedo ingresar exitosamente");
				}

			break;

			case 2:
				MostrarDatos(muestra, TAM);

				printf("Ingrese el id del cliente que quiere modificar: ");
				fflush(stdin);
				scanf("%d",&idModificar);
				ModificarDatosCliente(muestra,  TAM, idModificar);


			break;
			case 3:
				printf("Ingrese el id del cliente que quiere eliminar: ");
				fflush(stdin);
				scanf("%d",&idEliminar);
				ElimiarCliente(muestra,  TAM, idEliminar);
			break;

			case 4:
				MostrarDatos(muestra, TAM);


				PedidoRecoleccion( muestra,clientes, TAM);

				break;
			case 5:
				MostrarPedidosPendientes(muestra, clientes, TAM);
				polipropileno  =ProcesarResiduos(muestra,  clientes, TAM);
				break;

			case 6:

				ImprimirClientes(muestra, clientes, TAM);
			break;

			case 7:

				MostrarPedidosPendientes(muestra, clientes, TAM);
				break;
			case 8:
				MostrarPedidosProcesados(muestra, clientes, TAM);
				break;
			case 9:
				MostrarPorDireccion(muestra,  clientes,TAM);

				break;
			case 10:

				PromedioCliente( muestra, clientes, id, polipropileno);
				break;


		}





	}while(opcion != 11);

	return EXIT_SUCCESS;
}

