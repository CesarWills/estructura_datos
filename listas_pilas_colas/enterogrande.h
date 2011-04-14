
#ifndef ENTEROGRANDE_H
#define ENTEROGRANDE_H
#include "lista_enteros.h"
#include <string>
using namespace std;

class EnteroGrande
{
public:
    EnteroGrande();
    EnteroGrande(string valor )  ;
    void setValor(string valor);
    string toString() const;

    int size() const;
    int getDigito(int cual) const;
    void setDigito(int valor, int cual);
    void agregarDigito(int valor);  // Insertar Tendria sentido?

    void sumar(const EnteroGrande &N1,const EnteroGrande &N2);
    // Como representar si es negativo ???, ahorita asumir que N1
    // es mayor o igual que N2
   // void restar(const EnteroGrande &N1,const EnteroGrande &N2);


private:
   lista_enteros  digitos;
   int max(int a, int b) { if (a>b) return a; else return b;}

};

#endif // ENTEROGRANDE_H
