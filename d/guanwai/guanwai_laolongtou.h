//laolongtou.h

//Sample for room: 老龙头
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_laolongtou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "老龙头");

	set("resident", "山海关");

	//add npcs into the room
	add_npc("pub_fengxifan");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_bing");
	add_npc("pub_wujiang");
	
	add_door("关外军营", "关外军营", "关外老龙头");
	add_door("关外山海关", "关外山海关", "关外老龙头");
	add_door("北京大驿道3", "北京大驿道3", "关外老龙头");

    set("long","老龙头是万里长城最东端。澄海楼巍峨高踞城头，楼上“雄襟万里”的横匾居高临下，直俯大海。自澄海楼筑有一石城逐级而下伸入大海，站在石城终端楼平台上四眺，海天一色，无边无际，气象万千。" );
	
};

int valid_leave(CChar * me, const char * dir)
{
	if(EQUALSTR(dir,"关外军营") )
	{
		if(!me->query_temp("zhang/冯力强"))
		{
			return notify_fail("$HIR众兵齐声大喝：“你是何人，军营重地是你可以乱闯的地方？”");
		}
	}
	return CRoom::valid_leave(me, dir);
}

RESIDENT_END;
