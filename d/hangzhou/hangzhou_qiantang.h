//qiantang.h

//Sample for room: 杭州钱塘江畔
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_qiantang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州钱塘江畔");

	//add npcs into the room
	add_npc("pub_jianke");
	
	add_door("杭州六和塔", "杭州六和塔", "杭州钱塘江畔");
	add_door("杭州青石大道17", "杭州青石大道17", "杭州钱塘江畔");

	set("long"," 钱塘江，每年八月十八是观潮的好日子。“八月十八潮，壮观天下无”。潮水来时“远若素练横江，声如金鼓；近则亘如山岳，奋如雷霆”，刹那间，漫江沸腾，泼涛万顷，潮高丈馀，万马奔腾，真有“涛来势转雄，猎猎驾长风。雷震云霓里，山飞霜雪中”的壮丽气势。西上月轮山便到了六和塔。");

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
