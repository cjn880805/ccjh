//hcazhaitang.h

//Sample for room:  峨嵋华藏庵斋堂
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_hcazhaitang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋华藏庵斋堂");


	CBox * box = Add_Box();
	box->add_object("qingshui_hulu", 2);	
	box->set_name( "铁柜");
	
	add_npc("emei_feng");

	add_door("峨嵋华藏庵东廊2", "峨嵋华藏庵东廊2", "峨嵋华藏庵斋堂");
	add_door("峨嵋华藏庵大雄宝殿", "峨嵋华藏庵大雄宝殿", "峨嵋华藏庵斋堂");

	set("long","这里便是峨嵋华藏庵的斋堂。斋堂里摆满了长长的餐桌和长凳，几位小师太正来回忙碌着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。斋堂后面有一道门通往华藏庵储物间，北边的走廊通向广场。");
    
    set("sleep_room", 1);

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
