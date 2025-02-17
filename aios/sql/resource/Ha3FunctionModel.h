/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <stdint.h>
#include <string>

namespace sql {

class Ha3FunctionModel {
public:
    Ha3FunctionModel()
        : functionVersion(0) {}

    bool isValid() const {
        if (catalogName.empty() || databaseName.empty() || functionVersion <= 0
            || ha3FunctionsDefContent.empty()) {
            return false;
        }
        return true;
    }

public:
    std::string catalogName;
    std::string databaseName;
    int64_t functionVersion;
    std::string ha3FunctionsDefContent;
};

} // namespace sql
