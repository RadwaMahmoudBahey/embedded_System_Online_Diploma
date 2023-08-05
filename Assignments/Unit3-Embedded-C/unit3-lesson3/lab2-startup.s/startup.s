//startup.s lab 2 by radwa mahmoud
.section .vectors
.word 0x20001000 /*the address assigned to the stack pointer*/
.word _reset
.word _vector_handler 		/* 2 NMI */
.word _vector_handler		/* 3 MM FAULT */
.word _vector_handler		/* 4 BUS FAULT */
.word _vector_handler		/* 5 USAGE FAULT */
.word _vector_handler		/* 6 HARD FAULT */
.word _vector_handler		/* 7 REVERSED */
.word _vector_handler		/* 8 REVERSED */
.word _vector_handler		/* 9 REVERSED */
.word _vector_handler		/* 10 REVERSED */
.word _vector_handler		/* 11 SV call */
.word _vector_handler		/* 12 DEBUG reversed */
.word _vector_handler		/* 13 REVERSED */
.word _vector_handler		/* 14 PondSV */
.word _vector_handler		/* 15 SysTic */
.word _vector_handler		/* 16 IRQ0 */
.word _vector_handler		/* 17 IRQ1 */
.word _vector_handler		/* 18 IRQ2 */
.word _vector_handler		/* 19 ... */
.section .text
_reset:
	bl main
	b .
.thumb_func
_vector_handler:
	b _reset