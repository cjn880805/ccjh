//tianhuo.h

//Sample for room: 天豁峰
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_tianhuo);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天豁峰");

	add_npc("guiyun_wanyankang"); 
	add_npc("guiyun_wanyanhonglie"); 
	add_npc("guiyun_jinbing");
	add_npc("guiyun_jinbing");       // add by zdn 2001-07-20

	set("monster_chance", 50);

	add_door("关外龙门峰", "关外龙门峰", "关外天豁峰");
	add_door("关外华盖峰", "关外华盖峰", "关外天豁峰");

	set("long","乘槎河东岸，与龙门峰对峙。峰顶如鹰嘴般的峻峭山峰破石而出，伸向天池，故又名鹰嘴峰。古书载：“峰起双尖，中辟一线，有豁然开朗、令人不可思议之趣”，相传为大禹治水所劈，石多赤色，犹如二龙蟠踞，妙趣横生。" );
    

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
