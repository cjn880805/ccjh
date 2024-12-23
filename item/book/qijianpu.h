//qijianpu.h

//Sample for ITEM: �����潣����
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqijianpu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����潣����");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "��");
 	set("long", "����һ�������潣���ף����滭��һЩ�׷����ӵ���ʽ���������š�");
	set("value",  500 );
	set("material", "paper");
	set("skill/name","tianyu_qijian");	// name of the skill
	set("skill/exp_required",  100000);	// minimum combat experience required
	set("skill/jing_cost",   30 );	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  150);	// the maximum level you can learn
	set("skill/min_skill", 50 );  // the maximum level you can learn   

	set("no_put", 1);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp