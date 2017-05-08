#include "DropLoader.h"

#include "dataconfig_drop.pb.h"

using dataconfig::DROPArray;
using dataconfig::DROP;

DropLoader::DropLoader()
{
}


DropLoader::~DropLoader()
{
}

bool DropLoader::Load()
{
    DROPArray arrayDrop;
    if (!GetConfigArray(arrayDrop))
        return false;

    for (int i = 0; i < arrayDrop.items_size(); ++i)
    {
        const DROP oConfig = arrayDrop.items(i);

        Drop oDrop;
        if (!oDrop.Init(oConfig.id(), oConfig.item_id(), oConfig.item_num()))
            return false;

        m_mapDrop.insert(make_pair(oDrop.GetID(), oDrop));
    }

    return true;
}
