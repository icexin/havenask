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
#ifndef __INDEXLIB_CUSTOMIZED_INDEX_CONFIG_H
#define __INDEXLIB_CUSTOMIZED_INDEX_CONFIG_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/config/package_index_config.h"
#include "indexlib/indexlib.h"
#include "indexlib/util/KeyValueMap.h"

namespace indexlib { namespace config {

class CustomizedIndexConfig : public PackageIndexConfig
{
public:
    CustomizedIndexConfig(const std::string& indexName);
    CustomizedIndexConfig(const CustomizedIndexConfig& other);
    ~CustomizedIndexConfig();

public:
    void Check() const override;
    void Jsonize(autil::legacy::Jsonizable::JsonWrapper& json) override;
    void AssertEqual(const IndexConfig& other) const override;
    void AssertCompatible(const IndexConfig& other) const override;
    IndexConfig* Clone() const override;
    std::unique_ptr<indexlibv2::config::InvertedIndexConfig> ConstructConfigV2() const override;

public:
    const std::string& GetIndexerName() const;
    const util::KeyValueMap& GetParameters() const;

public: // for test
    void SetIndexer(const std::string& indexerName);
    void SetParameters(const util::KeyValueMap& params);

protected:
    bool CheckFieldType(FieldType ft) const override;
    bool FulfillConfigV2(indexlibv2::config::InvertedIndexConfig* configV2) const override;

private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;

private:
    inline static const std::string AITHETA_INDEXER_NAME = "aitheta_indexer";
    inline static const std::string AITHETA2_INDEXER_NAME = "aitheta2_indexer";

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(CustomizedIndexConfig);
}} // namespace indexlib::config

#endif //__INDEXLIB_CUSTOMIZED_INDEX_CONFIG_H
