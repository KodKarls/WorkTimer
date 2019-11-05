all:
	g++ Main.cpp header\Window.hpp header\Logger.hpp header\Utilities.hpp header\SplashScreen.hpp source\Logger.cpp source\Window.cpp source\Utilities.cpp source\SplashScreen.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-mwindows

console-on:
	g++ Main.cpp header\Window.hpp header\Logger.hpp header\Utilities.hpp source\Logger.cpp header\SplashScreen.hpp source\Window.cpp source\Utilities.cpp source\SplashScreen.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg

window-test:
	g++ -I boost\include\boost-1_71 -o bin/test/WindowTest.exe test/windowTest.cpp -L C:\Develop\boost\lib -Wl,-Bdynamic -lboost_unit_test_framework-mgw73-mt-x64-1_71
