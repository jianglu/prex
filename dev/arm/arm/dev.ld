/*
 * Linker script for driver
 */
INCLUDE config.ld
OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(driver_main)
PHDRS
{
	text PT_LOAD FILEHDR PHDRS;
	data PT_LOAD;
}
SECTIONS
{
	. = DRIVER_BASE + SIZEOF_HEADERS ;

	.text : {
		*(.text)
		*(.glue_7)
		*(.glue_7t)
	} : text = 0xff

	. = ALIGN(4);

	.rodata : {
		*(.rodata)
		*(.rodata.*)
	} : text

	.driver_table : {
		__driver_table = . ;
		*(.driver_table)
		__driver_table_end = . ;
	} : text

	.kstrtab : {
		*(.kstrtab)
	} : text

	.ksymtab ALIGN(4) : {
		*(.ksymtab)
	} : text

        . = ALIGN(4);
	.data : {
		*(.data)
	} : data

        . = ALIGN(4);
	.bss . : {
		*(.bss)
		*(COMMON)
	}

	/DISCARD/ : { *(.comment .note) }
}
