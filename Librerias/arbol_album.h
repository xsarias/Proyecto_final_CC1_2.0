#ifndef ARBOL_ALBUM_H
#define ARBOL_ALBUM_H
#include <iostream>
#include <string>
#include "estructuras.h"
using namespace std;
template <typename T>
struct nodo_alb{
    T clave;
    nodo_alb *izq, *der;
    bool color;
    nodo_album album;

};
template <typename T>
class Arbol_album{
    nodo_alb<T> *raiz;
public:
    void insertar(T dato, nodo_album album_new);
    nodo_alb<T>* buscar_nodo(T clave);
    nodo_alb<T>* buscarpadre(T dato, nodo_alb<T>* p);
    nodo_alb<T>* buscar_padre(T clave, nodo_alb<T>* raiz);
    void eliminar(T dato);
    void liberar_memoria(nodo_alb<T>* p);
    void rotar_derecha(nodo_alb<T>* base);
    void rotar_izquierda(nodo_alb<T>* base);
    void ajustar_supresion(nodo_alb<T>* x);
    bool arbol_vacio();
    void ajustar_color(nodo_alb<T>* hijo);
};
template <typename T>
nodo_alb<T>* Arbol_album<T>::buscar_nodo(T dato) {
    nodo_alb<T>* actual = raiz;

    
    while (actual != NULL) {
        if (dato == actual->clave) {
            return actual; 
        } else if (dato > actual->clave) {
            actual = actual->der; 
        } else {
            actual = actual->izq; 
        }
    }

    return NULL; // No se encontr? el nodo
}

//buscar padre de un nodo ya insertado
template <typename T>
nodo_alb<T>* Arbol_album<T> :: buscar_padre(T clave, nodo_alb<T>* raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    if ((raiz->izq != NULL && raiz->izq->clave == clave) || 
        (raiz->der != NULL && raiz->der->clave == clave)) {
        return raiz;
    }

    nodo_alb<T>* padre = buscar_padre(clave, raiz->izq);
    if (padre != NULL) {
        return padre;
    }

    return buscar_padre(clave, raiz->der);
}
template <typename T>
void Arbol_album<T>::rotar_derecha(nodo_alb<T>* base) {
    if (base == NULL || base->izq == NULL) return;

    nodo_alb<T>* hijo_izq = base->izq; // El hijo izquierdo de la base ser? la nueva ra?z del sub?rbol
    nodo_alb<T>* padre = buscar_padre(base->clave, raiz); // Encuentra el padre de la base

    // Actualizar el padre de base para que apunte al nuevo nodo ra?z
    if (padre != NULL) {
        if (padre->izq == base) {
            padre->izq = hijo_izq;
        } else {
            padre->der = hijo_izq;
        }
    } else {
        raiz = hijo_izq; // Si base era la ra?z, actualiza la ra?z del ?rbol
    }

    // Actualizar conexiones del sub?rbol
    base->izq = hijo_izq->der; // El hijo derecho del hijo izquierdo se convierte en el hijo izquierdo de la base
    hijo_izq->der = base;      // La base se convierte en el hijo derecho del hijo izquierdo

    // Si el nuevo hijo izquierdo de base no es NULL, actualizamos su relaci?n correctamente
    if (base->izq != NULL) {
        nodo_alb<T>* padre_hijo_izq = buscar_padre(base->izq->clave, raiz);
        if (padre_hijo_izq == hijo_izq) {
            base->izq = hijo_izq->der; // Aseguramos que la conexi?n sea consistente
        }
    }
}
template <typename T>
void  Arbol_album<T>::rotar_izquierda(nodo_alb<T>* base) {
    if (base == NULL || base->der == NULL) return;

    nodo_alb<T>* hijo_der = base->der;
    nodo_alb<T>* padre = buscar_padre(base->clave, raiz); 
    if (padre != NULL) {
        if (padre->izq == base) {
            padre->izq = hijo_der;
        } else {
            padre->der = hijo_der;
        }
    } else {
        raiz = hijo_der; 
    }

    
    base->der = hijo_der->izq; 
    hijo_der->izq = base;     

    
    if (base->der != NULL) {
        nodo_alb<T>* padre_hijo_der = buscar_padre(base->der->clave, raiz);
        if (padre_hijo_der == hijo_der) {
            base->der = hijo_der->izq;
        }
    }
}


template <typename T>
//buscar el padre de un elemento a insertar
nodo_alb<T>* Arbol_album<T>::buscarpadre(T dato, nodo_alb<T>* p) {
    if (p == NULL ) return NULL;

    if (dato > p->clave) {
        if (p->der != NULL) {
            return buscarpadre(dato, p->der);
        } else {
            return p;
        }
    } else if (dato < p->clave) {
        if (p->izq != NULL) {
            return buscarpadre(dato, p->izq);
        } else {
            return p;
        }
    }
    return NULL;
}
template <typename T>
void Arbol_album<T>::insertar(T dato, nodo_album album_new) {
    if (raiz == NULL) {
        raiz = new nodo_alb<T>;
        raiz->clave = dato;
        raiz->izq = NULL;
        raiz->der = NULL;
        raiz->color = false;
        raiz->album = album_new;
        //cout << "Nodo raíz insertado: " << dato << endl;
    } else {
        nodo_alb<T>* padre = buscarpadre(dato, raiz);
        if (padre == NULL) return;
		
        nodo_alb<T>* hijo = new nodo_alb<T>;
        hijo->clave = dato;
        hijo->izq = NULL;
        hijo->der = NULL;
		hijo->color = true;
        hijo->album = album_new;
        if (dato > padre->clave) {
            padre->der = hijo;
            //cout << "Insertado " << dato << " a la derecha de " << padre->clave << endl;
        } else {
            padre->izq = hijo;
            //cout << "Insertado " << dato << " a la izquierda de " << padre->clave << endl;
        }
        if (padre != NULL && padre != raiz) {
            ajustar_color(hijo);
        }
        
    }
    
}
template <typename T>
void Arbol_album<T> :: ajustar_color(nodo_alb<T>* hijo) {
    while (hijo != raiz && hijo->color == true && buscar_padre(hijo->clave, raiz)->color == true) {
        nodo_alb<T>* padre = buscar_padre(hijo->clave, raiz);
        if (padre == NULL) {
            break;
        }

        nodo_alb<T>* abuelo = buscar_padre(padre->clave, raiz);
        if (abuelo == NULL) {
            
            break;
        }

        nodo_alb<T>* tio = (abuelo->izq == padre) ? abuelo->der : abuelo->izq;

        // Caso 1: El padre y el t?o son rojos
        if (tio != NULL && tio->color == true) {

            padre->color = false;
            tio->color = false;
            if(abuelo != raiz){
                abuelo->color = true;
            }else{
            	abuelo -> color = false;
			}
            hijo = abuelo; 
        } else {
            // Caso 2: El padre es rojo, el t?o es negro o NULL
            if (tio == NULL || tio->color == false) {
                if (hijo == padre->der && padre == abuelo->izq) {
                    //cout << "Rotar izquierda en padre (caso 2)" << endl;
                    rotar_izquierda(padre);
                    hijo = padre;
                    padre = buscar_padre(hijo->clave, raiz);
                    abuelo = buscar_padre(padre->clave, raiz);
                    
                } else if (hijo == padre->izq && padre == abuelo->der) {
                    //cout << "Rotar derecha en padre (caso 2)" << endl;
                    rotar_derecha(padre);
                    hijo = padre;
                    padre = buscar_padre(hijo->clave, raiz);
                    abuelo = buscar_padre(padre->clave, raiz);
                }
            }

            // Caso 3: Ajustar colores y rotar en abuelo
            if (padre == abuelo->izq) {
                //cout << "Rotar derecha en abuelo (caso 3)" << endl;
                padre->color = false;
                abuelo->color = true;
                rotar_derecha(abuelo);
            } else {
                //cout << "Rotar izquierda en abuelo (caso 3)" << endl;
                padre->color = false;
                abuelo->color = true;
                rotar_izquierda(abuelo);
            }
        }

        hijo = abuelo; // Continua con el abuelo para verificar el árbol
    }

    if (raiz != NULL) {
        raiz->color = false; // Asegura que la ra?z siempre sea negra
    }
}

template <typename T>
void Arbol_album<T>::ajustar_supresion(nodo_alb<T>* x) {
    if (x == NULL) return;

    nodo_alb<T>* padre = buscar_padre(x->clave, raiz);
    if (padre == NULL) return;

    while (x != raiz && x->color == false) {
        if (x == padre->izq) {
            nodo_alb<T>* hermano = padre->der;
            if (hermano != NULL && hermano->color == true) {
                hermano->color = false;
                padre->color = true;
                rotar_izquierda(padre);
                hermano = padre->der;
            }
            if (hermano == NULL || 
                ((hermano->izq == NULL || hermano->izq->color == false) &&
                 (hermano->der == NULL || hermano->der->color == false))) {
                if (hermano != NULL) {
                    hermano->color = true;
                }
                x = padre;
            } else {
                if (hermano->der == NULL || hermano->der->color == false) {
                    if (hermano->izq != NULL) {
                        hermano->izq->color = false;
                    }
                    if (hermano != NULL) {
                        hermano->color = true;
                    }
                    rotar_derecha(hermano);
                    hermano = padre->der;
                }
                if (hermano != NULL) {
                    hermano->color = padre->color;
                }
                padre->color = false;
                if (hermano != NULL && hermano->der != NULL) {
                    hermano->der->color = false;
                }
                rotar_izquierda(padre);
                x = raiz;
            }
        } else {
            // Código simétrico
            nodo_alb<T>* hermano = padre->izq;
            if (hermano != NULL && hermano->color == true) {
                hermano->color = false;
                padre->color = true;
                rotar_derecha(padre);
                hermano = padre->izq;
            }
            if (hermano == NULL || 
                ((hermano->der == NULL || hermano->der->color == false) &&
                 (hermano->izq == NULL || hermano->izq->color == false))) {
                if (hermano != NULL) {
                    hermano->color = true;
                }
                x = padre;
            } else {
                if (hermano->izq == NULL || hermano->izq->color == false) {
                    if (hermano->der != NULL) {
                        hermano->der->color = false;
                    }
                    if (hermano != NULL) {
                        hermano->color = true;
                    }
                    rotar_izquierda(hermano);
                    hermano = padre->izq;
                }
                if (hermano != NULL) {
                    hermano->color = padre->color;
                }
                padre->color = false;
                if (hermano != NULL && hermano->izq != NULL) {
                    hermano->izq->color = false;
                }
                rotar_derecha(padre);
                x = raiz;
            }
        }
    }
    if (x != NULL) {
        x->color = false;
    }
}



template <typename T>
void Arbol_album<T>::eliminar(T dato) {
    if (raiz == NULL) {
        return;
    }

    nodo_alb<T>* padre = NULL;
    nodo_alb<T>* actual = raiz;

    // Buscar el nodo a eliminar y su padre
    while (actual != NULL && actual->clave != dato) {
        padre = actual;
        if (dato > actual->clave) {
            actual = actual->der;
        } else {
            actual = actual->izq;
        }
    }
	
    if (actual == NULL) {
        //cout << "El nodo con clave " << dato << " no se encuentra en el árbol." << endl;
        return;
    }

    // Caso 1: Nodo hoja
    if (actual->izq == NULL && actual->der == NULL) {
        if (actual == raiz) {
            raiz = NULL;
        } else if (padre->izq == actual) {
            padre->izq = NULL;
        } else {
            padre->der = NULL;
        }
        if(actual->color == false){
        	ajustar_supresion(actual);
		}
        delete actual;
        //cout << "Nodo " << dato << " eliminado (era una hoja)." << endl;
    }
    // Caso 2: Nodo con un hijo
    else if (actual->izq == NULL || actual->der == NULL) {
        nodo_alb<T>* hijo = (actual->izq != NULL) ? actual->izq : actual->der;
        if (actual == raiz) {
            raiz = hijo;
        } else if (padre->izq == actual) {
            padre->izq = hijo;
        } else {
            padre->der = hijo;
        }
        ajustar_supresion(hijo);
        delete actual;
        //cout << "Nodo " << dato << " eliminado (ten?a un hijo)." << endl;
    }
    // Caso 3: Nodo con dos hijos
    else {
        nodo_alb<T>* sucesor = actual->der;
        nodo_alb<T>* padreSucesor = actual;

        while (sucesor->izq != NULL) {
            padreSucesor = sucesor;
            sucesor = sucesor->izq;
        }

        actual->clave = sucesor->clave;
        if (padreSucesor->izq == sucesor) {
            padreSucesor->izq = sucesor->der;
        } else {
            padreSucesor->der = sucesor->der;
        }
        ajustar_supresion(sucesor);
        delete sucesor;
        //cout << "Nodo " << dato << " eliminado (ten?a dos hijos)." << endl;
    }
    //listInorden->VaciarCola();
    
}
#endif