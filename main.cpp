#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;


// prototipos de funcion*************

void pedirvalor();
void cambiobilletes(int*p,int tam);
int spiralDiaSum(int n);

int valor;
int vec[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
int tam=10;

int n,x ;




int main()
{
    int opcion;

    do {
    cout<<"***practica 1 de informatica 2***"<<endl;
    cout<<"1 para ver el problema 2"<<endl;
    cout<<"2 para ver el problema 5"<<endl;
    cout<<"3 para ver el problema 15"<<endl;
    cout<<"0 salir "<<endl;
    cout<<"ingrese la opcion que desea:"<<endl;
    cin>>opcion;

    switch (opcion) {
    case 0:
        break;

    case 1:
        pedirvalor();

        cambiobilletes(vec,tam);

        break;

   case 2:
        cout << " Ingrese un numero entero impar : " ;
                    cin >> x ;
                    n=x/2+1;
                    //formando piramide superior
                    for (int j = 0; j < n ; ++j) {
                        for (int i = 0; i < n-j-1; ++i)
                            cout << " ";// me ubique los espacios en la piramide superior
                        for (int i = 0; i < 2*j+1; ++i)
                             cout << "*" ;// me ubique los asteriscos piramide superior
                        cout << endl ;
                    }
                    // formando piramide inferior
                    for (int j=n-2; j>=0; --j) {
                            for (int i=0; i<n-j-1; ++i)
                                cout << " " ;// me ubique los espacios en la piramide inferior
                            for (int i=0; i<2*j+1; ++i)
                                cout << "*" ; //me ubique los astericos piramide inferior
                            cout << endl ;
                        }

        break;

    case 3:
        int res;
            short int n , n0 ;
                 cout << endl << " Ingrese un numero impar: " ;
                 cin >> n ;
                 cout << endl ;
                 res=n%2;
                 if(res==1){
                     cout<<"es una espiral "<<n<<"X"<<n<<","<<"la suma de los numeros en la diagonal es "<<spiralDiaSum( n)<<endl;
                     cout<<endl;

                 }


                 if( n%2 != 0 ){

                    for(int f = 0 ;f < n ; f++ ){
                        for(int c = 0 ; c < n ; c++ ){
                            if( f > c && f >= n-c-1 ){
                                n0 = 2*(1+f)-n ;
                                cout << n0*n0-2*(n0-1)-c+n-1-f << '\t' ;

                                }
                            else if( f <= c && f > n-c-1 ){
                                n0 = n-1-c ;
                                cout << ( n-2*(1+n0) )*( n-2*(1+n0) ) + 1 + f-(n0+1) << '\t' ;  // Triangulo derecho

                                   }

                            else if( f <= c && f <= n-c-1 ){
                                cout << ( n-2*f )*( n-2*f-1 )+1+c-f << '\t' ;

                                   }

                            else{

                                cout << ( n-2*c )*( n-2*c-1 )+1-f+c << '\t' ;
                                }

                       }
                        cout << endl << endl << endl;
                    }



                        }
                        else{

                            cout << endl << " Ingrese un numero impar..." << endl ;

                        }


        break;

    }
    } while (opcion<=3);

    return 0;
}



// funciones ******************************************


void pedirvalor(){
    cout<<"ingrese el valor que desea cambiar:"<<endl;
    cin>> valor;
}

void cambiobilletes(int*p,int tam){
    int billetes;
    for(int i=0;i<tam;i++){
        billetes=valor/ *(p+i);  //*(p+i)=vec[i]
        valor=valor%*(p+i);
        cout<<*(p+i)<<":"<<billetes<<endl<<endl;

    }
    cout<<"restante es: "<<valor<<endl;

}


int spiralDiaSum(int n)
{
    if (n == 1)
        return 1;


    return (4*n*n - 6*n + 6 + spiralDiaSum(n-2));
}




