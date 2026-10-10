#include <iostream>
using namespace std;

/*1. Sa se determine daca un numar natural citit de la tastatura este numar par
daca da sa se afiseze cuvantul Par altfel cuvantul Impar
*/

/*2. Sa se scrie o functie care primeste 2 parametri de tip float
* functia calculeaza si returneaza suma celor 2 numere
*/

/*3. Sa se scrie o functie care afiseaza valoarea unei variabile de tip intreg
functia primeste ca paramatru valoarea intreaga
*/

/*4. Se citeste un numar n de la tastatura, sa se afiseze toate numerele
mai mici sau egale cu n, pornind de la 0. Precizare facem codul in functia main
    1 - for -> facut
    2 - while -> facut
*/

/*5. Sa se scrie o functie care realizeaza interschimbarea valorilor a doua variabile
* de tip intreg, nu citim de la tastatura, le transmitem doar ca parametri
*/

void afisareNumar(int a)
{
    cout << "Valoarea lui numarului este: " << a << '\n';
}

float suma(float a, float b)
{
    //float sum = a + b;
    //return sum;
    return a + b; // forma echivalenta
}

void interschimbare(int a, int b) // nu face interschimbare in main deoarece parametrii sunt transmisi prin valoare
{
    int aux = a;
    a = b;
    b = aux;
}

int main()
{
    int a; // declarare a unei variabile de tip int

    cout << "Introduceti un numar: ";
    cin >> a;
    //cout << "Valoarea lui a este: " << a << '\n';

    afisareNumar(a);

    if (a % 2 == 0)
    {
        cout << "Par\n";
    }
    else
    {
        cout << "Impar\n";
    }

    cout << "Suma este: " << suma(5.2f, 6.1f) << '\n';

    int n;
    cout << "Valoarea lui n este: ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << "\n\n";

    int i = 0; // declararea unei variabile de tip int si initializarea ei cu o valoare

    while (i <= n)
    {
        cout << i << " ";
        i++;
    }

    cout << "\n\n";

    int x = 10;
    int y = 15;

    // sa se interschimbe valorile lui x si y

    /*int aux = x;
    x = y;
    y = aux;*/

    interschimbare(x, y); // la nivelul functiei interschimbare se vor face 2 copii locale pentru x si y

    afisareNumar(x);
    afisareNumar(y);

    int* ptr = &x; // declararea unui pointer la int si initializarea lui cu adresa variabilei x
    *ptr = 8;

    afisareNumar(x);
    return 0;
}