//pinganfu.h
//sound 2001-12-10
//平安符，装备上可以不被随机妖怪骚扰

EQUIP_BEGIN(CIpinganfu);

virtual void create(int nFlag = 0)
{
	char msg[80], str[20];
	set("wield_position", WIELD_NECK);		//set the position of wield
 	set_weight(5000);		//set item weight
   
	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	
	set("index", level);

	set_name( snprintf(msg, 80, "%s级平安符", chinese_number(level, str)));	//set item name
	set("long", "在地狱里保平安的平安符。可以减少被陷阱伤害的几率。");
	set("value", 5000 + level * 400);
	
	set("apply/armor", 0l);
	set("apply/safety", level);
	set("wear_msg", "$N轻轻地把$n戴在颈上。");
	set("unequip_msg", "$N轻轻地把$n从颈上摘了下来。");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp