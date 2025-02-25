SECTION code_video_vdp

INCLUDE "video/tms9918/vdp.inc"

IFDEF V9938

PUBLIC  __v9938_4bpp_drawr
PUBLIC  __v9938_8bpp_drawr

EXTERN  __tms9918_attribute
EXTERN  __tms9918_8bpp_attr
EXTERN  __v9938_draw_line
EXTERN  __gfx_coords



; gfx_coords+1 = current x
; Entry:  de = y, hl =x (direction)
__v9938_8bpp_drawr:
    ld      a,(__tms9918_8bpp_attr)
    ld      b,a
    jr      do_draw

__v9938_4bpp_drawr:
    ld      a,(__tms9918_attribute)
    rrca
    rrca
    rrca
    rrca
    and     15
    ld      b,a

do_draw:
    ld      a,(__gfx_coords)        ;current y
    ld      c,a
    add     e
    ld      e,a
    ld      a,(__gfx_coords+1)
    ld      h,a
    add     l
    ld      d,a
    ld      l,c
    ld      a,V9938_LOGIC_SET
    ; draw LINE (H,L)-(D,E) with color B, log-op A
    jp      __v9938_draw_line
    
ENDIF
