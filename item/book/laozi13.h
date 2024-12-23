//laozi13.h

//Sample for ITEM: 道德经「第十三章」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlaozi13);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "道德经「第十三章」");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
	set("long", "第十三章:宠辱若惊，贵大患若身。何谓宠辱若惊？宠为下，得之若惊，失之若惊，是谓宠辱若惊。何谓贵大患若身？吾所以有大患者，为吾有身，及吾无身，吾有何患？故贵以身为天下，若可寄天下；爱以身为天下，若可托天下。");
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