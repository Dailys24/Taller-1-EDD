/*
    TALLER 1 EDD 
    MIEMBROS:       Agustin Ugas Ñancucheo
                    Angelo Gonzalez Lobo
    FECHA:          10-09-2023
    SECCION:        412
    PROFESOR:       FERNANDO IVAN DONOSO SOLO DE ZALDIVAR
    LINK AL VDEO:   https://youtu.be/XtpLgWpZWLA
 */

//Biblioteca
#include <iostream>
#include <string>

//Clases que ultilizaremos
#include "Funciones.h"
#include "Patente.h"

using namespace std;
//Funcion main
int main() 
{

  vector<Patente> patentes;
  int op;
  char opcion;
  string rut;
  int indice=0;
  string patente ="patentesComerciales.txt";

  leerArchivo(patentes);
  
  //Do While
  do
  {
    
    //Menu del prograna
    cout<<"****************************************************************************************"<<endl;
    cout << "\n-----Municipalidad El Colmo-----\n"<<endl;
    cout<<"\n------------- MENU -------------"<<endl<<endl;
    cout << "\n\u27a4 [1] Completar valor patente "<<endl;
    cout << "\n\u27a4 [2] Actualizar Digito Verificador "<<endl;
    cout << "\n\u27a4 [3] Totalizar patentes comerciales "<<endl;
    cout << "\n\u27a4 [4] Consulta por patente "<<endl;
    cout << "\n\u27a4 [5] Patentes por antiguedad "<<endl;
    cout << "\n\u27a4 [6] Terminar ";
    cout<<"\n****************************************************************************************"<<endl;
    cout << "\nIngrese una opcion: ";
    cin >> op;
        
    if(op > 6)
    cout << "\n*** Opcion invalida. Porfavor digite nuevamente ***\n"<<endl;
        
    switch(op)
    {
      
      case 1: //Completar valor patente
        
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        completarValorPatente(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=6;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
          if(opcion=='Y')
          {
            break;
          }
              
          else
            cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 2: //Actualizar digito verificador
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        actualizarDigitoVerificador(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=6;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
            if(opcion=='Y')
            {
              break;
            }
              
            else
              cout<<"Operacion invalida."<<endl;
          }while(opcion!='Y'||opcion!='N');
        
          
      break;
      
      case 3: //Totalizar patentes comerciales
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        totalizarPatentesComerciales(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        do
        {
          if(opcion=='N')
          {
            op=6;
            cout << "\n****Gracias por utilizar****"<<endl;
            break;
          }
          
          if(opcion=='Y')
          {
            break;
          }
              
          else
            cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 4: //Consulta patente
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        consultaPorPatente(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
        cout<<"\n\u27a4 ¿Desea Realizar otra operacion? (Y=si/N=no): ";
        cin>>opcion;
        
        do
        {
          if(opcion=='N')
          {
            op=6;
            cout << "\n****Gracias por utilizar:)****"<<endl;
            break;
          }
          
          if(opcion=='Y'){
          break;
          }
              
          else
          cout<<"Operacion invalida."<<endl;
        }while(opcion!='Y'||opcion!='N');
        
      break;
      
      case 5: //Patentes por antiguedad
        cout <<"------------------------------------------------------------------------------------ "<<endl;
         mostrarPatentesPorAntiguedad(patentes);
        cout <<"------------------------------------------------------------------------------------ "<<endl;
      break;

      case 6: //Terminar el programa
        cout<<"*****Gracias por utilizar:)*****"<<endl;
      break;
    }
    
    
  }while(op!=6);
}
