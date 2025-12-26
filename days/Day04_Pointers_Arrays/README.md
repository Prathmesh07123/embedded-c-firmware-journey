# Day 04 – Pointers + Arrays (Embedded C)

## 🎯 Objective
Strengthen understanding of **pointer-based array manipulation** using
firmware-safe patterns:
- No dynamic memory
- Explicit length handling
- Pointer traversal instead of indexing

These patterns are heavily used in **DMA buffers, UART RX parsing,
sensor data processing, and protocol handling**.

---

## 📘 Topics Covered
- Copy arrays using pointers
- Compare arrays safely
- Detect duplicate elements
- Find second largest element
- Count frequency of elements
- Pointer boundary control

---

## 🧪 Problems Implemented

### 1️⃣ Copy Array Using Pointers
**File:** `Problem01_copy_array.c`

- Copy elements from source to destination using pointers
- Avoid index-based loops
- Protect source using `const`

**Firmware Use:**
- DMA buffer duplication
- Signal processing pipelines
- Endianness correction

⚠️ **Bug Learned**
- Lost `const` qualifier inside function

---

### 2️⃣ Compare Two Arrays
**File:** `Problem02_compare_arrays.c`

- Compare array lengths
- Compare elements byte-by-byte using pointers

**Firmware Use:**
- Packet validation
- Configuration verification
- Sensor data consistency checks

---

### 3️⃣ Find Duplicate Elements
**File:** `Problem03_find_duplicates.c`

- Nested pointer traversal
- Detect repeated values

**Firmware Use:**
- Detect repeated sensor samples
- UART RX data sanity checks
- Fault detection logic

---

### 4️⃣ Second Largest Element
**File:** `Problem04_second_largest.c`

- Track largest and second-largest values
- Single-pass pointer traversal

**Firmware Use:**
- Peak detection
- Signal thresholding
- Diagnostics

---

### 5️⃣ Count Frequency of Elements
**File:** `Problem05_count_frequency.c`

- Count occurrence of values
- Pointer-based comparison

**Firmware Use:**
- Error code frequency
- Event statistics
- Telemetry analysis

---

## 🧠 Key Firmware Learnings
- Pointer traversal is safer than index misuse
- `const` correctness is critical in APIs
- Always move pointers explicitly
- Never assume unused buffer values
- Boundary checks prevent memory corruption

---

## 🔧 Embedded Relevance
Used extensively in:
- UART RX/TX buffers
- DMA memory blocks
- Sensor queues
- Communication protocol stacks
- RTOS message handling

---

## ✅ Day 04 Status
✔ All problems completed  
✔ Firmware-relevant bugs documented  
✔ Pointer discipline improved  

➡️ Next: **Day 05 – Strings in C**
