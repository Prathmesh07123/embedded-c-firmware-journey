# Day 01 – Arrays Basics in C (Firmware-Oriented)

## 🎯 Objective
Build strong fundamentals of **arrays in C**, focusing on:
- Static memory usage
- Predictable execution
- Real embedded use cases (bare-metal)

---

## 📚 Concepts Covered
- Array declaration & indexing
- Traversal using loops
- Static memory allocation
- Boundary-safe access
- Embedded-friendly data types (`uint8_t`, `int16_t`)

---

## 🧪 Problems Implemented

### ✅ Problem 01 – Find Maximum & Minimum
**File:** `Problem01_max_min.c`

**Description:**  
Find the maximum and minimum values in an array of ADC samples.

**Firmware Usage:**  
- ADC signal range monitoring  
- Sensor fault detection  
- Calibration boundary checks

---

### ✅ Problem 02 – Reverse an Array
**File:** `Problem02_reverse_array.c`

**Description:**  
Reverse array elements using in-place swapping.

**Firmware Usage:**  
- Signal processing buffers  
- DMA data reordering  
- Communication frame reversal

---

### ✅ Problem 03 – Sum of Array Elements
**File:** `Problem03_sum_elements.c`

**Description:**  
Calculate the sum of all elements in an array.

**Firmware Usage:**  
- Energy calculation  
- Averaging sensor values  
- Statistical processing

---

### ✅ Problem 04 – Count Even and Odd Numbers
**File:** `Problem04_even_odd_count.c`

**Description:**  
Count even and odd values in a data buffer.

**Firmware Usage:**  
- Signal quality checks  
- Data classification  
- Diagnostic statistics

---

### ✅ Problem 05 – Linear Search
**File:** `Problem05_linear_search.c`

**Description:**  
Search for a target value in a lookup table.

**Firmware Usage:**  
- Lookup tables (LUTs)  
- Command matching  
- ID detection (sensor, protocol, device)

---

## 🧠 Key Firmware Learnings
- Prefer `static` arrays for predictable memory
- Avoid dynamic allocation
- Use fixed-width integer types
- Think in terms of **buffers**, not just arrays
- Every array = potential hardware data source

---

## 🛠 Tools Used
- Language: **C (C99)**
- Compiler: `arm-none-eabi-gcc` (target) / `gcc` (host testing)
- Editor: **VS Code**
- Version Control: **Git + GitHub**

---

## 🚀 Day 01 Status
✅ All problems completed  
✅ Code tested locally  


