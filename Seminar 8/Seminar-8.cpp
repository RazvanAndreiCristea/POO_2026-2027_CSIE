#include <string>
#include <iostream>

#pragma warning (disable : 4996)

using namespace std;

// 1. Sa se implemeteze toate metodele necesare astfel incat clasa Haina sa functioneze corect
// 2. Sa se stabileasca o legatura de tip "is-a" intre cele 2 clase (Haina si Geaca)
// 3. Sa se implementeze clasa Geaca, doar metodele si functiile necesare
// 4. Sa se testeze conceptul de mostenire in functia main

class Haina
{
    int marime;
    double pret;
    char* culoare; // sir de caractere care va fi alocat dinamic

protected:

    static char* copiazaSir(const char* original)
    {
        if (original == nullptr)
        {
            return nullptr;
        }

        char* copie = new char[1 + strlen(original)]; // se aduna 1 pentru ca sirul sa-si puna '\0' la final
        strcpy(copie, original);

        return copie;
    }

public:

    Haina()
    {
        marime = 0;
        pret = 0.0;
        culoare = nullptr;
    }

    Haina(const int marime, const double pret, const char* culoare) {
        this->marime = marime;
        this->pret = pret;
        this->culoare = copiazaSir(culoare);
    }

    Haina(const Haina& original)
    {
        this->marime = original.marime;
        this->pret = original.pret;
        this->culoare = copiazaSir(original.culoare);
    }

    Haina& operator=(const Haina& original)
    {
        if (this == &original)
        {
            return *this;
        }

        this->marime = original.marime;
        this->pret = original.pret;

        char* copie = copiazaSir(original.culoare);

        delete[] this->culoare;
        this->culoare = copie;

        return *this;
    }

    ~Haina()
    {
        delete[] this->culoare;
        this->culoare = nullptr;
    }

    friend ostream& operator<<(ostream& out, const Haina& h)
    {
        out << "Marime: " << h.marime << endl;
        out << "Pret: " << h.pret << " ron\n";
        out << "Culoare: " << (h.culoare == nullptr ? "N/A" : h.culoare) << endl;

        //out << "Culoare: ";

        //if (h.culoare == nullptr)
        //{
        //	out << "N/A\n";
        //}
        //else
        //{
        //	out << h.culoare << endl;
        //}

        return out;
    }
};

class Geaca : public Haina
{
    char* material;
    int numarBuzunare;
    float lungimeManeci;

public:

    Geaca() :Haina()
    {
        numarBuzunare = 0;
        lungimeManeci = 0.0f;
        material = nullptr;
    }

    Geaca(const int marime, const double pret, const char* culoare,
        const char* material, const int numarBuzunare, const float lungimeManeci)
        :Haina(marime, pret, culoare)
    {
        this->numarBuzunare = numarBuzunare;
        this->lungimeManeci = lungimeManeci;
        this->material = copiazaSir(material);
    }

    Geaca(const Geaca& original)
        :Haina(original)
    {
        this->numarBuzunare = original.numarBuzunare;
        this->lungimeManeci = original.lungimeManeci;
        this->material = copiazaSir(original.material);
    }

    Geaca& operator=(const Geaca& original)
    {
        if (this == &original)
        {
            return *this;
        }

        this->Haina::operator=(original);
        //(Haina&)(*this) = original;

        this->numarBuzunare = original.numarBuzunare;
        this->lungimeManeci = original.lungimeManeci;

        char* copie = copiazaSir(original.material);

        delete[] this->material;
        this->material = copie;

        return *this;
    }

    ~Geaca()
    {
        delete[] this->material;
        this->material = nullptr;
    }

    friend ostream& operator<<(ostream& out, const Geaca& g)
    {
        //out << (const Haina&)g;
        operator<<(out, (const Haina&)g);

        out << "Lungime maneci: " << g.lungimeManeci << " cm\n";
        out << "Numar buzunare: " << g.numarBuzunare << endl;
        out << "Material: " << (g.material == nullptr ? "N/A" : g.material) << endl;

        return out;
    }
};


int main()
{
    // 1. Testarea clasei de baza Haina

    Haina h1(2, 120.0, "Negru");
    Haina h2(h1); // Apelarea constructorului de copiere
    Haina h3; // Apelarea constructorului fara parametri

    h3 = h1; // Apelarea operatorului de asignare

    cout << "=== HAINA ===\n\n";

    cout << h1 << endl;
    cout << h2 << endl;
    cout << h3 << endl;

    // 2. Testarea clasei derivate Geaca

    // Un obiect de tip Geaca este si un obiect de tip Haina (relatie IS-A).
    // La construirea lui g1 se apeleaza mai intai constructorul
    // clasei Haina, apoi constructorul clasei Geaca.

    Geaca g1(3, 350.0, "Albastru", "Poliester", 4, 65.5f);

    cout << "=== GEACA ===\n\n";
    cout << g1 << endl;

    // 3. Constructorul de copiere al clasei derivate

    // Se apeleaza mai intai constructorul de copiere din Haina,
    // apoi constructorul de copiere din Geaca.
    // Astfel, sunt copiate profund atat culoare, cat si material.

    Geaca g2(g1);

    cout << "=== GEACA COPIATA ===\n\n";
    cout << g2 << endl;

    // 4. Operatorul de asignare al clasei derivate

    // Operatorul = din Geaca apeleaza explicit operatorul =
    // din Haina pentru copierea atributelor mostenite.
    // Ulterior sunt copiate atributele specifice clasei Geaca.

    Geaca g3;
    g3 = g1;

    cout << "=== GEACA ASIGNATA ===\n\n";
    cout << g3 << endl;

    // 5. Conversie implicita de la clasa derivata la clasa de baza

    // Deoarece Geaca mosteneste public Haina, un obiect Geaca
    // poate fi tratat ca un obiect Haina.
    // Aceasta conversie se numeste UPCASTING.

    Haina& referinta = g1;

    // Referinta nu creeaza un obiect nou si nu copiaza memoria.
    // Ea se refera la subobiectul Haina din g1.
    // Se apeleaza operatorul << pentru Haina, nu cel pentru Geaca.

    cout << "=== UPCASTING PRIN REFERINTA ===\n\n";
    cout << referinta << endl;

    // 6. Object slicing

    // Se construieste un obiect Haina pornind de la un obiect Geaca.
    // Se copiaza numai partea de Haina.
    // Atributele specifice clasei Geaca nu sunt pastrate.

    Haina h4 = g1;

    cout << "=== OBJECT SLICING ===\n\n";
    cout << h4 << endl;

    // 7. Asignarea unui obiect derivat catre unul de baza

    // Operatorul de asignare din Haina copiaza doar atributele
    // clasei de baza, chiar daca sursa este un obiect Geaca.

    Haina h5;
    h5 = g1;

    cout << "=== ASIGNARE GEACA CATRE HAINA ===\n\n";
    cout << h5;

    // La iesirea din main(), destructorii sunt apelati automat.
    // Pentru fiecare Geaca se executa mai intai ~Geaca(),
    // apoi ~Haina(), in ordine inversa construirii.

    return 0;
}