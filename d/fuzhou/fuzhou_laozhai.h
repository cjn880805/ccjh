//laozhai.h

//Sample for room: 向阳老宅
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_laozhai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "向阳老宅");

	add_npc("pub_boy");    // add by zdn 2001-07-13

	add_door("福州南", "福州南", "福州向阳老宅");
	CBox * box = Add_Box();
	box->add_object("pixie_sword_book", 1);	
	box->set_name( "木盒");
	set("long", "这里是福威镖局总镖头林震南在福建的旧居。室内的家具横七竖八地倒在地上。房间的一角结着一张蜘蛛网，屋里到处是尘土，显然是已经很久没有人住了。房间的尽头有一扇门(men)，但已被坍塌的砖瓦挡住了。" );
	
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
