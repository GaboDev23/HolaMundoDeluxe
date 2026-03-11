#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void holamundo(bool activado) {
 if (activado == false) {
  cout << "Hola mundo\n";
 } else {
  cout << "\033[32mHola mundo\033[0m\n";
 }
}

void obtenerFecha(bool activado) {
 time_t hora = time(0);
 tm *f = localtime(&hora);
 string fecha = "";

 if (activado == true) {
  fecha = "\033[32m" + to_string(f -> tm_mday) + "/" + to_string(f -> tm_mon + 1) + "/" + to_string(f -> tm_year + 1900) + "\033[0m";
 } else {
  fecha = to_string(f -> tm_mday) + "/" + to_string(f -> tm_mon + 1) + "/" + to_string(f -> tm_year + 1900);
 }
 cout << "Fecha: " << fecha << endl;
}

void pedirNombre(string &nombre) {
 cout << "Introduce tu nombre: ";
 cin >> nombre;
}

void mostrarNombre(string nombre, bool activado) {
 if (activado == false) {
  cout << "Bienvenido " << nombre << endl;
 } else {
   cout << "Bienvenido " << "\033[32m" << nombre << "\033[0m" << endl;
 }
}

void mostrarMensajes(bool activado) {
 if (activado == false) {
  cout << "Hola Mundo\nBienvenido al programa\nQue tengas un buen día\n";
 } else {
  cout << "\033[32mHola Mundo\nBienvenido al programa\nQue tengas un buen día\n\033[0m";
 }
}

bool activarColores(bool activado) {
 if (activado == false) {
  cout << "\033[32mColores activados\033[0m\n";
  return true;
 }
 cout << "Colores desactivados\n";
 return false;
}

int main() {
 string nombre = "";
 int opcion;
 bool activado = false;

 while (true) {
  cout << "\n==== HOLA MUNDO DELUXE ====\n\n";
  cout << "1. Mostrar Hola Mundo\n";
  cout << "2. Mostrar fecha actual\n";
  cout << "3. Mostrar nombre del usuario\n";
  cout << "4. Mostrar varios mensajes\n";
  cout << "5. Activar colores\n";
  cout << "0. Salir\n\n";
  cout << "Seleccione una opcion: ";

  cin >> opcion;

  switch(opcion) {
   case 1:
    holamundo(activado);
    break;
   case 2:
    obtenerFecha(activado);
    break;
   case 3:
    pedirNombre(nombre);
    mostrarNombre(nombre, activado);
    break;
   case 4:
    mostrarMensajes(activado);
    break;
   case 5:
    activado = activarColores(activado);
    break;
   case 0:
    cout << "Finalizando programa...\n";
    return 0;
  }
 }
 return 0;
}
