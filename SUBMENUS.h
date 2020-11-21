#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED



///FUNCIONES


void MENU_VENTAS()
{
    int opc=1;


    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_VENTA();


        gotoxy(56,14);cout<<"MENU VENTAS"<<endl;

        gotoxy(18,17);cout<<"1- NUEVA VENTA"<<endl;
        gotoxy(41,17);cout<<"2- MOSTRAR VENTAS"<<endl;
        gotoxy(64,17);cout<<"3- ELIMINAR VENTA"<<endl;
        gotoxy(87,17);cout<<"0- VOLVER ATRAS"<<endl;
        gotoxy(55,20);cout<<"OPCION:";
        opc=validarnumero(63,20,0,3,1,55,22);

        if(opc==1)
        {

          NuevaVenta();
        }
        if(opc==2)
        {
          MostraVentas();
        }
        if(opc==3)
        {
          EliminarVentaCompleta();
        }

    }

    system("cls");

}

void MENU_ARTICULOS()
{



    int opc=1;

    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_ARTICULOS();

        gotoxy(55,14);cout<<"MENU ARTICULOS"<<endl;

        gotoxy(20,15);cout<<"1-NUEVO ARTICULO"<<endl;
        gotoxy(20,20);cout<<"2-MODIFICAR "<<endl;///MODIFICAR PRECIO
        gotoxy(90,15);cout<<"3-LISTAR ARTICULOS "<<endl;/// LISTAR TAMBIEN LOS ART CON STCOK MIN Y MAX
        gotoxy(90,20);cout<<"4-ELIMINAR ARTICULO"<<endl;
        gotoxy(55,20);cout<<"0-VOLVER ATRAS:"<<endl;
        gotoxy(54,25);cout<<"OPCION:";
        cin>>opc;

        if(opc==1)
        {

         NuevoArticulo();
        }
        if(opc==2)
        {
           ModificarArticulo();
        }
        if(opc==3)
        {
           ListarArticulos();
        }
        if(opc==4)
        {
            EliminarArticulo();
        }

    }


    cout<<"VOLVIENDO"<<endl;

    Sleep(400);

    system("cls");
}

void MENU_COMPRAS()
{
    int opc=1;

    while(opc!=0)
    {

    system("cls");

    TITULO_MENU_COMPRAS();

    gotoxy(56,14);cout<<"MUNU COMPRAS"<<endl;

    gotoxy(20,15);cout<<"1- NUEVO PEDIDO"<<endl;
    gotoxy(20,20);cout<<"2- MODIFICAR "<<endl;
    gotoxy(90,15);cout<<"3- LISTAR"<<endl;
    gotoxy(90,20);cout<<"4- ELIMINAR PEDIDO"<<endl;
    ///cout<<"4- ARTICULOS ESCASOS"<<endl;
    gotoxy(52,18);cout<<"5- DEPIDOS COMPRADOS"<<endl;///HACER LUEGO
    gotoxy(54,21);cout<<"0- VOLVER ATRAS"<<endl;

    gotoxy(55,24);cout<<"OPCION:";
    opc=validarnumero(62,24,0,5,1,58,26);

    if(opc==1)
    {
      NuevoPedido();
    }
    if(opc==2)
    {
      ModificarPedido();
    }
    if(opc==3)
    {
      ListarPedidos();
    }
    if(opc==4)
    {
      EliminarPedido();
    }
    if(opc==5)
    {
      PedidosComprados();
    }


    }///fin while


    cout<<"VOLVIENDO"<<endl;

    Sleep(400);

    system("cls");

}

void MENU_CLIENTES()
{
    int opc=1;



    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_CLIENTE();

        gotoxy(55,14);cout<<"MENU CLIENTES"<<endl;

        gotoxy(20,15);cout<<"1- NUEVO CLIENTE"<<endl;
        gotoxy(20,20);cout<<"2- MODIFICAR"<<endl;
        gotoxy(90,15);cout<<"3- LISTAR"<<endl;
        gotoxy(90,20);cout<<"4- ELIMINAR CLIENTE"<<endl;
        gotoxy(55,20);cout<<"0- VOLVER ATRAS"<<endl;
        gotoxy(55,25);cout<<"OPCIONES:";
        opc=validarnumero(64,25,0,4,1,58,28);

        if(opc==1)
        {
           NuevoCliente();
        }
        if(opc==2)
        {
           ModificarCliente();
        }
        if(opc==3)
        {
           ListarCliente();
        }
        if(opc==4)
        {
           EliminarCliente();
        }

    }






    cout<<"VOLVIENDO"<<endl;
    Sleep(400);

    system("cls");
}

void MENU_EMPLEADOS()
{
   system("cls");


    int opc=1;

    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_EMPLEADO();

        gotoxy(55,14);cout<<"MENU EMPLEADOS"<<endl;

        gotoxy(20,15);cout<<"1- NUEVO EMPLEADO"<<endl;
        gotoxy(20,20);cout<<"2- MODIFICAR"<<endl;
        gotoxy(90,15);cout<<"3- LISTAR"<<endl;
        gotoxy(90,20);cout<<"4- ELIMNAR EMPLEADO"<<endl;
        gotoxy(55,20);cout<<"0- VOLVER ATRAS"<<endl;
        gotoxy(55,25);cout<<"OPCION:";
        opc=validarnumero(63,25,0,4,1,55,28);

        if(opc==1)
        {
         NuevoEmpleado();
        }
        if(opc==2)
        {
         ModificarEmpleado();
        }
        if(opc==3)
        {
         ListarEmpleado();
        }
        if(opc==4)
        {
         EliminarEmpleado();
        }

    }


   cout<<"VOLVIENDO"<<endl;
    Sleep(400);

    system("cls");


}

void MENU_REPORTES()
{
    system("cls");

    int opc=1;


    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_REPORTES();

        gotoxy(56,11);cout<<"MENU REPORTES"<<endl;

        gotoxy(56,14);cout<<"1- REPORTE_1"<<endl;
        gotoxy(72,14);cout<<"2- REPORTE_2"<<endl;
        gotoxy(87,14);cout<<"3- REPORTE_3"<<endl;
        gotoxy(56,17);cout<<"4- REPORTE_4"<<endl;
        gotoxy(72,17);cout<<"5_ REPORTE_5"<<endl;
        gotoxy(86,24);cout<<"0- VOLVER ATRAS"<<endl;

        gotoxy(55,24);cout<<"OPCION:";
        opc=validarnumero(62,24,0,5,1,55,28);

        if(opc==1)
        {
         ImporteAhora();
        }
        if(opc==2)
        {
         CantidadImporteXvendedor();
        }
        if(opc==3)
        {
         ImporteFecha();
        }
        if(opc==4)
        {
         ArticuloMasVendido();
        }
        if(opc==5)
        {
         ClienteConMasCompras();
        }

    }



    cout<<"VOLVIENDO"<<endl;
    Sleep(400);

    system("cls");


}

void MENU_CONFIGURACIONES()
{
        int opc=1;

    while(opc!=0)
    {
        system("cls");

        TITULO_MENU_CONFIGURACIONES();

        gotoxy(52,14);cout<<"MENU CONFIGURACIONES"<<endl;

        gotoxy(20,15);cout<<"1- REALIZAR BACKUP"<<endl;
        gotoxy(20,20);cout<<"2- RESTAURAR BACKUP"<<endl;
        gotoxy(90,15);cout<<"3- ALTA CLIENTE "<<endl;
        gotoxy(90,20);cout<<"4- ALTA EMPLEADO "<<endl;
        gotoxy(55,17);cout<<"5- CONTRASENIA"<<endl;
        gotoxy(55,20);cout<<"0- VOLVER ATRAS"<<endl;

        gotoxy(55,25);cout<<"OPCION:";
        opc=validarnumero(63,25,0,5,1,55,28);

        if(opc==1)
        {
          CopiaSeguridad();
        }
        if(opc==2)
        {
          RestablerCopia();
        }
        if(opc==3)
        {
          AltaClinete();
        }
        if(opc==4)
        {
          AltaEmpleado();
        }
        if(opc==5)
        {
         CambiarContrasenia();
        }

    }

    cout<<"VOLVIENDO"<<endl;
    Sleep(400);

    system("cls");

}

#endif // SUBMENUS_H_INCLUDED
