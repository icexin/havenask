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
#ifndef __INDEXLIB_RANGE_QUERY_EVALUATOR_H
#define __INDEXLIB_RANGE_QUERY_EVALUATOR_H

#include <memory>

#include "indexlib/common_define.h"
#include "indexlib/document/query/function_executor.h"
#include "indexlib/document/query/query_evaluator.h"
#include "indexlib/document/query/range_query.h"
#include "indexlib/indexlib.h"

namespace indexlib { namespace document {

class RangeQueryEvaluator : public QueryEvaluator
{
public:
    RangeQueryEvaluator(evaluatorid_t id = INVALID_EVALUATOR_ID) : QueryEvaluator(QET_RANGE, id) {}

    ~RangeQueryEvaluator() {}

public:
    void Init(const std::string& fieldName, const RangeQuery::RangeInfo& rangeInfo)
    {
        mFieldName = fieldName;
        mRangeInfo = rangeInfo;
    }

    void Init(const FunctionExecutorPtr& function, const RangeQuery::RangeInfo& rangeInfo)
    {
        assert(function);
        mFunc = function;
        mFieldName = mFunc->GetFunctionKey();
        mRangeInfo = rangeInfo;
    }

    EvaluatorState DoEvaluate(EvaluatorStateHandler& handler, const RawDocumentPtr& rawDoc,
                              EvaluateParam param) override;

private:
    FunctionExecutorPtr mFunc;
    std::string mFieldName;
    RangeQuery::RangeInfo mRangeInfo;

private:
    IE_LOG_DECLARE();
};

DEFINE_SHARED_PTR(RangeQueryEvaluator);
}} // namespace indexlib::document

#endif //__INDEXLIB_RANGE_QUERY_EVALUATOR_H
