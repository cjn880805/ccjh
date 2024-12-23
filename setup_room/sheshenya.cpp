#include "stdafx.h"
#include "../server/Room.h"
#include "../server/Char.h"


//������
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

	//������
    if(room_name == "������")
		r = new CRSheShenYacity();
    else if(room_name == "�����µ���ʯ��2")
		r = new CRSheShenYa_dixiashishi2();
    else if(room_name == "�����µ���ʯ��1")
		r = new CRSheShenYa_dixiashishi1();
    else if(room_name == "������ʯ��2")
		r = new CRSheShenYa_shishi2();
    else if(room_name == "������ʯ��1")
		r = new CRSheShenYa_shishi1(); 
    else if(room_name == "�����·���3")
		r = new CRSheShenYa_fangjian3();
    else if(room_name == "�����·���1")
		r = new CRSheShenYa_fangjian1();
    else if(room_name == "�����·���2")
		r = new CRSheShenYa_fangjian2();
    else if(room_name == "������ʯ��")
		r = new CRSheShenYa_shidong();

	return r;
}