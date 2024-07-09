// Pins des LEDs
const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;

void setup() {
  // Initialisation des broches des LEDs en sortie
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Premier scénario : toutes les LEDs allumées comme feux de route
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(2000);  // Attendre 2 secondes

  // Deuxième scénario : seule la première LED allumée (feu de route à gauche)
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(1000);  // Attendre 1 seconde

  // Troisième scénario : seule la troisième LED allumée (feu de route à droite)
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  delay(1000);  // Attendre 1 seconde

  // Quatrième scénario : toutes les LEDs éteintes
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(1000);  // Attendre 1 seconde
}
