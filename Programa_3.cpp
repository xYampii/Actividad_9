#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Definición de estructura de estudiante
struct Estudiante {
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
    char resultado[10];
};

// Función para calcular el promedio de notas de un estudiante
float calcularPromedio(float notas[]) {
    float promedio = 0;
    for (int i = 0; i < 4; i++) {
        promedio += notas[i];
    }
    return promedio / 4;
}

// Función para determinar si un estudiante aprobó o reprobó
void determinarResultado(float promedio, char resultado[]) {
    if (promedio >= 60) {
        strcpy(resultado, "APROBADO");
    } else {
        strcpy(resultado, "REPROBADO");
    }
}

int main() {
    // Solicitar la cantidad de estudiantes a ingresar
    int n;
    cout << "Ingrese la cantidad de estudiantes a ingresar: ";
    cin >> n;

    // Crear un arreglo dinámico de estudiantes
    Estudiante *estudiantes = new Estudiante[n];

    // Pedir información de cada estudiante y calcular promedio y resultado
    for (int i = 0; i < n; i++) {
        cout << "\nIngrese información del estudiante " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin >> estudiantes[i].nombres;
        cout << "Apellidos: ";
        cin >> estudiantes[i].apellidos;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j+1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = calcularPromedio(estudiantes[i].notas);
        determinarResultado(estudiantes[i].promedio, estudiantes[i].resultado);
    }

    // Almacenar información de estudiantes en archivo binario
    ofstream archivo("notas.dat", ios::binary);
    if (!archivo) {
        cout << "Error al abrir archivo para escritura" << endl;
        return 1;
    }
    archivo.write(reinterpret_cast<char*>(estudiantes), n*sizeof(Estudiante));
    archivo.close();

    // Leer información de estudiantes desde archivo binario
    ifstream archivoLectura("notas.dat", ios::binary);
    if (!archivoLectura) {
        cout << "Error al abrir archivo para lectura" << endl;
        return 1;
    }
    Estudiante estudianteLeido;
    while (archivoLectura.read(reinterpret_cast<char*>(&estudianteLeido), sizeof(Estudiante))) {
        cout << "\nID: " << estudianteLeido.id << endl;
        cout << "Nombres: " << estudianteLeido.nombres << endl;
        cout << "Apellidos: " << estudianteLeido.apellidos << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Nota " << j+1 << ": " << estudianteLeido.notas[j] << endl;
        }
        cout << "Promedio: " << estudianteLeido.promedio << endl;
        cout << "Resultado: " << estudianteLeido.resultado << endl;
    }
    archivoLectura.close();

    // Liberar memoria del arreglo dinámico de estudiantes
    delete[] estudiantes;

    return 0;
}