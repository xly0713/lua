#include <stdio.h>
#include <string.h>

#include <lua.hpp> //for c++

static int add2(lua_State* L) {
	//检查栈中参数是否合法
	double var1 = luaL_checknumber(L, 1);
	double var2 = luaL_checknumber(L, 2);

	//函数结果压栈
	double v = var1 + var2;
	lua_pushnumber(L, v);
	lua_pushnumber(L, v);

	return 2; //返回压栈值数量
}

const char* testfunc = "print(add2(1.0, 2.0))";

int main() {
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	lua_register(L, "add2", add2);

	if( luaL_dostring(L, testfunc) ) {
		printf("Failed to invoke.\n");
	}

	lua_close(L);

	return 0;
}
