# 1 "game.c" 1
# 1 "./game.h" 1
# 1 "./render.h" 1
# 1 "./model.h" 1
# 1 "./types.h" 1



typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 4 "./model.h" 2


typedef struct Player {
    UINT16 x, y;
    UINT8 l, w;
    UINT8 lives;
    int delta_x;
    int bullet_type;
} Player;

typedef struct Alien {
    UINT16 x, y;
    UINT8 l, w;
    int score;
    int alive;

} Alien;

typedef struct Aliens{
    Alien r1[11];
    Alien r2[11];
    Alien r3[11];
    Alien r4[11];
    Alien r5[11];
    UINT8 totalAliens;
    int delta_x;
    int bullet_type;
    char render;
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
# 66 "./model.h"
void move_player(Player *player);
# 74 "./model.h"
void alien_direc_change(Aliens *alien_arr, int alien_dx);
# 82 "./model.h"
int move_aliens(Aliens *aliens);
# 90 "./model.h"
int lower_aliens(Aliens *alien_arr, int highbound, int alien_dx);
# 98 "./model.h"
void destroy_alien(Alien alien, Score curr_score);
# 106 "./model.h"
int move_bullet(Model *model, Bullet *bullet);
# 114 "./model.h"
void add_score (int score_to_add, Score curr_score);
# 121 "./model.h"
void update_score(Score *score);
# 130 "./model.h"
int check_aliens_hit(Model *model, Bullet *bullet);
# 139 "./model.h"
int check_row_hit(Alien row[], Bullet *bullet);
# 148 "./model.h"
int check_player_hit(Player *player, Bullet *bullet);
# 4 "./render.h" 2
# 1 "./raster.h" 1
# 1 "./types.h" 1
# 4 "./raster.h" 2
# 13 "./raster.h"
void plot_bitmap8(UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
# 22 "./raster.h"
void plot_bitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
# 31 "./raster.h"
void plot_bitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
# 41 "./raster.h"
void plot_vline(UINT8 *base, int x, int y1, int y2);
# 51 "./raster.h"
void plot_hline(UINT8 *base, int x1, int x2, int y);
# 62 "./raster.h"
void plot_ch(UINT8 *base, UINT8 *font, char ch, int x, int y);


void clear_player(UINT32 *base);
# 5 "./render.h" 2
# 14 "./render.h"
void render(const Model *model, void *base, int f);
# 22 "./render.h"
void render_player(const Player *player, UINT32 *base);
# 31 "./render.h"
void render_alien(const Alien *alien, UINT32 *base, UINT32 *bitmap);
# 40 "./render.h"
void render_aliens(const Aliens *aliens, UINT32 *base, UINT32 f);
# 48 "./render.h"
void render_bullet(const Bullet *bullet, UINT8 *base);
# 56 "./render.h"
void render_score(const Score *score, UINT16 *base);
# 4 "./game.h" 2
# 1 "./types.h" 1
# 5 "./game.h" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 4 "./events.h" 2
# 12 "./events.h"
void async_move_player(Model *model, char key);
# 20 "./events.h"
void async_shoot(Model *model, int cooldown);
# 27 "./events.h"
int update_aliens(Model *model);
# 34 "./events.h"
void update_bullets(Model *model);
# 41 "./events.h"
int check_endgame(Model *model);
# 6 "./game.h" 2
# 1 "./model.h" 1
# 7 "./game.h" 2
# 1 "./raster.h" 1
# 8 "./game.h" 2
# 1 "./input.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
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
# 3 "./input.h" 2





char keystroke();
# 9 "./game.h" 2
# 1 "./psg.h" 1
# 1 "./TYPES.H" 1
# 4 "./psg.h" 2


void write_psg(int reg, UINT8 val);

void set_tone(int channel, int tuning);

void set_volume(int channel, int volume);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();
# 10 "./game.h" 2
# 1 "./music.h" 1
# 1 "./psg.h" 1
# 4 "./music.h" 2


void start_music();

char update_music(UINT32 time_elapsed, UINT32 time_before, int note);
# 11 "./game.h" 2
# 18 "./game.h"
void asyncHandle(Model *model);
# 26 "./game.h"
void syncHandle(Model *model, UINT32 timeElapsed);
# 34 "./game.h"
void swapBuffers (void **active, void **inactive);




UINT32 getTime();
# 1 "game.c" 2
# 1 "C:/c68/include/stdio.h" 1
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
# 2 "game.c" 2
# 1 "C:/c68/include/osbind.h" 1
# 3 "game.c" 2


extern void clear_screen(UINT32 base);

UINT8 preBuffer[32255];

int main() {
    void *base = (void*)_trap_14_w((short)0x2) ;
    void *inactive = (void *)(((UINT32)preBuffer + 255) & 0xFFFFFF00L);
    void *active = base;

    Model model = {
        { 288, 368, 32, 32, 3, 0, 1 },
        {
            {
                { 0, 32, 32, 32, 250, 1},
                {32, 32, 32, 32, 250, 1},
                {64, 32, 32, 32, 250, 1},
                {96, 32, 32, 32, 250, 1},
                {128, 32, 32, 32, 250, 1},
                {160, 32, 32, 32, 250, 1},
                {192, 32, 32, 32, 250, 1},
                {224, 32, 32, 32, 250, 1},
                {256, 32, 32, 32, 250, 1},
                {288, 32, 32, 32, 250, 1},
                {320, 32, 32, 32, 250, 1}
            },
            {
                {0, 64, 32, 32, 200, 1},
                {32, 64, 32, 32, 200, 1},
                {64, 64, 32, 32, 200, 1},
                {96, 64, 32, 32, 200, 1},
                {128, 64, 32, 32, 200, 1},
                {160, 64, 32, 32, 200, 1},
                {192, 64, 32, 32, 200, 1},
                {224, 64, 32, 32, 200, 1},
                {256, 64, 32, 32, 200, 1},
                {288, 64, 32, 32, 200, 1},
                {320, 64, 32, 32, 200, 1}
            },
            {
                {0, 96, 32, 32, 150, 1},
                {32, 96, 32, 32, 150, 1},
                {64, 96, 32, 32, 150, 1},
                {96, 96, 32, 32, 150, 1},
                {128, 96, 32, 32, 150, 1},
                {160, 96, 32, 32, 150, 1},
                {192, 96, 32, 32, 150, 1},
                {224, 96, 32, 32, 150, 1},
                {256, 96, 32, 32, 150, 1},
                {288, 96, 32, 32, 150, 1},
                {320, 96, 32, 32, 150, 1}
            },
            {
                {0, 128, 32, 32, 100, 1},
                {32, 128, 32, 32, 100, 1},
                {64, 128, 32, 32, 100, 1},
                {96, 128, 32, 32, 100, 1},
                {128, 128, 32, 32, 100, 1},
                {160, 128, 32, 32, 100, 1},
                {192, 128, 32, 32, 100, 1},
                {224, 128, 32, 32, 100, 1},
                {256, 128, 32, 32, 100, 1},
                {288, 128, 32, 32, 100, 1},
                {320, 128, 32, 32, 100, 1}
            },
            {
                {0, 160, 32, 32, 50, 1},
                {32, 160, 32, 32, 50, 1},
                {64, 160, 32, 32, 50, 1},
                {96, 160, 32, 32, 50, 1},
                {128, 160, 32, 32, 50, 1},
                {160, 160, 32, 32, 50, 1},
                {192, 160, 32, 32, 50, 1},
                {224, 160, 32, 32, 50, 1},
                {256, 160, 32, 32, 50, 1},
                {288, 160, 32, 32, 50, 1},
                {320, 160, 32, 32, 50, 1}
            },
            55,
            8,
            -1,
            1
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
    int f = 0;
    int note = 0;
    int temp;
    UINT32 timeStart, timeNow, timeElapsed, timeBefore;


    printf("\033E\033f\n");

    timeStart = getTime();

    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    render(&model, active, f);

    start_music();
    note = 1;

    while (!model.quit) {
        timeNow = getTime();
        timeElapsed = timeNow - timeStart;

        asyncHandle(&model);

        if(timeElapsed > 0){
            syncHandle(&model, timeElapsed);

            if((timeElapsed & 0x7F) > 120) {
                f++;
            }
        }

        if (model.aliens.render == 1) {
            clear_screen((UINT32)inactive);
        } else{
            clear_player((UINT32)inactive);
        }
        render(&model, inactive, f);
        swapBuffers(&active, &inactive);

        temp = update_music(timeElapsed, timeBefore, note);
        if (temp == 1) {
            timeBefore = timeElapsed;
            note++;
            if (note == 48) {
                note = 0;
            }
        }
    }

    stop_sound();


    clear_screen((UINT32)active);
    clear_screen((UINT32)inactive);

    (void)_trap_14_wllw((short)0x5,(long)(-1),(long)base,(short)(-1)) ;
    return 0;
}

void asyncHandle(Model *model) {
    char ch = keystroke();

    switch (ch) {
        case 'q':
            model->quit = 1;
            break;
        case 'a':
            async_move_player(model, ch);
            break;
        case 'd':
            async_move_player(model, ch);
            break;
        case 's':
            async_shoot(model, 0);
            break;
    }
}

void syncHandle(Model *model, UINT32 timeElapsed) {



    int game_state;
    if((timeElapsed & 0x7F) > 120) {
        game_state = update_aliens(model);
        if (game_state == -1) {
            model->quit = 1;
        }
        model->aliens.render = 1;
    }

    if (model->active_count > 0) {
        update_bullets(model);
    }


    if (check_endgame(model)) {
        model->quit = 1;
    }
}

void swapBuffers (void **active, void **inactive) {
    void *temp = *active;
    *active = *inactive;
    *inactive = temp;
    (void)_trap_14_wllw((short)0x5,(long)(-1),(long)*active,(short)(-1)) ;
    (void)_trap_14_w((short)0x25) ;
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
