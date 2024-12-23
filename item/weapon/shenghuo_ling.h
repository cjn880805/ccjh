//shenghuo_ling.h

//Sample for ITEM: ʥ����
//coded by Fisho
//data: 2000-10-30

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshenghuo_ling);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("ʥ����", "shenghuo ling");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("unit", "��");
 	set("long", "����һ�����������ĺ��ƣ��ǽ�������ʵؼ�Ӳ�ޱȣ���͸���������������л�����ڣ�ʵ��������ӳ�⣬��ɫ��á����Ͽ̵��в��ٲ�˹���֡�");
	set("value",  2000 );
	set("material", "steel");
	set("skill_type", "lingfa");			//set the skill applied
	set("skill/name","shenghuo_lingfa");	// name of the skill
	set("skill/exp_required",  50000);	// minimum combat experience required
	set("skill/jing_cost",   40);	// jing cost every time study this
	set("skill/difficulty", 30 );	// the base int to learn this skill
	set("skill/max_skill",  200);	// the maximum level you can learn
	set("skill/min_skill", 100 );  // the maximum level you can learn   

	set("wield_msg",  "$N��ৡ���һ������������һƬ����������������С�");
    set("unwield_msg",  "$N��ʥ���������䡣" );
//    init_sword(50);
 	set("apply/damage", 50);					//set the modifiers of attribute
   
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp