#include <string>
#include <iostream>
using namespace std;

// transmitere prin valoare -> ne-am lamurit din Seminarul 1 ca modificarile nu persista
//void interschimbare(int x, int y)
//{
//	int aux = x;
//	x = y;
//	y = aux;
//}

// transmiterea parametrilor prin pointer
void interschimbare(int* x, int* y)
{
    if (x == nullptr || y == nullptr)
    {
        return;
    }

    int aux = *x;
    *x = *y;
    *y = aux;
}

// trasmitere parametrilor prin referinta
void interschimbare(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

// sa se realizeze interschimbarea valorilor
// folosind referinte la pointeri
void interschimbareTema(int*& a, int*& b)
{
    if (a == nullptr || b == nullptr)
    {
        return;
    }

    int aux = *a;
    *a = *b;
    *b = aux;
}

// declararea structurii Masa care contine
// atributele inaltime si respectiv culoare
struct Masa
{
    float inaltime; // numar real
    string culoare; // sir de caractere
};

/* Sa se scrie o functie care initializeaza un obiect
* de tip Masa pe baza parametrilor si intoarce masa
*/
Masa initializareMasa(float inaltime, string culoare)
{
    Masa masa;

    masa.inaltime = inaltime;
    masa.culoare = culoare;

    return masa;
}

// Sa se scrie o functie care afiseaza o masa primita ca parametru
void afisareMasa(const Masa& m)
{
    //m.inaltime = 100; // eroare de compilare pentru ca masa este constanta

    //float inaltime = m.inaltime + 10000; // este permis pentru ca masa apare in partea dreapta a egalului
    cout << "Inaltimea mesei este: " << m.inaltime << "m\n";
    cout << "Culoarea mesei este: " << m.culoare << "\n\n";
}

int main()
{
    int a = 22;
    int b = 76;

    cout << "Valoarea lui a este: " << a << '\n';
    cout << "Valoarea lui b este: " << b << '\n';

    cout << "Adresa lui a este: " << &a << '\n';
    cout << "Adresa lui b este: " << &a << "\n\n";

    int* ptr = &a;
    cout << "Valoarea este de la adresa de pointare este: " << *ptr << "\n\n";

    cout << "Adresa lui a este: " << &a << '\n';
    cout << "Adresa lui ptr este: " << &ptr << '\n';
    cout << "Adresa de pointare a lui ptr este: " << ptr << "\n\n";

    interschimbare(&a, &b); // trimitem adresele celor 2 variabile si modificarile vor fi facute la aceste adrese

    cout << "Valoarea lui a dupa interschimbarea prin pointer este: " << a << '\n';
    cout << "Valoarea lui b dupa interschimbarea prin pointer este: " << b << "\n\n";

    int x = 100;
    int& ref = x; // declararea si intializarea unei referinte la int

    cout << "Valoarea lui ref este: " << ref << "\n\n";

    ref = 500; // modificam valoarea referintei

    cout << "Valoarea lui x este: " << x << '\n';
    cout << "Adresa lui x este: " << &x << '\n';
    cout << "Adresa lui ref este: " << &ref << "\n\n";

    interschimbare(a, b); // ii trimitem direct pe a si b in functie nu se vor genera copii

    cout << "Valoarea lui a dupa interschimbarea prin referinta este: " << a << '\n';
    cout << "Valoarea lui b dupa interschimbarea prin referinta este: " << b << "\n\n";

    int* ptr1 = &a;
    int* ptr2 = &b;

    interschimbareTema(ptr1, ptr2); // trimitem direct pointerii in functie prin referinta

    cout << "Valoarea lui a dupa interschimbarea prin referinta la pointer este: " << a << '\n';
    cout << "Valoarea lui b dupa interschimbarea prin referinta la pointer este: " << b << "\n\n";

    // Lucram cu structura Masa

    Masa masa = initializareMasa(5.0f, "Neagra");
    afisareMasa(masa);

    int dimensiune = 5;
    Masa* mese = new Masa[dimensiune]; // alocarea dinamica a unui vector de mese

    mese[0] = initializareMasa(3.5f, "Albastra");
    mese[1] = initializareMasa(5.5f, "Rosie");
    mese[2] = initializareMasa(2.75f, "Violet");
    mese[3] = initializareMasa(1.85f, "Verde");
    mese[4] = initializareMasa(0.15f, "Portocalie");

    cout << "Elementele vectorului de mese sunt afisate mai jos \n\n";

    // sa se afiseze elementele vectorului de mese
    for (int i = 0; i < dimensiune; i++)
    {
        afisareMasa(mese[i]);
    }

    delete[] mese; // dezalocarea vectorului de mese (eliberam memoria blocului contiguu)
    return 0;
}