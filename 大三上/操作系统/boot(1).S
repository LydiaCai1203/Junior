#include "mmu.h"

.set PROTECT_MODE_CSEG, 0x8
.set PROTECT_MODE_DSEG, 0x10
.set CRO_PE_ON,		0x1

.globl start
start:
  .code16
  cli
  cld

  xorw		%ax,%ax
  movw		%ax,%ds
  movw		%ax,%es
  movw		%ax,%ss

  movw		$0xb800,%ax
  movw		%ax,%es
  movw		$msg1,%si
  movw		$0xbe2,%di
  movw		$24,%cx
  rep		movsb

  movw		$hellostring,%si
  movw		$0xc04,%di
  movw		$32,%cx
  rep		movsb

seta20.1:
  inb		$0x64,%al
  testb		$0x2,%al
  jnz		seta20.1

  movb		$0xd1,%al
  outb		%al,$0x64

seta20.2:
  inb		$0x64,%al
  testb		$0x2,%al
  jnz		seta20.2

  movb		$0xdf,%al
  outb		%al,$0x60

lgdtload:
  lgdt		gdtdesc

  movl		%cr0, %eax
  orl		$CRO_PE_ON, %eax
  movl		%eax, %cr0

  ljmp		$PROTECT_MODE_CSEG, $protcseg

  .code32
protcseg:
  movw		$PROTECT_MODE_DSEG, %ax
  movw		%ax, %ds
  movw		%ax, %es
  movw		%ax, %fs
  movw		%ax, %gs
  movw		%ax, %ss

  movl		$msg2, %esi
  movl		$0xb8d22, %edi
  movl		$66, %ecx
  rep		movsb

spin:
  jmp		spin

.p2align 2
gdt:
  SEG_NULL
  SEG(STA_X|STA_R, 0x0, 0xffffffff)
  SEG(STA_W, 0x0, 0xffffffff)

gdtdesc:
  .word		0x17
  .long		gdt

msg1:
  .byte 'i',0x7,'n',0x7,' ',0x7,'r',0x7,'e',0x7,'a',0x7,'l',0x7,' ',0x7,'m',0x7,'o',0x7,'d',0x7,'e',0x7
msg2:
  .byte 'i',0x7,'n',0x7,' ',0x7,'p',0xf,'r',0xf,'o',0xf,'t',0xf,'e',0xf,'c',0xf,'t',0xf,'e',0xf,'d',0xf,' ',0x7,'m',0x7,'o',0x7,'d',0x7,'e',0x7
hellostring:
  .byte ':',0xf,' ',0xc,' ',0xc,'Y',0xc,'u',0xc,'H',0xc,'a',0xc,'o',0xc,' ',0xc,'1',0xc,'6',0xc,'1',0xc,'2',0xc,'9',0xc,'1',0xc,'1',0xc

