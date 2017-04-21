#include "FrameLoader.h"

bool FrameLoader::Init()
{
	FRAMEArray ayFrames;
	FILE *file;
	file = fopen("proto/data/dataconfig_frame.data", "rb");
	if (file == NULL)
		return 0;
	char buffer[1024];
	int length = fread(buffer, 1, 1024, file);
	printf("length:%d", length);

	ayFrames.ParseFromArray(buffer, length);

	const FRAME *pFrameConfig;
	FrameData oFrameData;
	Option oOptionData;
	vector<Option> vOptions;
	for (int i = 0; i < ayFrames.items_size(); ++i)
	{
		vOptions.clear();
		pFrameConfig = &(ayFrames.items(i));
		oFrameData.iID = pFrameConfig->id();
		oFrameData.eType = static_cast<data::FrameType>(pFrameConfig->type());
		oFrameData.eDirection = static_cast<data::Direction>(pFrameConfig->direction());
		oFrameData.oPosition.iX = pFrameConfig->x();
		oFrameData.oPosition.iY = pFrameConfig->y();
		oFrameData.oSize.iWidth = pFrameConfig->width();
		oFrameData.oSize.iHeigth = pFrameConfig->height();
		oFrameData.sDescription = platform::UTF_82ASCII(pFrameConfig->description()).c_str();
		if (pFrameConfig->has_handle_id())
			oFrameData.iHandlerID = pFrameConfig->handle_id();
		else
			oFrameData.iHandlerID = NO_HANDLER;
		for (int j = 0; j < pFrameConfig->option().size(); ++j )
		{
			oOptionData.sDescription = platform::UTF_82ASCII(pFrameConfig->option(j).description());
			oOptionData.iFrameID = pFrameConfig->option(j).frame_id();
			vOptions.push_back(oOptionData);
		}
		oFrameData.vOptions = vOptions;
		m_mapFrameDatas.insert(pair<int, data::FrameData>(oFrameData.iID, oFrameData));
	}

	return true;
}

Frame *FrameLoader::GetFrameByID(int iID)
{
	Frame *pFrame = NULL;
	map<int, FrameData>::iterator it = m_mapFrameDatas.find(iID);
	if (it != m_mapFrameDatas.end())
	{
        const data::FrameType eFrameType = it->second.eType;
        pFrame = CreateFrameInstanceByType(eFrameType);
		pFrame->Init(it->second);
	}
	return pFrame;
}

void FrameLoader::ReleaseFrame(Frame *pFrame)
{
    if (pFrame != NULL)
        delete pFrame;
}

Frame * FrameLoader::CreateFrameInstanceByType(const data::FrameType eType)
{
    switch (eType)
    {
    case data::FRAME_TYPE_NORMAL:
        return new Frame;
    case data::FRAME_TYPE_BAG:
        return new BagFrame;
    case data::FRAME_TYPE_ITEM:
        return new ItemFrame;
    case data::FRAME_TYPE_SHOP:
        return new ShopFrame;
    case data::FRAME_TYPE_SHOP_ITEM:
        return new ShopItemFrame;
    default:
        return new Frame;
    }
    return new Frame;
}

