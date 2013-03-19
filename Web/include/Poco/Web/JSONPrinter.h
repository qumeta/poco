//
// JSONPrinter.h
//
// $Id: //poco/Main/Web/include/Poco/Web/JSONPrinter.h#2 $
//
// Library: Web
// Package: Configuration
// Module:  JSONPrinter
//
// Definition of the JSONPrinter class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Web_JSONPrinter_INCLUDED
#define Web_JSONPrinter_INCLUDED


#include "Poco/Web/Web.h"
#include "Poco/Web/JSONHandler.h"
#include "Poco/Web/JSONEntity.h"
#include <ostream>


namespace Poco {
namespace Web {


class Web_API JSONPrinter: public JSONHandler
	/// Class that prints out he structure and values of a
	/// JSON string.
{
public:
	JSONPrinter(std::ostream& out, const std::string& indent = "\t");
		/// Creates JSONPrinter.

	~JSONPrinter();
		/// Destroys JSONPrinter.

	virtual void handleArrayBegin();
		/// Handles the array begin event.

	virtual void handleArrayEnd();
		/// Handles the array end event.

	virtual void handleObjectBegin();
		/// Handles the object begin event.

	virtual void handleObjectEnd();
		/// Handles the object end event.

	virtual void handleInteger(const JSONEntity& val);
		/// Handles the integer value event.

	virtual void handleFloat(const JSONEntity& val);
		/// Handles the float value event.

	virtual void handleNull();
		/// Handles the null value event.

	virtual void handleTrue();
		/// Handles the true value event.

	virtual void handleFalse();
		/// Handles the false value event.

	virtual void handleKey(const JSONEntity& val);
		/// Handles the key event.

	virtual void handleString(const JSONEntity& val);
		/// Handles the string value event.

private:
	void indent();

	std::string   _indent;
};


//
// inlines
//
inline void JSONPrinter::handleArrayBegin()
{
	if (!isKey()) indent();
	stream() << '[' << std::endl;
}


inline void JSONPrinter::handleArrayEnd()
{
	indent();
	stream() << ']' << std::endl;
}


inline void JSONPrinter::handleObjectBegin()
{
	if (!isKey()) indent();
	stream() << '{' << std::endl;
}


inline void JSONPrinter::handleObjectEnd()
{
	indent();
	stream() << '}' << std::endl;
}


inline void JSONPrinter::handleInteger(const JSONEntity& val)
{
	if (!isKey()) indent();
	stream() << "integer: " << val.toInteger() << std::endl;
}


inline void JSONPrinter::handleFloat(const JSONEntity& val)
{
	if (!isKey()) indent();
	stream() << "float: " << val.toFloat() << std::endl;
}


inline void JSONPrinter::handleNull()
{
	if (!isKey()) indent();
	stream() << "null" << std::endl;
}


inline void JSONPrinter::handleTrue()
{
	if (!isKey()) indent();
	stream() << "true" << std::endl;
}


inline void JSONPrinter::handleFalse()
{
	if (!isKey()) indent();
	stream() << "false" << std::endl;
}


inline void JSONPrinter::handleKey(const JSONEntity& val)
{
	setKey(true);
	stream() << "key = '" << val.toString() << "', value = ";
}


inline void JSONPrinter::handleString(const JSONEntity& val)
{
	if (!isKey()) indent();
	stream() << "string: '" << val.toString() << '\'' << std::endl;
}


} } // namespace Poco::Web


#endif // Web_JSONPrinter_INCLUDED
