CXC = g++ -c -std=c++11 -I./src -I./ext/glui/include -o
CXO = g++ -std=c++11 -I./src -I./ext/glui/include -lglut -lGL -lGLU -lglui -L./ext/glui/lib -o
EXECUTABLE = src/csci3081

all: src/csci3081

src/csci3081: src/main.o src/base_gfx_app.o src/special.o src/color_data.o src/brushwork_app.o src/pixel_buffer.o src/tools.o src/pen.o src/spray_can.o src/highlighter.o src/caligraphy.o src/eraser.o
	g++ -o src/csci3081 src/special.o src/main.o src/base_gfx_app.o src/color_data.o src/brushwork_app.o src/pixel_buffer.o src/tools.o src/pen.o src/spray_can.o src/highlighter.o src/caligraphy.o src/eraser.o -std=c++11 -I./src -I./ext/glui/include -lglut -lGL -lGLU -lglui -L./ext/glui/lib

src/main.o: src/main.cc src/include/brushwork_app.h src/include/color_data.h
	${CXC}  src/main.o src/main.cc

src/base_gfx_app.o: src/base_gfx_app.cc
	${CXC} src/base_gfx_app.o src/base_gfx_app.cc

src/color_data.o: src/color_data.cc
	${CXC} src/color_data.o src/color_data.cc

src/pixel_buffer.o: src/pixel_buffer.cc src/include/pixel_buffer.h src/include/color_data.h
	${CXC} src/pixel_buffer.o src/pixel_buffer.cc

src/brushwork_app.o: src/brushwork_app.cc src/include/pixel_buffer.h src/include/color_data.h src/include/brushwork_app.h
	${CXC} src/brushwork_app.o src/brushwork_app.cc

src/tools.o: src/tools.cc src/include/tools.h
	${CXC} src/tools.o src/tools.cc

src/pen.o: src/pen.cc src/include/pen.h
	${CXC} src/pen.o src/pen.cc

src/spray_can.o: src/spray_can.cc src/include/spray_can.h
	${CXC} src/spray_can.o src/spray_can.cc

src/highlighter.o: src/highlighter.cc src/include/highlighter.h
	${CXC} src/highlighter.o src/highlighter.cc

src/caligraphy.o: src/caligraphy.cc src/include/caligraphy.h
	${CXC} src/caligraphy.o src/caligraphy.cc

src/eraser.o: src/eraser.cc src/include/eraser.h
	${CXC} src/eraser.o src/eraser.cc

src/special.o: src/special.cc src/include/special.h
	${CXC} src/special.o src/special.cc

clean:
	rm -r ./src/*.o ./src/csci3081
