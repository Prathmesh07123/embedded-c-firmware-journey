# Day 03 – Pointer Basics (Embedded C)

## 🎯 Objective
Understand and practice **pointers from a firmware perspective**:
- Direct memory access
- Array traversal using pointers
- In-place data manipulation
- Avoiding unnecessary copying

These concepts are **fundamental to bare-metal firmware**, where
buffers, registers, and peripherals are accessed via pointers.

---

## 📘 Topics Covered
- Pointer declaration and dereferencing
- Passing variables using pointers
- Pointer arithmetic
- Arrays as pointers
- In-place modification using pointers

---

## 🧪 Problems Implemented

### 1️⃣ Swap Two Numbers Using Pointers
**File:** `Problem01_swap_using_pointers.c`

- Swap values without returning anything
- Modify variables via memory address

**Firmware Use:**
- Register value manipulation
- ISR-safe data swapping
- Peripheral configuration updates

---

### 2️⃣ Array Access Using Pointers
**File:** `Problem02_array_access_using_pointers.c`

- Traverse array using pointer arithmetic
- No array indexing (`arr[i]` avoided)

**Firmware Use:**
- ADC sample buffers
- Sensor data queues
- DMA memory traversal

---

### 3️⃣ Pointer Arithmetic
**File:** `Problem03_pointer_arithmetic.c`

- Observe how pointer increments depend on data type
- `uint16_t*` moves by 2 bytes

**Firmware Use:**
- DMA address increment
- Audio/sample buffer stepping
- Peripheral FIFO access

---

### 4️⃣ String Length Using Pointer
**File:** `Problem04_string_length_pointer.c`

- Calculate string length using pointer traversal
- No `strlen()` used

**Firmware Use:**
- UART command parsing
- AT command length detection
- Protocol frame handling

---

### 5️⃣ Reverse Array Using Pointers
**File:** `Problem05_reverse_array_using_pointers.c`

- Reverse array in-place
- No extra buffer used

**Firmware Use:**
- UART RX command reordering
- Endianness correction
- Sensor data preprocessing

---

## 🧠 Key Firmware Learnings
- Arrays are always passed as **pointers**
- Pointer arithmetic is **type dependent**
- In-place operations save memory
- Pointer misuse can cause silent bugs or hard faults

---

## 🔧 Embedded Relevance
These patterns are directly used in:
- UART RX/TX buffers
- DMA circular buffers
- Sensor data pipelines
- Bare-metal driver development

---

## ✅ Day 03 Status
✔ All planned pointer problems completed  
✔ Firmware relevance documented for each problem  
✔ Foundation ready for buffer parsing and protocol handling  

➡️ Next: **Day 04 – Pointers + Arrays**
