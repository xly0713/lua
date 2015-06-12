#include <stdio.h>
#include <string.h>
#include <lua.hpp>

extern "C" int add(lua_State *L) {
	double v1 = luaL_checknumber(L, 1);
	double v2 = luaL_checknumber(L, 2);

	double v = v1 + v2;
	lua_pushnumber(L, v);

	return 1;
}

extern "C" int sub(lua_State *L) {
	double v1 = luaL_checknumber(L, 1);
	double v2 = luaL_checknumber(L, 2);

	double v = v1 - v2;
	lua_pushnumber(L, v);

	return 1;
}

extern "C" int muti(lua_State *L) {
	double v1 = luaL_checknumber(L, 1);
	double v2 = luaL_checknumber(L, 2);

	double v = v1 * v2;
	lua_pushnumber(L, v);

	return 1;
} 


extern "C" int luaopen_c_opt(lua_State *L) {
	static luaL_Reg libs[] = {
		{"add", add},
		{"sub", sub},
		{"muti", muti},
		{NULL, NULL}
	};
	const char *libName = "c.opt";
	luaL_register(L, libName, libs);

	return 1;
}
