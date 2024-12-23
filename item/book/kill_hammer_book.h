ITEM_BEGIN(CIkill_hammer_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "《城市猎人》");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "本");
 	set("long", "这是一本由武林前辈旺财画的漫画书");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","kill_hammer");	// name of the skill
	set("skill/exp_required",  1000);	// minimum combat experience required
	set("skill/jing_cost",   30);	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  100);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp