#define CLEAR 0  // built-in led & clear function pin
#define SER 2    // serial data pin
#define CLK 3    // shift clock & storage register clock pin
#define GAP 100  // half-period of data clock signal in milliseconds


void pulse(int times, int ms) {
  for (int i = 0; i < times; ++i) {
    digitalWrite(CLK, HIGH);
    delay(ms);
    digitalWrite(CLK, LOW);
    delay(ms);
  }
}

// Each byte defines a character
int serialValues[16][8] = {
  { 0, 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 0, 0, 1, 1, 0, 0, 0 },  // 1
  { 1, 0, 1, 1, 0, 1, 1, 0 },  // 2
  { 1, 0, 1, 1, 1, 1, 0, 0 },  // 3
  { 1, 1, 0, 1, 1, 0, 0, 0 },  // 4
  { 1, 1, 1, 0, 1, 1, 0, 0 },  // 5
  { 1, 1, 1, 0, 1, 1, 1, 0 },  // 6
  { 0, 0, 1, 1, 1, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 },  // 8
  { 1, 1, 1, 1, 1, 1, 0, 0 },  // 9
  { 1, 1, 1, 1, 1, 0, 1, 0 },  // A
  { 1, 1, 0, 0, 1, 1, 1, 0 },  // B
  { 0, 1, 1, 0, 0, 1, 1, 0 },  // C
  { 1, 0, 0, 1, 1, 1, 1, 0 },  // D
  { 1, 1, 1, 0, 0, 1, 1, 0 },  // E
  { 1, 1, 1, 0, 0, 0, 1, 0 }   // F
};


void writeValue(int number) {

  for (int i = 0; i < 8; ++i) {
    digitalWrite(SER, serialValues[number][i]);
    pulse(1, GAP);
  }
}

void clearDisplay() {
  digitalWrite(CLEAR, 0);
  delay(1);
  digitalWrite(CLEAR, 1);
}

void setup() {

  pinMode(CLEAR, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(CLK, OUTPUT);
  digitalWrite(CLEAR, LOW);
  digitalWrite(CLEAR, HIGH);
}



void loop() {

  for (int i = 0; i < 16; ++i) {
    writeValue(i);
    delay(900);
  }
}
