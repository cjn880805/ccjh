//bingqiku.h

//Sample for room: 兵器房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_bingqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "兵器房");

	add_npc("pub_shiwei");   //add by zdn 2001-07-12 

	CBox * box = Add_Box();
	box->add_object("gangjian", 1);	
	box->set_name( "木柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("changbian", 1);	
	box1->set_name( "木柜");		

	add_door("大理城王府大厅", "大理城王府大厅", "大理城王府兵器房");

	set("long", "这里是镇南王府的兵器房，四周放这几个兵器架，上面是王府家人弟子平时练剑用的竹剑。" );
	set("no_fight", 1);

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
