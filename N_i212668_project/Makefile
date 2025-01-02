CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =		 Menu.o util.o N_i212668_project.o map.o  p1vsbots.o p1vsp2.o vehicle.o canon.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
