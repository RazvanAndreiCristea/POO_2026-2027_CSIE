#include <string>
#include <iostream>

using namespace std;

// 1. Sa se implementeze constructorul fara parametri pentru clasa Floare
// 2. Sa se implementeze constructorul cu toti parametrii pentru clasa Floare
// 3. Sa se implementeze constructorul de copiere pentru clasa Floare
// 4. Sa se implementeze operatorul de asignare pentru clasa Floare
// 5. Sa se implementeze destructorul pentru clasa Floare
// 6. Sa se implementeze metode de tip get/set pentru atributele clasei Floare

// IMPORTANT: pointerul lungimiPetale este alocat dinamic

class Floare
{
    float pret;
    string denumire;

    int numarPetale;
    float* lungimiPetale;

    const int ID;
    static int contor;
};

int main()
{
    /*Sa se testeze cerintele in functia main*/
    return 0;
}