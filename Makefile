TARGETS = lua_c c/opt.so

all : $(TARGETS)

clean : 
	-rm $(TARGETS)

lua_c : lua_c.cpp
	g++ -o lua_c -llua lua_c.cpp
	
c/opt.so : c_opt.cpp
	g++ -g -fpic -shared -llua -o c/opt.so c_opt.cpp
