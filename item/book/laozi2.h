//laozi2.h

//Sample for ITEM: 道德经「第二章」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIlaozi2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "道德经「第二章」");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "本");
	set("long", "第二章:天下皆知美之为美，斯恶已。皆知善之为善，斯不善已。有无相生，难易相成，长短相形，高下相盈，音声相和，前后相随。恒也。是以圣人处无为之事，行不言之教；万物作而弗始，生而弗有，为而弗恃，功成而不居。夫唯弗居，是以不去。");
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