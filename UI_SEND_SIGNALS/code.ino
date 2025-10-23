// Lee "idx,valor\n" y publica "ECG valor" para el Serial Plotter
const uint32_t BAUD = 115200;
String line;

void setup() {
  Serial.begin(BAUD);
  while (!Serial) { ; }
  Serial.println(F("READY"));
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    delay(1);
    if (c == '\n') {
      int comma = line.indexOf(',');
      if (comma > 0) {
        // idx no es estrictamente necesario si solo ploteas
        //long /*idx*/ _ = line.substring(0, comma).toInt();
        long val = line.substring(comma + 1).toInt();

        // Para el Serial Plotter: "ECG <valor>"
        Serial.print("500,");
        Serial.print(val);
        Serial.print(",2500\n");
      }
      line = "";
    } else {
      if (line.length() < 128) line += c; else line = ""; // control simple de overflow
    }
  }
}