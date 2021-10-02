# README #

## POLSKI

### Opis aplikacji
WorkTimer to prosta aplikacja do odliczania czasu. Projekt powstał z myślą o stosowaniu regularnych przerw od komputera w pracy i na co dzień. Aplikacji w chwili obecnej posiada trzy stałe możliwe punkty satrtowe odliczania: `15`, `30` i `45 minut`. Podczas uruchomienia aplikacji, użytkownik zostaje przeniesiony na ekran powitalny. Po kilku sekundach użytkownik trafia do ekranu menu na którym widnieją następujące opcje:
- ustaw odlicznie
- informacje
- wyjście

##### Ustaw odliczanie
Po wybraniu tej opcji na ekranie ukazują się trzy kolejne opcje: `15 minut`, `30 minut` i `45 minut`. To wspomniane wcześniej stałe, które może wybrać, aby rozpocząć odliczanie. Po wyborze jednej z opcji użytkownik zostaje przeniesiony do ekranu odliczania gdzie może: rozpocząć odliczanie, następnie zatrzymać je i ponownie wznowić.

##### Informacje
Po wybraniu tej opcji z menu na ekranie ukazują się skrótowe informacje na temat aplikacji oraz nicki twórców.

Każdy z wyżej wymienionych ekranów posiada przycisk `Powrót` umożliwiający cofnięcie się do poprzednio wyświetlanego ekranu. Na ekranie menu widnieje przycisk `Wyjście`, który umożliwia zamknięcie aplikacji. Zamykając aplikację użytkownik zostaje pożegnany na specjalnym ekranie. 

Na chwilę obecną aplikacja jest w pełni w języku polskim. 

### Sposób uruchamiania
Projekt stworzony został za pośrednictwem Visual Studio Code. Wszelkie graficzne aspekty aplikacji zostały osiągnięte dzięki bibliotece `SFML 2.5.1 w wersji 64 bitowej`. Aplikacja została skompilowana za pośrednictwem kompilatora `g++ 7.3.0. w wersji 64 bitowej`.

W celu zbudowania projektu należy wykorzystać plik Makefile i użyć następującej komendy:
```
mingw32-make
```
lub
```
mingw32-make all
```

W celu zbudowania wersji z możliwością debugowania należy użyć komendy:
```
mingw32-make debug
```

#### Pozsotałe komendy
Czyści wszyskie pliki obj:
```
mingw32-make clean
```

Czyści wszystkie pliki obj i dodatkowo usuwa zależności pomiędzy plikami:
```
mingw32-make deepClean
```

Całkowicie usuwa folder ze zbudowanymi plikami projektu:
```
mingw32-make allClean
```

Czyści pliki obj i ponownie buduje projekt:
```
mingw32-make rebuild
```

##### Uwagi
Wszystkie te komendy działają jedynie w bashu. Podczas próby uruchamiania ich w zwykłej konsoli na systemie Windows projekt nie zbuje się poprawnie!

Wszystkie zbudowane pliki trafiają do foleru bin. W nim znajdują się odpowiednio: pliki zależności oraz foldery: debug i release.

### Uwagi twórcy
Jeśli masz sugestie co można by ulepszyć, naprawić, widzisz jakieś błędy, czuj się swobodnie i napisz. Wszelkie uwagi i wskazówki są mile widziane. Dzięki temu nieustannie się rozwijamy.

### Podziękowania
Wszystkie wykorzystane w aplikacji tła do wszystkich ekranów zostały stworzone na wyraz uwielbienia wobec cudownego zwierzaka jakim jest `czarny kot Figaro :)`. Całość grafiki została wykonana przez moją serdeczną przyjaciółkę `Paulinę`. Gdyby nie jej wkład i zaangażowanie projekt nie wyglądałby tak dobrze z punktu widzenia estetyki. Chciałbym z tego miejsca bardzo serdecznie jej podziękować. 

```
Paulina wyszło to super! Dziękuję :)
```

## English

### Application description
WorkTimer is a simple timer application. The project was created with the thought of taking regular breaks from the computer at work and every day. The app currently has three possible countdown points: `15`, `30` and `45 minutes`. When starting the application, the user is taken to the welcome screen. After a few seconds, the user goes to the menu screen with the following options:
- set countdown
- information
- Exit 

##### Set the countdown
After selecting this option, three more options will appear on the screen: `15 minutes`,` 30 minutes` and `45 minutes`. These are the aforementioned constants that he can choose to start counting down. After selecting one of the options, the user is taken to the countdown screen, where he can: start the countdown, then stop it and resume it.

##### Information
When you select this option from the menu, abbreviated information about the application and the names of the creators are displayed on the screen.

Each of the above-mentioned screens has a `Back` button, which allows you to return to the previously displayed screen. There is an `Exit` button on the menu screen which allows you to close the application. After closing the application, a special screen says goodbye to user.

At the moment, the application is entirely in Polish.

### How to run
The project was created using Visual Studio Code. All graphic aspects of the application have been achieved thanks to the library `SFML 2.5.1 64 bit version`. The application was compiled with the compiler `g ++ 7.3.0. in the 64 bit version`.

In order to build a project, use the Makefile file and use the following command:
```
mingw32-make
```
or
```
mingw32-make all
```

In order to build a debugable version, use the command:
```
mingw32-make debug
```

#### Remaining commands
Clears all obj files:
```
mingw32-make clean
```

Clears all obj files and additionally removes dependencies between files:
```
mingw32-make deepClean
```

Completely deletes the folder with the built project files:
```
mingw32-make allClean
```

Clears the obj files and rebuilds the project:
```
mingw32-make rebuild
```

##### Notes
All of these commands work only in bash. When you try to run them in a regular console on Windows, the project doesn't build correctly!

All built files go to the bin foler. It contains, respectively: dependency files and folders: debug and release.

### Creator's Notes
If you have any suggestions on what could be improved or fixed, if you see any bugs, feel free to write. Any comments and tips are appreciated. Thanks to this, we are constantly developing.

### Thanks
All backgrounds used in the application for all screens have been created as an expression of admiration for the wonderful animal which is the `black Figaro cat :)`. All graphics were made by my dear friend `Paulina`. Were it not for her input and commitment, the design would not look so good from an aesthetic point of view. From this place I would like to thank her very much.

```
Paulina it turned out great! Thank you :)
```