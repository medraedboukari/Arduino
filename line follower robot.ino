// Définir les broches des capteurs
const int sensorPins[5] = {A0, A1, A2, A3, A4};

// Définir les broches des moteurs
const int enA = 9;
const int in1 = 2;
const int in2 = 3;
const int enB = 10;
const int in3 = 4;
const int in4 = 5;

// Seuil de détection pour les capteurs
const int threshold = 500;

void setup() {
  // Initialiser la communication série pour le débogage
  Serial.begin(9600);

  // Initialiser les broches des moteurs comme sorties
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Lire les valeurs des cinq capteurs
  int sensorValues[5];
  for (int i = 0; i < 5; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Afficher les valeurs lues dans le moniteur série
  Serial.print("Valeurs des capteurs: ");
  for (int i = 0; i < 5; i++) {
    Serial.print(sensorValues[i]);
    if (i < 4) {
      Serial.print(", ");
    }
  }
  Serial.println();

  // Logique de suivi de ligne
  if (sensorValues[2] > threshold) {
    // Avancer
    forward();
  } else if (sensorValues[1] > threshold) {
    // Tourner légèrement à gauche
    turnLeftSlightly();
  } else if (sensorValues[3] > threshold) {
    // Tourner légèrement à droite
    turnRightSlightly();
  } else if (sensorValues[0] > threshold) {
    // Tourner fortement à gauche
    turnLeft();
  } else if (sensorValues[4] > threshold) {
    // Tourner fortement à droite
    turnRight();
  } else {
    // Arrêter
    stop();
  }

  // Attendre 100 ms avant la prochaine lecture
  delay(100);
}

// Fonctions pour contrôler les moteurs
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void turnLeftSlightly() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void turnRightSlightly() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
}

void turnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}
