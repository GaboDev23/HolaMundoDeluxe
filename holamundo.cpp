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

string agregarCero (int tiempo) {
 if (tiempo < 10) {
  return "0" + to_string(tiempo);
 }
 return to_string(tiempo);
}

void obtenerFecha(bool activado) {
 time_t tiempo = time(0);
 tm *f = localtime(&tiempo);
 string fecha;
 string hora;
 string h = agregarCero(f -> tm_hour);
 string m = agregarCero(f -> tm_min);
 string s = agregarCero(f -> tm_sec);
 string fechaBase = to_string(f -> tm_mday) + "/" + to_string(f -> tm_mon + 1) + "/" + to_string(f -> tm_year + 1900);
 string horaBase = h + ":" + m + ":" + s;

 if (activado) {
  fecha = "\033[32m" + fechaBase + "\033[0m";
  hora = "\033[32m" + horaBase + "\033[0m";
 } else {
  fecha = fechaBase;
  hora = horaBase;
 }
 cout << "Fecha: " << fecha << endl;
 cout << "Hora: " << hora << endl;
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
