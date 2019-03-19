#include "tvectorporo.h"

// Constructor por defecto
TVectorPoro::TVectorPoro(){
    datos=NULL;
    dimension=0;

}

// Constructor a partir de una dimensión
TVectorPoro::TVectorPoro(int d){
datos=NULL;
if(d<=0){
dimension=0;
}else{
dimension=d;
datos= new TPoro[d];

}
}
// Constructor de copia
TVectorPoro::TVectorPoro(const TVectorPoro &vp){
datos = NULL;
Copia(vp);
}

void TVectorPoro::Copia(const TVectorPoro &vp){
dimension=vp.dimension;
delete datos;
datos = new TPoro[vp.dimension];
for(int i=0 ;i<dimension;i++){
datos[i]= vp.datos[i];
}
error=vp.error;
}
// Destructor
TVectorPoro::~TVectorPoro(){
    delete datos;
    dimension=0;
    datos= NULL;

}
// Sobrecarga del operador asignación
TVectorPoro & TVectorPoro::operator=(const TVectorPoro &vp){
if(this!=&vp){
    (*this).~TVectorPoro();
    Copia(vp);
}

return *this;
}

// Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &) const{

}
// Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &) const{

}
// Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro & TVectorPoro::operator[](int){

}
// Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](int) const{

}
// Devuelve la longitud (dimensión) del vector
int TVectorPoro::Longitud()const{

}
// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
int TVectorPoro::Cantidad()const{

}
// REDIMENSIONAR el vector de TPoro
bool TVectorPoro::Redimensionar(int){

}

// Sobrecarga del operador salida
ostream & operator<<(ostream &os,const TVectorPoro &vp){

}
