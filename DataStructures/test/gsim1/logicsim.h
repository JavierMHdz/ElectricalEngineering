//Javier Macossay and Rachel Gaines
#ifndef LOGICSIM_H
#define LOGICSIM_H

#include "net.h"
#include "design.h"
#include "gates.h"

#include "vlg_parser.h"
#ifdef AUTOPARSE
#include "vlg_parser_auto.h"
#else
#include "vlg_parser_man.h"
#endif

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <ostream>

   int read(int argc, char *argv1, char* argv2, VlgParser **parser, Design **d);

   void simulation(char* argv, Design **d, ostream &os);

   void output(Design **d, stringstream ss2, ostream &os);
#endif
