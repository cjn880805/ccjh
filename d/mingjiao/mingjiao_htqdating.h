//htqdating.h



//Sample for room: 厚土旗大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_htqdating);
virtual void create()			//Call it when Room Create
{
	set_name( "明教厚土旗大厅");

	add_npc("mingjiao_yanyuan");
	add_npc("pub_miaofeng");
	
	add_door("明教青石大道9", "明教青石大道9", "明教厚土旗大厅");

     

};

ROOM_END;
