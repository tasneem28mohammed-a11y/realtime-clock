# Real Time Clock using ATmega32

A digital clock project developed using the **ATmega32 AVR microcontroller** and programmed in **Embedded C**.

The system displays **hours, minutes, and seconds** using six multiplexed 7-segment displays. The clock updates automatically using **Timer0 interrupts**, while four push buttons are used to manually adjust the hours and minutes.

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
* After `23:59:59`, the clock returns to `00:00:00`.

## Main Features

* Digital clock displaying **Hours, Minutes, and Seconds**
* 6 × 7-Segment Displays
* 7-segment display **Multiplexing**
* Time generation using **Timer0**
* Timer interrupts for automatic time updates
* 24-hour time format
* Manual adjustment of:

  * Hours
  * Minutes
* 4 push buttons for increment and decrement control

## Hardware Components

* ATmega32 AVR Microcontroller
* 6 × 7-Segment Displays
* 4 × Push Buttons
* Supporting electronic components

## Push Button Controls

| Control  | Function         |
| -------- | ---------------- |
| Hour +   | Increase hours   |
| Hour −   | Decrease hours   |
| Minute + | Increase minutes |
| Minute − | Decrease minutes |

## Multiplexing

The project uses **multiplexing** to control the six 7-segment displays efficiently.

Instead of assigning separate segment lines to every display, the displays share the segment lines while each display is enabled individually.

The microcontroller switches between the six displays very quickly, making them appear to be ON simultaneously to the human eye.

This technique reduces the number of microcontroller pins required to control the displays.

## Software Operation

The program performs the following main tasks:

1. Initializes the microcontroller I/O pins.
2. Initializes Timer0.
3. Uses timer interrupts to generate the required timing.
4. Updates the seconds automatically.
5. Updates minutes and hours when required.
6. Reads the four push buttons for manual hour and minute adjustment.
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

* Embedded C
* AVR Microcontrollers
* ATmega32
* Timer0
* Interrupts
* GPIO
* 7-Segment Displays
* Multiplexing
* Push Button Interfacing
* Proteus Simulation

## Example Operation

Normal time counting:

```text
12:34:58
12:34:59
12:35:00
```

24-hour rollover:

```text
23:59:58
23:59:59
00:00:00
```

The hours and minutes can also be manually adjusted using the four push buttons.

## Team

This project was developed as a **team project by five students** as part of the **NTI Microcontroller Training**.

## Learning Outcomes

Through this project, we gained practical experience with:

* AVR microcontroller programming
* Embedded C
* GPIO configuration
* Timer and interrupt concepts
* 7-segment display interfacing
* Multiplexing
* Push button interfacing
* Debugging and testing embedded systems
* Proteus simulation

## Future Improvements

Possible future improvements include:

* Adding buttons for manual seconds adjustment
* Adding a dedicated RTC module such as DS3231
* Adding alarm functionality
* Adding date display
* Saving time settings during power loss
* Implementing the project on physical hardware

---

**Real Time Clock — ATmega32 Embedded Systems Project**
