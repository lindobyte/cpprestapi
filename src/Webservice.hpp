#pragma once

#include "cpprest/asyncrt_utils.h"
#include "cpprest/http_listener.h"
#include "cpprest/json.h"
#include "cpprest/uri.h"
#include <string>

namespace header {
    namespace key {
        const std::string contentType = "content-type";
        const std::string accept      = "accept";
    }
    namespace value {
        const std::string applicationJson = "application/json";
    }
}