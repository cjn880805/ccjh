//laozi1.h

//Sample for ITEM: 道德经「第一章」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlaozi1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "道德经「第一章」");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
	set("long", "第一章:道可道，非常道。名可名，非常名。无名天地之始；有名万物之母。故常无，欲以观其妙；常有，欲以观其徼。此两者，同出而异名，同谓之玄。玄之又玄，众妙之门。");
	set("value", 500);
	set("material", "paper");
	set("skill/name","taoism");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",10);	// jing cost every time study this
	set("skill/difficulty",15);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn

 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp