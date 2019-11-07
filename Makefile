all:
	g++ Main.cpp header\Logger.hpp header\Utilities.hpp header\SplashScreen.hpp source\Logger.cpp source\Utilities.cpp source\SplashScreen.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-mwindows

console-on:
	g++ Main.cpp header\Logger.hpp header\Utilities.hpp source\Logger.cpp header\SplashScreen.hpp source\Utilities.cpp source\SplashScreen.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg
