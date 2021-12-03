bool ledState = false;
void setup()
{
    // définition du mode de l'I/O
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
    digitalWrite(2, ledState);

    // def. de la vitesse du port série
    Serial.begin(9600);

    // Ecriture sans retour chariot
    Serial.print("Projet 3");

    // Ecriture avec retour chariot
    Serial.println(" écriture série");
}

void loop()
{
    // lecture de l'état de l'entrée
    bool isD3Pushed = digitalRead(3);
    if (isD3Pushed)
    {
        // Ecriture avec retour chariot
        Serial.println("button enfoncé");

        ledState = !ledState;

        //écriture du nouvel état d'allumage
        Serial.print("Etat d'allumage : ");
        Serial.println(ledState);

        // attente du relâchement du button avant nouveau cycle de loop
        delay(800);
    }
    digitalWrite(2, ledState);
}
