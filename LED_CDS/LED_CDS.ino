void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
}

void loop() {
  // A3은 GPIO26
  int ir = analogRead(26);
  
  // 밝을 때
  if (ir < 500) {
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
  }
  
  // 어두울 때
  else {
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
  }

  // 밝기에 대한 아날로그 데이터 출력
  Serial.println(ir);
  delay(500);
}
