CC = gcc
FLAGS = -Wall `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_image-5.0`
BIN = _main
SOURCE = _main.c controller_controller.c smart_environment.c smart_environment_types.c

all:
	$(CC) $(SOURCE) $(FLAGS) -o $(BIN)

clean:
	rm -f *.o _main