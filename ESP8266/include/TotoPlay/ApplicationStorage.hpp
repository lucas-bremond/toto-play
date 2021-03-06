////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						TotoPlay/ApplicationStorage.hpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TotoPlay_ApplicationStorage_HPP_INCLUDED__
#define __TotoPlay_ApplicationStorage_HPP_INCLUDED__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SmingCore/SmingCore.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define APP_SETTINGS_FILE "settings.json"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ApplicationStorage
{

	public:

								ApplicationStorage							( ) ;

		bool 					isDefined									( ) ;

		const String&			accessSSID									( ) const ;
		const String&			accessPassword								( ) const ;

		void 					load										( ) ;
		void 					save										( ) ;

	private:

		String 					ssid_ ;
		String 					password_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////