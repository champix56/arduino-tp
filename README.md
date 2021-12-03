# arduino-tp
cahier de tp pour le cours arduino

## Composants necessaires

- arduino uno
- 1x led

# Arduino_tp_list

# Projet 0

Découverte du code arduino minimum

## 0.1. Composants

- Aucun

## 0.2. code

~~~c
    void setup(){
        //code exécuter au départ de l'exécution du code
    }
    void loop(){
        //boucle d'exécution infinie 
    }
~~~

### 0.2.1. ***void setup ()***

>**fonction obligatoire** pour l'appel de tous les   >constructeurs d'instances diverses.
>
>cette fonction est exécutée une seul fois au démarrage de la puce

### 0.2.2 ***void loop()***

>**fonction obligatoire** exécuter en boucle lorsque la puce est allumée. Cette fonction commence à être exécutée qu’une fois le setup achevé

----------

# projet 1 : clignotement d'une LED

Découverte des sorties *Tout Ou Rien*.

## 1. Enoncé

Clignotement continue d'une diode électroluminescente

## 1.1. composants

- arduino uno
- 1x LED
- une résistance *(*facultatif)*

## 1.2. Code

fichier source : *projets/tp1/tp1.ino*

~~~c

    void setup() {
        //définition du mode de l'I/O
        pinMode(2, OUTPUT);
    }

    void loop() {
        //écriture sur le port
        digitalWrite(2, HIGH);
        delay(750);
        digitalWrite(2, LOW);
        delay(750);
    }
~~~

### 1.2.1 ***pinMode(*IOPin*, *digitalValue*)***

Def. du type d'usage d'un port numérique. Cette fonction permet de fixer des résistances à VCC ou GND

- #### *IOPin*

  - Valeur ou nom de l'entrée
    >
    >- 1, 2, ..., 13 : pour les ports digitaux
    >- A0, A1, ..., A5 : pour les ports digitaux. attention certaines cartes possèdent 2 ports CAN en plus (A6 / A7)

- #### *digitalValue*

  - Def. des PULLUP / PULLDOWN res sur les entrées / sorties :
    >
    >- OUTPUT : PULLUP résistance interne sur VCC
    >- INPUT  : PULLDOWN résistance interne sur GND

### 1.2.2. **digitalWrite(*IOPin*, *digitalValue*)**

Ecriture état numérique HAUT ou BAS *simple et constant ou remplissage cyclique PWM* sur une sortie digitale (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)
  
- *digitalValue*
  - Valeur à écrire sur le port : {#digital-value}
    >
    >- HIGH / LOW : état fixe et constant
    >- 0, 25, ..., 254, 255 : état de remplissage de cycle PWM, remplissage continu (sur les ports compatibles uniquement indiqués par '~' )

## 1.3. Montage

fichier fritzing : projets/tp1/projet1.fzz

![projet 1](./img/projet1.png)

----------
