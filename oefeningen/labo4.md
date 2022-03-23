### /etc/passwd

- uid: unieke identiefier van de user
- gid: id van primaire groep waartoe de user behoort
- GECOS

**Interactieve gebruiker**

user:x:uid:gid:GECOS:homedir:/bin/bash

**Niet interactieve gebruiker**

user:x:uid:gid:GECOS:homedir:/sbin/nologin

### /etc/group

naam:x:gid:secundaire leden

### /etc/shadow

Houdt per gebruiker het geëncrypteerde wachtwoord bij.

## 43.

```
sort -t : -k4,4 /etc/passwd | less
sort -t : -k4,4 /etc/passwd > passwd
```
- -t field separator
- -k sort via a given key (column)


```
sort -d -t : -k3,3 /etc/group > group
```

## 44.

```
join -t : -1 4 -2 3 -o "1.3 1.1 2.1" passwd group
```

join -t : -1 4 -2 3 -o "1.3 1.1 2.1" <(sort -t : -k4,4 /etc/passwd) <(sort -d -t : -k3,3 /etc/group)


## 45.

```
sort -n -t : -k4,4 /etc/passwd | less
```

```
sort -t : -k4n,4n -k5rf,5rf /etc/passwd
```

## 46.

```
cut -d : -f 1 /etc/passwd
```

## 47.

Dit zal de tail van invoer volgen en nieuwe lijnen doorsluizen naar het tee commando, vervolgens zal tee dit op het scherm tonen en in het bestand out wegschrijven.
```
tail -f invoer | tee out
```

Dit zal een nieuwe lijn toevoegen aan invoer. Automatisch zal deze lijn in de andere terminal op het scherm verschijnen en weggeschreven worden in het `out` bestand.
```
echo "Nieuwe lijn" >> invoer
```
> Doe dit in een nieuwe terminal.

cut -d : -f 1 /etc/passwd | tee -f out

## 48.

```
find /etc -name "pass*" -type f
```

## 49.

```
find / -name "sh*" -type d
```

## 50.

```
find /usr -size +1M -type f -exec du -h '{}' \;

find /usr -size +1M -type f -exec du -h '{}' \+
```
> + zal alle bestanden appenden en meegeven aan het commando `du` dit zorgt voor veel minder child processen.

```
find /usr -size +1M -type f -printf "%s %p\n";
```

## 51.

```
find ~ -type f -mtime -14 -printf "%t %p\n";
```

## 52.

```
find /usr -name "*.h" -printf "%h\n" | sort | uniq
```
- uniq -d geeft alleen duplicaten
- uniq -u geeft alleen unieke lijnen
- uniq zonder -d of -d geeft duplicaten en unieke lijnen

## 53. 

```
useradd jarno
su - jarno
find / -type d 2>&1 > /dev/null | cut -d ‘ -f 2 | cut -d ’ -f 1
```

## 54.

```
find /etc
```
