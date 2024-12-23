//jiuyang4.h

//Sample for ITEM: 「九阳真经」第四卷
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIjiuyang4);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "「九阳真经」第四卷");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "本");
	set("long", "这是一本薄薄的经书，只因油布包得紧密，虽长期藏在猿腹之中，书页仍然完好无损。书面上写著几个弯弯曲曲的文字，他一个也不识得，翻开来一看，四本书中尽是这些怪文，但每一行之间，却以蝇头小楷写满了中国文字。");
	set("value",   0l);
	set("material", "paper");
	set("skill/name","jiuyang_shengong");	// name of the skill
	set("skill/exp_required",  2000);	// minimum combat experience required
	set("skill/jing_cost",   40);	// jing cost every time study this
	set("skill/difficulty",  30);	// the base int to learn this skill
	set("skill/max_skill",  100);	// the maximum level you can learn
	set("skill/min_skill",  75);  // the maximum level you can learn

 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp