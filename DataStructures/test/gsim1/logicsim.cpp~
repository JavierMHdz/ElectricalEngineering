//Javier Macossay and Rachel Gaines
//#include libraries
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <ostream>
#include <string>
#include <cstring>

#include "vlg_parser.h"
#ifdef AUTOPARSE
#include "vlg_parser_auto.h"
#else
#include "vlg_parser_man.h"
#endif

#include "net.h"
#include "design.h"
#include "gates.h"

using namespace std;

void output(Design **d, string* line, ostream &os, int delay);

//Read and Parse the input simulation file
int read(int argc, char *argv1, char *argv2, VlgParser **parser, Design **d){

	//checking in the right amount of inputs where given
	if(argc < 4){
		cerr << "Usage ./gsim verilog_file input_sim_file output_sim_file"<<endl;
		return 1;
	}

//Parsing the file
#ifdef AUTOPARSE
    *parser = new VlgParserAuto();
#else
    *parser = new VlgParserMan();
#endif
    *d = (*parser)->parse(argv1);

    //Part 1
    //creating the input file
    ifstream ifile(argv2);
    //If the input file opened
    if(!ifile.fail()){

    	//get the PI's from the design to compare them
    	vector <Net *> *pis = (*d)->getPINets();
    	string myline;
    	string word;
    	bool check = false;
    	bool allTrue = true;
    	//getting the first line of the simulation file
    	//and saving it in a string
    	getline(ifile,myline);

    	//creating the stringstream
    	stringstream ss(myline);

    	//while we are getting a word, we will compare it
    	//to see if it is inside the PI's list
    	while(ss>>word){
    		//if they are equal, make check equal to true
    		for(unsigned int i = 0; i < pis->size(); ++i){
    			if(word.compare(((*pis)[i])->name()) == 0){
    				check = true;
    			}
    		}

    		if(check == false){
    			allTrue = false;
    		}
    	}

		//A specified PI on the first line does not exist in the design
		if(allTrue == false){
			cerr << "A specified PI on the first line does not exist in the design"<<endl;
			ifile.close();
	    	delete pis;
			return 1;
		}
        delete pis;
	}
	else{
		return 1;
	}

    //Part 2 and Part 3
    vector <Net *> *pis = (*d)->getPINets();
    bool sameSize = true;
    bool rightVal = true;
    string myline;
    stringstream ss1;
    unsigned int cnt;

    while(getline(ifile, myline)){
        //check the amount of numbers
        cnt = 0;

        for(unsigned int i = 0; i < myline.length(); ++i){
            if(myline[i] == ' '){
                cnt++;
            }
        }

        cnt++;

        if(cnt != pis->size()){
            sameSize = false;
        }
        //check their value
        //lo mas probable es que esto no funcione
        ss1 << myline;
        char val;
        while(ss1>>val){
            if(val != '0' && val != '1' && val != 'X'){
                rightVal = false;
            }
        }
    }

    //Check if it is the same size
    if(sameSize == false){
        cerr << "The number of input values for a vector does not match the number of PI's specified on the first line."<<endl;
        ifile.close();
        delete pis;
        return 1;
    }

    //Check if the value is either 0, 1, or X
    if(rightVal == false){
        cerr<<"An input value is not in the set {'0','1','X'}"<<endl;
        ifile.close();
        delete pis;
        return 1;
    }

    ifile.close();
    delete pis;
    return 0;
}

void simulation(char *argv, Design **d, ostream &os){
    ifstream ifile(argv);
    if(!ifile.fail()){
        
        //declare all my variables
        string myline;
        string word;

        char val;

        int delay = 0;

        stringstream ss;
        stringstream ss3;

        //creating vector pointer to primary inputs and the sorted list of Nets
        vector <Net *> *pis = (*d)->getPINets();        
        vector<Net *> *sort = (*d)->toposort();

        //I'm creating an array of strings
        char** words = new char*[pis->size()];
        for(unsigned int i = 0; i < pis->size(); ++i){
            words[i] = new char;
        }

        //Creating the output vector map
        vector<Net *> *pos = (*d)->getPONets();
        map<string, char> outputVector;
        for(unsigned int i = 0; i < pos->size(); ++i){
            outputVector.insert(make_pair((((*pos)[i])->name()),'0'));
        }

        //first line has the PI's so I'll grab the values two times
        getline(ifile, myline);
        ss<<myline;

        //dump it to the ofile
        os<<myline<<" => ";
        for(unsigned int i = 0; i < pos->size(); ++i){
            os<<((*pos)[i])->name()<<" ";
        }

        //creating a map to store the PI names with its value
        map<string,char> inputVector;
        int i = 0;
        //reading in the words
        while(ss>>word){
            inputVector.insert(make_pair(word,'0'));
            //copying the string into the char*
            strcpy(words[i], word.c_str());
            ++i;
        }

        //passing in all the input vectors
        while(getline(ifile, myline)){
            //creating the stringstream
            stringstream ss2(myline);
            int j = 0;
            //passing in the values of the input vectors
            while(ss2>>val){
                //filling in the map to keep track where the values are located
                inputVector[words[j]] = val;
                ++j;
            }
            //ComputeVal
            vector<Net*> *pis = (*d)->getPINets();
            //declare an iterator
            map<string, char>::iterator it;
            //loop for all Net* of *sort
            for(unsigned int k = 0; k < sort->size(); ++k){
                //check if the Net* are primary inputs
                for(it = inputVector.begin(); it != inputVector.end(); ++it){
                     if((*d)->findNet(((*sort)[k])->name())->name().compare(it->first) == 0){
                        //set the value if they are primary inputs without computing
                        ((*d)->findNet((*sort)[k]->name()))->setVal(it->second);
                    }
                }

            }

            //loop for every Net* from *sort
            for(unsigned int q = 0; q < sort->size(); ++q){
                bool PI = false;
                //check if they are primary inputs
                for(unsigned int k = 0; k < pis->size(); ++k){
                    if(((*d)->findNet(((*sort)[q])->name()))->name().compare(((*pis)[k])->name()) == 0){
                        PI = true;
                    }
                }

                //if they are not primary inputs, then proceed to compute the value and then set it
                if(PI == false){
                    char computedValue = ((*sort)[q])->computeVal();
                    ((*d)->findNet((*sort)[q]->name()))->setVal(computedValue);
                }
            }

            //Compute Delay
            for(unsigned int l = 0; l < sort->size(); ++l){
                delay = ((*sort)[l])->computeDelay();
                ((*sort)[l])->setDelay(delay);

            }

            //call the output function
            output(d,&myline,os, delay);
        }

        //close the inputs file
        ifile.close();
        delete pis;
        delete pos;
        delete sort;
        delete [] words;
    }

}

void output(Design ** d, string *line, ostream &os, int delay){
    //getting the primary outputs
    vector<Net*>* finalPos = (*d)->getPONets();
    //dump it to the ofile
    os<<endl;
    os<<*line<<" => ";
    for(unsigned int i = 0; i < finalPos->size(); ++i){
        char finalVal = ((*finalPos)[i])->getVal();
        os<<finalVal<<"@"<<delay<<" ";
    }

    //delete the pointer
    delete finalPos;
}
