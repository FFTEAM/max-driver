#ifndef pti_public_
#define pti_public_

/* public pti header */

struct PtiSession 
{
  short int 		pidtable[32];
  short int 		references[32];

  short int 		type[32];
  short int 		pes_type[32];
  short int 		num_pids;
  
  int 			slots[32];

  int 			session;
  int 			descrambler;
  int 			source;

};

typedef enum 
{
  VID_BUFFER = 222,
  AUD_BUFFER,
  MISC_BUFFER
} BUFFER_TYPE;

/* source */
typedef enum 
{
  TSIN0 = 0,
  TSIN1,
  TSIN2,
  SWTS0,
  TS_NOTAGS = 0x80
} tInputSource;

struct stpti 
{
  size_t 		InterruptDMABufferSize;
  dma_addr_t    	InterruptDMABufferInfo;
  void          	*InterruptBufferStart_p;

  /* spinlock for the interrupt handler */  
  spinlock_t 		irq_lock;

  /* gemappter speicherbereich; TCDevice_t* */
  unsigned int 		pti_io;
  
  struct dvb_device*    ca_device;

  /* work queue for polling the DMA (if configured) */
  wait_queue_head_t queue;
};



#endif