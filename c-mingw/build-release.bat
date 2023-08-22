windres ./src/my.rc my.o
gcc -D_RELEASE -mwindows -std=c17 -m64 -Ofast my.o ./src/*.c -o dist/game -I ./src/include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
if exist "my.o" (del my.o)
