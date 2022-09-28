String command;

#define relay1 3
#define relay3 5

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay3, HIGH);
  Serial.begin(9600);
  Serial.println("Type Command (relay1, relay3, off1, off3, off_all)");
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();
    if (command.equals("relay1")) {
      digitalWrite(relay1, LOW);
    }
    else if (command.equals("relay3")) {
      digitalWrite(relay3, LOW);
    }
    else if (command.equals("off1")) {
      digitalWrite(relay1, HIGH);
    }
    else if (command.equals("off3")) {
      digitalWrite(relay3, HIGH);
    }
    else if (command.equals("off_all")) {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay3, HIGH);
    }
    else {
      Serial.println("bad command");
    }
    Serial.print("Command: ");
    Serial.println(command);
  }
}