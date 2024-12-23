//xuanhebao.h

//Sample for room: 灵州宣和堡
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_xuanhebao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵州宣和堡");
	
	add_npc("pub_youke"); 
	add_npc("pub_caodongyun");
//	add_npc("lingzhou_helianchunshui");    //add by zdn 2001-07-14


	add_door("灵州鸣沙洲", "灵州鸣沙洲", "灵州宣和堡");
	add_door("黄河", "黄河", "灵州宣和堡");

};


ROOM_END;




