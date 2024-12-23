//jiuyang4.h

//Sample for ITEM: �������澭�����ľ�
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIjiuyang4);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�������澭�����ľ�");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ�������ľ��飬ֻ���Ͳ����ý��ܣ��䳤�ڲ���Գ��֮�У���ҳ��Ȼ�������������д�������������������֣���һ��Ҳ��ʶ�ã�������һ�����ı����о�����Щ���ģ���ÿһ��֮�䣬ȴ��ӬͷС��д�����й����֡�");
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