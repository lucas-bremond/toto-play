////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file 						TotoPlay/StepperMotorController.hpp
///	@author 					Lucas Bremond <lucas@axelspace.com>
///	@date 						17 Nov 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __TotoPlay_StepperMotorController_HPP_INCLUDED__
#define __TotoPlay_StepperMotorController_HPP_INCLUDED__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SmingCore/SmingCore.h>

#include <TotoPlay/Angle.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief						Stepper motor controller class
///
/// @note						Reference: https://github.com/bdargham/BYJ48-Stepper/blob/master/Stepper%20Driver.ino

class StepperMotorController
{

	public:

		enum class Mode
		{

			Forward,
			Reverse,
			Both

		} ;

								StepperMotorController						(	const	uint8_t&					aFirstPin,
																				const	uint8_t&					aSecondPin,
																				const	uint8_t&					aThirdPin,
																				const	uint8_t&					aFourthPin							) ;

								~StepperMotorController 					( ) ;

		bool					isDefined									( ) const ;
		bool					isBusy										( ) const ;

		double					getInputRadius								( ) const ;
		double					getOutputRadius								( ) const ;
		uint					getStepsPerRotation							( ) const ;
		
		uint8_t 				getPinA										( ) const ;
		uint8_t 				getPinB										( ) const ;
		uint8_t 				getPinC										( ) const ;
		uint8_t 				getPinD										( ) const ;

		void					rotate										(	const	Angle&						anAngle								) ;

		// static StepperMotorController Pins									(	const	uint8_t&					aFirstPin,
		// 																		const	uint8_t&					aSecondPin,
		// 																		const	uint8_t&					aThirdPin,
		// 																		const	uint8_t&					aFourthPin							) ;

	private:

		uint8_t					pin_A_ ;
		uint8_t					pin_B_ ;
		uint8_t					pin_C_ ;
		uint8_t					pin_D_ ;

		double					inputRadius_ ;
		double					outputRadius_ ;

		uint					stepsPerRotation_ ;

		StepperMotorController::Mode mode_ ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////