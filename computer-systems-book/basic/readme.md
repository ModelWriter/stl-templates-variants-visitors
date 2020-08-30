```c
long mult2(long, long);

void multstore(long x, long y, long *dest) {
  long t = mult2(x, y);
  *dest = t;
}
```

```shell script
gcc -Og -S mstore.c
```

```asm
	.file	"mstore.c"
	.text
	.globl	multstore
	.type	multstore, @function
multstore:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %rbx
	call	mult2@PLT
	movq	%rax, (%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	multstore, .-multstore
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
```

```shell script
gcc -Og -c mstore.c
objdump -d mstore.o 
```

```
mstore.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <multstore>:
   0:   f3 0f 1e fa             endbr64 
   4:   53                      push   %rbx
   5:   48 89 d3                mov    %rdx,%rbx
   8:   e8 00 00 00 00          callq  d <multstore+0xd>
   d:   48 89 03                mov    %rax,(%rbx)
  10:   5b                      pop    %rbx
  11:   c3                      etq   
```

```c
#include <stdio.h>

void multstore(long, long, long *);

int main() {
  long d;
  multstore(2, 3, &d);
  printf("2 * 3 --> %1d\n", d);
  return 0;
}

long mult2(long a, long b) {
  long s = a * b;
  return s;
}
```

```shell script
gcc -Og -o prog main.c mstore.c
objdump -d prog > prog.o.dump
```

```
00000000000011d5 <multstore>:
    11d5:	f3 0f 1e fa          	endbr64 
    11d9:	53                   	push   %rbx
    11da:	48 89 d3             	mov    %rdx,%rbx
    11dd:	e8 e7 ff ff ff       	callq  11c9 <mult2>
    11e2:	48 89 03             	mov    %rax,(%rbx)
    11e5:	5b                   	pop    %rbx
    11e6:	c3                   	retq   
    11e7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    11ee:	00 00 
```

