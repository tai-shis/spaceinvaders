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
# 22 "./render.h"
void render(const Model *model, void *base, int f);
# 30 "./render.h"
void render_player(const Player *player, UINT32 *base);
# 39 "./render.h"
void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);
# 48 "./render.h"
void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);
# 56 "./render.h"
void render_bullet(const Bullet *bullet, UINT8 *base);
# 64 "./render.h"
void render_score(const Score *score, UINT16 *base);
# 72 "./render.h"
void render_lives(UINT8 lives, UINT16 *base);
# 80 "./render.h"
void render_border(Model *model, void *base);
# 87 "./render.h"
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


extern char keyboard_buffer[256];
extern int buffer_index;
extern int buffer_fill;

char keystroke();

void do_IKBD_ISR();

void add_to_buffer(char ch);
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

    orig_VBL = install_vector(28 , vbl_isr);
    orig_IKBD = install_vector(70 , ikbd_isr);

    get_mouse_x();

    while (1) {
        play = title();
        if (play == 1) {
            break;
        }
        space();
        break;
    }

    install_vector(28 , orig_VBL);
    install_vector(70 , orig_IKBD);
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
    buffer_index = 0;
    buffer_fill = 0;




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
    UINT16 *base = get_video_base();




    clear_screen((UINT32)base);
    render_title((UINT32 *)base);

    while (1) {
        char ch = keystroke();
        switch (ch) {
            case 's':
                return 0;
            case 'q':
                clear_screen((UINT32)base);
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
