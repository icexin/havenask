load('//aios/storage:defs.bzl', 'strict_cc_library')
strict_cc_library(
    name='trivial_task',
    srcs=['TrivialTask.cpp'],
    hdrs=['TrivialTask.h'],
    implementation_deps=[
        '//aios/storage/indexlib/framework:DiskSegment',
        '//aios/storage/indexlib/framework:MemSegment',
        '//aios/storage/indexlib/framework:TabletReader',
        '//aios/storage/indexlib/framework:TabletWriter',
        '//aios/storage/indexlib/framework:TabletLoader',
        '//aios/storage/indexlib/framework/index_task:IIndexTaskPlanCreator',
        '//aios/storage/indexlib/framework/index_task:IIndexTaskResourceCreator',
        '//aios/storage/indexlib/framework:ITabletExporter',
        '//aios/storage/indexlib/framework:ITabletImporter',
        '//aios/storage/indexlib/framework:ITabletValidator'
    ],
    visibility=[
        '//aios/apps/facility/build_service:__subpackages__',
        '//aios/storage/indexlib:__subpackages__'
    ],
    deps=[
        '//aios/storage/indexlib/document:interface',
        '//aios/storage/indexlib/framework:ITabletFactory',
        '//aios/storage/indexlib/framework/index_task:BasicDefs',
        '//aios/storage/indexlib/framework/index_task:IIndexOperationCreator',
        '//aios/storage/indexlib/framework/index_task:IndexOperation'
    ]
)
