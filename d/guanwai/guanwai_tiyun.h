//tiyun.h

//Sample for room: 梯云峰
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuanWai_tiyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "关外梯云峰");
	
	add_npc("pub_jianke");   // add by zdn 2001-07-13

	set("monster_chance", 50);

	CBox * box = Add_Box();
	if(! random(10))
		box->add_object("qinghong", 1);	//put 100 coind into box
	else
		box->add_object("coin",1);	// Put 1 coin into box :ppp
	box->set_name( "石洞", "hole");
	box->Locked("封闭", 60000);

	add_door("关外玉柱峰", "关外玉柱峰", "关外梯云峰");

    set("long","玉柱峰北，有一山峰，峰脊出梯河瀑布，远望如腾白如云，纵列如梯，故名梯云峰。" );
    

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
