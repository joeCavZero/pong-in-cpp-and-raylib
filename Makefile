default:
	g++ src/*.cpp src/utils/*.cpp -o out/app.exe -Wall -I ./include -L ./lib -lraylib -lopengl32 -lgdi32 -lwinmm
	./out/app.exe
execute:
	./out/app.exe