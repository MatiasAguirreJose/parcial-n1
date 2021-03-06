#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define TRUE 0
#define FALSE 1
struct{
	 int idCliente ;
	 char Empresa[21];
	 char localidad[21];
	 int cuit;
	 char direccion[21];;
	 int isEmpty;
}typedef Clientes;

struct{
	int idRecoleccion;
	int idCliente;
	int  flag;
	int PedidosPendientes;
	int PedidosCompletados;
	int estado;
	int kilos;
	int isEmpty;
	int promedioCliente;
}typedef Pedido;

void SelecionarMenu(void);

int AniadirCliente(Clientes* muestra, int tamanio, int id, char empresa[],char localidad[], int cuit, char direccion[]);
void MostrarDatos(Clientes* muestra, int tamanio);
int InicializarClientes(Clientes* muestra, Pedido* clientes, int tam);
void ModificarDatosCliente(Clientes* muestra, int tam, int idModificar);
void ElimiarCliente(Clientes* muestra, int tam, int idEliminar);
int PedidoRecoleccion(Clientes* muestra, Pedido* clientes, int tam );
void ImprimirClientes(Clientes* muestra, Pedido* clientes, int tam);
void MostrarPedidosPendientes(Clientes* muestra, Pedido* clientes, int tam);
void MostrarPorDireccion(Clientes* muestra, Pedido* clientes, int tam);
int ProcesarResiduos(Clientes* muestra, Pedido* clientes, int tam);
void MostrarPedidosProcesados(Clientes* muestra, Pedido* clientes, int tam);
/// \brief Se pide el promedio.
/// \param
/// \param numMin int
/// \param numMax int
/// \return int Retorna el numero enviado;
void PromedioCliente(Clientes* muestra, Pedido* clientes, int cantidadCliente,int polipropileno);
/// \brief Se pide un numero entero.
/// \param mensaje[] char
/// \param numMin int
/// \param numMax int
/// \return int Retorna el numero enviado;
int IngresarEntero(char mensaje[],int min,int max);
