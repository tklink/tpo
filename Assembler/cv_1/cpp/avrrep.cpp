// Tested on Fedora where
// standard headers are unavailable for AVR

// Use cstdint-compatible type name for BYTE
typedef unsigned char uint8_t;

// Macro that creates access to ports
#define DEFPORT(A)  (*reinterpret_cast<volatile uint8_t*>(A))

// Individual ports used in this program
#define DDRF  DEFPORT(0x30)
#define PORTF DEFPORT(0x31)
#define DDRK  DEFPORT(0x107)
#define PORTK DEFPORT(0x108)

// Port K ... buttons
// Port F ... LEDs

// Initialize environment
static inline void init()
{
	DDRK = 0x00;  // input
	DDRF = 0xFF;  // output
}

// Neverending loop with the main functionality
static inline void loop()
{
	for (;;)
	{
		const uint8_t i = PORTK;
		// Rotation is required by unavailable in C/C++
		// We use shift, the corresponding machine instructions
		// have to be replaced in the generated assembly code
		PORTF = i | (i << 2);
	}
}

int main()
{
	// Program structure stolen from Arduino
	init();
	loop();
	return 0;
}
