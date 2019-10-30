all:
	g++ Main.cpp header\Window.hpp header\Logger.hpp header\Utilities.hpp source\Window.cpp source\Utilities.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-mwindows
