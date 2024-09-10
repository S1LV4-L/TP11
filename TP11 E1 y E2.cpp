#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Alumno {
private:
     string nombre;
     double nota1;
     double nota2;
     double nota3;
     int edad;
     bool aprobado;
public:
     // Constructor
     Alumno(string nombre, int edad, double nota1, double nota2, double nota3)
     : nombre(nombre), edad(edad), nota1(nota1), nota2(nota2), nota3(nota3) {}
     // Getters
     string getNombre() const { return nombre; }
     double getNota1() const { return nota1; }
     double getNota2() const { return nota2; }
     double getNota3() const { return nota3; }
     double getEdad() const { return edad; }
     // Método para calcular el promedio
     double calcularPromedio() const { return (nota1 + nota2 + nota3)/ 3; }
     
	bool getAprobado() const {
	    if(((nota1+nota2+nota3)/3)>=7)
		{
		    cout<<"Estado: Aprobado";
		    return true;
		}
 	    else
 	    {
 	    	getDesaprobado();
		}
	}
	
	bool getDesaprobado() const {  
		cout<<"Estado: Desaprobado";
		return false;
		}
		
		void setCalificacion(bool calif)
		{
			aprobado=calif;
		}
};
int main() {
 // Vector para almacenar los alumnos
 vector<Alumno> alumnos;
// Ingresar datos de los alumnos y agregarlos al vector
 string nombre;
 double nota1, nota2, nota3;
 int numAlumnos, edad;
 cout << "Ingrese el número de alumnos: ";
 cin >> numAlumnos;
 for (int i = 0; i < numAlumnos; i++) {
     cout << "Ingrese el nombre del alumno: ";
     cin >> nombre;
     cout << "Ingrese la edad del alumno: ";
     cin >> edad; 
     cout << "Ingrese la nota 1 del alumno: ";
     cin >> nota1;
     cout << "Ingrese la nota 2 del alumno: ";
     cin >> nota2;
     cout << "Ingrese la nota 3 del alumno: ";
     cin >> nota3;
     alumnos.push_back(Alumno(nombre, edad, nota1, nota2, nota3));
 }
 // Mostrar los datos de los alumnos y sus promedios
 cout << "\nDatos de los alumnos:" << endl;
 for (const auto& alumno : alumnos) {
     cout << "Nombre: " << alumno.getNombre() << endl;
     cout << "Nota 1: " << alumno.getNota1() << endl;
     cout << "Nota 2: " << alumno.getNota2() << endl;
     cout << "Nota 3: " << alumno.getNota3() << endl;
     cout << "Promedio: " << alumno.calcularPromedio() << endl;
     cout<<alumno.getAprobado();  //El cout toma el valor del bool y lo muestra pero no deberia
     
     cout << endl;
 }
 return 0;
}
