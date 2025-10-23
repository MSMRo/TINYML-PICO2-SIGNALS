# TINYML-PICO2-SIGNALS
# 🧠 Signal Generation and Analysis

This project demonstrates how to **generate synthetic signals** using Arduino (`code.ino`) and how to **analyze or visualize** them using Python (`test_gen_signals.ipynb`).  
It provides a foundation for experiments in **biomedical signal processing**, **embedded systems**, and **TinyML**.

---

## ⚙️ Components

### 1. `code.ino`
**Platform:** Arduino / Raspberry Pi Pico / compatible microcontroller  

**Purpose:**  
Generates and transmits synthetic signals (e.g., sine, square, or ECG-like) through the serial interface for real-time analysis.

**Key Features:**
- Adjustable sampling rate and amplitude.  
- Output via `analogWrite()` or DAC pins.  
- Serial transmission of timestamped samples.  
- Works seamlessly with `pyserial` in Python.

**Example structure:**
```cpp
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

