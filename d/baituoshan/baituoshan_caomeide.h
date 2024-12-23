//caomeide.h

//Sample for room: 白驼山草莓地
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_caomeide);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山草莓地");

	set("monster_chance", 1);
	CBox * box = Add_Box();
	box->add_object("caomei", 1);	
	box->set_name( "铁柜");	

	add_door("白驼山树林", "白驼山树林", "白驼山草莓地");

	set("long", "这里是一块草莓地，鲜红的草莓散落在绿草中，让人感到美妙惬意。");

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
