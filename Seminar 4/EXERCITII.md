# Exerciții suplimentare – Particularitățile clasei în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 4 · Particularitățile clasei
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Aceste exerciții sunt destinate aprofundării noțiunilor prezentate la seminar, folosind o clasă care conține atât atribute obișnuite, cât și un vector alocat dinamic, un atribut constant și unul static.

Prin rezolvarea lor veți exersa:

- implementarea constructorilor și a destructorului;
- utilizarea constructorului de copiere și a operatorului de asignare;
- alocarea și eliberarea memoriei folosind `new[]` și `delete[]`;
- realizarea unei copii profunde (*deep copy*) pentru un vector alocat dinamic;
- inițializarea atributelor constante și utilizarea atributelor statice;
- implementarea getterilor și setterilor;
- definirea unei metode pentru afișarea atributelor unui obiect.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile discutate la seminar.

---

### 2. Organizarea programului

Toate cerințele vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru rezolvare:

1. Definiți clasa `Sifonier` folosind structura prezentată mai jos.
2. Declarați și implementați constructorii, operatorul de asignare și destructorul.
3. Implementați metodele de tip get/set.
4. Implementați metoda de afișare a atributelor.
5. Testați toate funcționalitățile clasei în `main()`.

---

### 3. Definirea clasei `Sifonier`

Porniți de la următoarea clasă, păstrând **numele și tipurile atributelor**:

```cpp
class Sifonier
{
    float pret;
    double greutate;

    int numarRafturi;
    double* volumeRafturi;

    string culoare;
    string producator;

    const int ID;
    static int contor;
};
```

Atributele clasei reprezintă:

- **`pret`** (`float`) – prețul șifonierului, exprimat în lei;
- **`greutate`** (`double`) – greutatea șifonierului, exprimată în kilograme;
- **`numarRafturi`** (`int`) – numărul de rafturi ale șifonierului;
- **`volumeRafturi`** (`double*`) – vector alocat dinamic, care memorează volumul fiecărui raft, exprimat în litri;
- **`culoare`** (`string`) – culoarea șifonierului;
- **`producator`** (`string`) – numele producătorului;
- **`ID`** (`const int`) – identificatorul unic al fiecărui obiect;
- **`contor`** (`static int`) – atribut comun tuturor obiectelor, folosit pentru atribuirea identificatorilor.

> [!IMPORTANT]
> Toate atributele trebuie să rămână în zona **`private`**. Adăugați zona `public` pentru constructori, destructor și celelalte metode cerute.

---

### 4. Valorile implicite și identificatorul unic

Pentru constructorul fără parametri, utilizați următoarele valori:

| Atribut | Valoare implicită |
|---|---|
| `pret` | `0.0f` |
| `greutate` | `0.0` |
| `numarRafturi` | `0` |
| `volumeRafturi` | `nullptr` |
| `culoare` | `"N/A"` |
| `producator` | `"N/A"` |

Atributul static **`contor`** va fi inițializat cu valoarea `1`, în afara clasei.

La construirea fiecărui obiect:

- atributul `ID` va primi valoarea curentă a contorului;
- contorul va fi incrementat pentru următorul obiect;
- fiecare obiect nou creat va primi propriul identificator.

> [!IMPORTANT]
> Atributul `ID` este constant și trebuie inițializat folosind **lista de inițializare a constructorului**. Acesta nu poate fi modificat ulterior prin asignare.

> [!NOTE]
> Contorul este comun tuturor obiectelor de tip `Sifonier`. Acesta nu trebuie declarat din nou pentru fiecare obiect și nici decrementat atunci când un obiect este distrus.

---

### 5. Implementarea constructorilor

#### Exercițiul 1 – Constructorul fără parametri

Implementați constructorul fără parametri pentru clasa `Sifonier`.

Constructorul trebuie:

- să inițializeze atributele folosind valorile implicite din secțiunea anterioară;
- să inițializeze pointerul `volumeRafturi` cu `nullptr`;
- să atribuie obiectului un `ID` unic folosind contorul static.

> [!NOTE]
> Deoarece `numarRafturi` este inițializat cu `0`, nu este necesară alocarea dinamică a vectorului în acest constructor.

---

#### Exercițiul 2 – Constructorul cu toți parametrii

Implementați un constructor care primește valori pentru toate atributele obișnuite ale clasei:

- `pret`;
- `greutate`;
- `numarRafturi`;
- `volumeRafturi`;
- `culoare`;
- `producator`.

Atributele `ID` și `contor` nu vor fi primite ca parametri.

**Precizări:**

- Inițializați atributele folosind valorile primite.
- Pentru parametrii de tip `string`, `float`, `double` și `int`, folosiți transmiterea prin valoare.
- Vectorul `volumeRafturi` va fi primit prin pointer.
- Alocați dinamic memoria necesară pentru volumele rafturilor și copiați fiecare element din vectorul primit.
- Dacă numărul de rafturi este `0`, pointerul va rămâne `nullptr`.
- Atribuiți obiectului un identificator unic folosind contorul static.

> [!IMPORTANT]
> Pentru `volumeRafturi` trebuie realizată o **copie profundă (deep copy)**. Nu este suficient să copiați adresa vectorului primit ca parametru, deoarece cele două zone de memorie trebuie să fie independente.

---

#### Exercițiul 3 – Constructorul de copiere

Implementați constructorul de copiere pentru clasa `Sifonier`.

Acesta trebuie să permită crearea unui obiect nou, pornind de la un obiect deja existent.

Constructorul trebuie:

1. Să copieze valorile atributelor `pret`, `greutate`, `numarRafturi`, `culoare` și `producator`.
2. Să aloce separat memoria necesară pentru `volumeRafturi`.
3. Să copieze toate volumele rafturilor din obiectul sursă.
4. Să atribuie noului obiect un `ID` unic.

Dacă obiectul sursă nu conține rafturi, nu este necesară alocarea dinamică a memoriei.

> [!IMPORTANT]
> Constructorul de copiere nu trebuie să copieze identificatorul obiectului sursă. **Fiecare obiect nou construit va primi propriul `ID`**, inclusiv atunci când este creat prin copiere.

> [!NOTE]
> Folosiți transmiterea prin referință constantă pentru obiectul sursă. Acesta trebuie doar citit, fără să fie modificat în timpul copierii.

---

### 6. Operatorul de asignare

#### Exercițiul 4 – Supraîncărcarea operatorului `=`

Supraîncărcați operatorul de asignare pentru clasa `Sifonier`, astfel încât un obiect existent să poată primi datele altui obiect de același tip.

Operatorul trebuie:

1. Să verifice dacă obiectul nu este asignat lui însuși.
2. Să copieze valorile atributelor `pret`, `greutate`, `numarRafturi`, `culoare` și `producator`.
3. Să elibereze memoria alocată anterior pentru `volumeRafturi`.
4. Să aloce memoria necesară pentru noul vector și să copieze elementele acestuia.
5. Să trateze și cazul în care obiectul sursă nu conține rafturi.
6. Să păstreze identificatorul obiectului destinație.
7. Să returneze o referință la obiectul curent.

**Exemplu de utilizare:**

```cpp
Sifonier s1;
Sifonier s2;

// ...

s1 = s2;
```

După asignare, `s1` va conține aceleași date obișnuite ca `s2`, dar își va păstra identificatorul inițial.

> [!IMPORTANT]
> Spre deosebire de constructorul de copiere, operatorul de asignare **nu creează un obiect nou**. Prin urmare, acesta nu trebuie să modifice atributul `ID` și nici să incrementeze contorul static.

> [!NOTE]
> Aveți grijă la autoasignare, de exemplu `s1 = s1`. Verificați această situație înainte de a elibera memoria, astfel încât datele obiectului să nu fie pierdute.

---

### 7. Destructorul

#### Exercițiul 5 – Implementarea destructorului

Implementați destructorul clasei `Sifonier`.

Acesta trebuie să elibereze memoria alocată dinamic pentru vectorul `volumeRafturi`.

**Precizări:**

- Utilizați operatorul `delete[]` pentru eliberarea memoriei.
- Nu este necesară eliberarea manuală a memoriei pentru atributele de tip `string`.
- Destructorul nu trebuie să modifice atributul static `contor`.

> [!IMPORTANT]
> Memoria alocată pentru vector trebuie eliberată atunci când obiectul este distrus. **Nu decrementați contorul**, deoarece identificatorii obiectelor create ulterior nu trebuie reutilizați.

---

### 8. Implementarea getterilor și setterilor

#### Exercițiul 6 – Metode de tip get/set

Implementați metode publice de tip **getter** și **setter** pentru atributele clasei `Sifonier`.

Pentru atributele obișnuite, folosiți următoarele denumiri:

| Atribut | Getter | Setter |
|---|---|---|
| `pret` | `getPret()` | `setPret()` |
| `greutate` | `getGreutate()` | `setGreutate()` |
| `culoare` | `getCuloare()` | `setCuloare()` |
| `producator` | `getProducator()` | `setProducator()` |

Getterii trebuie să returneze valorile atributelor fără să modifice obiectul.

Setterii vor primi noile valori ca parametri și vor actualiza atributele corespunzătoare.

Pentru `pret` și `greutate`, acceptați doar valori mai mari sau egale cu `0`.

Pentru `culoare` și `producator`, dacă șirul primit este gol, atributul va primi valoarea `"N/A"`.

---

#### Setterul pentru `numarRafturi` și `volumeRafturi`

Pentru aceste două atribute, implementați **un singur setter**, numit `setVolumeRafturi()`.

Setterul va primi:

- un vector care conține volumele rafturilor;
- numărul de elemente ale vectorului.

Acesta trebuie:

1. Să verifice dacă numărul de rafturi este valid și dacă vectorul primit poate fi utilizat.
2. Să elibereze memoria alocată anterior pentru `volumeRafturi`.
3. Să actualizeze atributul `numarRafturi`.
4. Să aloce dinamic memoria pentru noul vector.
5. Să copieze elementele primite în memoria nou alocată.

Dacă numărul de rafturi este mai mic egal cu 0 sau pointerul primit este `nullptr`, setterul nu va modifica obiectul.

> [!IMPORTANT]
> **Nu implementați un setter separat pentru `numarRafturi`.** Numărul de rafturi și vectorul `volumeRafturi` trebuie actualizate împreună, pentru a evita situațiile în care dimensiunea memorată nu mai corespunde memoriei alocate.

**Exemplu:**

Un șifonier are inițial 3 rafturi, cu volumele:

```text
Raft 1: 80 litri
Raft 2: 100 litri
Raft 3: 120 litri
```

După apelarea setterului cu un vector care conține două volume noi:

```text
Raft 1: 150 litri
Raft 2: 200 litri
```

Obiectul trebuie să aibă `numarRafturi = 2`, iar vechea zonă de memorie să fie eliberată.

---

#### Getterii pentru vector și dimensiune

Implementați și următorii getteri:

- **`getNumarRafturi()`** – returnează numărul de rafturi;
- **`getVolumeRafturi()`** – returnează un pointer constant către elementele vectorului.

Getterul pentru volume trebuie să permită citirea elementelor, fără modificarea acestora prin pointerul returnat.

---

#### Getterii pentru `ID` și `contor`

Implementați următoarele metode:

- **`getID()`** – returnează identificatorul obiectului curent;
- **`getContor()`** – funcție statică ce returnează valoarea curentă a contorului.

> [!IMPORTANT]
> Nu implementați setteri pentru `ID` și `contor`. Identificatorul este constant, iar contorul trebuie gestionat exclusiv prin construirea obiectelor.

---

### 9. Metoda de afișare

#### Exercițiul 7 – Implementarea metodei `afisare()`

Implementați o metodă publică numită **`afisare()`**, care afișează toate atributele unui obiect de tip `Sifonier`.

Metoda nu va primi parametri și nu trebuie să modifice obiectul.

Afișați identificatorul, prețul, greutatea, numărul de rafturi, volumele acestora, culoarea și producătorul.

**Exemplu de afișare:**

Pentru un șifonier cu identificatorul `1`, prețul `1800`, greutatea `95`, trei rafturi cu volumele `80`, `100` și `120`, culoarea `Alb` și producătorul `IKEA`, afișarea va fi:

```text
ID sifonier: 1
Pret: 1800 lei
Greutate: 95 kg
Numar rafturi: 3
Volume rafturi:
Raft 1: 80 litri
Raft 2: 100 litri
Raft 3: 120 litri
Culoare: Alb
Producator: IKEA
```

Dacă șifonierul nu are rafturi, afișarea va conține:

```text
Numar rafturi: 0
Volume rafturi: N/A
```

**Precizări:**

- Respectați ordinea informațiilor din exemplu.
- Pentru volumele rafturilor, utilizați o instrucțiune repetitivă.
- Fiecare raft va fi afișat pe o linie separată.
- Dacă vectorul nu conține elemente, afișați `N/A`.
- După fiecare informație, treceți la linia următoare.

> [!NOTE]
> Volumele rafturilor vor fi afișate în **litri**, conform exemplului. Nu este necesară afișarea acestora în metri cubi.

---

### 10. Testarea clasei în `main()`

În funcția `main()`, testați toate funcționalitățile implementate pentru clasa `Sifonier`.

Parcurgeți următorii pași:

1. Creați un obiect folosind constructorul fără parametri și afișați-l.
2. Declarați un vector de tip `double`, care să conțină volumele a cel puțin 3 rafturi.
3. Creați un obiect folosind constructorul cu toți parametrii și vectorul de volume declarat anterior.
4. Creați un al treilea obiect folosind constructorul de copiere.
5. Afișați obiectele și verificați dacă identificatorii sunt diferiți.
6. Modificați volumele rafturilor pentru unul dintre obiecte, folosind `setVolumeRafturi()`.
7. Verificați dacă modificarea nu a afectat vectorul celuilalt obiect.
8. Testați operatorul de asignare între două obiecte deja existente.
9. Verificați dacă obiectul destinație și-a păstrat identificatorul după asignare.
10. Testați și autoasignarea unui obiect.
11. Apelați getterii pentru a verifica valorile atributelor.
12. Folosiți setterii pentru a modifica prețul, greutatea, culoarea și producătorul.
13. Afișați din nou obiectele după modificări.
14. Afișați valoarea contorului static folosind `getContor()`.

**Pentru testarea constructorului de copiere:**

```cpp
Sifonier s2(s1);
```

**Pentru testarea operatorului de asignare:**

```cpp
s1 = s2;
```

**Pentru testarea autoasignării:**

```cpp
s1 = s1;
```

> [!IMPORTANT]
> După copiere sau asignare, vectorii obiectelor trebuie să fie independenți. Modificarea volumelor rafturilor unui obiect nu trebuie să afecteze volumele celuilalt obiect.

> [!NOTE]
> Pentru a verifica eliberarea memoriei, puteți crea și un obiect alocat dinamic folosind `new`, pe care să îl distrugeți ulterior folosind `delete`. Verificați că destructorul este apelat și că nu apar erori la eliberarea memoriei.

---

### 11. Recomandări pentru rezolvare

Înainte de a considera exercițiile terminate, verificați dacă toate operațiile de copiere și modificare a obiectelor funcționează corect.

Câteva recomandări:

1. Inițializați toate atributele în constructori, inclusiv pointerul și atributul constant.
2. Folosiți `new[]` pentru alocarea vectorului și `delete[]` pentru eliberarea memoriei.
3. Nu copiați doar adresa vectorului atunci când construiți sau asignați obiecte.
4. Verificați autoasignarea înainte de a modifica datele obiectului.
5. Transmiteți parametrii simpli prin valoare, iar obiectele folosite doar pentru copiere prin referință constantă.
6. Păstrați identificatorul obiectului destinație atunci când utilizați operatorul de asignare.
7. Nu modificați contorul static în destructor sau în operatorul de asignare.
8. Testați și obiectele care au `numarRafturi = 0` și `volumeRafturi = nullptr`.
9. Aveți grijă să nu accesați memoria după ce aceasta a fost eliberată.

> [!WARNING]
> Nu utilizați `std::vector` sau alte containere STL pentru memorarea volumelor rafturilor. Vectorul trebuie gestionat manual, folosind alocarea dinamică.

> [!NOTE]
> Pentru aceste exerciții nu sunt necesare fișiere suplimentare. Toate implementările pot fi realizate în același fișier `.cpp`, alături de funcția `main()`.

---

### 12. Observații finale

Aceste exerciții vă ajută să înțelegeți cum trebuie gestionată memoria atunci când o clasă conține atribute alocate dinamic.

Acordați atenție constructorului de copiere, operatorului de asignare și destructorului, deoarece acestea trebuie să gestioneze corect memoria asociată obiectelor.

Nu uitați că **fiecare obiect nou creat primește un identificator unic**, iar asignarea modifică datele unui obiect existent fără să îi schimbe identificatorul.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
