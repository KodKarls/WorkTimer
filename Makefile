all:
	g++ Main.cpp header\Logger.hpp header\Utilities.hpp header\SplashScreen.hpp header\Button.hpp header\EachScreen.hpp header\screens.hpp source\Logger.cpp source\Utilities.cpp source\SplashScreen.cpp source\Button.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
	-mwindows

console-on:
	g++ Main.cpp header\Logger.hpp header\Utilities.hpp header\SplashScreen.hpp header\Button.hpp header\EachScreen.hpp header\screens.hpp source\Logger.cpp source\Utilities.cpp source\SplashScreen.cpp source\Button.cpp -o WorkTimer.exe \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg

splashScreen-test:
	g++ -I boost\include\boost-1_71 header\Logger.hpp header\Utilities.hpp source\Logger.cpp source\Utilities.cpp -o bin\test\splashScreenTest test\splashScreenTest.cpp -L boost\lib -Wl,-Bdynamic -lboost_unit_test_framework-mgw73-mt-x64-1_71 \
	-DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg
