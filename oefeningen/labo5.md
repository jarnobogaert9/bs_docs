## 55.

$PATH

> Hier (lijst van mappen) ga je zoeken naar commando's die je wilt uitvoeren.

## 56.

date="23/3/2022" 

```
echo '$date:' $date
$date: 23/03/2022
```

> Print gewoon de string, enkele quotes zal de string letterlijk overnemen.

```
echo '${date}:' ${date}
${date}: 23/03/2022
```
> Voert ook gwn letterlijk uit

```
echo '$(date):' $(date)
${date}: Wed Mar 23 01:52:54 PM CET 2022
```
> Voert de functie date uit in het laatste argument

## 57.

```
een=1

twee=een
```

```
echo ${een}
1
```

```
echo ${twee}
een
```

```
echo ${!twee}
1
```
> ! zelfde als * in C, je zal in dit geval niet de waarde `een` printen maar de waarde naarwaar `een ` wijst en dat is `1`. Dit komt omdat `een` een shell variabele is.

```
echo ${$twee}
bash: ${$twee}: bad substitution
```

## 58.

