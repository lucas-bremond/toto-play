////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						TotoPlay/WiFiManager.hpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TotoPlay_WiFiManager_HPP_INCLUDED__
#define __TotoPlay_WiFiManager_HPP_INCLUDED__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SmingCore/SmingCore.h>

#include <TotoPlay/ApplicationStorage.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class WiFiManager
{

	public:

		enum class Mode
		{

			Station,
			AccessPoint

		} ;

								WiFiManager 								( ) ;

		bool					isActive									( ) const ;

		WiFiManager::Mode		getMode										( ) const ;

		void					setMode										(	const 	WiFiManager::Mode&			aMode								) ;

		void					start										( ) ;
		void					stop										( ) ;

		void					associateApplicationStorage					(			ApplicationStorage&			anApplicationStorage				) ;

		void					setConnectionSuccessHandler					(			Delegate<void()>			aDelegate							) ;
		void					setConnectionFailureHandler					(			Delegate<void()>			aDelegate							) ;

		static String			getModeFromString							(	const 	String&						aString								) ;

	private:

		WiFiManager::Mode		mode_ ;

		String					SSID_ ;
		String					password_ ;

		bool					active_ ;

		ApplicationStorage*		applicationStoragePtr_ ;

		Delegate<void()>		connectionSuccessHandler_ ;
		Delegate<void()>		connectionFailureHandler_ ;

		void					startmDNS									( ) ;

		void					onConnectionSuccess							(			IPAddress					anIPAddress,
																						IPAddress					aMask,
																						IPAddress					aGateway							) ;
		
		void					onConnectionFailure							(			String						aSsid,
																						uint8_t						aSsidLength,
																						uint8_t						*bssid,
																						uint8_t						aReason								) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////