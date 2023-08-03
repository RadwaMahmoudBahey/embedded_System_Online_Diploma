/*startup.c by radwa mahmoud*/
extern int main(void);
extern unsigned int E_TEXT;
extern unsigned int S_DATA;
extern unsigned int E_DATA;
extern unsigned int S_BSS;
extern unsigned int E_BSS;
extern unsigned int stack_top;

void reset_Handler(void);
void default_Handler(void);
void NMI_Handler(void) __attribute__ ((weak,alias("default_Handler")));
void H_fault_Handler(void) __attribute__ ((weak,alias("default_Handler")));
void MM_fault_Handler(void) __attribute__ ((weak,alias("default_Handler")));
void Bus_fault_Handler(void) __attribute__ ((weak,alias("default_Handler")));
void Usage_fault_Handler(void) __attribute__ ((weak,alias("default_Handler")));

unsigned int vectors[] __attribute__ ((section(".vectors"))) ={
	(unsigned int) &stack_top,
	(unsigned int) &reset_Handler,
	(unsigned int) &NMI_Handler,
	(unsigned int) &H_fault_Handler,
	(unsigned int) &MM_fault_Handler,
	(unsigned int) &Bus_fault_Handler,
	(unsigned int) &Usage_fault_Handler,
};
void default_Handler(void){
	reset_Handler();
}
void reset_Handler(void){
	int i;
	unsigned int DATA_SIZE = (unsigned char*)&E_DATA - (unsigned char*)&S_DATA ;
	unsigned int BSS_SIZE = (unsigned char*)&E_BSS - (unsigned char*)&S_BSS;
	unsigned char* prom = (unsigned char*)&E_TEXT;
	unsigned char* pram = (unsigned char*)&S_DATA;
	for(i=0 ; i<DATA_SIZE ; i++){
		*((unsigned char*)pram++)= *((unsigned char*)prom++);
	}
	pram = (unsigned char*)&S_BSS;
	for( i=0 ; i<BSS_SIZE ; i++){
		*((unsigned char*)pram++)= (unsigned char)0;
	}
	main();
	}