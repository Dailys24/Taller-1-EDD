#ifndef PATENTE_H
#define PATENTE_H

#include <iostream>
#include <string>



using namespace std;

class Patente {
  private:
    string rol;
    string rut;
    string nombre;
    string direccion;
    string giro;
    string fechaOtorgamiento;
    string tipoPatente;
    double valorPatente;

  public:
    // Constructor base
    Patente() {}

    // Constructor parametrizado
    Patente(string rol, string rut, string nombre, string direccion, string giro, string fechaOtorgamiento, string tipoPatente) 
    {
      this->rol = rol;
      this->rut = rut;
      this->nombre = nombre;
      this->direccion = direccion;
      this->giro = giro;
      this->fechaOtorgamiento = fechaOtorgamiento;
      this->tipoPatente = tipoPatente;
      this->valorPatente = 0.0;  // Inicialmente el valor de la patente es 0
    }

    // Constructor de copia
    Patente(const Patente& other) 
    {
      rol = other.rol;
      rut = other.rut;
      nombre = other.nombre;
      direccion = other.direccion;
      giro = other.giro;
      fechaOtorgamiento = other.fechaOtorgamiento;
      tipoPatente = other.tipoPatente;
      valorPatente = other.valorPatente;
    }

  // Métodos setters
  void setRol(string rol) 
  { 
    this->rol = rol; 
  }
  void setRut(string rut) 
  { 
    this->rut = rut; 
  }
  void setNombre(string nombre) 
  { 
    this->nombre = nombre; 
  }
  void setDireccion(string direccion) 
  { 
    this->direccion = direccion; 
  }
  void setGiro(string giro) 
  { 
    this->giro = giro; 
  }
  void setFechaOtorgamiento(string fechaOtorgamiento) 
  { 
    this->fechaOtorgamiento = fechaOtorgamiento; 
  }
  void setTipoPatente(string tipoPatente) 
  { 
    this->tipoPatente = tipoPatente; 
  }
  void setValorPatente(double valorPatente) 
  { 
    this->valorPatente = valorPatente; 
  }

  // Métodos getters
  string getRol() const 
  { 
    return rol; 
  }
  string getRut() const 
  { 
    return rut; 
  }
  string getNombre() const 
  { 
    return nombre; 
  }
  string getDireccion() const 
  { 
    return direccion; 
  }
  string getGiro() const 
  { 
    return giro; 
  }
  string getFechaOtorgamiento() const 
  { 
    return fechaOtorgamiento; 
  }
  string getTipoPatente() const 
  { 
    return tipoPatente; 
  }
  double getValorPatente() const 
  { 
    return valorPatente; 
  }

};

#endif
