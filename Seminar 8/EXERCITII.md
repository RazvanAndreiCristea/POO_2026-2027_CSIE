
# Exerciții suplimentare – Moștenirea în C++

- **Materia:** Programare Orientată pe Obiecte (POO)
- **Seminar:** Seminarul 8 · Moștenirea în C++
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Scopul acestor exerciții este aprofundarea conceptului de **moștenire în C++**, prin implementarea unor clase aflate într-o relație de tip **IS-A**.

Veți urmări în special:

- stabilirea unei relații de moștenire între două clase;
- reutilizarea atributelor și metodelor clasei de bază;
- apelarea constructorilor clasei de bază din constructorii clasei derivate;
- implementarea constructorului de copiere și a operatorului de asignare în contextul moștenirii;
- gestionarea corectă a memoriei alocate dinamic în ambele clase;
- apelarea operatorilor de afișare ai clasei de bază din clasa derivată;
- conversia implicită de la un obiect derivat la tipul clasei de bază (*upcasting*);
- înțelegerea fenomenului de *object slicing*;
- identificarea ordinii în care sunt apelați constructorii și destructorii.

> [!NOTE]
> **Exercițiile sunt opționale și nu se punctează.** Scopul lor este să vă ajute să consolidați noțiunile discutate la seminar, prin rezolvarea individuală a unor probleme asemănătoare.

---

### 2. Organizarea programului

Vom considera două clase, `InstrumentMuzical` și `Chitara`, între care există o relație de moștenire.

O chitară este un instrument muzical, deci relația dintre cele două clase este de tip **IS-A**.

Clasa `InstrumentMuzical` va conține următoarele atribute:

- `denumire` – șir de caractere alocat dinamic (`char*`);
- `pret` – valoare de tip `double`;
- `anFabricatie` – valoare de tip `int`.

Clasa `Chitara` va adăuga următoarele atribute:

- `tipCorzi` – șir de caractere alocat dinamic (`char*`);
- `numarCorzi` – valoare de tip `int`;
- `lungimeScala` – valoare de tip `float`, exprimată în centimetri.

Declarațiile inițiale ale claselor sunt:

```cpp
class InstrumentMuzical
{
private:
    char* denumire;
    double pret;
    int anFabricatie;

protected:
    static char* copiazaSir(const char* original);

public:
    // Implementati metodele si functiile necesare.
};

class Chitara : public InstrumentMuzical
{
private:
    char* tipCorzi;
    int numarCorzi;
    float lungimeScala;

public:
    // Implementati metodele si functiile necesare.
};
```

> [!IMPORTANT]
> Rezolvați toate exercițiile într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.
>
> Pentru gestionarea șirurilor de caractere, utilizați `char*`, `new[]`, `delete[]` și funcțiile necesare din `<string>`.
>
> Nu înlocuiți pointerii alocați dinamic cu `std::string` și nu utilizați containere STL pentru aceste atribute.
>
> Implementați singuri metodele solicitate. Semnăturile și exemplele oferite au rol orientativ și nu reprezintă soluții complete.

---

### 3. Exerciții ușoare – 8 exerciții

#### Exercițiul 1 – Stabilirea relației de moștenire

Definiți clasele `InstrumentMuzical` și `Chitara` folosind atributele prezentate anterior.

Clasa `Chitara` trebuie să moștenească **public** clasa `InstrumentMuzical`.

**Cerințe:**

1. Declarați atributele în zona `private` a fiecărei clase.
2. Declarați funcția statică `copiazaSir()` în zona `protected` a clasei de bază.
3. Stabiliți relația de moștenire folosind sintaxa corespunzătoare.
4. Explicați, printr-un comentariu, de ce relația dintre cele două clase este de tip IS-A.

> [!TIP]
> Gândiți-vă dacă orice chitară poate fi considerată instrument muzical și dacă orice instrument muzical poate fi considerat chitară.

---

#### Exercițiul 2 – Constructorii fără parametri

Implementați constructorii fără parametri pentru ambele clase.

**Cerințe:**

1. Constructorul clasei `InstrumentMuzical` trebuie să inițializeze toate atributele cu valori implicite.
2. Constructorul clasei `Chitara` trebuie să apeleze constructorul fără parametri al clasei de bază.
3. Inițializați separat atributele specifice clasei `Chitara`.
4. Pentru pointerii de tip `char*`, utilizați inițializarea cu `nullptr`.

**Exemplu de utilizare:**

```cpp
InstrumentMuzical instrument;
Chitara chitara;
```

**Întrebare:** În ce ordine sunt apelați constructorii atunci când se creează un obiect de tip `Chitara`?

---

#### Exercițiul 3 – Constructorii cu toți parametrii

Implementați constructorii cu toți parametrii pentru ambele clase.

Constructorul clasei `Chitara` trebuie să primească atât valorile atributelor moștenite, cât și valorile atributelor proprii.

**Cerințe:**

1. Utilizați lista de inițializare pentru apelarea constructorului clasei de bază.
2. Nu inițializați manual în clasa derivată atributele care aparțin clasei de bază.
3. Realizați copiere profundă pentru pointerii de tip `char*`.
4. Folosiți funcția `copiazaSir()` pentru alocarea și copierea șirurilor de caractere.

**Exemplu de utilizare:**

```cpp
Chitara c1("Chitara acustica", 1500.0, 2024, "Nylon", 6, 65.0f);
```

> [!IMPORTANT]
> Un obiect de tip `Chitara` conține și partea corespunzătoare clasei `InstrumentMuzical`. Constructorul clasei derivate nu trebuie să dubleze codul deja implementat în constructorul clasei de bază.

---

#### Exercițiul 4 – Constructorii de copiere

Implementați constructorii de copiere pentru ambele clase.

**Cerințe:**

1. Constructorul de copiere din `InstrumentMuzical` trebuie să realizeze copierea profundă a atributului `denumire`.
2. Constructorul de copiere din `Chitara` trebuie să apeleze constructorul de copiere al clasei de bază.
3. Copiați profund atributul `tipCorzi`.
4. Copiați celelalte atribute specifice clasei derivate.

**Exemplu de utilizare:**

```cpp
Chitara c1("Chitara clasica", 900.0, 2023, "Nylon", 6, 64.0f);
Chitara c2(c1);
```

**Întrebare:** Ce s-ar întâmpla dacă atributele `denumire` și `tipCorzi` ar fi copiate doar prin atribuirea adreselor pointerilor?

---

#### Exercițiul 5 – Operatorii de asignare

Supraîncărcați operatorul `=` pentru ambele clase.

**Cerințe:**

1. Tratați corect autoasignarea.
2. Realizați copiere profundă pentru șirurile alocate dinamic.
3. Eliberați memoria veche înainte de a înlocui pointerii, păstrând o copie validă a noilor date.
4. În operatorul de asignare al clasei `Chitara`, apelați explicit operatorul de asignare al clasei `InstrumentMuzical`.
5. Returnați o referință la obiectul curent.

**Exemplu de utilizare:**

```cpp
Chitara c1("Chitara electrica", 3200.0, 2025, "Otel", 6, 64.8);
Chitara c2;

c2 = c1;
c2 = c2;
```

> [!TIP]
> Observați diferența dintre apelarea constructorului de copiere al clasei de bază și apelarea operatorului său de asignare.

---

#### Exercițiul 6 – Destructorii și eliberarea memoriei

Implementați destructorii pentru ambele clase.

**Cerințe:**

1. Destructorul clasei `InstrumentMuzical` trebuie să elibereze memoria atributului `denumire`.
2. Destructorul clasei `Chitara` trebuie să elibereze memoria atributului `tipCorzi`.
3. Nu eliberați manual, în destructorul clasei derivate, memoria atributelor aparținând clasei de bază.
4. Testați distrugerea automată a obiectelor locale.

**Exemplu:**

```cpp
{
    Chitara c1("Chitara bass", 2400.0, 2022, "Metal", 4, 86.0f);
}

// Obiectul c1 este distrus la iesirea din bloc.
```

**Întrebare:** În ce ordine sunt apelați destructorii pentru un obiect de tip `Chitara`?

---

#### Exercițiul 7 – Supraîncărcarea operatorului de afișare

Supraîncărcați operatorul `<<` ca funcție `friend` pentru fiecare clasă.

**Cerințe:**

1. Operatorul din `InstrumentMuzical` trebuie să afișeze toate cele trei atribute ale clasei de bază.
2. Operatorul din `Chitara` trebuie să afișeze atât atributele moștenite, cât și cele specifice.
3. Reutilizați operatorul de afișare al clasei de bază în implementarea celui din clasa derivată.
4. Tratați corespunzător pointerii care au valoarea `nullptr`.

**Exemplu de utilizare:**

```cpp
Chitara c1("Chitara acustica", 1200.0, 2024, "Bronz", 6, 65.0f);

cout << c1 << endl;
```

**Exemplu orientativ de afișare:**

```text
Denumire: Chitara acustica
Pret: 1200 lei
An fabricatie: 2024
Tip corzi: Bronz
Numar corzi: 6
Lungime scala: 65 cm
```

> [!IMPORTANT]
> Nu duplicați în operatorul clasei derivate instrucțiunile de afișare pentru atributele moștenite. Reutilizați funcționalitatea deja implementată în clasa de bază.

---

#### Exercițiul 8 – Upcasting și object slicing

După implementarea claselor, testați conversia implicită de la clasa derivată la clasa de bază.

**Cerințe:**

1. Construiți un obiect de tip `Chitara`.
2. Declarați o referință de tip `InstrumentMuzical&` către obiectul respectiv.
3. Declarați un pointer de tip `InstrumentMuzical*` către același obiect.
4. Afișați obiectul folosind referința.
5. Construiți un obiect nou de tip `InstrumentMuzical` pornind de la obiectul `Chitara`.
6. Comparați rezultatele.

**Exemplu:**

```cpp
Chitara c1("Chitara electrica", 2800.0, 2025, "Otel", 6, 64.8f);

InstrumentMuzical& referinta = c1;
InstrumentMuzical* pointer = &c1;

InstrumentMuzical instrument = c1;

cout << referinta << endl;
cout << *pointer << endl;
cout << instrument << endl;
```

**Întrebări:**

- Ce reprezintă operația de *upcasting*?
- Se creează un obiect nou atunci când folosim o referință către clasa de bază?
- Ce se întâmplă în cazul instrucțiunii `InstrumentMuzical instrument = c1;`?
- De ce nu sunt păstrate atributele specifice clasei `Chitara` în obiectul `instrument`?

> [!NOTE]
> Conversia către clasa de bază este permisă datorită moștenirii publice.
>
> Fenomenul prin care se copiază numai partea corespunzătoare clasei de bază într-un obiect separat se numește **object slicing**.
>
> În acest exemplu, operatorii `<<` sunt funcții `friend`, nu metode virtuale. Alegerea operatorului depinde de tipul expresiei transmise.

---

### 4. Exerciții de dificultate medie – 3 exerciții

#### Exercițiul 9 – Verificarea independenței obiectelor copiate

Extindeți clasele implementate anterior prin adăugarea următoarelor metode:

```cpp
// In clasa InstrumentMuzical
void setDenumire(const char* denumire);

// In clasa Chitara
void setTipCorzi(const char* tipCorzi);
```

**Cerințe:**

1. Implementați metodele folosind copiere profundă.
2. Tratați corect situația în care parametrul este `nullptr`.
3. Testați copierea prin constructorul de copiere.
4. Testați copierea prin operatorul de asignare.
5. Modificați ulterior denumirea și tipul corzilor unui singur obiect.
6. Verificați dacă celelalte obiecte își păstrează valorile inițiale.

**Exemplu orientativ:**

```cpp
Chitara c1(
    "Chitara clasica",
    1000.0,
    2023,
    "Nylon",
    6,
    65.0f
);

Chitara c2(c1);
Chitara c3;

c3 = c1;

c1.setDenumire("Chitara modificata");
c1.setTipCorzi("Metal");

cout << c1 << endl;
cout << c2 << endl;
cout << c3 << endl;
```

**Rezultat așteptat:** Modificarea obiectului `c1` nu trebuie să afecteze valorile atributelor dinamice din obiectele `c2` și `c3`.

> [!WARNING]
> Nu este suficient ca programul să afișeze corect datele. Asigurați-vă că fiecare obiect deține propriile zone de memorie pentru șirurile alocate dinamic.
>
> Fiți atenți și la situația în care setterul primește chiar pointerul către șirul deja deținut de obiect. Nu trebuie să distrugeți sursa înainte de copiere.

---

#### Exercițiul 10 – Moștenirea pe trei niveluri

Extindeți ierarhia existentă prin introducerea clasei `ChitaraElectrica`, derivată public din clasa `Chitara`.

Noua clasă va avea următoarele atribute:

```cpp
class ChitaraElectrica : public Chitara
{
private:
    char* tipDoze;
    int numarDoze;

public:
    // Implementati metodele si functiile necesare.
};
```

**Cerințe:**

1. Implementați constructorul fără parametri.
2. Implementați constructorul cu toți parametrii.
3. Implementați constructorul de copiere.
4. Supraîncărcați operatorul de asignare.
5. Implementați destructorul.
6. Supraîncărcați operatorul `<<` ca funcție `friend`.
7. Realizați copiere profundă pentru atributul `tipDoze`.
8. Reutilizați metodele și funcțiile claselor de bază ori de câte ori este posibil.

Ierarhia rezultată trebuie să fie:

```text
InstrumentMuzical
       |
       v
    Chitara
       |
       v
 ChitaraElectrica
```

**Exemplu orientativ de utilizare:**

```cpp
ChitaraElectrica e1;
ChitaraElectrica e2(e1);

ChitaraElectrica e3;
e3 = e2;

cout << e3 << endl;
```

**Întrebări:**

- În ce ordine sunt apelați cei trei constructori?
- În ce ordine sunt apelați destructorii?
- Ce constructor trebuie apelat din constructorul de copiere al clasei `ChitaraElectrica`?
- De ce nu este necesar ca noua clasă să copieze manual atributele `denumire` și `tipCorzi`?

> [!IMPORTANT]
> Fiecare clasă trebuie să gestioneze memoria pe care o deține. Folosiți constructorii și operatorii claselor de bază pentru a evita duplicarea codului.

---

#### Exercițiul 11 – Analiza construirii și distrugerii obiectelor

Folosind ierarhia cu trei niveluri de la exercițiul anterior, adăugați temporar mesaje de diagnostic în constructorii și destructorii tuturor claselor.

De exemplu, în constructorul fără parametri al unei clase puteți afișa:

```cpp
cout << "Constructor InstrumentMuzical\n";
```

Pentru destructor, folosiți un mesaj corespunzător.

**Cerințe:**

1. Declarați în `main()` un obiect de tip `InstrumentMuzical`.
2. Declarați un obiect de tip `Chitara`.
3. Declarați un obiect de tip `ChitaraElectrica`.
4. Construiți prin copiere un al doilea obiect de tip `ChitaraElectrica`.
5. Creați un bloc local în care construiți încă un obiect de tip `ChitaraElectrica`.
6. Observați ce destructori sunt apelați la ieșirea din blocul local.
7. Urmăriți ordinea destructorilor la terminarea funcției `main()`.

**Exemplu orientativ:**

```cpp
int main()
{
    InstrumentMuzical i1;

    Chitara c1;

    ChitaraElectrica e1;
    ChitaraElectrica e2(e1);

    {
        ChitaraElectrica e3;
    }

    cout << "Final main\n";

    return 0;
}
```

**Întrebări:**

- De ce constructorul clasei `InstrumentMuzical` este apelat și la construirea unui obiect `ChitaraElectrica`?
- Ce se întâmplă dacă nu apelăm explicit constructorul clasei de bază în lista de inițializare?
- De ce destructorii se execută în ordinea inversă constructorilor?
- Care este diferența dintre apelarea unui constructor și apelarea operatorului de asignare?
- Ce se întâmplă cu memoria alocată dinamic pentru fiecare clasă atunci când obiectul este distrus?

> [!TIP]
> Desenați pe hârtie ordinea apelurilor înainte de a rula programul. Comparați apoi rezultatul estimat cu mesajele afișate în consolă.

---

### 5. Verificarea exercițiilor în `main()`

Pentru fiecare funcționalitate implementată:

1. Construiți obiecte folosind constructorii disponibili.
2. Verificați constructorul de copiere și operatorul de asignare.
3. Afișați obiectele pentru a observa valorile atributelor.
4. Testați și situațiile în care pointerii sunt `nullptr`.
5. Verificați dacă obiectele copiate își gestionează independent memoria.
6. Testați autoasignarea (`obiect = obiect`).
7. Observați ordinea apelării constructorilor și destructorilor.
8. Verificați diferența dintre utilizarea unei referințe către clasa de bază și construirea unui obiect separat de tipul clasei de bază.

> [!IMPORTANT]
> Nu este necesar să citiți datele de la tastatură. Puteți inițializa valorile direct în `main()`, folosind exemplele oferite.
>
> Important este să înțelegeți **cum funcționează relația de moștenire** și cum sunt reutilizate funcționalitățile claselor de bază.

---

### 6. Observații finale

- Toate exercițiile pot fi rezolvate într-un **singur fișier `.cpp`**.
- Exercițiile **1–8** urmăresc construirea și utilizarea unei ierarhii simple de clase.
- Exercițiul **9** urmărește verificarea copierii profunde și a independenței obiectelor.
- Exercițiul **10** introduce o ierarhie de moștenire pe trei niveluri.
- Exercițiul **11** urmărește ordinea apelării constructorilor și destructorilor.
- Folosiți `new[]` și `delete[]` pentru gestionarea șirurilor de caractere.
- Evitați copierea superficială a pointerilor care dețin memorie alocată dinamic.
- Implementați funcționalitățile reutilizabile în clasele de bază, fără duplicarea inutilă a codului.
- Nu este necesară utilizarea metodelor virtuale sau a polimorfismului dinamic.
- Exercițiile sunt **suplimentare, opționale și fără punctaj**.

> [!TIP]
> Încercați să rezolvați exercițiile în ordinea prezentată, deoarece fiecare cerință dezvoltă funcționalitățile implementate anterior.
>
> Acordați o atenție deosebită constructorilor de copiere, operatorilor de asignare și destructorilor. Într-o ierarhie de clase, gestionarea incorectă a memoriei într-o singură clasă poate afecta comportamentul întregului obiect.
>
> **Obiectivul principal este să înțelegeți cum poate o clasă derivată să extindă funcționalitățile unei clase de bază, fără să le implementeze din nou.**
