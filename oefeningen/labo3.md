# Labo 3

Uitvoerkanaal 1 is wel gebufferd

Uitvoerkanaal 2 is niet gebufferd

```c
#include <stdio.h>

int main() {
    fprintf(stderr, "Hello ");
    printf(" oei ");
    fprintf(stderr, "World!");
    return 0;
}
```

```
Hello World! oei
```

> Je gaat eerst de niet gebufferde opdrachten uitvoeren en dan pas de gebufferde opdrachten.

```c
#include <stdio.h>

int main() {
    fprintf(stderr, "Hello ");
    printf(" oei \n");
    fprintf(stderr, "World!");
    return 0;
}
```

```
Hello  oei 
World!
```

> Newline teken flusht de buffer dus als je een \n toevoegd aan " oei " dan zal oei nu wel voor "World!" worden uitgevoerd.

## 23. Verwijder de werkbestanden tmp*.txt, indien die reeds zouden bestaan. Voer hiertoe het commando `rm -f tmp*.txt` uit. Voer daarna achtereenvolgens deze opdrachten uit:

```
du /etc
du /var > tmp.txt
du /etc 1> tmp.txt
du /var >> tmp.txt
du /etc 1>> tmp.txt
> tmp.txt du /etc
du /var > tmp1.txt > tmp2.txt
```

>`> tmp.txt du /etc` dit zal de uitvoer van du /etc overschrijven in het tmp.txt bestand.

> \> Zal wat er in het bestand overschrijven.

> \>> Zal wat er in het bestand niet overschrijven en gewoon het gene wat je meegaf achteraan toevoegen.

> `du /var > tmp1.txt > tmp2.txt` schrijft de inhoud van du /var weg naar het laatste bestand 


> `du /etc | tee temp4.txt > temp3.txt > temp5.txt` zal wegschrijven naar temp4.txt en temp5.txt maar niet naar temp3.txt

## 24.

```
set -o noclobber
set -C
```

```
[root@localhost labos]# set -o noclobber
[root@localhost labos]# echo test > tmp.txt
[root@localhost labos]# echo test > tmp.txt
bash: tmp.txt: cannot overwrite existing file
```


```
[root@localhost labos]# set -C
[root@localhost labos]# echo test > tmp.txt
[root@localhost labos]# echo test > tmp.txt
bash: tmp.txt: cannot overwrite existing file
```

> Zal ervoor zorgen dat je een bestaande file niet meer kunt overschijven met `>`. Wil je dit toch doen kan je gebruik maken van `>|`.

## 25. Foutmeldingen worden via een apart kanaal weergegeven, zodat er onderscheid gemaakt kan worden tussen gewone uitvoer en foutteksten. Voer achtereenvolgens volgende commando's uit en controleer de inhoud van het bestanden tmp* txt:

- du /etc  
- du /etc 1> tmp.txt  
- du /etc 2>> tmp.txt
> Wanneer men gebruik maakt van `2>>` zal de inhoud alleen naar het scherm geschreven worden maar niet naar het bestand buiten de errors, deze worden wel in het bestand weggeschreven.

- du /etc >tmp1.txt 2> tmp2.txt

> Hier zal de inhoud in tmp1.txt belanden maar niet in tmp2.txt omdat we daar de foutuitvoer descriptor gebruiken. In tmp2.txt zullen de errors terecht komen.


## 26. Je kunt ook omleiden naar de vuilnisbak (/dev/null). Verklaar de uitvoer bij uitvoering van volgende opdrachten:

- du /etc > /dev/null  
- cat /dev/null

> Alles wat je naar /dev/null stuurt wordt gewoon weg gegooid.

> /dev/null is altijd leeg.

## 27. Ga na wat het effect is van cat /dev/null > test.txt

```
cat /dev/null > test.txt
```

> Zal het bestand leegmaken

## 28. Veronderstel dat een of ander programma continu informatie wegschrijft in een logbestand (dat hierdoor onbeperkt en continu in grootte toeneemt), en dat niemand geïnteresseerd is in dit logbestand. Hoe kun je vermijden dat je periodiek het bestand moet legen of verwijderen?

Maak symlink van je output bestand naar /dev/null

ln -s /dev/null datums


## 29.

```
du /etc >tmp.txt 2>&1
```

> Alles zal file descriptor 1 gebruiken, 2 wordt naar 1 geredirect als het ware. Alles belandt in het bestand.

```
du /etc 2>&1 >tmp.txt 
```

> Fouten zullen ook naar de standaarduitvoer gebuffered worden. Je zal de fouten nog steeds op het scherm zien.

Alleen gebufferde uitvoer gaat door een pipe maar niet gebufferde uitvoer zal niet door een pipe gaan.

du /proc 2>&1 /dev/null | less

> Hier zal je in kunnen scrollen

strace 2>&1 ls -l | less

> We maken van niet gebufferde uitvoer, gebufferde uitvoer.


```
1 -> gebufferd           |       ------      |       ------
2 -> niet gebufferd      |       ------      |       ------

        eerste kind            tweede kind         derde kind
                         ^                   ^
                         |                   |
                Inter process communicatie d.m.v. pipe
```

Enkel de gebufferde uitvoer wordt doorgesluisd naar het volgende kind.

```
ls /proc                    |   2>&1                    | > t.txt
1 -> scherm gebufferd       | 1 -> scherm gebufferd     | 1 -> t.txt
2 -> scherm niet gebufferd  | 2 -> scherm gebufferd     | 2 -> scherm gebufferd
```


## 30.
() is in een kind proces, maakt een nieuwe shell aan

```
$ (var=7)
$ echo $var

```

> Zal niets naar het scherm schrijven

{} is in huidige shell

```
$ { var=7; }
$ echo $var
7
```

> Zal var naar het scherm schrijven


Clear zal ook een kind proces aanmaken.


## 31.

```
$ printf "Dit is fout" 1>&2 | wc -w
Dit is fout0
```
We maken van gebufferde uitvoer niet gebufferde uitvoer.

## 32.

```
du /proc 2>&1 > /dev/null | wc -l
```

> We maken van 2, gebufferde uitvoer die in null komt en de errors komen bij de pipe terecht doordat dit gebufferde uitvoer is geworden.

## 33.

```
head -n 3 /etc/passwd | tail -n 1
```

## 34.
Windows sluit lijnen op deze manier af:
---------\r\n
-----------\r\n
--------\r\n

r = carrage return -> terug naar begin
n = newline -> naar volgende line

Unix sluit lijnen op deze manier af:
-------\n
----------\n
-------\n

```
tr -d '\r' < test.txt
```
> Verwijder \r in het bestand test.txt


```
tr -d '\r' < test.txt > test2.txt
```

> Schrijf het resultaat weg naar een ander bestand.


wc -c test*.txt

> Print bytes van beide files. Je zal zien dat het DOS bestand 1 byte meer zal hebben doordat daar een carrage return in staat.

## 35.

uniq kijkt alleen naar opeenvolgende lijnen die hetzelfde zijn anders zou het heel veel werk zijn.

Doormiddel van sort kunnen we ze alfabetisch sorteren.

```
sort -d bestand.txt | uniq -d
```
