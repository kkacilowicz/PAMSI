Została zrealizowana wersja na 5 rozwiązująca problem najkrótszej ścieżki za pomocą algorytmów Dijkstry i Bellmana-Forda.

Zdecydowałem się na rozmiary 10,25,50,75,100,150,200,250,300, ze względu na długi czas wykonania na moim sprzęcie - 300VDens1 dla 100 grafów to
czas ok. 15min. jeśli chodzi o samo wykonanie, nie wspominając o wczytywaniu. Stwierdziłem, że te czasy są wystarczające do zaprezentowania
działania algorytmów.

W przypadku Bellmana-Forda lista sąsiedztwa działa szybciej, niż macierz sąsiedztwa, lecz dla Dijkstry czasy obu reprezentacji są do siebie
zbliżone. Prawdopodbnie wywodzi się to z implementacji tablicowej kopca (wykorzystanego w poprzednich projektach) do kolejki priorytetowej.

Jeśli chodzi o skrócony opis koncepcji na reprezentacje grafu:
Macierz sąsiedztwa - macierz wskaźników do krawędzi, w wierszu o zadanym kluczu wierzchołka znajdują się wszystkie krawędzie wychodzące z niego
Lista sąsiedztwa - tablica mniejszych list. Po kluczu możliwy jest dostęp do listy krawędzi wychodzące z danego wierzchołka

Ponadto węzły Edge oraz Vertex poza swoimi obiektami mają wskaźniki *next, co umożliwia tworzenie list wierzchołków i krawędzi.