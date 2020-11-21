#ifndef VALIDAR_FECHA_H_INCLUDED
#define VALIDAR_FECHA_H_INCLUDED


///PROTOTIPO

int fecha(int );
int comparacionfecha(int,int,int,int,int,int);
void validarfecha(int *,int *,int * ,int,int,int,int,int,int,int,int);
///FUNCIONES


int fecha(int dma)///INFORMACIO DE LA FECHA ACTUAL
{

  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  ///gotoxy(10,8);printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d",tmPtr->tm_mday, tmPtr->tm_mon+1,1900+tmPtr->tm_year,tmPtr->tm_hour,tmPtr->tm_min,tmPtr->tm_sec);
   ///gotoxy(10,6);cout<<" FECHA ACTUAL " <<endl;
  ///gotoxy(10,7);printf("%d/%d/%d ",tmPtr->tm_mday,tmPtr->tm_mon+1,1900+tmPtr->tm_year);///,tmPtr->tm_hour,tmPtr->tm_min,tmPtr->tm_sec);
 /// tmPtr->tm_mday;      numero del dia del mes
 /// tmPtr->tm_mon+1;     numero del mes
 /// 1900+tmPtr->tm_year; numero del año
 /// tmPtr->tm_hour; hora
 /// tmPtr->tm_min;  minutos
 /// tmPtr->tm_sec;  segundos
  ///strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
  ///gotoxy(10,8);printf("%s", cad);

  if(dma==1)
  {
   return tmPtr->tm_mday;
  }
  if(dma==2)
  {
   return tmPtr->tm_mon+1;
  }
  if(dma==3)
  {
   return tmPtr->tm_year+1900;
  }

}

int comparacionfecha(int d1,int m1,int a1,int d2, int m2, int a2)///COMPARACION
{

    if(d1==d2 && m1==m2 && a1==a2)
    {
        return 0;
    }
    if(a1>a2)
    {
        return 1;
    }
    if(a1<a2)
    {
        return -1;
    }
    if(a1==a2)
    {
    	if(m1>m2)
    	{
    		return 1;
		}
		if(m2>m1)
		{
			return -1;
		}
		if(m1==m2)
		{
			if(d1>d2)
			{
				return 1;
			}
			if(d2>d1)
			{
				return -1;
			}
		}
    }
}


void validarfecha(int *dia,int  *mes, int  *anio, int diainicio,int mesinicio,int anioinicio,int diafin,int mesfin,int aniofin,int px,int py)///VALIDACION DE FECHA
{
  while(comparacionfecha(*dia,*mes,*anio,diainicio,mesinicio,anioinicio)!=1 || comparacionfecha(*dia,*mes,*anio,diafin,mesfin,aniofin)!=-1)
  {
    ///atencion1("FECHA INVALIDA DA DEBE",87,8,"INTERVALO DE FECHA ",87,9,"[15/3/2020;FECHA ACTUAL]",87,10);

    gotoxy(px,py+1);cout<<"DIA:";

   *dia=validarnumero(px+4,py+1,1,31,2,55,28);

   gotoxy(px+8,py+1);cout<<"MES:";

   *mes=validarnumero(px+12,py+1,1,12,2,55,28);

    gotoxy(px+15,py+1);cout<<"ANIO:";

   *anio=validarnumero(px+20,py+1,1999,2020,4,55,8);

  }
}

#endif // VALIDAR_FECHA_H_INCLUDED
