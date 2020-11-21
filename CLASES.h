#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED






///CLASE FECHA

class FECHA
{
private:
    int dia;
    int mes;
    int anio;
public:

    ///GETS

    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}

    ///SEST


    void setdia(int d){dia=d;}
    void setmes(int m){mes=m;}
    void setanio(int a){anio=a;}


    ///METODOS
    void Cargar(int,int);
    void Mostrar(int,int);
    void MostraLetras(void);

    void fechaAtual(void);
    int operator==(FECHA);

};

void FECHA::Cargar(int px,int py)
{
    int opc;
    gotoxy(px,py);cout<<"FECHA ACTUAL SI=1 NO=0:";///11  15
    opc=validarnumero(px+23,py,0,1,1,55,28);
    if(opc==1)
    {
    fechaAtual();

    gotoxy(px,py+1);cout<<"DIA:";///11 16
    gotoxy(px+4,py+1);cout<<dia<<endl;///15 16

    gotoxy(px+8,py+1);cout<<"MES:";///19 16
    gotoxy(px+12,py+1);cout<<mes<<endl;///23 16

    gotoxy(px+15,py+1);cout<<"ANIO:";///26 16
    gotoxy(px+20,py+1);cout<<anio<<endl;///31 16
    }
    else
    {
    validarfecha(&dia,&mes,&anio,1,1,2020,fecha(1),fecha(2),fecha(3), px, py);
    }


}

void FECHA::Mostrar(int px,int py)
{
    gotoxy(px,py);cout<< dia <<"/"<< mes <<"/"<< anio<<endl;
}

void FECHA::MostraLetras()
{
    char meses[12][10];

    strcpy(meses[0],"ENERO");
    strcpy(meses[1],"FREBRERO");
    strcpy(meses[2],"MARZO");
    strcpy(meses[3],"ABRIL");
    strcpy(meses[4],"MAYO");
    strcpy(meses[5],"JUNIO");
    strcpy(meses[6],"JULIO");
    strcpy(meses[7],"AGOSTO");
    strcpy(meses[8],"SEPTIEMBRE");
    strcpy(meses[9],"OCTUBRE");
    strcpy(meses[10],"NOVIENBRE");
    strcpy(meses[11],"DICIEMBRE");

    cout<<"FECHA:"<<dia <<"_"<<meses[mes-1]<<"_"<<anio<<endl;

}

void FECHA::fechaAtual()
{

   dia=fecha(1);

   mes=fecha(2);

   anio=fecha(3);

}

int FECHA::operator==(FECHA obj)
{
    if(this->dia==obj.getdia() && this->mes==obj.getmes() && this->anio==obj.getanio())
    {
        return 0;
    }

    if(this->mes>obj.getmes())
    {
        return 1;
    }
    if(this->mes<obj.getmes())
    {
        return -1;
    }

    if(this->dia>obj.getdia())
    {
        return 1;
    }
    if(this->dia<obj.getdia())
    {
        return -1;
    }

}


///CLASE DIRECCION
class DIRECCION
{
 private:
     char localidad[20];
     char domicilio[20];
     int numero;

 public:

     ///GETS

     char *getlocalidad(){return localidad;}
     char *getdomicilio(){return domicilio;}
     int getnumero(){return numero;}

     ///SETS

     void setlocalidad(char *loc){strcpy(localidad,loc);}
     void setdomicilio(char *domi){strcpy(domicilio,domi);}
     void setnumero(int num){numero=num;}

     ///METODS

     void Cargar(void);
     void Mostrar(int);

};
///DEFICION DE LAS FUNCIONES

void DIRECCION::Cargar()
{
    fflush(stdin);
    gotoxy(71,7);cout<<"LOCA.:";
    cin.getline(localidad,20);
    gotoxy(71,10);cout<<"DOM.:";
    cin.getline(domicilio,20);
    gotoxy(71,13);cout<<"NUMERO:";
    numero=validarnumero(78,13,100,10000,5,55,28);
}

void DIRECCION::Mostrar(int py)
{
    gotoxy(40,py);cout<< localidad<<endl;
    gotoxy(54,py);cout<< domicilio <<endl;
    gotoxy(67,py);cout<<numero<<endl;
}

///CLASE VENTA DETALLADA
class VENTADETALLADA
{
    private:

    int IDventa;
    int codigoArticulo;
    int cantidad;
    float importe;
    float precio;
    int estado;

    public:
      ///GETS

    int getIDventa(){return IDventa;}
    int getarticulo(){return codigoArticulo;}
    int getcantidad(){return cantidad;}
    float getprecio(){return precio;}
    float getimporte(){return importe;}
    int getestado(){return estado;}

     ///SETS
    void setidventa(int id){IDventa=id;}
    void setarticulo(int ida){codigoArticulo=ida;}
    void setcantidad(int cant){cantidad=cant;}
    void setprecio(float pre){precio=pre;}
    void setimporte(float imp){importe=imp;}
    void setestado(int esta){estado=esta;}

    void Cargar(void);
    void Mostrar(int);

    void GrabarVentaDetallada(void);
    void LeerVentaDetallada(int);
    void GrabarModificacionVentaDetallada(int);


    int operator ==(int idventa)
    {
        if(this->IDventa==idventa)
        {
            return 1;
        }

        return -1;
    }


};

void VENTADETALLADA::Cargar()
{

    gotoxy(47,13);cout<<"PRECIO  :"<<precio<<endl;
    gotoxy(47,16);cout<<"CANTIDAD:";
    cantidad=validarnumero(56,16,1,15,2,55,28);
    importe=cantidad*precio;
    gotoxy(47,19);cout<<"IMPORTE :"<<importe<<endl;
    estado=1;
}

void VENTADETALLADA::Mostrar(int py)
{

    if(estado==1)
    {
        gotoxy(30,py);cout<<IDventa<<endl;
        gotoxy(47,py);cout<<codigoArticulo<<endl;
        gotoxy(62,py);cout<<"$"<<precio<<endl;
        gotoxy(77,py);cout<<cantidad<<endl;
        gotoxy(92,py);cout<<importe<<endl;
    }

}

void VENTADETALLADA::GrabarVentaDetallada()
{
    FILE *p;

    p=fopen(ARCHIVO_VENTAS_DETALLES,"ab");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(VENTADETALLADA),1,p);

    fclose(p);
}

void VENTADETALLADA::LeerVentaDetallada(int posicion)
{
    FILE *p;
    p=fopen(ARCHIVO_VENTAS_DETALLES,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(VENTADETALLADA)*posicion,0);

    fread(this,sizeof(VENTADETALLADA),1,p);

    fclose(p);
}

void VENTADETALLADA::GrabarModificacionVentaDetallada(int posicion)
{
    FILE *p;


    p=fopen(ARCHIVO_VENTAS_DETALLES,"rb+");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(VENTADETALLADA)*posicion,0);

    fwrite(this,sizeof(VENTADETALLADA),1,p);

    fclose(p);
}


///CLASS VENTAS
class VENTAS
{
 private:

    int IDventa;
    int dnicliente;
    int dnivendedor;
    FECHA fch;///COMPOSICION
    float importe;
    int estado;


 public:

    ///GETS
    int getIDventa(){return IDventa;}
    int getidcliente(){return dnicliente;}
    int getvendedor(){return dnivendedor;}
    int getdia(){return fch.getdia();}
    int getmes(){return fch.getmes();}
    int getanio(){return fch.getanio();}
    float getimporte(){return importe;}
    int getestado(){return estado;}

    ///SETS
    void setidventa(int id){IDventa=id;}
    void setidcliente(int idc){dnicliente=idc;}
    void setvendedor(int idv){dnivendedor=idv;}
    void setimporte(int imp){importe=imp;}
    void setdia(int d){fch.setdia(d);}
    void setmes(int m){fch.setmes(m);}
    void setanio(int a){fch.setanio(a);}
    void setestado(int esta){estado=esta;}

    ///METODOS
    void Cargar(void);
    void Mostrar(int &);

    ///

    void grabarVenta(void);///GRABA UN REG VENTA EN EL ARCHIVO ventas.dat
    void leerVenta(int);///LEE UNA REG DEL ARCHIVO MEDIANTE UNA POSICION
    void grabarModificacionVenta(int);///GRABAR UN REG EN UNA POSICION DADA

     void operator +=(float impor)
    {
        importe=importe+impor;
    }

    int  operator ==(VENTADETALLADA obj)
    {
        if(this->IDventa==obj.getIDventa())
        {
            return 1;
        }
        return 0;
    }

};
///DEFINICION DE LOS METODOS

void VENTAS::Cargar()
{

    fch.Cargar(11,15);

    importe=0;

    gotoxy(12,19);cout<<"IMPORTE:"<<importe<<endl;

    estado=1;
}

void VENTAS::Mostrar(int &py)
{

        gotoxy(61,py-2);cout<<"ID VENTA:"<<IDventa<<endl;

        gotoxy(30,py);cout<<"DNI DE CLIENTE :" << dnicliente<<endl;
        py++;
        gotoxy(30,py);cout<<"DNI DE VENDEDOR:"<< dnivendedor<<endl;
        ///fch.MostraLetras();
        gotoxy(79,py-1);cout<<"FECHA:"<<endl;
        fch.Mostrar(85,py-1);
        gotoxy(79,py);cout<<"IMPORTE:"<<importe<<endl;

}


void VENTAS::grabarVenta()
{


    FILE *pv;
    pv=fopen(ARCHIVO_VENTAS,"ab");
    if(pv==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof (VENTAS),1,pv);

    fclose(pv);
}

void VENTAS::leerVenta(int posicion)
{
    FILE *pv;
    pv=fopen(ARCHIVO_VENTAS,"rb");
    if(pv==NULL)
    {
        exit(1);
    }

    fseek(pv,sizeof (VENTAS)* posicion,0);

    fread(this,sizeof (VENTAS),1,pv);

    fclose(pv);
}

void VENTAS::grabarModificacionVenta(int posicion)
{
    FILE *pv;

    pv=fopen(ARCHIVO_VENTAS,"rb+");
    if(pv==NULL)
    {
        exit(1);
    }

    fseek(pv,sizeof (VENTAS)*posicion,0);

    fwrite(this,sizeof (VENTAS),1,pv);

    fclose(pv);
}



///CLASS ARTCICULO

class ARTICULOS
{
private:

    int codigoArticulo;///8 digitod
    char familiaArticulo[20];
    char descripcion[20];
    float precio;
    int Cantidad;
    int stockMinimo;
    int stockMaximo;
    int Nproveedor;///10 digitos
    int estado;

public:

    ///GETS

    int getcodigoArticulo(){return codigoArticulo;}
    char * getfamiliaArticulo(){return familiaArticulo;}
    char * getdescripcion(){return descripcion;}
    float getprecio(){return precio;}
    int getcantidad(){return Cantidad;}
    int getstockminimo(){return stockMinimo;}
    int getstockmaximo(){return stockMaximo;}
    int getNproveedor(){return Nproveedor;}
    int getestado(){return estado;}

    ///SETS

    void setcodigoArticulo(int coda){codigoArticulo=coda;}
    void setfamiliaArticulo(char *famil){strcpy(familiaArticulo,famil);}
    void setnombre(char *des){ strcpy(descripcion,des);}
    void setprecio(float pre){ precio=pre;}
    void setcantidad(int cant){Cantidad=cant;}
    void setstockminimo(int stcmin){stockMinimo=stcmin;}
    void setstockmaximo(int stcmax){stockMaximo=stcmax;}
    void setNproveedor(int nprov){Nproveedor=nprov;}
    void setestado(int est){ estado=est;}

    ///METODOS
    void Cargar(void);
    void Mostrar(int);
    void Familia(int);


    void grabarArticulo();
    void leerArticulo(int);
    void grabarModificacionArticulo(int);


      int operator ==(int codig)///COMPARA EL CODIGO DE ARTICULOS
    {
    	if(this->codigoArticulo==codig)
    	{return 0;}
    	return -1;
	}

	void operator+=(int canti)///AGREGA UNIDADES AL CAMPO CANTIDAD
	{
	    Cantidad=Cantidad+canti;
	}

	void operator-=(int canti)///DESMINUIMOS LA CANTIDAD
	{
	   Cantidad=Cantidad-canti;
	}
	int operator ==(char *famil)
	{
	    if(strcmp(this->familiaArticulo,famil)==0)
        {
            return 0;
        }

        return -1;
    }

};

///DEFICIONES DE MEDOTOS

void ARTICULOS::Cargar()
{
   int opc=0;

    gotoxy(22,7);cout<<"FML ARTICULO:";
    opc=validarnumero(80,25,1,8,1,55,28);
    Familia(opc);
    gotoxy(35,7);cout<<familiaArticulo<<endl;

    fflush(stdin);
    gotoxy(22,10);cout<<"DES:";
    gotoxy(26,10);cin.getline(descripcion,20);
    gotoxy(22,13);cout<<"PRECIO:";
    precio=validarnumero(29,13,1,5000,5,55,28);
    gotoxy(22,16);cout<<"CANTIDAD REALES:";
    Cantidad=validarnumero(38,16,1,50,2,55,28);
    gotoxy(22,19);cout<<"STOCK MAXIMO:";
    stockMaximo=validarnumero(36,19,1,50,2,55,28);
    gotoxy(22,22);cout<<"STOCK MINIMO:";
    stockMinimo=validarnumero(36,22,1,stockMaximo,2,55,28);
    gotoxy(30,24);cout<<"EMPEZAR CON 11"<<endl;
    gotoxy(22,25);cout<<"N.PROVEEDOR:";
    Nproveedor=validarnumero(35,25,1000000000,9999999999,10,55,28);
    estado=1;
}

void ARTICULOS::Mostrar(int py)
{

    gotoxy(3,py);cout<< codigoArticulo<<endl;
    gotoxy(12,py);cout<<familiaArticulo<<endl;
    gotoxy(31,py);cout<<descripcion<<endl;
    gotoxy(55,py);cout<<"$"<<precio<<endl;
    gotoxy(68,py);cout<<Cantidad<<endl;
    gotoxy(79,py);cout<<stockMaximo<<endl;
    gotoxy(93,py);cout<<stockMinimo<<endl;;
    gotoxy(105,py);cout<<Nproveedor<<endl;


}

void ARTICULOS::Familia(int nuf)
{

    if(nuf==1)
    {
      strcpy(familiaArticulo,"DINOSAURIO");
    }
    if(nuf==2)
    {
        strcpy(familiaArticulo,"AUTOS");
    }
    if(nuf==3)
    {
        strcpy(familiaArticulo,"PELUCHES");
    }
    if(nuf==4)
    {
        strcpy(familiaArticulo,"JUEGO DIDACTICO");
    }
    if(nuf==5)
    {
        strcpy(familiaArticulo,"JUEGO DE MESA");
    }
    if(nuf==6)
    {
        strcpy(familiaArticulo,"MUNIECAS");
    }
    if(nuf==7)
    {
        strcpy(familiaArticulo,"MUNIECOS");
    }
    if(nuf==8)
    {
        strcpy(familiaArticulo,"AVIONES");
    }

}


void ARTICULOS::grabarArticulo()
{
    FILE *pa;

    Cargar();

    pa=fopen(ARCHIVO_ARTICULOS,"ab");
    if(pa==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof (ARTICULOS),1,pa);

    fclose(pa);
}

void ARTICULOS::leerArticulo(int posicion)
{
    FILE *pa;

    pa=fopen(ARCHIVO_ARTICULOS,"rb");
    if(pa==NULL){
        exit(1);
    }


     fseek(pa,sizeof (ARTICULOS)*posicion,0);

     fread(this,sizeof (ARTICULOS),1,pa);

    fclose(pa);

}

void ARTICULOS::grabarModificacionArticulo(int posicion)
{
    FILE *pa;

    pa=fopen(ARCHIVO_ARTICULOS,"rb+");
    if(pa==NULL)
    {
        exit(1);
    }

    fseek(pa,sizeof(ARTICULOS)*posicion,0);

    fwrite(this,sizeof(ARTICULOS),1,pa);

    fclose(pa);

}



///CLASE PERSONA

class PERSONA
{
protected:

     int dni;
     char nombre[20];
     char apellido[20];
     DIRECCION dir;
     int edad;
     char sexo;
     int telefono;

public:

    ///GEST

    int  getdni(){return dni;}
    char *getnombre(){return nombre;}
    char *getapellido(){return apellido;}
    char *getlocalidad(){return dir.getlocalidad();}
    char *getdomicilio(){return dir.getdomicilio();}
    int getnumero(){return dir.getnumero();}
    int  getedad(){return edad;}
    char getsexo(){return sexo;}
    int  gettelefono(){return telefono;}


    ///SETS

    void setdni(int d){dni=d;}
    void setnombre(char *nom){strcpy(nombre,nom);}
    void setapellido(char *apell){strcpy(apellido,apell);}
    void setlocalidad(char *loca){dir.setlocalidad(loca);}
    void setdimicilio(char *domi){dir.setdomicilio(domi);}
    void setnumero(int num){dir.setnumero(num);}
    void setedad(int ed){edad=ed;}
    void setsexo(char sex){sexo=sex;}
    void settelefono(int telef){telefono=telef;}

    ///METODOS

    void Cargar(void);
    void Mostrar(int);

};

void PERSONA::Cargar()
{

    fflush(stdin);
    gotoxy(31,10);cout<<"NOMBRE:";
    cin.getline(nombre,20);
    gotoxy(31,13);cout<<"APELLIDO:";
    cin.getline(apellido,20);
    gotoxy(31,16);cout<<"EDAD:";
    edad=validarnumero(36,16,10,100,3,55,28);
    gotoxy(34,18);cout<<"F=FEMENINO M=MASCULINO"<<endl;
    gotoxy(31,19);cout<<"SEXO:";
    gotoxy(36,19);cin>>sexo;
    gotoxy(31,22);cout<<"TELEFONO:";
    gotoxy(39,21);cout<<"EMPEZAR CON 11"<<endl;
    telefono=validarnumero(40,22,1000000000,9999999999,10,55,28);
    dir.Cargar();
}

void PERSONA::Mostrar(int py)
{
    gotoxy(0,py);cout<<dni<<endl;
    gotoxy(12,py);cout<<nombre<<endl;
    gotoxy(25,py);cout<<apellido<<endl;
    dir.Mostrar(py);
    gotoxy(78,py);cout<<edad<<endl;
    gotoxy(85,py);cout<<sexo<<endl;
    gotoxy(92,py);cout<<telefono<<endl;
}

      ///clase derivada cliente

class CLIENTE:public PERSONA
{
  private:
        FECHA fch;///fecha de inscripcion
        int estado;

  public:

        ///GETS

        int getdia(){fch.getdia();}
        int getmes(){fch.getmes();}
        int getanio(){fch.getanio();}
        int getestado(){return estado;}

        ///SEST

        void setdia(int d){fch.setdia(d);}
        void setmes(int m){fch.setmes(m);}
        void setanio(int a){fch.setanio(a);}
        void setestado(int est){estado=est;}

       ///METODOS

       void Cargar(void);
       void Mostrar(int);

       void grabarCliente();
       void leerCliente(int);
       void grabarModificacionCliente(int);

       int operator==(int dni)///COMPARAMOS EL DNI 0 SI SON IGUALES -1 SI SON DISTINTOS
       {
        if(this->dni==dni)
        {
            return 0;
        }
        return -1;
      }

};
///DEFINICION DE LOS METODOS

void CLIENTE::Cargar()
{
    PERSONA::Cargar();
    fch.Cargar(71,22);
    estado=1;
}
void CLIENTE::Mostrar(int py)
{

    PERSONA::Mostrar(py);
    ///fch.MostraLetras();
    fch.Mostrar(107,py);



}

void CLIENTE::grabarCliente()
{
    FILE *pc;

    Cargar();

    pc=fopen(ARCHIVO_CLIENTES,"ab");
    if(pc==NULL)
    {
        exit(1);
    }
    fwrite(this,sizeof (CLIENTE),1,pc);

    fclose(pc);

}

void CLIENTE::leerCliente(int posicion)
{
    FILE *pc;

    pc=fopen(ARCHIVO_CLIENTES,"rb");

    if(pc==NULL)
    {
        exit(1);
    }

    fseek(pc,sizeof (CLIENTE)*posicion,0);

    fread(this,sizeof(CLIENTE),1,pc);

    fclose(pc);

}

void CLIENTE::grabarModificacionCliente(int posicion)
{
    FILE *pc;

    pc=fopen(ARCHIVO_CLIENTES,"rb+");
    if(pc==NULL)
    {
        exit(1);
    }

    fseek(pc,sizeof(CLIENTE)*posicion,0);

    fwrite(this,sizeof(CLIENTE),1,pc);

    fclose(pc);
}


    ///clase derivada empleado

class EMPLEADO: public PERSONA
{
private:

    FECHA fch;///fecha de ingreso
    int estado;

public:

    ///GETS

    int getdia(){return fch.getdia();}
    int getmes(){return fch.getmes();}
    int getanio(){return fch.getanio();}
    int getestado(){return estado;}

    ///SETS

    void setdia(int d){fch.setdia(d);}
    void setmes(int m){fch.setmes(m);}
    void setanio(int a){fch.setanio(a);}
    void setestado(int est){estado=est;}

    ///METODOS

    void Cargar(void);
    void Mostrar(int);

    void grabarEmpleado(void);
    void leerEmpleado(int);
    void grabarModificacionEmpleado(int);

    int operator==(int dniemple)
    {
        if(this->dni==dniemple)
        {
            return 0;
        }

        return -1;
    }

};
///DEFINICION DE METODOS

void EMPLEADO::Cargar()
{
    PERSONA::Cargar();
    fch.Cargar(71,21);
    estado=1;
}
void EMPLEADO::Mostrar(int py)
{
    PERSONA::Mostrar(py);
    ///fch.MostraLetras();
    fch.Mostrar(107,py);


}



void EMPLEADO::grabarEmpleado()
{
    FILE *pe;

    Cargar();


    pe=fopen(ARCHIVO_EMPLEADOS,"ab");
    if(pe==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(EMPLEADO),1,pe);

    fclose(pe);
}

void EMPLEADO::leerEmpleado(int posicion)
{
    FILE *pe;

    pe=fopen(ARCHIVO_EMPLEADOS,"rb");
    if(pe== NULL)
        {
            exit(1);
        }

    fseek(pe,sizeof(EMPLEADO)*posicion,0);
    fread(this,sizeof(EMPLEADO),1,pe);

    fclose(pe);
}

void EMPLEADO::grabarModificacionEmpleado(int posicion)
{
    FILE *pe;
    pe=fopen(ARCHIVO_EMPLEADOS,"rb+");
    if(pe==NULL)
    {
        exit(1);
    }

    fseek(pe,sizeof(EMPLEADO)*posicion,0);

    fwrite(this,sizeof(EMPLEADO),1,pe);

    fclose(pe);

}



///CLASE COMPRA
class COMPRAS
{
private:
      int numeroCompra;
      FECHA fch;
      int codigoarticulo;
      char nombreFamilia[20];
      char descripcion[20];
      int cantidad;
      int Nproveedor;
      int estado;
public:

    ///GEST

    int getnumeroCompra(){return numeroCompra;}
    int getdia(){return fch.getdia();}
    int getmes(){return fch.getmes();}
    int getanio(){return fch.getanio();}
    int getcodigoarticulo(){return codigoarticulo;}
    char *getnombre(){return nombreFamilia;}
    char *getdescripcion(){return descripcion;}
    int getcantidad(){return cantidad;}
    int getnumeroproveedor(){return Nproveedor;}
    int getestado(){return estado;}

    ///SETS

    void setnumeroCompra(int n){numeroCompra=n;}
    void setdia(int d){fch.setdia(d);}
    void setmes(int m){fch.setmes(m);}
    void stanio(int a){fch.setanio(a);}
    void setcodigoarticulo(int codiA){codigoarticulo=codiA;}
    void setnombre(char *nmf){strcpy(nombreFamilia,nmf);}
    void setdescripcion(char *dec){ strcpy(descripcion,dec);}
    void setcantidad(int can){ cantidad=can;}
    void setnumeroproveedor(int np){Nproveedor=np;}
    void setestado(int est){estado=est;}

    ///METODOS

    void Cargar(void);
    void Mostrar(int);

    void grabarComprar(void);
    void leerComprar(int);
    void grabarModificacionComprar(int);


    int operator ==(int numeroCompra)///NUEVO AGREGAR A INFORMA
    {
        if(this->numeroCompra==numeroCompra)
        {
            return 0;
        }
        return -1;
    }

};
///DEFINICION DE LOS METODOS

void COMPRAS::Cargar()
{

    gotoxy(31,13);cout<<"FAMILIA:"<<nombreFamilia<<endl;
    gotoxy(31,16);cout<<"DES:"<<descripcion<<endl;
    gotoxy(31,19);cout<<"CANTIDAD A COMPRAR:";
    cantidad=validarnumero(50,19,1,100,3,70,21);
    fch.Cargar(71,6);

    estado=1;
}

void COMPRAS::Mostrar(int py)
{

    gotoxy(23,py);cout<<numeroCompra<<endl;
    gotoxy(38,py);cout<<codigoarticulo<<endl;
    gotoxy(50,py);cout<<nombreFamilia<<endl;
    gotoxy(68,py);cout<<descripcion<<endl;
    gotoxy(93,py);cout<<cantidad<<endl;
    fch.Mostrar(105,py);
   /// fch.MostraLetras();






}

void COMPRAS::grabarComprar()
{
    FILE *pc;

    Cargar();

    pc=fopen(ARCHIVO_COMPRAS,"ab");
    if(pc==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(COMPRAS),1,pc);

    fclose(pc);
}

void COMPRAS::leerComprar(int posicion)
{
    FILE *pc;

    pc=fopen(ARCHIVO_COMPRAS,"rb");
    if(pc==NULL)
    {
        exit(1);
    }

    fseek(pc,sizeof(COMPRAS)*posicion,0);

    fread(this,sizeof(COMPRAS),1,pc);

    fclose(pc);
}

void COMPRAS::grabarModificacionComprar(int posicion)
{
    FILE *pc;
    pc=fopen(ARCHIVO_COMPRAS,"rb+");
    if(pc==NULL)
    {
        exit(1);
    }

    fseek(pc,sizeof(COMPRAS)*posicion,0);

    fwrite(this,sizeof(COMPRAS),1,pc);

   fclose(pc);
}


///CLASS CONTRASEÑA

class CONTRASENIA
{
private:

    char contrasenia[30];

public:

    char * getcontrasenia(){return contrasenia;}
    void * setcontrasenia(char *cont){strcpy(contrasenia,cont);}
   void Cargar();
   void Mostrar();

   void Grabar();
   void LeerContrasenia();


};
void CONTRASENIA::Cargar()
{
   fflush(stdin);
   cout<<"CONTRASENIA:";
   cin.getline(contrasenia,30);
}

void CONTRASENIA::Mostrar()
{
    cout<<"CONSTRASENIA:"<< contrasenia<<endl;

}

void CONTRASENIA::Grabar()
{
   FILE *p;

   ///Cargar();

   p=fopen("Contrasenia.dat","wb");

   if(p==NULL)
   {
       exit(1);
   }

   fwrite(this,sizeof(CONTRASENIA),1,p);

   fclose(p);
}

void CONTRASENIA::LeerContrasenia()
{
 FILE *p;

 p=fopen("Contrasenia.dat","rb");

 if(p==NULL)
 {
     exit(1);
 }

 fread(this,sizeof(CONTRASENIA),1,p);


 fclose(p);

}




#endif // CLASES_H_INCLUDED
