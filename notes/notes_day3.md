# 📌 Day 03 – Pointer Fundamentals

## 🎯 Objective
Understand pointers deeply from a **firmware and embedded systems perspective**, not just basic C theory.

This focuses on how pointers interact with:
- Hardware registers  
- DMA  
- Buffers  
- ISRs  
- Peripherals  

---

## 📘 What Is a Pointer?
A pointer is a variable that stores a **memory address**.

```c
uint32_t x = 10;
uint32_t *p = &x;
```

- `p` stores the **address of `x`**
- `*p` accesses the **value stored at that address**

👉 In firmware, we rarely care about variables — **we care about addresses**.

---

## 📍 Dereferencing a Pointer
Dereferencing means accessing or modifying the data at the memory address.

```c
*p = 20;
```

This writes `20` to the memory location pointed to by `p`.

⚙️ This is **exactly how firmware writes to hardware registers**.

---

## 🧠 Memory-Mapped Registers (CRITICAL)
In embedded systems, peripherals are controlled via fixed memory addresses.

```c
#define GPIOC_ODR (*(volatile uint32_t*)0x4001100C)
```

### Breakdown
- `0x4001100C` → Fixed STM32 register address  
- `(uint32_t*)` → Register is 32-bit wide  
- `volatile` → Value can change outside CPU control  
- `*` → Dereference to access real hardware  

### ❓ Why `volatile` Is Mandatory
Without `volatile`, the compiler may:
- Cache register values  
- Skip re-reading memory  
- Optimize away critical reads/writes  

🚨 This **breaks hardware interaction**.

👉 **Every hardware register pointer must be `volatile`.**

---

## 🔢 Pointer Arithmetic (Firmware Core Concept)

```c
uint16_t arr[5];
uint16_t *p = arr;

p + 1;  // moves 2 bytes
```

### Why does it move 2 bytes?
Because `p` is a `uint16_t*`

| Pointer Type | Step Size |
|-------------|----------|
| `uint8_t*`  | 1 byte   |
| `uint16_t*` | 2 bytes  |
| `uint32_t*` | 4 bytes  |

### Firmware Relevance
- DMA depends on correct pointer stepping  
- UART / ADC / SPI buffers rely on this  
- ❌ Wrong pointer type = corrupted data  

---

## 📦 Arrays and Pointers

```c
uint16_t arr[5];
uint16_t *p = arr;
```

- Array name = **base address**
- These are equivalent:

```c
arr[i]
*(arr + i)
```

👉 Hardware, DMA, and drivers **think in pointers**, not indexes.

---

## 🔐 `const` + Pointer Combinations (Firmware Gold)

### 1️⃣ Read-only Data
```c
const uint8_t *p;
```
- Data cannot be modified  
- Pointer can move  

### 2️⃣ Fixed Pointer
```c
uint8_t *const p;
```
- Pointer cannot move  
- Data can change  

### Used In
- Driver APIs  
- Configuration tables  
- Flash-stored constants  

---

## ⚡ `volatile` + Pointers (ISR Safety)

```c
volatile uint32_t *reg;
```

### Why `volatile` is required
- Hardware can modify memory anytime  
- ISR can modify variables asynchronously  
- Compiler must always re-read memory  

### Used For
- Peripheral registers  
- ISR-shared flags  
- DMA-updated buffers  

---

## 7️⃣ Function Pointers (Firmware Essential)

A function pointer stores the **address of a function**.

```c
void (*func_ptr)(void);
```

### Example
```c
void led_on(void) {}

void (*func_ptr)(void);
func_ptr = led_on;
func_ptr();
```

### Firmware Use
- Interrupt vector tables
- Callback mechanisms
- Driver abstraction layers
- RTOS hooks
- State machines

---

## 8️⃣ Pointer to Pointer (Double Pointer)

```c
uint8_t **pp;
```

### Example
```c
uint8_t val = 10;
uint8_t *p = &val;
uint8_t **pp = &p;
```

| Expression | Meaning |
|---------|--------|
| pp | address of pointer |
| *pp | pointer |
| **pp | actual data |

### Firmware Use
- Buffer reassignment
- Driver initialization
- RTOS APIs
- DMA buffer updates

---

## 🐞 Common Bugs Learned
- ❌ Forgetting `volatile` → incorrect register values  
- ❌ Wrong pointer type → DMA/buffer corruption  
- ❌ Unsigned reverse loop → underflow bug  
- ❌ Writing to `const` memory → undefined behavior  

---

## 🔧 Firmware Relevance Summary
Pointers are everywhere in embedded systems:

- STM32 register access  
- DMA buffers  
- UART RX/TX queues  
- Sensor data arrays  
- Peripheral drivers  
- RTOS APIs  

---

## ✅ Key Takeaway
> **Firmware = controlling memory directly.**  
> **Pointers are the language of hardware.**
