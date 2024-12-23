//lengsl2.h
//Sample for room:  峨嵋冷杉林2
//coded by zouwenbin
//data: 2000-11-30
ROOM_BEGIN(CREMei_lengsl2);
virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋冷杉林2");
	add_npc("pub_flowerg");               // add by zdn 2001-07-14
	add_door("峨嵋八十四盘1", "峨嵋八十四盘1", "峨嵋冷杉林2");
	add_door("峨嵋冷杉林3", "峨嵋冷杉林3", "峨嵋冷杉林2");
	set("long","这是一片遮天蔽日的冷杉林。数人也合抱不过来的冷杉树簇在一块，棵棵枝繁叶茂，象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。看地上厚厚的枯枝烂叶，显然游客很少踏足此处。");

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
