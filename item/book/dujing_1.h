//dujing_1.h

//Sample for ITEM: �����޶������ϲ᡽��
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIdujing_1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����޶������ϲ᡽��");	//set item name

 	set_weight(10);		//set item weight

	set("unit", "��");
	set("long", "�����޶������ϲ᡽��:��������Ϊ���ޱ��䣬���Դ˾�����������ҩ��˽�����ˣ�����Ϊ��ʦ���桢����ʦ�š�����ʦ֮ͽ����������أ�����ӱ�����֮�����˳��б����ߣ�����Ӽ�һ��ɱһ������ʮ��ɱʮ�����ϲ���˽�ı��ű����߹��������������������������������������������������������������������ɡ���      ���ɺ�ҩ�����÷�����ҩ�����ˮ�����˺��£�pour yao in <����>������ҩ�ԣ�����������ʹ�˻��ʡ���������ǿ�ߣ�ҩЧ���ԡ�����ҩ�����÷�����ҩ�����ˮ�����˺��£�pour yao in <����>������ҩ�ԣ�������Ů������������٣���Ϊ�����á����ϳ�ɢ�����÷�����ҩ�����ˮ�����˺��£�pour yao in <����>������ҩ�ԣ���ҩ��γ���϶�����������ǿ�ߣ�ҩЧ���ԡ�������ɢ�����÷����̷���eat san������ҩ�ԣ�Ϊ���Ŷ��Ž�ҩ���ɽ�ϳ�ɢ�����޶���֮����");
	set("value", 50);
	set("material", "paper");
	set("skill/name","poison");	// name of the skill
	set("skill/exp_required",50000);	// minimum combat experience required
	set("skill/jing_cost",20);	// jing cost every time study this
	set("skill/difficulty",25);	// the base int to learn this skill
	set("skill/max_skill",99);	// the maximum level you can learn
	set("skill/min_skill",50);  // the maximum level you can learn

 
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp