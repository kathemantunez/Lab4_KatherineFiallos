#include <iostream>
#include <string.h>

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
void fillMatrix2(int*** ,int);


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
/*	int size=3;
	int*** matrix=NULL;
	matrix=crearMatrix3(size);

	int grado_alto;
	int cont=1;
	int cont2=grado_alto;
	int num;
	int a;
	cout<<"ingrese el grado mas alto del polinomio:";
	cin>>grado_alto;
	cout<<endl;
	string xx;
	while(cont<=grado_alto){
		
		cout<<"ingrese x'"<<cont2<<":";
		cin>>num;
		cout<<endl;
		x+=num;
		cont2--;

		cont++;
	}
	cout<<"ingrese a:";
	cin>>a;
	cout<<endl;

	
	fillMatrix2(matrix,size);


*/
	
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
void fillMatrix2(int*** matrix,int size){


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
/*

int j=0;
	for(int i=0;i<name.length();i++){
		if(letras[i]!=24){
			name[j]=letras[i];
			j++;
		}
	}
	
//m2=name,m=letras
	int i=0;
	j=1;
	while(j<=strlen()){
		if(name[i]==nmae[j]){
			for(int k=strlen(name)+1;k>j;k--){
				name[k]=name[k-1];
			}
			name[j]='x';
		}
		i=i+2;
		j=j+2;
	}
	if(strlen(name)%2!=0={
			name[strlen(m2)+1]='\0';
			name[strlen(m2)]='x';
			}

*/


/*	strcpy (array_name,name.c_str());
//prueba
	for(int k=0;k<size_n;k++){
	cout<<array_name[k];

	}
	cout<<endl;


*/

	for(int k=0;k<=25;k++){
		if(letras[k]==name[cont]){
			cont++;
		}else{
			nuevo+=letras[k];
			cont++;
		}
	}


	int cont2=0;
	int cont3=0;

	cout<<"matriz de cifrado resultante"<<endl;

	for(int i=0;i<size;i++){

		for(int j=0;j<size;j++){
			if(cont2<size_n){
				
				matrix[i][j]=name[cont2];
				cont2++;
				

		
			}else{
		
						
				matrix[i][j]=nuevo[cont3];
				cont3++;
							
						}
					}
	}
}
		

	




		
	
/*
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){

			matrix[i][j]=letras[cont];
			cont++;
		}
	}*/

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
