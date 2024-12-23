//kedian.h

//Sample for room: 锦城驿
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRChengDu_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "锦城驿");

	add_npc("pub_xiaoer2");   //zdn 2001-07-12 add

	add_npc("pub_baixiaosheng");
	CContainer * env = load_room("pk");
	if(env->query("活动")==1)
		add_npc("wiz_109");
	else if(env->query("活动")==2)
		add_npc("wiz_teacher2");

	add_door("成都东", "成都东", "成都锦城驿");
	add_door("成都锦城驿二楼", "成都锦城驿二楼", "成都锦城驿");

	set("long",	"锦城驿是全西南最大的客店，生意非常兴隆。外地游客多选择这里落脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，沉重的川味官话你是实在听不顺耳。这是成都督府官办的客栈，接待着各地入川的官差浪人。墙上挂着一个牌子(paizi)。"	);
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("sleep_room",1);


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




