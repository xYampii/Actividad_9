#include <iostream>
#include <string>

using namespace std;

struct Estudiante {

    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
};

int main() {
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    Estudiante estudiantes[N];

    for (int i = 0; i < N; i++) {
        cout << "Ingrese el id del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese los nombres del estudiante " << i+1 << ": ";
        cin.ignore();
        getline(cin, estudiantes[i].nombres);
        cout << "Ingrese los apellidos del estudiante " << i+1 << ": ";
        getline(cin, estudiantes[i].apellidos);
        cout << "Ingrese la nota 1 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota1;
        cout << "Ingrese la nota 2 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota2;
        cout << "Ingrese la nota 3 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota3;
        cout << "Ingrese la nota 4 del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nota4;
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        float promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4;
        cout << "El estudiante " << estudiantes[i].nombres << " " << estudiantes[i].apellidos << " con id " << estudiantes[i].id << " tiene un promedio de " << promedio;
        if (promedio >= 60) {
            cout << " , ah aprobado." << endl;
        } else {
            cout << " , ah reprobado." << endl;
        }
    }

    return 0;
}
