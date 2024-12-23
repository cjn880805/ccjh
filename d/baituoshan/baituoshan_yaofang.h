//yaofang.h

//Sample for room: 药房
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_yaofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "药房");

	//add npcs into the room
	add_npc("pub_xiaoqing");

	CBox * box = Add_Box();
	box->add_object("baiyunwan", 1);	
	box->set_name( "铁柜");	
	
	add_door("白驼山长廊", "白驼山长廊", "白驼山药房");

	set("long", "这里是间药房，靠墙放着一只大药柜。屋子里有张桌子，上边摆满了炼药用的瓶瓶罐罐。其中一个药瓶(bottle)里只装了清水。炼药师是位小姑娘,正在那里发呆，不知在想什么。北面是气派的长廊。");  

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
