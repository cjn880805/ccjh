//bagua1.h

//Sample for ITEM: �����项
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbagua1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����ԡ�");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ���ñ���д�ɵ��顣������ֹ�׭�������ԡ��������װ�����������Ի��������֮˵��ν֮����������������Ҳ�����������Ϲ����顶���ء�֮һ��");
	set("value", 0l);
/*	set("material", "silk");
	set("skill/name","count");	// name of the skill
	set("skill/jing_cost",40);	// jing cost every time study this
	set("skill/difficulty",30);	// the base int to learn this skill
	set("skill/max_skill",149);	// the maximum level you can learn
	set("skill/min_skill",100);  // the maximum level you can learn
*/
 };

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp