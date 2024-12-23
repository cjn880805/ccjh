//laozi16.h

//Sample for ITEM: 道德经「第十六章」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlaozi16);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "道德经「第十六章」");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
	set("long", "第十六章:致虚极，守静笃。万物并作，吾以观复。夫物芸芸，各复归其根。归根曰静，静曰复命。复命曰常，知常曰明。不知常，妄作凶。知常容，容乃公，公乃全，全乃天，天乃道，道乃久，没身不殆。");
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