        xdef    _vbl_isr
        xdef    _ikbd_isr
        xdef    _isr_pause

        xref    _do_VBL_ISR
        xref    _do_IKBD_ISR

_vbl_isr:
                movem.l d0-2/a0-2,-(sp)
                jsr     _do_VBL_ISR
                movem.l (sp)+,d0-2/a0-2
                rte


MFP_IN_SERVICE_B_REG:    equ    $FFFFFA11
IKBD_MFP_SERVICE_BIT:    equ    6

_ikbd_isr:
                movem.l d0-2/a0-2,-(sp)
                jsr     _do_IKBD_ISR
                movem.l (sp)+,d0-2/a0-2
                bclr.b  #IKBD_MFP_SERVICE_BIT,MFP_IN_SERVICE_B_REG
                rte 

NEW_MASK                equ     8

_isr_pause:
                link	a6,#0
		movem.l	d1-3/a0-2,-(sp)

		move.w  sr,d0
                move.w  d0,d3           ; saving old sr
                move.w  NEW_MASK(a6),d1
                lsl.w   #8,d1
                and.w   #$F8FF,d0
                or.w    d1,d0
                move.w  d0,sr

                move.w  d3,d0
                lsr.w   #8,d0
                and.w   #7,d0

		movem.l (sp)+,d1-3/a0-2
		unlk	a6
		rts
