; quick clear (uses movem to reduce fetch-execute cycle overhead)
;
; takes about half the number of clock cycles as the code in clear.s, and
; so runs in about 1/100th of a second (at 8MHz) instead of 1/50th

		xdef		_clear_screen

base		equ		64		; offset from SP, not A6

_clear_screen:
		movem.l		d0-7/a0-6,-(sp)	; save state of registers
		lea		zeros,a0	; zeros (13 longs sequentially)
		movem.l		(a0)+,d1-7/a1-6	; put 0s into all unused registers
		movea.l		base(sp),a0	; put address of frame buffer into a0 to loop
		adda.l		#32000,a0	; bytes to clear, go backwards 
		move.w		#614,d0		; is 8k longs, 8000//13 is 615, with remainder of 5 
fill_loop:
		movem.l		d1-7/a1-6,-(a0) ; loop to put 0s from registers into a0 (faster with movem)
		dbra		d0,fill_loop	; dbra for loop
		movem.l		d1-5,-(a0)	; remainder of 5 for last 5 longs to clear
		movem.l		(sp)+,d0-7/a0-6 ; restore registers
		rts

zeros:		ds.l		13
