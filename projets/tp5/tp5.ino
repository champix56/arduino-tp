void setup()
{
    // def. de la vitesse du port série
    Serial.begin(9600);

    // Ecriture sans retour chariot
    Serial.println("Projet 5");
}

void loop()
{
    uint8_t potValue = analogRead(A1);
    analogWrite(A0, potValue);

    float voltValue = (5 / 1024) * potValue;
    Serial.print("Valeur de tension : ");
    Serial.print(voltValue);
    Serial.print("V");
}