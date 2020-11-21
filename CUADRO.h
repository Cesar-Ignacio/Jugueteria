#ifndef CUADRO_H_INCLUDED
#define CUADRO_H_INCLUDED


void cuadro(int xx, int yy ,int alto, int largo,int colorcuadroyfondo, int fondo)
{
  int x=0,y=yy;
  color("",colorcuadroyfondo);///color puede modificarse
  for(x=0;x<alto;x++)///poner bordes a los costados
  {
      gotoxy(xx,y);cout<<(char)186<<endl;///borde izquierdo
      gotoxy(largo,y);cout<<(char)186<<endl;///borde derecho
      y++;
  }


  for(x=xx;x<=largo;x++)///barras horinzontales
  {
      if(x==xx)///x igual a la posicion de iniciañ de la oracion disminuida en 1
      {
          gotoxy(x,yy-1);cout<<(char)201<<endl;///codo izquierdo arriba
          gotoxy(x,y);cout<<(char)200<<endl;///codo izquierdo invertido abajo
      }
     else if(x==largo)
      {
          gotoxy(x,yy-1);cout<<(char)187<<endl; ///codo derecho  arriba
          gotoxy(x,y);cout<<(char)188<<endl;   ///codo derecho invertido abajo
      }
      else
      {
          gotoxy(x,yy-1);cout<<(char)205<<endl;/// barra superior
          gotoxy(x,y);cout<<(char)205<<endl;   ///barra inferior

      }
  }

///color del fondo
  int yyy=yy;

  for(int t=0;t<alto;t++)
  {
   for(x=xx;x<=largo;x++)
  {
    if(x!=xx && x!=largo)
    {
     color("",fondo);
     gotoxy(x,yyy);cout<<" "<<endl;
    }

  }
  yyy++;
  }

color("",7);///vuelve al color de consola

}
///class

class CUADROS{

private:
      int posicionx;
      int posiciony;
      int alto;
      int largo;
      int colordemarco;
      int colorfondo;

public:

     CUADROS(int px=50, int py=10,int alt=1, int larg=10,int colorM=15,int colorF=0)
     {
       posicionx=px;
       posiciony=py;
       alto=alt;
       largo=larg;
       colordemarco=colorM;
       colorfondo=colorF;
     }

     void setsposicionx(int x){posicionx=x;}
     void setsposiciony(int y){posiciony=y;}
     void setsalto(int alt){alto=alt;}
     void setslargo(int larg){largo=larg;}
     void setscolormarco(int colm){colordemarco=colm;}
     void setscolorfondo(int colf){colorfondo=colf;}

     void mostrar(void);
     void ocultar(void);

     ~CUADROS()
     {
         cout<<"EL OBJETO MURIO"<<endl;
     }

};

void CUADROS::mostrar()
{
    cuadro(posicionx,posiciony,alto,posicionx+largo,colordemarco,colorfondo);
}
void CUADROS::ocultar()
{
    cuadro(posicionx,posiciony,alto,posicionx+largo,0,0);
}



/**
LA FUNCION CUADRADO RECIBE 6 PARA METROS:

cuadrado(PXO,PYO,ALTO,((PXO+TAMAÑO_DE_LA_ORACION)=LARGO),COLOR_CUADRO_FONDO,COLOR_FONDO);

PXO=AQUI SE DEBE PONER EL PUNTO EN "X" DE DONDE EMPIESA LA ORACION.
PY0=AQUI SE DEBE PONER EL PUNTO EN "Y" DE DONDE EMPIESA LA ORACION.
ALTO=AQUI DEBES PODER EL TAMAÑO DEL CUADRADO (EL TAMAÑO CRESE ASIA ABAJO , Y NO ASIA ARRIBA)
LARGO=AQUI SE PONE EL LARGO; QUE ES EL TAMOÑO DE LA ORACION + PXO.
COLOR_CUADRO_FONDO=SE PONE EN NUMEROS EL COLOR DEL MARCO Y EL FONDO QUE TENDRA
COLOR_FONDO=SE PONE EL COLOR DEL FONDO(AREA)DEL MARCO.

copia esto para que veas:
cuadrado(49,4,alto,50+19,192,207);

PARA AGRANDAR EN ANCHURA EL CUADRO LO HACEMOS ASI:

cuadrado(PXO-10,PYO,alto,(LARGO)+10,192,207);/// hacemos que el cuadro sea mas ancho(largo horizontalmente)

ACA VAMOS A SER CRECER EL CUADRO EN 10 PARA LOS DOS LADOS

(PXO-10)=RESTAMOS A PXO 10 PORQUE ESE TIENE QUE CRECER ASIA LA IZQUIERDA.
(LARGO)+10=SUMAMOS A LARGO 10 PORQUE TIENE QUE CRECER ASIA LA DERECHA.


<<<COSAS A TENER EN CUENTA >>>

 Un cuadro es aquivales a 3 lineas.

 ejemplo

 5  ---------------
 6 |  xxxxxxx     |
 7 ---------------
 8   -------------
 9  | xxxxxx     |
 10 -------------

  cuadro  lineas
  1-------3
  9-------27
  por lo tanto para crear 9 cuadro necesitaremos 27 lineas 9*3=27


*/

/**

0 = negro
1 = azul
2 = verde
3 = verdiazul
4 = Marrón
5 = Morado
6 = Verde Mostaza
7 = Gris claro
8 = Gris Oscuro
9 = Azul Rey
10 = Verde Limon
11 = Celeste
12 = Rojo
13 = Rosita/Morado
14 = Amarillo Pollo
15 = Blanco

FORMULA PARA MODIFICAR
Por ejemplo, si queremos texto verde en fondo blanco
sería
2 + 15*16 = 242*/


#endif // CUADRO_H_INCLUDED
