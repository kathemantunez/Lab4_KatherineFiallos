#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>


using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void ejercicio3();
char** createMatrix(int);
void fillMatrix(char**,int,string);
void printMatrix(char**,int);


void ejercicio2();
int*** crearMatrix3(int);

void division(int***,int,int);
void printdivision(int***,int,int);



void ejercicio1();


int main()
{
    bool bandera=false;
    char tecla;
 
    do
    {
       
        
        cout << "LAB 4" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- EJERCICIO 1(EXTRA)" << endl;
        cout << "\t2 .- EJERCICIO 2" << endl;
        cout << "\t3 .- EJERCICIO 3" << endl;
        cout << "\t4 .- SALIR" << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
		{
			case '1':
				//extra
				ejercicio1();
				break;
 
			case '2':
				
				ejercicio2();
				break;
 
			case '3':
				ejercicio3();
				break;
 
			case '4':
				bandera=true;
				//exit(1);
				break;
 
			default:
			
				cout << "Opcion no valida.\a\n";
	
				break;
		}
    }while(bandera!=true);
 
    return 0;

}

void ejercicio1(){


}

void ejercicio2(){

/*
	int n,i;
	cout<<"grado del polinomio:";
	cin>>n;
	double *f;

	f=new double[n+1];
*/
	bool b=false;
	int x=0;
	do{
	
	int size=3;
	int*** matrix=NULL;


	int grado_alto;
	int a;
	cout<<"ingrese el grado mas alto del polinomio:";
	cin>>grado_alto;
	cout<<endl;

	cout<<"ingrese a:";
	cin>>a;
	cout<<endl;
	
	int grado2=grado_alto+1;

	matrix=crearMatrix3(grado2);

	int c=0;

	division(matrix,grado2,a);


	cout<<"desea continuar[1]:"<<endl;
	cin>>x;
	}while(x!=1);



	
}



void division(int*** matrix,int a,int valor_a){
	int xs=0;
	for(int i=0;i<a;i++){
		xs=0;
		cout<<"ingrese el valor de x'"<<i<<":";
		cin>>xs;
		cout<<endl;

		matrix[0][0][i]=xs;
	}
	for(int j=0;j<a;j++){

		for(int i=0;i<a;i++){

			matrix[j][0][i]=matrix[0][0][i];
			matrix[j][2][0]=matrix[0][0][0];
		}
	}

	for(int k=0;k<a;k++){
		for(int m=0;m<3;m++){
			for(int e=0;e<a;e++){
				matrix[e][1][e+1]=matrix[k][2][e]*valor_a;
				matrix[k][2][e+1]=matrix[k][0][e+1]+matrix[k][1][e+1];
			}
		}
	}
	printdivision(matrix,a,valor_a);



}


void printdivision(int*** matrix,int size,int a){
	for(int i=0;i<size;i++){
		for(int j=0;j<3;j++){
			for(int m=0;m<size;m++){
				cout<<"|"<<matrix[i][j][m]<<"|";
			}
			cout<<"|"<<a<<endl;
		}
		cout<<endl;
	}
}


int*** crearMatrix3(int size){
	int*** matrix=new int**[size];
	for(int i=0;i<size;i++){
		matrix[i]=new int*[3];
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<3;j++){
			matrix[i][j]=new int [size];
		}
	}
	return matrix;


}

//.-----------------------------

void ejercicio3(){
	char letras[]="abcdefghiklmnopqrstuvwxyz";

	string nombre;
	cout<<"Ingrese nombre:";
	cin >>nombre;
	cout<<endl;
	int size_name=nombre.length();
	if(size_name<0 || size_name>25){
		cout<<"el tamano es del nombre es incorrecto"<<endl;


	}else{
		int size=5;
		char** matrix=NULL;
		matrix=createMatrix(size);//crear
		fillMatrix(matrix,size,nombre);
		printMatrix(matrix,size);
		


	}

}
//------------------------------------------------
void printMatrix(char** matrix,int size){
	
	for (int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<" " <<matrix[i][j];
		}
		cout<<endl;
	}
	

	

}
void fillMatrix(char** matrix,int size,string name){

	char letras[]="abcdefghiklmnopqrstuvwxyz";
//	int size2=letras.length();
	int cont=0;
	int size_n=name.length();
	char array[25];
	string nuevo="";


	
	int cont2=0;
	int cont3=0;

	cout<<"matriz de cifrado resultante"<<endl;

	for(int i=0;i<size;i++){

		for(int j=0;j<size;j++){
			if(cont2<size_n){
				
				matrix[i][j]=name[cont2];
				cont2++;
		
			}
		}
	}

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){

			if(matrix[i][j]==letras[cont] && matrix[i][j]!='*'){
					
				cont++;
			}
			if(matrix[i][j]!=letras[cont] && matrix[i][j]=='*'){
				matrix[i][j]=letras[cont];
				cont++;
				}
			}
		}
}


		
							
	
		

	




		
	

char** createMatrix(int size){
	char** retValue=new char*[size];
	for(int i=0;i<size;i++){
		retValue[i]=new char[size];
	}
	//inicializar la matriz en cero
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			retValue[i][j]='*';
		}
	}
	return retValue;

}
