/*
 * This source file is part of libRocket, the HTML/CSS Interface Middleware
 *
 * For the latest information, see http://www.librocket.com
 *
 * Copyright (c) 2008-2010 CodePoint Ltd, Shift Technology Ltd
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "precompiled.h"
#include "PropertyParserNumber.h"

namespace Rocket {
namespace Core {

PropertyParserNumber::PropertyParserNumber()
{
	unit_suffixes.push_back(UnitSuffix(Property::PX, "px"));
	unit_suffixes.push_back(UnitSuffix(Property::REM, "rem"));
	unit_suffixes.push_back(UnitSuffix(Property::EM, "em"));
	unit_suffixes.push_back(UnitSuffix(Property::INCH, "in"));
	unit_suffixes.push_back(UnitSuffix(Property::CM, "cm"));
	unit_suffixes.push_back(UnitSuffix(Property::MM, "mm"));
	unit_suffixes.push_back(UnitSuffix(Property::PT, "pt"));
	unit_suffixes.push_back(UnitSuffix(Property::PC, "pc"));
	unit_suffixes.push_back(UnitSuffix(Property::PERCENT, "%"));
}

PropertyParserNumber::~PropertyParserNumber()
{
}

// Called to parse a RCSS number declaration.
bool PropertyParserNumber::ParseValue(Property& property, const String& value, const ParameterMap& ROCKET_UNUSED_PARAMETER(parameters)) const
{
	ROCKET_UNUSED(parameters);

	// Default to a simple number.
	property.unit = Property::NUMBER;

	// Check for a unit declaration at the end of the number.
	size_t suffixLength = 0;
	for (size_t i = 0; i < unit_suffixes.size(); i++)
	{
		const UnitSuffix& unit_suffix = unit_suffixes[i];

		if (value.Length() < unit_suffix.second.Length())
			continue;

		if (strcasecmp(value.CString() + (value.Length() - unit_suffix.second.Length()), unit_suffix.second.CString()) == 0)
		{
			// Found a suffix, remember the size.
			suffixLength = unit_suffix.second.Length();
			property.unit = unit_suffix.first;
			break;
		}
	}

	float float_value;
	// Remove the unit suffix if there was one so sscanf doesn't see it and get confused.
	int matched = sscanf(suffixLength == 0 ? value.CString() : value.Substring(0, value.Length() - suffixLength).CString(), "%f", &float_value);
	if (matched == 1)
	{
		property.value = Variant(float_value);
		return true;
	}

	return false;
}

// Destroys the parser.
void PropertyParserNumber::Release()
{
	delete this;
}

}
}
