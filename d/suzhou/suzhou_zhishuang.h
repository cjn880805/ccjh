//zhishuang.h

//Sample for room: 致爽阁
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_zhishuang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "致爽阁");
	
	add_npc("pub_jianke");
	add_npc("pub_youke");        //add by zdn 2001-07-15


	add_door("苏州千人石", "苏州千人石", "苏州致爽阁");

	set("long", "在千人石西面就是致爽阁，又名伏虎阁，在虎丘塔的西南面，是山上的最高点。阁名取“四山爽气，日夕西来”之意。旧称“小五台”，是海涌峰顶。阁外平台宽，俯瞰沃野；远眺群峰逶迤，可赏著名上午“狮子回头看虎丘”一景。深秋季节观成群飞翔的苍鹰，蔚为壮观。" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
