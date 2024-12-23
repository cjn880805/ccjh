#include "stdafx.h"
#include "../std/RField.h"

//野外
#include "../d/yewai_room.h"
#include "../d/cunluo_room.h"

#include "../d/senlin/cunzi.h"
#include "../d/senlin/senlin1.h"
#include "../d/senlin/senlin2.h"
#include "../d/senlin/senlin3.h"
#include "../d/senlin/senlin4.h"
#include "../d/senlin/senlin5.h"
#include "../d/senlin/senlin6.h"
#include "../d/senlin/senlin7.h"
#include "../d/senlin/senlin8.h"

//18地狱
#include "../d/18hell/18_1/18hell_1.h"
#include "../d/18hell/18_1/18hell_1_1.h"
#include "../d/18hell/18_1/18hell_1_2.h"
#include "../d/18hell/18_1/18hell_1_3.h"
#include "../d/18hell/18_1/18hell_1_4.h"
#include "../d/18hell/18_1/18hell_1_5.h"
#include "../d/18hell/18_1/18hell_1_6.h"
#include "../d/18hell/18_1/18hell_1_7.h"
#include "../d/18hell/18_1/18hell_1_8.h"

#include "../d/18hell/18_2/18hell_2.h"
#include "../d/18hell/18_2/18hell_2_1.h"
#include "../d/18hell/18_2/18hell_2_2.h"
#include "../d/18hell/18_2/18hell_2_3.h"
#include "../d/18hell/18_2/18hell_2_4.h"
#include "../d/18hell/18_2/18hell_2_5.h"
#include "../d/18hell/18_2/18hell_2_6.h"
#include "../d/18hell/18_2/18hell_2_7.h"
#include "../d/18hell/18_2/18hell_2_8.h"

#include "../d/18hell/18_3/18hell_3.h"
#include "../d/18hell/18_3/18hell_3_1.h"
#include "../d/18hell/18_3/18hell_3_2.h"
#include "../d/18hell/18_3/18hell_3_3.h"
#include "../d/18hell/18_3/18hell_3_4.h"
#include "../d/18hell/18_3/18hell_3_5.h"
#include "../d/18hell/18_3/18hell_3_6.h"
#include "../d/18hell/18_3/18hell_3_7.h"
#include "../d/18hell/18_3/18hell_3_8.h"

#include "../d/18hell/18_4/18hell_4.h"
#include "../d/18hell/18_4/18hell_4_1.h"
#include "../d/18hell/18_4/18hell_4_2.h"
#include "../d/18hell/18_4/18hell_4_3.h"
#include "../d/18hell/18_4/18hell_4_4.h"
#include "../d/18hell/18_4/18hell_4_5.h"
#include "../d/18hell/18_4/18hell_4_6.h"
#include "../d/18hell/18_4/18hell_4_7.h"
#include "../d/18hell/18_4/18hell_4_8.h"

#include "../d/18hell/18_5/18hell_5.h"
#include "../d/18hell/18_5/18hell_5_1.h"
#include "../d/18hell/18_5/18hell_5_2.h"
#include "../d/18hell/18_5/18hell_5_3.h"
#include "../d/18hell/18_5/18hell_5_4.h"
#include "../d/18hell/18_5/18hell_5_5.h"
#include "../d/18hell/18_5/18hell_5_6.h"
#include "../d/18hell/18_5/18hell_5_7.h"
#include "../d/18hell/18_5/18hell_5_8.h"

#include "../d/18hell/18_6/18hell_6.h"
#include "../d/18hell/18_6/18hell_6_1.h"
#include "../d/18hell/18_6/18hell_6_2.h"
#include "../d/18hell/18_6/18hell_6_3.h"
#include "../d/18hell/18_6/18hell_6_4.h"
#include "../d/18hell/18_6/18hell_6_5.h"
#include "../d/18hell/18_6/18hell_6_6.h"
#include "../d/18hell/18_6/18hell_6_7.h"
#include "../d/18hell/18_6/18hell_6_8.h"

#include "../d/18hell/18_7/18hell_7.h"
#include "../d/18hell/18_7/18hell_7_1.h"
#include "../d/18hell/18_7/18hell_7_2.h"
#include "../d/18hell/18_7/18hell_7_3.h"
#include "../d/18hell/18_7/18hell_7_4.h"
#include "../d/18hell/18_7/18hell_7_5.h"
#include "../d/18hell/18_7/18hell_7_6.h"
#include "../d/18hell/18_7/18hell_7_7.h"
#include "../d/18hell/18_7/18hell_7_8.h"

#include "../d/18hell/18_8/18hell_8.h"
#include "../d/18hell/18_8/18hell_8_1.h"
#include "../d/18hell/18_8/18hell_8_2.h"
#include "../d/18hell/18_8/18hell_8_3.h"
#include "../d/18hell/18_8/18hell_8_4.h"
#include "../d/18hell/18_8/18hell_8_5.h"
#include "../d/18hell/18_8/18hell_8_6.h"
#include "../d/18hell/18_8/18hell_8_7.h"
#include "../d/18hell/18_8/18hell_8_8.h"

#include "../d/18hell/18_9/18hell_9.h"
#include "../d/18hell/18_9/18hell_9_1.h"
#include "../d/18hell/18_9/18hell_9_2.h"
#include "../d/18hell/18_9/18hell_9_3.h"
#include "../d/18hell/18_9/18hell_9_4.h"
#include "../d/18hell/18_9/18hell_9_5.h"
#include "../d/18hell/18_9/18hell_9_6.h"
#include "../d/18hell/18_9/18hell_9_7.h"
#include "../d/18hell/18_9/18hell_9_8.h"

#include "../d/18hell/18_10/18hell_10.h"
#include "../d/18hell/18_10/18hell_10_1.h"
#include "../d/18hell/18_10/18hell_10_2.h"
#include "../d/18hell/18_10/18hell_10_3.h"
#include "../d/18hell/18_10/18hell_10_4.h"
#include "../d/18hell/18_10/18hell_10_5.h"
#include "../d/18hell/18_10/18hell_10_6.h"
#include "../d/18hell/18_10/18hell_10_7.h"
#include "../d/18hell/18_10/18hell_10_8.h"

#include "../d/18hell/18_11/18hell_11.h"
#include "../d/18hell/18_11/18hell_11_1.h"
#include "../d/18hell/18_11/18hell_11_2.h"
#include "../d/18hell/18_11/18hell_11_3.h"
#include "../d/18hell/18_11/18hell_11_4.h"
#include "../d/18hell/18_11/18hell_11_5.h"
#include "../d/18hell/18_11/18hell_11_6.h"
#include "../d/18hell/18_11/18hell_11_7.h"
#include "../d/18hell/18_11/18hell_11_8.h"

#include "../d/18hell/18_12/18hell_12.h"
#include "../d/18hell/18_12/18hell_12_1.h"
#include "../d/18hell/18_12/18hell_12_2.h"
#include "../d/18hell/18_12/18hell_12_3.h"
#include "../d/18hell/18_12/18hell_12_4.h"
#include "../d/18hell/18_12/18hell_12_5.h"
#include "../d/18hell/18_12/18hell_12_6.h"
#include "../d/18hell/18_12/18hell_12_7.h"
#include "../d/18hell/18_12/18hell_12_8.h"

#include "../d/18hell/18_13/18hell_13.h"
#include "../d/18hell/18_13/18hell_13_1.h"
#include "../d/18hell/18_13/18hell_13_2.h"
#include "../d/18hell/18_13/18hell_13_3.h"
#include "../d/18hell/18_13/18hell_13_4.h"
#include "../d/18hell/18_13/18hell_13_5.h"
#include "../d/18hell/18_13/18hell_13_6.h"
#include "../d/18hell/18_13/18hell_13_7.h"
#include "../d/18hell/18_13/18hell_13_8.h"

#include "../d/18hell/18_14/18hell_14.h"
#include "../d/18hell/18_14/18hell_14_1.h"
#include "../d/18hell/18_14/18hell_14_2.h"
#include "../d/18hell/18_14/18hell_14_3.h"
#include "../d/18hell/18_14/18hell_14_4.h"
#include "../d/18hell/18_14/18hell_14_5.h"
#include "../d/18hell/18_14/18hell_14_6.h"
#include "../d/18hell/18_14/18hell_14_7.h"
#include "../d/18hell/18_14/18hell_14_8.h"

#include "../d/18hell/18_15/18hell_15.h"
#include "../d/18hell/18_15/18hell_15_1.h"
#include "../d/18hell/18_15/18hell_15_2.h"
#include "../d/18hell/18_15/18hell_15_3.h"
#include "../d/18hell/18_15/18hell_15_4.h"
#include "../d/18hell/18_15/18hell_15_5.h"
#include "../d/18hell/18_15/18hell_15_6.h"
#include "../d/18hell/18_15/18hell_15_7.h"
#include "../d/18hell/18_15/18hell_15_8.h"

#include "../d/18hell/18_16/18hell_16.h"
#include "../d/18hell/18_16/18hell_16_1.h"
#include "../d/18hell/18_16/18hell_16_2.h"
#include "../d/18hell/18_16/18hell_16_3.h"
#include "../d/18hell/18_16/18hell_16_4.h"
#include "../d/18hell/18_16/18hell_16_5.h"
#include "../d/18hell/18_16/18hell_16_6.h"
#include "../d/18hell/18_16/18hell_16_7.h"
#include "../d/18hell/18_16/18hell_16_8.h"

#include "../d/18hell/18_17/18hell_17.h"
#include "../d/18hell/18_17/18hell_17_1.h"
#include "../d/18hell/18_17/18hell_17_2.h"
#include "../d/18hell/18_17/18hell_17_3.h"
#include "../d/18hell/18_17/18hell_17_4.h"
#include "../d/18hell/18_17/18hell_17_5.h"
#include "../d/18hell/18_17/18hell_17_6.h"
#include "../d/18hell/18_17/18hell_17_7.h"
#include "../d/18hell/18_17/18hell_17_8.h"

#include "../d/18hell/18_18/18hell_18.h"
#include "../d/18hell/18_18/18hell_18_1.h"
#include "../d/18hell/18_18/18hell_18_2.h"
#include "../d/18hell/18_18/18hell_18_3.h"
#include "../d/18hell/18_18/18hell_18_4.h"
#include "../d/18hell/18_18/18hell_18_5.h"
#include "../d/18hell/18_18/18hell_18_6.h"
#include "../d/18hell/18_18/18hell_18_7.h"
#include "../d/18hell/18_18/18hell_18_8.h"

#include "../d/18hell/18_19/18hell_19.h"
#include "../d/18hell/18_19/18hell_19_1.h"
#include "../d/18hell/18_19/18hell_19_2.h"
#include "../d/18hell/18_19/18hell_19_3.h"
#include "../d/18hell/18_19/18hell_19_4.h"
#include "../d/18hell/18_19/18hell_19_5.h"
#include "../d/18hell/18_19/18hell_19_6.h"
#include "../d/18hell/18_19/18hell_19_7.h"
#include "../d/18hell/18_19/18hell_19_8.h"

#include "../d/18hell/18_20/18hell_20.h"
#include "../d/18hell/18_20/18hell_20_1.h"
#include "../d/18hell/18_20/18hell_20_2.h"
#include "../d/18hell/18_20/18hell_20_3.h"
#include "../d/18hell/18_20/18hell_20_4.h"
#include "../d/18hell/18_20/18hell_20_5.h"
#include "../d/18hell/18_20/18hell_20_6.h"
#include "../d/18hell/18_20/18hell_20_7.h"
#include "../d/18hell/18_20/18hell_20_8.h"

#include "../d/18hell/18_21/18hell_21.h"
#include "../d/18hell/18_21/18hell_21_1.h"
#include "../d/18hell/18_21/18hell_21_2.h"
#include "../d/18hell/18_21/18hell_21_3.h"
#include "../d/18hell/18_21/18hell_21_4.h"
#include "../d/18hell/18_21/18hell_21_5.h"
#include "../d/18hell/18_21/18hell_21_6.h"
#include "../d/18hell/18_21/18hell_21_7.h"
#include "../d/18hell/18_21/18hell_21_8.h"

#include "../d/18hell/18_22/18hell_22.h"
#include "../d/18hell/18_22/18hell_22_1.h"
#include "../d/18hell/18_22/18hell_22_2.h"
#include "../d/18hell/18_22/18hell_22_3.h"
#include "../d/18hell/18_22/18hell_22_4.h"
#include "../d/18hell/18_22/18hell_22_5.h"
#include "../d/18hell/18_22/18hell_22_6.h"
#include "../d/18hell/18_22/18hell_22_7.h"
#include "../d/18hell/18_22/18hell_22_8.h"

#define DEFINEYEWAICREATEROOM(func) CRoom * func(UINT n)
typedef CRoom * (* YEWAICREATEROOMFUNC)(UINT n);
typedef struct _YEWAIDATA
{
	YEWAICREATEROOMFUNC Func;		//分配房间的函数指针
	UINT nWidth;					//野外区域宽
	UINT nHeight;					//野外区域高
	UINT nMaxRoom;					//使用的Room最大数
	BOOL bCunLuo;					//是否有村落
}YEWAIDATA;

#define MIN_RADII		3				//不可大于任何野外的(宽/2)和(高/2)
#define MAX_YEWAIAREA	23
#define MAX_YEWAIWIDTH	10
#define MAX_YEWAIHEIGHT	10

DEFINEYEWAICREATEROOM(_Yewai1_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_1_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_2_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_3_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_4_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_5_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_6_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_7_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_8_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_9_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_10_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_11_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_12_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_13_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_14_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_15_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_16_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_17_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_18_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_19_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_20_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_21_CreateRoom);
DEFINEYEWAICREATEROOM(_18hell_22_CreateRoom);

static YEWAIDATA YeWaiData[MAX_YEWAIAREA] = 
{
	{_Yewai1_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_1_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_2_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_3_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_4_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_5_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_6_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_7_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_8_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_9_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_10_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_11_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_12_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_13_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_14_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_15_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_16_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_17_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_18_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_19_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_20_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_21_CreateRoom, 10, 10, 8, TRUE},
	{_18hell_22_CreateRoom, 10, 10, 8, TRUE}
};

static struct{UINT x; UINT y;}CunLuo[MAX_YEWAIAREA];
static UINT Area[MAX_YEWAIAREA][MAX_YEWAIHEIGHT][MAX_YEWAIWIDTH];

CRoom * _Yewai1_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CRcunzi_1();
			break;
		case 1:			//随机场景1
			return new CRshenlin_1();
			break;
		case 2:			//随机场景2
			return new CRshenlin_2();
			break;
		case 3:			//....
			return new CRshenlin_3();
			break;
		case 4:
			return new CRshenlin_4();
			break;
		case 5:
			return new CRshenlin_5();
			break;
		case 6:
			return new CRshenlin_6();
			break;
		case 7:
			return new CRshenlin_7();
			break;
		case 8:			//随机场景n
			return new CRshenlin_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_1_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_1();
			break;
		case 1:			//随机场景1
			return new CR18hell_1_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_1_2();
			break;
		case 3:			//....
			return new CR18hell_1_3();
			break;
		case 4:
			return new CR18hell_1_4();
			break;
		case 5:
			return new CR18hell_1_5();
			break;
		case 6:
			return new CR18hell_1_6();
			break;
		case 7:
			return new CR18hell_1_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_1_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_2_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_2();
			break;
		case 1:			//随机场景1
			return new CR18hell_2_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_2_2();
			break;
		case 3:			//....
			return new CR18hell_2_3();
			break;
		case 4:
			return new CR18hell_2_4();
			break;
		case 5:
			return new CR18hell_2_5();
			break;
		case 6:
			return new CR18hell_2_6();
			break;
		case 7:
			return new CR18hell_2_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_2_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_3_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_3();
			break;
		case 1:			//随机场景1
			return new CR18hell_3_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_3_2();
			break;
		case 3:			//....
			return new CR18hell_3_3();
			break;
		case 4:
			return new CR18hell_3_4();
			break;
		case 5:
			return new CR18hell_3_5();
			break;
		case 6:
			return new CR18hell_3_6();
			break;
		case 7:
			return new CR18hell_3_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_2_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_4_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_4();
			break;
		case 1:			//随机场景1
			return new CR18hell_4_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_4_2();
			break;
		case 3:			//....
			return new CR18hell_4_3();
			break;
		case 4:
			return new CR18hell_4_4();
			break;
		case 5:
			return new CR18hell_4_5();
			break;
		case 6:
			return new CR18hell_4_6();
			break;
		case 7:
			return new CR18hell_4_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_4_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_5_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_5();
			break;
		case 1:			//随机场景1
			return new CR18hell_5_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_5_2();
			break;
		case 3:			//....
			return new CR18hell_5_3();
			break;
		case 4:
			return new CR18hell_5_4();
			break;
		case 5:
			return new CR18hell_5_5();
			break;
		case 6:
			return new CR18hell_5_6();
			break;
		case 7:
			return new CR18hell_5_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_5_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_6_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_6();
			break;
		case 1:			//随机场景1
			return new CR18hell_6_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_6_2();
			break;
		case 3:			//....
			return new CR18hell_6_3();
			break;
		case 4:
			return new CR18hell_6_4();
			break;
		case 5:
			return new CR18hell_6_5();
			break;
		case 6:
			return new CR18hell_6_6();
			break;
		case 7:
			return new CR18hell_6_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_6_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_7_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_7();
			break;
		case 1:			//随机场景1
			return new CR18hell_7_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_7_2();
			break;
		case 3:			//....
			return new CR18hell_7_3();
			break;
		case 4:
			return new CR18hell_7_4();
			break;
		case 5:
			return new CR18hell_7_5();
			break;
		case 6:
			return new CR18hell_7_6();
			break;
		case 7:
			return new CR18hell_7_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_7_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_8_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_8();
			break;
		case 1:			//随机场景1
			return new CR18hell_8_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_8_2();
			break;
		case 3:			//....
			return new CR18hell_8_3();
			break;
		case 4:
			return new CR18hell_8_4();
			break;
		case 5:
			return new CR18hell_8_5();
			break;
		case 6:
			return new CR18hell_8_6();
			break;
		case 7:
			return new CR18hell_8_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_8_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_9_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_9();
			break;
		case 1:			//随机场景1
			return new CR18hell_9_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_9_2();
			break;
		case 3:			//....
			return new CR18hell_9_3();
			break;
		case 4:
			return new CR18hell_9_4();
			break;
		case 5:
			return new CR18hell_9_5();
			break;
		case 6:
			return new CR18hell_9_6();
			break;
		case 7:
			return new CR18hell_9_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_9_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_10_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_10();
			break;
		case 1:			//随机场景1
			return new CR18hell_10_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_10_2();
			break;
		case 3:			//....
			return new CR18hell_10_3();
			break;
		case 4:
			return new CR18hell_10_4();
			break;
		case 5:
			return new CR18hell_10_5();
			break;
		case 6:
			return new CR18hell_10_6();
			break;
		case 7:
			return new CR18hell_10_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_10_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_11_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_11();
			break;
		case 1:			//随机场景1
			return new CR18hell_11_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_11_2();
			break;
		case 3:			//....
			return new CR18hell_11_3();
			break;
		case 4:
			return new CR18hell_11_4();
			break;
		case 5:
			return new CR18hell_11_5();
			break;
		case 6:
			return new CR18hell_11_6();
			break;
		case 7:
			return new CR18hell_11_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_11_8();
			break;
	}

	return NULL;
}

CRoom * _18hell_12_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_12();
			break;
		case 1:			//随机场景1
			return new CR18hell_12_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_12_2();
			break;
		case 3:			//....
			return new CR18hell_12_3();
			break;
		case 4:
			return new CR18hell_12_4();
			break;
		case 5:
			return new CR18hell_12_5();
			break;
		case 6:
			return new CR18hell_12_6();
			break;
		case 7:
			return new CR18hell_12_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_12_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_13_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_13();
			break;
		case 1:			//随机场景1
			return new CR18hell_13_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_13_2();
			break;
		case 3:			//....
			return new CR18hell_13_3();
			break;
		case 4:
			return new CR18hell_13_4();
			break;
		case 5:
			return new CR18hell_13_5();
			break;
		case 6:
			return new CR18hell_13_6();
			break;
		case 7:
			return new CR18hell_13_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_13_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_14_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_14();
			break;
		case 1:			//随机场景1
			return new CR18hell_14_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_14_2();
			break;
		case 3:			//....
			return new CR18hell_14_3();
			break;
		case 4:
			return new CR18hell_14_4();
			break;
		case 5:
			return new CR18hell_14_5();
			break;
		case 6:
			return new CR18hell_14_6();
			break;
		case 7:
			return new CR18hell_14_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_14_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_15_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_15();
			break;
		case 1:			//随机场景1
			return new CR18hell_15_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_15_2();
			break;
		case 3:			//....
			return new CR18hell_15_3();
			break;
		case 4:
			return new CR18hell_15_4();
			break;
		case 5:
			return new CR18hell_15_5();
			break;
		case 6:
			return new CR18hell_15_6();
			break;
		case 7:
			return new CR18hell_15_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_15_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_16_CreateRoom(UINT n)		//野外1
{
	switch(n)
	{
		case 0:			//村落
			return new CR18hell_16();
			break;
		case 1:			//随机场景1
			return new CR18hell_16_1();
			break;
		case 2:			//随机场景2
			return new CR18hell_16_2();
			break;
		case 3:			//....
			return new CR18hell_16_3();
			break;
		case 4:
			return new CR18hell_16_4();
			break;
		case 5:
			return new CR18hell_16_5();
			break;
		case 6:
			return new CR18hell_16_6();
			break;
		case 7:
			return new CR18hell_16_7();
			break;
		case 8:			//随机场景n
			return new CR18hell_16_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_17_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_17();
			break;
		case 1:			
			return new CR18hell_17_1();
			break;
		case 2:			
			return new CR18hell_17_2();
			break;
		case 3:			
			return new CR18hell_17_3();
			break;
		case 4:
			return new CR18hell_17_4();
			break;
		case 5:
			return new CR18hell_17_5();
			break;
		case 6:
			return new CR18hell_17_6();
			break;
		case 7:
			return new CR18hell_17_7();
			break;
		case 8:	
			return new CR18hell_17_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_18_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_18();
			break;
		case 1:			
			return new CR18hell_18_1();
			break;
		case 2:			
			return new CR18hell_18_2();
			break;
		case 3:			
			return new CR18hell_18_3();
			break;
		case 4:
			return new CR18hell_18_4();
			break;
		case 5:
			return new CR18hell_18_5();
			break;
		case 6:
			return new CR18hell_18_6();
			break;
		case 7:
			return new CR18hell_18_7();
			break;
		case 8:	
			return new CR18hell_18_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_19_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_19();
			break;
		case 1:			
			return new CR18hell_19_1();
			break;
		case 2:			
			return new CR18hell_19_2();
			break;
		case 3:			
			return new CR18hell_19_3();
			break;
		case 4:
			return new CR18hell_19_4();
			break;
		case 5:
			return new CR18hell_19_5();
			break;
		case 6:
			return new CR18hell_19_6();
			break;
		case 7:
			return new CR18hell_19_7();
			break;
		case 8:	
			return new CR18hell_19_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_20_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_20();
			break;
		case 1:			
			return new CR18hell_20_1();
			break;
		case 2:			
			return new CR18hell_20_2();
			break;
		case 3:			
			return new CR18hell_20_3();
			break;
		case 4:
			return new CR18hell_20_4();
			break;
		case 5:
			return new CR18hell_20_5();
			break;
		case 6:
			return new CR18hell_20_6();
			break;
		case 7:
			return new CR18hell_20_7();
			break;
		case 8:	
			return new CR18hell_20_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_21_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_21();
			break;
		case 1:			
			return new CR18hell_21_1();
			break;
		case 2:			
			return new CR18hell_21_2();
			break;
		case 3:			
			return new CR18hell_21_3();
			break;
		case 4:
			return new CR18hell_21_4();
			break;
		case 5:
			return new CR18hell_21_5();
			break;
		case 6:
			return new CR18hell_21_6();
			break;
		case 7:
			return new CR18hell_21_7();
			break;
		case 8:	
			return new CR18hell_21_8();
			break;
	}
	return NULL;
}

CRoom * _18hell_22_CreateRoom(UINT n)
{
	switch(n)
	{
		case 0:			
			return new CR18hell_22();
			break;
		case 1:			
			return new CR18hell_22_1();
			break;
		case 2:			
			return new CR18hell_22_2();
			break;
		case 3:			
			return new CR18hell_22_3();
			break;
		case 4:
			return new CR18hell_22_4();
			break;
		case 5:
			return new CR18hell_22_5();
			break;
		case 6:
			return new CR18hell_22_6();
			break;
		case 7:
			return new CR18hell_22_7();
			break;
		case 8:	
			return new CR18hell_22_8();
			break;
	}
	return NULL;
}

BOOL _analyse_roomname(const char *name, UINT &n, UINT &x, UINT &y)
{
	const char *p = name + 4;
	char tmp[20];
	UINT m = 0, step = 0;
	
	if(name == NULL)return FALSE;

	for( ; ; p++)
	{
		if(*p >= '0' && *p <= '9')
		{
			tmp[m++] = *p;
		}
		else if(*p == '_' || *p == '\0')
		{
			tmp[m] = '\0';
			switch(step)
			{
				case 0:
					n = atoi(tmp);
					break;
				case 1:
					x = atoi(tmp);
					break;
				case 2:
					y = atoi(tmp);
					break;
			}
			step++;
			m = 0;
			if(*p == '\0')break;
		}
		else break;
	}

	if(step<3)
		return FALSE;
	else
		return TRUE;
}

char * _make_roomname(const char *name, UINT n, UINT x, UINT y)
{
	static char tmp[50];

	snprintf(tmp, 50, "%s%d_%d_%d", name, n, x, y);

	return tmp;
}

UINT QueryYeWaiArea(UINT n, UINT x, UINT y)
{
	static BOOL bInit = TRUE;
	int a;
	UINT i, j;


	if(bInit)
	{
		for(a = 0; a < MAX_YEWAIAREA; a++)
		{
			if(YeWaiData[a].nHeight > MAX_YEWAIHEIGHT || YeWaiData[a].nWidth > MAX_YEWAIWIDTH)
				return 0;			//察看是否越界
			
			for(i = 0; i < YeWaiData[a].nHeight; i++)
				for(j = 0; j < YeWaiData[a].nWidth; j++)
				{
					Area[a][i][j] = 1 + random(YeWaiData[a].nMaxRoom);
				}

			if(YeWaiData[a].bCunLuo)
			{
				CunLuo[a].y = random(YeWaiData[a].nHeight);
				CunLuo[a].x = random(YeWaiData[a].nWidth);
				Area[a][CunLuo[a].y][CunLuo[a].x] = 0;
			}
		}

		bInit = FALSE;
	}

	return Area[n][y][x];
}

CRoom * Load_Yewai(string room_name)
{
	CRoom * r = NULL;
	UINT n, x, y;

	//分析野外
	if(_analyse_roomname(room_name.c_str(), n, x, y))
	{
		if(n != 0 && n <= MAX_YEWAIAREA)
		{
			if(x < YeWaiData[n - 1].nWidth || y < YeWaiData[n - 1].nHeight)
			{
				UINT dx, dy;
				r = YeWaiData[n - 1].Func(QueryYeWaiArea(n - 1, x, y));
				r->set_name(room_name.c_str());

				if(x == 0)dx = YeWaiData[n - 1].nWidth - 1;
				else dx = x - 1;
				dy = y;
				r->add_door("迷宫西", _make_roomname(room_name.substr(0, 4).c_str(), n, dx, dy), "east");

				if(y == 0)dy = YeWaiData[n - 1].nHeight - 1;
				else dy = y - 1;
				dx = x;
				r->add_door("迷宫北", _make_roomname(room_name.substr(0, 4).c_str(), n, dx, dy), "south");

				if(x == YeWaiData[n - 1].nWidth - 1)dx = 0;
				else dx = x + 1;
				dy = y;
				r->add_door("迷宫东", _make_roomname(room_name.substr(0, 4).c_str(), n, dx, dy), "west");

				if(y == YeWaiData[n - 1].nHeight - 1)dy = 0;
				else dy = y + 1;
				dx = x;
				r->add_door("迷宫南", _make_roomname(room_name.substr(0, 4).c_str(), n, dx, dy), "north");
			}
		}
	}

	return r;
}

char * make_random_yewai(UINT n)
{
	UINT w, h;

	if(n == 0)return "";

	QueryYeWaiArea(n - 1, 0, 0);		//强迫初始化

	w = YeWaiData[n - 1].nWidth - MIN_RADII * 2;
	h = YeWaiData[n - 1].nHeight - MIN_RADII * 2;

	w = random(w);
	h = random(h);

	w = CunLuo[n - 1].x + MIN_RADII + w;
	h = CunLuo[n - 1].y + MIN_RADII + h;

	if(w >= YeWaiData[n - 1].nWidth)w -= YeWaiData[n - 1].nWidth;
	if(h >= YeWaiData[n - 1].nHeight)h -= YeWaiData[n - 1].nHeight;

	return _make_roomname("野外", n, w, h);
}

#undef MAX_YEWAIAREA
#undef MAX_YEWAIWIDTH
#undef MAX_YEWAIHEIGHT
