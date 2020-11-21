#ifndef LETRAS_H_INCLUDED
#define LETRAS_H_INCLUDED

///prototipo

void lineaHorizontal(int ,int ,int );
void lineaVertical(int,int,int);

void lineaDiagonalAscendente(int ,int, int );
void lineaDiagonalDescendente(int ,int,int);

///funciones

void lineaHorizontal(int x,int y,int ancho)
{
   int lhx=0;
   for(lhx=x;lhx<=x+ancho;lhx++)
   {
      gotoxy(lhx,y);cout<<(char)219<<endl;
   }
}

void lineaVertical(int x,int y,int largo)
{
  int lvy=0;
  for(lvy=y;lvy<=y+largo;lvy++)
  {
      gotoxy(x,lvy);cout<<(char)219<<endl;
  }
}

void lineaDiagonalAscendente(int x,int y, int ancho)
{
    int px=0,py=y;

    for(px=x+1;px<=x+ancho;px++)
    {
        gotoxy(px,py);cout<<(char)219<<endl;
        py=py-1;
    }
}

void lineaDiagonalDescendente(int x, int y,int ancho)
{
    int px=0,py=y;

    for(px=x+1;px<=x+ancho;px++)
    {
        gotoxy(px,py);cout<<(char)219<<endl;

        py=py+1;
    }
}

void LETRAR(int x, int y,int ancho,int largo,int colorletra,char letrar )
{

color("",colorletra);

   if(letrar=='s' || letrar=='S')
   {
  lineaHorizontal(x,y,ancho);///HORIZONTAL SUPERIO

  lineaVertical(x,y,largo);///VERTIVAL SUPERIO

  lineaHorizontal(x,(y+largo)+1,ancho);///HORIZONTAL MEDIO

  lineaVertical(x+ancho,(y+largo)+1,largo);///VRTICAL INFERIOS

  lineaHorizontal(x,(y+largo*2)+2,ancho);///HORIZOBTAL INFERIOR
   }
   if(letrar=='d' || letrar=='D')
   {

    lineaHorizontal(x,y,ancho-1);///LINEA HORIZONTAL SUPERIOR

    lineaHorizontal(x,y+largo,ancho-1);///LINEA HORIZONTAL INFERIOR

    lineaVertical(x,y+1,largo-1);///LINEA VERTICAL IZQUIERDA

    lineaVertical(x+ancho,y+1,largo-2);///LINEA VERTICAL DERECHA

   }
   if(letrar=='o' || letrar=='O')
    {
    lineaHorizontal(x,y,ancho);

    lineaHorizontal(x,(y+largo)+1,ancho);

    lineaVertical(x,y+1,largo-1);

    lineaVertical(x+ancho,y+1,largo-1);
    }
   if(letrar=='c' || letrar=='C')
   {
    lineaHorizontal(x,y,ancho);///LINEA SUPERIOR

    lineaHorizontal(x,(y+largo)+1,ancho);///LINIA INFERIOR

    lineaVertical(x,y,largo);///LINIEA IZQUIERDA
   }
   if(letrar=='a' || letrar=='A')
   {
     lineaHorizontal(x,y,ancho);///LINEA SUPERIO

     lineaHorizontal(x,y+(largo/2),ancho);///LENIA MEDIA

     lineaVertical(x,y,largo);///LINEA IZQUIERDA

     lineaVertical(x+ancho,y,largo);///LINEA DERECHA
   }
   if(letrar=='e'  || letrar=='E')
   {
       lineaHorizontal(x,y,ancho);///LINEA SUPERIOR

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA MEDIA

       lineaHorizontal(x,y+largo,ancho);///LINEA INFERIOS

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

   }
   if(letrar=='f' || letrar=='F')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOS

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZONTAL MEDIA

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

   }

   if(letrar=='l' || letrar=='L')
   {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaHorizontal(x,(y+largo),ancho);///LINEA HORINZONTAL INFERIOR
   }

   if(letrar=='j' || letrar=='J')
   {
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZAONTAL INFERIOR
   }
   if(letrar=='i' || letrar=='I')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOR
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZAONTA INFERIOR
       lineaVertical(x+(ancho/2),y,largo);///LINEA VERTICAL
   }
   if(letrar=='h' || letrar=='H')
   {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA MEDIA

       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
   }
   if(letrar=='t' || letrar=='T')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR

       lineaVertical(x+(ancho/2),y,largo);///LINEA VERTICAL MEDIA

   }
   if(letrar=='p' || letrar=='P')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZANTAL SUPERIOR

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZAONTAL MEDIA

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

       lineaVertical(x+ancho,y,largo/2);///LINEA VERICAL DERECHA

   }
   if(letrar=='u' || letrar=='U')
   {
       lineaHorizontal(x,y+largo+1,ancho);///LINEA HORIZAONTAL INFERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
   }
   if(letrar=='k' || letrar =='K')
   {
      if(largo%2==0 && ancho==0)
      {
       ancho=(largo/2)+1;

       lineaVertical(x,y,largo);///LINEA VERTICAL IZUIERDA

       lineaDiagonalAscendente(x,y+(largo/2),ancho);///LINEA DIAGONAL ASCENDENTE

       lineaDiagonalDescendente(x,y+(largo/2),ancho);
      }
      else
      {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"LARGO DEBE SER PAR y ANCHO=0"<<endl;
      }

   }
   if(letrar=='b' || letrar=='B')
   {
    lineaHorizontal(x,y,ancho-1);///LINEA HORIZAONTAL SUPERIOR

    lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZAONTAL MEDIA

    lineaHorizontal(x,y+largo,ancho-1);///LINEA HORIZAONTAL INFERIOS

    lineaVertical(x,y,largo);///LINEA VERTICAL

    lineaVertical(x+ancho,y+1,largo-2);///LINEA VERTICAL DERECHA

   }

   if(letrar=='z' || letrar=='Z')
   {
       if(largo==ancho)
       {

       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR

       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZONTAL INFERIOR

       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
       }
       else
        {
        gotoxy(x,y);cout<<"ERROR"<<endl;
        gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }


   }

   if(letrar=='n' || letrar=='N')
   {
       if(ancho==largo)
       {
          lineaVertical(x,y,largo);///LINEA VERTICAL OZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTCICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho);///DIAGONAL DESCENDENTE
       }
       else
        {
         gotoxy(x,y);cout<<"ERROR"<<endl;
         gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }
   }

   if(letrar=='_' )
   {
      if(ancho==largo)
      {
       lineaHorizontal(x+1,y-1,ancho-2);///LINEA HORIZONTAL ACENTO
       lineaVertical(x,y,largo);///LINEA VERTICAL  IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho);///LINEA DIAGONAL DESCENDENTE
      }
      else
      {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
      }

   }

   if(letrar=='g' || letrar=='G')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZONTAL INFERIOR
       lineaHorizontal(x+2,y+(largo/2),ancho-2);///LINEA HORIZAONTAL MEDIA
       lineaVertical(x+ancho,y+(largo/2),largo/2);///LINEA VERTICAL DERECHA
   }

   if(letrar=='x' || letrar=='X')
   {
       if(ancho==largo)
       {
       lineaDiagonalDescendente(x,y,ancho);///LINEA DIAGONAL DESCENDENTE

       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
       }
       else
        {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }


   }
   if(letrar=='y' || letrar=='Y')
   {
      if(largo==ancho)
      {
       lineaDiagonalDescendente(x,y,ancho/2);///LINEA DIAGONAL DESCENDENTE
       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
      }
      else
      {
         gotoxy(x,y);cout<<"ERROR"<<endl;
         gotoxy(x,y+1);cout<<"EL ANCHO==LARGO"<<endl;
      }


   }
   if(letrar=='v' || letrar=='V')
   {
       if(ancho==largo)
       {
         lineaDiagonalDescendente(x,y,ancho);
       lineaDiagonalAscendente(x+ancho,(y+largo)-2,ancho-1);
       }
       else
        {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"DEBE SER ANCHO==LARGO "<<endl;
        }

   }
   if(letrar=='r' || letrar=='R')
   {
      if(largo%2==0 && ancho==largo-1)
      {
        lineaHorizontal(x,y,ancho);
        lineaVertical(x,y,largo);
        lineaVertical(x+ancho,y,largo/2);
        lineaHorizontal(x,y+(largo/2),ancho);
        lineaDiagonalDescendente(x,y+(largo/2)+1,largo/2);
      }
      else
        {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"LARGO PAR Y ANCHO==LARGO-1"<<endl;
        }

   }
   if(letrar=='w' || letrar=='W')
   {
       if(ancho==largo)
       {
        lineaDiagonalDescendente(x,y,ancho);
       lineaDiagonalAscendente(x+ancho,(y+largo)-2,ancho-1);

       lineaDiagonalDescendente((x+ancho)-1,y,ancho);
       lineaDiagonalAscendente((x+(ancho*2))-1,(y+largo)-2,ancho-1);
       }
       else
       {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"DEBE SER ANCHO==LARGO "<<endl;
       }
   }
   if(letrar=='q' || letrar=='Q')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaHorizontal(x,y+largo,ancho+1);///LINEA HORIZONTAL SUPERIOR
       lineaDiagonalDescendente((x+ancho)-2,(y+largo)-1,2);///LINEA DIAGONAL DESCENDENTE
   }
   if(letrar=='m' || letrar=='M')
   {
       ///EL ANCHO DEBE SER PAR

       if(ancho%2==0)
       {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho/2);///LINEA DIAGONAL DESCENDENTE
       lineaDiagonalAscendente(x+(ancho/2),(y+(ancho/2))-1,ancho/2);///LINEA DIAGONAL ASCENDENTE
       }
       else
       {
        gotoxy(x,y);cout<<"ERROR"<<endl;
        gotoxy(x,y+1);cout<<"EL ANCHO BEBE SER PAR"<<endl;
       }
   }





 color("",7);
}


///CLASS

class LETRA{

  private:

      int posicionX;
      int posicionY;
      int ancho;
      int largo;
      int colorLetra;
      char letra;

  public:



      LETRA(int x=0,int y=0,int anch=8,int larg=5,int colo=15,char letr={'m'})
      {
          posicionX=x;
          posicionY=y;
          ancho=anch;
          largo=larg;
          colorLetra=colo;
          letra=letr;
      }

      void setsposicionX(int x)
      {
          posicionX=x;
      }
      void setsposicionY(int y)
      {
          posicionY=y;
      }
      void setsancho(int anch)
      {
          ancho=anch;
      }
      void setslargo(int larg)
      {
          largo=larg;
      }
      void setscolorletra(int col)
      {
          colorLetra=col;
      }
      void setsletra(char let)
      {
          letra=let;
      }
      void mostrar();
      void ocultar();

     ~LETRA()
     {
         cout<<"EL OBJETO MURIO"<<endl;
     }

};

void LETRA::mostrar()
{
    LETRAR(posicionX,posicionY,ancho,largo,colorLetra,letra);
}
void LETRA::ocultar()
{
LETRAR(posicionX,posicionY,ancho,largo,0,letra);
}







/* LA FUNCION LETRAR()

   *RECIBE 6 PARAMETROS

   void LETRAR(int x, int y,int ancho,int largo,int colorletra,char letrar )

   x= LA POSICION EN X
   y= LA POSICION EN Y
   ancho= ANCHO QUE TENDRA LA LETRA (HORIZAONTALMENTE)
   largo= LARGO QUE TENDRA LA LETRA (VERTICALMENTE)
   colorletra= NUMERO DEL COLOR DE LA LETRA
   letra= LETRA QUE SE SE IMPRIMIRA POR PANTALLA


   *LAS FUNCIONES
       ->lineaHorizontal():NOS IMPRIMIRA UNA LINEA HORIZAONTA CON RESPECTO A LOS VALORES QUE SE LE ENVIAN
                           RECIBE - 3 PARAMETROS
                           void lineaHorizontal(int x,int y,int ancho)
       ->lineaVertical():NOS IMPRIME UNA LINEA VERTICAL  CON RESPETOS A LOS VALORES QUE SE ENVIAN COMO PARAMETROS
                         RECIBE - 3 PARAMETROS
                         void lineaVertical(int x,int y,int largo)


   *COSAS A TENER EN CUENTA

    **CUANDO QUEREMOS IMPREIR LA LETRA K
    TENEMOS QUE HACER UNA OPERACION .

    EL ANCHO SERA IGUAL A METAD DEL LARGO +1;

    LARGO=18;
    ANCHO=(18/2)+1; =10

    EJEMPLO:

    LETRAR(50,9,(10/2)+1,10,5,'k');

      *FUNCIONA SOLO COM NUMEROS PARES
      *AL PONER UN NUMERO IMPAR LA LETRA QUE DARA INCOMPLETA ,CON LA FALTA DE UN CUBO

   **CUANDO QUEREMOS INCRIBIR LA "Z" O LA "N" O "X" ,"Y" ,"V","W"
     TANTO EL LARGO COMO EL ANCHO DEBEN SER IGUALES

     EJEMPLO:

     LETRAR(7,10,6,6,8,'z');
     LETRAR(15,10,6,6,6,'n');
     LETRAR(50,10,7,7,8,'X');
     LETRAR(46,10,7,7,4,'y');


   **CUANDO QUE REMOS ESCRIBIR "R"
     EL ANCHO VA A HACER IGUAL A = LARGO-1;

     EL NUMERO DEL LARGO DEBE SER PAR:

     NUMERO IMPAR:
     PROEBE:
     EJEMPLO:
     largo=7;
     ancho=7-1;
     LETRAR(69,10,6,7,4,'r');

     NUMERO PAR:
     PRUEBE:
     EJEMPLO:
     largo=8;
     ancho=8-1=7
     LETRA(69,10,7,8,4,'r');


     INFORMACION DE CADA LETRA:

     A: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     B: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     C: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     D: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     E: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     F: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     G: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     H: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     I: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     J: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     K: EL LARGO DEBE SER PAR Y EL ANCHO=(LARGO/2)+1;
     L: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     M: EL ANCHO DEBE SER UN NUMERO PAR , EL LARGO PUEDE SER CUALQUIER NUMERO(PAR O IMPAR)
     N: EL ANCHO Y EL LARGO DEBEN SER DOS NUMERO IGULAES
     Ñ: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGUALES
     O: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     P: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     Q: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     R: EL ANCHO VA HACER EL LARGO -1 Y EL NUMERO DEL LARGO DEBE SER PAR
     S: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     T: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     U: EL ANCHO Y EL LARGO PUEDEN SER CUALQUIER NUMERO
     V: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGUALES
     W: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGUALES
     X: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGUALES
     Y: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGUALES
     Z: EL ANCHO Y EL LARGO DEBE SER DOS NUMEROS IGULAES
*/


#endif // LETRAS_H_INCLUDED
