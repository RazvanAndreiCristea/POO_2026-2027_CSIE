#include <string>
#include <iostream>
using namespace std;

struct Masa
{
    float inaltime;
    string culoare;
};

class Scaun
{
private:

    // lista de atribute / membri / campuri

    float pret;
    int anFabricare;

    string material;
    string culoare;

public:

    Scaun() // constructor fara parametri
    {
        pret = 0.0f;
        anFabricare = -1;
        material = "N/A";
        culoare = "N/A";
    }

    Scaun(const float pret, int anFabricare) // constructor cu 2 parametri
    {
        (*this).pret = pret; // dereferentiem pointerul this si apoi accesam membrul pret
        this->anFabricare = anFabricare; // o forma mai scurta de accesare a membrului anFabricare, operatorul -> este echivalentul scrierii de mai sus
        material = "N/A"; // nu este nevoie de this deoarece nu avem o variabila sau un parametru definite in acest constructor ca sa coincida ca si denumire cu material
        culoare = "N/A";
    }
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

Masa* alocareVectorMese(const int& dimensiune) // cerinta 1
{
    Masa* mese = new Masa[dimensiune];
    return mese;
}

void inserareMasa(Masa*& mese, int& dimensiune, const Masa& masa)
{
    if (dimensiune < 0 || (mese == nullptr && dimensiune != 0) || (mese != nullptr && dimensiune == 0))
    {
        return;
    }

    Masa* vectorNou = new Masa[dimensiune + 1];

    for (int i = 0; i < dimensiune; i++)
    {
        vectorNou[i] = mese[i];
    }

    vectorNou[dimensiune] = masa;
    delete[] mese;

    mese = vectorNou;
    dimensiune++;
}

void eliminarePrimaMasa(Masa*& mese, int& dimensiune)
{
    if (mese == nullptr || dimensiune <= 0)
    {
        return;
    }

    if (dimensiune == 1)
    {
        delete[] mese;

        mese = nullptr;
        dimensiune = 0;

        return;
    }

    Masa* vectorNou = new Masa[dimensiune - 1];

    for (int i = 1; i < dimensiune; i++)
    {
        vectorNou[i - 1] = mese[i];
    }

    delete[] mese;
    mese = vectorNou;
    dimensiune--;
}

void afisareMese(Masa*& mese, const int& dimensiune) // cerinta 5
{
    if (mese == nullptr || dimensiune <= 0)
    {
        return;
    }

    for (int i = 0; i < dimensiune; i++)
    {
        afisareMasa(mese[i]);
    }
}

void dezalocareMese(Masa*& mese) // cerinta 2
{
    // dezalocarea s-ar face corect si daca nu folosim referinta la parametru
    // dar atribuirea cu nullptr nu ar persista in afara functiei deoarece
    // pointerul ar fi transmis de fapt prin valoare

    delete[] mese;
    mese = nullptr;
}

int main()
{
    Masa masa = initializareMasa(5.0f, "Neagra");
    afisareMasa(masa);

    int dimensiune = 5;
    Masa* mese = alocareVectorMese(dimensiune); // cerinta 1 - rezolvata

    mese[0] = initializareMasa(3.5f, "Albastra");
    mese[1] = initializareMasa(5.5f, "Rosie");
    mese[2] = initializareMasa(2.75f, "Violet");
    mese[3] = initializareMasa(1.85f, "Verde");
    mese[4] = initializareMasa(0.15f, "Portocalie");

    cout << "Elementele vectorului de mese sunt afisate mai jos \n\n";

    afisareMese(mese, dimensiune);

    Masa masaNoua = initializareMasa(3, "Alba");
    inserareMasa(mese, dimensiune, masaNoua);

    cout << "Elementele vectorului de mese dupa inserare sunt afisate mai jos \n\n";

    afisareMese(mese, dimensiune);
    eliminarePrimaMasa(mese, dimensiune);

    cout << "Elementele vectorului de mese dupa eliminarea primei mese sunt afisate mai jos \n\n";

    afisareMese(mese, dimensiune);
    dezalocareMese(mese);

    Scaun scaun(500.0f, 2026); // se apeleaza constructorul cu 2 parametri, se mai putea scrie si Scaun scaun = Scaun(500.0f, 2026);
    Scaun scaun2; // se apeleaza constructorul fara parametri se mai putea scrie si Scaun scaun2 = Scaun();

    return 0;
}