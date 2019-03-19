
#ifndef TPORO_H_
#define TPORO_H_

#include <iostream>
#include <cstring>

using namespace std;

class TPoro
{
  private:
    // Coordenada x de la posición
    int x;
    // Coordenada y de la posición
    int y;
    // Volumen
    double volumen;
    // Color
    char *color;

    void Copia(const TPoro &);
  public:
    // Constructor por defecto
    TPoro();
    // Constructor a partir de una posición y un volumen
    TPoro(int, int, double);
    // Constructor a partir de una posición, un volumen y un color
    TPoro(int, int, double, char *);
    // Constructor de copia
    TPoro(const TPoro &);
    // Destructor
    ~TPoro();
    // Sobrecarga del operador asignación
    TPoro &operator=(const TPoro &);
    // Sobrecarga del operador igualdad
    bool operator==(TPoro &);
    // Sobrecarga del operador desigualdad
    bool operator!=(TPoro &);
    // Modifica la posición
    void Posicion(int, int);
    // Modifica el volumen
    void Volumen(double);
    // Modifica el color
    void Color(char *);

    // Devuelve la coordenada x de la posición
    int PosicionX()const;
    // Devuelve la coordenada y de la posición
    int PosicionY()const;
    // Devuelve el volumen
    double Volumen()const;
    // Devuelve el color
    char *Color() const;
    // Devuelve cierto si el poro está vacío
    bool EsVacio() const;
    // Sobrecarga del operador SALIDA
    friend ostream &operator<<(ostream &,const TPoro &);
};
#endif /* TPORO_H_ */