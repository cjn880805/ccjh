//xiaodao3.h

//Sample for room: 小道3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXiaoYao_xiaodao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "逍遥林小道3");


	add_door("逍遥林小道2", "逍遥林小道2", "逍遥林小道3");
	add_door("逍遥林打铁屋", "逍遥林打铁屋", "逍遥林小道3");
	add_door("逍遥林酒家", "逍遥林酒家", "逍遥林小道3");
	add_door("逍遥林小屋", "逍遥林小屋", "逍遥林小道3");


};


ROOM_END;
