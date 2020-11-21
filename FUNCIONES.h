#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



///FUNCINES  VENTAS

void NuevaVenta()
{
  system("cls");

    VENTADETALLADA obj1[20];

    VENTAS obj2;

    ARTICULOS obj3;

    CUADROS_NUEVA_VENTA();

    int dniC,dniV,codigoA,x=0,opc=0,cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));

    float importe;


    gotoxy(12,7);cout<<"ID VENTA:"<<cantreg+1<<endl;

    gotoxy(12,10);cout<<"DNI CLI:";

    dniC=ValidarC();

    if(dniC==0)
    {
        system("cls");
        Error(1,55,15);
        return ;
    }

    obj2.setidventa(cantreg+1);
    obj2.setidcliente(dniC);

    gotoxy(12,13);cout<<"DNI VEN:";

    dniV=ValidarE();///EL EMPLEADO DEBE SABER SU DNI

    obj2.setvendedor(dniV);

    obj2.Cargar();

     while(x<20)
    {
        gotoxy(47,7);cout<<"ID VENTAS:"<<cantreg+1<<endl;
        gotoxy(47,10);cout<<"COD_ARTI:";
        codigoA=ValidarA(56,10);

        obj3.leerArticulo(BuscarCodigoArticulo(codigoA));

        obj1[x].setidventa(cantreg+1);
        obj1[x].setarticulo(codigoA);
        obj1[x].setprecio(obj3.getprecio());

        CompraCorrecta(obj1[x],obj3);

        obj3.grabarModificacionArticulo(BuscarCodigoArticulo(codigoA));

        importe+=obj1[x].getimporte();

        mostrarcompras(obj1,x+1);

        gotoxy(20,19);cout<<"       "<<endl;///BORRA IMPORTE CUADRO PRIMERO
        gotoxy(20,19);cout<<importe<<endl;

        opc=validarnumero(60,26,0,2,1,60,28);

        if(opc==2)
        {
         EliminarCompraVenta(obj1,&importe);

        gotoxy(20,19);cout<<"       "<<endl;///BORRA IMPORTE CU P
        gotoxy(20,19);cout<<importe<<endl;

        opc=validarnumero(60,26,0,1,1,60,28);

        }
        if(opc==1)
        {
         importe=guardarVentas(obj1,x+1);
          x=30;
        }
        if(opc==0)
        {
          x++;
        }
    }
    obj2.setimporte(importe);
    obj2.grabarVenta();

    system("pause>null");
    system("cls");
}

void mostrarcompras(VENTADETALLADA *vobj,int tam)
{
     int py=6;

    for(int x=0;x<tam;x++)
    {
       if(vobj[x].getestado()==1)
       {
          gotoxy(82,py);cout<<x+1<<":"<<"CODI_ART:"<<vobj[x].getarticulo()<<":"<<"IMPORTE:"<<vobj[x].getimporte()<<endl;
          py++;
       }

    }

}

float guardarVentas(VENTADETALLADA *obj,int tam)
{
    float importe=0;

    for(int x=0;x<tam;x++)
    {
        if(obj[x].getestado()==1)
        {
          importe=importe+obj[x].getimporte();

          obj[x].GrabarVentaDetallada();


        }

    }
    return importe;
}

void  EliminarCompraVenta(VENTADETALLADA *obj,float *importe)
{
     int numcompr,pos;

     ARTICULOS objA;


    gotoxy(81,20);cout<<"INGRESE NUMERO DE COMPRA:";
    cin>>numcompr;

   if(obj[numcompr-1].getestado()==1)
   {
    obj[numcompr-1].setestado(0);

    *importe=*importe-obj[numcompr-1].getimporte();



    pos=BuscarCodigoArticulo(obj[numcompr-1].getarticulo());

    objA.leerArticulo(pos);

    objA+=obj[numcompr-1].getcantidad();

    objA.grabarModificacionArticulo(pos);


   }

}

void MostraVentas()
{
    system("cls");
    VENTAS obj;
    VENTADETALLADA obj2;

    int cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));
    int cantreg2=cantidadReg(ARCHIVO_VENTAS_DETALLES,sizeof(VENTADETALLADA));

    cuadro(5,2,2,5+50,9,0);///CUADRO CONTENDOR

    LOGO();

   color("",12);
   gotoxy(25,2);cout<<"LISTADO DE LAS VENTAS"<<endl;
   color("",7);

   int py=8;

   for(int x=0;x<cantreg;x++)
   {

       obj.leerVenta(x);

       if(obj.getestado()==1)
       {

        CUADRO_LISTA_VENTAS(py-2);
        obj.Mostrar(py);
        py=py+3;

       for(int z=0;z<cantreg2;z++)
       {
           obj2.LeerVentaDetallada(z);

           if(obj==obj2)
           {
            obj2.Mostrar(py);
            py+=2;
           }
       }
       py=py+4;
       }

   }

   system("pause>null");
   system("cls");
}

void EliminarVentaCompleta()
{
  system("cls");

  VENTAS obj;
  VENTADETALLADA objVD;
  int idventa,cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS)),cantregVd=cantidadReg(ARCHIVO_VENTAS_DETALLES,sizeof(VENTADETALLADA));

  CUADRO_ELIMINACION_VENTA();

  gotoxy(47,10);cout<<"ID DE VENTA:";
  idventa=validarnumero(59,10,1,1000,4,58,15);

  for(int x=0;x<cantreg;x++)
  {
        obj.leerVenta(x);

        if(obj.getIDventa()==idventa && obj.getestado()==1)
        {
            obj.setestado(0);
            obj.grabarModificacionVenta(x);

            for(int z=0;z<cantregVd;z++)
            {
              objVD.LeerVentaDetallada(z);

              if((objVD==idventa)==1 && objVD.getestado()==1)
              {
                  objVD.setestado(0);
                  objVD.GrabarModificacionVentaDetallada(z);
              }

            }

            gotoxy(50,15);cout<<"SE ELIMINO LA VENTA"<<endl;
            system("pause>null");
            return ;
        }
  }

  gotoxy(49,15);cout<<"NO SE ENCONTRO EL REG"<<endl;

  system("pause>null");
  system("cls");

}

void CompraCorrecta(VENTADETALLADA &objV, ARTICULOS &objA)
{
        int cantidad=0,cantREALES=0;

        gotoxy(56,19);cout<<"          "<<endl;///BORRAMOS IMPORTE ANTERIOR
        objV.Cargar();

        if(objV.getcantidad()<=objA.getcantidad())
        {
        objA-=objV.getcantidad();

        }
        else if(objV.getcantidad()>objA.getcantidad())
        {

            Error(3,50,28);
            gotoxy(52,29);cout<<"CANT STOCK DISPO:"<<objA.getcantidad()<<endl;

            cantREALES=objA.getcantidad();

            cantidad=validarnumero(56,16,1,cantREALES,2,55,28);

            objV.setcantidad(cantidad);

            objA-=objV.getcantidad();

            objV.setimporte(cantidad*objA.getprecio());
             gotoxy(52,29);cout<<"                  "<<endl;///BARRAMOS CARTEL
            gotoxy(56,19);cout<<"          "<<endl;///BORRAMOS IMPORTE ANTERIOR
            gotoxy(47,19);cout<<"IMPORTE :"<<cantidad*objA.getprecio()<<endl;

        }


        gotoxy(56,13);cout<<"          "<<endl;///BORRA PRECIO CU SE

}


///FUNCIONES ARTICULOS

void  NuevoArticulo()
{
    system("cls");

    CUADRO_NUEVO_ARTICULO();

    int codigoA;

    ARTICULOS obj;

    gotoxy(22,4);cout<<"CODIGO DE ARTICULO:";
    codigoA=validarnumero(41,4,1000,9999,4,55,28);

    while(BuscarCodigoArticulo(codigoA)!=-1)
    {
    Error(4,55,28);
    gotoxy(22,4);cout<<"CODIGO DE ARTICULO:";
    codigoA=validarnumero(41,4,1000,9999,4,55,28);
    }
    obj.setcodigoArticulo(codigoA);

    obj.grabarArticulo();


    system("pause>null");
    system("cls");


}

void ModificarArticulo()
{
    system("cls");

    CUADRO_MODIFICACION();

    int opc=0;


    opc=validarnumero(69,10,1,2,1,57,19);

    if(opc==1)
    {
        CambiarPrecio();
    }
    if(opc==2)
    {
        CambiarPrecioTodos();
    }

    system("pause>null");
    system("cls");

}

void ListarArticulos()
{


    ///Munu_Lista_Articulos();

   int opc=1;

    while(opc!=0)
   {
    system("cls");

    cout<<"MENU LISTA"<<endl;
    cout<<"*********"<<endl;
    cout<<"1- LISTA SECUENCIAL"<<endl;
    cout<<"2- LISTA FAMILIA"<<endl;
    cout<<"3- ARTICULOS CON STOCK POR DEBAJO DEL MINIMO"<<endl;
    cout<<"4- ARTICULOS CON STOCk POR ARRIBA DEL MAXIMO"<<endl;
    cout<<"*********"<<endl;
    cout<<"OPCION:";
    cin>>opc;

    if(opc==1)
    {
       Lista_A_Secuencial();
    }
    if(opc==2)
    {
        Lista_A_Familia();
    }
    if(opc==3)
    {
        Articulos_Escasos();
    }
    if(opc==4)
    {
        Articulos_En_Excesos();
    }

   }

    system("pause>null");
    system("cls");


}

void CambiarPrecio()
{

    ARTICULOS obj;

    int codigoArticulo;
    float precio;

    gotoxy(43,13);cout<<"INGRESE CODIGO ARTICULO:";
    codigoArticulo=validarnumero(67,13,1000,9999,4,55,19);



    if(BuscarCodigoArticulo(codigoArticulo)!=-1)
    {
    gotoxy(43,16);cout<<"INGRESE PRECIO:";
    precio=validarnumero(58,16,1,1000,4,55,19);
     obj.leerArticulo(BuscarCodigoArticulo(codigoArticulo));
     obj.setprecio(precio);
     obj.grabarModificacionArticulo(BuscarCodigoArticulo(codigoArticulo));

    gotoxy(54,19);cout<<"SALIO TODO BIEN"<<endl;

    }
    else {
    gotoxy(47,19);cout<<"NO SE ENCONTRO EL ARTICULO"<<endl;
    }


}

void CambiarPrecioTodos()
{

  int opc=0,cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));
  float porcentaje,precio;


  ARTICULOS obj;

  gotoxy(43,13);cout<<"AUMENTO=1 DESCUENTO=2 :";
  opc=validarnumero(66,13,1,2,1,57,19);

  gotoxy(43,16);cout<<"INGRESE %:";
  porcentaje=validarnumero(53,16,1,100,3,55,19);

  if(opc==1)
  {

    for(int x=0;x<cantreg;x++)
    {
        obj.leerArticulo(x);

        precio=(porcentaje*obj.getprecio())/100;

        precio=precio+obj.getprecio();

        obj.setprecio(precio);

       obj.grabarModificacionArticulo(x);
    }

  }
  else if(opc==2)
  {

      for(int x=0;x<cantreg;x++)
      {
      obj.leerArticulo(x);

      precio=(porcentaje*obj.getprecio())/100;

      precio=obj.getprecio()-precio;

      obj.setprecio(precio);

      obj.grabarModificacionArticulo(x);
      }

  }

  gotoxy(47,19);cout<<"SE GUARDAD LOS CAMBIOS"<<endl;


}

int BuscarCodigoArticulo(int codigo)
{

    int cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));

    ARTICULOS obj;

    for(int x=0;x<cantreg;x++)
    {
        obj.leerArticulo(x);

        if(obj.getcodigoArticulo()==codigo && obj.getestado()==1)
        {
            return x;
        }
    }

   return -1;
}

void EliminarArticulo()
{
    system("cls");

    ARTICULOS obj;

    CUADRO_ELIMANACION_ARTICULO();

    int x=0,codigoArticulo,canteg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));

    gotoxy(46,10);cout<<"CODIGO DEL ARTICULO:";
    codigoArticulo=validarnumero(66,10,1000,9999,4,58,15);


    for(x=0;x<canteg;x++)
    {
        obj.leerArticulo(x);

        if((obj==codigoArticulo)==0 && obj.getestado()==1)
        {
            obj.setestado(0);

            obj.grabarModificacionArticulo(x);

            gotoxy(49,15);cout<<"SE ELIMINO EL ARTICULO"<<endl;
            system("pause>null");

            return;
        }
    }

    gotoxy(49,15);cout<<"NO SE ENCONTRO EL REG"<<endl;


    system("pause>null");
    system("cls");

}

int VerificarStock(int codigoA)
{
     ARTICULOS obj;

     int cantidad=0,cantmax=0,cantmin=0, pos=BuscarCodigoArticulo(codigoA);

     if(pos!=-1)
     {
     obj.leerArticulo(pos);

     system("pause>null");
     cantidad=obj.getcantidad();
     cantmax=obj.getstockmaximo();
     cantmin=obj.getstockminimo();

     if(cantidad==0)
     {

         return 0;
     }

     else if(cantidad<cantmin)
     {

         return -1;
     }
     else if(cantidad>cantmax)
     {
        return 1;
     }


     }

     return -2;


}

void Lista_A_Secuencial()
{
    system("cls");
   ARTICULOS obj;

   CUADRO_LISTA_A();
    gotoxy(17,2);cout<<"LISTADO SECUENCIAL DE LOS ARTICULOS"<<endl;


   int y=9,cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));


    for(int x=0;x<cantreg;x++)
    {
        obj.leerArticulo(x);
        if(obj.getestado()==1)
        {
        obj.Mostrar(y);
        y=y+2;
        }

    }

   system("pause>null");

}

void Lista_A_Familia()
{
    system("cls");

    CUADRO_LISTA_A();

    ARTICULOS objA;

    char familia[20];
    int opc=0,y=9,cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));

    gotoxy(17,2);cout<<"LISTADO FAMILIA"<<endl;

    gotoxy(5,5);cout<<"1=DINOSAURIO ,2=AUTOS, 3=PELUCHES, 4=JUEGO DIDACTICO, 5=JUEGO DE MESA, 6=MUNIECAS, 7=MUNIECOS, 8=AVIONES:"<<endl;
    opc=validarnumero(110,5,1,8,1,60,0);

    FamiliasArticulo(familia,opc);

    for(int x=0;x<cantreg;x++)
    {
        objA.leerArticulo(x);
        if((objA==familia)==0 && objA.getestado()==1)
        {
        objA.Mostrar(y);
        y=y+2;
        }

    }




    system("pause>null");
    system("cls");
}

void Articulos_Escasos()
{
    system("cls");

    CUADRO_LISTA_A();

    ARTICULOS objA;

    int y=9,stockmin=0,cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));

     gotoxy(17,2);cout<<"ARTICULOS ESCASOS"<<endl;

    for(int x=0;x<cantreg;x++)
    {
        objA.leerArticulo(x);
        stockmin=objA.getstockminimo();
        if(objA.getestado()==1 && objA.getcantidad()<stockmin)
        {
         objA.Mostrar(y);
          y=y+2;
        }

    }

    system("pause>null");
    system("cls");
}

void Articulos_En_Excesos()
{
    system("cls");

    CUADRO_LISTA_A();

    ARTICULOS objA;

    int y=9,stockmx=0,cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));

     gotoxy(17,2);cout<<"ARTICULOS EXCEDIDOS"<<endl;

    for(int x=0;x<cantreg;x++)
    {
        objA.leerArticulo(x);

        stockmx=objA.getstockmaximo();

        if(objA.getestado()==1 && objA.getcantidad()>stockmx)
        {
            objA.Mostrar(y);
            y=y+2;
        }
    }


    system("pause>null");
    system("cls");
}

void FamiliasArticulo(char *familia,int numerof)
{
    if(numerof==1)
    {
      strcpy(familia,"DINOSAURIO");
    }
    if(numerof==2)
    {
        strcpy(familia,"AUTOS");
    }
    if(numerof==3)
    {
        strcpy(familia,"PELUCHES");
    }
    if(numerof==4)
    {
        strcpy(familia,"JUEGO DIDACTICO");
    }
    if(numerof==5)
    {
        strcpy(familia,"JUEGO DE MESA");
    }
    if(numerof==6)
    {
        strcpy(familia,"MUNIECAS");
    }
    if(numerof==7)
    {
        strcpy(familia,"MUNIECOS");
    }
    if(numerof==8)
    {
        strcpy(familia,"AVIONES");
    }

}


///FUNCIONES COMPRAS

void NuevoPedido()
{
    system("cls");


    CUADRO_NUEVA_COMPRA();

    COMPRAS obj;

    ARTICULOS objA;

    int cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));

    int codigoA;

    obj.setnumeroCompra(cantreg+1);

    gotoxy(31,7);cout<<"NUMERO DE PEDIDO:"<<cantreg+1<<endl;


    gotoxy(31,10);cout<<"CODIGO DE ARTICULO:";
    codigoA=validarnumero(50,10,1000,9999,4,70,21);

    while(BuscarCodigoArticulo(codigoA)==-1)
    {
    Error(2,70,21);
    gotoxy(31,10);cout<<"CODIGO DE ARTICULO:";
    codigoA=validarnumero(50,10,1000,9999,4,70,21);
    }

    objA.leerArticulo(BuscarCodigoArticulo(codigoA));

    obj.setcodigoarticulo(objA.getcodigoArticulo());
    obj.setnombre(objA.getfamiliaArticulo());
    obj.setdescripcion(objA.getdescripcion());

    obj.grabarComprar();


    system("pause>null");
    system("cls");
}

void ModificarPedido()
{
    system("cls");

   CUADRO_MODIFICACION_COMPRA();

   COMPRAS obj;

   int x=0,numerocompra,cantidad,cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));



   numerocompra=validarnumero(64,10,1,100,3,55,28);

   for(x=0;x<cantreg;x++)
   {
       obj.leerComprar(x);

       if((obj==numerocompra)==0 && obj.getestado()==1)
       {

          gotoxy(47,13);cout<<"NUEVA CANTIDAD:";
          cantidad=validarnumero(62,13,1,100,3,55,28);

          obj.setcantidad(cantidad);

          obj.grabarModificacionComprar(x);

          gotoxy(52,16);cout<<"SALIO TODO BIEN"<<endl;

          system("pause>null");
          return ;

       }

   }

    gotoxy(50,16);cout<<"NO SE ENCONTRO EL REG"<<endl;

    system("pause>null");
    system("cls");

}

void ListarPedidos()
{
    system("cls");

    CUADRO_LISTA_PEDIDOS();

    COMPRAS obj;

    int x=0,cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));

    int y=9;
    for(x=0;x<cantreg;x++)
    {
        obj.leerComprar(x);
        if(obj.getestado()==1)
        {
            obj.Mostrar(y);
            y=y+2;
        }

    }

    system("pause>null");
    system("cls");
}

void EliminarPedido()
{
    system("cls");

    CUADRO_ELIMINACION_COMPRAR();

    COMPRAS obj;

    int x=0,numeroPedido,cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));

    numeroPedido=validarnumero(65,10,1,100,3,55,28);

    for(x=0;x<cantreg;x++)
    {
        obj.leerComprar(x);

        if((obj==numeroPedido)==0 && obj.getestado()==1)
        {
            obj.setestado(0);

            obj.grabarModificacionComprar(x);

            gotoxy(49,15);cout<<"SE ELIMINO ESTE PEDIDO"<<endl;
            system("pause>null");
            return ;
        }

    }


    gotoxy(49,15);cout<<"NO SE ENCONTRO EL REG"<<endl;

    system("pause>null");
    system("cls");

}

void PedidosComprados()
{
    system("cls");

    int pos;

    ARTICULOS objA;

    COMPRAS objC;

    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(25,15,1,25+70,12,0);

    int cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));

    for(int x=0;x<cantreg;x++)
    {
        objC.leerComprar(x);

        if(objC.getestado()==1)
        {

            pos=BuscarCodigoArticulo(objC.getcodigoarticulo());

            objA.leerArticulo(pos);

            objA+=objC.getcantidad();

            objA.grabarModificacionArticulo(pos);
        }

    }

    gotoxy(28,15);cout<<"LOS PRODUCTOS COMPRADOS SE AGREGARAN EN EL STOCK DE CADA PRODUCTO"<<endl;
    system("pause>null");

    LimpiarRegArchivo(ARCHIVO_COMPRAS);



    system("pause>null");
    system("cls");
}



///FUNCIONES CLINETES

void NuevoCliente()
{
    system("cls");


    CUADRO_NUEVO_CLIENTE();

    int dni;

    CLIENTE obj;

    gotoxy(31,7);cout<<"DNI:";
    dni=validarnumero(36,7,10000000,99999999,8,55,28);

    while(BuscarCliente(dni)!=-1)
    {
    Error(5,55,28);
    gotoxy(31,7);cout<<"DNI:";
    dni=validarnumero(36,7,10000000,99999999,8,55,28);
    }

    obj.setdni(dni);

    obj.grabarCliente();

    system("pause>null");
    system("cls");
}

void ModificarCliente()
{
    system("cls");

    CUADRO_MODIFICACION_CLIENTE();

    CLIENTE obj;

    int x=0,opc=0,dniclinete,cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));

    dniclinete=validarnumero(62,9,10000000,99999999,8,55,28);


    for(x=0;x<cantreg;x++)
    {

        obj.leerCliente(x);

        if((obj==dniclinete)==0 && obj.getestado()==1)
        {

        ///obj.Mostrar();

        opc=validarnumero(62,15,1,5,1,55,28);

        if(opc==1)
        {
            fflush(stdin);
            char nombre[20];
            gotoxy(45,18);cout<<"NOMBRE:";
            cin.getline(nombre,20);

            obj.setnombre(nombre);

            obj.grabarModificacionCliente(x);


        }
        if(opc==2)
        {
             fflush(stdin);
            char apellido[20];
            gotoxy(45,18);cout<<"APELLIDO:";
            cin.getline(apellido,20);

            obj.setapellido(apellido);

            obj.grabarModificacionCliente(x);
        }
        if(opc==3)
        {
            int edad;
            gotoxy(45,18);cout<<"EDAD:";
            edad=validarnumero(52,18,10,100,3,55,28);

            obj.setedad(edad);

            obj.grabarModificacionCliente(x);
        }
        if(opc==4)
        {
            char sexo;
            gotoxy(48,17);cout<<"F=FEMENINO M=MASCULINO"<<endl;
            gotoxy(45,18);cout<<"SEXO:";
            cin>>sexo;

            obj.setsexo(sexo);

            obj.grabarModificacionCliente(x);
         }
         if(opc==5)
         {
            int telefono;
            gotoxy(53,17);cout<<"EMPEZAR CON 11"<<endl;
            gotoxy(45,18);cout<<"TELEFONO:";
            telefono=validarnumero(54,18,1000000000,9999999999,10,55,28);

            obj.settelefono(telefono);

            obj.grabarModificacionCliente(x);

         }


            system("pause>null");
            return;

        }
    }

    gotoxy(48,18);cout<<" NO SE ENCONTRO EL REG"<<endl;

    system("pause>null");
    system("cls");
}

void ListarCliente()
{
    system("cls");

    CUADRO_LISTA_CLIENTE();

    CLIENTE obj;

    int x=0,cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));

  int yy=9;
    for(x=0;x<cantreg;x++)
    {
        obj.leerCliente(x);
        if(obj.getestado()==1)
        {
         obj.Mostrar(yy);
         yy=yy+2;
        }

    }


    system("pause>null");
    system("cls");


}

void EliminarCliente()
{
    system("cls");

    CUADRO_ELIMANACION_CLIENTE();

    CLIENTE obj;


    int x=0,dnicliente=0,cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));


    dnicliente=validarnumero(61,10,10000000,99999999,8,55,28);

    for(x=0;x<cantreg;x++)
    {
       obj.leerCliente(x);

       if((obj==dnicliente)==0 && obj.getestado()==1)
       {
           ///obj.Mostrar();
           obj.setestado(0);
           obj.grabarModificacionCliente(x);

           gotoxy(50,15);cout<<"SE ELIMINO EL CLIENTE"<<endl;

           system("pause>null");
           return ;

       }

    }

    gotoxy(50,15);cout<<"NO SE ENCONTRO EL REG"<<endl;

    system("pause>null");
    system("cls");

}



///FUNCIONES EMPLEADO

void NuevoEmpleado()
{
    system("cls");

   CUADRO_NUEVO_EMPLEADO();

    EMPLEADO obj;

    int dni;

    gotoxy(31,7);cout<<"DNI:";
    dni=validarnumero(35,7,10000000,99999999,8,55,28);

    while(BuscarEmpleado(dni)!=-1)
    {
     Error(5,55,28);
    gotoxy(31,7);cout<<"DNI:";
    dni=validarnumero(35,7,10000000,99999999,8,55,28);
    }

    obj.setdni(dni);
    obj.grabarEmpleado();

    system("pause>null");
    system("cls");
}

void ModificarEmpleado()
{
    system("cls");

    CUADRO_MODIFICACION_EMPLEADO();

    EMPLEADO obj;

    int x=0,DNIempleado,opc=0,cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));


    DNIempleado=validarnumero(62,9,10000000,99999999,8,55,28);

    for(x=0;x<cantreg;x++)
    {

        obj.leerEmpleado(x);


        if((obj==DNIempleado)==0 && obj.getestado()==1)
        {

            ///obj.Mostrar();

            opc=validarnumero(62,15,1,5,1,55,28);

            fflush(stdin);

            if(opc==1)
            {
                char nombre[30];

                gotoxy(45,18);cout<<" NOMBRE:";
                cin.getline(nombre,30);

                obj.setnombre(nombre);
                obj.grabarModificacionEmpleado(x);

            }
            if(opc==2)
            {
               char apellido[20];
               gotoxy(45,18);cout<<"APELLIDO:";
               cin.getline(apellido,20);

               obj.setapellido(apellido);

               obj.grabarModificacionEmpleado(x);

            }
            if(opc==3)
            {
               int edad;
               gotoxy(45,18);cout<<"EDAD:";
               edad=validarnumero(51,18,10,100,3,55,28);

               obj.setedad(edad);

               obj.grabarModificacionEmpleado(x);


            }
            if(opc==4)
            {
                char sexo;
                gotoxy(48,17);cout<<"F=FEMENINO M=MASCULINO"<<endl;
                gotoxy(45,18);cout<<"SEXO:";
                cin>>sexo;

                obj.setsexo(sexo);

                obj.grabarModificacionEmpleado(x);
            }
            if(opc==5)
            {
                int telefono;
                gotoxy(53,17);cout<<"EMPEZAR CON 11"<<endl;
                gotoxy(45,18);cout<<"TELEFONO:";
                telefono=validarnumero(56,18,1000000000,9999999999,10,55,28);


                obj.settelefono(telefono);

                obj.grabarModificacionEmpleado(x);
            }

            system("pause>null");
            return ;
        }

    }

    gotoxy(50,18);cout<<"NO SE ENCONTRO EL REG"<<endl;


    system("pause>null");
    system("cls");
}

void ListarEmpleado()
{
    system("cls");

    CUADRO_LISTA_EMPLEADO();

    EMPLEADO obj;

    int x=0,cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));

    int yy=9;
    for(x=0;x<cantreg;x++)
    {
        obj.leerEmpleado(x);
        if(obj.getestado()==1)
        {
         obj.Mostrar(yy);
          yy=yy+2;
        }

    }



    system("pause>null");
    system("cls");
}

void EliminarEmpleado()
{
    system("cls");

    CUADRO_ELIMINACION_EMPLEADO();

    EMPLEADO obj;

    int x=0,DNIempledo,cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));

    DNIempledo=validarnumero(62,10,10000000,99999999,8,55,28);


    for(x=0;x<cantreg;x++)
    {
        obj.leerEmpleado(x);

        if((obj==DNIempledo)==0 && obj.getestado()==1)
        {
            ///obj.Mostrar();
            obj.setestado(0);

            obj.grabarModificacionEmpleado(x);

            gotoxy(50,15);cout<<"SE ELIMINO EMPLEADO"<<endl;

            system("pause>null");
            return ;
        }

    }

    gotoxy(50,15);cout<<"NO SE ENCONTRO EL REG"<<endl;

    system("pause>null");
    system("cls");


}


/// FUNCIONES REPORTES

void ImporteAhora()
{
    system("cls");

    CUADRO_IMPORTE_AHORA();

    VENTAS objV;

    int cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));

    float importe=0;

    for(int x=0;x<cantreg;x++)
    {
        objV.leerVenta(x);

        if(objV.getestado()==1 && comparacionfecha(objV.getdia(),objV.getmes(),objV.getanio(),fecha(1),fecha(2),fecha(3))==0)
        {
            importe+=objV.getimporte();
        }
    }

    gotoxy(51,10);cout<<"IMPORTE AHORA:";
    color("",2);
    gotoxy(65,10);cout<<"$"<<importe<<endl;
    color("",7);
    system("pause>null");
    system("cls");


}

void CantidadImporteXvendedor()
{
    system("cls");

    CUADRO_CANTIDAD_IMPORTE();

    EMPLEADO objE;

    int x=0,py=0,cantidadV=0,cantregV=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));
    int dia,mes,anio;
    float importe;

    ///LA FECHA DEBE SER >1/1/2020 Y MENOR A LA FECHA ACTUAL


    gotoxy(19,5);cout<<"DIA:";
    dia=validarnumero(23,5,1,31,2,55,28);
    gotoxy(29,5);cout<<"MES:";
    mes=validarnumero(33,5,1,12,2,55,28);
    gotoxy(39,5);cout<<"ANIO:";
    anio=validarnumero(44,5,2020,2050,4,55,28);
    py=12;
    for(x=0;x<cantregV;x++)
    {
        objE.leerEmpleado(x);
        if(objE.getestado()==1)
        {
        cantidadV=0,
        importe=0;

        CantidadImporte(objE.getdni(),&cantidadV,&importe,dia,mes,anio);


        gotoxy(22,py);cout<<objE.getnombre()<<endl;
        gotoxy(40,py); cout<<objE.getdni()<<endl;
        gotoxy(62,py);cout<<cantidadV<<endl;
        if(importe==0)
        {
        color("",12);
        gotoxy(84,py);cout<<"$"<<importe<<endl;
        color("",7);
        }
        else
        {
        color("",2);
        gotoxy(84,py);cout<<"$"<<importe<<endl;
        color("",7);
        }

        py=py+2;
        }

    }

    system("pause>null");
    system("cls");
}

void CantidadImporte(int dniV,int *cant,float *import,int dia,int mes,int anio)
{
   VENTAS objV;


   int x=0,cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));


   for(x=0;x<cantreg;x++)
   {
       objV.leerVenta(x);

       if(objV.getestado()==1)
       {
        if(comparacionfecha(objV.getdia(),objV.getmes(),objV.getanio(),dia,mes,anio)==0 && objV.getvendedor()==dniV)
       {
           *import+=objV.getimporte();
           *cant+=1;
       }
       }

   }
}

void ArticuloMasVendido()
{
    system("cls");

    CUADRO_ARTICULO_MAS_VENDIDO();

    ARTICULOS objA;
    VENTAS objV;
    VENTADETALLADA objVD;

    int posAMV=0,*varti,cantregA=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));
    int cantregV=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS)),cantregVD=cantidadReg(ARCHIVO_VENTAS_DETALLES,sizeof(VENTADETALLADA));
    varti=new int[cantregA];


     Vcero(varti,cantregA);

    for(int a=0;a<cantregA;a++)///ARTICULOS
    {
        objA.leerArticulo(a);

        if(objA.getestado()==1)///CA
        {

            for(int v=0;v<cantregV;v++)///VENTAS
            {
                objV.leerVenta(v);

                if(objV.getestado()==1)///CV
                {

                    for(int vd=0;vd<cantregVD;vd++)///VENTAS DETALLADAS
                    {
                        objVD.LeerVentaDetallada(vd);

                        if(objVD.getestado()==1 && objV.getIDventa()==objVD.getIDventa())///CDV
                        {

                         if(objA.getcodigoArticulo()==objVD.getarticulo())
                         {
                          varti[a]=varti[a]+objVD.getcantidad();
                         }

                        }

                    }

                }

            }
        }


    }

   posAMV=buscarMayor(varti,cantregA);

   objA.leerArticulo(posAMV);

   color("",11);
   gotoxy(63,5);cout<<objA.getcodigoArticulo() <<endl;
   gotoxy(55,10);cout<<objA.getfamiliaArticulo()<<endl;
   gotoxy(56,15);cout<<varti[posAMV] <<endl;
   color("",7);

    delete []varti;


    system("pause>null");

    system("cls");
}

int buscarMayor(int *v,int tam)
{

    int posm=0,nm=v[0];

    for(int x=1;x<tam;x++)
    {

      if(v[x]>nm)
      {
          posm=x;
          nm=v[x];
      }

    }

    return posm;

}

void ImporteFecha()
{

    system("cls");

    CUADRO_IMPORTE_FECHA();

    VENTAS objV;

    int dia=0,mes=0,anio=0,cantregV=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));

    float importe=0;

    gotoxy(19,5);cout<<"DIA:";
    dia=validarnumero(23,5,1,31,2,55,28);
    gotoxy(29,5);cout<<"MES:";
    mes=validarnumero(33,5,1,12,2,55,28);
    gotoxy(39,5);cout<<"ANIO:";
    anio=validarnumero(44,5,2020,2050,4,55,28);

    for(int x=0;x<cantregV;x++)
    {
        objV.leerVenta(x);
        if(objV.getestado()==1 && comparacionfecha(objV.getdia(),objV.getmes(),objV.getanio(),dia,mes,anio)==0)
        {
         importe+=objV.getimporte();
        }
    }


    color("",2);
    gotoxy(68,10);cout<<"$"<<importe<<endl;
    color("",7);


    system("pause>null");
    system("cls");

}

void ClienteConMasCompras()
{
   system("cls");

   CUADRO_CLIENTE_CON_MAS_COMPRAS();

   CLIENTE objC;
   VENTAS objV;


   int cantregC=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));
   int cantidadCompras=0,cantregV=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));

   int *vcliente=new int [cantregC],posCli=0;

   Vcero(vcliente,cantregC);

   for(int x=0;x<cantregC;x++)
   {

       objC.leerCliente(x);

       cantidadCompras=0;

       if(objC.getestado()==1)
       {

           for(int z=0;z<cantregV;z++)
           {

              objV.leerVenta(z);

              if(objV.getestado()==1 && objV.getidcliente()==objC.getdni())
              {

               cantidadCompras=CantidadVD(objV.getIDventa());

               vcliente[x]+=cantidadCompras;

              }


           }


       }



   }


   posCli=buscarMayor(vcliente,cantregC);

   objC.leerCliente(posCli);

   if(vcliente[posCli]>0)
   {
   color("",11);
   gotoxy(54,5);cout<<objC.getnombre()<<endl;
   gotoxy(51,10);cout<<objC.getdni()<<endl;
   gotoxy(67,15);cout<<vcliente[posCli]<<endl;
   color("",7);
   }
   else
   {
   cout<<"NADIE REALIZO COMPRAS TODAVIA"<<endl;
   }


   delete[]vcliente;

   system("pause>null");

   system("cls");
}

int CantidadVD(int vcb)
{
    VENTADETALLADA objVD;

    int cant=0,cantreg=cantidadReg(ARCHIVO_VENTAS_DETALLES,sizeof(VENTADETALLADA));



    for(int x=0;x<cantreg;x++)
    {

        objVD.LeerVentaDetallada(x);

        if(objVD.getestado()==1 && objVD.getIDventa()==vcb)
        {
         cant++;
        }

    }

   return cant;

}

///FUNCIONES CONFIGURACIONES

void CopiaSeguridad()
{
    system("cls");

    CUADRO_REALIZAR_BACKUP();


    BKParticulos();
    BKPclientes();
    BKPcompras();
    BKPempleados();
    BKPventas();
    BKPventasDetalles();


    gotoxy(45,8);cout<<"SE HA CREADO UN COPIA DE LOS DATOS"<<endl;

    system("pause>null");
    system("cls");

}

void BKParticulos()
{
    ARTICULOS objA;

    int cantreg=cantidadReg(ARCHIVO_ARTICULOS,sizeof(ARTICULOS));


    FILE *p;

    p=fopen(ARCHIVO_BKP_ARTICULOS,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    for(int x=0;x<cantreg;x++)
    {
        objA.leerArticulo(x);

        fwrite(&objA,sizeof(ARTICULOS),1,p);


    }

    fclose(p);
}

void BKPcompras()
{
   COMPRAS objC;

   int cantreg=cantidadReg(ARCHIVO_COMPRAS,sizeof(COMPRAS));

   FILE *p;
   p=fopen(ARCHIVO_BKP_COMPRAS,"wb");
   if(p==NULL)
   {
       exit(1);
   }

   for(int x=0;x<cantreg;x++)
   {
       objC.leerComprar(x);

       fwrite(&objC,sizeof(COMPRAS),1,p);
   }


    fclose(p);


}

void BKPclientes()
{
    CLIENTE objC;

    int cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));

    FILE *p;
    p=fopen(ARCHIVO_BKP_CLIENTES,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    for(int x=0;x<cantreg;x++)
    {
        objC.leerCliente(x);

        fwrite(&objC,sizeof(CLIENTE),1,p);

    }


    fclose(p);
}

void BKPempleados()
{
      EMPLEADO objE;

    int cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));

    FILE *p;
    p=fopen(ARCHIVO_BKP_EMPLEADOS,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    for(int x=0;x<cantreg;x++)
    {
        objE.leerEmpleado(x);

        fwrite(&objE,sizeof(EMPLEADO),1,p);

    }


    fclose(p);
}

void BKPventas()
{
      VENTAS objV;

    int cantreg=cantidadReg(ARCHIVO_VENTAS,sizeof(VENTAS));

    FILE *p;
    p=fopen(ARCHIVO_BKP_VENTAS,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    for(int x=0;x<cantreg;x++)
    {
        objV.leerVenta(x);

        fwrite(&objV,sizeof(VENTAS),1,p);

    }


    fclose(p);
}

void BKPventasDetalles()
{
    VENTADETALLADA objV;

    int cantreg=cantidadReg(ARCHIVO_VENTAS_DETALLES,sizeof(VENTADETALLADA));

    FILE *p;
    p=fopen(ARCHIVO_BKP_VENTAS_DETALLES,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    for(int x=0;x<cantreg;x++)
    {
        objV.LeerVentaDetallada(x);

        fwrite(&objV,sizeof(VENTADETALLADA),1,p);

    }


    fclose(p);
}


void RestablerCopia()
{
    system("cls");

    CUADRO_RESTAURAR_BACKUP();

    RTarticulos();
    RTclientes();
    RTcompras();
    RTempleados();
    RTventas();
    RTventasDetalles();

    gotoxy(51,8);cout<<"SE HA RESTAURADO LOS DATOS "<<endl;

    system("pause>null");
    system("cls");

}

void RTarticulos()
{
      int x=0;

    ARTICULOS objA;

    LimpiarRegArchivo(ARCHIVO_ARTICULOS);

    FILE *p;
    p=fopen(ARCHIVO_BKP_ARTICULOS,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&objA,sizeof(ARTICULOS),1,p)==1)
    {
        objA.grabarModificacionArticulo(x);
        x++;
    }

    fclose(p);

}

void RTcompras()
{
    int x=0;

    COMPRAS objC;

    LimpiarRegArchivo(ARCHIVO_COMPRAS);

    FILE *p;
    p=fopen(ARCHIVO_BKP_COMPRAS,"rb");
    if(p==NULL)
    {
        exit(1);
    }
    while(fread(&objC,sizeof(COMPRAS),1,p)==1)
    {
        objC.grabarModificacionComprar(x);
        x++;
    }


    fclose(p);


}

void RTclientes()
{
    int x=0;

    CLIENTE objC;


    LimpiarRegArchivo(ARCHIVO_CLIENTES);

    FILE *p;
    p=fopen(ARCHIVO_BKP_CLIENTES,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&objC,sizeof(CLIENTE),1,p)==1)
    {


         objC.grabarModificacionCliente(x);
         x++;
    }

    fclose(p);
}

void RTempleados()
{

    EMPLEADO objE;

    LimpiarRegArchivo(ARCHIVO_EMPLEADOS);

    int x=0;


    FILE *p;
    p=fopen(ARCHIVO_BKP_EMPLEADOS,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&objE,sizeof(EMPLEADO),1,p)==1)
    {
        objE.grabarModificacionEmpleado(x);
        x++;
    }

    fclose(p);

}

void RTventas()
{
    VENTAS objV;

    LimpiarRegArchivo(ARCHIVO_VENTAS);

    int x=0;


    FILE *p;
    p=fopen(ARCHIVO_BKP_VENTAS,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&objV,sizeof(VENTAS),1,p)==1)
    {
        objV.grabarModificacionVenta(x);
        x++;
    }

    fclose(p);

}

void RTventasDetalles()
{
    VENTADETALLADA objV;

    LimpiarRegArchivo(ARCHIVO_VENTAS_DETALLES);

    int x=0;


    FILE *p;
    p=fopen(ARCHIVO_BKP_VENTAS_DETALLES,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    while(fread(&objV,sizeof(VENTADETALLADA),1,p)==1)
    {
        objV.GrabarModificacionVentaDetallada(x);
        x++;
    }

    fclose(p);


}

void AltaClinete()
{
    system("cls");

    CUADRO_ALTA_CLIENTE();

    CLIENTE objC;

    int dni,pos;


    dni=validarnumero(62,9,10000000,99999999,8,55,28);

    pos=BuscarClineteBaja(dni);

    if(pos!=-1)
    {
       objC.leerCliente(pos);

       objC.setestado(1);

       objC.grabarModificacionCliente(pos);

       gotoxy(47,15);cout<<"SE HA PRODUCIDO EL ALTA"<<endl;


    }
    else
    {gotoxy(48,15);cout<<" NO SE ENCONTRO EL DNI"<<endl;}



    system("pause>null");
    system("cls");

}

void AltaEmpleado()
{
    system("cls");

    CUADRO_ALTA_EMPLEADO();

    EMPLEADO objE;

    int dni,pos;



    dni=validarnumero(62,9,10000000,99999999,8,55,28);

    pos=BuscarEmpleadoBaja(dni);

    if(pos!=-1)
    {
      objE.leerEmpleado(pos);

      objE.setestado(1);

      objE.grabarModificacionEmpleado(pos);

      gotoxy(47,15);cout<<"SE HA PRODUCIDO EL ALTA"<<endl;

    }
    else
     {
     gotoxy(48,15);cout<<" NO SE ENCONTRO EL DNI"<<endl;
     }


    system("pause>null");

    system("cls");
}


///VALIDACIONES

int ValidarC()
{
  int dnidd,pos;

    dnidd=validarnumero(20,10,10000000,99999999,8,55,28);

    pos=BuscarCliente(dnidd);

    if(pos==-1)
    {
        return 0;
    }
    else if(pos!=-1)
    {return dnidd;}

}

int ValidarE()
{
    int dniempleado;

    dniempleado=validarnumero(20,13,10000000,99999999,8,55,28);

    while(BuscarEmpleado(dniempleado)==-1)
    {
     Error(1,50,28);
     dniempleado=validarnumero(20,13,10000000,99999999,8,55,28);
    }

    return dniempleado;
}

int ValidarA(int px,int py)
{
    int codigoArticulo;
    codigoArticulo=validarnumero(px,py,100,9999,4,55,28);

    while(BuscarCodigoArticulo(codigoArticulo)==-1 || VerificarStock(codigoArticulo)==0)
    {
     Error(2,50,28);
     codigoArticulo=validarnumero(px,py,100,9999,4,55,28);

    }



    return codigoArticulo;
}


///FUNCIONES DE BUSQUEDA

int BuscarCliente(int dniclinete)
{
    CLIENTE obj;

    int x=0,cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));

    for(x=0;x<cantreg;x++)
    {
        obj.leerCliente(x);
        if((obj==dniclinete)==0 && obj.getestado()==1)
        {
            return x;
        }
    }

    return -1;
}

int BuscarClineteBaja(int dnicliente)
{
    CLIENTE objC;

    int x,cantreg=cantidadReg(ARCHIVO_CLIENTES,sizeof(CLIENTE));

    for(x=0;x<cantreg;x++)
    {
        objC.leerCliente(x);

        if((objC==dnicliente)==0 && objC.getestado()==0)
        {
            return x;
        }

    }

    return -1;
}

int BuscarEmpleado(int dni)
{
    EMPLEADO obj;

    int x=0,cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));


    for(int x=0;x<cantreg;x++)
    {
        obj.leerEmpleado(x);

        if((obj==dni)==0 && obj.getestado()==1 )
        {
            return x;
        }
    }

    return -1;
}

int BuscarEmpleadoBaja(int dniempleado)
{
  EMPLEADO objE;

  int cantreg=cantidadReg(ARCHIVO_EMPLEADOS,sizeof(EMPLEADO));

  for(int x=0;x<cantreg;x++)
  {
      objE.leerEmpleado(x);

      if((objE==dniempleado)==0 && objE.getestado()==0)
      {
          return x;
      }
 }

 return -1;
}

///FUNCIONES DE CONTRA REG Y ELIMINAR DE UN ARCHIVO DETERMINADO

int cantidadReg(const char *nombreArchivo,int tamOBJ)
{



   int cantreg;

   char archivo[20];

   strcpy(archivo,nombreArchivo);

   FILE *p;

   p=fopen(archivo,"rb");

   if(p==NULL)
   {
       return 0;
   }

   fseek(p,0,2);

   cantreg=ftell(p)/tamOBJ;

   fclose(p);

   return cantreg;
}

void LimpiarRegArchivo(const char *nombreArchivo)
{
    char ARCHIVO[20];

    strcpy(ARCHIVO,nombreArchivo);

    FILE *p;
    p=fopen(ARCHIVO,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    fclose(p);

}


///CONTRASENIA

int VerificarContrasenia()
{
    system("cls");

    CUADRO_CONTRASENIA();

    CONTRASENIA objC;

    objC.LeerContrasenia();
    objC.Mostrar();
    char contrase[30];
    fflush(stdin);
    gotoxy(43,10);cout<<"CONTRASENIA:";
    cin.getline(contrase,30);

    if(strcmp(contrase,objC.getcontrasenia())==0)
    {
        system("cls");
        return 1;
    }
    else
    {
        system("cls");
        return 0;
    }

}

void CambiarContrasenia()
{
    system("cls");

    CUADRO_CAMBIAR_CONTRASENIA();

    CONTRASENIA objC;

    objC.LeerContrasenia();

    objC.Mostrar();

    char contrasenia[30];

    fflush(stdin);

    gotoxy(44,13);cout<<"CONTRASENIA:";
    cin.getline(contrasenia,30);

    if(strcmp(contrasenia,objC.getcontrasenia())==0)
    {
        gotoxy(44,16);cout<<"NUEVA CONTRASENIA:";
        cin.getline(contrasenia,30);

        objC.setcontrasenia(contrasenia);

        objC.Grabar();
    }
    else
    {
        gotoxy(48,16);cout<<"CONTRASENIA INVALIDA"<<endl;
    }

    system("pause>null");
    system("cls");

}

///FUNCION ERROR
void Error(float numeroerror,int px,int py)
{
 if(numeroerror==1)
 {

    gotoxy(px,py);cout<<"DNI NO EXISTE"<<endl;
    Sleep(1000);
    gotoxy(px,py);cout<<"             "<<endl;
 }

 if(numeroerror==2)
 {
    gotoxy(px,py);cout<<"ART NO SE ENCUENTRA "<<endl;
    Sleep(1000);
    gotoxy(px,py);cout<<"                    "<<endl;
 }

 if(numeroerror==3)
 {
     gotoxy(px,py);cout<<"NO SE POSEE ES CANT"<<endl;
     Sleep(1000);
     gotoxy(px,py);cout<<"                    "<<endl;
 }

  if(numeroerror==4)
 {
     gotoxy(px,py);cout<<"ART YA EXISTES"<<endl;
     Sleep(1000);
     gotoxy(px,py);cout<<"              "<<endl;
 }
  if(numeroerror==5)
 {
    gotoxy(px,py);cout<<"DNI YA EXISTES"<<endl;
    Sleep(1000);
    gotoxy(px,py);cout<<"              "<<endl;
 }
}

void Vcero(int *v,int tam)
{
    int x=0;

    for(x=0;x<tam;x++)
    {
        v[x]=0;
    }

}

#endif // FUNCIONES_H_INCLUDED
