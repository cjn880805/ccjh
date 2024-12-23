//paper.h

//Sample for ITEM: ��ֽ
//coded by Fisho
//data: 2000-11-14

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIpaper);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ֽ");	//set item name

	set_weight(100);		//set item weight

	set("unit", "��");
	set("long", "��������ͨ����ֽ������������Ⱥд�����ѵļҳ��ţ�����д�ã����Ҹ�����˽ӡ������ߵĴ�æ���Ǵ����ˡ� ");
	set("value", 5000);
	set("material", "paper");

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp