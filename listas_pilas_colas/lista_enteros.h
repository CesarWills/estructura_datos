#ifndef LISTA_ENTEROS_H
#define LISTA_ENTEROS_H

class nodo_entero{
public:
    int numero;
    nodo_entero* sig;
    nodo_entero* ant;
    nodo_entero(int val){  sig=ant=0;    numero=val;         }
};

class lista_enteros
{
public:
lista_enteros();
lista_enteros(const lista_enteros &l);
const lista_enteros& operator=(const lista_enteros& l);
void agregar(int valor);
void insertar(int valor, int pos);
int getvalor(int pos)const;
void setvalor(int pos, int valor);
int getlength()const;
~lista_enteros();
void liberar();
void concatenar(const lista_enteros *L);
// Agregada
int buscar(int valor) const;

void borrar_al_inicio();




private:
  nodo_entero* inicio;
  nodo_entero* final;
  nodo_entero* actual;
  int cuantos;

};

#endif // LISTA_ENTEROS_H
