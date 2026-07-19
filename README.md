# 🔐 Embedded Password-Based Security System

A password-based embedded security system developed in Embedded C that authenticates users using a keypad and grants or denies access based on the entered password.

---

## 📷 Circuit Diagram

<p align="center">
  <img src="images/circuit.png" alt="Password Based Security System Circuit" width="750">
</p>

## 📷 Circuit Diagram

<img width="1599" height="899" alt="image" src="https://github.com/user-attachments/assets/2279d387-2718-4f91-8809-9a2404fe669e" />

The circuit consists of:

- **AT89S52 (8051) Microcontroller** – Main controller
- **16×2 LCD** – Displays prompts and authentication status
- **4×4 Matrix Keypad** – Used to enter the password
- **Relay Driver Circuit** – Controls the electronic lock/load
- **Buzzer** – Indicates incorrect password attempts
- **Reset Circuit** – Initializes the microcontroller
- **Crystal Oscillator** – Provides the system clock
- **Power Supply** – 5V regulated supply for the complete system
---

## 🛠 Hardware Components

- Microcontroller
- 4×4 Matrix Keypad
- 16×2 LCD Display
- Buzzer
- LED Indicators
- Relay / Door Lock (Optional)
- Power Supply

---

## ⚙️ Working

1. Power ON the system.
2. LCD prompts **Enter Password**.
3. User enters password through keypad.
4. Firmware validates the password.
5. If correct:
   - LCD displays **Access Granted**
   - Relay/LED activates.
6. Otherwise:
   - LCD displays **Access Denied**
   - User retries.

---

## 🔄 System Flow

```text
Power ON
   │
   ▼
Initialize MCU
   │
   ▼
Display "Enter Password"
   │
   ▼
Read Keypad
   │
   ▼
Compare Password
   │
 ┌─┴──────────────┐
 │                │
 ▼                ▼
Correct       Incorrect
 │                │
 ▼                ▼
Unlock      Access Denied
 │                │
 └──────┬─────────┘
        ▼
   Wait for Next User
```

---

## 📂 Repository Structure

```text
.
├── Core/
├── Drivers/
├── images/
│   ├── circuit.png
│   ├── setup.jpg
│   └── demo.gif
├── README.md
└── LICENSE
```

## 🚀 Applications

- Smart Door Lock
- Access Control
- Electronic Safe
- Office Security
- Home Automation

## 🔮 Future Improvements

- EEPROM Password Storage
- Password Change
- RFID Authentication
- Fingerprint Module
- Bluetooth/Wi-Fi Control
- Multiple User Support

## 📜 License

Unless otherwise specified, all content in this repository—including, but not
limited to, software source code, firmware, hardware design files (schematics,
PCB layouts, Gerber files, BOMs, CAD files), documentation, configuration
files, examples, and supporting materials—is made available under the MIT
License.

---

## MIT License

Copyright (c) 2026 Joydeep Majumdar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---


