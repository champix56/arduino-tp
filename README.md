# arduino-tp
cahier de tp pour le cours arduino

## Composants necessaires

- arduino uno
- 1x led
- 1x push button
- 2x resistance 1k&ohm;

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

# Projet 2

Lecture numérique TOR sans gestion d'interruption, et écriture en fonction de l'état de l'entrée

# 2. Enoncé

Lire l'état d'un bouton et allumer une diode en fonction du bouton

## 2.1. Composants

- arduino uno
- 1x push button
- 1x led
- 2x résistances

## 2.2. Code

fichier source : *projets/tp2/tp2.ino*

~~~c
    void setup() {
        //définition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
    }

    void loop() {
        //lecture de l'état de l'entrée
        bool isD3Pushed=digitalRead(3);
        if(isD3Pushed){
            digitalWrite(2, HIGH);
        }
        else {
            digitalWrite(2, LOW);
        }
    }
~~~

### 2.2.1. **digitalRead(*IOPin*)**

Lecture d'état numérique HAUT ou BAS simple sur une entrée numérique (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)

## 2.3. Montage

fichier fritzing : *projets/tp2/projet.fzz*

![projet 2](img/projet2.png)

----------

# Projet 3

Découverte de la liaison série *HardwareSerial*.

Ecriture vers le port série matériel

## 3. Enoncé

- récupérer et stocker l'état d'allumage
- stocker & modifier l'état d'allumage uniquement lors d’un nouveau click sur le bouton
- afficher l'état d'allumage en cas de changement

## 3.1. composants

- arduino uno
- 1x push button
- 1x led
- 2x résistances

## 3.2. code

fichier source : *projets/tp3/tp3.ino*

~~~c
    bool ledState = false;
    void setup()
    {
        // définition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
        digitalWrite(2, ledState);

        // def. de la vitesse du port série
        Serial.begin(9600);

        //Ecriture sans retour chariot
        Serial.print("Projet 3");
        
        //Ecriture avec retour chariot
        Serial.println(" écriture série");
    }

    void loop()
    {
        // lecture de l'état de l'entrée
        bool isD3Pushed = digitalRead(3);
        if (isD3Pushed)
        {
            //Ecriture avec retour chariot 
            Serial.println("button enfoncé");
            
            ledState=!ledState;

            //écriture du nouvel état d'allumage
            Serial.print("Etat d'allumage : ");
            Serial.println(ledState);

            //attente du relâchement du button avant nouveau cycle de loop
            delay(800);
        }
         digitalWrite(2, ledState);
    }
~~~

### 3.2.1 **Serial.begin(*serialSpeed*)**

Instanciation de l'objet ***Serial*** et ouverture du port série et def. de la vitesse de transmission.

- *serialSpeed*
  
  Vitesse en bits/sec (bauds)
  
  >- 300, 1200, 2400, 4800, **9600**, 19200, 38400, **57600**, **115200** : valeurs admises. les valeurs en gras (**9600, 57600, 115200**) sont des valeurs standard fortement utilisées

### 3.2.2 **Serial.print(*printableValue*) / Serial.println(*printableValue*)**

Ecriture de contenu vers la sortie série. **Serial.println** ajoute un saut de ligne en fin d'impression de contenu vers la sortie

- *printableValue*
    Contenu imprimable à diffuser de n'importe quel type de données
    >
    >- "const char" : chaine de caractère constante
    >- 123 ou 123.45 : entier ou float
    >- *varName* : variable de tous types. les chaines de **char** doivent finir par le caractère **'\0'**

### 3.3. montage

fichier fritzing : *projets/tp3/projet3.fzz*

![alt](img/projet2.png)

### 3.4. doc officiel

- **HarwareSerial**
  [https://www.arduino.cc/reference/en/language/functions/communication/serial/](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
  
  - *Serial.begin*
  [https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/)
  
  - *Serial.println*
  [https://www.arduino.cc/reference/en/language/functions/communication/serial/println/](https://www.arduino.cc/reference/en/language/functions/communication/serial/println/)
  
  - *Serial.print*
  [https://www.arduino.cc/reference/en/language/functions/communication/serial/print/](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/)

----------
