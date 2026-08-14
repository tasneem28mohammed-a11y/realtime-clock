# Real Time Clock (RTC) using ATmega32

A digital **Real Time Clock project** developed using the **ATmega32 AVR microcontroller**, programmed in **Embedded C**.

The system displays **hours, minutes, and seconds** using six multiplexed 7-segment displays and allows the user to manually adjust the time using six push buttons.

## Project Overview

The clock displays time in the following format:

```text
HH : MM : SS
```

The system automatically updates the time every second.

* Seconds count from `00` to `59`.
* When seconds reach `60`, they reset to `00` and the minutes are incremented.
* Minutes count from `00` to `59`.
* When minutes reach `60`, they reset to `00` and the hours are incremented.
* Hours operate in a 24-hour format.

## Main Features

* Digital clock displaying **Hours, Minutes, and Seconds**
* Six 7-segment displays
* 7-segment **Multiplexing**
* Time generation using **Timer0**
* Timer interrupts for automatic time updates
* Manual time adjustment using six push buttons
* Increment and decrement control for:

  * Hours
  * Minutes
  * Seconds
* 24-hour time format

## Hardware Components

* ATmega32 AVR Microcontroller
* 6 × 7-Segment Displays
* 6 × Push Buttons
* Supporting electronic components

## Push Button Controls

| Control  | Function         |
| -------- | ---------------- |
| Hour +   | Increase hours   |
| Hour −   | Decrease hours   |
| Minute + | Increase minutes |
| Minute − | Decrease minutes |
| Second + | Increase seconds |
| Second − | Decrease seconds |

## Multiplexing

Instead of controlling each 7-segment display independently, the project uses **multiplexing**.

The segment lines are shared between the six displays, while each display is enabled individually for a very short period of time.

The microcontroller switches between the displays rapidly, making all six displays appear to be ON simultaneously to the human eye.

This technique reduces the number of microcontroller pins required to control the displays.

## Software Operation

The program performs the following main tasks:

1. Initializes the microcontroller I/O pins.
2. Initializes Timer0.
3. Uses timer interrupts to generate the required time interval.
4. Updates the seconds every second.
5. Updates minutes and hours when required.
6. Reads the six push buttons for manual time adjustment.
7. Continuously refreshes the six 7-segment displays using multiplexing.

## Time Update Logic

```text
Seconds++
    |
    v
Seconds = 60?
    |
   Yes
    |
    v
Seconds = 0
Minutes++
    |
    v
Minutes = 60?
    |
   Yes
    |
    v
Minutes = 0
Hours++
    |
    v
Hours = 24?
    |
   Yes
    |
    v
Hours = 0
```

## Tools & Technologies

* **Embedded C**
* **AVR Microcontroller**
* **ATmega32**
* **Timer0**
* **Interrupts**
* **GPIO**
* **7-Segment Display**
* **Multiplexing**
* **Proteus Simulation**

## Project Demo

The project can demonstrate:

```text
12:34:58
12:34:59
12:35:00
```

and the 24-hour rollover:

```text
23:59:58
23:59:59
00:00:00
```

The displayed time can also be manually adjusted using the six push buttons.

## Team

This project was developed as a **team project by five students** as part of our Microcontroller training.

## Learning Outcomes

Through this project, we gained practical experience with:

* AVR microcontroller programming
* Embedded C
* GPIO configuration
* Timer and interrupt concepts
* 7-segment display interfacing
* Multiplexing techniques
* Push button interfacing
* Debugging and testing embedded systems
* Proteus simulation

## Future Improvements

Possible future improvements include:

* Adding a dedicated RTC module such as DS1307 or DS3231
* Adding alarm functionality
* Adding date display
* Saving time settings during power loss
* Implementing the project on physical hardware

---

**Real Time Clock — AVR Microcontroller Project**
