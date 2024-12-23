//beijingcity.h

//Sample for room:  北京皇城
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRbeijingcity);


virtual void create()			
{
	set_name( "北京皇城");

	add_npc("pub_kunlunnu");
	add_npc("pub_boy");
	add_npc("pub_xiaoguizi");
	add_npc("pub_shamurai");
	add_npc("pub_hai");
	add_npc("helpnpc008");

	add_door("北京东南", "北京东南", "北京皇城");
	add_door("北京西南", "北京西南", "北京皇城");
	add_door("北京大驿道5", "北京大驿道5", "北京皇城");
	
	add_door("北京当铺", "北京当铺", "北京皇城");
	add_door("北京客店1", "北京客店1", "北京皇城");
	add_door("北京屠宰场", "北京屠宰场", "北京皇城");
	add_door("北京高升茶馆", "北京高升茶馆", "北京皇城");

};


ROOM_END;
