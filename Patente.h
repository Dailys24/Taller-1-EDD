#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Patente.h"

using namespace std;

void leerArchivo(vector<Patente> &patentes) {
  // Crear una lista de objetos Patente

  // Leer los datos de las patentes desde un archivo de texto
  ifstream file("patentesComerciales.txt");
  string line;

  // Saltar la primera línea (encabezado del archivo)
  getline(file, line);

  while (getline(file, line)) {
    stringstream ss(line);
    string rol, rut, nombre, direccion, giro, fechaOtorgamiento, tipoPatente;
    double valorPatente = 0.0; // Inicialmente el valor de la patente es 0

    getline(ss, rol, ';');
    getline(ss, rut, ';');
    getline(ss, nombre, ';');
    getline(ss, direccion, ';');
    getline(ss, giro, ';');
    getline(ss, fechaOtorgamiento, ';');
    getline(ss, tipoPatente, ';');

    // Crear un objeto Patente y añadirlo a la lista
    Patente patente(rol, rut, nombre, direccion, giro, fechaOtorgamiento,
                    tipoPatente);
    patentes.push_back(patente);
  }

  file.close();

  // Ahora el vector 'patentes' contiene todos los datos del archivo
}

// Opcion 1
//  Genera un número aleatorio en el rango min y max.
double generarAleatorio(double min, double max) {
  return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

void completarValorPatente(vector<Patente> &patentes) {
  // Inicializa el generador de números aleatorios.
  srand(static_cast<unsigned>(time(0)));

  for (Patente &patente : patentes) {
    double valorPatente =
        generarAleatorio(1.0, 8.0); // Genera un valor aleatorio entre 1 y 8.
    patente.setValorPatente(valorPatente); // Establece el valor de la patente.
  }
  cout << "Completado." << endl;
}

// Opcion 2
//  Calcula el dígito verificador de un RUT.
char calcularDigitoVerificador(const string &rut) {
  int suma = 0;
  int multiplicador = 2;

  // Recorre los dígitos del RUT de atrás hacia adelante.
  for (auto it = rut.rbegin(); it != rut.rend(); ++it) {
    suma += (*it - '0') * multiplicador;
    if (++multiplicador > 7)
      multiplicador = 2;
  }

  int resto = suma % 11;
  if (resto == 1)
    return 'K';
  if (resto == 0)
    return '0';
  return '0' + (11 - resto);
}

void actualizarDigitoVerificador(vector<Patente> &patentes) {
  for (Patente &patente : patentes) {
    string rut = patente.getRut();
    string rutSoloDigitos;
    for (char c : rut) {
      if (isdigit(c)) {
        rutSoloDigitos += c;
      }
    }
    // Calcula el nuevo dígito verificador.
    char nuevoDigitoVerificador = calcularDigitoVerificador(rutSoloDigitos);
    // Actualiza el RUT en el objeto Patente.
    patente.setRut(rutSoloDigitos + "-" + nuevoDigitoVerificador);
  }
}

// Opcion 3
double totalizarPatentesComerciales(vector<Patente> &patentes) {
  cout << "\n\u27a4 Por favor, ingresa la UTM del mes actual: ";
  double utm;
  cin >> utm;

  double total = 0.0;
  for (const Patente &patente : patentes) {
    total += patente.getValorPatente() * utm;
  }

  cout << "total es: " << total;
  return total;
}

// Opcion 4

void consultaPorPatente(vector<Patente> &patentes) {
  string rut;
  cout << "Ingrese un RUT: ";
  cin >> rut;
  for (Patente &patente : patentes) {
    if (patente.getRut() == rut) {
      cout << "Rol: " << patente.getRol() << endl;
      cout << "Rut: " << patente.getRut() << endl;
      cout << "Nombre: " << patente.getNombre() << endl;
      cout << "Direccion: " << patente.getDireccion() << endl;
      cout << "Giro: " << patente.getGiro() << endl;
      cout << "Fecha de Otorgamiento: " << patente.getFechaOtorgamiento()
           << endl;
      cout << "Tipo de Patente: " << patente.getTipoPatente() << endl;
      cout << "Valor de la Patente: $" << patente.getValorPatente() << endl;
      break;
    }
  }
}

// Opcion 5
//  Función de comparación
bool compararPorGiro(const Patente &a, const Patente &b) {
  return a.getGiro() < b.getGiro();
}

// Función para obtener el año actual
int obtenerAnoActual() {
  time_t t = time(0); // Obtener tiempo actual
  struct tm *now = localtime(&t);
  return (now->tm_year + 1900);
}

// Función para obtener el año de una fecha en formato "dd/mm/yyyy"
int obtenerAnoDeFecha(string fecha) { return stoi(fecha.substr(6, 4)); }

// Función para mostrar las patentes por antigüedad
void mostrarPatentesPorAntiguedad(vector<Patente> &patentes) {
  // Filtrar las patentes que tienen más de 5 años
  vector<Patente> patentesAntiguas;
  int anoActual = obtenerAnoActual();
  for (Patente &patente : patentes) {
    if (anoActual - obtenerAnoDeFecha(patente.getFechaOtorgamiento()) > 5) {
      patentesAntiguas.push_back(patente);
    }
  }

  // Ordenar las patentes por giro
  sort(patentesAntiguas.begin(), patentesAntiguas.end(), compararPorGiro);

  // Mostrar las patentes
  for (Patente &patente : patentesAntiguas) {
    cout << "-------------------------------------------" << endl;
    cout << "Giro: " << patente.getGiro() << endl;
    cout << "Rol: " << patente.getRol() << endl;
    cout << "Nombre: " << patente.getNombre() << endl;
    cout << "-------------------------------------------" << endl;
  }
}
