vim hello.cpp
qmake -project
ls
	hello.cpp
	qt.pro
	readme.txt
add 'QT += widgets' into qt.pro
qmake
ls
	hello.cpp
	Makefile
	.qmake.stash
	qt.pro
	readme.txt
make
	g++ -c -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -I. -I/usr/include/arm-linux-gnueabihf/qt5 -I/usr/include/arm-linux-gnueabihf/qt5/QtWidgets -I/usr/include/arm-linux-gnueabihf/qt5/QtGui -I/usr/include/arm-linux-gnueabihf/qt5/QtCore -I. -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++ -o hello.o hello.cpp
	g++ -Wl,-O1 -o qt hello.o   /usr/lib/arm-linux-gnueabihf/libQt5Widgets.so /usr/lib/arm-linux-gnueabihf/libQt5Gui.so /usr/lib/arm-linux-gnueabihf/libQt5Core.so -lGLESv2 -lpthread -latomic   
	
ls
	hello.cpp
	hello.o
	Makefile
	qt
	qt.pro
	readme.txt

./qt &

