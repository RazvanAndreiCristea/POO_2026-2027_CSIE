#include <string>
#include <iostream>

using namespace std;

// 1. Sa se implementeze constructorul fara parametri pentru clasa Floare - realizat (S4)
// 2. Sa se implementeze constructorul cu toti parametrii pentru clasa Floare - realizat (S4)
// 3. Sa se implementeze constructorul de copiere pentru clasa Floare - realizat (S4)
// 4. Sa se implementeze operatorul de asignare pentru clasa Floare - realizat (S4)
// 5. Sa se implementeze destructorul pentru clasa Floare - realizat (S4)

// 6. Sa se implementeze metode de tip get/set pentru atributele clasei Floare - realizat (S5)
// 7. Sa se implementeze o functie statica in zona privata care copiaza elementele unui vector cu elemente de tip float, functia returneaza vectorul nou creat - realizat (S5)

// 8. Sa se supraincarce operatorul ++ care incrementeaza cu 1 elementele vectorului lungimiPetale (2 forme pre si post fixate)
// 9. Sa se supraincarce operatorul de indexare [] care acceseaza si returneaza un element din vectorul lungimiPetale (2 forme) - realizat (S5)
// 10. Sa se supraincarce operatorul -> pentru a accesa metodele publice ale unui obiect, f1->metoda(), (2 forme) - realizat (S5)

// 11. Se se supraincarce operatorul << care permite afisarea obiectelor de tip Floare (ca functie friend)
// 12. Sa se supraincarce operatorii == si != care verifica daca 2 obiecte de tip Floare sunt egale sau nu (ca metode)
// 13. Sa se supraincarce operatorul de apel de functie () care va seta atributele unui obiect de tip Floare (minim 2 forme)

// 14. Sa se implementeze operatorul + care aduna pretul unei flori cu o valoare primita ca parametru (functie friend) (2 forme)
// 14. Sa se implementeze operatorul -= care scade pretul unei flori cu o valoare primita ca parametru (functie membra) - realizat (S5)
// 15. Sa se implementeze operatorul de cast explicit de la o Floare la un float; se foloseste pretul unei flori (functie membra)
// 16. Sa se implementeze operatorul > care compara preturile a doua obiecte de tip Floare (functie membra) - realizat (S5)

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

    static float* copiazaVector(const int dimemnsiune, const float* original)
    {
        if (original == nullptr || dimemnsiune <= 0)
        {
            return nullptr;
        }

        float* copie = new float[dimemnsiune];

        for (int i = 0; i < dimemnsiune; i++)
        {
            copie[i] = original[i];
        }

        return copie;
    }

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
        this->lungimiPetale = copiazaVector(numarPetale, lungimiPetale);
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
        lungimiPetale = copiazaVector(original.numarPetale, original.lungimiPetale);
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
    * 9. Face verificarea de autoasignare/autoatribuire ca sa evite lucrul pe acelasi obiect, mai ales cand se lucreaza cu resurse alocate dinamic
    */
    Floare& operator=(const Floare& original)
    {
        if (this == &original) // verificarea de autoasignare
        {
            return *this;
        }

        pret = original.pret;
        denumire = original.denumire;
        numarPetale = original.numarPetale;

        delete[] lungimiPetale;
        lungimiPetale = copiazaVector(original.numarPetale, original.lungimiPetale);

        return *this;
    }

    // string getDenumire(const Floare* this)
    const string getDenumire() const
    {
        return denumire;
    }

    const float getPret() const
    {
        return pret;
    }

    const int getNumarPetale() const
    {
        return numarPetale;
    }

    const float* getLungimiPetale() const
    {
        return lungimiPetale;
    }

    // void setDenumire(Floare* this, string denumire)
    void setDenumire(const string denumire)
    {
        this->denumire = denumire;
    }

    void setPret(const float pret)
    {
        if (pret <= 0)
        {
            return;
        }

        this->pret = pret;
    }

    void setPetale(const int numarPetale, const float* lungimiPetale)
    {
        if (numarPetale <= 0 || lungimiPetale == nullptr)
        {
            return;
        }

        this->numarPetale = numarPetale;
        float* copie = copiazaVector(numarPetale, lungimiPetale);

        delete[] this->lungimiPetale;
        this->lungimiPetale = copie;
    }

    // float& operator[](Floare* this, const int index)
    float& operator[](const int index)
    {
        if (lungimiPetale != nullptr && index >= 0 && index <= numarPetale - 1)
        {
            return lungimiPetale[index];
        }
    }

    // const float& operator[](const Floare* this, const int index)
    const float& operator[](const int index) const
    {
        if (lungimiPetale != nullptr && index >= 0 && index <= numarPetale - 1)
        {
            return lungimiPetale[index];
        }
    }

    // Floare* operator->(Floare* this)
    Floare* operator->()
    {
        return this;
    }

    // const Floare* operator->(const Floare* this)
    const Floare* operator->() const
    {
        return this;
    }

    Floare& operator-=(const float valoare)
    {
        //this->pret = this->pret - valoare;
        this->pret -= valoare;
        return *this;
    }

    // bool operator>(const Floare* this, const Floare& f)
    bool operator>(const Floare& f) const
    {
        return pret > f.pret;
    }

    bool operator<(const Floare& f) const
    {
        return pret < f.pret;
    }

    // de aici continuam cu seminarul 6

    Floare& operator++()
    {
        if (lungimiPetale != nullptr)
        {
            for (int i = 0; i < numarPetale; i++)
            {
                ++lungimiPetale[i];
            }
        }

        return *this;
    }

    Floare operator++(int)
    {
        Floare copie = *this;
        ++(*this);
        return copie;
    }

    bool operator==(const Floare& f) const
    {
        if (this->pret != f.pret || this->numarPetale != f.numarPetale || this->denumire != f.denumire)
        {
            return false;
        }

        if (this->lungimiPetale == nullptr && f.lungimiPetale == nullptr)
        {
            return true;
        }

        if (this->lungimiPetale == nullptr || f.lungimiPetale == nullptr)
        {
            return false;
        }

        for (int i = 0; i < numarPetale; i++)
        {
            if (this->lungimiPetale[i] != f.lungimiPetale[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Floare& f) const
    {
        return !(*this == f);
    }

    Floare& operator()()
    {
        pret = 0.0f;
        denumire = "N/A";

        numarPetale = 0;
        delete[] lungimiPetale;
        lungimiPetale = nullptr;

        return *this;
    }

    Floare& operator()(float pret, string denumire)
    {
        this->pret = pret;
        this->denumire = denumire;

        return *this;
    }

    friend ostream& operator<<(ostream& out, const Floare& f)
    {
        out << "ID-ul florii este: " << f.ID << '\n';
        out << "Pretul florii este: " << f.pret << " euro\n";
        out << "Denumirea florii este: " << f.denumire << '\n';
        out << "Numarul de petale este: " << f.numarPetale << '\n';

        out << "Lungimile petalelor sunt: ";

        if (f.lungimiPetale == nullptr || f.numarPetale <= 0)
        {
            out << "Inexistente\n";
        }
        else
        {
            for (int i = 0; i < f.numarPetale; i++)
            {
                out << f.lungimiPetale[i] << " ";
            }
        }

        out << "\n\n";

        return out;
    }

    friend Floare operator+(const Floare& f, int x)
    {
        Floare copie = f;
        copie.pret = copie.pret + x;
        return copie;
    }

    friend Floare operator+(int x, const Floare& f)
    {
        return f + x;
    }

    explicit operator float() const
    {
        return pret + 0.21 * pret; // returnam pretul cu TVA cu tot
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
    int nrPetale = 3;
    float lungimiPetale[3] = { 2.2f, 1.95f, 2.05f };

    Floare f1(10.5f, "Hortensie", nrPetale, lungimiPetale);
    const Floare f2(11.5f, "Panseluta", nrPetale, lungimiPetale);

    Floare f3;
    Floare f4(f1); // Constructorul de copiere

    cout << "Denumire: " << f1.getDenumire() << '\n';
    cout << "Pret: " << f1.getPret() << '\n';
    cout << "Numar petale: " << f1.getNumarPetale() << '\n';

    for (int i = 0; i < f1.getNumarPetale(); i++)
    {
        cout << "Lungimea petalei " << i + 1 << ": " << f1.getLungimiPetale()[i] << '\n';
    }

    f3.setDenumire("Lalea");
    f3.setPret(25.5f);
    f3.setPetale(nrPetale, lungimiPetale);

    cout << "\nDenumire f3: " << f3.getDenumire() << '\n';
    cout << "Pret f3: " << f3.getPret() << '\n';
    cout << "Numar petale f3: " << f3.getNumarPetale() << '\n';
    cout << "Prima petala f3: " << f3.getLungimiPetale()[0] << '\n';

    // Testarea valorilor invalide pentru setteri
    f3.setPret(-10.0f);
    f3.setPetale(0, nullptr);

    cout << "\nPret f3 dupa valoare invalida: " << f3.getPret() << '\n';
    cout << "Numar petale f3 dupa valori invalide: " << f3.getNumarPetale() << '\n';

    f3 = f1; // f3.operator=(f1);
    f3 = f3; // f3.operator=(f3); - autoasignare

    f1[0] = 9.5f;
    cout << "\nPrima petala f1: " << f1[0] << '\n';
    cout << "Prima petala f3 (asignare): " << f3[0] << '\n';
    cout << "Prima petala f4 (constructor copiere): " << f4[0] << '\n';

    // Testarea operatorului [] pentru obiecte neconstante
    f1[1] = 2.02f; // f1.operator[](1) = 2.02f;

    cout << "\nA doua petala f1: " << f1[1] << '\n';
    // f1.operator[](1);

    // Testarea operatorului [] pentru obiecte constante
    cout << "A treia petala f2: " << f2[2] << '\n';
    // f2.operator[](2);

    // Testarea operatorului -> pentru obiecte neconstante
    f1->setPret(69.99f);
    // f1.operator->()->setPret(69.99f);

    cout << "\nPret f1: " << f1->getPret() << '\n';
    // f1.operator->()->getPret();

    // Testarea operatorului -> pentru obiecte constante
    cout << "Pret f2: " << f2->getPret() << '\n';
    // f2.operator->()->getPret();

    // Testarea operatorului -=
    f1 -= 5.0f; // f1.operator-=(5.0f);

    cout << "\nPret f1 dupa scadere: " << f1.getPret() << '\n';

    // Testarea operatorului >
    cout << "\nf1 > f2: " << (f1 > f2) << '\n';
    // f1.operator>(f2);

    // Testarea operatorului <
    cout << "f1 < f2: " << (f1 < f2) << '\n';
    // f1.operator<(f2);

    // =========================================================
    // Testarea operatorului de afisare <<
    // =========================================================

    cout << "\n========== OPERATOR << ==========\n";
    cout << "Starea initiala a obiectului f1:\n";
    cout << f1; // operator<<(cout, f1);

    // =========================================================
    // Testarea operatorului ++ (prefixat si postfixat)
    // =========================================================

    cout << "\n========== OPERATOR ++ ==========\n";

    ++f1; // f1.operator++();

    cout << "f1 dupa incrementarea prefixata (++f1):\n";
    cout << f1;

    Floare copieInainte = f1++; // f1.operator++(0);

    cout << "Valoarea returnata de incrementarea postfixata:\n";
    cout << copieInainte;

    cout << "f1 dupa incrementarea postfixata (f1++):\n";
    cout << f1;

    // =========================================================
    // Testarea operatorilor == si !=
    // =========================================================

    cout << "\n========== OPERATORII == SI != ==========\n";

    Floare f5(f1);

    cout << "f1 == f5: " << (f1 == f5) << '\n'; // f1.operator==(f5);
    cout << "f1 != f5: " << (f1 != f5) << '\n'; // f1.operator!=(f5);

    cout << "f1 == f2: " << (f1 == f2) << '\n';
    cout << "f1 != f2: " << (f1 != f2) << '\n';

    f5.setPret(200.0f);

    cout << "Dupa modificarea pretului lui f5:\n";
    cout << "f1 == f5: " << (f1 == f5) << '\n';
    cout << "f1 != f5: " << (f1 != f5) << '\n';

    // =========================================================
    // Testarea operatorului () - fara parametri
    // =========================================================

    cout << "\n========== OPERATOR () FARA PARAMETRI ==========\n";

    f1(); // f1.operator()();

    cout << "f1 dupa resetarea atributelor:\n";
    cout << f1;

    // =========================================================
    // Testarea operatorului () - cu doi parametri
    // =========================================================

    cout << "\n========== OPERATOR () CU PARAMETRI ==========\n";

    f1(100.0f, "Trandafir japonez");
    // f1.operator()(100.0f, "Trandafir japonez");

    cout << "f1 dupa modificarea pretului si denumirii:\n";
    cout << f1;

    // =========================================================
    // Testarea operatorului + (Floare + int si int + Floare)
    // =========================================================

    cout << "\n========== OPERATOR + ==========\n";

    Floare f6 = f1 + 5; // operator+(f1, 5);
    Floare f7 = 5 + f1; // operator+(5, f1);

    cout << "Obiectul original f1:\n";
    cout << f1;

    cout << "Rezultatul operatiei f1 + 5:\n";
    cout << f6;

    cout << "Rezultatul operatiei 5 + f1:\n";
    cout << f7;

    // =========================================================
    // Testarea operatorului de cast explicit la float
    // =========================================================

    cout << "\n========== OPERATOR CAST EXPLICIT ==========\n";

    float pretCuTVA = (float)f1;
    // float pretCuTVA = f1.operator float();

    cout << "Pretul initial al florii: " << f1.getPret() << '\n';
    cout << "Pretul florii cu TVA: " << pretCuTVA << '\n';

    return 0;
}