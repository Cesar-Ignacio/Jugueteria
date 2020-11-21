#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <limits>

using namespace std;

const char *ARCHIVO_VENTAS_DETALLES={"DETALLES.dat"};
const char *ARCHIVO_VENTAS={"ventas.dat"};
const char *ARCHIVO_ARTICULOS={"articulos.dat"};
const char *ARCHIVO_CLIENTES={"clientes.dat"};
const char *ARCHIVO_EMPLEADOS={"empleados.dat"};
const char *ARCHIVO_COMPRAS={"compras.dat"};


const char *ARCHIVO_BKP_VENTAS_DETALLES={"detalles.BKP"};
const char *ARCHIVO_BKP_VENTAS={"ventas.BKP"};
const char *ARCHIVO_BKP_ARTICULOS={"articulos.BKP"};
const char *ARCHIVO_BKP_CLIENTES={"clientes.BKP"};
const char *ARCHIVO_BKP_EMPLEADOS={"empleados.BKP"};
const char *ARCHIVO_BKP_COMPRAS={"compras.BKP"};


#include "GOTOXY.h"
#include "COLOR.h"
#include "LETRAS.h"
#include "CUADRO.h"
#include "CUADROS&LETRAS.h"
#include "VALIDAR NUMERO.h"
#include "VALIDAR FECHA.h"


#include "CLASES.h"
#include "PROTOTIPOS.h"
#include "FUNCIONES.h"
#include "SUBMENUS.h"



int main()
{
   system("mode con: cols=123 lines=31");

    int opc=1;

    while(opc!=0)
    {
        system("cls");

       TITULO_MENU_PRINCIPAL();

       gotoxy(60,14);cout<<"MENU"<<endl;

       gotoxy(20,15);cout<<"1- VENTAS "<<endl;
       gotoxy(20,20);cout<<"2- ARTICULOS"<<endl;
       gotoxy(20,25);cout<<"3- COMPRAS "<<endl;
       gotoxy(90,15);cout<<"4- CLIENTES"<<endl;
       gotoxy(90,20);cout<<"5- EMPLEADOS"<<endl;
       gotoxy(90,25);cout<<"6- REPORTES"<<endl;
       gotoxy(53,25);cout<<"7- CONFIGURACIONES"<<endl;
       gotoxy(52,18);cout<<"OPCION:";
       opc=validarnumero(60,18,0,7,1,52,22);

       if(opc==1)
       {

          MENU_VENTAS();
       }
       if(opc==2)
       {
          MENU_ARTICULOS();
       }
       if(opc==3)
       {
          MENU_COMPRAS();
       }
       if(opc==4)
       {
          MENU_CLIENTES();
       }
       if(opc==5 && VerificarContrasenia()==1)
       {
         MENU_EMPLEADOS();
       }
       if(opc==6 && VerificarContrasenia()==1)
       {
         MENU_REPORTES();
       }
       if(opc==7 && VerificarContrasenia()==1)
       {
         MENU_CONFIGURACIONES();
       }

    }



    ///system("pause>null");
    gotoxy(0,28);return 0;
}
