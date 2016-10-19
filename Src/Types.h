#pragma once

#include <cstdlib>
#include <list>
#include <iostream>
#include <map>
#include <string>
#include <vector>

enum VType { T_INT, T_PTR, T_ARR };
enum EType { E_UNARY, E_BIN, E_VAL, E_VAR, E_FUNC, E_ARRAT }; // expression type