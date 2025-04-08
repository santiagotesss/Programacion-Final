#include <iostream>
#include <ctime> // Para obtener la hora actual
using namespace std;

int main() {
    int opcion;
    int desplazamientos[] = {-12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};

    cout << "Selecciona una zona horaria para ver la hora actual:\n";
    for (int i = 0; i < 24; i++) {
        cout << i + 1 << ". UTC" << (desplazamientos[i] >= 0 ? "+" : "") << desplazamientos[i] << ":00\n";
    }
    cout << "Elige una opcion (1-24): ";
    cin >> opcion;

    if (opcion < 1 || opcion > 24) {
        cout << "Opcion no válida. Por favor, selecciona un numero entre 1 y 24.\n";
        return 1;
    }

    time_t ahora = time(0);
    tm* utcHora = gmtime(&ahora); // Obtiene la hora en formato UTC
    utcHora->tm_hour += desplazamientos[opcion - 1]; // Ajusta el desplazamiento de la zona horaria

    // Normaliza la hora (maneja cambios de día)
    if (utcHora->tm_hour >= 24) {
        utcHora->tm_hour -= 24;
        utcHora->tm_mday += 1; // Cambia al día siguiente
    } else if (utcHora->tm_hour < 0) {
        utcHora->tm_hour += 24;
        utcHora->tm_mday -= 1; // Cambia al día anterior
    }

    cout << "La hora en UTC" << (desplazamientos[opcion - 1] >= 0 ? "+" : "") 
         << desplazamientos[opcion - 1] << ":00 es: "
         << utcHora->tm_hour << ":" << utcHora->tm_min << ":" << utcHora->tm_sec << endl;

    return 0;
}
