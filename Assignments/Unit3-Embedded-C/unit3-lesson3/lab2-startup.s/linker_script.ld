/*linker script lab 2 by radwa mahmoud*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
	sram (rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
	}> flash
	.data :
	{
		*(.data)
	}> flash
	.bss :
	{
		*(.bss)
	}> sram
}