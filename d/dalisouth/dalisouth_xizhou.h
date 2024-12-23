//xizhou.h

//Sample for room: 喜州城
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_xizhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "喜州城");

	set("resident", "喜州");

	//add npcs into the room
	add_npc("pub_keshang");
	add_npc("dali_keshang");       //add by zdn 2001-07-20
	
	add_door("大理城客店", "大理城客店", "大理城喜州城");
	add_door("大理城天威径", "大理城天威径", "大理城喜州城");
	add_door("大理城竹林小路", "大理城竹林小路", "大理城喜州城");
	add_door("大理城妃丽湖畔", "大理城妃丽湖畔", "大理城喜州城");

	set("long", "喜州又名大鳖城，是大理南部大城，自唐代已极繁荣，邑居人户尤众，商贸甚繁荣，有大量他国客商来此交易，采购大理产的金银、丝织品、象牙、皮毛等，其中又以来自印度的客商最多，前来贩丝绸往波斯甚至更远的西方。" );
};


RESIDENT_END;
