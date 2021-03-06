//The TTreeRaw Class that reads raw npdg data files in TTree format
//Author: Latiful Kabir
//Date: 12/25/14

#include "TTreeRaw.h"
#include "TBranchBinary.h"
#include <TBranch.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "CalOffset.h"
void libn3He() {
}
;
using namespace std;

ClassImp(TTreeRaw)

//______________________________________________________________________
int TTreeRaw::module[5]={21,22,23,24,30};

TTreeRaw::TTreeRaw(int runNumber):TTree("npdg", "npdg raw data")
{

    DaqLeaf=new TString[5];
    dataFile=new TString[5];

    int offsetDaq21=0;
    int offsetDaq22=0;
    int offsetDaq23=0;
    int offsetDaq24=0;
    int offsetDaq30=0;

//-------------------Get The Data Path-----------------------------
    dataPath=DATA_PATH;

//------------------Get the Leaf list-------------------------------

    DaqLeaf[0]=DAQ21_LEAF;
    DaqLeaf[1]=DAQ22_LEAF;
    DaqLeaf[2]=DAQ23_LEAF;
    DaqLeaf[3]=DAQ24_LEAF;
    DaqLeaf[4]=DAQ30_LEAF;

    //---------------Generate data file name for each DAQ--------------

    for(int i=0;i<5;i++)
    {
	dataFile[i]=dataPath;
	dataFile[i]+="run-";
	dataFile[i]+=runNumber;
	dataFile[i]+="data-";
	dataFile[i]+=module[i];
    }

    //if(ifstream(dataFile[0]) && ifstream(dataFile[1]) && ifstream(dataFile[2]) && ifstream(dataFile[3]) && ifstream(dataFile[4]))
    if(ifstream(dataFile[0]) && ifstream(dataFile[4]))
    {
        //-------------------Calculate The Dynamic Offset to go around sync issues with data stream for first few events from the DAQ-------------

	offsetDaq21=CalOffset(dataFile[0],21);
	// offsetDaq22=CalOffset(dataFile[1],22);
	// offsetDaq23=CalOffset(dataFile[2],23);
	// offsetDaq24=CalOffset(dataFile[3],24);
	offsetDaq30=CalOffset(dataFile[4],30);
	
	//if(offsetDaq21==0 || offsetDaq22 ==0 || offsetDaq23 ==0 || offsetDaq24 == 0 || offsetDaq30 == 0)
	if(offsetDaq21==0 || offsetDaq30 == 0)
	{
	    //offsetDaq21=offsetDaq22=offsetDaq23=offsetDaq24=offsetDaq30=0;
	    offsetDaq21=4*9600; //Skip first 4 events: 50 samples/event x 4 events x 48 channels x 4 bytes/sample.
	    offsetDaq30=4*13000; //Skip first 4 events: 1625 samples/event x 4 events x 2 channels x 4 bytes/sample.
	}
	else
	{
	    offsetDaq21=(offsetDaq21-6)*4;
	    // offsetDaq22=(offsetDaq22-6)*4;
	    // offsetDaq23=(offsetDaq23-6)*4;
	    // offsetDaq24=(offsetDaq24-6)*4;
	    offsetDaq30=(offsetDaq30-1)*4;
	}

//-------------Add the Branches to this tree-----------------------------------
 
//------------Brach for daq-21------------                            
	cout << "Reading clean daq file: " << dataFile[0] << endl;
	b21 = new TBranchBinary(this,dataFile[0],DaqLeaf[0],"b21", -1, 0,offsetDaq21);
	this->GetListOfBranches()->Add(b21);

// //-----------Branch for daq-22-------------                                                     
// 	cout << "Reading clean daq file: " << dataFile[1] << endl;
// 	b22 = new TBranchBinary(this,dataFile[1],DaqLeaf[1],"b22", -1, 0,offsetDaq22);
// 	this->GetListOfBranches()->Add(b22);

// //----------Branch for daq-23--------------                                                            
// 	cout << "Reading clean daq file: " << dataFile[2] << endl;
// 	b23 = new TBranchBinary(this,dataFile[2],DaqLeaf[2],"b23", -1, 0,offsetDaq23);
// 	this->GetListOfBranches()->Add(b23);

// //--------Branch for daq-24----------------                                                            
// 	cout << "Reading clean daq file: " << dataFile[3] << endl;
// 	b24 = new TBranchBinary(this,dataFile[3],DaqLeaf[3],"b24", -1, 0,offsetDaq24);
// 	this->GetListOfBranches()->Add(b24);

//--------Branch for daq-30---------------
	cout << "Reading dirty daq file: " <<dataFile[4] << endl;
	b30 = new TBranchBinary(this,dataFile[4],DaqLeaf[4],"b30", -1, 0,offsetDaq30); 
	this->GetListOfBranches()->Add(b30);

//----------------Set/Get Entries and Print Leaf List---------------
	this->SetEntries();
	this->GetEntries();
	// this->Print();
	// this->GetListOfLeaves()->Print();

    }
    else
    {
	cout<<"No data files for requested run number"<<endl;
    }
    
}

TTreeRaw::~TTreeRaw()
{
    // delete b21;
    // delete b22;
    // delete b23;
    // delete b24;
    // delete b30;
    delete[] DaqLeaf;
    delete[] dataFile;
}

