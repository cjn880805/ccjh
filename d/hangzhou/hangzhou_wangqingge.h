//wangqingge.h
//Sample for room: 杭州忘情阁

ROOM_BEGIN(CRhangzhou_wangqingge);

virtual void create()			
{
	set_name( "忘情阁");

	add_npc("wei_jhlz");
	add_npc("wei_jhlz");
	add_npc("wei_mujianping");

	add_door("杭州茅家埠", "杭州茅家埠", "杭州忘情阁");

};

ROOM_END;
