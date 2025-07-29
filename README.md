# 🛒 RetailSense: Console-Based Billing System 📊

---

## Overview

StoreBill is a robust, console-based billing and inventory management system developed in C++. It provides a straightforward interface for managing a store's item inventory, adding new items, and processing customer transactions with real-time stock updates and total bill generation. This project demonstrates foundational programming concepts, including object-oriented design, file handling for data persistence, and basic error management.

---

## Features ✨

* **Item Management:**
    * ➕ Add new items to the inventory with a specified name, rate, and initial quantity.
* **Transaction Processing:**
    * 🛒 Allow customers to select items and quantities from the inventory.
    * 📉 Real-time stock decrementation based on items purchased.
    * 🧾 Calculates the amount for each item and accumulates the total bill for the current session.
* **Data Persistence:**
    * 💾 Stores inventory data in a plain text file (`Bill.txt`) using a simple CSV-like format (`ItemName : Rate : Quantity`).
    * 🔒 Securely updates inventory by writing to a temporary file (`Bill Temp.txt`) and then atomically replacing the original inventory file, ensuring data integrity.
* **Console User Interface:**
    * 🖥️ Provides a clean, interactive command-line interface for ease of use.
* **Basic Error Handling:**
    * ⚠️ Includes checks for file opening failures and insufficient stock during transactions.

---

## How to Run 🚀

To compile and run this C++ application, you will need a C++ compiler (like g++ for MinGW on Windows, or GCC/Clang on Linux/macOS).

**Prerequisites:**
* A C++ compiler (e.g., MinGW-w64 on Windows, build-essential on Linux, Xcode Command Line Tools on macOS).

**Steps:**

1.  **Save the Code:**
    * Save the entire C++ code into a file named `Billing System.cpp`.
2.  **Open Terminal/Command Prompt:**
    * Navigate to the directory where you saved `Billing System.cpp`.
    ```bash
    cd /path/to/your/project/folder
    ```
3.  **Compile the Code:**
    * Use your C++ compiler to compile the source file into an executable. Remember to put the filename in quotes due to the space.
    ```bash
    g++ "Billing System.cpp" -o StoreBill.exe
    ```
    (On Linux/macOS, you might use `./StoreBill` instead of `StoreBill.exe` to run the executable.)
4.  **Run the Application:**
    * Execute the compiled program from the command line:
    ```bash
    ./StoreBill.exe
    ```
    (On Linux/macOS: `./StoreBill`)

---

## Demo 💻

<img width="1308" height="182" alt="Screenshot 2025-07-29 173446" src="https://github.com/user-attachments/assets/c193abb4-1f8f-44a4-9545-51732eb5a597" />
<img width="1298" height="143" alt="Screenshot 2025-07-29 173558" src="https://github.com/user-attachments/assets/5f1ba845-54c4-4ee5-83b3-1e7c33a398e2" />
<img width="1304" height="169" alt="Screenshot 2025-07-29 173616" src="https://github.com/user-attachments/assets/53ec3dcd-1b85-408c-a503-155eb3e22def" />
<img width="1305" height="301" alt="Screenshot 2025-07-29 173644" src="https://github.com/user-attachments/assets/e0efdbd4-8b42-4ad2-bbac-e7887d30963e" />
<img width="1299" height="183" alt="Screenshot 2025-07-29 173658" src="https://github.com/user-attachments/assets/0db15971-8041-4f73-b457-544a8b35e487" />

---

## Technical Details ⚙️

* **Language:** C++
* **Core Concepts:** Object-Oriented Programming (OOP) for structuring item data (`Bill` class), File Input/Output (I/O) using `fstream` for reading and writing inventory data, String Stream (`sstream`) for parsing data from file lines, and basic conditional logic (`if-else`, `while` loops) for program flow.
* **Data Storage:** Persistent inventory data is managed through local text files (`Bill.txt`, `Bill Temp.txt`).
* **System Interaction:** Utilizes `windows.h` for `Sleep()` (pauses) and `system("cls")` (clears console), making it primarily compatible with Windows environments.
* **Quantified Impact:**
    * Ensures **100% data integrity** ✅ for inventory updates through robust atomic file operations (temporary file write, delete, and rename).
    * Designed to handle a **dynamic volume of transactions** 📈, adapting to ongoing sales without predefined limits on item additions or purchases.

---

## ✍️ Author

**Shefali Kaushal**   
🔗 [LinkedIn](https://www.linkedin.com/in/shefalikaushal13)  
🌐 [Portfolio](https://shefali-kaushal-portfolio.netlify.app/)
💻 [Peerlist](https://peerlist.io/shefalikaushal)

---
