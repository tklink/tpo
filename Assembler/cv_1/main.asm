; Created: 22.09.2018
; Author : Albert Klinkovský




.def acc = r23	;promenna
.def bcc = r24	;promenna

init:
	ldi bcc, $00	;nastaveni portk jako vstupni
	sts ddrk, bcc
	ldi bcc, $ff
	out ddrf, bcc	;nastaveni portf jako vystupni
	
start:
	lds	bcc, portk
	mov acc, bcc

	rol acc	;rotace v levo poprve
	rol acc	;rotace v levo podruhe

	or bcc, acc ;logicky soucet bcc a acc

	out	portf, bcc
	rjmp start
