//bagua0.h

//Sample for ITEM: ����ͼ��
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIbagua0);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ͼ��");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ���ñ���д�ɵ��顣������ֹ�׭������ͼ������Ƥ���ƣ������Ѿ�����ܾ��ˡ���ҳ���ƺ�д�ţ�ɽ�������ԣ��������ϵú�ͼ���ĺ���֮��Ի����ɽ�������������Ϲ����顶���ء�֮һ��");
	set("value", 0l);
/*	set("material", "silk");
	set("skill/name","count");	// name of the skill
	set("skill/jing_cost",25);	// jing cost every time study this
	set("skill/difficulty",20);	// the base int to learn this skill
	set("skill/max_skill",69);	// the maximum level you can learn
	set("skill/min_skill",40);  // the maximum level you can learn
*/
 };

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp