//bagua0.h

//Sample for ITEM: 「河图」
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbagua0);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "「河图」");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "本");
	set("long", "这是一本用薄绢写成的书。上书二字古篆：“河图”。书皮泛黄，看来已经保存很久了。扉页上似乎写着，山海经有言：“伏羲氏得河图，夏后因之，曰《连山》。”此书乃上古遗书《三坟》之一。");
	set("value", 0l);
/*	set("material", "silk");
	set("skill/name","count");	// name of the skill
	set("skill/jing_cost",25);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",69);	// the maximum level you can learn
	set("skill/min_skill",40);  // the maximum level you can learn
*/
 };

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp