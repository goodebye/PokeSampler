/*
	contains some useful functions for some basic operations
*/

#pragma once

class Util {
public:
	static int wrappingModulo(int x, int n) {
		return (x % n + n) % n;
	}
};