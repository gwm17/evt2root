/*mTDCUnpacker.h
 *Class to parse through data coming from mtdc 
 *Most of the program's structure borrowed from 
 *http://docs.nscl.msu.edu/daq/newsite/nscldaq-11.2/x5013.html
 *Ken H. & Gordon M.
 *Nov 2018
 *
 *This particular version is designed to work with SPSevt2root and uses 16-bit integer pointers
 *to traverse, instead of the spectcl 32-bit translator pointers. Possible area for improvement?
 *Gordon M. Feb 2019
 *
 *Updated to have better error handling, and have a more general application
 *Gordon M. April 2019
 *
 *NOTE: This version is specifically designed to unpack data that come in reverse!!
 */


#ifndef MTDCUNPACKER_H 
#define MTDCUNPACKER_H 

#include <vector>
#include <utility>
#include <cstdint>

using namespace std;

struct ParsedmTDCEvent {
  int s_id;
  int s_res;
  int s_count;
  int s_eventNumber;   
  vector<pair<int, uint16_t>> s_data;
};

class mTDCUnpacker {
  public:
    pair<uint32_t*, ParsedmTDCEvent> parse(uint32_t* begin,uint32_t* end);
    bool isHeader(uint32_t word);

  private:
    bool isData(uint32_t word);
    bool isEOE(uint32_t word); 
   
    void unpackHeader(uint32_t* word, ParsedmTDCEvent& event);
    void unpackDatum(uint32_t* word, ParsedmTDCEvent& event); 
    uint32_t* unpackData(uint32_t* begin,uint32_t* end,ParsedmTDCEvent& event); 
};

#endif
        
