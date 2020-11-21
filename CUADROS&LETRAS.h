#ifndef CUADROS&LETRAS_H_INCLUDED
#define CUADROS&LETRAS_H_INCLUDED

/// PROTOTIPO

void LOGO(void);

void TITULO_MENU_PRINCIPAL(void);///cuadros menu principal
void TITULO_MENU_VENTA(void);///cuadros menu ventas
void CUADROS_NUEVA_VENTA(void);
void CUADRO_LISTA_VENTAS(int );///CUADRO LISTA VENTAS
void CUADRO_ELIMINACION_VENTA(void);///CUADRO ELIMINACION DE VENTA

void TITULO_MENU_ARTICULOS(void);///cuadros menu articulos
void CUADRO_NUEVO_ARTICULO(void);///cuadro  para crear un articulo
void CUADRO_MODIFICACION(void);///cuadros modificacion
void CUADRO_ELIMANACION_ARTICULO(void);///cuadros eliminacion
void CUADRO_LISTA_A(void);///CUADRO LISTA ARTICULOS


void TITULO_MENU_COMPRAS(void);///cuadro menu compras
void CUADRO_NUEVA_COMPRA(void);///cuadro nuevo pedido
void CUADRO_MODIFICACION_COMPRA(void);///cuadro modificacion
void CUADRO_LISTA_PEDIDOS(void);///cuadro lista
void CUADRO_ELIMINACION_COMPRAR(void);///cuadro de eliminacion


void TITULO_MENU_CLIENTE(void);///cuadro menu cliente
void CUADRO_NUEVO_CLIENTE(void);///cuadro para creacion de un clinete
void CUADRO_MODIFICACION_CLIENTE(void);///cuadro para modificar cliente
void CUADRO_LISTA_CLIENTE(void);///cuadro para listar cliente
void CUADRO_ELIMANACION_CLIENTE(void);///cuadro para eliminar cliente


void TITULO_MENU_EMPLEADO(void);///cuadro menu empleado
void CUADRO_NUEVO_EMPLEADO(void);///cuadro para creacion de un empleado
void CUADRO_MODIFICACION_EMPLEADO(void);///cuadrp para modificar cliente
void CUADRO_LISTA_EMPLEADO(void);///cuadro para listar empleado
void CUADRO_ELIMINACION_EMPLEADO(void);///cuadro para eliminar empleado


void TITULO_MENU_REPORTES(void);///cuadro menu reportes
void CUADRO_IMPORTE_AHORA(void);
void CUADRO_CANTIDAD_IMPORTE(void);
void CUADRO_IMPORTE_FECHA(void);
void CUADRO_ARTICULO_MAS_VENDIDO(void);
void CUADRO_CLIENTE_CON_MAS_COMPRAS(void);


void TITULO_MENU_CONFIGURACIONES(void);///cuadro menu configuraciones
void CUADRO_CAMBIAR_CONTRASENIA(void);///cuadro para cambiar contrasenia
void CUADRO_REALIZAR_BACKUP(void);
void CUADRO_RESTAURAR_BACKUP(void);
void CUADRO_ALTA_CLIENTE(void);
void CUADRO_ALTA_EMPLEADO(void);


void CUADRO_CONTRASENIA(void);///cuadro para escribir la contrasenia



///FUNCIONES

void TITULO_MENU_PRINCIPAL()
{
 ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,9,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,9,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+10,6,0);///CUADRO MENU

 cuadro(52,25,1,50+22,9,0);///CUADRO CONFIGURACIONES

int yy=15;
for(int y=0;y<3;y++)
 {
     cuadro(19,yy,1,19+15,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+15,9,0);///CUADROS IZQUIERDOS
     yy=yy+5;
 }

  cuadro(50,18,1,50+23,6,0);///CUADRO OPC
  cuadro(50+5,21,1,50+18,9,0);///

  color("",12);
  gotoxy(58,21);cout<<"0- SALIR "<<endl;
  color("",7);
}

void TITULO_MENU_VENTA()
{
   ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU
 cuadro(9-5,12,15,9+105,12,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,12,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+9,6,0);///CUADRO MENU

 cuadro(54-2,20,1,54+16,6,0);
  int xx=17;

  for(int x=0;x<4;x++)
  {
    cuadro(xx,17,1,xx+18,9,0);///CUADRO HORIZONTALES

    xx=xx+23;
  }

}

void CUADROS_NUEVA_VENTA()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(10,6,15,10+25,9,0);///CUADRO CONTENEDOR IZQUIERDO

    cuadro(45,6,15,45+25,9,0);///CUADRO CONTENEDOR CENTRAL

    cuadro(80,6,15,80+30,9,0);///CUADRO CONTENEDOR DERECHO

    for(int y=7;y<20;y=y+3)
    {
           cuadro(11,y,1,11+23,9,0);///CUADROS IZQUIERDOS
           cuadro(46,y,1,46+23,9,0);
    }

    cuadro(10,16,1,11+24,9,0);///CUADROS IZQUIERDOS
    cuadro(20-2,16,1,(20+5),9,0);///CUADRO FECHA
    cuadro(47,26,1,47+23,12,0);///CUADRO OPCION

    for(int x=14;x<86;x=x+35)
    {
         cuadro(x,23,1,x+20,8,0);
    }



    ///TITULOS & BOTONES
    gotoxy(15,5);cout<<"CABECERA DE VENTA"<<endl<<endl;
    gotoxy(56,5);cout<<"VENTA"<<endl;
    gotoxy(86,5);cout<<"COMPRAS"<<endl;

    gotoxy(15,23);cout<<"1- TERMINAR "<<endl;
    gotoxy(50,23);cout<<"2- ELIMINAR JUGUETE"<<endl;
    gotoxy(85,23);cout<<"0- SEGUIR"<<endl;
    gotoxy(52,26);cout<<"OPCION:"<<endl;
}

void CUADRO_LISTA_VENTAS(int py)
{

  cuadro(56,py,1,56+20,9,0);

  color("",3);
  gotoxy(28,py+5);cout<<"ID VENTA"<<endl;
  gotoxy(45,py+5);cout<<"CODI ART"<<endl;
  gotoxy(60,py+5);cout<<"PREC ART"<<endl;
  gotoxy(75,py+5);cout<<"CANTIDAD"<<endl;
  gotoxy(90,py+5);cout<<"IMPOR ART"<<endl;

  color("",7);


}

void CUADRO_ELIMINACION_VENTA()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47,7,8,47+25,3,0);///CUADRO CONTENEDOR

    cuadro(47-2,10,1,47+27,3,0);///CUADRO DONDE SE INGRESA ID VENTA

    cuadro(47-2,15,1,47+27,3,0);

    ///TITULOS
    gotoxy(53,7);cout<<"ELIMINAR VENTA"<<endl;

}


void TITULO_MENU_ARTICULOS()
{
    ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

  cuadro(9-5,12,15,9+105,14,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,14,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+10,6,0);///CUADRO MENU

 cuadro(59-7,25,1,59+12,6,0);///CUADRO OPCION

 int yy=15;
for(int y=0;y<2;y++)
 {

     if(y==1)
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(54,yy,1,54+16,9,0);///CUADRO CENTRAL
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS
      yy=yy+5;
     }
     else
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS

     yy=yy+5;
     }

 }


}

void CUADRO_NUEVO_ARTICULO()
{
    cuadro(5,2,25,5+100,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(20,2,25,20+30,9,0);///cuadro contenedor nuevo articulo
    cuadro(60-3,4,22,60+40,9,0);///cuadro contenedor familia articulo

    int y;
    for(y=4;y<28;y=y+3)
    {
     cuadro(21,y,1,21+28,9,0);///cuadros de campos de un art
    }

    for(y=6;y<6+12;y=y+3)
    {
    cuadro(58,y,1,58+20,9,0);///cuadros familias izquierdos
    cuadro(79,y,1,79+20,9,0);///cuadros familias derechos
    }

    /// TITULOS y FAMILIAS

    gotoxy(28,2);cout<<"NUEVO ARTICULO"<<endl;
    gotoxy(69,4);cout<<"FAMILIAS DISPONIBLES"<<endl;


    gotoxy(59,6);cout<<"1=DINOSAURIO"<<endl;
    gotoxy(80,6);cout<<"2=AUTOS"<<endl;
    gotoxy(59,9);cout<<"3=PELUCHES"<<endl;
    gotoxy(80,9);cout<<"4=JUEGO DIDACTICO"<<endl;
    gotoxy(59,12);cout<<"5=JUEGO DE MESA"<<endl;
    gotoxy(80,12);cout<<"6=MUNIECAS"<<endl;
    gotoxy(59,15);cout<<"7=MUNIECOS"<<endl;
    gotoxy(80,15);cout<<"8=AVIONES"<<endl;




}

void CUADRO_LISTA_A()
{
    cuadro(5,2,2,5+50,9,0);///CUADRO CONTENDOR

    LOGO();


    ///TITULOS
    color("",11);
    gotoxy(0,7);cout<<"CODI ARTI"<<endl;
    gotoxy(12,7);cout<<"FAMI ARTI"<<endl;
    gotoxy(31,7);cout<<"DEC  ARTI"<<endl;
    gotoxy(53,7);cout<<"PRECIO AT"<<endl;
    gotoxy(65,7);cout<<"CANTIDAD"<<endl;
    gotoxy(79,7);cout<<"STOCK MX"<<endl;
    gotoxy(93,7);cout<<"STOCK MIN"<<endl;
    gotoxy(105,7);cout<<"N. PROVE"<<endl;
    color("",7);


}

void CUADRO_MODIFICACION()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47-8,7,15,47+33,3,0);///CUADRO SUB CONTENEDOR

    for(int y=10;y<20;y=y+3)
    {
     cuadro(47-5,y,1,47+30,3,0);///CUADROS DENTRO DEL CONTENEDOR
    }


    ///TITULOS
    gotoxy(53,7);cout<<"MODIFICAR PRECIO"<<endl;
    gotoxy(43,10);cout<<"UN ART=1, TODOD LOS ART=2:"<<endl;

}

void CUADRO_ELIMANACION_ARTICULO()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47,7,8,47+25,3,0);///CUADRO CONTENEDOR

    cuadro(47-2,10,1,47+27,3,0);///CUADRO DONDE SE INGRESA EL CODI ART5

    cuadro(47-2,15,1,47+27,3,0);

    ///TITULOS
    gotoxy(52,7);cout<<"ELIMINAR ARTICULO"<<endl;
}



void TITULO_MENU_COMPRAS()
{
     ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,10,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,10,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+10,6,0);///CUADRO MENU

  int yy=15;
for(int y=0;y<2;y++)
 {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS

     yy=yy+5;
 }

 cuadro(59-8,18,1,59+13,9,0);///CUADRO OPC 5

 cuadro(59-8,21,1,59+13,9,0);///CUADOR VOLVER

 cuadro(55-2,24,1,55+15,6,0);///CUADRO OPCIONES

}

void CUADRO_NUEVA_COMPRA()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(30,4,20,30+30,9,0);///contenedor pequenio

    cuadro(70,4,10,70+30,9,0);///cuadro fecha

    for(int y=7;y<22;y=y+3)
    {
     cuadro(30,y,1,30+30,9,0);///cuadro donde se escribira
    }

    ///TITULO
    gotoxy(39,4);cout<<"NUEVO PEDIDO"<<endl;
    gotoxy(78,4);cout<<"FECHA DE PEDIDO"<<endl;

}

void CUADRO_MODIFICACION_COMPRA()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47-8,7,12,47+33,3,0);///CUADRO SUB CONTENEDOR

    for(int y=10;y<19;y=y+3)
    {
     cuadro(47-2,y,1,47+27,3,0);///CUADROS DONDE SE ESCRIBIRA
    }

    ///TITULOS
    gotoxy(52,7);cout<<"MODIFICAR CANTIDAD"<<endl;
    gotoxy(47,10);cout<<"NUMERO DE COMPRA:";


}

void CUADRO_LISTA_PEDIDOS()
{
    cuadro(5,2,2,5+50,9,0);///CUADRO CONTENDOR

    LOGO();


    ///TITULOS

    gotoxy(25,2);cout<<"LISTA DE PEDIDOS"<<endl;

    color("",11);

    gotoxy(20,7);cout<<"NUM.COMPRA"<<endl;
    gotoxy(35,7);cout<<"COD.ARTICU"<<endl;
    gotoxy(50,7);cout<<"FAMILIA"<<endl;
    gotoxy(68,7);cout<<"DESCRIPCION"<<endl;
    gotoxy(90,7);cout<<"CANTIDAD"<<endl;
    gotoxy(105,7);cout<<"FECHA"<<endl;

    color("",7);

}

void CUADRO_ELIMINACION_COMPRAR()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47,7,8,47+25,3,0);///CUADRO CONTENEDOR

    cuadro(47-2,10,1,47+27,3,0);///

    cuadro(47-2,15,1,47+27,3,0);///CARTEL

    ///TITULOS
    gotoxy(52,7);cout<<"ELIMINAR PEDIDO"<<endl;
    gotoxy(48,10);cout<<"NUMERO DE PEDIDO:";
}


void TITULO_MENU_CLIENTE()
{
    ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,12,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,12,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+10,6,0);///CUADRO MENU

 cuadro(59-7,25,1,59+12,6,0);///CUADRO OPCION

  int yy=15;
for(int y=0;y<2;y++)
 {

     if(y==1)
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(54,yy,1,54+16,9,0);///CUADRO CENTRAL
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS
      yy=yy+5;
     }
     else
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS

     yy=yy+5;
     }

 }


}

void CUADRO_NUEVO_CLIENTE()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(30,4,20,30+30,9,0);///contenedos pequenio

    cuadro(70,4,10,70+30,9,0);///cuadro direccion

    cuadro(70,21,3,70+30,9,0);///cuadro fecha

    for(int y=7;y<25;y=y+3)
    {
      if(y<14)
      {
      cuadro(30,y,1,30+30,9,0);///cuadro de nuevo cliente
      cuadro(70,y,1,70+30,9,0);///cuadro de direccion
      }
      else
        {cuadro(30,y,1,30+30,9,0);///cuadro de nuevo cliente
        }

    }



    ///TITULOS

    gotoxy(39,4);cout<<"NUEVO CLIENTE"<<endl;
    gotoxy(81,4);cout<<"DIRECCION"<<endl;
    gotoxy(75,20);cout<<"FECHA DE INSCRIPCION"<<endl;

}

void CUADRO_MODIFICACION_CLIENTE()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47-8,7,13,47+33,3,0);///CUADRO SUB CONTENEDOR

    cuadro(47-3,9,1,47+28,3,0);///CUADRO DONDE SE INGRESARA EL DNI

    cuadro(47+3,15,1,47+22,3,0);///CUADRO DONDE SE INGRESARA LA OPC

    cuadro(47-3,18,1,47+28,3,0);///CUADRO DONDE SE MODIFICARA

    for(int x=10;x<100;x=x+20)
    {
        cuadro(x,12,1,x+19,3,0);///CUADRO OPCIONES
    }


    ///TITULOS Y BOTONES

    gotoxy(55,7);cout<<"MIDIFICACION"<<endl;
    gotoxy(45,9);cout<<"DNI DEL CLIENTE:";
    gotoxy(54,15);cout<<"OPCION:"<<endl;
    gotoxy(11,12);cout<<"1=NOMBRE"<<endl;
    gotoxy(31,12);cout<<"2=APELLIDO"<<endl;
    gotoxy(51,12);cout<<"3=EDAD"<<endl;
    gotoxy(71,12);cout<<"4=SEXO"<<endl;
    gotoxy(91,12);cout<<"5=TELEFONO:"<<endl;


}

void CUADRO_LISTA_CLIENTE()
{
    cuadro(5,2,2,5+50,9,0);///CUADRO CONTENDOR

    LOGO();


    ///TITULOS

    gotoxy(18,2);cout<<" LISTO DE LOS CLIENTE"<<endl;

    color("",12);
    gotoxy(2,7);cout<<"DNI"<<endl;
    gotoxy(12,7);cout<<"NOMBRE"<<endl;
    gotoxy(25,7);cout<<"APELLIDO"<<endl;
    gotoxy(38,7);cout<<"LOCALIDAD"<<endl;
    gotoxy(52,7);cout<<"DOMICILIO"<<endl;
    gotoxy(67,7);cout<<"NUMERO"<<endl;
    gotoxy(77,7);cout<<"EDAD"<<endl;
    gotoxy(84,7);cout<<"SEXO"<<endl;
    gotoxy(92,7);cout<<"TELEFONO"<<endl;
    gotoxy(105,7);cout<<"F.INSCRIPCION"<<endl;
    color("",7);



}

void CUADRO_ELIMANACION_CLIENTE()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47,7,8,47+25,3,0);///CUADRO CONTENEDOR

    cuadro(47-2,10,1,47+27,3,0);///CUADRO DONDE SE INGRESA EL DNI

    cuadro(47-2,15,1,47+27,3,0);///CARTEL

    ///TITULOS
    gotoxy(52,7);cout<<"ELIMINAR CLIENTE"<<endl;
    gotoxy(48,10);cout<<"DNI CLIENTE:";
}




void TITULO_MENU_EMPLEADO()
{
    ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,14,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,14,0);///CUADRO PEQUEÑO

 cuadro(59-5,14,1,59+10,6,0);///CUADRO MENU
 cuadro(59-7,25,1,59+12,6,0);///CUADRO OPC

 int yy=15;
for(int y=0;y<2;y++)
 {

     if(y==1)
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(54,yy,1,54+16,9,0);///CUADRO CENTRAL
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS
      yy=yy+5;
     }
     else
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS

     yy=yy+5;
     }

 }



}

void CUADRO_NUEVO_EMPLEADO()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(30,4,20,30+30,9,0);///contenedos pequenio

    cuadro(70,4,10,70+30,9,0);///cuadro direccion

    cuadro(70,21,3,70+30,9,0);///cuadro fecha

    for(int y=7;y<25;y=y+3)
    {
      if(y<14)
      {
      cuadro(30,y,1,30+30,9,0);///cuadro de nuevo cliente
      cuadro(70,y,1,70+30,9,0);///cuadro de direccion
      }
      else
        {cuadro(30,y,1,30+30,9,0);///cuadro de nuevo cliente
        }

    }

    ///TITULOS

    gotoxy(39,4);cout<<"NUEVO EMPLEADO"<<endl;
    gotoxy(81,4);cout<<"DIRECCION"<<endl;
    gotoxy(75,20);cout<<"FECHA DE INGRESO"<<endl;

}

void CUADRO_MODIFICACION_EMPLEADO()
{
      cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47-8,7,13,47+33,3,0);///CUADRO SUB CONTENEDOR

    cuadro(47-3,9,1,47+28,3,0);///CUADRO DONDE SE INGRESARA EL DNI

    cuadro(47+3,15,1,47+22,3,0);///CUADRO DONDE SE INGRESARA LA OPC

    cuadro(47-3,18,1,47+28,3,0);///CUADRO DONDE SE MODIFICARA

    for(int x=10;x<100;x=x+20)
    {
        cuadro(x,12,1,x+19,3,0);///CUADRO OPCIONES
    }


    ///TITULOS Y BOTONES

    gotoxy(55,7);cout<<"MIDIFICACION"<<endl;
    gotoxy(45,9);cout<<"DNI DEL EMPLEADO:";
    gotoxy(54,15);cout<<"OPCION:"<<endl;
    gotoxy(11,12);cout<<"1=NOMBRE"<<endl;
    gotoxy(31,12);cout<<"2=APELLIDO"<<endl;
    gotoxy(51,12);cout<<"3=EDAD"<<endl;
    gotoxy(71,12);cout<<"4=SEXO"<<endl;
    gotoxy(91,12);cout<<"5=TELEFONO:"<<endl;


}

void CUADRO_LISTA_EMPLEADO()
{
      cuadro(5,2,2,5+50,9,0);///CUADRO CONTENDOR

    LOGO();


    ///TITULOS

    gotoxy(18,2);cout<<" LISTADO DE LOS EMPLEADO"<<endl;

    color("",12);
    gotoxy(2,7);cout<<"DNI"<<endl;
    gotoxy(12,7);cout<<"NOMBRE"<<endl;
    gotoxy(25,7);cout<<"APELLIDO"<<endl;
    gotoxy(38,7);cout<<"LOCALIDAD"<<endl;
    gotoxy(52,7);cout<<"DOMICILIO"<<endl;
    gotoxy(67,7);cout<<"NUMERO"<<endl;
    gotoxy(77,7);cout<<"EDAD"<<endl;
    gotoxy(84,7);cout<<"SEXO"<<endl;
    gotoxy(92,7);cout<<"TELEFONO"<<endl;
    gotoxy(108,7);cout<<"F.INGRESO"<<endl;
    color("",7);


}

void CUADRO_ELIMINACION_EMPLEADO()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(47,7,8,47+25,3,0);///CUADRO CONTENEDOR

    cuadro(47-2,10,1,47+27,3,0);///CUADRO DONDE SE INGRESA EL DNI

    cuadro(47-2,15,1,47+27,3,0);///CARTEL

    ///TITULOS
    gotoxy(52,7);cout<<"ELIMINAR EMPLEADO"<<endl;
    gotoxy(48,10);cout<<"DNI EMPLEADO:";
}


void TITULO_MENU_REPORTES()
{
     ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,9,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,9,0);///CUADRO PEQUEÑO

 cuadro(59-5,11,1,59+11,6,0);///CUADRO MENU

 cuadro(10,14,10,10+40,9,0);///CUADRO INFORMACION

 cuadro(85,24,1,85+18,9,0);///CUADRO VOLVER

 cuadro(54,24,1,54+15,6,0);///CUADRO OPCION

 for(int y=14;y<21;y=y+3)
 {
     for(int x=55;x<100;x=x+15)
     {
        if(x==55)
        {
            cuadro(x,y,1,x+15,9,0);
        }
        else
        {
            cuadro(x+1,y,1,x+15,9,0);
        }

     }
 }




///INFORMACION

gotoxy(25,12);cout<<"ACLARACIONES"<<endl;

color("",11);
gotoxy(11,14);cout<<"R1:CAJA AHORA"<<endl;
gotoxy(11,15);cout<<"R2:CANTIDAD DE VENTAS Y FACTURADO POR"<<endl;
gotoxy(14,16);cout<<"EMPLEADO EN UNA FECHA"<<endl;
gotoxy(11,17);cout<<"R3:IMPORTE DE UNA FECHA"<<endl;
gotoxy(11,18);cout<<"R4:ARTICULO MAS VENDIDO "<<endl;
gotoxy(11,19);cout<<"R5:CLIENTE CON MAS COMPRAS"<<endl;
color("",7);

}

void CUADRO_IMPORTE_AHORA()
{
    cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(50,10,1,50+20,12,0);

}

void CUADRO_CANTIDAD_IMPORTE()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();


    for(int x=18;x<48;x=x+10)
    {
     cuadro(x,5,1,x+10,9,0);///cuadros fechas

    }

    ///TITULOS

    gotoxy(25,3);cout<<"INGRESE FECHA"<<endl;
    color("",11);
    gotoxy(22,10);cout<<"NOMBRE"<<endl;
    gotoxy(42,10);cout<<"DNI"<<endl;
    gotoxy(56,10);cout<<"CANTIDAD VENTAS"<<endl;
    gotoxy(80,10);cout<<"FACTURADO"<<endl;
    color("",7);
}

void CUADRO_IMPORTE_FECHA()
{
    cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    for(int x=18;x<48;x=x+10)
    {
     cuadro(x,5,1,x+10,9,0);///cuadros fechas

    }

    cuadro(50-10,10,1,50+30,12,0);///CUADRO DONDE SE IMPRIME EL IMPORTE

    ///TITULOS

    gotoxy(25,3);cout<<"INGRESE FECHA"<<endl;
    gotoxy(51,10);cout<<"IMPORTE DE FECHA:"<<endl;

}

void CUADRO_ARTICULO_MAS_VENDIDO()
{
    cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(25-10,3,1,25+15,9,0);///TITULO

    for(int y=5;y<16;y=y+5)
    {
    cuadro(55-10,y,1,55+20,9,0);
    }



    ///TITULO

    gotoxy(18,3);cout<<"ARTICULO MAS VENDIDO"<<endl;
    gotoxy(47,5);cout<<"CODIGO ARTICULO:"<<endl;
    gotoxy(47,10);cout<<"FAMILIA:"<<endl;
    gotoxy(47,15);cout<<"CANTIDAD:"<<endl;



}

void CUADRO_CLIENTE_CON_MAS_COMPRAS()
{
     cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(25-10,3,1,25+15,9,0);///TITULO

    for(int y=5;y<16;y=y+5)
    {
    cuadro(55-10,y,1,55+20,9,0);
    }



    ///TITULO

    gotoxy(16,3);cout<<"CLIENTE CON MAS COMPRAS"<<endl;
    gotoxy(47,5);cout<<"NOMBRE:"<<endl;
    gotoxy(47,10);cout<<"DNI:"<<endl;
    gotoxy(47,15);cout<<"CANTIDAD DE COMPRAS:"<<endl;


}


void TITULO_MENU_CONFIGURACIONES()
{
     ///TITULO
 cuadro(10,1,8,10+100,8,0);///CUADRO CONTENEDOR
 cuadro(9,8,2,9+5,8,0);///CUADRO PEQUEÑO
 LETRAR(20,1,5,6,9,'T');
 LETRAR(30,2,4,4,12,'O');
 LETRAR(40,2,6,6,14,'Y');
 LETRAR(55,2,6,6,9,'W');
 LETRAR(75,2,4,4,10,'O');
 LETRAR(83,2,5,6,12,'R');
 LETRAR(92,1,5,6,14,'L');
 LETRAR(100,2,4,5,9,'D');

 ///MENU

 cuadro(9-5,12,15,9+105,5,0);///CUADRO CONTENEDOR
 cuadro(3,26,2,4+4,13,0);///CUADRO PEQUEÑO

 cuadro(59-10,14,1,59+15,6,0);///CUADRO MENU

 cuadro(59-7,25,1,59+12,6,0);///CUADRO OPC

 cuadro(59-7,17,1,59+12,9,0);///CUADRO VOLVER

   int yy=15;
for(int y=0;y<2;y++)
 {

     if(y==1)
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(54,yy,1,54+16,9,0);///CUADRO CENTRAL
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS
      yy=yy+5;
     }
     else
     {
     cuadro(19,yy,1,19+20,9,0);///CUADROS DERECHOS
     cuadro(89,yy,1,89+20,9,0);///CUADROS IZQUIERDOS

     yy=yy+5;
     }

 }




}

void CUADRO_REALIZAR_BACKUP()
{

    cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();


    cuadro(55-20,8,1,55+37,12,0);

}

void CUADRO_RESTAURAR_BACKUP()
{
    cuadro(5,2,15,2+110,9,0);///CUADRO CONTENDOR

    LOGO();


    cuadro(55-20,8,1,55+37,12,0);

}

void CUADRO_CAMBIAR_CONTRASENIA()
{

    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();

    cuadro(55-13,10,5,55+20,9,0);///cuadro sub contendor

    cuadro(55-13,13,1,55+20,9,0);///cuadro donde se ingresa la contrasenia

    cuadro(55-13,16,1,55+20,9,0);///nueva contrasenia/cartel

    ///TITULO

    gotoxy(50,10);cout<<"CAMBIAR CONTRASENIA"<<endl;

}

void CUADRO_ALTA_CLIENTE()
{

    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();


    cuadro(55-14,7,10,55+21,9,0);///CUADRO SUB CONTENEDOR

    cuadro(55-12,9,1,55+19,9,0);///CUADRO DONDE SE INGRESA EL DNI

    cuadro(55-12,15,1,55+19,9,0);///CARTEL

    ///TITULO

    gotoxy(53,7);cout<<"ALTA CLIENTE"<<endl;
    gotoxy(45,9);cout<<"DNI DEL CLIENTE:";

}

void CUADRO_ALTA_EMPLEADO()
{
    cuadro(5,2,25,2+110,9,0);///CUADRO CONTENDOR

    LOGO();


    cuadro(55-14,7,10,55+21,9,0);///CUADRO SUB CONTENEDOR

    cuadro(55-12,9,1,55+19,9,0);///CUADRO DONDE SE INGRESA EL DNI

    cuadro(55-12,15,1,55+19,9,0);///CARTEL

    ///TITULO

    gotoxy(53,7);cout<<"ALTA EMPLEADO"<<endl;
    gotoxy(45,9);cout<<"DNI DEL EMPLEADO:";


}


void CUADRO_CONTRASENIA()
{

  cuadro(34+2,8,5,34+50,134,136);///cuadro contenedor


  cuadro(34+7,10,1,34+45,134,136);///cuadro donde se ingresara la contrasenia


}



void LOGO()
{
   cuadro(1,1,3,1+12,9,0);
   LETRAR(2,1,2,2,12,'T');
   LETRAR(5,1,3,3,9,'W');
}

#endif // CUADROS&LETRAS_H_INCLUDED
