CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJS = Main.o Logger.o SplashScreen.o Utilities.o Button.o ClockButton.o MenuButton.o InfoButton.o Menu.o InfoScreen.o ClockScreen.o ClockBlock.o EndScreen.o
LIBDIR=lib

LDFLAGS = -L$(LIBDIR)/SFML/lib
CPPFLAGS = -I$(LIBDIR)/SFML/include

LDDEBUGLIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d -mwindows
LDRELEASELIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -mwindows

debug: $(OBJS)
	$(CXX) -g $^ $(LDFLAGS) $(LDDEBUGLIBS) -o WorkTimer

Main.o: Main.cpp header/Logger.hpp header/screens.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

Logger.o: source/Logger.cpp header/Logger.hpp header/Utilities.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

SplashScreen.o: source/SplashScreen.cpp header/SplashScreen.hpp header/Logger.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

Utilities.o: source/Utilities.cpp header/Utilities.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

Button.o: source/Button.cpp header/Button.hpp header/Logger.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

ClockButton.o: source/ClockButton.cpp header/ClockButton.hpp header/Button.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

MenuButton.o: source/MenuButton.cpp header/MenuButton.hpp header/Button.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

InfoButton.o: source/InfoButton.cpp header/InfoButton.hpp header/Button.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

Menu.o: source/Menu.cpp header/Menu.hpp header/Button.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

InfoScreen.o: source/InfoScreen.cpp header/InfoScreen.hpp header/Button.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

ClockScreen.o: source/ClockScreen.cpp header/ClockBlock.hpp header/ClockScreen.hpp header/Button.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

ClockBlock.o: source/ClockBlock.cpp header/ClockBlock.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

EndScreen.o: source/EndScreen.cpp header/EndScreen.hpp header/Button.hpp header/EachScreen.hpp
	$(CXX) -g -c $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJS) WorkTimer

.PHONY: all clean
