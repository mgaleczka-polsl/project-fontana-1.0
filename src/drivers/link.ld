ENTRY(_start)

MEMORY
{
    /* NOTE Memory address are just examples for esp32c6 architecture */
    rom (rx)  : ORIGIN = 0x42000000, LENGTH = 2M    /* 2MB memory reserved for Flash */
    ram (rwx) : ORIGIN = 0x40800000, LENGTH = 512K  /* 512KB of memory reserved for SRAM */
}

SECTIONS
{
    .text :
    {
        . = ALIGN(4);   /* Address align to 4 bytes, it is RISC-V requirement */
        KEEP(*(.init))  /* Startup section code */
        *(.text)
        *(.text.*)
        *(.rodata)      /* Data only for read */
        *(.rodata.*)
        . = ALIGN(4);
    } > rom             /* All of this memory block goes into rom */
    
    .data :
    {
        . = ALIGN(4);
        _sdata = .;     /* Save the start address of the .data section in ram */
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;     /* Save the end address of the .data section in ram */
    } > ram AT > rom    /* Variables live in ram, but its initial values lay in rom */

    .bss :
    {
        . = ALIGN(4);
        __bss_start = .;
        _sbss = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        _end = .;
    } > ram             /* This section lives only in ram */

    __global_pointer$ = MIN(ALIGN(_sdata + 0x800), ALIGN(_sbss + 0x800));

    /* NOTE Stack pointer definition lays at the end of the SECTIONS block at the end of the RAM section */
    _estack = ORIGIN(ram) + LENGTH(ram);
}