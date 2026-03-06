# 🤖 Robô de Sumô Autônomo

Projeto de desenvolvimento de um **robô de sumô autônomo**, programado em **C++** utilizando a **Arduino IDE**.
O robô foi projetado para detectar o oponente dentro da arena e empurrá-lo para fora, ao mesmo tempo em que evita ultrapassar os limites da arena utilizando sensores de linha.

---

# 🎯 Objetivo do Projeto

O objetivo deste projeto foi aplicar conhecimentos de:

* Eletrônica
* Programação embarcada
* Sistemas embarcados
* Robótica
* Integração entre hardware e software

O robô foi desenvolvido para operar de forma **totalmente autônoma**, tomando decisões com base nas leituras dos sensores.

---

# ⚙️ Componentes Utilizados

* 1 Arduino Uno
* 2 Pontes H L298N
* 4 Motores DC
* 4 Rodas
* 2 Sensores infravermelhos (detecção da linha da arena)
* 1 Sensor ultrassônico
* 1 Mini protoboard
* 1 Bateria de 12V
* Fios jumpers diversos

---

# 🧠 Funcionamento do Robô

O robô opera seguindo a seguinte lógica:

1. O **sensor ultrassônico** detecta a presença de um oponente.
2. Quando o oponente é detectado, o robô **avança para atacar**.
3. Os **sensores infravermelhos** monitoram constantemente a borda da arena.
4. Caso o robô detecte a linha da arena, ele **recua e muda de direção** para evitar sair da área de combate.
5. Se nenhum oponente for detectado, o robô **gira procurando adversários**.

---

# 💻 Tecnologias Utilizadas

* C++
* Arduino IDE
* Programação de sistemas embarcados

---

# 📁 Estrutura do Projeto

```
robo-sumo/
│
├── RoboSumo.ino
├── README.md
└── imagens/
```
