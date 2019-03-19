#include "tporo.h"

// Constructor por defecto
TPoro::TPoro()
{
    x=0;
    y=0;
    volumen=0;
    color=NULL;
}
//TODO volumen negativo permitido
// Constructor a partir de una posición y un volumen
TPoro::TPoro(int x, int y, double volumen)
{
}
// Constructor a partir de una posición, un volumen y un color
TPoro::TPoro(int x, int y, double volumen, char *color)
{
    this->x=x;
    this->y=y;
    this->volumen=volumen;

    if(color==NULL){
        this->color=NULL;
    }else{
        
        //TODO revisar esto con detenimiento !!!!
        this->color=new char (strlen(color) + 1);
        
        for(int i=0 ;i<strlen(color);i++){
            this->color[i]=tolower(color[i]);
           
        }
        this->color[strlen(color) + 1]='\0';
        
    }
    
    
}
// Constructor de copia
TPoro::TPoro(const TPoro &p)
{
    Copia(p);
}
// Destructor
TPoro::~TPoro()
{
    x = 0;
    y = 0;
    volumen = 0;
	if(color != NULL) {
		delete[] color;
		color = NULL;
    }
}
// Sobrecarga del operador asignación
TPoro &TPoro::operator=(const TPoro &p)
{
    if(this != &p) {
		(*this).~TPoro();
		Copia(p);
	}

return *this;
}

void TPoro::Copia(const TPoro &p){

    this->x=p.x;
    this->y=p.y;
    this->volumen=p.volumen;

    Color(p.color);
    
}
// Sobrecarga del operador igualdad
bool TPoro::operator==(TPoro &p)
{
    if(x==p.x && y==p.y && volumen==p.volumen){
        if(
        (color == NULL && p.color == NULL) ||
        (color != NULL && p.color != NULL && strcmp(color,p.color) == 0)
        ){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }

}
// Sobrecarga del operador desigualdad
bool TPoro::operator!=(TPoro &p)
{
    return (*this==p);
}
// Modifica la posición
void TPoro::Posicion(int x, int y)
{
    this->x=x;
    this->y=y;
}
// Modifica el volumen
void TPoro::Volumen(double v)
{
    this->volumen=v;
}
// Modifica el color
void TPoro::Color(char *c)
{
    if(c==NULL){
        this->color=NULL;
    }else{
        
        //TODO revisar esto con detenimiento !!!!
        this->color=new char (strlen(c) + 1);

        strcpy(this->color,c);
    }
}
// Devuelve la coordenada x de la posición
int TPoro::PosicionX() const
{
    return x;
}
// Devuelve la coordenada y de la posición
int TPoro::PosicionY() const
{
    return y;
}
// Devuelve el volumen
double TPoro::Volumen() const
{
    return volumen;
}
// Devuelve el color
char *TPoro::Color() const
{
    return color;
}
// Devuelve cierto si el poro está vacío
bool TPoro::EsVacio() const
{
    if( x==0 && y==0 && volumen==0 && color==NULL){
        return true;
    }else{
        return false;
    }

}
// Sobrecarga del operador SALIDA
ostream &operator<<(ostream & os,const TPoro & p)
{
	if(!p.EsVacio()){
        os.setf(ios::fixed);
		os.precision(2);
		os << "(" << p.x << ", " << p.y << ") " << p.volumen << " ";
		
        if(p.color != NULL){
            os << p.color;
        }else{
            os << "-";
        } 
         
    }else {
		os << "()";
	}
return os;
}
