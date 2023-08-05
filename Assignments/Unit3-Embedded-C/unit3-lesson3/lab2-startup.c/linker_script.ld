/*linker script lab 2 by radwa mahmoud*/
MEMORY
{
	flash(RX) :ORIGIN = 0x08000000 , LENGTH = 128K
	sram(rwx):ORIGIN = 0x20000000 , LENGTH = 20K
}
SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		E_TEXT = .;
	}> flash

	.data :
	{
		S_DATA = .;
		*(.data)
		. = ALIGN(4);
		E_DATA = .;
	}> sram AT> flash
	.bss :
	{
		S_BSS = .;
		*(.bss)
		. = ALIGN(4);
		E_BSS = .;
		. = ALIGN(4);
		. = . + 0x1000;
		stack_top = . ;
	}> sram
}