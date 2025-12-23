# Day 02 – Array Operations (Embedded C)

## 🎯 Objective
Practice core array operations in **pure C** with a firmware mindset:
- No dynamic memory
- Explicit length tracking
- Index safety
- Real embedded use-cases (bare-metal)

These problems directly map to **sensor queues, command buffers, and DMA data handling**.

---

## 📘 Topics Covered
- Array traversal
- Insertion & deletion
- Left and right rotation
- Static buffer management
- Index validation & edge cases

---

## 🧪 Problems Implemented

### 1️⃣ Insert Element at Given Position
**File:** `Problem01_insert_element.c`

- Insert value into array at specific index
- Shift elements to the right
- Check buffer capacity

**Firmware Use:**
- Sensor data queues
- Command buffers

---

### 2️⃣ Delete Element at Given Position
**File:** `Problem02_delete_element.c`

- Validate position
- Shift elements left
- Update length safely

**Firmware Use:**
- Removing processed commands
- Data queue cleanup

⚠️ **Bug Learned & Fixed**
- Incorrect validation: `pos > length` → `pos >= length`

---

### 3️⃣ Rotate Array Left (by 1)
**File:** `Problem04_rotate_array_left.c`

- Shift elements left
- Move first element to end

**Firmware Use:**
- Circular buffers
- Sliding window sensor data

---

### 4️⃣ Rotate Array Right (by 1)
**File:** `Problem05_rotate_array_right.c`

- Shift elements right
- Move last element to front

**Firmware Use:**
- Time-shifted data
- Ring buffer indexing

---

### 5️⃣ Merge Two Arrays (Bonus)
**File:** `Problem06_merge_arrays.c`

- Merge two arrays into one static buffer
- Track merged length

**Firmware Use:**
- Packet assembly
- UART / DMA transmit buffers
- Sensor data aggregation

---

## 🧠 Key Firmware Learnings
- Always track **logical length**, not just array size
- Backward loops should use **signed indices**
- Never assume unused buffer elements are zero
- Index validation prevents silent memory corruption

---

## 🔧 Embedded Relevance
These patterns are used in:
- UART RX/TX buffers
- DMA circular buffers
- Telemetry packet framing
- RTOS message queues

---

## ✅ Day 02 Status
✔ All planned problems completed  
✔ One bonus firmware-relevant problem added  
✔ Bugs documented for future reference  

➡️ Next: **Day 03 – Pointers Basics**
