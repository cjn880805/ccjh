//laozi8.h

//Sample for ITEM: 道德经「第八章」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlaozi8);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "道德经「第八章」");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
	set("long", "第八章:上善若水。水善利万物而不争，处众人之所恶，故几于道。居善地，心善渊，与善仁，言善信，政善治，事善能，动善时。夫唯不争，故无尤。");
	set("value",   500);
	set("material", "paper");
	set("skill/name","taoism");	// name of the skill
	set("skill/exp_required",  0l);	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty",  15);	// the base int to learn this skill
	set("skill/max_skill",  29);	// the maximum level you can learn
	set("skill/min_skill",  0l);  // the maximum level you can learn
   

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp