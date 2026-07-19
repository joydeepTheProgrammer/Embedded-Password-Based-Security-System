# 🔐 Embedded Password-Based Security System

A password-based embedded security system developed in Embedded C that authenticates users using a keypad and grants or denies access based on the entered password.

---

## 📷 Circuit Diagram

<p align="center">
  <img src="images/circuit.png" alt="Password Based Security System Circuit" width="750">
</p>

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

MIT License
![IMG-20221013-WA0002](https://user-images.githubusercontent.com/76057623/214027823-02081c27-404f-4ac8-b05a-617fdcc9d549.jpg)
