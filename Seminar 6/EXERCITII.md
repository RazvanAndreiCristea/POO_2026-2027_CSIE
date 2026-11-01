# Exerciții suplimentare – Recapitulare supraîncărcarea operatorilor în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 6 · Supraîncărcarea operatorilor
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

În aceste exerciții vom continua să lucrăm cu supraîncărcarea operatorilor, de data aceasta folosind o clasă care reprezintă un vector algebric.

Veți implementa operatori care permit efectuarea unor operații între doi vectori, dar și între un vector și un număr real.

Prin rezolvarea exercițiilor veți exersa:

- implementarea constructorilor, a constructorului de copiere și a destructorului;
- gestionarea unui vector alocat dinamic;
- supraîncărcarea operatorului de asignare;
- supraîncărcarea operatorilor aritmetici și de asignare compusă;
- diferența dintre formele prefixată și postfixată ale operatorilor `++` și `--`;
- supraîncărcarea operatorilor `[]` și `->`;
- compararea a două obiecte folosind `==` și `!=`;
- supraîncărcarea operatorului unar `-`;
- conversia implicită a unui obiect la `double`;
- afișarea obiectelor folosind operatorul `<<`.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile discutate la seminar.

---

### 2. Organizarea programului

Toate cerințele vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru rezolvare:

1. Definiți clasa `Vector` folosind structura prezentată mai jos.
2. Declarați și implementați constructorii, destructorul și operatorul de asignare.
3. Implementați operatorii ceruți în secțiunile următoare.
4. Testați fiecare operator în `main()`, folosind vectori cu valori alese de voi.
5. Afișați rezultatele pentru a verifica dacă operațiile au fost efectuate corect.

> [!IMPORTANT]
> De această dată, **semnăturile operatorilor nu sunt oferite**. Va trebui să stabiliți singuri tipul returnat, parametrii necesari și dacă operatorul trebuie implementat ca metodă a clasei sau ca funcție `friend`.

Fiți atenți și la operatorii care trebuie să modifice obiectul curent, respectiv la cei care trebuie să returneze un obiect nou.

---

### 3. Definirea clasei `Vector`

Porniți de la următoarea clasă, păstrând **numele și tipurile atributelor**:

```cpp
class Vector
{
    int dimensiune;
    double* elemente;
};
```

Atributele clasei reprezintă:

- **`dimensiune`** (`int`) – numărul de elemente ale vectorului;
- **`elemente`** (`double*`) – pointer către elementele vectorului, memorate într-o zonă de memorie alocată dinamic.

De exemplu, un vector cu trei elemente poate fi reprezentat astfel:

$$
v=(2,\ 4,\ 6)
$$

În acest caz:

- `dimensiune` va avea valoarea `3`;
- `elemente` va conține valorile `2`, `4` și `6`.

> [!IMPORTANT]
> Atributele clasei trebuie să rămână în zona **`private`**. Adăugați zona `public` pentru constructori, destructor și metodele necesare.

Nu utilizați `std::vector` sau alte containere STL pentru memorarea elementelor. Memoria trebuie gestionată folosind operatorii `new[]` și `delete[]`.

---

### 4. Constructorii, destructorul și operatorul de asignare

#### Exercițiul 1 – Constructorul fără parametri

Implementați constructorul fără parametri al clasei `Vector`.

Acesta trebuie să inițializeze:

- `dimensiune` cu `0`;
- `elemente` cu `nullptr`.

Nu este necesară alocarea dinamică a memoriei în acest constructor.

---

#### Exercițiul 2 – Constructorul cu toți parametrii

Implementați un constructor care primește dimensiunea unui vector și un pointer către elementele acestuia.

Constructorul trebuie:

1. Să inițializeze atributul `dimensiune` cu valoarea primită.
2. Să aloce dinamic memoria necesară pentru elementele vectorului.
3. Să copieze fiecare element din vectorul primit în noua zonă de memorie.

Dacă dimensiunea este `0`, atributul `elemente` va rămâne `nullptr`.

**Exemplu:**

```cpp
double valori[] = { 2, 4, 6 };

Vector v(3, valori);
```

Obiectul `v` va conține trei elemente, cu valorile `2`, `4` și `6`.

> [!IMPORTANT]
> Pentru atributul `elemente` trebuie realizată o **copie profundă (deep copy)**. Nu copiați doar adresa vectorului primit ca parametru.

> [!NOTE]
> Vectorul primit ca parametru este folosit doar pentru citirea elementelor. Alegeți o modalitate de transmitere care să nu permită modificarea acestora prin parametrul respectiv.

---

#### Exercițiul 3 – Constructorul de copiere

Implementați constructorul de copiere pentru clasa `Vector`.

Acesta trebuie să permită crearea unui vector nou, pornind de la unul deja existent.

Constructorul trebuie:

- să copieze dimensiunea vectorului sursă;
- să aloce separat memoria necesară;
- să copieze toate elementele vectorului sursă;
- să trateze și cazul unui vector cu dimensiunea `0`.

**Exemplu:**

```cpp
double valori[] = { 1, 2, 3 };

Vector v1(3, valori);
Vector v2(v1);
```

După copiere, cei doi vectori vor conține aceleași valori, dar vor avea zone de memorie diferite.

> [!IMPORTANT]
> Modificarea unui element din `v2` nu trebuie să afecteze elementele din `v1`.

---

#### Exercițiul 4 – Operatorul de asignare

Supraîncărcați operatorul `=` pentru clasa `Vector`.

Operatorul trebuie:

1. Să trateze corect autoasignarea.
2. Să elibereze memoria asociată vechilor elemente.
3. Să copieze dimensiunea vectorului sursă.
4. Să aloce memoria necesară pentru noile elemente.
5. Să realizeze o copie profundă a acestora.
6. Să returneze o referință la obiectul curent.

**Exemplu:**

```cpp
double valori1[] = { 1, 2, 3 };
double valori2[] = { 5, 6 };

Vector v1(3, valori1);
Vector v2(2, valori2);

v1 = v2;
```

După asignare, `v1` va avea dimensiunea `2` și va conține elementele `5` și `6`.

**Testați și autoasignarea:**

```cpp
v1 = v1;
```

> [!NOTE]
> Verificați autoasignarea înainte de a elibera memoria. Aveți grijă și la cazul în care vectorul sursă are dimensiunea `0`.

---

#### Exercițiul 5 – Destructorul

Implementați destructorul clasei `Vector`.

Acesta trebuie să elibereze memoria alocată dinamic pentru atributul `elemente`, folosind operatorul `delete[]`.

> [!IMPORTANT]
> Fiecare obiect trebuie să își gestioneze propria zonă de memorie. Evitați situațiile în care doi vectori ajung să elibereze aceeași adresă.

---

### 5. Operatorii aritmetici

#### Exercițiul 6 – Operatorul `+`

Supraîncărcați operatorul `+` pentru următoarele trei situații:

- adunarea a doi vectori;
- adunarea unui vector cu un număr real;
- adunarea unui număr real cu un vector.

**a) Adunarea a doi vectori**

Pentru doi vectori:

$$
v_1=(a_1,a_2,\ldots,a_n)
$$

$$
v_2=(b_1,b_2,\ldots,b_n)
$$

Adunarea se realizează element cu element:

$$
v_1+v_2=(a_1+b_1,a_2+b_2,\ldots,a_n+b_n)
$$

**Exemplu:**

```text
v1 = (1, 2, 3)
v2 = (4, 5, 6)

v1 + v2 = (5, 7, 9)
```

**b) Adunarea unui vector cu un număr real**

Numărul real se adună la fiecare element al vectorului.

**Exemplu:**

```text
v = (1, 2, 3)

v + 2 = (3, 4, 5)
2 + v = (3, 4, 5)
```

> [!IMPORTANT]
> Implementați toate cele trei variante ale operatorului `+`. Rezultatul trebuie să fie un nou obiect de tip `Vector`, fără modificarea operanzilor.

---

#### Exercițiul 7 – Operatorul `-`

Supraîncărcați operatorul `-` pentru aceleași trei situații:

- scăderea a doi vectori;
- scăderea unui număr real dintr-un vector;
- scăderea unui vector dintr-un număr real.

**a) Scăderea a doi vectori**

Scădeți elementele aflate pe aceleași poziții.

$$
v_1-v_2=(a_1-b_1,a_2-b_2,\ldots,a_n-b_n)
$$

**Exemplu:**

```text
v1 = (5, 7, 9)
v2 = (1, 2, 3)

v1 - v2 = (4, 5, 6)
```

**b) Scăderea între un vector și un număr real**

**Exemplu:**

```text
v = (1, 2, 3)

v - 2 = (-1, 0, 1)
2 - v = (1, 0, -1)
```

> [!NOTE]
> Fiți atenți la ordinea operanzilor. Operația `v - 2` nu este echivalentă cu `2 - v`.

---

#### Exercițiul 8 – Operatorul `*`

Supraîncărcați operatorul `*` pentru:

- înmulțirea a doi vectori;
- înmulțirea unui vector cu un număr real;
- înmulțirea unui număr real cu un vector.

**a) Înmulțirea a doi vectori**

Pentru acest exercițiu, înmulțirea a doi vectori se va realiza **element cu element**.

$$
v_1*v_2=(a_1b_1,a_2b_2,\ldots,a_nb_n)
$$

**Exemplu:**

```text
v1 = (1, 2, 3)
v2 = (4, 5, 6)

v1 * v2 = (4, 10, 18)
```

> [!NOTE]
> Această operație este o înmulțire element cu element, nu produsul scalar obișnuit al doi vectori. Am ales această variantă pentru ca rezultatul să fie tot un vector și să putem implementa în același mod și operatorul `*=`.

**b) Înmulțirea unui vector cu un număr real**

Fiecare element al vectorului va fi înmulțit cu numărul primit.

**Exemplu:**

```text
v = (1, 2, 3)

v * 3 = (3, 6, 9)
3 * v = (3, 6, 9)
```

> [!IMPORTANT]
> Toate cele trei variante trebuie să returneze un nou obiect de tip `Vector`. Vectorii folosiți în operație nu trebuie modificați.

---

### 6. Operatorii de asignare compusă

#### Exercițiul 9 – Operatorii `+=`, `-=` și `*=`

Implementați operatorii de asignare compusă pentru clasa `Vector`.

Fiecare operator va avea **două variante**:

- una care primește un alt obiect de tip `Vector`;
- una care primește un număr real de tip `double`.

**a) Operații între doi vectori**

Operațiile se realizează element cu element, folosind aceleași reguli ca în secțiunea anterioară.

**Exemplu:**

```text
v1 = (1, 2, 3)
v2 = (4, 5, 6)

Dupa v1 += v2:
v1 = (5, 7, 9)
```

Pentru `-=`, elementele vectorului primit vor fi scăzute din elementele obiectului curent.

Pentru `*=`, elementele aflate pe aceleași poziții vor fi înmulțite.

**b) Operații între un vector și un număr real**

**Exemplu:**

```text
v = (1, 2, 3)(
Dupa v)+= 2:
v = (3, 4, 5)

Dupa v -= 1:
v = (2, 3, 4)

Dupa v *= 2:
v = (4, 6, 8)
```

**Precizări:**

- Operatorii trebuie să modifice elementele obiectului curent.
- Nu modificați vectorul primit ca parametru.
- Returnați o referință la obiectul curent.
- Nu este necesară alocarea unui nou vector dacă dimensiunea rămâne neschimbată.

> [!IMPORTANT]
> Spre deosebire de operatorii `+`, `-` și `*`, operatorii de asignare compusă modifică obiectul din partea stângă a expresiei.

---

### 7. Operatorii de incrementare, decrementare și negare

#### Exercițiul 10 – Operatorii `++` și `--`

Implementați atât formele prefixate, cât și formele postfixate ale operatorilor `++` și `--`.

Pentru un vector, incrementarea înseamnă **adunarea valorii `1` la fiecare element**, iar decrementarea presupune scăderea valorii `1` din fiecare element.

**Exemplu:**

```text
v = (2, 4, 6)

Dupa ++v:
v = (3, 5, 7)

Dupa --v:
v = (2, 4, 6)
```

**Forma prefixată**

Operatorul trebuie să modifice obiectul curent și să returneze o referință la acesta.

**Forma postfixată**

Operatorul trebuie să modifice obiectul curent, dar să returneze o copie a vectorului de dinaintea modificării.

**Exemplu:**

```cpp
double valori[] = { 1, 2, 3 };

Vector v(3, valori);

Vector rezultat = v++;
```

După executarea instrucțiunii:

```text
v = (2, 3, 4)

rezultat = (1, 2, 3)
```

> [!NOTE]
> Nu uitați că forma postfixată se diferențiază de cea prefixată prin parametrul suplimentar de tip `int`, care nu este utilizat efectiv în calcul.

---

#### Exercițiul 11 – Operatorul unar `-`

Supraîncărcați operatorul unar `-` astfel încât să returneze **opusul vectorului curent**.

Opusul unui vector se obține prin schimbarea semnului fiecărui element.

$$
-v=(-a_1,-a_2,\ldots,-a_n)
$$

**Exemplu:**

```text
v = (2, -4, 6)

-v = (-2, 4, -6)
```

**Precizări:**

- Operatorul nu primește parametri.
- Trebuie să returneze un nou obiect de tip `Vector`.
- Obiectul curent nu trebuie modificat.

> [!IMPORTANT]
> Nu confundați operatorul unar `-` cu operatorul binar `-`, care realizează scăderea între doi operanzi.

---

### 8. Operatorii `[]` și `->`

#### Exercițiul 12 – Operatorul `[]`

Supraîncărcați operatorul `[]` pentru a permite accesarea unui element din vector folosind poziția acestuia.

**Exemplu:**

```cpp
double valori[] = { 10, 20, 30 };

Vector v(3, valori);

cout << v[0] << '\n';
cout << v[2] << '\n';
```

**Rezultat:**

```text
10
30
```

Operatorul trebuie să permită și modificarea unui element:

```cpp
v[1] = 50;
```

După această instrucțiune, vectorul va conține:

```text
(10, 50, 30)
```

**Precizări:**

- Indexarea începe de la `0`.
- Operatorul primește poziția elementului care trebuie accesat.
- Alegeți un tip returnat care să permită atât citirea, cât și modificarea elementului.
- Implementați și o variantă care să permită doar citirea elementelor unui obiect constant.

> [!NOTE]
> Pentru aceste exerciții considerăm că indicii utilizați sunt valizi, adică se află în intervalul `[0, dimensiune - 1]`. Nu este necesară implementarea verificării limitelor vectorului.

---

#### Exercițiul 13 – Operatorul `->`

Supraîncărcați operatorul `->` pentru clasa `Vector`.

Acesta trebuie să permită accesarea membrilor publici ai obiectului folosind sintaxa specifică pointerilor, chiar dacă variabila este un obiect, nu un pointer.

Pentru a putea testa mai ușor acest operator, implementați și un getter public numit **`getDimensiune()`**, care returnează dimensiunea vectorului fără să modifice obiectul.

**Exemplu:**

```cpp
double valori[] = { 10, 20, 30 };

Vector v(3, valori);

cout << v->getDimensiune() << '\n';
```

**Rezultat:**

```text
3
```

**Precizări:**

- Operatorul nu primește parametri.
- Trebuie să permită accesarea membrilor publici ai obiectului curent.
- Nu trebuie să aloce memorie sau să creeze un obiect nou.
- Implementați și o variantă pentru obiectele constante, astfel încât acestea să poată accesa metodele publice marcate cu `const`.

> [!NOTE]
> Gândiți-vă ce trebuie să returneze operatorul `->` pentru ca expresia `v->getDimensiune()` să funcționeze. În acest caz, nu dorim accesul la adresa vectorului intern `elemente`, ci la obiectul `Vector` propriu-zis.

---

### 9. Operatorii de comparație

#### Exercițiul 14 – Operatorii `==` și `!=`

Supraîncărcați operatorii de egalitate și inegalitate pentru două obiecte de tip `Vector`.

**Operatorul `==`**

Doi vectori sunt considerați egali dacă:

- au aceeași dimensiune;
- toate elementele aflate pe aceleași poziții sunt egale;
- trebuie tratată și situația pentru doi vectori care au fost făcuți cu constructorul defaut.

**Exemplu:**

```text
v1 = (1, 2, 3)
v2 = (1, 2, 3)
v3 = (1, 2, 4)

v1 == v2 -> true
v1 == v3 -> false
```

**Operatorul `!=`**

Trebuie să returneze `true` dacă vectorii sunt diferiți și `false` dacă sunt egali.

**Exemplu:**

```text
v1 = (1, 2, 3)
v2 = (1, 2, 4)

v1 != v2 -> true
```

**Precizări:**

- Operatorii trebuie să returneze o valoare de tip `bool`.
- Nu modificați niciunul dintre vectorii comparați.
- Verificați mai întâi dimensiunile și apoi elementele.
- Doi vectori fără elemente, creați cu constructorul fără parametri, sunt considerați egali.

> [!IMPORTANT]
> Nu comparați adresele pointerilor `elemente`. Trebuie comparate **valorile memorate în vectori**, nu zonele de memorie în care se află acestea.

---

### 10. Operatorul de conversie implicită

#### Exercițiul 15 – Conversia unui vector la `double`

Implementați un operator de conversie implicită la tipul `double`, care returnează **modulul vectorului**.

Pentru un vector:

$$
v=(a_1,a_2,\ldots,a_n)
$$

Modulul se calculează folosind formula:

$$
\|v\|=\sqrt{a_1^2+a_2^2+\ldots+a_n^2}
$$

**Exemplu:**

Pentru vectorul:

$$
v=(3,4)
$$

Modulul este:

$$
\|v\|=\sqrt{3^2+4^2}=\sqrt{25}=5
$$

Operatorul trebuie să permită atribuirea directă a unui obiect `Vector` unei variabile de tip `double`.

**Exemplu:**

```cpp
double valori[] = { 3, 4 };

Vector v(2, valori);

double modul = v;
```

Variabila `modul` va avea valoarea `5`.

**Precizări:**

- Operatorul nu primește parametri.
- Nu modificați elementele vectorului.
- Parcurgeți vectorul și calculați suma pătratelor elementelor.
- Returnați rădăcina pătrată a sumei.
- Pentru un vector cu dimensiunea `0`, modulul va fi `0`.

> [!NOTE]
> Pentru calcularea rădăcinii pătrate puteți utiliza funcția `sqrt()` din biblioteca `<cmath>`.

> [!IMPORTANT]
> Conversia trebuie să fie **implicită**, deci nu utilizați cuvântul-cheie `explicit` la declararea acestui operator.

---

### 11. Operatorul de afișare

#### Exercițiul 16 – Supraîncărcarea operatorului `<<`

Implementați operatorul `<<` pentru a putea afișa direct obiecte de tip `Vector` folosind `cout`.

**Exemplu:**

```cpp
double valori[] = { 2, 4, 6 };

Vector v(3, valori);

cout << v;
```

**Rezultat:**

```text
(2, 4, 6)
```

Dacă vectorul nu conține elemente, afișarea va fi:

```text
()
```

**Precizări:**

- Afișați elementele între paranteze drepte.
- Separați elementele prin virgulă și spațiu.
- Nu afișați o virgulă după ultimul element.
- Operatorul nu trebuie să modifice vectorul.
- Nu adăugați automat caracterul de trecere la linia următoare.
- Returnați fluxul de ieșire pentru a permite afișările în lanț.

**Exemplu de afișare în lanț:**

```cpp
cout << "Vectorul este: " << v << '\n';
```

**Rezultat:**

```text
Vectorul este: (2, 4, 6)
```

> [!NOTE]
> Gândiți-vă de ce operatorul `<<` trebuie implementat ca funcție `friend` și nu ca metodă obișnuită a clasei `Vector`.

---

### 12. Testarea clasei în `main()`

În funcția `main()`, creați mai mulți vectori și testați toate funcționalitățile implementate.

Pentru început, puteți folosi următoarele valori:

```cpp
double valori1[] = { 1, 2, 3 };
double valori2[] = { 4, 5, 6 };

Vector v1(3, valori1);
Vector v2(3, valori2);
```

**Testarea constructorilor și a gestionării memoriei**

1. Creați un vector folosind constructorul fără parametri.
2. Creați doi vectori folosind constructorul cu toți parametrii.
3. Creați un alt vector folosind constructorul de copiere.
4. Modificați un element din copia obținută și verificați dacă vectorul original a rămas nemodificat.
5. Testați operatorul de asignare între doi vectori cu dimensiuni diferite.
6. Verificați dacă autoasignarea funcționează corect.

**Testarea operatorilor**

7. Testați operatorii `+`, `-` și `*` între doi vectori.
8. Testați aceiași operatori între un vector și un număr real, în ambele ordini.
9. Testați operatorii `+=`, `-=` și `*=` cu un alt vector.
10. Testați operatorii `+=`, `-=` și `*=` cu un număr real.
11. Testați formele prefixată și postfixată ale operatorilor `++` și `--`.
12. Calculați opusul unui vector folosind operatorul unar `-`.
13. Accesați și modificați elemente folosind operatorul `[]`.
14. Testați operatorul `->` și getterul `getDimensiune()`.
15. Comparați vectori folosind operatorii `==` și `!=`.
16. Calculați modulul unui vector folosind conversia implicită la `double`.
17. Afișați rezultatele folosind operatorul `<<`.

**Exemplu de testare a operatorilor aritmetici:**

```cpp
cout << "v1 = " << v1 << '\n';
cout << "v2 = " << v2 << '\n';

cout << "Suma: " << v1 + v2 << '\n';
cout << "Diferenta: " << v1 - v2 << '\n';
cout << "Produs: " << v1 * v2 << '\n';

cout << "v1 + 2: " << v1 + 2.0 << '\n';
cout << "2 + v1: " << 2.0 + v1 << '\n';

cout << "Opusul lui v1: " << -v1 << '\n';
```

**Rezultatele așteptate:**

```text
v1 = (1, 2, 3)
v2 = (4, 5, 6)

Suma: (5, 7, 9)
Diferenta: (-3, -3, -3)
Produs: (4, 10, 18)

v1 + 2: (3, 4, 5)
2 + v1: (3, 4, 5)

Opusul lui v1: (-1, -2, -3)
```

**Exemplu de testare a conversiei implicite:**

```cpp
double valori[] = { 3, 4 };

Vector v(2, valori);

double modul = v;

cout << "Modulul vectorului: " << modul << '\n';
```

**Rezultat:**

```text
Modulul vectorului: 5
```

> [!IMPORTANT]
> Pentru operațiile dintre doi vectori considerăm că aceștia au aceeași dimensiune. Nu este necesar să implementați tratarea operațiilor între vectori cu dimensiuni diferite.

> [!NOTE]
> Folosiți obiecte separate pentru testarea operatorilor care modifică vectorul curent. În acest fel, rezultatul unei operații nu va influența testarea alteia.

---

### 13. Recomandări pentru rezolvare

Înainte de a considera exercițiile terminate, verificați dacă toți operatorii respectă comportamentul cerut.

Câteva recomandări:

1. Inițializați corect atributele clasei în constructori.
2. Folosiți `new[]` pentru alocarea memoriei și `delete[]` pentru eliberarea acesteia.
3. Realizați copii profunde în constructorul de copiere și în operatorul de asignare.
4. Verificați autoasignarea înainte de a modifica memoria obiectului.
5. Alegeți cu atenție tipurile returnate de operatori.
6. Folosiți referințe constante pentru obiectele primite ca parametri atunci când acestea nu trebuie modificate.
7. Nu returnați referințe către obiecte locale create în interiorul operatorilor.
8. Pentru operatorii postfixați, păstrați o copie a obiectului înainte de modificare.
9. Fiți atenți la ordinea operanzilor în cazul scăderii.
10. Reutilizați operatorii deja implementați acolo unde este posibil.
11. Testați și vectorii care nu conțin elemente.
12. Verificați dacă memoria alocată este eliberată corect.

> [!WARNING]
> Nu utilizați `std::vector`, `std::array` sau alte containere STL. Elementele clasei trebuie memorate exclusiv prin atributul `double* elemente`.

> [!NOTE]
> Nu este necesară implementarea altor operații matematice în afara celor cerute. Accentul cade pe supraîncărcarea operatorilor și pe gestionarea corectă a memoriei.

---

### 14. Observații finale

Aceste exerciții vă ajută să înțelegeți cum putem defini comportamentul operatorilor din C++ pentru obiectele unei clase care gestionează memorie alocată dinamic.

Acordați atenție diferenței dintre operatorii care modifică obiectul curent și cei care returnează un obiect nou. De asemenea, urmăriți când este potrivit să returnați o valoare și când trebuie să returnați o referință.

Nu uitați să testați constructorul de copiere, operatorul de asignare și destructorul, deoarece gestionarea corectă a memoriei este la fel de importantă ca implementarea operatorilor.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
