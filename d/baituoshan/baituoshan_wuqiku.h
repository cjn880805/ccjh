//wuqiku.h

//Sample for room: 武器库
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_wuqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武器库");

	//add npcs into the room
	add_npc("pub_shiwei");

	CBox * box = Add_Box();
	box->add_object("shezhang", 1);	
	box->set_name( "木柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("gangzhang", 3);	
	box1->set_name( "木柜");	
	
	add_door("白驼山院子", "白驼山院子", "白驼山武器库");

	set("long", "这里是『白驼山』弟子的武器库，『白驼山』弟子可以到此拿取练功用的各种武器。不过别派弟子是不允许进来的。");  

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
