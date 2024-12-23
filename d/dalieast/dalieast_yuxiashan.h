//yuxiashan.h

//Sample for room: 大理城玉霞山
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_yuxiashan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城玉霞山");

	//add npcs into the room
	add_npc("pub_youke2");

	CBox * box = Add_Box();
	if(!random(5))
		box->add_object("wangqing_shi", 1);	//put 100 coind into box
	else
	{
		box->add_object("sword_3",1);
	}
	box->set_name("石洞", "hole");
	box->Locked("封闭", 10000);

	
	add_door("大理城星云湖畔", "大理城星云湖畔", "大理城玉霞山");

	set("long", "玉霞山东镇星云湖，山清林秀，许多游人来此欣赏湖光山色，无不为之倾倒。古人有诗曰：玉霞凄清秋气凉，星云湖水澄明光，近屿含烟凝紫翠，远山峭壁摩青苍，水光山色相辉映， 万里无云碧天净。" );

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
