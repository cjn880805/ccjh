//daodian.h

//Sample for room: 刀店
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_daodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "刀店");

	//add npcs into the room
	add_npc("pub_daodianhuoji");/////////////////////////

	add_door("灵州西", "灵州西", "灵州刀店");

	set("long", "这是一家以卖西域特产“英吉儿”小刀出名的兵器铺，上百把各式各样的“英吉儿”小刀整整齐齐的摆放在柜台上，说是小刀却尺寸型制大不相同，既有长仅一寸的柳叶飞刀、也有长达三尺的阿拉伯弯刀。最多的还是长六寸，宽三分，背厚一黍，刃薄如纸的匕首柜台后面的墙上也挂着些长剑，钢刀，铁杖等中原兵器。");  

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
