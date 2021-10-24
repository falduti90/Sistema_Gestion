#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include "Agencia.h"

Agencia::Agencia() {
    _IdAgencia=0;
    strcpy(_NombreAgencia,"NO SE INGRESO EL NOMBRE DE LA AGENCIA");
    _DisponibilidadMensual=0;
    _GastosLocales=0;
    _Activo=true;

}

int     Agencia::setIdAgencia(int NuevoID) {
    _IdAgencia=NuevoID;
}

char    Agencia::setNombreAgencia(char * NuevoNombre) {
    strcpy(_NombreAgencia,NuevoNombre);
}

int     Agencia::setDisponibilidadMensual(int NuevoCupo) {
    _DisponibilidadMensual=NuevoCupo;
}

float   Agencia::setGastosLocales(float NuevoGasto) {
    _GastosLocales=NuevoGasto;
}

bool    Agencia::setActivo(bool NuevoEstado) {
    _Activo=NuevoEstado;
}
int     Agencia::getIdAgencia(){
    return _IdAgencia;
}

char *  Agencia::getNombreAgencia() {
    return _NombreAgencia;
}

int     Agencia::getDisponibilidadMensual() {
    return _DisponibilidadMensual;
}

float   Agencia::getGastosLocales() {
    return _GastosLocales;
}

bool    Agencia::getActivo() {
    return _Activo;
}

void    Agencia::Cargar() {
    cout<< "INGRESE EL NUMERO DE ID DE LA AGENCIA: ";
    cin>> _IdAgencia;

    cout<< "INGRESE EL NOMBRE DE LA AGENCIA: ";
    cin.ignore();
    cin.getline(_NombreAgencia,29);

    cout<< "INGRESE LA DISPONIBILIDAD MENSUAL: ";
    cin>> _DisponibilidadMensual;

    cout<< "INGRESE LOS GASTOS LOCALES: ";
    cin>> _GastosLocales;

}

void    Agencia::Mostrar() {
    cout<< "ID AGENCIA            :"<<"\t"<< _IdAgencia<<endl ;
    cout<< "NOMBRE AGENCIA        :"<<"\t"<< _NombreAgencia<<endl;
    cout<< "DISPONIBILIDAD MENSUAL:"<<"\t"<< _DisponibilidadMensual<<endl;
    cout<< "GASTOS FIJOS          :"<<"\t"<< _GastosLocales<<endl;

   // cout<< "|  ID AGENCIA  |    NOMBRE     |  DISPONIBILIDAD  |  GASTOS  | "<<endl;
}

bool    Agencia::leerDeDisco(int pos) {
        FILE *p;
        p=fopen("Agencias.dat","rb");
        if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }

        fseek(p,sizeof(Agencia)*pos,0);
        bool leyo=fread(this, sizeof(Agencia), 1, p);
        fclose(p);
        return leyo;

}
bool    Agencia::grabarEnDisco() {

    FILE *p;
    p=fopen("Agencias.dat","ab");
    if(p==NULL)
    {
        cout<< "No se pudo abrir el archivo docentes";
        return false;
    }
    bool ok=  fwrite(this,sizeof(Agencia),1,p);
    if (ok==true)
    {
        cout<< "Registro guardado"<<endl;
    }
    else
    {
        cout<< "No se guardo el registro"<<endl;
    }
    fclose(p);


}


//-------------------------------------------------------------------------------------------------
//FUNCIONES GLOBALES

void ListadoDeAgencias(){

    FILE *p;
    Agencia reg;
    p=fopen("Agencias.dat","rb");
    if(p==NULL){
        cout<< "No se pudo abrir el archivo docentes";
    return ;
    }

    while(fread(&reg,sizeof(Agencia),1,p)==1){
        reg.Mostrar();
        cout << endl;
    }

    fclose(p);
}
