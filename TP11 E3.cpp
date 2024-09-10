#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
class Alumno {
private:
     string nombre;
     double nota1;
     double nota2;
     double nota3;
public:
     // Constructor
     Alumno(string nombre, double nota1, double nota2, double nota3)
     : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3) {}
     // Getters
     string getNombre() const { return nombre; }
     double getNota1() const { return nota1; }
     double getNota2() const { return nota2; }
     double getNota3() const { return nota3; }
     // Método para calcular el promedio
     double calcularPromedio() const { return (nota1 + nota2 + nota3)/ 3; }
     
    static void BuscarAlumno(const vector<Alumno>& alumnos, const string& a) {        //este metodo no se ejecuta o se mezcla con otro código
        for (const auto& alumno : alumnos) {
            if (alumno.getNombre() == a) {
                cout << "Nombre: " << alumno.getNombre() << endl;
                cout << "Nota 1: " << alumno.getNota1() << endl;
                cout << "Nota 2: " << alumno.getNota2() << endl;
                cout << "Nota 3: " << alumno.getNota3() << endl;
                cout << "Promedio: " << alumno.calcularPromedio() << endl;
                return;  
            }
        }
        cout << "Alumno "<<a<<" no encontrado."<<endl;
    }
};

int main() {
    // Vector para almacenar los alumnos
    vector<Alumno> alumnos;

    // Ingresar datos de los alumnos y agregarlos al vector
    string nombre, a;
    double nota1, nota2, nota3;
    int numAlumnos;

    cout << "Ingrese el número de alumnos: ";
    cin >> numAlumnos;
    cin.ignore(); 

    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno: ";
        getline(cin, nombre);

        for (int j = 0; j < nombre.size(); j++) {
            if (j == 0 || nombre[j - 1] == ' ') {
                nombre[j] = toupper(nombre[j]);
            } else {
                nombre[j] = tolower(nombre[j]);
            }
        }

        cout << "Ingrese la nota 1 del alumno: ";
        cin >> nota1;
        cout << "Ingrese la nota 2 del alumno: ";
        cin >> nota2;
        cout << "Ingrese la nota 3 del alumno: ";
        cin >> nota3;
        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3));
        cin.ignore();
    }

    cout << "Ingrese el nombre del alumno a buscar: ";
    getline(cin, a);

    for (int j = 0; j < a.size(); j++) {
        if (j == 0 || a[j - 1] == ' ') {
            a[j] = toupper(a[j]);
        } else {
            a[j] = tolower(a[j]);
        }
    }

    Alumno::BuscarAlumno(alumnos, a);

    // Mostrar los datos de todos los alumnos y sus promedios
    cout << "\nDatos de los alumnos:" << endl;
    for (const auto& alumno : alumnos) {
        cout << "Nombre: " << alumno.getNombre() << endl;
        cout << "Nota 1: " << alumno.getNota1() << endl;
        cout << "Nota 2: " << alumno.getNota2() << endl;
        cout << "Nota 3: " << alumno.getNota3() << endl;
        cout << "Promedio: " << alumno.calcularPromedio() << endl;
        cout << endl;
    }

    return 0;
 }
