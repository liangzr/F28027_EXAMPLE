/*
 * main.c
 */

/*    GPIO0,1,2,3  --> LED
 *
 */
/////////////////////////////////////////////////////////
//   Header include
#include "DSP28x_Project.h"


//#pragma CODE_SECTION(EPwm1_timer_isr, "ramfuncs");
//#pragma CODE_SECTION(EPwm2_timer_isr, "ramfuncs");

/////////////////////////////////////////////////////////
//   defined

#ifdef TOFLASH
extern void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

#endif


void main(void)

{
	InitSysCtrl();
	InitGpio();
	InitSciaGpio();
	DINT;
	InitPieCtrl();

	IER = 0x0000;
	IFR = 0x0000;

	InitPieVectTable();

#ifdef TOFLASH

	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
	InitFlash();
#endif


	while(1)
        {
	     ;
        }
}
