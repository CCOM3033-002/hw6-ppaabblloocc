/*
Pablo Campos Méndez
CCOM 3033
HW6 figuras 3D

Este programa calcula el volumen o area supericial de uno entre estas figuras cilindro, esfera o prisma rectangular
el programa hace esto atrvez de dos menus en el cual el usario seleciona entre las opciones provistas 
para determinar cual figura y cual medicion quiere. Cuando ya haya selecionado, entonces finalmente el usario
entra el data necesario y recibe su contestacion

*/

#include<iostream>
#include<iomanip>
using namespace std;

//prototipo para la funcion del volumen para esfera
double volumen(double);

//prototipo para la funcion del volumen para cilindro, nota esto funciona porque tiene...
//... mas argumentos por lo tanto no conflijen uno con la otra
double volumen(double,double);

//prototipo para la funcion del volumen para prisma rectangular, nota esto funciona porque tiene...
//... mas argumentos por lo tanto no conflijen uno con la otra
double volumen(double,double,double);

//prototipo para la funcion del area superifical de una esfera
double areasuper(double);

//prototipo para la fucnion del area superifcial de un cilindro
double areasuper(double,double);

//prototipo para la funcion del area supeficila de un prisma rectangular
double areasuper(double,double,double);

int main(){
    //incializo mis varibles char que usare para que usario seleccione su figura y medida en el menu
    char choice_figura,choice_medida;

    //Despliego el proposito de programa
    cout<<"\nEste programa calcula el volumen o area superficial, de una de tres figuras (cilindro, esfera, prisma rectangular)"<<endl;
   
    //Despliego un menu con las opciones de figuras
    cout<<"\n-----------[Escoga una figura]-----------"<<endl;
    cout<<"\ta.Cilindro\n\tb.Esfera\n\tc.Prisma rectangular"<<endl;
    cout<<"\nEntre letra de figura:";
    cin>>choice_figura;
    
    //input validation de que entro una ocpion valida para figura
    switch(choice_figura){
        case'a':
        case'A':cout<<"Selecciono: a"<<endl;
            choice_figura=1;
            break;
        case'b':
        case'B':cout<<"Selecciono: b"<<endl;
            choice_figura=2;
            break;
        case'c':
        case'C':cout<<"Selecciono: c"<<endl;
            choice_figura=3;
            break;
        default:cout<<"No entro 'a', 'b' o 'c'"<<endl;
    }

    //Despliego un menu con las opciones de medidas
    cout<<"\n-----------[Escoga una medida]-----------"<<endl;
    cout<<"\ta.Volumen\n\tb.Area de la superficie"<<endl;
    cout<<"\nEntre letra de la medida:";
    cin>>choice_medida;

    //input validation de que entro una ocpion valida para medida
    switch(choice_medida){
        case'a':
        case'A':cout<<"Selecciono: a"<<endl;
            choice_medida=1;
            break;
        case'b':
        case'B':cout<<"Selecciono: b"<<endl;
            choice_medida=2;
            break;
        default:cout<<"No entro 'a' o 'b'"<<endl;
    }

    //rama de decision si quiere volumen de las figuras
    //primero verifico si la opcion de medida iguala a 1
    if(choice_medida==1){

        if(choice_figura==1){
            double r,h;
            cout<<"\nEntre el radio del cilindro:";
            cin>>r;
            cout<<"\nEntre la altura del cilindro:";
            cin>>h;
            cout<<"El volumen es = "<<setprecision(2)<<fixed<<volumen(r,h)<<endl;
        }

        else if(choice_figura==2){
            double r;
            cout<<"\nEntre el radio de la esfera:";
            cin>>r;
            cout<<"El volumen es = "<<setprecision(2)<<fixed<<volumen(r)<<endl;
        }

        else if(choice_figura==3){
            double largo,ancho,altura;
            cout<<"\nEntre el largo del prisma rectangular:";
            cin>>largo;
            cout<<"\nEntre la ancho del prisma rectangular:";
            cin>>ancho;
            cout<<"\nEntre el altura del prisma rectangular:";
            cin>>altura;
            cout<<"El volumen es = "<<setprecision(2)<<fixed<<volumen(largo,ancho,altura)<<endl;
        }
    }

    //rama de decisiones para si quiere calcual area superficial
    else if(choice_medida==2){

        if(choice_figura==1){
            double r,h;
            cout<<"\nEntre el radio del cilindro:";
            cin>>r;
            cout<<"\nEntre la altura del cilindro:";
            cin>>h;
            cout<<"El area superficial es = "<<setprecision(2)<<fixed<<areasuper(r,h)<<endl;
        }

        else if(choice_figura==2){
            double r;
            cout<<"\nEntre el radio de la esfera:";
            cin>>r;
            cout<<"El area superficial es = "<<setprecision(2)<<fixed<<areasuper(r)<<endl;
        }

        else if(choice_figura==3){
            double largo,ancho,altura;
            cout<<"\nEntre el largo del prisma rectangular:";
            cin>>largo;
            cout<<"\nEntre la ancho del prisma rectangular:";
            cin>>ancho;
            cout<<"\nEntre el altura del prisma rectangular:";
            cin>>altura;
            cout<<"El area superficial es = "<<setprecision(2)<<fixed<<areasuper(largo,ancho,altura)<<endl;
        }
    }
    
    return 0;
}

//funcion para calcular volumen de una esfera, sigue la formula 4/3*pi*radio
//unico cosa es que para poder usar double pongo 4.0 y 3.0 porque sino fueran de otro tipo
double volumen(double radio){
    return 4.0/3.0*3.14*radio;
}

//funcion para calcular volumen de un cilindro siguiendo la formula pi*radio^2*altura
//pongo un pi aproximado y radio_c*radio_c en un parentesis para salir con un radio cuadrado
double volumen(double radio_c,double height){
    return 3.14*(radio_c*radio_c)*height;
}

//funcion para calcular volumen de un prisma rectangular siguiendo la formula largo*ancho*altura
double volumen(double largo,double ancho, double altura){
    return largo*ancho*altura;
}

//funcion para clacular la area superficial de una esfera
//usando formula 4*pi*radio^2
double areasuper(double radio){
    return 4.0*3.14*(radio*radio);
}

//funcion para calcular la area superficial de un cilindro
//usando formula (2*pi*radio*height)+2*pi*radio^2
double areasuper(double radio_c,double height){
    return (2.0*3.14*radio_c*height)+(2.0*3.14*radio_c*radio_c);
}

//funcion para clacular la area superficial de un prisma rectangular
//usando formula 2((largo*ancho)+(largo*altura)+(altura*ancho))
double areasuper(double largo,double ancho,double altura){
    return 2*((largo*ancho)+(largo*altura)+(altura*ancho));
}

