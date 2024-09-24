#define POTENCIOMETRO A0

const int PinTrig = 9;
const int PinEcho = 10;
const int alarma = 12;

long distancia;
long tiempo;
int lecturaPotenciometro;

const long maximaDistanciaSegura = 35;
const long minimaDistanciaSegura = 300;

void setup(){
  Serial.begin(9600);

  pinMode(PinTrig, OUTPUT);
  pinMode(PinEcho, INPUT);
  pinMode(alarma,OUTPUT);
}

void loop(){
  iniciarTrigger();

  lecturaPotenciometro = analogRead(POTENCIOMETRO); // Convierte la lectura analogica (0 - 1023) en voltaje (0 - 5v)

  tiempo = pulseIn(PinEcho, HIGH);
  distancia = tiempo * 0.034/2;

  // Logica del controlador
  if (distancia < minimaDistanciaSegura && distancia > maximaDistanciaSegura){
	digitalWrite(alarma, LOW);
  } else {
  	digitalWrite(alarma, HIGH);
  }

  delay(1000);
}

void iniciarTrigger(){
  digitalWrite(PinTrig, LOW);
  delayMicroseconds(2);

  digitalWrite(PinTrig, HIGH);
  delayMicroseconds(10);

  digitalWrite(PinTrig,LOW);
}
