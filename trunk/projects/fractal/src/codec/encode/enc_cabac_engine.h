#ifndef _ENC_CABAC_ENGINE_H_
#define _ENC_CABAC_ENGINE_H_

#include "taah264stdtypes.h"
#include "enc_writebits.h"


/************************************************************************
* D e f i n i t i o n s
***********************************************************************
*/

// some definitions to increase the readability of the source code

#define B_BITS         10    // Number of bits to represent the whole coding interval
#define BITS_TO_LOAD   16
#define MAX_BITS       26          //(B_BITS + BITS_TO_LOAD)
#define MASK_BITS      18          //(MAX_BITS - 8)
#define ONE            0x04000000  //(1 << MAX_BITS)
#define ONE_M1         0x03FFFFFF  //(ONE - 1)
#define HALF           0x01FE      //(1 << (B_BITS-1)) - 2
#define QUARTER        0x0100      //(1 << (B_BITS-2))
#define MIN_BITS_TO_GO 0
#define B_LOAD_MASK    0xFFFF      // ((1<<BITS_TO_LOAD) - 1)

typedef struct encoding_environment EncodingEnvironment;
typedef EncodingEnvironment *EncodingEnvironmentPtr;
typedef struct bi_context_type BiContextType;
typedef BiContextType *BiContextTypePtr;

//! struct to characterize the state of the arithmetic coding engine
struct encoding_environment
{
	int cabac_encoding;                   
	unsigned int  Elow;
	unsigned int  Erange;
	unsigned int  Ebuffer;
	unsigned int  Ebits_to_go;
	unsigned int  Echunks_outstanding;
	int           Epbuf;
	int           *Ecodestrm_len;         //need ? maybe not, point to the stream buf length
	int           C;                      // processed bin counts % 8
	int           E;                      //byte count of processed bins


	unsigned int  saved_Elow;
	unsigned int  saved_Erange;
	unsigned int  saved_Ebuffer;
	unsigned int  saved_Ebits_to_go;
	unsigned int  saved_Echunks_outstanding;
	int           saved_Epbuf;
	int           saved_Ecodestrm_len;         //need ? maybe not, point to the stream buf length
	int           saved_C;                      // processed bin counts % 8
	int           saved_E;                      //byte count of processed bins

	bitwriter_t *w;

};

//! struct for context management
struct bi_context_type
{
	unsigned long  count;
	uint8_t state; //uint16 state;         // index into state-table CP
	unsigned char  MPS;           // Least Probable Symbol 0/1 CP  
};



void binary_encode_symbol(EncodingEnvironmentPtr eep, int symbol, BiContextTypePtr bi_ct);
void binary_encode_symbol_final(EncodingEnvironmentPtr eep, int symbol);
void unary_bin_encode(EncodingEnvironmentPtr eep, unsigned int symbol, BiContextTypePtr ctx, int ctx_offset);
void binary_encode_symbol_eq_prob(EncodingEnvironmentPtr eep, int symbol);
void algorithm_enc_done(EncodingEnvironmentPtr eep);
void binary_init_context(int qp, BiContextTypePtr ctx, const char* ini);



#endif
