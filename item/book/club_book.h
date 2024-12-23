//parry_book.h

//Sample for ITEM: �м�����
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIclub_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name

 	set_weight(200);		//set item weight

	set("unit", "��");
 	set("long", "�Ȿ�����������д�������ǽ��������Ǽ��ص�ȴ�ǹ�����");
	set("value",  15000 );
	set("material", "paper");
	set("skill/name","club");	// name of the skill
	set("skill/exp_required", 1 );	// minimum combat experience required
	set("skill/jing_cost",   10+random(10));	// jing cost every time study this
	set("skill/difficulty", 10 );	// the base int to learn this skill
	set("skill/max_skill", 100 );	// the maximum level you can learn
	set("skill/min_skill", 25 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp