/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef UNICODE_H_
#define UNICODE_H_

#include "../platform.h"

#ifndef PLATFORM_WIN
#define wchar_t short 
#endif

namespace sys {
  namespace lang {
		
	class unicode {
		wchar_t* ustring;
		int count;
	
		void create(const char* ascii, int len);
		void asciitowide(wchar_t* unicode, const char* ascii, int len); 
	
		void copy(wchar_t* dest, const wchar_t* src); 
		void copy(wchar_t* dest, const wchar_t* src, int len); 
		
	public:
		unicode();
		unicode(const char* ascii);
		unicode(const string& ascii);
		unicode(const char* ascii, int len);
		unicode(const unicode& str);
	
		~unicode();
	
		unicode& operator=(const unicode& str);
		unicode& operator=(const string& ascii);
		unicode& operator+(const string& ascii);
	
		char operator[](int index);
	
		void append(const string& ascii);
		void append(const char* ascii, int len);
		void append(const wchar_t* str, int len);
	
		int indexOf(wchar_t chr);
	
		unicode substring(int beg, int end);
	
		void clear();
		
		const char* u_str() const;
	
		string c_str() const;
		void c_str(string& ascii) const;
	
		inline int size() const {
			return count;
		}
	
	};

  } // namespace lang
} // namespace sys

using namespace sys::lang;

#endif /*UNICODE_H_*/
