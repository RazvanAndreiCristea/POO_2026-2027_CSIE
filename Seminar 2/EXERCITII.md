# Exerciții suplimentare – Numere complexe în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 2 · Structuri, funcții și alocare dinamică
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Aceste exerciții sunt destinate aprofundării noțiunilor discutate la seminar, folosind o structură pentru reprezentarea numerelor complexe.

Prin rezolvarea lor veți exersa:

- definirea și utilizarea structurilor în C++;
- declararea, definirea și apelarea funcțiilor;
- transmiterea parametrilor prin valoare, pointeri și referințe;
- utilizarea parametrilor constanți acolo unde este cazul;
- returnarea structurilor din funcții;
- alocarea și eliberarea memoriei folosind operatorii `new[]` și `delete[]`;
- parcurgerea unui vector alocat dinamic.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile prezentate la seminar.

---

### 2. Organizarea programului

Toate exercițiile vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru fiecare exercițiu:

1. Stabiliți semnătura funcției, ținând cont de cerință și de indicațiile oferite.
2. Implementați funcția respectivă.
3. Apelați funcția în `main()`, folosind valori alese de voi.
4. Afișați rezultatele în consolă pentru a verifica dacă sunt corecte.

> [!IMPORTANT]
> **Numele funcțiilor trebuie respectate**, însă semnăturile acestora vor fi stabilite de voi. Alegeți tipurile parametrilor, modalitatea de transmitere și tipul returnat în funcție de ceea ce trebuie să realizeze fiecare funcție.

---

### 3. Definirea structurii `NrComplex`

Pentru reprezentarea unui număr complex, utilizați următoarea structură:

```cpp
struct NrComplex
{
    double real;
    double imaginar;
};
```

Un număr complex are forma:

$$
z = a + bi
$$

unde:

- `a` reprezintă partea reală;
- `b` reprezintă partea imaginară;
- `i` este unitatea imaginară, pentru care $i^2 = -1$.

De exemplu, numărul complex $3 + 2i$ va avea:

```text
real = 3
imaginar = 2
```

> [!IMPORTANT]
> Păstrați structura `NrComplex` exact în forma prezentată. Nu este necesară utilizarea claselor sau a altor tipuri de date pentru reprezentarea numerelor complexe.

---

### 4. Operații cu numere complexe

#### Exercițiul 1 – Inițializarea unui număr complex

Scrieți o funcție numită **`initializareNrComplex()`**, care primește partea reală și partea imaginară a unui număr complex.

Funcția va crea un număr complex folosind cele două valori primite și îl va returna.

**Exemplu:**

```text
Partea reala: 4
Partea imaginara: 2

Numar complex: 4 + 2i
```

> [!NOTE]
> Gândiți-vă ce tip de date trebuie să primească funcția și ce tip trebuie să returneze. Valorile primite nu trebuie modificate.

---

#### Exercițiul 2 – Adunarea numerelor complexe

Implementați funcția **`adunareNrComplexe()`**, care primește două numere complexe și returnează suma acestora.

Pentru două numere complexe:

$$
z_1 = a + bi
$$

$$
z_2 = c + di
$$

Adunarea se realizează astfel:

$$
z_1 + z_2 = (a+c) + (b+d)i
$$

**Exemplu:**

```text
z1 = 4 + 2i
z2 = 1 + i

Rezultat: 5 + 3i
```

> [!NOTE]
> Cele două numere complexe sunt folosite doar pentru calcul. Nu este nevoie să le modificați. Alegeți o modalitate potrivită de transmitere a structurilor către funcție.

---

#### Exercițiul 3 – Scăderea numerelor complexe

Scrieți o funcție **`scadereNrComplexe()`**, care primește două numere complexe și returnează diferența dintre primul și al doilea.

Scăderea se realizează separat pentru partea reală și cea imaginară:

$$
z_1 - z_2 = (a-c) + (b-d)i
$$

**Exemplu:**

```text
z1 = 4 + 2i
z2 = 1 + i

Rezultat: 3 + i
```

La fel ca în cazul adunării, numerele complexe primite ca parametri nu trebuie modificate.

---

#### Exercițiul 4 – Înmulțirea numerelor complexe

Implementați funcția **`inmultireNrComplexe()`**, care primește două numere complexe și returnează produsul lor.

Pentru înmulțire, utilizați relația:

$$
(a+bi)(c+di) = (ac-bd) + (ad+bc)i
$$

**Exemplu:**

```text
z1 = 4 + 2i
z2 = 1 + i

Rezultat: 2 + 6i
```

> [!NOTE]
> Rezultatul înmulțirii este tot un număr complex. Nu modificați structurile primite ca parametri, ci construiți și returnați rezultatul obținut.

---

#### Exercițiul 5 – Împărțirea numerelor complexe

Scrieți o funcție **`impartireNrComplexe()`**, care primește două numere complexe și returnează rezultatul împărțirii primului la al doilea.

Împărțirea se realizează folosind formula:

$$
\frac{a+bi}{c+di} =
\frac{ac+bd}{c^2+d^2} +
\frac{bc-ad}{c^2+d^2}i
$$

**Exemplu:**

```text
z1 = 4 + 2i
z2 = 1 + i

Rezultat: 3 - i
```

**Precizări:**

- Primul număr reprezintă deîmpărțitul, iar al doilea împărțitorul.
- Funcția trebuie să returneze un număr complex.
- Numerele primite ca parametri nu trebuie modificate.
- Împărțirea nu este definită dacă al doilea număr complex este `0 + 0i`.

> [!IMPORTANT]
> Verificați cazul în care împărțitorul este `0 + 0i`, pentru a evita împărțirea la zero. Modul în care semnalați această situație este la alegerea voastră.

---

### 5. Alte operații cu numere complexe

#### Exercițiul 6 – Calcularea modulului

Scrieți o funcție numită **`calculeazaModul()`**, care primește un număr complex și returnează modulul acestuia.

Pentru un număr complex:

$$
z = a + bi
$$

Modulul se calculează folosind formula:

$$
|z| = \sqrt{a^2+b^2}
$$

**Exemplu:**

```text
z = 3 + 4i

Modul: 5
```

**Precizări:**

- Funcția primește un singur număr complex.
- Numărul primit nu trebuie modificat.
- Rezultatul este un număr real, nu un număr complex.

> [!NOTE]
> Pentru calcularea rădăcinii pătrate puteți utiliza funcția `sqrt()` din biblioteca `<cmath>`.

---

#### Exercițiul 7 – Conjugatul unui număr complex

Implementați funcția **`calculeazaConjugat()`**, care primește un număr complex și returnează conjugatul acestuia.

Conjugatul se obține prin schimbarea semnului părții imaginare:

$$
z = a + bi
$$

$$
\overline{z} = a - bi
$$

**Exemplu:**

```text
z = 4 + 2i

Conjugat: 4 - 2i
```

> [!NOTE]
> Funcția trebuie să returneze un nou număr complex, fără să modifice numărul primit ca parametru.

---

### 6. Afișarea numerelor complexe

#### Exercițiul 8 – Afișarea unui număr complex

Scrieți o funcție numită **`afisareNrComplex()`**, care primește un număr complex și afișează partea reală și partea imaginară sub forma unui număr complex.

**Exemple:**

```text
Partea reala: 4
Partea imaginara: 2

Afisare: 4 + 2i
```

```text
Partea reala: 5
Partea imaginara: -3

Afisare: 5 - 3i
```

**Precizări:**

- Funcția trebuie doar să afișeze numărul, fără să returneze o valoare.
- Numărul complex primit nu trebuie modificat.
- Țineți cont de semnul părții imaginare atunci când realizați afișarea.

> [!NOTE]
> Evitați afișările de forma `5 + -3i`. Dacă partea imaginară este negativă, afișați semnul `-` urmat de valoarea sa pozitivă.

---

#### Exercițiul 9 – Afișarea unui vector de numere complexe

Implementați funcția **`afisareNrComplexe()`**, care primește un vector de numere complexe și dimensiunea acestuia.

Funcția va parcurge vectorul și va afișa fiecare număr complex pe câte o linie.

**Exemplu:**

```text
Vectorul contine 4 numere complexe:

1. 4 + 2i
2. 1 + i
3. 5 - 3i
4. 2 + 4i
```

**Precizări:**

- Vectorul va fi alocat dinamic în funcția `main()`.
- Pentru transmiterea vectorului către funcție, folosiți un pointer.
- Dimensiunea vectorului trebuie transmisă ca parametru separat.
- Funcția nu trebuie să modifice elementele vectorului sau dimensiunea acestuia.
- Pentru afișarea fiecărui element, reutilizați funcția `afisareNrComplex()`.

> [!IMPORTANT]
> Nu implementați din nou logica de afișare a unui număr complex. Folosiți funcția de la exercițiul anterior pentru fiecare element al vectorului.

---

### 7. Alocarea dinamică a vectorului în `main()`

În funcția `main()`, creați un vector de numere complexe, folosind operatorul **`new[]`**.

Dimensiunea vectorului va fi stabilită de voi, iar elementele vor fi inițializate cu valori alese de voi sau citite de la tastatură.

Parcurgeți următorii pași:

1. Declarați un pointer de tip `NrComplex*`.
2. Alocați dinamic memoria pentru vector, folosind operatorul `new[]`.
3. Inițializați elementele vectorului, folosind funcția `initializareNrComplex()`.
4. Afișați toate elementele vectorului, apelând funcția `afisareNrComplexe()`.
5. Testați funcțiile pentru operațiile aritmetice, folosind numere complexe din vector.
6. Calculați modulul și conjugatul pentru cel puțin un număr complex.
7. La final, eliberați memoria alocată vectorului folosind operatorul `delete[]`.

> [!IMPORTANT]
> Vectorul trebuie **alocat dinamic în `main()` și eliberat înainte de terminarea programului**. Nu folosiți un vector static și nu uitați să eliberați memoria alocată.

> [!NOTE]
> Nu este necesară alocarea dinamică pentru fiecare număr complex în parte. Structura `NrComplex` conține doar doi membri de tip `double`, iar vectorul va stoca direct elementele de acest tip.

---

### 8. Recomandări pentru rezolvare

Înainte de a considera un exercițiu terminat, verificați dacă funcția se comportă corect și pentru alte valori decât cele din exemple.

Câteva recomandări:

1. Respectați numele funcțiilor indicate în cerințe.
2. Alegeți tipurile parametrilor și tipurile returnate în funcție de rolul fiecărei funcții.
3. Evitați copierea inutilă a structurilor atunci când acestea sunt folosite doar pentru citirea valorilor.
4. Folosiți `const` pentru parametrii care nu trebuie modificați, acolo unde este potrivit.
5. Apelați și testați fiecare funcție în `main()`.
6. Verificați rezultatele operațiilor și pentru numere complexe care au partea reală sau imaginară negativă.
7. Nu uitați să eliberați memoria alocată dinamic.

> [!NOTE]
> Pentru parametrii de tip `NrComplex`, gândiți-vă când este potrivită transmiterea prin valoare și când este mai avantajoasă transmiterea prin referință constantă. Pentru valorile simple, precum cele de tip `double` sau `int`, transmiterea prin valoare este de regulă suficientă.

> [!WARNING]
> Nu utilizați clase, `std::vector` sau alte containere STL pentru rezolvarea acestor exerciții. Folosiți structura `NrComplex` și un vector alocat dinamic, conform cerințelor.

---

### 9. Observații finale

Exercițiile urmăresc să vă familiarizeze cu utilizarea structurilor în C++ și cu transmiterea datelor între funcții.

Acordați atenție modului în care definiți funcțiile și alegeți parametrii acestora. Nu toate funcțiile trebuie să primească datele în același mod și nu toate trebuie să returneze o valoare.

Încercați să reutilizați funcțiile deja implementate acolo unde este posibil, în loc să scrieți aceeași logică de mai multe ori.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
