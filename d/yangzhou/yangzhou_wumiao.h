//wumiao.h

//Sample for room: 武庙
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_wumiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武庙");


				
	CBox * box = Add_Box();
	box->add_object("coin", 100);	//put 100 coind into box
	box->set_name( "铁柜");	
	
	add_door("扬州西北", "扬州西北", "扬州武庙");

	set("long", "这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭毕敬地上香礼拜。旁边似乎有一道侧门。(paizi)，柜台后坐着唐老板，一双精明的上上下下打量着你。据街坊们说铁面当铺给的价还不算最坏，并且从不问货的来处，除了活人什么都收，所以生意很不错。" );
	set("no_fight", "1");
	set("no_steal", "1");
	set("sleep_room", "1");
    set("valid_startroom","1");
/*****************************************************
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"up"   : __DIR__"wumiao2",
		"northwest": "/d/wizard/guest_room",
	]));
        create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
********************************************/
};


ROOM_END;
