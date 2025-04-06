driver: driver.o psg.o music.o effects.o
	cc68x -g driver.o psg.o music.o effects.o -o driver.prg

driver.o: driver.c psg.h music.h effects.h
	cc68x -g -c driver.c

psg.o: psg.c psg.h
	cc68x -g -c psg.c

music.o: music.c music.h
	cc68x -g -c music.c

effects.o: effects.c effects.h
	cc68x -g -c effects.c

clean:
	$(RM) *.o *.prg 
	