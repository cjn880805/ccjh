//sheyuan.h

//Sample for room: 蛇园
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_sheyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "蛇园");

	//add npcs into the room
	add_npc("animal_jinshe");/////////////////////////
	add_npc("animal_dushe");
	add_npc("animal_fushe");
	add_npc("animal_qingshe");
	add_npc("animal_wubushe");

	add_door("白驼山兔苑", "白驼山兔苑", "白驼山蛇园");

	set("long", "这里是白驼山庄的蛇园。白驼山以毒名扬天下，最重要的毒质就来自毒蛇。这里遍地是蛇，墙上也巴着蛇，屋檐上也向下垂着蛇，树枝上也盘绕着蛇，不由你不心惊");  

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
