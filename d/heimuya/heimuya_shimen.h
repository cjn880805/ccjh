//shimen.h

//Sample for room: 黑木崖石门
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shimen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖石门");

        add_npc("heimuya_zishan");          //add by zdn 2001-07-14


	add_door("黑木崖石阶", "黑木崖石阶", "黑木崖石门");
	add_door("黑木崖日月坪", "黑木崖日月坪", "黑木崖石门");

};


ROOM_END;
