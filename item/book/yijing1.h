//yijing1.h

//Sample for ITEM: ���׾�˵��ƪ��
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIyijing1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���׾�˵��ƪ��");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
 	set("long", "����һ���ñ���д�ɵ��顣���飺���׾�˵��ƪ������Ƥ���ƣ������Ѿ�����ܾ��ˡ�");
	set("value",  0l );
	set("material", "silk");
	set("skill/name","qimen_wuxing");	// name of the skill
//	set("skill/exp_required",  100000);	// minimum combat experience required
	set("skill/jing_cost",   25);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  50);	// the maximum level you can learn
	set("skill/min_skill", 25 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp