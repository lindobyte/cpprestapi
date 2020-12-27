#pragma once

#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/uri.h"
#include <string>

class headerKey {
public:
    static const utility::string_t contentType;
    static const utility::string_t accept;
};

class headerValue {
public:
    static const utility::string_t applicationJson;
};
