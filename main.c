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



interrupt void  cpu_timer0_isr(void);
void itoa(float num);

#ifdef TOFLASH
extern void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

#endif

float voltage = 0;
char *str;
unsigned char inta[10] = {0}, floatn[10] = {0};
unsigned char test[10] = "3";

void main(void)
{

	InitSysCtrl();
    InitGpio();
    InitSciaGpio();

    DINT;
    InitPieCtrl();
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    InitPieVectTable();
    EALLOW;
    PieVectTable.TINT0 = &cpu_timer0_isr;
    EDIS;
    IER |= M_INT1;

    InitAdc();
    ConfigAdc();

    InitCpuTimers();
    ConfigCpuTimer(&CpuTimer0, 60,500000);
    CpuTimer0Regs.TCR.bit.TSS = 0;              //CpuTimer0 Start/ReStart
    EnableInterrupts();

#ifdef TOFLASH

	MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);
	InitFlash();
#endif

	LCD_init();
	LCD_string(0, 0, "The Voltage: ");

	while(1)
	{


		//DELAY_US(1000000);
        //LCD_string2(test);
	}
}

interrupt void cpu_timer0_isr(void)
{
	CpuTimer0.InterruptCount++;

	voltage =  (3.3 * AdcResult.ADCRESULT0) / 4096.0;
	itoa(voltage);
	LCD_clear();

    LCD_string(0, 0, "The Voltage: ");
    //LCD_string(0,35, test);
    LCD_string(0, 15, inta);
	LCD_char('.');
	LCD_string2(floatn);
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void itoa(float num)
{
	int i, j, numi;
	float numf;
	numi = (int)num;
	numf = num - numi;
	for(j=0; (numi%10) != 0; j++)
	{
		*(inta+j) = (unsigned char)numi%10;
		numi /= 10;
	}
	*(inta+j) = '\0';
	for(i=0; i<3; i++)
	{
		numf *= 10;
		*(floatn+i) = (unsigned char) ((int)numf % 10);
	}
	*(floatn+i) = '\0';
}











