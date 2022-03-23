# Labo 2

## 1. Met welk commando kan je x aantal bestanden aanmaken waarvan de namen als parameters van het commando worden opgegeven?


```
$ touch filename.txt main.c
```

Je misbruikt eigenlijk `touch` want touch wordt gebruikt om de timestamp aan te passen van een bestand.

Maar wanneer de opgegeven file niet aanwezig is zal het commando touch automatisch een nieuwe bestand aanmaken met de opgegeven naam.


> `ll`, lichtblauw is een symlink. Rechten die je ziet zijn van toepassing op het bestand/map waarnaar het wijst.

### Hardlink

Hardlink: aan dezelfde inode een 2de naam gaan koppelen, een naam toevoegen diewijst naar dezelfde inode, de datablokken blijven gewoon staan. Er wordt niets gekopieerd.

```
$ ll /etc/passwd

-rw-r--r--. 1 root root 2546 Feb 25 2021 /etc/passwd
```

1 is het aantal hardlink's.

Dit toont de inode.

```
$ ls -i /etc/passwd

151064 -rw-r--r--. 1 root root 2564 Feb 25  2021 /etc/passwd
```
151064 is de inode id.

Hardlink leggen naar een map zal niet lukken. We zouden hier oneindige lussen aanmaken waardoor het commando `find` hier oneindig zou heen en weer gaan.

### Symlink

Met een symlink maak je een nieuwe inode aan met daarin de naam waar naartoe het moet wijzen.

Hardlink kost niets extra, je hebt geen extra resources nodig. Bij een symlink wel want dan wordt er een nieuwe inode aangemaakt.


## 2.

```
$ head /etc/passwd
```

Geeft 10 eerste lijnen weer van de file passwd.

```
$ tail /etc/passwd
```

Geeft 10 laatste lijnen weer van de file passwd.

Om steeds de laatste lijnen van een bestand te tonen wanneer een ander proces lijnen toevoegd, doet men aan de hand van de `-f` flag mee te geven, dit staat voor follow.

```
$ tail lijnen.txt -f
```

```
$ echo "Nog een nieuwe lijn" >> lijnen.txt
```

Dit zal een nieuwe lijn toevoegen aan lijnen.txt en zal je live zien waar je het commando `tail lijnen.txt -f` hebt gedaan.

### 3. Waarvoor dient de optie -rf bij de opdracht rm?

-r, --recursive; remove directories and their contents recursively

-f, --force; ignore nonexistent files and arguments, never prompt

-- dit wil zeggen end op options

### 4.
```
$ wc -c /etc/passwd

2564 /etc/passwd
```

```
$ wc -c < /etc/passwd

2564
```

Door gebruik te maken van `<` zullen we enkel het getal terugkrijgen.



Oneindige while lus

while : ;do : ; done

I.p.v. `:` true gebruiken is een slecht idee want dan gebruiken we een extern programma.

### 6.

`sync` buffers leegmaken.



--------------------------------

udevadm monitor


### 7.
lsblk

Je kan ook een afbeelding maken van de usb met cat 
```
$ /dev/sdb1 > file.img
```

### 8.

Kopie maken van de eerste 512 bytes naar een image bestand

```
$ head -c 512 /dev/sda > mbr.img
```

```
$ dd if=/dev/sda of=mbr2.img bs=512 count=1
```

md5sum zal een hash genereren.

```
$ md5sum mbr.img mbr2.img
```
> Je zal zien dat beide hashes normaal hetzelfde zullen zijn.

```
$ strings mbr2.img
```

Dit zal de inhoud van de img file mounten in je bestandsysteem op /mnt.

```
$ mount usb.img /mnt
```

Je kan dus zowel hardware (USB pen) als software(.img file) mounten.

### 9.

-1 minder dan 24 uur geleden
+1 meer dan 24 uur geleden

```
$ find -mtime -1
```

```
$ find / -type f -mtime -1
```

### 10.

### 11.

### 12.

```
$ find / -name pas*
```
Je wilt het sterretjes meegeven aan find en niet aan bash

> Is op een examen niets waard

Echo interessant als je niets wilt formateren

Printf ga je wrs wel formateren

Brace expansion

Schrijf alle hexadecimale shizzle

```
echo {{0..9},{a..f}}{{0..9},{a..f}}
```