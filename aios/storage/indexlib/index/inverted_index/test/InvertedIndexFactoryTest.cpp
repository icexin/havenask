#include "indexlib/index/inverted_index/InvertedIndexFactory.h"

#include "indexlib/index/IIndexMerger.h"
#include "indexlib/index/IIndexReader.h"
#include "indexlib/index/IndexerParameter.h"
#include "indexlib/index/inverted_index/config/SingleFieldIndexConfig.h"
#include "indexlib/index/inverted_index/config/test/InvertedIndexConfigCreator.h"
#include "unittest/unittest.h"

namespace indexlib::index {
class InvertedIndexFactoryTest : public TESTBASE
{
public:
    InvertedIndexFactoryTest() = default;
    ~InvertedIndexFactoryTest() = default;

    void setUp() override;
    void tearDown() override {}
};

void InvertedIndexFactoryTest::setUp() {}

TEST_F(InvertedIndexFactoryTest, TestSimpleProcess)
{
    optionflag_t optionFlag = of_none;
    auto indexConfig =
        InvertedIndexConfigCreator::CreateSingleFieldIndexConfig("NumberIndex", it_number, ft_integer, optionFlag);
    auto indexFactoryCreator = indexlibv2::index::IndexFactoryCreator::GetInstance();
    auto [status, indexFactory] = indexFactoryCreator->Create(indexConfig->GetIndexType());
    ASSERT_TRUE(status.IsOK());
    ASSERT_EQ(typeid(InvertedIndexFactory), typeid(*indexFactory));
    indexlibv2::index::IndexerParameter indexParam;
    ASSERT_TRUE(indexFactory->CreateDiskIndexer(indexConfig, indexParam));
    ASSERT_TRUE(indexFactory->CreateMemIndexer(indexConfig, indexParam));
    ASSERT_TRUE(indexFactory->CreateIndexReader(indexConfig, indexParam));
    ASSERT_TRUE(indexFactory->CreateIndexMerger(indexConfig));
    ASSERT_EQ(std::string("index"), indexFactory->GetIndexPath());
}

} // namespace indexlib::index
