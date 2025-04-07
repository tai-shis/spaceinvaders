# 1 "space.c" 1
# 1 "./space.h" 1
# 1 "C:/c68/include/stdio.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 11 "C:/c68/include/stdio.h" 2
# 20 "C:/c68/include/stdio.h"
typedef unsigned long  size_t;
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 12 "./space.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 13 "./space.h" 2
# 1 "./render.h" 1
# 1 "./model.h" 1
# 1 "./types.h" 1
# 11 "./types.h"
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

typedef void (*Vector)();
# 13 "./model.h" 2
# 1 "./effects.h" 1
# 1 "./psg.h" 1
# 1 "./TYPES.H" 1
# 12 "./psg.h" 2
# 19 "./psg.h"
 void write_psg(int reg, UINT8 val);
# 26 "./psg.h"
 void set_tone(int channel, int tuning);
# 33 "./psg.h"
 void set_volume(int channel, int volume);
# 41 "./psg.h"
 void enable_channel(int channel, int tone_on, int noise_on);




 void stop_sound();





 void set_noise(UINT8 tuning);
# 59 "./psg.h"
 void set_envelope(UINT8 shape, UINT16 sustain);
# 66 "./psg.h"
 UINT8 read_psg(int reg);
# 12 "./effects.h" 2





void play_shoot();




void play_hit();




void play_game_over();
# 14 "./model.h" 2


typedef struct Player {
    UINT16 x, y;
    UINT8 l, w;
    UINT8 lives;
    int delta_x;
    int bullet_type;
} Player;

typedef struct Alien {
    UINT32 x, y;
    UINT8 l, w;
    int score;
    int alive;

} Alien;

typedef struct Aliens{
    Alien array[5][9];
    Alien orig[5][9];
    UINT8 totalAliens;
    int delta_x;
    int bullet_type;
    char render;
    int lowest_alive;
    int right_alive;
    int left_alive;
    int lowest_alien[9];
} Aliens;

typedef struct Bullet {
    UINT16 x, y;
    UINT8 l, w;
    int delta_y;
    int direc;
    int is_active;
} Bullet;

typedef struct Score {
    UINT16 score;
    UINT16 x, y;
} Score;

typedef struct Model {
    Player player;
    Aliens aliens;
    Score score;
    UINT16 lowbound_x, lowbound_y, highbound_x, highbound_y;
    UINT8 alien_l, alien_w;
    int alien_dx;
    int bullet_dy;
    Bullet active[30];
    int active_count;
    int quit;
} Model;
# 77 "./model.h"
void move_player(Player *player);
# 85 "./model.h"
void alien_direc_change(Aliens *alien_arr, int alien_dx);
# 93 "./model.h"
int move_aliens(Aliens *aliens);
# 101 "./model.h"
int lower_aliens(Model *model, int highbound, int alien_dx);
# 109 "./model.h"
void destroy_alien(Alien alien, Score curr_score);
# 117 "./model.h"
int move_bullet(Model *model, Bullet *bullet);
# 125 "./model.h"
void add_score (int score_to_add, Score curr_score);
# 134 "./model.h"
int check_aliens_hit(Model *model, Bullet *bullet);
# 144 "./model.h"
int check_row_hit(Model *model, Alien row[], Bullet *bullet);
# 153 "./model.h"
int check_player_hit(Player *player, Bullet *bullet);
# 160 "./model.h"
void update_lowest (Model *model);
# 167 "./model.h"
void update_left (Model *model);
# 174 "./model.h"
void update_right (Model *model);
# 181 "./model.h"
void lowest_alive(Aliens *aliens);
# 12 "./render.h" 2
# 1 "./raster.h" 1
# 1 "./types.h" 1
# 12 "./raster.h" 2
# 21 "./raster.h"
void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
# 30 "./raster.h"
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
# 39 "./raster.h"
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
# 49 "./raster.h"
void plot_vline(UINT8 *base, int x, int y1, int y2);
# 59 "./raster.h"
void plot_hline(UINT32 *base, int x1, int x2, int y);
# 70 "./raster.h"
void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y);
# 82 "./raster.h"
void plot_custom(UINT32 *base, int x, int y, const UINT32 *bitmap, int height, int longWidth);
# 89 "./raster.h"
UINT16 *get_video_base();
# 13 "./render.h" 2
# 1 "./bitmaps.c" 1
# 1 "./TYPES.H" 1
# 9 "./bitmaps.c" 2


UINT32 alien_maps [3][2][32] = {
    {
        {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00C00300,
            0x00C00300,
            0x00300C00,
            0x00300C00,
            0x00FFFF00,
            0x00FFFF00,
            0x03CFF3C0,
            0x03CFF3C0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x0CFFFF30,
            0x0CFFFF30,
            0x0CC00330,
            0x0CC00330,
            0x003E7C00,
            0x003E7C00,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }, {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00C00300,
            0x00C00300,
            0x0C300C30,
            0x0C300C30,
            0x0CFFFF30,
            0x0CFFFF30,
            0x0FCFF3F0,
            0x0FCFF3F0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x03FFFFC0,
            0x03FFFFC0,
            0x00C00300,
            0x00C00300,
            0x030000C0,
            0x030000C0,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }
    },
    {
        {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x000FF000,
            0x000FF000,
            0x03FFFFC0,
            0x03FFFFC0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x0FC3C3F0,
            0x0FC3C3F0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x00FC3F00,
            0x00FC3F00,
            0x03C3C3C0,
            0x03C3C3C0,
            0x00F00F00,
            0x00F00F00,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }, {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x000FF000,
            0x000FF000,
            0x03FFFFC0,
            0x03FFFFC0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x0FC3C3F0,
            0x0FC3C3F0,
            0x0FFFFFF0,
            0x0FFFFFF0,
            0x003C3C00,
            0x003C3C00,
            0x00F3CF00,
            0x00F3CF00,
            0x0F0000F0,
            0x0F0000F0,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }
    },
    {
        {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x0003C000,
            0x0003C000,
            0x000FF000,
            0x000FF000,
            0x003FFC00,
            0x003FFC00,
            0x00F3CF00,
            0x00F3CF00,
            0x00FFFF00,
            0x00FFFF00,
            0x0033CC00,
            0x0033CC00,
            0x00C00300,
            0x00C00300,
            0x00300C00,
            0x00300C00,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }, {
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x0003C000,
            0x0003C000,
            0x000FF000,
            0x000FF000,
            0x003FFC00,
            0x003FFC00,
            0x00F3CF00,
            0x00F3CF00,
            0x00FFFF00,
            0x00FFFF00,
            0x000C3000,
            0x000C3000,
            0x0033CC00,
            0x0033CC00,
            0x00CC3300,
            0x00CC3300,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000,
            0x00000000
        }
    }
};

UINT32 player_bitmap[32] = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00018000,
    0x00018000,
    0x0007E000,
    0x0007E000,
    0x0007E000,
    0x0007E000,
    0x0007E000,
    0x0007E000,
    0x3FFFFFFC,
    0x3FFFFFFC,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF
};

UINT8 bullet_bitmaps[2][16] = {
    {
        0x60,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0x90
    }, {
        0x90,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0xF0,
        0x60
    }
};

UINT16 nums[10][16] = {
    {
        0x07E0,
        0x07E0,
        0x1818,
        0x1818,
        0x1818,
        0x1878,
        0x1878,
        0x1998,
        0x1998,
        0x1E18,
        0x1E18,
        0x1818,
        0x1818,
        0x1818,
        0x07E0,
        0x07E0
    }, {
        0x0180,
        0x0180,
        0x0780,
        0x0780,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x0180,
        0x07E0,
        0x07E0
    }, {
        0x03C0,
        0x03C0,
        0x0C30,
        0x0C30,
        0x0030,
        0x0030,
        0x0030,
        0x0030,
        0x03C0,
        0x03C0,
        0x0C00,
        0x0C00,
        0x0C00,
        0x0C00,
        0x0FF0,
        0x0FF0
    }, {
        0x03C0,
        0x03C0,
        0x0C30,
        0x0C30,
        0x0030,
        0x0030,
        0x0030,
        0x01C0,
        0x01C0,
        0x0030,
        0x0030,
        0x0030,
        0x0C30,
        0x0C30,
        0x03C0,
        0x03C0
    }, {
        0x0030,
        0x0030,
        0x00F0,
        0x00F0,
        0x00F0,
        0x0330,
        0x0330,
        0x0330,
        0x0C30,
        0x0C30,
        0x0C30,
        0x0C30,
        0x0FF8,
        0x0FF8,
        0x0030,
        0x0030
    }, {
        0x0FF0,
        0x0FF0,
        0x0C00,
        0x0C00,
        0x0C00,
        0x0C00,
        0x0C00,
        0x0C00,
        0x03F0,
        0x03F0,
        0x000C,
        0x000C,
        0x080C,
        0x080C,
        0x07F0,
        0x07F0
    }, {
        0x01F0,
        0x01F0,
        0x0600,
        0x0600,
        0x1800,
        0x1800,
        0x1800,
        0x1800,
        0x1FE0,
        0x1FE0,
        0x1818,
        0x1818,
        0x1818,
        0x1818,
        0x07E0,
        0x07E0
    }, {
        0x0FF0,
        0x0FF0,
        0x0C30,
        0x0C30,
        0x0030,
        0x0030,
        0x00C0,
        0x00C0,
        0x0300,
        0x0300,
        0x0300,
        0x0300,
        0x0300,
        0x0300,
        0x0300,
        0x0300
    }, {
        0x07E0,
        0x07E0,
        0x1818,
        0x1818,
        0x1818,
        0x1818,
        0x1818,
        0x07E0,
        0x07E0,
        0x1818,
        0x1818,
        0x1818,
        0x1818,
        0x1818,
        0x07E0,
        0x07E0
    }, {
        0x03E0,
        0x03E0,
        0x0C18,
        0x0C18,
        0x0C18,
        0x0C18,
        0x0C18,
        0x0C18,
        0x03F8,
        0x03F8,
        0x0018,
        0x0018,
        0x0018,
        0x0018,
        0x03E0,
        0x03E0
    }
};

UINT16 heart[16] = {
    0x0000,
    0x0000,
    0x1C38,
    0x3E7C,
    0x7FFE,
    0x7FFE,
    0x7FFE,
    0x7FFE,
    0x3FFC,
    0x1FF8,
    0x0FF0,
    0x07E0,
    0x03C0,
    0x0180,
    0x0000,
    0x0000
};

UINT16 broken_heart[16] = {
    0x0000,
    0x0000,
    0x381C,
    0x7C3E,
    0xFE7F,
    0xFCFF,
    0xF9FF,
    0xFCFF,
    0x7E7E,
    0x3CFC,
    0x19F8,
    0x0CF0,
    0x0660,
    0x0240,
    0x0000,
    0x0000
};

UINT8 mouse[8] = {
    0xC0,
    0xF0,
    0x60,
    0x50,
    0x08,
    0x06,
    0x02,
    0x00
};

UINT32 title_bitmap[] = {
    0x3FFFFFC3L, 0xFFFFFF0FL, 0xFFFFFC0FL, 0xFFFFFC7FL, 0xFFFFF000L, 0x7F100003L, 0xF87F0000L, 0xFE3FFFFFL, 0xF81FFFFEL, 0x007FFFFFL, 0xE1FFFFFFL, 0xC03FFFFFL, 0x7FFFFF83L, 0xFFFFFF0FL, 0xFFFFFC0FL, 0xFFFFFC7FL, 0xFFFFE000L, 0x7F1C0003L, 0xF83F8001L, 0xFC3FFFFFL, 0xF81FFFFEL, 0x007FFFFFL, 0xC1FFFFFFL, 0xC07FFFFFL, 0x7FFFFF03L, 0xFFFFFF0FL, 0xFFFFFC0FL, 0xFFFFF87FL, 0xFFFFC000L, 0x7F1E0003L, 0xF83F8001L, 0xFC3FFFFFL,
    0xF81FFFFFL, 0x007FFFFFL, 0x81FFFFFFL, 0xC0FFFFFEL, 0xFF800003L, 0xF8007F0FL, 0xE003FC0FL, 0xE000007FL, 0x80000000L, 0x7F1F0003L, 0xF81FC003L, 0xF83FC007L, 0xF81FC07FL, 0x807F0000L, 0x01FC001FL, 0xC1FF0000L, 0xFF000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC003L, 0xF81FC003L, 0xF03FC007L, 0xF81FC03FL, 0x807F0000L, 0x01FC001FL, 0xC1FF0000L, 0xFE000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL,
    0x00000000L, 0x7F1FE003L, 0xF80FE007L, 0xF03FC007L, 0xF81FC01FL, 0xC07F0000L, 0x01FC001FL, 0xC1FE0000L, 0xFE000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FF803L, 0xF807E007L, 0xE03FC007L, 0xF81FC01FL, 0xC07F0000L, 0x01FC001FL, 0xC1FE0000L, 0xFE000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FFC03L, 0xF807F00FL, 0xE03FC007L, 0xF81FC00FL, 0xE07F0000L, 0x01FC001FL, 0xC1FE0000L,
    0xFE000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FFF03L, 0xF803F00FL, 0xC03FC007L, 0xF81FC007L, 0xF07F0000L, 0x01FC001FL, 0xC1FE0000L, 0xFE000003L, 0xF8007F0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FFF83L, 0xF803F81FL, 0xC03FC007L, 0xF81FC007L, 0xF07F0000L, 0x01FDFFFFL, 0xC1FE0000L, 0xFFFFFFE3L, 0xF8007F0FL, 0xFFFFFC0FL, 0xE000007FL, 0xFFFFE000L, 0x7F1FFFC3L, 0xF801F81FL, 0x803FFFFFL,
    0xF81FC003L, 0xF87FFFFFL, 0xC1FCFFFFL, 0xC1FFFFFFL, 0xFFFFFFE3L, 0xF8007F0FL, 0xFFFFFC0FL, 0xE000007FL, 0xFFFFE000L, 0x7F1FDFF3L, 0xF801FC3FL, 0x803FFFFFL, 0xF81FC001L, 0xFC7FFFFFL, 0xC1FC7FFFL, 0xC1FFFFFFL, 0xFFFFFFE3L, 0xFFFFFF0FL, 0xFFFFFC0FL, 0xE000007FL, 0xFFFFE000L, 0x7F1FC7FFL, 0xF800FC3FL, 0x003FFFFFL, 0xF81FC003L, 0xFC7FFFFFL, 0xC1FC3FFFL, 0xC1FFFFFFL, 0xFFFFFFE3L, 0xFFFFFF0FL, 0xFFFFFC0FL, 0xE000007FL,
    0xFFFFE000L, 0x7F1FC3FFL, 0xF800FE7FL, 0x003FFFFFL, 0xF81FC003L, 0xF87FFFFFL, 0xC1FC1FE0L, 0x01FFFFFFL, 0x00001FE3L, 0xFFFFFF0FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC0FFL, 0xF8007E7EL, 0x003FC003L, 0xF81FC007L, 0xF87F0000L, 0x01FC0FF0L, 0x0000003FL, 0x00001FE3L, 0xF800000FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC07FL, 0xF8007FFEL, 0x003FC003L, 0xF81FC00FL, 0xF07F0000L, 0x01FC0FF8L, 0x0000003FL,
    0x00001FE3L, 0xF800000FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC03FL, 0xF8003FFCL, 0x003FC003L, 0xF81FC00FL, 0xF07F0000L, 0x01FC07FCL, 0x0000003FL, 0x00001FE3L, 0xF800000FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC00FL, 0xF8003FFCL, 0x003FC003L, 0xF81FC01FL, 0xE07F0000L, 0x01FC03FEL, 0x0000003FL, 0x00001FE3L, 0xF800000FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC007L, 0xF8001FF8L, 0x003FC003L,
    0xF81FC01FL, 0xE07F0000L, 0x01FC01FFL, 0x0000003FL, 0x00003FE3L, 0xF800000FL, 0xE001FC0FL, 0xE000007FL, 0x00000000L, 0x7F1FC001L, 0xF8001FF8L, 0x003FC003L, 0xF81FC03FL, 0xC07F0000L, 0x01FC00FFL, 0x8000003FL, 0x00007FC3L, 0xF800000FL, 0xE001FC0FL, 0xF000007FL, 0x80000000L, 0x7F1FC000L, 0xF8000FF0L, 0x003FC003L, 0xF81FC07FL, 0xC07F0000L, 0x01FC007FL, 0x8000007FL, 0x7FFFFF83L, 0xF800000FL, 0xE001FC0FL, 0xFFFFFC7FL,
    0xFFFFC000L, 0x7F1FC000L, 0x78000FF0L, 0x003FC003L, 0xF81FFFFFL, 0x807FFFFFL, 0xC1FC003FL, 0xC07FFFFFL, 0x3FFFFF03L, 0xF800000FL, 0xE001FC0FL, 0xFFFFF87FL, 0xFFFFE000L, 0x7F1FC000L, 0x180007E0L, 0x003FC003L, 0xF81FFFFFL, 0x807FFFFFL, 0xC1FC001FL, 0xE03FFFFEL, 0x1FFFFC03L, 0xF800000FL, 0xE001FC0FL, 0xFFFFF07FL, 0xFFFFF000L, 0x7F1FC000L, 0x000003C0L, 0x003FC003L, 0xF81FFFFFL, 0x007FFFFFL, 0xE1FC001FL, 0xF01FFFFCL
};

UINT32 start_bitmap[] = {
    0x000007FFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFF800000L, 0x000FFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFF8000L, 0x00FFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFE00L, 0x0FFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFC0L, 0x3FFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFF0L, 0x7FFFF800L, 0x00000000L,
    0x00000000L, 0x00000000L, 0x00000000L, 0x007FFFF8L, 0xFFF80000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00007FFCL, 0xFF000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x000003FCL, 0xFC000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L,
    0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF800FFF1L, 0xFFFC7FFEL, 0x1FFF8FFFL, 0xF00FFF87L, 0xFFE20004L, 0x7FFE007CL, 0xF801FFE0L, 0xFFF87FFEL, 0x1FFF87FFL, 0xE00FFF07L, 0xFFE3000CL, 0x7FFE007CL, 0xF801E000L, 0x0780781EL, 0x1C03803EL, 0x000F0007L, 0x81E3C03CL, 0x7800007CL,
    0xF801E000L, 0x0780781EL, 0x1C03803EL, 0x000F0007L, 0x81E3E07CL, 0x7800007CL, 0xF801E000L, 0x0780781EL, 0x1C03803EL, 0x000F0007L, 0x81E3F9FCL, 0x7800007CL, 0xF801E000L, 0x07807C1EL, 0x1DFF803EL, 0x000F0007L, 0x81E3FFFCL, 0x7C00007CL, 0xF801FFF8L, 0x07807FFEL, 0x1CFF803EL, 0x000F0387L, 0xFFE3CFBCL, 0x7FFE007CL, 0xF80000F8L, 0x07807C1EL, 0x1C7C003EL, 0x000F0387L, 0x81E3C63CL, 0x7C00007CL, 0xF8000078L, 0x0780781EL,
    0x1C3E003EL, 0x000F0387L, 0x81E3C03CL, 0x7800007CL, 0xF8000078L, 0x0780781EL, 0x1C1F003EL, 0x000F0387L, 0x81E3C03CL, 0x7800007CL, 0xF8000078L, 0x0780781EL, 0x1C0F803EL, 0x000F0387L, 0x81E3C03CL, 0x7800007CL, 0xF801FFF0L, 0x0780781EL, 0x1C07803EL, 0x000FFF87L, 0x81E3C03CL, 0x7FFE007CL, 0xF800FFE0L, 0x0780781EL, 0x1C03C03EL, 0x000FFF87L, 0x81E3C03CL, 0x7FFE007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L,
    0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xF8000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000007CL, 0xFC000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x000000FCL,
    0xFF800000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x000007FCL, 0x7FFC0000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x0000FFF8L, 0x3FFFFF80L, 0x00000000L, 0x00000000L, 0x00000000L, 0x00000000L, 0x07FFFFF8L, 0x1FFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFE0L, 0x07FFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFF80L, 0x007FFFFFL, 0xFFFFFFFFL,
    0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFF800L, 0x0003FFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFF0000L, 0x0000007FL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xFFFFFFFFL, 0xF0000000L, 0x00000000L
};

UINT32 quit_bitmap[] = {
    0x003FFFFFL, 0xFFFFFFFFL, 0xFFE00000L, 0x01FFFFFFL, 0xFFFFFFFFL, 0xFFFC0000L, 0x0FFFFFFFL, 0xFFFFFFFFL, 0xFFFF8000L, 0x1FFFFFFFL, 0xFFFFFFFFL, 0xFFFFE000L, 0x7FFFFFFFL, 0xFFFFFFFFL, 0xFFFFF000L, 0x7FE00000L, 0x00000000L, 0x003FF000L, 0xFE000000L, 0x00000000L, 0x0003F800L, 0xFC000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L,
    0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF801FFFCL, 0x701E79FFL, 0xFC00F800L, 0xF801FFFCL, 0x701E78FFL, 0xF800F800L, 0xF801E07CL, 0x701E7807L, 0x8000F800L, 0xF801E07CL, 0x701E7807L, 0x8000F800L, 0xF801E07CL, 0x701E7807L, 0x8000F800L, 0xF801E07CL, 0x701E7807L, 0x8000F800L, 0xF801E0FCL, 0x701E7807L, 0x8000F800L, 0xF801E3FCL,
    0x701E7807L, 0x8000F800L, 0xF801E1FCL, 0x701E7807L, 0x8000F800L, 0xF801E0F8L, 0x701E7807L, 0x8000F800L, 0xF801E1FCL, 0x701E7807L, 0x8000F800L, 0xF801FFFEL, 0x7FFE7807L, 0x8000F800L, 0xF801FFDEL, 0x7FFE7807L, 0x8000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L, 0xF8000000L, 0x00000000L, 0x0000F800L,
    0xFC000000L, 0x00000000L, 0x0001F800L, 0xFF000000L, 0x00000000L, 0x0007F800L, 0x7FF80000L, 0x00000000L, 0x00FFF000L, 0x3FFFFFFFL, 0xFFFFFFFFL, 0xFFFFE000L, 0x1FFFFFFFL, 0xFFFFFFFFL, 0xFFFFC000L, 0x07FFFFFFL, 0xFFFFFFFFL, 0xFFFF8000L, 0x01FFFFFFL, 0xFFFFFFFFL, 0xFFFC0000L, 0x0007FFFFL, 0xFFFFFFFFL, 0xFF000000L
};
# 14 "./render.h" 2
# 23 "./render.h"
void render(const Model *model, void *base, int f);
# 31 "./render.h"
void render_player(const Player *player, UINT32 *base);
# 40 "./render.h"
void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);
# 49 "./render.h"
void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);
# 57 "./render.h"
void render_bullet(const Bullet *bullet, UINT8 *base);
# 65 "./render.h"
void render_score(const Score *score, UINT16 *base);
# 73 "./render.h"
void render_lives(UINT8 lives, UINT16 *base);
# 81 "./render.h"
void render_border(Model *model, void *base);
# 88 "./render.h"
void render_title(UINT32 *base);
# 15 "./space.h" 2
# 1 "./types.h" 1
# 16 "./space.h" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 12 "./events.h" 2
# 1 "./effects.h" 1
# 13 "./events.h" 2
# 21 "./events.h"
void async_move_player(Model *model, char key);
# 29 "./events.h"
void async_shoot(Model *model, int cooldown);
# 36 "./events.h"
void aliens_shoot(Model *model);
# 43 "./events.h"
int update_aliens(Model *model);
# 50 "./events.h"
void update_bullets(Model *model);
# 57 "./events.h"
void respawn_aliens(Model *model);
# 64 "./events.h"
int check_endgame(Model *model);




int rand();
# 17 "./space.h" 2
# 1 "./model.h" 1
# 18 "./space.h" 2
# 1 "./raster.h" 1
# 19 "./space.h" 2
# 1 "./input.h" 1
# 1 "./types.h" 1
# 11 "./input.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 12 "./input.h" 2





char keystroke();




void do_IKBD_ISR();
# 29 "./input.h"
void add_to_buffer(char ch);
# 36 "./input.h"
int get_mouse_x();
# 43 "./input.h"
int get_mouse_y();
# 50 "./input.h"
int get_mouse_button();
# 20 "./space.h" 2
# 1 "./psg.h" 1
# 21 "./space.h" 2
# 1 "./music.h" 1
# 1 "./psg.h" 1
# 12 "./music.h" 2


typedef enum{
  C = 0,
  C_SHARP,
  D,
  D_SHARP,
  E,
  F,
  F_SHARP,
  G,
  G_SHARP,
  A,
  A_SHARP,
  B
} Note;

extern const UINT16 noteTunings[12][3];




 void start_music();




 void update_music();
# 22 "./space.h" 2
# 1 "./isr.h" 1
# 1 "./music.h" 1
# 4 "./isr.h" 2
# 1 "./space.h" 1
# 5 "./isr.h" 2
# 1 "./types.h" 1
# 6 "./isr.h" 2
# 1 "./input.h" 1
# 7 "./isr.h" 2
# 1 "./raster.h" 1
# 8 "./isr.h" 2


void uninstall_vectors();

void install_vectors();

Vector install_vector(int num, Vector vector);

void do_VBL_ISR();
# 23 "./space.h" 2


extern Model model;
extern unsigned int note;
extern unsigned int animation_frame;
extern int render_request;
extern int alien_interval;
extern int in_game;




void space();
# 42 "./space.h"
int title();
# 49 "./space.h"
void asyncHandle();
# 57 "./space.h"
void syncHandle();
# 64 "./space.h"
void syncBullets();
# 72 "./space.h"
void swapBuffers (void **active, void **inactive);





UINT32 getTime();
# 1 "space.c" 2





extern void clear_screen(UINT32 base);
extern void set_video_base(UINT16 *address);

extern void vbl_isr();
extern void ikbd_isr();

unsigned int animation_frame;
unsigned int note;
int render_request;
int alien_interval;
int in_game;

UINT8 preBuffer[32255];

Model model = {
    {288, 336, 32, 32, 3, 0, 1},
    {
        {
            {
                { 0, 32, 32, 32, 150, 1},
                {32, 32, 32, 32, 150, 1},
                {64, 32, 32, 32, 150, 1},
                {96, 32, 32, 32, 150, 1},
                {128, 32, 32, 32, 150, 1},
                {160, 32, 32, 32, 150, 1},
                {192, 32, 32, 32, 150, 1},
                {224, 32, 32, 32, 150, 1},
                {256, 32, 32, 32, 150, 1}
            },
            {
                {0, 64, 32, 32, 100, 1},
                {32, 64, 32, 32, 100, 1},
                {64, 64, 32, 32, 100, 1},
                {96, 64, 32, 32, 100, 1},
                {128, 64, 32, 32, 100, 1},
                {160, 64, 32, 32, 100, 1},
                {192, 64, 32, 32, 100, 1},
                {224, 64, 32, 32, 100, 1},
                {256, 64, 32, 32, 100, 1}
            },
            {
                {0, 96, 32, 32, 75, 1},
                {32, 96, 32, 32, 75, 1},
                {64, 96, 32, 32, 75, 1},
                {96, 96, 32, 32, 75, 1},
                {128, 96, 32, 32, 75, 1},
                {160, 96, 32, 32, 75, 1},
                {192, 96, 32, 32, 75, 1},
                {224, 96, 32, 32, 75, 1},
                {256, 96, 32, 32, 75, 1}
            },
            {
                {0, 128, 32, 32, 50, 1},
                {32, 128, 32, 32, 50, 1},
                {64, 128, 32, 32, 50, 1},
                {96, 128, 32, 32, 50, 1},
                {128, 128, 32, 32, 50, 1},
                {160, 128, 32, 32, 50, 1},
                {192, 128, 32, 32, 50, 1},
                {224, 128, 32, 32, 50, 1},
                {256, 128, 32, 32, 50, 1}
            },
            {
                {0, 160, 32, 32, 25, 1},
                {32, 160, 32, 32, 25, 1},
                {64, 160, 32, 32, 25, 1},
                {96, 160, 32, 32, 25, 1},
                {128, 160, 32, 32, 25, 1},
                {160, 160, 32, 32, 25, 1},
                {192, 160, 32, 32, 25, 1},
                {224, 160, 32, 32, 25, 1},
                {256, 160, 32, 32, 25, 1}
            }
        },
        {
            {
                { 0, 32, 32, 32, 150, 1},
                {32, 32, 32, 32, 150, 1},
                {64, 32, 32, 32, 150, 1},
                {96, 32, 32, 32, 150, 1},
                {128, 32, 32, 32, 150, 1},
                {160, 32, 32, 32, 150, 1},
                {192, 32, 32, 32, 150, 1},
                {224, 32, 32, 32, 150, 1},
                {256, 32, 32, 32, 150, 1}
            },
            {
                {0, 64, 32, 32, 100, 1},
                {32, 64, 32, 32, 100, 1},
                {64, 64, 32, 32, 100, 1},
                {96, 64, 32, 32, 100, 1},
                {128, 64, 32, 32, 100, 1},
                {160, 64, 32, 32, 100, 1},
                {192, 64, 32, 32, 100, 1},
                {224, 64, 32, 32, 100, 1},
                {256, 64, 32, 32, 100, 1}
            },
            {
                {0, 96, 32, 32, 75, 1},
                {32, 96, 32, 32, 75, 1},
                {64, 96, 32, 32, 75, 1},
                {96, 96, 32, 32, 75, 1},
                {128, 96, 32, 32, 75, 1},
                {160, 96, 32, 32, 75, 1},
                {192, 96, 32, 32, 75, 1},
                {224, 96, 32, 32, 75, 1},
                {256, 96, 32, 32, 75, 1}
            },
            {
                {0, 128, 32, 32, 50, 1},
                {32, 128, 32, 32, 50, 1},
                {64, 128, 32, 32, 50, 1},
                {96, 128, 32, 32, 50, 1},
                {128, 128, 32, 32, 50, 1},
                {160, 128, 32, 32, 50, 1},
                {192, 128, 32, 32, 50, 1},
                {224, 128, 32, 32, 50, 1},
                {256, 128, 32, 32, 50, 1}
            },
            {
                {0, 160, 32, 32, 25, 1},
                {32, 160, 32, 32, 25, 1},
                {64, 160, 32, 32, 25, 1},
                {96, 160, 32, 32, 25, 1},
                {128, 160, 32, 32, 25, 1},
                {160, 160, 32, 32, 25, 1},
                {192, 160, 32, 32, 25, 1},
                {224, 160, 32, 32, 25, 1},
                {256, 160, 32, 32, 25, 1}
            }
        },
        45, 8, -1, 1, 4, 8, 0,
        {4,4,4,4,4,4,4,4,4}
    },
    { 0, 544, 8},
    0, 0, 630, 400,
    32, 32,
    8,
    4,
    {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    },
    0,0
};


int main() {
    Vector orig_VBL, orig_IKBD;
    int play;

    install_vectors();

    while (1) {
        play = title();
        if (play == 1) {
            break;
        }
        space();
        break;
    }

    uninstall_vectors();

    return 0;
}

void space() {
    UINT16 *base = get_video_base();
    void *active = (void *)base;
    void *inactive = (void *)(((UINT32)preBuffer + 255) & 0xFFFFFF00L);

    int temp;

    UINT32 timeStart, timeNow, timeElapsed, timeBefore;

    alien_interval = 75;
    animation_frame = 0;

    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    render(&model, active, 0);

    start_music();
    in_game = 1;


    while (!model.quit) {

        asyncHandle(&model);

        if (render_request == 1) {
            clear_screen((UINT32)inactive);
            render(&model, inactive, (animation_frame & 1));
            swapBuffers(&active, &inactive);
            render_request = 0;
        }



        if (model.aliens.array[model.aliens.lowest_alive][0].y > 150) {
            alien_interval = 40;
        }
        if (model.aliens.array[model.aliens.lowest_alive][0].y > 200) {
            alien_interval = 25;
        }
        if (model.aliens.array[model.aliens.lowest_alive][0].y > 250) {
            alien_interval = 10;
        }
    }
    stop_sound();
    play_game_over();


    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    set_video_base((UINT16*)base);

}

int title() {
    char ch;
    UINT16 *base = get_video_base();
    void *active = (void *)base;
    void *inactive = (void *)(((UINT32)preBuffer + 255) & 0xFFFFFF00L);

    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    render_title((UINT32 *)active);

    in_game = 2;

    while (1) {
        if (render_request == 1) {
            clear_screen((UINT32)inactive);
            render_title((UINT32 *)inactive);
            swapBuffers(&active, &inactive);
            render_request = 0;
        }

        ch = keystroke();
        switch (ch) {
            case 's':
                clear_screen((UINT32)active);
                clear_screen((UINT32)inactive);
                set_video_base((UINT16*)base);
                return 0;
            case 'q':
                clear_screen((UINT32)active);
                clear_screen((UINT32)inactive);
                set_video_base((UINT16*)base);
                return 1;
        }
    }
}

void asyncHandle() {
    char ch = keystroke();
    switch (ch) {
        case 'q':
            model.quit = 1;
            break;
        case 'a':
            async_move_player(&model, ch);
            break;
        case 'd':
            async_move_player(&model, ch);
            break;
        case ' ':
            async_shoot(&model, 0);
            break;
    }
}

void syncHandle() {



    int game_state;
    game_state = update_aliens(&model);
    aliens_shoot(&model);
    if (game_state == -1) {
        model.quit = 1;
    }


    if (check_endgame(&model)) {
        model.quit = 1;
    }
}

void syncBullets() {
    if (model.active_count > 0) {
        update_bullets(&model);
    }
}

void swapBuffers (void **active, void **inactive) {
    void *temp = *active;
    *active = *inactive;
    *inactive = temp;
    set_video_base((UINT16*)*active);
}

UINT32 getTime() {
    UINT32 *timer = (UINT32 *)0x462;
    UINT32 currTime;
    UINT32 oldSsp;

    oldSsp = _trap_1_wl((short)0x20,(long)(0)) ;
    currTime = *timer;
    _trap_1_wl((short)0x20,(long)(oldSsp)) ;

    return currTime;
}
