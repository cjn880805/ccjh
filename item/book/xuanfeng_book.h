//xuanfeng_book.h

//Sample for ITEM: ����ɨҶ�ȷ�
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIxuanfeng_book);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����ɨҶ�ȷ�");	//set item name

 	set_weight(500);		//set item weight

	set("unit", "��");
 	set("long", "��������ֽƬ������д�Ķ��������Ŀھ�Ҫּ��ȴ�ǻ�ҩʦ���ױʣ��ּ��پ�ͦ�Σ���һҶ������д����Ŀ���ǡ�����ɨҶ�ȷ������֡�");
	set("value",  100 );
	set("material", "paper");
	set("skill/name","xuanfeng_leg");	// name of the skill
	set("skill/exp_required",  1000);	// minimum combat experience required
	set("skill/jing_cost",   40);	// jing cost every time study this
	set("skill/difficulty", 20 );	// the base int to learn this skill
	set("skill/max_skill",  99);	// the maximum level you can learn
	set("skill/min_skill", 30 );  // the maximum level you can learn   
	

};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp