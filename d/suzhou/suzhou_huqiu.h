//huqiu.h

//Sample for room: 虎丘山
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_huqiu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "虎丘山");

	CBox * box = Add_Box();
	box->add_object("eluanshi", 1);	
	box->set_name( "铁柜");	

	add_npc("pub_luxiuwen");

	add_door("苏州青石官道2", "苏州青石官道2", "苏州虎丘山");
	add_door("苏州头门山", "苏州头门山", "苏州虎丘山");

	set("long", "虎丘山因其山形似蹲虎而得名。又相传吴王葬后，有白虎出现其墓上，故名虎丘。山前绝岩幽谷，花木繁茂，景色绮丽，后山空蒙宽广，石壁树立，气势雄浑。有“山藏寺里”的特色，被誉为“吴中第一名胜”。" );

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
