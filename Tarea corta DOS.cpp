#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sstream>
#include <map>
#include <cmath> 
#include <typeinfo>
#include <iomanip>

using namespace std;


//////////////////////////////////////////////////////////ARBOL BINARIO DE BUSQUEDA//////////////////////////////////////////////////////////
class NodoBinario{
	public:
		NodoBinario(){
		}
	
		NodoBinario(string v, NodoBinario*i, NodoBinario*d){
		valor = v;
		Hizq = i;
		Hder = d;
		}
		
		NodoBinario(string v){
		valor = v;
		Hizq = NULL;
		Hder = NULL;
		}
		
		
		void InsertaBinario(int num);
	
		
		string getValor(){
			return valor;
		}
		void setValor(string v){
			valor = v;
		}
		
		NodoBinario* getHizq(){
			return Hizq;
		}
		
		NodoBinario* getHder(){
			return Hder;
		}
		
		void setHizq(NodoBinario * izq){
			Hizq = izq;
		}
		void setHder(NodoBinario* der){
			Hder = der;
		}
		
		
		
	private:
		string valor;
		NodoBinario * Hizq;
		NodoBinario * Hder;
	friend class Binario;
	
};

class Binario{
	public:
		Binario(){
			raiz = NULL;
		}
		
		void InsertarRaiz(NodoBinario* n);
		void InsertarDerecho(NodoBinario* n);
		void InsertarIzquierdo(NodoBinario *n);
		
		void PreordenR(NodoBinario *R);
		void InordenR(NodoBinario *R);
		void PostordenR(NodoBinario *R);
		NodoBinario* RetornarRaiz();
		double evaluar();
		double evaluarAux(NodoBinario* r, ofstream& myfile);
		double operacion(double num1, double num2, string op);
		
		
		
	private:
		NodoBinario* raiz;
		
		
};

NodoBinario* Binario::RetornarRaiz(){
	return raiz;
}


void Binario::InsertarRaiz(NodoBinario* n){
	raiz = n;
}


void Binario::PreordenR(NodoBinario *R){
	
	if(R==NULL){
		return;
	
	}else{
		cout<<R->valor<<"|";
		PreordenR(R->Hizq);
		PreordenR(R->Hder);
	
		}
	}

void Binario::InordenR(NodoBinario *R){
	
	if(R==NULL){
		return;
	
		}else{
			InordenR(R->Hizq);
			cout<<R->valor<< "|";
			InordenR(R->Hder);
		}
	
	}

void Binario::PostordenR(NodoBinario *R){
	if(R==NULL){
		return;
	
	}else{
		PostordenR(R->Hizq);
		PostordenR(R->Hder);
		cout<<R->valor<< "|";
		}
	}

//////////////////////////////////////////////////////////FIN ARBOL BINARIO DE BUSQUEDA//////////////////////////////////////////////////////////


class nodo {
   public:
   	
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
    }

	nodo(string v, nodo * signodo)
	    {
	       valor = v;
	       siguiente = signodo;
	    }
	    

	nodo(int v)
	    {
	       valor = v;
	       siguiente = NULL;
	    }
	    
	nodo(int v, nodo * signodo)
	    {
	       valor = v;
	       siguiente = signodo;
	    }

///////////////CONSTRUCTOR NODOS CON NODOS DE ARBOL///////////

	nodo(NodoBinario v)
	    {
	       valorABB = v;
	       siguiente = NULL;
	    }
	    
	nodo(NodoBinario v, nodo * signodo)
	    {
	       valorABB = v;
	       siguiente = signodo;
	    }
///////////////FIN CONSTRUCTOR NODOS CON NODOS DE ARBOL///////////

   private:
    string valor;
    NodoBinario valorABB;
    
    nodo *siguiente;
    
        
   friend class lista;
   friend class NodoBinario;
   friend class Binario;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { primero = actual = NULL; }
    ~lista();
    
    void InsertarInicio(string v);
    
    void InsertarFinal(string v);
    void InsertarFinal(int v);
    void InsertarFinal(NodoBinario v);
	
	
    void EliminarInicio();
    void EliminarFinal();
    
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    
    void BorrarFinal();
    void BorrarInicio();
    
    int largoLista();
    
    int LeerArchivo(string num_archivo);
    pnodo RetornarPrimero();
    string LeerPrimerCaracter(string num_archivo);
    Binario recorrer();
    NodoBinario retUltimo();
    
    int evaluarNumeros(int numero1, int numero2, string operacion);
    void buscarParentesis(int cantidad);
    
    
   private:
    pnodo primero;
    pnodo actual;
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}


class Stack: public lista{
	public:
		Stack():lista(){
		}
		void Push(string v){
			NodoBinario _nodo = NodoBinario(v);
			
			InsertarFinal(_nodo);
		}
		
		void Push(NodoBinario v){
			InsertarFinal(v);
		}
		void Push(string v, NodoBinario *_der, NodoBinario* _izq){
			NodoBinario _nodo = NodoBinario(v, _izq, _der);
			InsertarFinal(_nodo);
		}
		
		void Pop(){
			BorrarFinal();
		}
	private:
		pnodo tope;
};

//////////////
double Binario::evaluar(){
	Stack pilaOperandos;
	NodoBinario * r = raiz;
	ofstream myfile;
	myfile.open ("Operandos.txt");
	double resul = evaluarAux(r, myfile);
	return resul;
}
Stack pilaOperandos;
double Binario::evaluarAux(NodoBinario* r, ofstream &myfile){
	double resultado;
	
	
	if (r == NULL){
		return stod(pilaOperandos.retUltimo().getValor());
	}
	
	if (r->Hizq != NULL){
		evaluarAux(r->Hizq, myfile);

	}
	if (r->Hder != NULL){
		evaluarAux(r->Hder, myfile);
		double a= std::stod(pilaOperandos.retUltimo().getValor());
		pilaOperandos.Pop();
		
		double b= std::stod(pilaOperandos.retUltimo().getValor());
		pilaOperandos.Pop();
		
		resultado = operacion(b, a, r->getValor());
		
		pilaOperandos.Push(std::to_string(resultado));
			
  		myfile << to_string(resultado) <<endl;
			
		r = NULL;
		evaluarAux(r, myfile);
		
		
	}
	else{
		pilaOperandos.Push(r->getValor());
  		myfile << r->getValor()<<endl;
		r = NULL;
	}
}

double Binario::operacion(double numero1, double numero2, string op){
	map <string, double> pFP;
  	if (op == "/" && numero2 == 0){
  		cout<<endl<<"/************************************* Error: Division entre cero **************************************/"<<endl;
  		return 0;
	  }
  	pFP["("]= 0;
	pFP["+"]= numero1+numero2;
	pFP["-"]= numero1-numero2;
	pFP["*"]= numero1*numero2;
	pFP["/"]= static_cast<double>(numero1)/static_cast<double>(numero2);
	pFP["^"]= pow(numero1, numero2);
	
	return pFP [op]; 
}
//////////////

int lista::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}


//////////////INSERTAR NODOS DE ARBOL//////////////
void lista::InsertarFinal (NodoBinario v)
	{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
	}
//////////////FIN INSERTAR NODOS DE ARBOL//////////////





void lista::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}
 
 
void lista::InsertarFinal (string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}



void lista::InsertarFinal (int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}

      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
        	(primero->valorABB).getValor();

                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
	              pnodo temp = aux->siguiente;
	              aux->siguiente= NULL;

            	delete temp;
            }
        }
}




void lista::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << " -> ";
      aux = aux->siguiente;
   }
   cout << endl;
}



NodoBinario lista :: retUltimo(){ //Retorna el ultimo NODOBINARIO de una lista 
	pnodo aux;
	aux = primero;
	

	while (aux ->siguiente != NULL){
		aux = aux ->siguiente;
	}
	return aux->valorABB;
		
}

string lista::LeerPrimerCaracter(string num_archivo) //Esta funcion saca solo la primera linea del .txt y lo mete en Arch1
	{
	string line;
	string Arch = "Arch";
	string txt = ".txt";
	string numero_archivo = Arch  + num_archivo + txt;
	
	const char * c = numero_archivo.c_str();
  	ifstream myfile (c);
  	if (myfile.is_open())
  		{
    	while ( getline (myfile,line) )
    		{
    		return line;
    		}
    	myfile.close();
		}
	}
	
	
int lista::LeerArchivo(string num_archivo) //Esta funcion saca todas las demas lineas
	{
	//Este es el que lee linea por linea

	string linea;
	string Arch = "Arch";
	string txt = ".txt";
	string numero_archivo = Arch  + num_archivo + txt;

	
	
	const char * c = numero_archivo.c_str(); //Para pasar el string a constant char
  	ifstream archivo (c); //Solo acepta constant chars
  	
  	if (archivo.is_open())
  		{
  		getline (archivo, linea);
    	while ( getline (archivo, linea) )
    		{
    		
    		InsertarFinal(linea);
       		
			}
    	archivo.close();
    	cout<<"Expresion original: ";
    	Mostrar();
  		}
  			
  	else cout << "No se puede abrir el archivo"; 
  	return 0;
	
	}
	

pnodo lista::RetornarPrimero() //Esta funcion retorna el puntero "primero" de una lista. SÃƒÆ’Ã‚Â­ se usa :P
	{
	return primero; 
	}



int convInt (string s){  //Convierte un string a un int
	int x;
	
	stringstream convert(s);
	convert >> x;
	return x;
			
	}
	
int prioriDP (string s){ //Retorna la prioridad de un operador dentro de la pila usando un mapa

  map <string, int> pDP;
  
  pDP["("]= 0;
  pDP["+"]= 1;
  pDP["-"]= 1;
  pDP["*"]= 2;
  pDP["/"]= 2;
  pDP["^"]= 3;

  return pDP [s];  
}



int prioriFP (string s){
	
  map <string, int> pFP;
  
  pFP["("]= 5;
  pFP["+"]= 1;
  pFP["-"]= 1;
  pFP["*"]= 2;
  pFP["/"]= 2;
  pFP["^"]= 4;

  return pFP [s];  
}
	

Binario lista :: recorrer(){ //recorre la lista que contiene la expresion original
	
	Binario ABB;
	pnodo aux;
	aux = primero;
	Stack listaTemp;
	Stack pilaPosFijo;
	int contPar = 0;
	
	while (aux){
		
		if (aux->valor == "("){
			contPar++;
			
		}
		if (isdigit(aux->valor[0])){  //Si es numero, la pone en el posfijo de una vez
			pilaPosFijo.Push(aux->valor);
			
		
		}else{
		
			if (listaTemp.ListaVacia()){  //Si la listatemp de simbolos esta vacia, mete el operador de una vez
				listaTemp.Push(aux->valor);
				
			}else{
				
				if (aux->valor == ")"){
				 
					while ((listaTemp.retUltimo()).getValor() != "("){
						
						NodoBinario* nodoDerecho = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
						
						NodoBinario* nodoIzquierdo = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
						
						(listaTemp.retUltimo()).setHder(nodoDerecho);
						(listaTemp.retUltimo()).setHizq(nodoIzquierdo);
						
						pilaPosFijo.Push((listaTemp.retUltimo()).getValor(), nodoDerecho, nodoIzquierdo);
						listaTemp.Pop();
						
					}
					listaTemp.Pop();
					
						
				}else{
					
					if (prioriDP((listaTemp.retUltimo()).getValor())>= prioriFP(aux->valor)){ 
					
						NodoBinario* nodoDerecho = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
							
						NodoBinario* nodoIzquierdo = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
							
						(listaTemp.retUltimo()).setHder(nodoDerecho);
						(listaTemp.retUltimo()).setHizq(nodoIzquierdo);

						pilaPosFijo.Push((listaTemp.retUltimo()).getValor(), nodoDerecho, nodoIzquierdo);

						listaTemp.Pop();
					
						
						listaTemp.Push(aux->valor);
					
					}else{
					listaTemp.Push(aux->valor);
					}
				
					
				}
				
			}
			
			}
		
		 aux = aux -> siguiente;
		 
		
	
	}
	
	if ((listaTemp.retUltimo()).getValor() != ")"){

		while(!listaTemp.ListaVacia()){
		
		NodoBinario* nodoDerecho = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());

			
		pilaPosFijo.Pop();
						
		NodoBinario* nodoIzquierdo = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
		pilaPosFijo.Pop();

						
		pilaPosFijo.Push((listaTemp.retUltimo()).getValor(), nodoDerecho, nodoIzquierdo);
						
		listaTemp.Pop();
		}
		
	}
	

	
	NodoBinario final = pilaPosFijo.retUltimo();
	

	NodoBinario* raizABB = new NodoBinario(final.getValor(), final.getHizq(), final.getHder());
	cout<<endl;
	ABB.InsertarRaiz(raizABB);
	
	cout<<"Inorden: ";
	ABB.InordenR(ABB.RetornarRaiz());
	cout<<endl<<"Postorden: ";
	ABB.PostordenR(ABB.RetornarRaiz());
	cout<<endl<<"Preorden: ";
	ABB.PreordenR(ABB.RetornarRaiz());
	
	
	
	return ABB;
	}
	



class NodoLista 
{
   private:
   int frente;
   int fondo;
   pnodo Cola [5]={0};
   int tamano;


public:
       NodoLista(){
       frente = 0;
       fondo = -1;
       tamano = sizeof(Cola)/sizeof(int);
        for(int i =0;i<tamano;i++){
         Cola[i]=0;    
           }
       }
       
      bool ColaVacia(){return fondo < frente;}        
	  void insertar(pnodo v); 
	  void eliminar ();
	  void imprimir();
	  void recorrer();
	  
	  
};


void NodoLista:: insertar (pnodo v)
{
         if(fondo < tamano){
             fondo++;
             Cola[fondo]= v; 
           
         }
         else{
         //cout<<"La cola esta llena";  
         }
}   


void NodoLista:: eliminar ()
{
         if(!ColaVacia()){
            frente++;
         }
         else{
         cout<<"La cola esta vacia";  
         }
}  


void NodoLista:: imprimir(){
     for(int i = frente;i<fondo+1;i++){
         cout<<Cola[i]<<"->";    
           }
}






	



int main()
	{
	
	NodoLista ExpOriginal; //La cola con los punteros 
	
	
	lista Arch1; //La lista (pila) donde se va a guardar la expresion del primer archivo
	lista Arch2;
	lista Arch3;
	lista Arch4;
	lista Arch5;
	
	string cont = "1";
 
 	string PrimerCaracter = Arch1.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
 	Arch1.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
 	pnodo primero = Arch1.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
 	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
 	Arch1.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
 	
	Binario pba = Arch1.recorrer();
	double resultado = pba.evaluar();
	cout<<endl<<"Resultado: "<<resultado<<endl<<endl;
	
	
	cont = "2";
 	PrimerCaracter = Arch2.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
 	Arch2.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
 	primero = Arch2.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
 	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
 	Arch2.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
 	
	pba = Arch2.recorrer();
	resultado = pba.evaluar();
	cout<<endl<<"Resultado: "<<resultado<<endl<<endl;
	
	
	cont = "3";
 	PrimerCaracter = Arch3.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
 	Arch3.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
 	primero = Arch3.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
 	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
 	Arch3.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
 	
	pba = Arch3.recorrer();
	resultado = pba.evaluar();
	cout<<endl<<"Resultado: "<<resultado<<endl<<endl;
	
	
	cont = "4";
 	PrimerCaracter = Arch4.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
 	Arch4.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
 	primero = Arch4.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
 	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
 	Arch4.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
 	
	pba = Arch4.recorrer();
	resultado = pba.evaluar();
	cout<<endl<<"Resultado: "<<resultado<<endl<<endl;
	
	
	cont = "5";
 	PrimerCaracter = Arch5.LeerPrimerCaracter(cont); //Esto es para meter el primer caracter a la lista y crear un primero
 	Arch5.InsertarFinal(PrimerCaracter); //Se inserta el primer caracter a la lista (pila)
 	primero = Arch5.RetornarPrimero(); //Retorna el puntero "primero" de la lista para pegarlo a la cola
 	ExpOriginal.insertar(primero); //Inserta el puntero a la NodoLista
 	Arch5.LeerArchivo(cont); //LeerArchivo saca todos los demas elementos de la expresion y los mete a la lista (pila) Arch1
 	
	pba = Arch5.recorrer();
	resultado = pba.evaluar();
	cout<<endl<<"Resultado: "<<resultado<<endl<<endl;
	return 0;
	

	}


