//heifengkou.h

//Sample for room: 黑风口
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_heifengkou);

virtual void create()			
{
	set_name( "黑风口");

	set("monster_chance", 50);

    add_npc("guanwai_jiaowenqi"); 
	add_npc("pub_fengwuchang");
	
	add_door("关外密林2", "关外密林2", "关外黑风口");
	add_door("关外小天池", "关外小天池", "关外黑风口");

	set("long","这里是密林中的险恶之境周围是为茂密的松林，不见天光。林中传来野兽饥饿之极的嘶吼。四处有不知名的草菰和野果，可你一点也不敢尝尝。林木幽暗深邃，似乎暗藏杀机。你到了此处，心胆俱裂，只想快点离开。" );

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
