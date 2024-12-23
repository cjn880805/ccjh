#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"


//舍身崖
#include "../d/sheshenya/sheshenya.h"
#include "../d/sheshenya/sheshenya_fangjian1.h"
#include "../d/sheshenya/sheshenya_fangjian2.h"
#include "../d/sheshenya/sheshenya_fangjian3.h"
#include "../d/sheshenya/sheshenya_shidong.h"
#include "../d/sheshenya/sheshenya_shishi1.h"
#include "../d/sheshenya/sheshenya_shishi2.h"
#include "../d/sheshenya/sheshenya_shishi3.h"
#include "../d/sheshenya/sheshenya_dixiashishi1.h"
#include "../d/sheshenya/sheshenya_dixiashishi2.h"

CRoom * Load_SheShenYa(string room_name)
{
	CRoom * r = NULL;

	//舍身崖
    if(room_name == "舍身崖")
		r = new CRSheShenYacity();
    else if(room_name == "舍身崖地下石室2")
		r = new CRSheShenYa_dixiashishi2();
    else if(room_name == "舍身崖地下石室1")
		r = new CRSheShenYa_dixiashishi1();
    else if(room_name == "舍身崖石室2")
		r = new CRSheShenYa_shishi2();
    else if(room_name == "舍身崖石室1")
		r = new CRSheShenYa_shishi1(); 
    else if(room_name == "舍身崖房间3")
		r = new CRSheShenYa_fangjian3();
    else if(room_name == "舍身崖房间1")
		r = new CRSheShenYa_fangjian1();
    else if(room_name == "舍身崖房间2")
		r = new CRSheShenYa_fangjian2();
    else if(room_name == "舍身崖石洞")
		r = new CRSheShenYa_shidong();

	return r;
}