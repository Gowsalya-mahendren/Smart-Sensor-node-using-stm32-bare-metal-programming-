# Smart-Sensor-node-using-stm32-bare-metal-programming-

## 📌 Project Overview

This project is a **Smart Sensor Node** built using an STM32 microcontroller with **bare-metal programming (no HAL, no RTOS)**.

The main focus of this project is to design a **fully interrupt-driven embedded system**. Instead of relying on polling, the system is built to react to real-world events efficiently using hardware features like EXTI and NVIC.

Currently, motion detection is implemented using a PIR sensor, forming the first building block of a larger system.

---

## 🎯 Objectives

* Design an **interrupt-driven embedded system architecture**
* Use hardware features (EXTI, NVIC) for efficient event handling
* Build a **scalable system** that integrates multiple sensors
* Move towards a **modular, real-world embedded application**

---

## 🧠 System Architecture

```
PIR Sensor → GPIO (PA1)
           → EXTI Line 1
           → NVIC
           → ISR (Interrupt Handler)
           → motion_flag
           → Main Loop → UART Output
```

---

## ⚙️ What’s Implemented

### ✅ GPIO Configuration

* PA1 configured as input with pull-down
* Ensures stable default state

---

### ✅ EXTI Configuration

* PA1 mapped to EXTI Line 1 via SYSCFG
* Interrupt enabled through IMR
* Rising edge detection configured for motion events

---

### ✅ NVIC Integration

* EXTI1 interrupt enabled in NVIC
* Proper interrupt routing to CPU verified

---

### ✅ Interrupt Handler (ISR)

* `EXTI1_IRQHandler` implemented
* Minimal ISR design:

  * Validates interrupt source
  * Clears pending register
  * Signals main loop via flag

---

### ✅ UART Interface

* USART2 configured for runtime observation
* Used for system-level debugging and verification

---

### ✅ Debugging & Fixes

* Corrected EXTI line mapping in SYSCFG
* Fixed pending register clearing behavior
* Resolved ISR lock condition caused by improper PR handling

---

## 🧪 Hardware Setup

| Component | Connection   |
| --------- | ------------ |
| PIR VCC   | 3.3V         |
| PIR GND   | GND          |
| PIR OUT   | PA1          |
| UART TX   | PA2 (USART2) |

---

## 🔥 Key Concepts Applied

* Interrupt vs Polling
* EXTI (External Interrupt Controller)
* NVIC (Nested Vector Interrupt Controller)
* ISR design principles

---

## 🚀 Roadmap

### 🔜 Ultrasonic Integration

* Trigger distance measurement only on motion events
* Use timer input capture for precise signal measurement

---

### 🔜 State Machine Architecture

* Introduce structured states:

  * IDLE
  * MOTION_DETECTED
  * MEASURE
  * SEND
* Improve system scalability and control flow

---

### 🔜 Sensor Expansion

* Integrate light sensing (ADC)
* Combine multiple sensor inputs for decision making

---

### 🔜 Communication Optimization

* Transition UART to interrupt/DMA-based transmission

---

## 🧠 Design Approach

* Event-driven execution using interrupts
* Minimal ISR, logic handled in main loop
* Efficient use of hardware peripherals
* Structured and scalable system design

---

## 📈 Current Status

* Interrupt-driven PIR detection working reliably
* System stable under testing
* UART-based validation complete

---

## 💡 Next Milestone

👉 Integrate ultrasonic sensing triggered by motion
👉 Build a structured state-driven system

---

## 🏁 Summary

This project focuses on building a **robust interrupt-driven embedded system**, forming the foundation for a scalable multi-sensor node using bare-metal STM32 development.

---

## 👩‍💻 Author

Gowsalya Mahendren
