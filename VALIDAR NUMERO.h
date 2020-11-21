#ifndef VALIDAR_NUMERO_H_INCLUDED
#define VALIDAR_NUMERO_H_INCLUDED

///PROTOTIPO

int validarnumero(int,int,int,int,int,int,int);

int filtro_caracter(int,int,int,int,int);///VERIFICA QUE NO SE INGRESE UN CARACTER

///FUNCIONES

int  filtro_caracter(int px,int py, int cantAingresar ,int pxAT,int pyAT){

  int valor;
    int z=0;
    for(z=px;z<px+cantAingresar;z++)
    {
     gotoxy(z,py);cout<<"*    "<<endl;///BORRAMOS EL CONTENIDO ANTERIOR
    }

    gotoxy(px,py);std::cin >> valor;
    if( !std::cin.good() )
    {


      gotoxy(pxAT,pyAT);cout<<"ERROR"<<endl;
      ///atencion1("ERROR : ",87,8,"SE A DETECTADOS UN CARACTER ",87,9,"O A INGRESADO UN ALGO MAL !!!",87,10);
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

      Sleep(5000);

      gotoxy(pxAT,pyAT);cout<<"        "<<endl;
     /// atencion1("",88,8,"",88,9,"",88,10);///BORRAMOS

      return -1;
    }
    else
     {return valor;}


  ///std::cout << var;

}

int validarnumero(int px, int py,int inicio, int fin,int cantAingresar,int pxAtencion, int pyAtencion)
{
    int num;

    num=filtro_caracter(px,py,cantAingresar,pxAtencion,pyAtencion);

    while(num==-1 || num>fin || num<inicio)
    {
    num=filtro_caracter(px,py,cantAingresar,pxAtencion,pyAtencion);
    }
    return num;
}


/**
INFORMACION

ESTA FUNCION RECIBE 4 PARAMETROS

 int  filtro_caracter(int px,int py, int cantAingresar)

 px=POSICION EN X DONDE SE ESCRIBIRA
 PY=PISICION EN Y DONDE SE ESCRIBIRA
 cantAingresar= LA CANTIDAD DE NUMEROS QUE SE DEBEN INGRESAR EN UN DETERMINADO CAMPO

 LA FUNCION DE VUELVE UN -1 O UN NUMERO ENTERO (1,2,3..........99999..)

 -1= SI DEVUEL -1 SERA PORQUE SE INGRESO UNA LETRA
 N_ENTERO= SERA EL NUMERO QUE SE INGRESO.



*/

/*
INFORMACION DE LA FUNCION

LA FUNCION RECIBE 7 PARAMETRO.

int validarnumero(int px, int py,int inicio, int fin,int cantAingresar,int pxAtencion, int pyAtencion)

px=POSICION DE X DONDE SE ESCRIBIRA
PY=POSICION DE Y DONDE SE ESCRIBIRA
INICIO=CONDICION
FIN=CONDICION
cantAingresar= LA CATIDAD DE NUMERO QUE SE VA A INGRESAR (DIBUJA LOS *)
pxAtencion=POSICION EN "X" DONDE SE MOSTRARA EL CARTEL ATENCION
pyAtencion=POSICION EN "Y" DONDE SE MOSTRARA EL CARTEL ATENCION


INCIO/FIN ***

SON LOS QUE VAN A CONDICIONAR O MOLDEAR EL NUMERO PARA LUEGO RETORNARLO

EJEMPLO

incio=10;
fin=20;

int validarnumero(int px, int py,int inicio, int fin,int cantAingresar)

LEEMOS LA FUNCION DE LA SIGUIENTE MANERA:

EL NUMERO QUE RETORNARA NO BEBE SER MENOR QUE INICIO(10) NI MAYOR QUE FIN Y POR ECHO NO BEBE SER UN CARACTER


while(num==-1 || num>fin || num<inicio)/// ACA PARA QUE SALGA DE WHILE NO SE DEBE CUMPLIR NIGUNA DE LAS CONDICIONES
    {
    num=filtro_caracter(px,py,cantAingresar);
    }

POR LO TANTO SALDRA CUANDO "num" SE DISTINDO QUE -1 (NO ES UN CARACTER) Y A SU VES SEA MENOR QUE "fin" y MAYOR QUE INICIO

si "num" = 7;

retornaria "num" y saldria del while

PORQUE "num(7)" NO ES IGUAL QUE  -1 ,NO ES MAYOR QUE  "fin(20)" NI TAMPOCO ES MENOR QUE "inicio(10)"




*/

#endif // VALIDAR_NUMERO_H_INCLUDED
