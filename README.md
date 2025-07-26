Database-Driven Billing System using RFID and LPC2148

 🧾 Project Overview

This project implements a real-time billing system that uses **RFID technology** and an **LPC2148 microcontroller**. It is designed to interact with a Linux-based database via **UART communication**. The system facilitates stock management, purchase entry, deletion, and secure payment handling through both cash and ATM card emulation.
 🎯 Objective

To build a general-purpose, embedded billing system that:

* Reads RFID cards for item identification.
* Communicates with a Linux PC for stock and payment operations.
* Performs real-time billing and updates the database accordingly.

 

🔧 Requirements
 Hardware

* LPC2148 ARM7 Microcontroller
* RFID Reader & RFID Cards
* LCD Display (16x2)
* 4x4 Keypad
* Switches
* MAX232 (for serial communication)
* USB-to-UART Converter

 Software

* Embedded C
* Keil uVision (for coding and compilation)
* Flash Magic (for firmware upload)
* Linux (for database and UART communication)
* UART Loopback Program (for testing on Linux)

 📁 Folder Structure
DATABASE-DRIVEN-BILLING-SYSTEM-main/
├── Embedded_Code/
│   ├── lcd.c, lcd.h
│   ├── uart.c, uart.h
│   ├── keypad.c, keypad.h
|   |── eint0_eint1.c, header.h
│   ├── delay.c, delay.h
│   └── projectmain.c
├── Linux_Code/
│   ├── uart_linux.c
│   ├── main.c myheader.h
│   ├── stock.txt
│   └── bank.txt
└── README.md


🚀 How to Run the Project

 🔌 Microcontroller Setup

1. Write individual modules for:

   * LCD Display
   * UART0 and UART1 (interrupt-based)
   * eint0_eint1.c
   * Keypad
   * RFID Card Reader
2. Integrate all modules into `projectmain.c`.
3. Flash the final hex file using Flash Magic to LPC2148.

 🐧 Linux System Setup

1. Use the provided **uart\_linux.c** program.
2. Create two text files:

   * `stock.txt`: item inventory with quantities and prices.
   * `bank.txt`: mock bank account and PIN data.
3. Run the UART listener program to handle communication.

 🔄 System Flow

1. Display project RFID SYSTEM message on LCD.
2. Wait for `Entry`, `Delete`, or `Exit` key signal.
3. On RFID scan:

   * **Manager card** allows stock update.
   * **Item card** triggers purchase and billing.
4. On `Exit`:

   * Choose payment method: **Cash** or **Card**.
   * Validate card and PIN for ATM card transactions.
   * Update database accordingly
 📑 Data Formats

 **Manager Card:** `$<CARDNUMBER>&`
 **Customer Card:** $<CARDNUMBER>&`
 **Delete Card:** `$<CARDNUMBER>&``

 📂 Example Data

 stock.txt

```
Item       | CardNumber | Quantity | Price
SOAPS      | 00332069   | 190      | 100
MILKY      | 00336463   | 95       | 50
CHIPS      | 00312472   | 26       | 10
```
 bank.txt
 
 Bank Name | Acc Number | Balance | PIN
 VECTOR    | 12638754   | 10000   | 1234

 📎 Notes

* UART0 is used for communication with Linux.
* UART1 is used for RFID input.
* Error handling and invalid card detection logic should be added for robustness.
* Expandable for multiple banks or product categories.

 ✅ Status

✅ RFID Reading
✅ UART Communication
✅ Item Billing & Stock Update
✅ Cash & Card Payment Simulation
✅ Embedded C Code & Linux Code included


