#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32,16,2);

int Hora = A0; // Fotoresistor
int Bo1 = 2; // Janela
int Bo2 = 3; // Porta
int Sen = A1; // Sensor
int Led = 13; // Led
int Alr = 9; // Alarme
void setup()
{
  lcd.begin(16,2); // Inicia LCD
  lcd.backlight(); // Inicia Luzes de Fundo
  lcd.init(); // Inica LCD
  lcd.clear(); // Limpa LCD
  pinMode (Bo1,INPUT); // Definde entrada
  pinMode (Bo2,INPUT); // Definde entrada
  pinMode (Alr,OUTPUT); // Define saida
  pinMode (Led, OUTPUT); // Define saida
}

void loop()
{
  Hora = analogRead (A0);
  Bo1 = digitalRead (2);
  Bo2 = digitalRead (3);
  Sen = analogRead (A1);
  if (Hora >= 500) {
    if (Bo1 == 1 && Bo2 == 1 && Sen == 0) {
    lcd.setCursor (1,0);
    lcd.print ("Status: Ligado");
    lcd.setCursor (2,1);
    lcd.print ("Seguranca On");
    delay (2000);
    lcd.clear ();
   }
   if (Bo1 == 0) {
    lcd.clear();
    digitalWrite (Led, HIGH);
    tone (Alr, 1600, 1500) ;
    lcd.setCursor (0,0);
    lcd.print ("Status: Perigo");
    lcd.setCursor (0,1);
    lcd.print ("Portas Abertas ");
    delay(1500);
    digitalWrite (Led, LOW);
    lcd.clear();
    delay(500);
   } else {
    digitalWrite (Led, LOW) ; }
   if (Bo2 == 0) {
    lcd.clear();
    digitalWrite (Led, HIGH);
    tone (Alr, 1800, 1500) ;
    lcd.setCursor (0,0);
    lcd.print ("Status: Perigo");
    lcd.setCursor (0,1);
    lcd.print ("Janelas Abertas");
    delay(1500);
    digitalWrite (Led, LOW);
    lcd.clear();
    delay(500);
   } else {
    digitalWrite (Led, LOW) ; }
   if (Sen > 1) {
    lcd.clear();
    digitalWrite (Led, HIGH);
    tone (Alr, 2000, 1500) ;
    lcd.setCursor (0,0);
    lcd.print ("Status: Perigo");
    lcd.setCursor (0,1);
    lcd.print ("Movimento");
    delay(1500);
    digitalWrite (Led, LOW);
    lcd.clear();
    delay(500);
   } else {
    digitalWrite (Led, LOW) ; }
   } else {
    lcd.setCursor (1,0);
    lcd.print ("Status: Ligado");
    lcd.setCursor (1,1);
    lcd.print ("Aguardando 18h ");
    delay (2000);
    lcd.clear ();
  }
}
