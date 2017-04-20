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
			//cout<<"JAJA"<<endl;
			//Hder = 
		}
		/*
		NodoBinario(int v){
		valor = v;
		Hizq = NULL;
		Hder = NULL;
		}
		*/
		
		NodoBinario(string v, NodoBinario*i, NodoBinario*d){
		//if (i!=NULL & d!=NULL){
			//cout<<"ESTE ES EL HIJO DERECHO Y EL IZQUIERDO "<<d<<"  "<<i<<endl;
		//}
		valor = v;
		Hizq = i;
		Hder = d;
		}
		
		NodoBinario(string v){
		valor = v;
		Hizq = NULL;
		Hder = NULL;
		}
		
		//void InsertaBinario(string num);
		void InsertaBinario(int num);
		//void InsertaBinario(NodoBinario num);
		
		string getValor(){
			cout<<valor<<endl;
			return valor;
		}
		void setValor(string v){
			cout<<"Aqu� hay un " <<valor<<endl;
			valor = v;
		}
		
		NodoBinario* getHizq(){
			if (Hizq)
			{
				cout<<"ESTE ES EL HIJO IZQUIERDO: " <<Hizq->valor<<endl;
			}
			return Hizq;
		}
		
		NodoBinario* getHder(){
			if (Hizq)
			{
				cout<<"ESTE ES EL HIJO DERECHO: " <<Hder->valor<<endl;
			}
			return Hder;
		}
		
		void setHizq(NodoBinario * izq){
			Hizq = izq;
		}
		void setHder(NodoBinario* der){
			if (!der){
				cout<<"Es nulo"<<endl;
			}
			Hder = der;
			cout<<Hder<<endl;
			
		}
		
		
		
	private:
		string valor;
		NodoBinario * Hizq;
		NodoBinario * Hder;
	friend class Binario;
	//friend class lista;
};

class Binario{
	public:
		Binario(){
			raiz = NULL;
		}
		
		//void InsertaNodo(int num);
		//void InsertaNodo(NodoBinario num);
		
		void InsertarRaiz(NodoBinario* n);
		void InsertarDerecho(NodoBinario* n);
		void InsertarIzquierdo(NodoBinario *n);
		
		void PreordenR(NodoBinario *R);
		void InordenR(NodoBinario *R);
		void PostordenR(NodoBinario *R);
		NodoBinario* RetornarRaiz();
		double evaluar();
		double evaluarAux(NodoBinario* r);
		double operacion(double num1, double num2, string op);
		
		
		
	private:
		NodoBinario* raiz;
		//friend class Stack;
		
};

NodoBinario* Binario::RetornarRaiz(){
	cout<<raiz->valor<<endl;
	return raiz;
}



/*void NodoBinario::InsertaBinario(int num)
	{

	if(num<valor){
		if(Hizq==NULL){
			Hizq = new NodoBinario(num);
		}else{
			Hizq->InsertaBinario(num);
			}
	}else{
		if(Hder==NULL){
			Hder = new NodoBinario(num);
		}else{
			Hder->InsertaBinario(num);

		}
	}
	}

void NodoBinario::InsertaBinario(NodoBinario num)
	{

	if(num<valor){
		if(Hizq==NULL){
			Hizq = new NodoBinario(num);
		}else{
			Hizq->InsertaBinario(num);
			}
	}else{
		if(Hder==NULL){
			Hder = new NodoBinario(num);
		}else{
			Hder->InsertaBinario(num);

		}
	}
	}

void Binario::InsertaNodo(int num)
	{
	if(raiz==NULL){
		raiz = new NodoBinario(num);
	}else{
		raiz->InsertaBinario(num);
	}
	} 
*/



void Binario::InsertarRaiz(NodoBinario* n){
	raiz = n;
}
/*	
void Binario::InsertarDerecho(NodoBinario* n){
	Hder = n;	
}

void Binario::InsertarIzquierdo(NodoBinario* n){
	Hizq = n;	
}
*/


/*	
void Binario::InsertaNodo(NodoBinario num)
	{
	if(raiz==NULL & !isdigit(->valor[0]){
		raiz = new NodoBinario(num);
	}else{
		raiz->InsertaBinario(num);
	}
	} 

*/



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
    
    //NodoBinario BorrarFinal();
	
	void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
    int LeerArchivo(string num_archivo);
    pnodo RetornarPrimero();
    string LeerPrimerCaracter(string num_archivo);
    Binario recorrer();
    NodoBinario retUltimo();
    void evaluar();
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
			//tope = actual = NULL;
		}
		//void InsertarFinal(string v); //Push
		//void EliminarFinal(); //Pop
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
	//friend class Binario;	
};

//////////////
double Binario::evaluar(){
	Stack pilaOperandos;
	NodoBinario * r = raiz;
	evaluarAux(r);
	//cout<<pilaOperandos.retUltimo().getValor()<<endl;
}
Stack pilaOperandos;
double Binario::evaluarAux(NodoBinario* r){
	double resultado;
	
	if (r == NULL){
		cout<<stod(pilaOperandos.retUltimo().getValor())<<endl;
		cout << std::setprecision(15) << stod(pilaOperandos.retUltimo().getValor()) << endl;
		return stod(pilaOperandos.retUltimo().getValor());
	}
	
	if (r->Hizq != NULL){
		evaluarAux(r->Hizq);
		//r = r->Hizq	
	}
	if (r->Hder != NULL){
		evaluarAux(r->Hder);
		double a= std::stod(pilaOperandos.retUltimo().getValor());
		pilaOperandos.Pop();
		
		double b= std::stod(pilaOperandos.retUltimo().getValor());
		cout<<"ES B: "<<b<<endl;
		pilaOperandos.Pop();
		
		resultado = operacion(b, a, r->getValor());
		
		pilaOperandos.Push(std::to_string(resultado));
		
		r = NULL;
		evaluarAux(r);
		
		
	}
	else{
		pilaOperandos.Push(r->getValor());
		r = NULL;
	}
}

double Binario::operacion(double numero1, double numero2, string op){
	map <string, double> pFP;
  	if (op == "/" && numero2 == 0){
  		cout<<"Error: Division entre cero"<<endl;
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

void lista::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
	
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
        	(primero->valorABB).getValor();
        	
        	//cout<<primero->valor<<endl;
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                cout<<"PBAAAA: "<< temp<<endl;
                delete temp;
            }
        }
}
/*
NodoBinario lista::BorrarFinal()
{
	NodoBinario ultimo;
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              ultimo = (aux->siguiente)->valor;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}
*/
void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
            }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
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

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}


void lista::Primero()
{
	
	cout<<primero<<endl;
   actual = primero;
}


void lista::Ultimo()
{
   actual = primero;  
   if(!ListaVacia()) 
      while(actual->siguiente) Siguiente();
} 

NodoBinario lista :: retUltimo(){ //Retorna el ultimo NODOBINARIO de una lista 
	pnodo aux;
	aux = primero;
	

	while (aux ->siguiente != NULL){
		aux = aux ->siguiente;
	}
	cout<<(aux->valorABB.getValor())<<endl;
	return aux->valorABB;
		
}

//NodoBinario * NodoBinario::retRefRaiz(){
//	NodoBinario * 
//}

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
		//	cout<<"EJEJEJE: "<<aux->valor<<endl;
			pilaPosFijo.Push(aux->valor);
			
		
		}else{
		
			if (listaTemp.ListaVacia()){  //Si la listatemp de simbolos esta vacia, mete el operador de una vez
				listaTemp.Push(aux->valor);
				
			}else{
				
				if (aux->valor == ")"){
				 
					while ((listaTemp.retUltimo()).getValor() != "("){
						//NodoBinario temp = (pilaPosFijo.retUltimo());
						
						NodoBinario* nodoDerecho = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
						
						NodoBinario* nodoIzquierdo = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
						pilaPosFijo.Pop();
						
						(listaTemp.retUltimo()).setHder(nodoDerecho);
						(listaTemp.retUltimo()).setHizq(nodoIzquierdo);
						
						//pilaPosFijo.Push((listaTemp.retUltimo()));
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
							
							//pilaPosFijo.Push((listaTemp.retUltimo()));
						pilaPosFijo.Push((listaTemp.retUltimo()).getValor(), nodoDerecho, nodoIzquierdo);
							
						//pilaPosFijo.Push(listaTemp.retUltimo());
						listaTemp.Pop();
					//	if(aux->valor != "#"){
						
						listaTemp.Push(aux->valor);
					//	}
					}else{
					listaTemp.Push(aux->valor);
					}
				
					
				}
				
			}
			
			}
		
		 aux = aux -> siguiente;
		 
		
	
	}
	
	if ((listaTemp.retUltimo()).getValor() != ")"){
		//pilaPosFijo.InsertarFinal(listaTemp.retUltimo());
		//cout<<"PRUEBA: " << (pilaPosFijo.retUltimo()).getValor()<<endl;
		while(!listaTemp.ListaVacia()){
		
		NodoBinario* nodoDerecho = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
		//if (((pilaPosFijo.retUltimo()).getHizq())){
		
			//cout<<"El hijo izquierdo jiji: "<<endl;
		//	}
			
		pilaPosFijo.Pop();
						
		NodoBinario* nodoIzquierdo = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
		pilaPosFijo.Pop();
						
		//(listaTemp.retUltimo()).setHder(nodoDerecho);
		//(listaTemp.retUltimo()).setHizq(nodoIzquierdo);
						
		pilaPosFijo.Push((listaTemp.retUltimo()).getValor(), nodoDerecho, nodoIzquierdo);
						
		listaTemp.Pop();
		}
		//cout<<"LA RAIZ: "<<((pilaPosFijo.retUltimo()).getHizq())->getValor()<<endl;
	}
	
	//else{
		
	//}
	

	//cout<< "PosFijo: ";
	//pilaPosFijo.Mostrar();
	
	NodoBinario final = pilaPosFijo.retUltimo();
	
	//NodoBinario* raizABB = new NodoBinario((pilaPosFijo.retUltimo()).getValor(), (pilaPosFijo.retUltimo()).getHizq(), (pilaPosFijo.retUltimo()).getHder());
	NodoBinario* raizABB = new NodoBinario(final.getValor(), final.getHizq(), final.getHder());
//	cout<<endl;
	ABB.InsertarRaiz(raizABB);
	//cout<<"Hijo: "<<raizABB->getHder()<<endl;
	ABB.InordenR(ABB.RetornarRaiz());
//	cout<<endl;
	ABB.PostordenR(ABB.RetornarRaiz());
//	cout<<endl;
	ABB.PreordenR(ABB.RetornarRaiz());
	
	
	
	return ABB;
	}
	
//Evalua la expresion posfijo 
void lista::evaluar()
	{
	
	int num1;
	int num2;
	pnodo aux = primero;

	int primerNumero = convInt(aux->valor);
	int segundoNumero = convInt(aux->siguiente->valor);

	
	while (aux!=NULL)
		{

		num1 = primerNumero;
		num2 = segundoNumero;
		
		
		while (isdigit(aux->valor[0])) //Mueve el aux hasta encontar la operacion
			{
	
			aux=aux->siguiente;
			
			}
		primerNumero = evaluarNumeros(num1, num2, aux->valor);
		aux = aux->siguiente;
		if (aux!=NULL)
			{
			
			if (isdigit(aux->siguiente->valor[0]))
				{
				
				segundoNumero = evaluarNumeros(convInt(aux->valor), convInt(aux->siguiente->valor), aux->siguiente->siguiente->valor);
				aux = aux->siguiente->siguiente->siguiente;
				}
			else
				{
				
					segundoNumero=convInt(aux->valor);
					aux = aux->siguiente;
	
				}
			}
		else
			{

			break;
			}
		}
	cout<<"Resultado: ";
	cout<<primerNumero<<endl;
	}



int lista::evaluarNumeros(int numero1, int numero2, string operacion)
	{
	
	map <string, int> pFP;
  	
  	pFP["("]= 0;
	pFP["+"]= numero1+numero2;
	pFP["-"]= numero1-numero2;
	pFP["*"]= numero1*numero2;
	pFP["/"]= numero1/numero2;
	pFP["^"]= pow(numero1, numero2);
	
	return pFP [operacion]; 
  
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
         cout<<"La cola esta llena";  
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
	pba.evaluar();
	
	double a = std::stod("1.5");
	//cout.precision(15);
	//cout << std::setprecision(15) << (double)a << endl;
	cout<<a<<endl;

 	//ExpresionPostfijo.evaluar();
 	
	
	/*
	NodoBinario dere = NodoBinario("66", NULL, NULL);
	NodoBinario* izqu = new NodoBinario("1000");
	
	Stack PilaJIJI;
	PilaJIJI.Push("3");
	PilaJIJI.Push("+");
	NodoBinario prueba = (PilaJIJI.retUltimo());
	
	//(PilaJIJI.retUltimo()).getValor();
	prueba.setHder(&dere);
	prueba.setHizq(izqu);
	cout<<"Derecho: "<< prueba.getHder()<<endl;
	cout<<"Izquierdo: "<<prueba.getHizq()<<endl;
	
	/*
	(PilaJIJI.retUltimo()).setHder(dere);
	(PilaJIJI.retUltimo()).setHizq(izqu);
	
	cout<<"LALALA "<<(PilaJIJI.retUltimo()).getHizq()<<endl;
	
	NodoBinario uno = (PilaJIJI.retUltimo());
	
	Binario abb;
	
	NodoBinario * subder = new NodoBinario(prueba.getValor(), prueba.getHizq(), prueba.getHder());
	
	
	
	NodoBinario * ndo = new NodoBinario("+", subder, izqu);
	
	cout<<ndo->getHder()<<endl;
	abb.InsertarRaiz(ndo);
	
	abb.InordenR(abb.RetornarRaiz());
	
	//PilaJIJI.retUltimo();
	
	//PilaJIJI.Pop();
	/*	
	cont = "5";
	PrimerCaracter = Arch5.LeerPrimerCaracter(cont); 
	Arch5.InsertarFinal(PrimerCaracter); 
	primero = Arch5.RetornarPrimero(); 
	ExpOriginal.insertar(primero); 
	Arch5.LeerArchivo(cont); 
	Arch5.recorrer();
	lista ExpresionPostfijo5 = Arch5.recorrer();
	ExpresionPostfijo5.evaluar();
	
	cout<<"Presione ENTER para SALIR"<<endl;
	cin.get();
	

	
	
	
	
	ExpOriginal.imprimir();
	*/
	return 0;
	

	}


