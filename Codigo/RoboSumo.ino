CÓDIGO FINAL: // --- BIBLIOTECAS ---
#include <Ultrasonic.h>

// --- DEFINIÇÕES DE PINOS ---
// Módulo Ponte H 1
#define IN1_1 13
#define IN2_1 12
#define IN3_1 9
#define IN4_1 8
#define ENA1 10
#define ENB1 11

// Módulo Ponte H 2
#define IN1_2 7
#define IN2_2 4
#define IN3_2 3
#define IN4_2 2
#define ENA2 5
#define ENB2 6

// Sensor ultrassônico
#define trigPin A5
#define echoPin A4

// Sensores de linha (infravermelho)
#define sensorFrente A2
#define sensorTras A3

int velocidade = 140;

// --- FUNÇÕES ---
void setVelocidadeMotores(int v) {
  analogWrite(ENA1, v);
  analogWrite(ENB1, v);
  analogWrite(ENA2, v);
  analogWrite(ENB2, v);
}

void frente() {
  digitalWrite(IN1_1, HIGH); digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, HIGH); digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, HIGH); digitalWrite(IN4_2, LOW);
  setVelocidadeMotores(velocidade);
  delay(300);
}

void tras() {
  digitalWrite(IN1_1, LOW);  digitalWrite(IN2_1, HIGH);
  digitalWrite(IN3_1, LOW);  digitalWrite(IN4_1, HIGH);
  digitalWrite(IN1_2, HIGH); digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW);  digitalWrite(IN4_2, HIGH);
  setVelocidadeMotores(velocidade);
}

void esquerda() {
  digitalWrite(IN1_1, LOW);  digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW);  digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW);  digitalWrite(IN2_2, HIGH);
  digitalWrite(IN3_2, HIGH); digitalWrite(IN4_2, LOW);
  setVelocidadeMotores(velocidade);
}

void parada() {
  digitalWrite(IN1_1, LOW); digitalWrite(IN2_1, LOW);
  digitalWrite(IN3_1, LOW); digitalWrite(IN4_1, LOW);
  digitalWrite(IN1_2, LOW); digitalWrite(IN2_2, LOW);
  digitalWrite(IN3_2, LOW); digitalWrite(IN4_2, LOW);
  setVelocidadeMotores(0);
}

long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH, 10000); // Timeout 10ms (~170cm)
  if (duracao == 0) return -1; // Sem retorno
  return (duracao * 0.034) / 2;
}

// --- SETUP ---
void setup() {
  delay(5000); // Espera antes da luta começar

  int motorPins[] = {IN1_1, IN2_1, IN3_1, IN4_1, ENA1, ENB1, IN1_2, IN2_2, IN3_2, IN4_2, ENA2, ENB2};
  for (int i = 0; i < 12; i++) pinMode(motorPins[i], OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensorFrente, INPUT);
  pinMode(sensorTras, INPUT);

  Serial.begin(9600);
}

// --- LOOP ---
void loop() {
  long distancia = medirDistancia();
  int linhaFrente = digitalRead(sensorFrente); // LOW = linha detectada
  int linhaTras = digitalRead(sensorTras);

  Serial.print("Distância: "); Serial.println(distancia);
  Serial.print("Frente: "); Serial.println(linhaFrente);
  Serial.print("Trás: "); Serial.println(linhaTras);
  delay(100);

 /* if (linhaFrente == LOW) {
    Serial.print("Frente: ligando "); Serial.println(linhaFrente);
    tras();
    delay(400);
    esquerda();
    delay(300);
  }*/
  if (linhaTras == LOW) {
    frente();
    delay(200);
    esquerda();
    delay(150);
  }
  else if (distancia > 0 && distancia < 40) {
    frente(); // Inimigo detectado
  }
  else {
    parada();
    delay(150);
    esquerda(); // Gira procurando oponente
  }
}