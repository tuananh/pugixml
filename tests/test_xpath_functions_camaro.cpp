#ifndef PUGIXML_NO_XPATH

#include "test.hpp"

#include <string>

using namespace pugi;

TEST_XML(xpath_function_case, "<node>hello wORLd</node>")
{
	xml_node n = doc.child(STR("node"));

	CHECK_XPATH_STRING(n, STR("upper-case(.)"), STR("HELLO WORLD"));
	CHECK_XPATH_STRING(n, STR("lower-case(.)"), STR("hello world"));
    CHECK_XPATH_STRING(n, STR("title-case(.)"), STR("Hello World"));
    CHECK_XPATH_STRING(n, STR("camel-case(.)"), STR("helloWorld"));
    CHECK_XPATH_STRING(n, STR("snake-case(.)"), STR("hello_world"));
}
#endif
