//qinpu.h

//Sample for ITEM: ��ʯ��
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqinpu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ʯ��");	//set item name

	set_weight(600);		//set item weight

	set("unit", "��");
 	set("long", "����һ�����ף�����Ŷ��ţ��ƺ����Դ����淢��һЩ�����Ķ�����ԭ������һ�����Ž��������ס� ");
	set("value",  1000 );
	set("material", "paper");
	set("skill/name","wuyun_jianfa");	// name of the skill
	set("skill/exp_required",  100);	// minimum combat experience required
	set("skill/jing_cost",   10);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  80);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp