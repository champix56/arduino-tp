void setup()
{
    // définition du mode de l'I/O
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
}

void loop()
{
    // lecture de l'état de l'entrée
    bool isD3Pushed = digitalRead(3);
    if (isD3Pushed)
    {
        digitalWrite(2, HIGH);
    }
    else
    {
        digitalWrite(2, LOW);
    }
}