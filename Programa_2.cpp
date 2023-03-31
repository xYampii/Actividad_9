#include <iostream>
using namespace std;

// Definición de la estructura Estudiante
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
};

// Función para calcular el promedio de un estudiante
float calcularPromedio(Estudiante* estudiante) {
    float promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4;
    return promedio;
}

// Función para imprimir si el estudiante aprobó o reprobó
void imprimirResultado(Estudiante* estudiante) {
    float promedio = calcularPromedio(estudiante);
    cout << "El estudiante " << estudiante->nombres << " " << estudiante->apellidos;
    cout << " con ID " << estudiante->id << " tiene un promedio de " << promedio << ". ";
    if (promedio >= 60) {
        cout << "Aprobó." << endl;
    } else {
        cout << "Reprobó." << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Crear un arreglo dinámico de estudiantes con tamaño N
    Estudiante* estudiantes = new Estudiante[n];

    // Pedir al usuario que ingrese los datos de cada estudiante
    for (int i = 0; i < n; i++) {
        cout << endl << "Ingrese los datos del estudiante " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;
    }

    // Imprimir los resultados para cada estudiante
    for (int i = 0; i < n; i++) {
        imprimirResultado(&estudiantes[i]);
    }

    // Liberar la memoria del arreglo dinámico de estudiantes
    delete[] estudiantes;

    return 0;
}