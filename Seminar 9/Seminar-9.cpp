#include <string>
#include <iostream>

#pragma warning (disable : 4996)

using namespace std;

// 1. Sa se implemeteze toate metodele si functiile necesare astfel incat clasele EchipamentSportiv si Buzunar sa functioneze corect.
// 2. Sa se stabileasca o legaturile de tip "is-a" si "has-a/has-many" intre clase.
// 3. Sa se adapteze clasa Geaca astfel incat sa se adapteze la cele 2 clase noi introduse.
// 4. Sa se implementeze cativa getteri si setteri pentru a demonstra utilitatea specificatorilor de acces.
// 5. Sa se testeze conceptul de mostenire multipla in functia main.

class Haina
{
    int marime;
    double pret;
    char* culoare;

protected:

    static char* copiazaSir(const char* original)
    {
        if (original == nullptr)
        {
            return nullptr;
        }

        char* copie = new char[1 + strlen(original)]; // se aduna 1 pentru ca sirul sa-si puna caracterul '\0' la final
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

    Haina(const int marime, const double pret, const char* culoare)
    {
        this->pret = pret;
        this->marime = marime;
        this->culoare = copiazaSir(culoare);
    }

    Haina(const Haina& original)
    {
        this->pret = original.pret;
        this->marime = original.marime;
        this->culoare = copiazaSir(original.culoare);
    }

    Haina& operator=(const Haina& original)
    {
        if (this == &original)
        {
            return *this;
        }

        this->pret = original.pret;
        this->marime = original.marime;

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

        return out;
    }
};

class EchipamentSportiv
{
    char* tipSport;
    bool esteImpermeabil;
    float gradIzolareTermica;
};

class Buzunar
{
    float adancime;
    bool esteInterior;
    string tipInchidere;
};

class Geaca : public Haina
{
    char* material;
    float lungimeManeci;

    int numarBuzunare;

public:

    Geaca() : Haina()
    {
        numarBuzunare = 0;
        lungimeManeci = 0.0f;
        material = nullptr;
    }

    Geaca(const int marime, const double pret, const char* culoare,
        const char* material, const int numarBuzunare, const float lungimeManeci)
        : Haina(marime, pret, culoare)
    {
        this->numarBuzunare = numarBuzunare;
        this->lungimeManeci = lungimeManeci;
        this->material = copiazaSir(material);
    }

    Geaca(const Geaca& original) : Haina(original)
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
        operator<<(out, (const Haina&)g);

        out << "Lungime maneci: " << g.lungimeManeci << " cm\n";
        out << "Numar buzunare: " << g.numarBuzunare << endl;
        out << "Material: " << (g.material == nullptr ? "N/A" : g.material) << endl;

        return out;
    }
};

int main()
{
    /*Sa se testeze functionalitatile aici*/

    return 0;
}