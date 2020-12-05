//Javier Macossay and Rachel Gaines
#include <iostream>
#include <fstream>

#include "vlg_parser.h"
#ifdef AUTOPARSE
#include "vlg_parser_auto.h"
#else
#include "vlg_parser_man.h"
#endif

#include "design.h"
#include "gates.h"
#include "net.h"
#include "logicsim.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*if(argc < 3){
      cerr << "Usage ./gsim infile.v outfile.v" << endl;
      return 1;
    }
#ifdef AUTOPARSE
    VlgParser *parser = new VlgParserAuto();
#else
    VlgParser *parser = new VlgParserMan();
#endif
    Design *d = parser->parse(argv[1]);
*/
    // Add more of your code here to simply dump the design back
    // out to a file named output.v
    
    //Creating vector pointers
    VlgParser *parser = NULL;
    Design *d = NULL;

    //call the read function from LogicSim
    int result = read(argc, argv[1], argv[2], &parser, &d);

    //if the read function worked
    if(result == 0){
       
        //create the ouput file
        ofstream ofile(argv[3]);

        //call the simulation function from LogicSim
        simulation(argv[2], &d, ofile);

        //close the output file
        ofile.close();
    }

    //delete the parser pointer
    delete parser;

    return 0;
}

