        xdef    _vbl_isr

        xref    _do_VBL_ISR

_vbl_isr:
            movem.l d0-2/a0-2,-(sp)
            jsr     _do_VBL_ISR
            movem.l (sp)+,d0-2/a0-2
            rte