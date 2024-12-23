//qiankun_fake.h

//Sample for ITEM: ��Ǭ����Ų���ķ�
//coded by cat
//data: 2001-3-16

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqiankun_fake);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ƥ");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "��");
 	set("long", "����һ����Ƥ��һ����ë��һ��⻬��һ�ۿ���ȥ�ƺ�û��ʲô�ر�֮����������Ҫ�Ҹ�ʶ��֮�˰������һ�¡�");
	set("value",  50000 );
	set("material", "paper");

};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp