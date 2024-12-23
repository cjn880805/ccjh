//book2.h

//Sample for ITEM: ����Ƭ
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbook2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����Ƭ");	//set item name

 	set_weight(100);		//set item weight

	set("unit", "Ƭ");
	set("long", "�׽�Ṧƪ:����һƬ����ȥƤ�ľ���Ƭ������ͱ��涼����������������Ծ��Сͼ�Ρ�");
	set("value", 500);
	set("material", "bamboo");
	set("skill/name","dodge");	// name of the skill
	set("skill/exp_required",0l);	// minimum combat experience required
	set("skill/jing_cost",10);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",29);	// the maximum level you can learn
	set("skill/min_skill",0l);  // the maximum level you can learn


};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp