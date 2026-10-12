#include <string>
#include <iostream>
using namespace std;

struct Masa
{
    float inaltime;
    string culoare;
};

/* Cerinte Seminar 3 - Partea I
* 1. Sa se scrie o functie care aloca dinamic un vector mese, functia primeste dimensiunea vectorului ca parametru.
* 2. Sa se scrie o functie care dezaloca un vector de mese primit ca parametru.
* 3. Sa se scrie o functie care face inserarea unei mese la finalul vectorului, parametrii functiei sunt vectorul si masa care trebuie inserata.
* 4. Sa se scrie o functie care elimina primul element din vectorul de mese, functia primeste doar vectorul ca parametru
* 5. Sa se scrie o functie care afiseaza elementele unui vector de mese primit ca parametru
*/

Masa initializareMasa(float inaltime, string culoare)
{
    Masa masa;

    masa.inaltime = inaltime;
    masa.culoare = culoare;

    return masa;
}

void afisareMasa(const Masa& m)
{
    cout << "Inaltimea mesei este: " << m.inaltime << "m\n";
    cout << "Culoarea mesei este: " << m.culoare << "\n\n";
}

int main()
{
    Masa masa = initializareMasa(5.0f, "Neagra");
    afisareMasa(masa);

    int dimensiune = 5;
    Masa* mese = new Masa[dimensiune];

    mese[0] = initializareMasa(3.5f, "Albastra");
    mese[1] = initializareMasa(5.5f, "Rosie");
    mese[2] = initializareMasa(2.75f, "Violet");
    mese[3] = initializareMasa(1.85f, "Verde");
    mese[4] = initializareMasa(0.15f, "Portocalie");

    cout << "Elementele vectorului de mese sunt afisate mai jos \n\n";

    for (int i = 0; i < dimensiune; i++)
    {
        afisareMasa(mese[i]);
    }

    delete[] mese;
    return 0;
}