//18muou.h

//Sample for ITEM: ʮ��ľż
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CI18muou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ʮ��ľż");	//set item name

	set_weight(600);		//set item weight

	set("unit", "��");
	set("long", "����һ��Сľ�У����е����޻�������������ľż�������ϲ�ò�������ʹ�����ᣬ�������ŭ����ȺͿ��ף���һ��ͬ��");
	set("value", 5000);
	set("material", "wood");
	set("skill/name","force");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",40);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",99);	// the maximum level you can learn
	set("skill/min_skill",60);  // the maximum level you can learn

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp