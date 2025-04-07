            xdef		_set_video_base

            
ADDRESS		equ		8
VID_HI		equ 	$FFFF8201

_set_video_base:
		    link	a6,#0
		    movem.l	d0-2/a0-2,-(sp)

        ; entering supervisor mode
            clr.l 	-(sp)
            move.w 	#$20,-(sp)
            trap	#1	
            addq.l	#6,sp

            move.l	ADDRESS(a6),d1
            lsr.l	#8,d1
            lea		VID_HI,a0
            movep.w d1,0(a0)

        ; exit supervisor mode
            move.l	d0,-(sp)
            move.w	#$20,-(sp)
            trap	#1
            addq.l	#6,sp

            movem.l (sp)+,d0-2/a0-2
            unlk	a6
            rts