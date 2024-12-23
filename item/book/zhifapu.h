//zhifapu.h

//Sample for ITEM: һ��ָ����
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIzhifapu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "һ��ָ����");	//set item name

 	set_weight(1000);		//set item weight

	set("unit", "��");
 	set("long", "����һ��д��˿�ϵ��飬��������һλ������ʿ������ָָ����յı�Ӱ��");
	set("value",  0l );
	set("material", "silk");
	set("skill/name","sun_finger");	// name of the skill
	set("skill/exp_required",  150000);	// minimum combat experience required
	set("skill/jing_cost",   35);	// jing cost every time study this
	set("skill/difficulty", 25 );	// the base int to learn this skill
	set("skill/max_skill",  150);	// the maximum level you can learn
	set("skill/min_skill", 0l );  // the maximum level you can learn   
 
	set("no_give", "�����������������ˡ�");
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp