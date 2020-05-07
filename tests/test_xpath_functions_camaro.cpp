#ifndef PUGIXML_NO_XPATH

#include "test.hpp"

#include <string>

using namespace pugi;

TEST_XML(xpath_function_case, "<node>hello wORLd</node>")
{
	xml_node n = doc.child(STR("node"));

    // x-case functions with 0 arguments
    CHECK_XPATH_FAIL(STR("upper-case()"));
    CHECK_XPATH_FAIL(STR("lower-case()"));
    CHECK_XPATH_FAIL(STR("title-case()"));
    CHECK_XPATH_FAIL(STR("camel-case()"));
    CHECK_XPATH_FAIL(STR("snake-case()"));

    // x-case functions with 1 arguments
	CHECK_XPATH_STRING(n, STR("upper-case(.)"), STR("HELLO WORLD"));
	CHECK_XPATH_STRING(n, STR("lower-case(.)"), STR("hello world"));
    CHECK_XPATH_STRING(n, STR("title-case(.)"), STR("Hello World"));
    CHECK_XPATH_STRING(n, STR("camel-case(.)"), STR("helloWorld"));
    CHECK_XPATH_STRING(n, STR("snake-case(.)"), STR("hello_world"));
}

TEST_XML(xpath_function_string_join, "<nodes><node>node 1</node><node>node 2</node></nodes>")
{
	xml_node n = doc.child(STR("nodes"));

    // string-join functions with 0 arguments
    CHECK_XPATH_FAIL(STR("string-join()"));

    // string-join functions with 1 arguments
	CHECK_XPATH_STRING(n, STR("string-join(node)"), STR("node 1node 2"));
}

TEST_XML(xpath_function_raw, "<nodes><node>1</node><node>2</node></nodes>")
{
    // string-join functions with 0 arguments
    CHECK_XPATH_STRING(doc, STR("raw()"), STR("<nodes>\n\t<node>1</node>\n\t<node>2</node>\n</nodes>\n"));

    // string-join functions with 1 arguments
	CHECK_XPATH_STRING(doc, STR("raw(nodes)"), STR("<nodes>\n\t<node>1</node>\n\t<node>2</node>\n</nodes>\n"));
    CHECK_XPATH_STRING(doc, STR("raw(//node)"), STR("<node>1</node>\n"));
}

#endif
