

#include <stdint.h>
#include <stdint.h>


int main(void)
{
    uint32_t *pClkCtrlreg = (uint32_t*)0x40023830;//clock control register.
    uint32_t *pPortDModReg= (uint32_t*)0x40020C00;//base GPIOD.
    uint32_t *pPortDOutReg= (uint32_t*)0x40020C14;//GPIOD's output register.

    //1. enable the clock for GPOID peripheral in the AHB1ENR.
    *pClkCtrlreg |= (1<<3);//0x08

    //2. configure the mode of the IO pin as output.
    //a. clear the 24th and 25th bit positions.(clear)
    *pPortDModReg &= ~(3<<24);//0xFCFFFFFF
    //b. set 24th bit as 0 and 25th as 1.(set)
    *pPortDModReg |=(1<<24);//0x01000000

    //3. set 12th bit of the output data register to make I/O pin-12 as High.
    *pPortDOutReg |=(1<<12);//0x1000

    while(1){
    *pPortDOutReg |= (1<<12);
    for( uint32_t i=0;i<300000 ;i++ );
    *pPortDOutReg &= ~(1<<12);
    for( uint32_t i=0;i<300000 ;i++ );

    }




}
