# Exerciții suplimentare – Supraîncărcarea operatorilor în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 5 · Supraîncărcarea operatorilor
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Aceste exerciții sunt destinate aprofundării noțiunilor prezentate la seminar, în special a modului în care putem supraîncărca operatorii în C++ pentru a lucra cu obiecte ale unei clase.

Vom folosi clasa `Fractie`, pentru care veți implementa mai mulți operatori aritmetici, relaționali, unari și de conversie.

Prin rezolvarea exercițiilor veți exersa:

- implementarea constructorilor, getterilor și setterilor;
- supraîncărcarea operatorilor ca metode ale clasei;
- diferența dintre formele prefixată și postfixată ale operatorilor `++` și `--`;
- supraîncărcarea operatorilor aritmetici și de asignare compusă;
- supraîncărcarea operatorilor folosind funcții `friend`;
- transmiterea obiectelor prin referință constantă;
- returnarea obiectelor prin valoare sau prin referință;
- utilizarea operatorilor de comparație;
- supraîncărcarea operatorului de conversie explicită;
- supraîncărcarea operatorului de afișare `<<`.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile discutate la seminar.

---

### 2. Organizarea programului

Toate cerințele vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru rezolvare:

1. Copiați clasa `Fractie` prezentată mai jos.
2. Implementați constructorii, getterii și setterii.
3. Implementați fiecare operator, respectând semnăturile indicate.
4. Testați operatorii în `main()`, folosind obiecte de tip `Fractie`.
5. Afișați rezultatele pentru a verifica dacă operațiile au fost efectuate corect.

> [!IMPORTANT]
> Toate metodele și funcțiile `friend` sunt deja declarate în clasă. Pentru implementarea lor, **eliminați caracterul `;` de la sfârșitul declarației și adăugați corpul funcției între acolade `{}`**.

---

### 3. Definirea clasei `Fractie`

Porniți de la următoarea clasă, păstrând **numele, tipurile atributelor și semnăturile tuturor funcțiilor și metodelor**:

```cpp
class Fractie
{
    double numitor;
    double numarator;

public:

    Fractie();

    Fractie(const double numarator, const double numitor);

    double getNumitor() const;

    double getNumarator() const;

    void setNumitor(const double numitor);

    void setNumarator(const double numarator);

    Fractie& operator++();

    Fractie& operator--();

    Fractie operator++(int);

    Fractie operator--(int);

    Fractie operator!() const;

    Fractie operator-() const;

    Fractie& operator+=(const Fractie& f);

    Fractie& operator-=(const Fractie& f);

    Fractie& operator*=(const Fractie& f);

    Fractie& operator/=(const Fractie& f);

    Fractie& operator+=(const double numar);

    Fractie& operator-=(const double numar);

    Fractie& operator*=(const double numar);

    Fractie& operator/=(const double numar);

    bool operator==(const Fractie& f) const;

    bool operator!=(const Fractie& f) const;

    explicit operator double() const;

    friend Fractie operator+(const Fractie& f1, const Fractie& f2);

    friend Fractie operator+(const Fractie& f, const double numar);

    friend Fractie operator+(const double numar, const Fractie& f);

    friend Fractie operator-(const Fractie& f1, const Fractie& f2);

    friend Fractie operator-(const Fractie& f, const double numar);

    friend Fractie operator-(const double numar, const Fractie& f);

    friend Fractie operator*(const Fractie& f1, const Fractie& f2);

    friend Fractie operator*(const Fractie& f, const double numar);

    friend Fractie operator*(const double numar, const Fractie& f);

    friend Fractie operator/(const Fractie& f1, const Fractie& f2);

    friend Fractie operator/(const Fractie& f, const double numar);

    friend Fractie operator/(const double numar, const Fractie& f);

    friend ostream& operator<<(ostream& out, const Fractie& f);
};
```

Atributele clasei reprezintă:

- **`numarator`** (`double`) – numărătorul fracției;
- **`numitor`** (`double`) – numitorul fracției.

> [!IMPORTANT]
> Atributele trebuie să rămână în zona **`private`**. Nu modificați semnăturile constructorilor, metodelor sau funcțiilor `friend`.

Pentru a păstra exercițiile cât mai simple, vom considera că numitorii fracțiilor sunt diferiți de `0`.

De asemenea, **nu este necesară simplificarea fracțiilor**. Rezultatele pot rămâne în forma obținută după efectuarea operațiilor, chiar dacă fracția nu este ireductibilă.

---

### 4. Constructorii, getterii și setterii

#### Exercițiul 1 – Implementarea constructorilor

Implementați cei doi constructori ai clasei `Fractie`.

**Constructorul fără parametri**

Acesta va inițializa:

- `numarator` cu `0.0`;
- `numitor` cu `1.0`.

**Constructorul cu doi parametri**

Acesta va inițializa numărătorul și numitorul folosind valorile primite ca parametri.

**Exemplu:**

```cpp
Fractie f1;
Fractie f2(3, 4);
```

Obiectul `f1` va reprezenta fracția `0/1`, iar obiectul `f2` va reprezenta fracția `3/4`.

---

#### Exercițiul 2 – Implementarea getterilor și setterilor

Implementați următoarele metode:

- **`getNumitor()`** – returnează numitorul fracției;
- **`getNumarator()`** – returnează numărătorul fracției;
- **`setNumitor()`** – modifică numitorul folosind valoarea primită;
- **`setNumarator()`** – modifică numărătorul folosind valoarea primită.

Getterii nu trebuie să modifice obiectul curent, motiv pentru care sunt declarați cu `const`.

> [!NOTE]
> Pentru aceste exerciții considerăm că valorile transmise către `setNumitor()` sunt diferite de `0`. Nu este necesară implementarea unor verificări suplimentare.

---

### 5. Operatorii de incrementare și decrementare

#### Exercițiul 3 – Operatorii `++` și `--`

Implementați formele prefixată și postfixată ale operatorilor de incrementare și decrementare.

Pentru o fracție, incrementarea cu `1` înseamnă adunarea numitorului la numărător.

De exemplu:

$$
\frac{3}{4}+1=\frac{3+4}{4}=\frac{7}{4}
$$

În mod asemănător, decrementarea cu `1` presupune scăderea numitorului din numărător.

**Operatorii prefixați**

Implementați `operator++()` și `operator--()` astfel încât să modifice obiectul curent și să returneze o referință la acesta.

**Exemplu:**

```cpp
Fractie f(3, 4);

++f;
--f;
```

După incrementare, fracția va deveni `7/4`, iar după decrementare va reveni la `3/4`.

**Operatorii postfixați**

Implementați `operator++(int)` și `operator--(int)`.

Aceștia trebuie să modifice obiectul curent, dar să returneze **valoarea pe care obiectul o avea înainte de modificare**.

**Exemplu:**

```cpp
Fractie f(3, 4);

Fractie rezultat = f++;
```

După executarea instrucțiunii:

- `f` va reprezenta fracția `7/4`;
- `rezultat` va reprezenta fracția `3/4`.

> [!IMPORTANT]
> Fiți atenți la diferența dintre cele două forme. Operatorul prefixat returnează o referință la obiectul modificat, în timp ce operatorul postfixat returnează o copie a valorii anterioare.

> [!NOTE]
> Parametrul `int` din forma postfixată este folosit pentru a diferenția cele două forme ale operatorului. Nu trebuie să utilizați valoarea acestuia în implementare.

---

### 6. Operatorii unari

#### Exercițiul 4 – Operatorul `!`

Supraîncărcați operatorul **`!`** astfel încât să returneze inversa fracției curente.

Inversarea unei fracții presupune interschimbarea numărătorului cu numitorul.

$$
\frac{a}{b}\rightarrow\frac{b}{a}
$$

**Exemplu:**

```cpp
Fractie f(3, 4);

Fractie rezultat = !f;
```

Rezultatul va fi fracția `4/3`, iar obiectul `f` va rămâne nemodificat.

> [!NOTE]
> Pentru această cerință, operatorul `!` nu realizează negarea logică, ci inversarea fracției. Considerăm că operatorul va fi aplicat doar fracțiilor cu numărător diferit de `0`.

---

#### Exercițiul 5 – Operatorul unar `-`

Implementați operatorul **`-`** astfel încât să returneze opusul fracției curente.

Opusul unei fracții se obține prin schimbarea semnului numărătorului.

$$
-\left(\frac{a}{b}\right)=\frac{-a}{b}
$$

**Exemplu:**

```cpp
Fractie f(3, 4);

Fractie rezultat = -f;
```

Rezultatul va fi fracția `-3/4`, fără modificarea obiectului `f`.

> [!IMPORTANT]
> Atât `operator!()`, cât și `operator-()` trebuie să returneze un nou obiect de tip `Fractie`. Nu modificați obiectul asupra căruia sunt aplicați.

---

### 7. Operatorii de asignare compusă

#### Exercițiul 6 – Operații între două fracții

Implementați următorii operatori:

- **`operator+=`** – adună o fracție la obiectul curent;
- **`operator-=`** – scade o fracție din obiectul curent;
- **`operator*=`** – înmulțește obiectul curent cu o fracție;
- **`operator/=`** – împarte obiectul curent la o fracție.

Pentru două fracții:

$$
f_1=\frac{a}{b},\quad f_2=\frac{c}{d}
$$

Utilizați următoarele formule:

**Adunare**

$$
\frac{a}{b}+\frac{c}{d}=\frac{ad+bc}{bd}
$$

**Scădere**

$$
\frac{a}{b}-\frac{c}{d}=\frac{ad-bc}{bd}
$$

**Înmulțire**

$$
\frac{a}{b}\cdot\frac{c}{d}=\frac{ac}{bd}
$$

**Împărțire**

$$
\frac{a}{b}:\frac{c}{d}=\frac{ad}{bc}
$$

**Exemplu:**

```cpp
Fractie f1(3, 4);
Fractie f2(1, 2);

f1 += f2;
```

După apel, `f1` va reprezenta fracția `10/8`.

**Precizări:**

- Operatorii trebuie să modifice obiectul curent.
- Fracția primită ca parametru nu trebuie modificată.
- Returnați o referință la obiectul curent.
- Nu este necesară simplificarea rezultatului.

> [!NOTE]
> Folosiți variabile auxiliare acolo unde este necesar, astfel încât modificarea unui atribut să nu afecteze calculul celuilalt.

---

#### Exercițiul 7 – Operații între o fracție și un număr real

Implementați și variantele operatorilor `+=`, `-=`, `*=` și `/=` care primesc un număr de tip `double`.

Pentru o fracție:

$$
f=\frac{a}{b}
$$

și un număr real `x`, operațiile se realizează astfel:

**Adunare**

$$
\frac{a}{b}+x=\frac{a+bx}{b}
$$

**Scădere**

$$
\frac{a}{b}-x=\frac{a-bx}{b}
$$

**Înmulțire**

$$
\frac{a}{b}\cdot x=\frac{ax}{b}
$$

**Împărțire**

$$
\frac{a}{b}:x=\frac{a}{bx}
$$

**Exemplu:**

```cpp
Fractie f(3, 4);

f += 2.0;
```

După apel, fracția va deveni `11/4`.

> [!IMPORTANT]
> Operatorii de asignare compusă trebuie să modifice obiectul asupra căruia sunt apelați și să returneze o referință la acesta.

---

### 8. Operatorii de comparație

#### Exercițiul 8 – Operatorii `==` și `!=`

Supraîncărcați operatorii de egalitate și inegalitate pentru două obiecte de tip `Fractie`.

**Operatorul `==`**

Trebuie să returneze `true` dacă cele două fracții au aceeași valoare matematică și `false` în caz contrar.

**Exemplu:**

```cpp
Fractie f1(1, 2);
Fractie f2(2, 4);

bool rezultat = (f1 == f2);
```

Rezultatul trebuie să fie `true`, deoarece cele două fracții sunt echivalente.

> [!NOTE]
> Nu este suficient să comparați separat numărătorii și numitorii. Puteți verifica egalitatea folosind înmulțirea în cruce.

**Operatorul `!=`**

Trebuie să returneze `true` dacă fracțiile au valori diferite și `false` dacă sunt egale.

**Exemplu:**

```cpp
Fractie f1(1, 2);
Fractie f2(3, 4);

bool rezultat = (f1 != f2);
```

Rezultatul trebuie să fie `true`.

> [!IMPORTANT]
> Ambii operatori trebuie să returneze o valoare de tip `bool` și să nu modifice obiectele comparate.

---

### 9. Operatorul de conversie explicită

#### Exercițiul 9 – Conversia unei fracții la `double`

Implementați operatorul de conversie explicită:

```cpp
explicit operator double() const;
```

Acesta trebuie să returneze rezultatul împărțirii numărătorului la numitor.

**Exemplu:**

```cpp
Fractie f(3, 4);

double rezultat = static_cast<double>(f);
```

Valoarea obținută va fi `0.75`.

Puteți utiliza și conversia în stil C:

```cpp
double rezultat = (double)f;
```

**Precizări:**

- Operatorul nu primește parametri.
- Nu modificați numărătorul sau numitorul.
- Returnați rezultatul împărțirii ca valoare de tip `double`.

> [!NOTE]
> Deoarece operatorul este declarat cu `explicit`, conversia nu se realizează automat în contexte care necesită o conversie implicită. Va trebui să solicitați conversia în mod explicit.

---

### 10. Operatorii aritmetici implementați prin funcții `friend`

#### Exercițiul 10 – Operații între două fracții

Implementați operatorii `+`, `-`, `*` și `/` declarați ca funcții `friend`, care primesc două obiecte de tip `Fractie`.

Aceștia trebuie să efectueze operațiile aritmetice folosind formulele prezentate în secțiunea 7.

**Exemplu:**

```cpp
Fractie f1(3, 4);
Fractie f2(1, 2);

Fractie suma = f1 + f2;
Fractie diferenta = f1 - f2;
Fractie produs = f1 * f2;
Fractie cat = f1 / f2;
```

**Rezultatele așteptate:**

```text
Suma: 10/8
Diferenta: 2/8
Produs: 3/8
Cat: 6/4
```

**Precizări:**

- Operatorii trebuie să returneze un nou obiect de tip `Fractie`.
- Nu modificați obiectele primite ca parametri.
- Folosiți formulele aritmetice corespunzătoare fiecărui operator.
- Nu este necesară simplificarea fracțiilor rezultate.

> [!IMPORTANT]
> Spre deosebire de operatorii de asignare compusă, operatorii aritmetici `+`, `-`, `*` și `/` **nu trebuie să modifice operanzii**.

---

#### Exercițiul 11 – Operații între o fracție și un număr real

Implementați variantele operatorilor `+`, `-`, `*` și `/` care permit efectuarea operațiilor între un obiect de tip `Fractie` și un număr de tip `double`.

Trebuie să funcționeze ambele ordini ale operanzilor:

- fracție urmată de număr real;
- număr real urmat de fracție.

**Exemplu:**

```cpp
Fractie f(3, 4);

Fractie r1 = f + 2.0;
Fractie r2 = 2.0 + f;

Fractie r3 = f - 2.0;
Fractie r4 = 2.0 - f;
```

**Rezultatele așteptate:**

```text
f + 2.0 = 11/4
2.0 + f = 11/4

f - 2.0 = -5/4
2.0 - f = 5/4
```

Implementați în același mod și cele două variante pentru înmulțire și împărțire.

**Exemplu:**

```cpp
Fractie f(3, 4);

Fractie r1 = f * 2.0;
Fractie r2 = 2.0 * f;

Fractie r3 = f / 2.0;
Fractie r4 = 2.0 / f;
```

**Rezultatele așteptate:**

```text
f * 2.0 = 6/4
2.0 * f = 6/4

f / 2.0 = 3/8
2.0 / f = 8/3
```

> [!NOTE]
> Fiți atenți la ordinea operanzilor pentru scădere și împărțire. Spre deosebire de adunare și înmulțire, aceste operații nu sunt comutative.

> [!IMPORTANT]
> Toate aceste variante trebuie să returneze un nou obiect de tip `Fractie`, fără să modifice obiectul primit ca parametru.

---

### 11. Operatorul de afișare

#### Exercițiul 12 – Supraîncărcarea operatorului `<<`

Implementați operatorul `<<` astfel încât obiectele de tip `Fractie` să poată fi afișate direct folosind `cout`.

**Exemplu:**

```cpp
Fractie f(3, 4);

cout << f;
```

**Rezultat:**

```text
3/4
```

**Precizări:**

- Afișați numărătorul, caracterul `/` și numitorul.
- Nu adăugați mesaje suplimentare sau treceri automate la linia următoare.
- Operatorul nu trebuie să modifice fracția primită.
- Returnați fluxul de ieșire primit ca parametru, pentru a permite afișările în lanț.

**Exemplu de afișare în lanț:**

```cpp
Fractie f1(3, 4);
Fractie f2(1, 2);

cout << "Prima fractie: " << f1 << '\n';
cout << "A doua fractie: " << f2 << '\n';
```

**Rezultat:**

```text
Prima fractie: 3/4
A doua fractie: 1/2
```

> [!NOTE]
> Operatorul `<<` este implementat ca funcție `friend`, deoarece operandul din stânga este fluxul de ieșire, nu un obiect de tip `Fractie`.

---

### 12. Testarea operatorilor în `main()`

În funcția `main()`, creați mai multe obiecte de tip `Fractie` și testați toate funcționalitățile implementate.

Parcurgeți următorii pași:

1. Creați un obiect folosind constructorul fără parametri și unul folosind constructorul cu doi parametri.
2. Testați getterii și setterii, apoi afișați valorile obținute.
3. Testați formele prefixată și postfixată ale operatorilor `++` și `--`.
4. Verificați diferența dintre valoarea returnată de forma postfixată și valoarea obiectului după incrementare sau decrementare.
5. Testați operatorii unari `!` și `-`.
6. Testați operatorii de asignare compusă între două fracții.
7. Testați operatorii de asignare compusă între o fracție și un număr de tip `double`.
8. Comparați două fracții folosind operatorii `==` și `!=`, inclusiv două fracții echivalente care au numărători și numitori diferiți.
9. Testați operatorul de conversie explicită la `double`.
10. Testați operațiile aritmetice dintre două fracții.
11. Testați operațiile aritmetice dintre o fracție și un număr real, în ambele ordini.
12. Afișați rezultatele folosind operatorul `<<`.

**Exemplu de testare:**

```cpp
Fractie f1(3, 4);
Fractie f2(1, 2);

cout << "f1 = " << f1 << '\n';
cout << "f2 = " << f2 << '\n';

cout << "Suma: " << f1 + f2 << '\n';
cout << "Diferenta: " << f1 - f2 << '\n';
cout << "Produs: " << f1 * f2 << '\n';
cout << "Cat: " << f1 / f2 << '\n';

cout << "Inversa lui f1: " << !f1 << '\n';
cout << "Opusul lui f1: " << -f1 << '\n';

cout << "Valoarea lui f1: " << static_cast<double>(f1) << '\n';
```

**Rezultatele așteptate:**

```text
f1 = 3/4
f2 = 1/2

Suma: 10/8
Diferenta: 2/8
Produs: 3/8
Cat: 6/4

Inversa lui f1: 4/3
Opusul lui f1: -3/4

Valoarea lui f1: 0.75
```

> [!IMPORTANT]
> Nu vă limitați doar la exemplele prezentate. Testați **toate variantele supraîncărcate ale operatorilor**, inclusiv cele în care numărul real se află în partea stângă a expresiei.

> [!NOTE]
> Pentru a verifica mai ușor operatorii de asignare compusă, puteți crea obiecte separate pentru fiecare operație. Astfel, rezultatul unei operații nu va influența testarea următoarei.

---

### 13. Recomandări pentru rezolvare

Înainte de a considera exercițiile terminate, verificați dacă fiecare operator respectă comportamentul cerut.

Câteva recomandări:

1. Respectați semnăturile metodelor și funcțiilor `friend` din clasă.
2. Fiți atenți la tipul returnat de fiecare operator: `Fractie`, `Fractie&`, `bool`, `double` sau `ostream&`.
3. Nu modificați obiectele primite prin referință constantă.
4. Pentru operatorii declarați cu `const`, nu modificați atributele obiectului curent.
5. Folosiți `return *this;` acolo unde operatorul trebuie să returneze o referință la obiectul curent.
6. Pentru operatorii postfixați, păstrați o copie a obiectului înainte de modificare.
7. Verificați ordinea operanzilor în cazul scăderii și împărțirii.
8. Reutilizați operatorii deja implementați acolo unde este posibil, pentru a evita repetarea aceleiași logici.
9. Testați operatorii folosind și fracții cu numărători negativi.
10. Nu simplificați fracțiile rezultate, deoarece acest lucru nu este cerut.

> [!IMPORTANT]
> Considerăm că toate operațiile sunt valide din punct de vedere matematic: numitorii sunt diferiți de `0`, nu împărțim la o fracție cu numărătorul `0` și nu împărțim la un număr real egal cu `0`. Nu este necesar să implementați verificări pentru aceste situații.

> [!NOTE]
> Nu este necesară alocarea dinamică a memoriei pentru aceste exerciții. Folosiți obiecte declarate direct în `main()` și membrii clasei prezentați în cerință.

---

### 14. Observații finale

Aceste exerciții vă ajută să înțelegeți cum putem folosi operatorii obișnuiți din C++ pentru a lucra cu obiecte ale unei clase.

Acordați atenție diferențelor dintre operatorii care modifică obiectul curent și cei care returnează un obiect nou. De asemenea, urmăriți modul în care tipul returnat și parametrii influențează comportamentul fiecărui operator.

Încercați să implementați operatorii într-o ordine firească, începând cu cei mai simpli și continuând cu cei care pot reutiliza funcționalitățile deja implementate.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
