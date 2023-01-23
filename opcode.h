#ifndef OPCODE_H
#define OPCODE_H

#include "monty.h"

instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

#endif
