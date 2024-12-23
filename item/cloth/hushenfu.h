//hushenfu.h
//Lanwood 2001-03-10
//护身符，装备上可以不被随机妖怪骚扰

EQUIP_BEGIN(CIhushenfu);

virtual void create(int nFlag = 0)
{
	char msg[80], str[20];
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(500);		//set item weight
   
	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	
	set("index", level);

	set_name( snprintf(msg, 80, "%s级护身符", chinese_number(level, str)));	//set item name
	set("long", snprintf(msg, 80, "用来防妖的护身符。可以吓退%s级以下怪物。", str));
	set("value", 5000 + level * 400);
	
	set("apply/armor", 0l);
	set("apply/protect", level);
	set("wear_msg", "$N轻轻地把$n戴在颈上。");
	set("unequip_msg", "$N轻轻地把$n从颈上摘了下来。");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp