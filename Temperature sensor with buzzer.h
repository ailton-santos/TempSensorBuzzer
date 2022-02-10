Temperature sensor with buzzer
  
const int LM35 = 0; // entrada sensor no Arduino: A0 - Analógica
int temperatura = 0; // variável tipo float - inícia no 0
int ADClido = 0;
const int Buzzer = 12; // entrada buzzer: 12 - digital
const int Led10 = 10; // entrada led: 10 - digital
  
void setup(){
Serial.begin(9600); // taxa comunicação da placa com o computador
pinMode(Buzzer, OUTPUT);
pinMode(Led10, OUTPUT);
}
  
void loop(){
ADClido = analogRead(LM35);
temperatura = ADClido*110/1023;
Serial.print("Temperatura = "); //mostra valor na tela
Serial.print(temperatura);
Serial.println(" *C");
    
if(temperatura > 30){ // setado como 30ºC
digitalWrite(Buzzer, HIGH); //aciona o buzzer
digitalWrite(Led10, HIGH);  //aciona o led
}
else{
digitalWrite(Buzzer, LOW);
digitalWrite(Led10, LOW);
}
delay(500);
}