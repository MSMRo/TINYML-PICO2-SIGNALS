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
void setup() {
  Serial.begin(115200);
}

void loop() {
  float signal = sin(2 * PI * freq * t);
  Serial.println(signal);
  delayMicroseconds(period);
}
