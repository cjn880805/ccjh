//wuji2.h

//Sample for ITEM: titles[i]
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIwuji2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char titles[6][10] = {
		"龙爪功法",
		"鹰爪功法",
		"拈花指法",
		"一指禅功",
		"慈悲刀法",
		"修罗刀法",
	};

	char skills[6][20] = {
		"longzhua_gong",
		"yingzhua_gong",
		"nianhua_zhi",
		"yizhi_chan",
		"cibei_dao",
		"xiuluo_dao",
	};

	int lvl = random(6);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

	char msg[255];

	set_name( titles[lvl]);	//set item name

 	set_weight(200);		//set item weight

	set("unit", "册");
	snprintf(msg, 255, "这是一册%s", titles[lvl]);
 	set("long", msg);
	set("value",  500 );
	set("material", "paper");
	set("skill/name",skills[lvl]);	// name of the skill
	set("skill/exp_required",  10000);	// minimum combat experience required
	set("skill/jing_cost",   15+random(30));	// jing cost every time study this
	set("skill/difficulty", 25 );	// the base int to learn this skill
	set("skill/max_skill",  99);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp