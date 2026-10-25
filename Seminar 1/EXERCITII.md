# Exerciții suplimentare – Funcții în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 1 · Introducere în C++ și funcții
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Aceste exerciții sunt destinate aprofundării noțiunilor prezentate în cadrul primului seminar, în special a modului în care sunt definite și apelate funcțiile în C++.

Prin rezolvarea lor veți exersa:

- declararea, definirea și apelarea funcțiilor;
- transmiterea parametrilor prin valoare și prin pointeri;
- utilizarea instrucțiunilor condiționale `if` și `else`;
- utilizarea instrucțiunilor repetitive `for` și `while`;
- returnarea valorilor din funcții;
- accesarea și modificarea variabilelor prin intermediul pointerilor.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile discutate la seminar.

---

### 2. Organizarea programului

Toate exercițiile vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru fiecare exercițiu:

1. Implementați funcția folosind semnătura indicată.
2. Apelați funcția în `main()`, folosind valori alese de voi.
3. Afișați rezultatul în consolă și verificați dacă este cel așteptat.

> [!IMPORTANT]
> Parametrii funcțiilor vor fi transmiși **prin valoare sau prin pointeri**, conform cerințelor. Nu utilizați transmiterea prin referință.

---

### 3. Exerciții ușoare

#### Exercițiul 1 – Produsul a două numere

Scrieți o funcție **`produs()`** care primește două numere întregi și returnează produsul lor.

**Semnătura funcției:**

```cpp
int produs(int a, int b);
```

**Exemplu:**

```text
a = 5
b = 4

Rezultat: 20
```

---

#### Exercițiul 2 – Maximul dintre două numere

Implementați funcția **`maxim()`**, care primește două numere întregi și returnează numărul mai mare.

**Semnătura funcției:**

```cpp
int maxim(int a, int b);
```

**Exemplu:**

```text
a = 12
b = 7

Rezultat: 12
```

> [!NOTE]
> Dacă cele două numere sunt egale, funcția va returna valoarea comună.

---

#### Exercițiul 3 – Verificarea unui număr negativ

Scrieți o funcție **`esteNegativ()`** care verifică dacă numărul întreg primit ca parametru este negativ.

Funcția va returna:

- `true` dacă numărul este negativ;
- `false` în caz contrar.

**Semnătura funcției:**

```cpp
bool esteNegativ(int numar);
```

**Exemplu:**

```text
numar = -8

Rezultat: true
```

> [!NOTE]
> Numărul `0` nu este considerat negativ.

---

#### Exercițiul 4 – Media aritmetică

Scrieți o funcție **`medieAritmetica()`** care primește trei numere de tip `float` și returnează media lor aritmetică.

**Semnătura funcției:**

```cpp
float medieAritmetica(float a, float b, float c);
```

**Exemplu:**

```text
a = 5
b = 7
c = 9

Rezultat: 7
```

---

#### Exercițiul 5 – Suma numerelor pare

Implementați funcția **`sumaNumerelorPare()`**, care primește un număr natural `n` și calculează suma tuturor numerelor pare de la `0` la `n`, inclusiv.

**Semnătura funcției:**

```cpp
int sumaNumerelorPare(int n);
```

**Exemplu:**

```text
n = 10

Numere pare: 0 2 4 6 8 10

Rezultat: 30
```

Pentru parcurgerea numerelor, utilizați o instrucțiune repetitivă `for` sau `while`.

---

#### Exercițiul 6 – Numărul de cifre

Scrieți o funcție **`numarCifre()`** care primește un număr natural și returnează câte cifre are acesta.

**Semnătura funcției:**

```cpp
int numarCifre(int numar);
```

**Exemplu:**

```text
numar = 12345

Rezultat: 5
```

> [!NOTE]
> Puteți determina numărul de cifre folosind împărțirea întreagă la `10`. Aveți grijă și la cazul în care numărul primit este `0`, deoarece acesta are o singură cifră.

---

#### Exercițiul 7 – Dublarea valorii unei variabile

Scrieți o funcție **`dubleazaValoarea()`** care primește adresa unei variabile întregi și îi dublează valoarea.

După apelarea funcției, variabila declarată în `main()` trebuie să conțină noua valoare.

**Semnătura funcției:**

```cpp
void dubleazaValoarea(int* numar);
```

**Exemplu:**

```text
Valoarea initiala: 15

Valoarea dupa apelarea functiei: 30
```

> [!IMPORTANT]
> Modificați valoarea variabilei prin **dereferențierea pointerului**, nu prin returnarea unui rezultat.

---

#### Exercițiul 8 – Interschimbarea a două valori

Implementați funcția **`interschimbare()`**, care primește adresele a două variabile întregi și le interschimbă valorile.

**Semnătura funcției:**

```cpp
void interschimbare(int* a, int* b);
```

**Exemplu:**

```text
Inainte de interschimbare:

a = 10
b = 25

Dupa interschimbare:

a = 25
b = 10
```

> [!NOTE]
> La seminar am văzut că transmiterea parametrilor prin valoare nu modifică variabilele originale. De această dată, folosind pointeri, interschimbarea trebuie să fie vizibilă și în `main()`.

---

### 4. Exerciții de dificultate medie

#### Exercițiul 9 – Calcularea factorialului

Scrieți o funcție **`factorial()`** care primește un număr natural `n` și returnează factorialul acestuia.

Factorialul unui număr natural reprezintă produsul tuturor numerelor naturale de la `1` la `n`.

**Semnătura funcției:**

```cpp
int factorial(int n);
```

**Exemplu:**

```text
n = 5

Calcul: 1 * 2 * 3 * 4 * 5

Rezultat: 120
```

**Precizări:**

- Folosiți o instrucțiune repetitivă `for` sau `while`.
- Pentru `n = 0`, funcția va returna `1`.
- Considerați valori ale lui `n` din intervalul `[0, 12]`.

> [!NOTE]
> Nu este nevoie să folosiți recursivitatea. Exercițiul poate fi rezolvat cu instrucțiunile repetitive studiate la seminar.

---

#### Exercițiul 10 – Suma cifrelor unui număr

Scrieți o funcție **`sumaCifrelor()`** care primește un număr natural și returnează suma cifrelor sale.

**Semnătura funcției:**

```cpp
int sumaCifrelor(int numar);
```

**Exemplu:**

```text
numar = 2534

Calcul: 2 + 5 + 3 + 4

Rezultat: 14
```

**Precizări:**

- Folosiți instrucțiunea repetitivă `while`.
- Extrageți cifrele numărului pe rând și adunați-le.
- Pentru `numar = 0`, funcția va returna `0`.

> [!NOTE]
> Amintiți-vă că operatorul `%` poate fi folosit pentru a obține ultima cifră a unui număr, iar împărțirea întreagă la `10` permite eliminarea acesteia.

---

#### Exercițiul 11 – Determinarea minimului și maximului

Scrieți o funcție **`minimMaxim()`** care primește trei numere întregi și determină cea mai mică și cea mai mare valoare dintre acestea.

Cele două rezultate vor fi transmise către funcția `main()` prin intermediul pointerilor.

**Semnătura funcției:**

```cpp
void minimMaxim(int a, int b, int c, int* minim, int* maxim);
```

**Exemplu:**

```text
a = 14
b = 5
c = 23

Minim: 5
Maxim: 23
```

**Precizări:**

- Primele trei numere sunt transmise prin valoare.
- Parametrii `minim` și `maxim` sunt pointeri prin intermediul cărora vor fi transmise rezultatele.
- Folosiți instrucțiuni `if` pentru a determina cele două valori.
- Afișați în `main()` minimul și maximul obținute.

> [!IMPORTANT]
> Funcția trebuie să determine **ambele valori printr-un singur apel**. Nu returnați rezultatele folosind `return`, ci modificați variabilele corespunzătoare prin pointeri.

---

### 5. Recomandări pentru rezolvare

Înainte de a considera un exercițiu terminat, verificați dacă funcția se comportă corect și pentru alte valori decât cele din exemple.

Câteva recomandări:

1. Respectați semnăturile funcțiilor din cerințe.
2. Apelați fiecare funcție în `main()` și afișați rezultatele.
3. Încercați mai multe valori pentru fiecare exercițiu.
4. Nu uitați să verificați și cazurile particulare, cum ar fi numărul `0` sau două valori egale.
5. Alegeți nume sugestive pentru variabile și păstrați codul cât mai ușor de urmărit.

> [!WARNING]
> Nu utilizați referințe pentru transmiterea parametrilor. În exercițiile în care trebuie modificate variabilele din `main()`, folosiți pointeri.

---

### 6. Observații finale

Toate exercițiile pot fi rezolvate folosind noțiunile prezentate la seminar. Nu aveți nevoie de clase, vectori, alocare dinamică sau alte concepte pe care nu le-am discutat încă.

Acordați mai multă atenție exercițiilor **7, 8 și 11**, deoarece acestea vă ajută să înțelegeți cum putem modifica valorile unor variabile dintr-o altă funcție, folosind pointeri.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
