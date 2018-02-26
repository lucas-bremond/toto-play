////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///	This file is part of the TotoPlay library.
///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///	@file						TotoPlay/ServerManager.cpp
///	@author						Lucas Bremond <lucas@axelspace.com>
///	@date						9 Oct 2016

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <TotoPlay/ServerManager.hpp>
#include <TotoPlay/Version.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace TotoPlay
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef Delegate<void(HttpRequest&, HttpResponse&)> HttpPathDelegate ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

								ServerManager::ServerManager				( )
								:	port_(80),
									serverPtr_(nullptr),
									actionManagerPtr_(nullptr)
{

}

bool							ServerManager::isActive						( ) const
{
	return (serverPtr_ != nullptr) ;
}

void							ServerManager::start						( )
{

	if (this->isActive())
	{
		this->stop() ;
	}

	serverPtr_																	=		new HttpServer() ;

	if (serverPtr_ != nullptr)
	{

		serverPtr_->listen(port_) ;

		serverPtr_->setDefaultHandler(HttpPathDelegate(&ServerManager::onFile, this)) ;

		serverPtr_->addPath("/", HttpPathDelegate(&ServerManager::onIndex, this)) ;
		serverPtr_->addPath("/status", HttpPathDelegate(&ServerManager::onStatus, this)) ;
		serverPtr_->addPath("/time", HttpPathDelegate(&ServerManager::onTime, this)) ;
		serverPtr_->addPath("/action", HttpPathDelegate(&ServerManager::onAction, this)) ;

	}

}

void							ServerManager::stop							( )
{

	if (!this->isActive())
	{
		return ;
	}

	delete serverPtr_ ;

	serverPtr_																	=		nullptr ;

}

void							ServerManager::associateActionManager		(			ActionManager&				anActionManager						)
{
	actionManagerPtr_															=		&anActionManager ;
}

void							ServerManager::onIndex						(			HttpRequest&				aRequest,
																						HttpResponse&				aResponse							)
{

	aResponse.setCache(86400, true) ;

	aResponse.sendFile("index.html") ;

}

void							ServerManager::onFile						(			HttpRequest&				aRequest,
																						HttpResponse&				aResponse							)
{
	
	String						file											=		aRequest.getPath() ;

	if (file[0] == '/')
	{
		file																	=		file.substring(1) ;
	}

	if (file[0] == '.')
	{
		aResponse.forbidden() ;
	}
	else
	{
	
		aResponse.setCache(86400, true) ;
		aResponse.sendFile(file) ;
	
	}

}

void							ServerManager::onStatus						(			HttpRequest&				aRequest,
																						HttpResponse&				aResponse							)
{

	if (aRequest.method == HTTP_GET)
	{

		JsonObjectStream*		JSONStream										=		new JsonObjectStream() ;

		JsonObject&				JSONObject										=		JSONStream->getRoot() ;
	
		JSONObject["status"]													=		(bool)true ;
		JSONObject["version"]													=		(String)Version::Current().getString() ;

		aResponse.sendJsonObject(JSONStream) ;

	}
	else
	{
		aResponse.code = HTTP_STATUS_FORBIDDEN ;
	}

}

void							ServerManager::onTime				(			HttpRequest&				aRequest,
																						HttpResponse&				aResponse							)
{

	if (aRequest.method == HTTP_GET)
	{

		JsonObjectStream*		JSONStream										=		new JsonObjectStream() ;

		JsonObject&				JSONObject										=		JSONStream->getRoot() ;
	
		JSONObject["time"]														=		(String)Time::Now().getString() ;

		aResponse.sendJsonObject(JSONStream) ;

	}
	else
	{
		aResponse.code = HTTP_STATUS_FORBIDDEN ;
	}

}

void							ServerManager::onAction						(			HttpRequest&				aRequest,
																						HttpResponse&				aResponse							)
{

	if (!actionManagerPtr_)
	{
		return aResponse.notFound() ;
	}

	if (aRequest.method == HTTP_POST)
	{

		String					actionTypeString								=		aRequest.getPostParameter("type") ;

		if (actionTypeString == "")
		{
			aResponse.code = HTTP_STATUS_FORBIDDEN ;
			return ;
		}

		Action::Type			actionType										=		Action::TypeFromString(actionTypeString) ;

		if (actionType == Action::Type::Undefined)
		{
			aResponse.code = HTTP_STATUS_FORBIDDEN ;
			return ;
		}

		switch (actionType)
		{

			case Action::Type::Rotation:
			{

				String			rotationAngleString								=		aRequest.getPostParameter("rotation_angle") ;

				if (rotationAngleString == "")
				{
					aResponse.code = HTTP_STATUS_FORBIDDEN ;
					return ;
				}

				Angle			rotationAngle									=		Angle::Parse(rotationAngleString) ;

				if (!rotationAngle.isDefined())
				{
					aResponse.code = HTTP_STATUS_FORBIDDEN ;
					return ;
				}

				if (!actionManagerPtr_->addAction(Action::Rotation(rotationAngle)))
				{
					aResponse.code = HTTP_STATUS_FORBIDDEN ;
					return ;
				}

				break ;

			}

			default:
				aResponse.code = HTTP_STATUS_FORBIDDEN ;
				return ;

		}

	}
	else
	{
		aResponse.code = HTTP_STATUS_FORBIDDEN ;
		return ;
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////