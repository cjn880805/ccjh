//feilihueast.h

//Sample for room: 妃丽湖东
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_feilihueast);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "妃丽湖东");

	set("resident", "喜州");

	add_npc("pub_youke");
	add_npc("pub_flowerg");    //add by zdn 2001-07-13

	add_door("大理城龙口城", "大理城龙口城", "大理城妃丽湖东");
	add_door("大理城河西镇", "大理城河西镇", "大理城妃丽湖东");
	add_door("大理城妃丽湖畔", "大理城妃丽湖畔", "大理城妃丽湖东");

	set("long", "你站在妃丽湖的东岸，脚下的土路绕湖东连接南北的村镇。眺望湖中只见轻舟点点，正是捕鱼的台夷竹筏。路边尽是青青竹林，台夷的竹楼间或出现。向西南去的岔路通往湖西的休猎部，正路向南直达龙口城。" );
};


RESIDENT_END;
