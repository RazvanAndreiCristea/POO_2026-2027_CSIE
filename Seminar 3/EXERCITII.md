# Exerciții suplimentare – Clase și constructori în C++

- **Materia:** Programare Orientată Obiect
- **Seminar:** Seminar 3 · Clase și constructori
- **Punctaj:** Exerciții suplimentare, fără punctaj

### 1. Scopul exercițiilor

Aceste exerciții sunt destinate aprofundării noțiunilor prezentate la seminar, în special a modului în care sunt definiți și utilizați constructorii unei clase în C++.

Prin rezolvarea lor veți exersa:

- definirea unei clase și utilizarea atributelor private;
- declararea și implementarea constructorilor;
- supraîncărcarea constructorilor;
- inițializarea atributelor folosind valorile primite ca parametri;
- inițializarea atributelor cu valori implicite;
- definirea și apelarea metodelor unei clase;
- utilizarea atributelor clasei în interiorul metodelor.

> [!NOTE]
> Exercițiile sunt **opționale și nu se punctează**. Le puteți rezolva pentru a exersa suplimentar noțiunile discutate la seminar.

---

### 2. Organizarea programului

Toate cerințele vor fi rezolvate într-un **singur fișier `.cpp`**, în care se va afla și funcția `main()`.

Pentru rezolvare:

1. Definiți clasa `Apartament` folosind structura prezentată mai jos.
2. Declarați și implementați cei 7 constructori solicitați.
3. Implementați metoda `calculeazaPretPeMetruPatrat()`.
4. Creați în `main()` câte un obiect folosind fiecare constructor.
5. Apelați metoda de calcul și afișați rezultatele obținute.

---

### 3. Definirea clasei `Apartament`

Porniți de la următoarea clasă, păstrând **numele și tipurile atributelor**:

```cpp
class Apartament
{
    int etaj;
    int numarCamere;

    float pret;
    float suprafata;

    string adresa;
    string proprietar;
};
```

Atributele clasei reprezintă:

- **`etaj`** (`int`) – etajul la care se află apartamentul;
- **`numarCamere`** (`int`) – numărul de camere;
- **`pret`** (`float`) – prețul apartamentului, exprimat în euro;
- **`suprafata`** (`float`) – suprafața apartamentului, exprimată în metri pătrați;
- **`adresa`** (`string`) – adresa apartamentului;
- **`proprietar`** (`string`) – numele proprietarului.

> [!IMPORTANT]
> Atributele trebuie să rămână în zona **`private`**. Adăugați zona `public` pentru constructorii și metoda pe care urmează să le implementați.

---

### 4. Valorile implicite ale atributelor

Constructorii care nu primesc toate cele 6 atribute ca parametri trebuie să inițializeze atributele rămase cu valori implicite.

Folosiți următoarele valori:

| Atribut | Valoare implicită |
|---|---|
| `etaj` | `0` |
| `numarCamere` | `0` |
| `pret` | `0.0f` |
| `suprafata` | `0.0f` |
| `adresa` | `"N/A"` |
| `proprietar` | `"N/A"` |

De exemplu, dacă un constructor primește doar `numarCamere` și `pret`, celelalte patru atribute vor fi inițializate cu valorile din tabel.

> [!NOTE]
> Valorile implicite se folosesc pentru atributele care nu sunt primite ca parametri. Nu este necesar să utilizați argumente implicite în declarațiile constructorilor.

---

### 5. Implementarea constructorilor

Implementați **7 constructori** pentru clasa `Apartament`, câte unul cu 0, 1, 2, 3, 4, 5 și 6 parametri.

Respectați următoarele semnături:

#### Constructorul 1 – Fără parametri

```cpp
Apartament();
```

Constructorul nu primește niciun parametru și trebuie să inițializeze toate cele 6 atribute cu valorile implicite prezentate în secțiunea anterioară.

---

#### Constructorul 2 – Un parametru

```cpp
Apartament(string adresa);
```

Constructorul primește adresa apartamentului și o folosește pentru inițializarea atributului corespunzător.

Celelalte 5 atribute vor primi valorile implicite.

---

#### Constructorul 3 – Doi parametri

```cpp
Apartament(int numarCamere, float pret);
```

Constructorul primește numărul de camere și prețul apartamentului.

Inițializați aceste două atribute folosind valorile primite, iar pentru celelalte 4 utilizați valorile implicite.

---

#### Constructorul 4 – Trei parametri

```cpp
Apartament(string proprietar, int etaj, float pret);
```

Constructorul primește numele proprietarului, etajul și prețul apartamentului.

Atributele `numarCamere`, `suprafata` și `adresa` vor fi inițializate cu valorile implicite.

---

#### Constructorul 5 – Patru parametri

```cpp
Apartament(float suprafata, string adresa, int numarCamere, float pret);
```

Constructorul primește suprafața, adresa, numărul de camere și prețul apartamentului.

Inițializați cele patru atribute folosind parametrii constructorului.

Pentru `etaj` și `proprietar`, utilizați valorile implicite.

---

#### Constructorul 6 – Cinci parametri

```cpp
Apartament(string proprietar, float pret, int etaj, string adresa, float suprafata);
```

Constructorul primește numele proprietarului, prețul, etajul, adresa și suprafața apartamentului.

Toate aceste atribute vor fi inițializate folosind valorile primite.

Atributul `numarCamere` va fi inițializat cu `0`.

---

#### Constructorul 7 – Șase parametri

```cpp
Apartament(float suprafata, string proprietar, int numarCamere, float pret, string adresa, int etaj);
```

Constructorul primește toate cele 6 atribute ale clasei.

Inițializați fiecare atribut folosind parametrul corespunzător, fără să utilizați valori implicite.

> [!IMPORTANT]
> La final trebuie să aveți **exact 7 constructori implementați conform cerințelor**, câte unul cu 0, 1, 2, 3, 4, 5 și 6 parametri. Fiecare constructor trebuie să inițializeze toate atributele clasei, inclusiv pe cele care nu sunt primite ca parametri.

> [!NOTE]
> Ordinea parametrilor diferă de la un constructor la altul și nu respectă neapărat ordinea atributelor din clasă. Fiți atenți la corespondența dintre parametri și atribute atunci când implementați constructorii.

---

### 6. Metoda `calculeazaPretPeMetruPatrat()`

Scrieți o metodă publică numită **`calculeazaPretPeMetruPatrat()`**, care calculează și returnează prețul unui metru pătrat pentru apartamentul curent.

Calculul se realizează folosind formula:

$$
\text{Preț pe metru pătrat} = \frac{\text{Prețul apartamentului}}{\text{Suprafața apartamentului}}
$$

**Exemplu:**

```text
Pret apartament: 120000 euro
Suprafata: 60 mp

Pret pe metru patrat: 2000 euro/mp
```

**Precizări:**

- Metoda nu primește parametri.
- Pentru calcul, utilizați atributele `pret` și `suprafata` ale obiectului curent.
- Metoda trebuie să returneze un rezultat de tip `float`.
- Nu modificați atributele obiectului în timpul calculului.
- Dacă `suprafata` este `0.0f`, metoda trebuie să returneze `0.0f`.

> [!IMPORTANT]
> Verificați valoarea atributului `suprafata` **înainte de efectuarea împărțirii**, pentru a evita împărțirea la zero.

---

### 7. Testarea constructorilor și a metodei în `main()`

În funcția `main()`, creați **7 obiecte de tip `Apartament`**, folosind fiecare dintre constructorii implementați.

Pentru fiecare obiect, apelați metoda `calculeazaPretPeMetruPatrat()` și afișați rezultatul în consolă.

Folosiți următoarele exemple pentru a testa constructorii:

| Obiect | Constructor | Valori transmise |
|---|---|---|
| `a1` | Fără parametri | – |
| `a2` | Un parametru | `"Strada Lalelelor 12"` |
| `a3` | Doi parametri | `2`, `85000.0f` |
| `a4` | Trei parametri | `"Andrei Popescu"`, `3`, `90000.0f` |
| `a5` | Patru parametri | `60.0f`, `"Strada Teilor 5"`, `3`, `120000.0f` |
| `a6` | Cinci parametri | `"Maria Ionescu"`, `90000.0f`, `2`, `"Bulevardul Unirii 10"`, `60.0f` |
| `a7` | Șase parametri | `100.0f`, `"Ioana Marin"`, `4`, `180000.0f`, `"Strada Viitorului 8"`, `5` |

Valorile din tabel sunt prezentate **în ordinea parametrilor fiecărui constructor**.

După crearea obiectelor, apelați metoda de calcul pentru fiecare dintre ele.

**Rezultatele așteptate:**

```text
Apartament 1:
Pret pe metru patrat: 0 euro/mp

Apartament 2:
Pret pe metru patrat: 0 euro/mp

Apartament 3:
Pret pe metru patrat: 0 euro/mp

Apartament 4:
Pret pe metru patrat: 0 euro/mp

Apartament 5:
Pret pe metru patrat: 2000 euro/mp

Apartament 6:
Pret pe metru patrat: 1500 euro/mp

Apartament 7:
Pret pe metru patrat: 1800 euro/mp
```

> [!NOTE]
> Pentru primele patru obiecte, atributul `suprafata` nu este primit ca parametru și va avea valoarea implicită `0.0f`. Din acest motiv, metoda `calculeazaPretPeMetruPatrat()` trebuie să returneze `0.0f`, chiar dacă unele dintre obiecte au un preț diferit de zero.

> [!IMPORTANT]
> Pentru această cerință nu este necesară implementarea getterilor, setterilor sau a unei metode suplimentare de afișare. În `main()` trebuie doar să creați obiectele, să apelați metoda de calcul și să afișați rezultatele.

---

### 8. Recomandări pentru rezolvare

Înainte de a considera exercițiile terminate, verificați dacă fiecare constructor inițializează corect toate atributele clasei.

Câteva recomandări:

1. Respectați semnăturile constructorilor indicate în cerințe.
2. Inițializați toate atributele, inclusiv pe cele care nu sunt primite ca parametri.
3. Transmiteți toți parametrii constructorilor prin valoare, inclusiv pe cei de tip `string`.
4. Folosiți `this` acolo unde este necesar pentru a diferenția atributele clasei de parametrii cu același nume.
5. Testați metoda de calcul atât pentru suprafețe pozitive, cât și pentru suprafața egală cu `0`.
6. Păstrați codul organizat și folosiți nume sugestive pentru variabile.

> [!NOTE]
> Nu este necesară alocarea dinamică a memoriei pentru aceste exerciții. Folosiți obiecte declarate direct în `main()` și atributele prezentate în clasă.

---

### 9. Observații finale

Aceste exerciții vă ajută să înțelegeți cum putem crea obiecte ale aceleiași clase folosind constructori diferiți, în funcție de informațiile pe care le avem la momentul inițializării.

Acordați atenție ordinii parametrilor, inițializării tuturor atributelor și modului în care metoda `calculeazaPretPeMetruPatrat()` folosește datele obiectului.

**Exercițiile sunt opționale, nu se punctează și nu influențează nota finală.**
