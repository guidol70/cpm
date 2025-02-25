#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "defs.h"
#include "vt.h"

z80info *z80term; /* terminal controller */

int last = -1;

int kpoll(int w)
{
	int c;
	unsigned char d;
	int tries;
	if (last != -1) {
		c = last;
		last = -1;
		return c;
	}
	for (tries = 0; tries != 1; ++tries) {
#ifndef _WIN32
		int flags;
		if (w) {
			flags = fcntl(fileno(stdin), F_GETFL);
			fcntl(fileno(stdin), F_SETFL, flags | O_NONBLOCK);
		}
#endif
		c = read(fileno(stdin), &d, 1);
#ifndef _WIN32
		if (w) {
			fcntl(fileno(stdin), F_SETFL, flags);
		}
#endif
		if (c == 1) {
/*			printf("\r\nkpoll got %d \r\n", d); */
			return d;
		}
/*		usleep(1); */
	}
/*	printf("\r\n--- no char after esc? ---\r\n"); fflush(stdout); */
	return -1;
}

int constat()
{
	if (last != -1)
		return 1;
	last = kpoll(1);
	if (last != -1)
		return 1;
	else
		return 0;
}

/* Input FIFO */

#define FIFO_SIZE 4
int stuff[FIFO_SIZE];
int stuff_ptr;

void kpush(int c)
{
	if (c != -1 && stuff_ptr != FIFO_SIZE) {
		stuff[stuff_ptr++] = c;
	}
}

int kget(int w)
{
        int c;
        if (stuff_ptr) {
        	int x;
        	c = stuff[0];
        	for (x = 0; x != stuff_ptr - 1; ++x) {
        		stuff[x] = stuff[x + 1];
        	}
		stuff_ptr--;
        	stuff[x] = 0;
        	return c;
        }

        c = kpoll(w);
        if (c != 27) {
                return c;
        }
        /* We got ESC.. see if any chars follow */
        c = kpoll(1);

        if (c == -1) { /* Just ESC */
        	return 27;
        } else if (c == '[') {
                c = kpoll(0);
                if (c == 'A') { /* Up arrow */
                        return 'E' - '@';
                } else if (c == 'B') { /* Down arrow */
                        return 'X' - '@';
                } else if (c == 'C') { /* Right arrow */
                        return 'D' - '@';
                } else if (c == 'D') { /* Left arrow */
                        return 'S' - '@';
                } else if (c == '3') { /* Delete key */
                        c = kpoll(0);
                        return 'G' - '@';
                } else if (c == '2') { /* Insert key */
                        c = kpoll(0);
                        return 'V' - '@';
                } else if (c == '5') { /* PgUp */
                        c = kpoll(0);
                        return 'R' - '@';
                } else if (c == '6') { /* PgDn */
                        c = kpoll(0);
                        return 'C' - '@';
                } else if (c == '1' || c == '7') { /* Home */
                	kpush('s');
                        c = kpoll(0);
                        return 'Q' - '@';
                } else if (c == '4' || c == '8') { /* End */
                        kpush('d');
                        c = kpoll(0);
                        return 'Q' - '@';
                } else if (c == 'H') { /* Home */
                        kpush('s');
                        return 'Q' - '@';
                } else if (c == 'F') { /* End */
                        kpush('d');
                        return 'Q' - '@';
                } else {
                	kpush('[');
                	kpush(c);
                        return 27;
		}
        } else if (c == 'O') {
                c = kpoll(0);
                if (c == 'A') { /* Up arrow */
                        return 'E' - '@';
                } else if (c == 'B') { /* Down arrow */
                        return 'X' - '@';
                } else if (c == 'C') { /* Right arrow */
                        return 'D' - '@';
                } else if (c == 'D') { /* Left arrow */
                        return 'S' - '@';
                } else if (c == 'd') { /* Ctrl left arrow (rxvt) */
                        return 'A' - '@';
                } else if (c == 'c') { /* Ctrl right arrow (rxvt) */
                        return 'F' - '@';
                } else if (c == 'H') { /* Home */
                        kpush('s');
                        return 'Q' - '@';
                } else if (c == 'F') { /* End */
                        kpush('d');
                        return 'Q' - '@';
		} else if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') {
			return INTR_CHAR;
                } else {
                	kpush('O');
                	kpush(c);
                	return 27;
		}
        } else {
        	kpush(c);
        	return 27;
        }
}

/*
[5~ PgUp
[6~ PgDn
[7~ Home
[8~ End
Od  Ctrl-Ltarw
Oc  Ctrl-Rtarw
*/

void putch(int c) {	/* output character without postprocessing */
    write(fileno(stdout), &c, 1);
}

void putmes(const char *s) {
    write(fileno(stdout), s, strlen(s));
}

void vt52(int c) {	/* simple vt52,adm3a => ANSI conversion */
	z80info *z80 = z80term;
    static int state = 0, x, y;
    char buff[32];
    static int pix = 0;
    static int parse = 0;
#ifdef DEBUGLOG
    static FILE *log = NULL;
    if (!log)
	log = fopen("cpm.out", "w");
    fputc(c, log);
#endif
    if(c == 0x1d) /* GS ^] */ {
	/* escape sequence close/reset */
	state = 0;
	return;
    }
    switch (state) {
    case 0:
	switch (c) {
		/* Jacko override put CTRL */
		/*^ the irony of LF equates to VT when the CR is not auto (the LF/CR what do auto point?) */
		/* Always pass ^D */
		case 0: /* NUL (C string terminal, but nothing as a SYN duplicate but zero, so flash default) */
			break;
		case 6: /* ACK (got you) */
			putmes("\033[92m"); /* green ^F */
			break;
		case 0xe: /* SO ^N */
			putmes("\033[37m"); /* cyan, wakey, not RYGB or M */
			break;
		case 0xf: /* SI ^O */
			putmes("\033[0m"); /* default */
			break;
		case 0x10: /* DLE (ask root RPC options) */
			putmes("\033[95m"); /* magenta ^P */
			break;
		case 0x11: /* DC1 (user do) */
			putmes("\033[94m"); /* blue ^Q */ /* XON */
			break;
		case 0x14: /* DC4 (user undo) */
			putmes("\033[93m"); /* yellow ^T */
			break;
		case 0x15: /* NAK (say waht?) */
			putmes("\033[91m"); /* red ^U */
			break;
		case 0x16: /* SYN (achives phase lock so needs bit changes) ^V */
			putmes(" \033[91mThe body of Christ. Blessed Mary Mother of God. Hands together for holy code handling. Like an 'er gin, boop, boop. Touched for the very first time. \033[0m ");
			/* the best constant syn jokes are the best */
			break;
		case 0x17: /* ETB (back later, busy) ^W */
			putmes(" \033[92m'$\033[0m ");
			/* I believe */
			break;
		case 0x19: /* EM (back later, must buy magnetic media) ^Y */
			/* Hard limit indicator */
			putmes(" \033[92mYou are in a queue. All our operatives are using remote controls. We'll get back to you as soon a possible.\033[0m ");
			break;
		case 0x1c: /* FS ^\ */
			state = 10; /* escape control literal */
			break;
		/* case 0x1e: / RS ^^ / adm3a - home */
		case 0x1f: /* US ^_ (used on input to enter monitor) */
			printf("\r\n^_ (AF=%04x BC=%04x DE=%04x HL =%04x SP=%04x)\n", AF, BC, DE, HL, SP);
			break; /* better */
			
#ifdef VBELL
        case 0x07:              /* BEL: flash screen */
            putmes("\033[?5h\033[?5l");
	    break;
#endif
	case 0x7f:		/* DEL: echo BS, space, BS */
	    putmes("\b \b");
	    break;
	case 0x1a:		/* adm3a clear screen */
	case 0x0c:		/* vt52 clear screen */
	    putmes("\033[H\033[2J");
	    break;
	case 0x1e:		/* adm3a cursor home */
	    putmes("\033[H");
	    break;
	case 0x1b:
	    state = 1;	/* esc-prefix */
	    break;
	case 1:
	    state = 2;	/* cursor motion prefix */
	    break;
	case 2:		/* insert line */
	    putmes("\033[L");
	    break;
	case 3:		/* delete line */
	    putmes("\033[M");
	    break;
	case 0x18: case 5:	/* clear to eol */
	    putmes("\033[K");
	    break;
	case 0x12: case 0x13: /* DC2, DC3 / ^R, ^S (XOFF) */
	    break;
	default:
	    putch(c);
	}
	break;
    case 1:	/* esc was sent */
	switch (c) {
        case 0x1b:
	    putch(c);
	    break;
	case '=':
	case 'Y': /* adm3a steals vt52 ESC A to D cursor option */
	    state = 2;
	    break;
	case 'E':	/* insert line */
	    putmes("\033[L");
	    break;
	case 'R':	/* delete line */
	    putmes("\033[M");
	    break;
	case 'B':	/* enable attribute */
	    state = 4;
	    break;
	case 'C':	/* disable attribute */
	    state = 5;
	    break;
        case 'L':       /* set line */
        case 'D':       /* delete line */
            state = 6;
            break;
	case '*':       /* set pixel */
	case ' ':       /* clear pixel */
	    state = 2;
	    pix = c;
	    break;
	case 'S':	/* hook for fun */
	    state = 11;
	    break;
	default:		/* some true ANSI sequence? */
	    state = 0;
	    putch(0x1b);
	    putch(c);
	}
	break;
    case 2:
	y = c - ' '+1;
	state = 3;
	break;
    case 3:
	x = c - ' '+1;
	state = 0;
	if(pix == 0) {
		sprintf(buff, "\033[%d;%dH", y, x);
		putmes(buff);
	} else {
		/* set or clear pixel (remember cursor) */
		putmes("\033[s");
		sprintf(buff, "\033[%d;%dH", y, x);
		putmes(buff);
		if(pix == '*') {
			/* set pixel */
			putmes("μ"); /* SI for real micro computing joke 0xB5 Socio-economic classifications et al? */
		} else {
			/* clear pixel */
			putch(' ');
		}
		putmes("\033[u");
		pix = 0;
	}
	break;
    case 4:	/* <ESC>+B prefix */
        state = 0;
        switch (c) {
	case '0': /* start reverse video */
	    putmes("\033[7m");
	    break;
	case '1': /* start half intensity */
	    putmes("\033[1m");
	    break;
	case '2': /* start blinking */
	    putmes("\033[5m");
	    break;
	case '3': /* start underlining */
	    putmes("\033[4m");
	    break;
	case '4': /* cursor on */
	    putmes("\033[?25h");
	    break;
	case '6': /* remember cursor position */
	    putmes("\033[s");
	    break;
	case '5': /* video mode on */
	case '7': /* preserve status line */
	    break;
	default:
	    putch(0x1b);
	    putch('B');
	    putch(c);
        }
	break;
    case 5:	/* <ESC>+C prefix */
        state = 0;
        switch (c) {
	case '0': /* stop reverse video */
	    putmes("\033[27m");
	    break;
	case '1': /* stop half intensity */
	    putmes("\033[m");
	    break;
	case '2': /* stop blinking */
	    putmes("\033[25m");
	    break;
	case '3': /* stop underlining */
	    putmes("\033[24m");
	    break;
	case '4': /* cursor off */
	    putmes("\033[?25l");
	    break;
	case '6': /* restore cursor position */
	    putmes("\033[u");
	    break;
	case '5': /* video mode off */
	case '7': /* don't preserve status line */
		/* what custom status line? what no video? */
		/* inbuilt obsolecence of apps? */
	    putmes(" \033[92mShinny, shinny. Shinny piece of metal. Empty wallet, here are some ads.\033[0m ");
	    break;
	default:
	    putch(0x1b);
	    putch('C');
	    putch(c);
        }
	break;
/* set/clear line/point */
    case 6:
    case 7:
    case 8:
        state ++;
	break;
    case 9:
	state = 0;
	break;
/* control literal */
    case 10:
	state = 0;
	if(c < 32) {
		putmes("\033[90m^"); /* literal escape (bold) */
		putch(c + 64); /* code CTRL +32 is space gen slow, but funny */  
		putmes("\033[0m");
	} else putch(c);
	break;	
    case 11: /* ESC S prefixed */
        /* fun hook */
        switch(c) {
        case ' ': /* no operation */
        default:
        	break;
        /* the added extra codes with functioning beyond character absorbtion
           set paree to non-zero to remain in sequence parsing.
           This removes the affectation of state beyond a well defined single state. */
        
        }
        if(!parse) {
        	state = 0; /* auto exit after character process */
        parse = 0; /* oops! ready for later */
    	break;    
    } 
}
