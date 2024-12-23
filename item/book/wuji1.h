//wuji1.h

//Sample for ITEM: titles[i]
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIwuji1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char titles[6][20] = {
		"风云手手法",
		"如来千叶手手法",
		"大金刚拳法",
		"罗汉拳法",
		"般若掌法",
		"散花掌法",
	};

	char skills[6][20] = {
		"fengyun_shou",
		"qianye_shou",
		"jingang_quan",
		"luohan_quan",
		"banruo_zhang",
		"sanhua_zhang",
	};

	int lvl = random(6);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);
	
	char msg[255];

	set_name( titles[lvl]);	     //set item name

	set_weight(200);		//set item weight

	set("unit", "册");
	snprintf(msg, 255, "这是一册%s", titles[lvl]);
 	set("long", msg );
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