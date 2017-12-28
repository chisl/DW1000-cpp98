/*
 * name:        DW1000
 * description: A fully integrated single chip Ultra Wideband (UWB) low-power low-cost transceiver IC for 2-way ranging or TDOA location systems.
 * manuf:       Decawave
 * version:     0.1
 * url:         http://www.decawave.com/support/download/file/nojs/796
 * date:        2017-02-07
 * author       https://chisl.io/
 * file:        DW1000.hpp
 */

#include <cinttypes>

/* Derive from class DW1000_Base and implement the read and write functions! */

/* DW1000: A fully integrated single chip Ultra Wideband (UWB) low-power low-cost transceiver IC for 2-way ranging or TDOA location systems. */
class DW1000_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG DEV_ID                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG DEV_ID:
	 * 7.2.2
	 * Register 0x00 is the device identifier.
	 * This is hard-coded into the silicon.
	 * The value in this register is read-only and cannot be overwritten by the host system.
	 * The device ID will be changed for any silicon updates.
	 * The device ID register is ideal to use in the host μP to validate that the SPI interface
	 * is operational.
	 * It is expected that the host system will validate that the device ID is the expected
	 * value, supported by its software, before proceeding to use the IC.
	 */
	struct DEV_ID
	{
		static const uint16_t __address = 0;
		
		/* Bits DEV_ID: */
		struct DEV_ID_
		{
			/* Mode: */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register DEV_ID */
	void setDEV_ID(uint8_t value)
	{
		write(DEV_ID::__address, value, 8);
	}
	
	/* Get register DEV_ID */
	uint8_t getDEV_ID()
	{
		return read8(DEV_ID::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG SYS_CFG                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG SYS_CFG:
	 * 7.2.6
	 * Register 0x04 is the system configuration register.
	 * This is a bitmapped register.
	 * Each bit field is separately identified and described below.
	 * The System Configuration register contains the following bitmapped sub-fields: Definition
	 * of the bit fields within REG:04:00 – SYS_CFG: System Configuration bitmap: -
	 */
	struct SYS_CFG
	{
		static const uint16_t __address = 4;
		
		/* Bits SYS_CFG: */
		struct SYS_CFG_
		{
			/* Mode: */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register SYS_CFG */
	void setSYS_CFG(uint8_t value)
	{
		write(SYS_CFG::__address, value, 8);
	}
	
	/* Get register SYS_CFG */
	uint8_t getSYS_CFG()
	{
		return read8(SYS_CFG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG TX_FCTRL                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG TX_FCTRL:
	 * 7.2.10
	 * Register 0x08, the transmit frame control register, contains a number of TX control fields.
	 * (For a general discussion of transmission please refer to section 3 – Message Transmission.)
	 */
	struct TX_FCTRL
	{
		static const uint16_t __address = 8;
		
		/* Bits TX_FCTRL: */
		struct TX_FCTRL_
		{
			/* Mode:rw */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register TX_FCTRL */
	void setTX_FCTRL(uint8_t value)
	{
		write(TX_FCTRL::__address, value, 8);
	}
	
	/* Get register TX_FCTRL */
	uint8_t getTX_FCTRL()
	{
		return read8(TX_FCTRL::__address, 8);
	}
	
};
