//haigang.h

//Sample for room: 塘沽口
//coded by zwb
//data: 2000-12-1

ROOM_BEGIN(CRBeiJing_haigang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "塘沽口");

	//add npcs into the room
	add_npc("pub_chuanfu");
	add_npc("pub_flowerg");
	add_npc("mingjiao_changjinpeng");
	add_npc("pub_shenjiqiu");
	add_npc("pub_zhangzhongding");
	
	add_door("北京大驿道9", "北京大驿道9", "北京塘沽口");
	add_door("神龙教海滩", "神龙教海滩", "北京塘沽口");
	
	set("long", "这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群海鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大船(chuan)，船上坐着几个渔夫打扮的人，乘船可渡过大海到达海的另一端。西面过天津城就是北京了，东面是一望无际的大海。" );


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
