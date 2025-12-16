# Assignment2
CENG201 Object Oriented Programming - Implementation Assignment 2 (Battery &amp; BatteryPack)

# Assignment3

# BatterySystemGUI

BatterySystemGUI is a **battery management system simulation** developed using **C++ and the Qt framework**.  
The main goal of this project is to simulate **series and parallel battery connections**, perform **charge and discharge operations**, and display **battery charge levels visually** through a graphical user interface.

This project was developed as a **student project** to practice **Object-Oriented Programming (OOP)** concepts and **GUI development with Qt**.

---

## Project Contents

This submission includes all required files:

- ✔️ All **C++ source codes** (`.h` and `.cpp`)
- ✔️ Qt project file (`.pro`)
- ✔️ UI design file (`.ui`)
- ✔️ **Executable file** (`.exe`)
- ✔️ This **README.md** file

---

## 🛠️ Technologies Used

- C++
- Qt Framework (Qt Widgets)
- Qt Creator
- QPainter (for custom graphics)

---

## 📁 Project File Structure

```
BatterySystemGUI/
│
├── BatterySystemGUI.pro
├── mainwindow.ui
├── README.md
│
├── Headers/
│   ├── Battery.h
│   ├── BatteryPack.h
│   ├── batterycanvas.h
│   └── mainwindow.h
│
├── Sources/
│   ├── Battery.cpp
│   ├── BatteryPack.cpp
│   ├── batterycanvas.cpp
│   ├── mainwindow.cpp
│   └── main.cpp
│
└── BatterySystemGUI.exe
```

---

## ⚙️ How to Compile the Program

### Using Qt Creator (Recommended)

1. Open **Qt Creator**
2. Click **File → Open File or Project**
3. Select `BatterySystemGUI.pro`
4. Configure the project using the default Qt Kit
5. Build the project:
   ```
   Ctrl + B
   ```
6. Run the program:
   ```
   Ctrl + R
   ```

---

## How to Run the Program

### Running Without Compiling

You can directly run the program by double-clicking:

```
BatterySystemGUI.exe
```

> Note: Qt runtime libraries must be installed on the system.

---

## Program Features

- Add batteries to the system
- Connect batteries in **series or parallel**
- Simulate battery usage (discharge)
- Recharge batteries
- Display battery charge level as percentage (%)
- Visual battery representation using custom drawing
- Click on a battery to see its current charge percentage
- Dynamic UI updates when switching between series and parallel modes

---

## Program Logic Overview

- **Battery class**  
  Represents a single battery and stores its charge information.

- **BatteryPack class**  
  Manages multiple batteries and applies series or parallel connection logic.

- **BatteryCanvas class**  
  Responsible for drawing batteries and visual effects on the screen.

- **MainWindow class**  
  Handles user interactions, buttons, and signal-slot connections.

The project is designed in a **modular and readable way**, making it easy to understand and extend.

---

## Possible Improvements

- Adding voltage and current calculations
- Time-based charge and discharge animations
- Graph-based battery level visualization
- Saving and loading battery states from a file
- Battery health monitoring

---

## Developer Information

- **Names:**
Fatih Kocaay -21050111071

Esra İlayda Günidi -22050151037

Arzu Bal -23050151006

Rümeysa Ayhan 23050151015

- **Project Type:** C++ / Qt GUI Application  
- **Purpose:** Learning OOP and GUI programming

---

## License

This project was developed for educational purposes.
