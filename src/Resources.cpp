#include "Resource.hpp"

char* strdupxx(std::string_view str)
{
	size_t str_len = str.length();
	char* new_str = new char[str_len];
	std::char_traits<char>::copy(new_str, str.data(), str_len + 1); // terminating zero
	return new_str;
}

Resource::Resource(http_methd_t _method, const char* _url)
	: method(_method)
	, url(strdupxx(_url))
	// , configured(false)
{
	// assert(_url && "Resource has null url!");
	// url = strdupxx(_url);
}


Resource::~Resource()
{
	if (url)
	{
		delete[] url; 
	}
}


