#include <string>
#include <iostream>

using namespace std;

// 1. Sa se implementeze constructorul fara parametri pentru clasa Floare - realizat
// 2. Sa se implementeze constructorul cu toti parametrii pentru clasa Floare - realizat
// 3. Sa se implementeze constructorul de copiere pentru clasa Floare - realizat
// 4. Sa se implementeze operatorul de asignare pentru clasa Floare - realizat
// 5. Sa se implementeze destructorul pentru clasa Floare - realizat
// 6. Sa se implementeze metode de tip get/set pentru atributele clasei Floare

// IMPORTANT: pointerul lungimiPetale trebuie alocat dinamic

class Floare
{
private:

    float pret;
    string denumire;

    int numarPetale;
    float* lungimiPetale;

    const int ID; // atribut constant, se initializeaza obligatoriu in lista de initializare a constructorului
    static int contor; // atribut static, apartine clasei, nu este specific obiectelor, se comporta ca o variabila globala

public:

    Floare() : ID(++contor)
    {
        pret = 0.0f;
        denumire = "N/A";

        numarPetale = 0;
        lungimiPetale = nullptr;
    }

    Floare(float pret, string denumire, int numarPetale, float* lungimiPetale) : ID(++contor)
    {
        this->pret = pret;
        this->denumire = denumire;
        this->numarPetale = numarPetale;

        if (lungimiPetale == nullptr || numarPetale <= 0)
        {
            this->lungimiPetale = nullptr;
        }
        else
        {
            this->lungimiPetale = new float[this->numarPetale];

            for (int i = 0; i < numarPetale; i++)
            {
                this->lungimiPetale[i] = lungimiPetale[i];
            }
        }
    }

    /*
    * Constructorul de copiere pentru clasa Floare
    * 1. Obiectul destinatie abia se construieste, doar originalul exista
    * 2. Nu modifica originalul
    * 3. Originalul este transmis prin referinta pentru a evita apelul recursiv al constructorului de copiere
    * 4. Destinatia este chiar valoarea spre care pointeaza this-ul (obiectul nou creat)
    * 5. Compilatorul genereaza o versiune pentru acest constructor dar va face shallow copy atunci cand vom avea pointeri in lista de atribute
    * 6. Programatorul implementeaza acest constructor pentru a realiza deep copy in cazul pointerilor alocati dinamic
    */
    Floare(const Floare& original) : ID(++contor)
    {
        pret = original.pret;
        denumire = original.denumire;
        numarPetale = original.numarPetale;

        if (original.lungimiPetale == nullptr || original.numarPetale <= 0)
        {
            lungimiPetale = nullptr;
        }
        else
        {
            lungimiPetale = new float[original.numarPetale];

            for (int i = 0; i < original.numarPetale; i++)
            {
                lungimiPetale[i] = original.lungimiPetale[i];
            }
        }
    }

    /*
    * Operatorul de asignare pentru clasa Floare, permite operatii de genul f1 = f2
    * 1. Ambii operanzi trebuie sa existe
    * 2. Destinatia este chiar valoarea spre care pointeaza this-ul
    * 3. Returneaza o referinta pentru a evita apelul constructorului de copiere
    * 4. Nu modifica originalul
    * 5. Nu trebuie sa apeleze constructorul de copiere sub nicio forma, de aceea parametrul e transmis prin referinta, si returneaza prin referinta valoarea din this
    * 6. Compilatorul poate genera o varianta de astfel de operator de asignare,dar aceasta va face shallow copy daca avem un pointer alocat dinamic in clasa
    * 7. Se implementeaza explicit doar atunci cand avem pointeri alocati dinamic in clasa pentru a realiza deep copy
    * 8. Elibereaza resursele vechi alocate dinamic inainte de copierea celor noi din original
    */
    Floare& operator=(const Floare& original)
    {
        pret = original.pret;
        denumire = original.denumire;
        numarPetale = original.numarPetale;

        delete[] this->lungimiPetale;

        if (original.lungimiPetale == nullptr || original.numarPetale <= 0)
        {
            lungimiPetale = nullptr;
        }
        else
        {
            lungimiPetale = new float[original.numarPetale];

            for (int i = 0; i < original.numarPetale; i++)
            {
                lungimiPetale[i] = original.lungimiPetale[i];
            }
        }

        return *this;
    }

    /*
    * Destructorul clasei Floare
    * 1. Este unic
    * 2. Nu are parametri
    * 3. Nu are tip returnat, nici macar void
    * 4. Are acelasi nume cu clasa din care face parte dar e precedat de simbolul "~"
    * 5. Nu se apeleaza explicit de catre programator, compilatorul se ocupa de asta in mod automat (vezi main)
    * 6. Compilatorul genereaza un destructor default, dar acesta nu se va ocupa de eliberarea pointerilor alocati dinamic
    * 7. Se implementeaza explicit de catre programator pentru a elibera resursele alocate dinamic
    */
    ~Floare()
    {
        delete[] lungimiPetale;
        lungimiPetale = nullptr;
    }
};

int Floare::contor = 0; // membrii statici se initializeaza mereu in afara clasei

int main()
{
    /*Sa se testeze cerintele in functia main*/

    // un obiect care este facut cu constructorul fara parametri
    // un obiect care este facut cu constructorul cu toti parametrii
    // un obiect care este facut cu constructorul de copiere
    // un obiect existent care preia toate proprietatile unui alt obiect folosind operatorul =

    int nrPetale = 5;
    float lungimiPetale1[5] = { 2.2f, 1.8f, 2.0f, 2.5f, 1.75f };

    // Floare f1; // apel implicit al constructorului fara parametri
    Floare f1 = Floare(); // apel explicit al constructorului fara parametri
    Floare f2(15.5f, "Trandafir", nrPetale, lungimiPetale1);

    Floare f3 = f2; // apel capcana al constructorului de copiere, nu este vorba de operatorul de asignare, f3 abia se construieste
    //Floare f3 = Floare(f2); // apel explicit al constructorului de copiere
    //Floare f3(f2); // apel implicit al constructorului de copiere

    nrPetale = 3;
    float lungimiPetale2[3] = { 1.85f, 1.9f, 2.0f };

    Floare f4(9.99f, "Lalea", nrPetale, lungimiPetale2);
    f4 = f2; // operatorul de asignare, f4 si f2 exista amandoi pe aceasta linie

    //f4.~Floare(); // NU FACEM ASA CEVA, NICIODATA, SE OCUPA COMPILATORUL !!!!!!!!!!

    return 0;
}