/********
   ohmmetre

  ------+---vIn
        |
       [R2] ???Ohm
        |
        +--- vOut (A3)
        |
       [R1] 2.2KOhm
        |
  ------+---GND
*/
#define CANPIN A3
float R1 = 2200.0F;
float VIN = 5.0F;
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    // recuperrer la tensions aux bornes de R2
    int canValue = analogRead(CANPIN);
    // tension en A3
    float vOut = canValue * (VIN / 1024);
    // calcul:
    // vOut=(R1/(R1+R2)) * VIN
    // r2=R1 * ( VIN / vOut) -R1
    float r2 = R1 * (VIN / vOut) - R1;
    Serial.print("Res : ");
    Serial.println(r2);
    delay(1000);
}