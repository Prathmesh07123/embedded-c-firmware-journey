//--------------------------- Basic Pointer ------------------------------

#include <stdio.h>
#include <stdint.h>

/*
int main(void)
{
    uint32_t value = 100;
    uint32_t *ptr = &value;

    printf("Value      : %u\n", value);
    printf("Address    : %p\n", (void*)ptr);
    printf("Via Pointer: %u\n", *ptr);

    *ptr = 200;

    printf("Updated Value: %u\n", value);

    return 0;
}
*/


//--------------------------- Pointer Arithmetic (DMA Logic) ------------------------------

/* #include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t buffer[5] = {10, 20, 30, 40, 50};
    uint16_t *p = buffer;

    for (uint8_t i = 0; i < 5; i++)
    {
        printf("Value : %u , Address : %p ", *(p + i), (void*)(p + i));
    }

    return 0;
}
*/

//-------------------------- const & volatile -------------------------

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t reg = 0x12345678;
    uint32_t reg2 = 0x42145765;

    volatile uint32_t *vreg = &reg;
    const uint32_t *cvreg = &reg;
    uint32_t *const cpreg = &reg;

    printf("Volatile read: %lu with Address  : %p\n", *vreg, vreg);
    printf("Const value read   : %lu with Address  : %p\n", *cvreg, cvreg);
    printf("Const pointer read   : %lu with Address  : %p\n", *cpreg, cpreg);

    //*vreg = 0x87654321;
    //*cvreg = 0x87654321;    //NOT allowed to change value
    //*cpreg = 0x87654321;     //Allowed to change value
    cvreg = &reg2;         //Allowed to change pointer address
    //cpreg = &reg2;         //NOT allow to change address 

    printf("Volatile read: %lu with Address  : %p\n", *vreg, vreg);
    printf("Const value read   : %lu with Address  : %p\n", *cvreg, cvreg);
    printf("Const pointer read   : %lu with Address  : %p\n", *cpreg, cpreg);

    return 0;
}
*/

//------------------------------ Function Pointer ----------------------------


#include <stdio.h>

void handler1(void)
{
    printf("Handler 1 executed\n");
}

void handler2(void)
{
    printf("Handler 2 executed\n");
}

int main(void)
{
    void (*irq_handeler)(void);

    irq_handeler = handler1;
    irq_handeler();

    irq_handeler = handler2;
    irq_handeler();

    return 0;
}


//---------------------------- Register Access ---------------------------

/*
#include <stdio.h>
#include <stdint.h>

#define GPIO_ODR   (*(volatile uint32_t*)0x4001100C)

int main(void)
{
    printf("Pretend writing to GPIO register\n");

    GPIO_ODR = 0x01;   // LED ON
    GPIO_ODR = 0x00;   // LED OFF

    return 0;
}
*/