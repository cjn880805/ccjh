//cangshan.h

//Sample for room: 大理城苍山
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_cangshan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城苍山");

	set("resident", "下关城");

	add_npc("pub_youke");
	add_npc("pub_playboy");  //add by zdn 2001-07-13

	add_door("大理城下关城", "大理城下关城", "大理城苍山");
	add_door("大理城宏圣寺塔", "大理城宏圣寺塔", "大理城苍山");
	add_door("大理城路南石林", "大理城路南石林", "大理城苍山");

	set("long", "苍山之腹盛产奇石，世称大理石，又名点苍石、文石、础石。石质细腻，色彩丰富，有彩花、水墨、银灰、雪白等品种。水墨最为稀有，彩花独具特点，常用于作屏风观赏，有云树山川、人物鸟兽之形，姿态万千，浑朴天成，为世所宝。银灰石是精美的建筑材料，用于贴墙铺地，光润冰亮，气若云水，消暑生凉。雪花石又名点苍白玉，晶莹可爱，白如截脂，是雕刻、绘画的好材料。石本以产于大理而得名，而今天下凡此种花石皆称大理石，“大理”也因此石而名扬天下。");
	
};


RESIDENT_END;
