# evt2root
Program to convert files generated by NSCLDAQ ver. 11 (.evt) to a ROOT file (.root).

# Description:
The program asks for the name of an evtlist file which should contain the full pathname for the root file to be generated along with the full pathname to each evt file to be converted. All of the listed evt files will be converted into a single root file. An example evtlist file is included inthe repository. The converter will show dialog describing the status of the file conversion; it should be noted that at the end of each file the converter will show the number of physics buffers found. This should match the number of buffers read out by SpecTcl. 

The file is unpacked by stack order. This means that, in the unpacker method of the evt2root class, the modules to be unpacked should be listed in the order that was given to readout in a daqconfig.tcl file. Each buffer is then parsed by a module unpacker. The module unpackers return the parsed data which is then sorted by geoaddress and stored in a root tree (DataTree). There is then a method called parameters. This is where some fundamental parameters can be constructed for the root file. It is not recommened to do anything overly complex here, as that would signifcantly slow down the conversion time. 

# Execution:
./evt2root

A Makefile is included to build the program

