//fojing201.h

//Sample for ITEM: ��
//coded by Fisho
//data: 2000-11-20

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIfojing201);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char titles[][30] = {
//      "������",
//      "άĦ��",
//      "������",
//      "���Ͼ�",
        "�����پ�",
        "������;�",
        "������",
        "��վ�",
        "�����۶��ľ�",
	};

	set_name( titles[random(5)]);	//set item name

	set_weight(200);		//set item weight

	set("unit", "��");
	set("value", 500);
	set("long", "����һ��𾭡�");
	set("material", "paper");
	set("skill/name", "buddhism");
	set("skill/exp_required", 0l);
	set("skill/jing_cost", 20);
	set("skill/difficulty", 20);
	set("skill/max_skill",100 );
	
};
/**********************

int do_tear(string arg)
{
	object me, bible;
	object where;

	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}

	me = this_player();

	if ( arg == "hp" || arg == "shu" || arg == "book" )
	{
		bible = new(CLASS_D("shaolin")+"/obj/book-jiuyang");
		where = environment(me);
		message_vision("$N����ذ���˺��������ͻȻ�������Ʈ�����ҳ��Ƥֽ��\n",
			this_player());
		bible->move(file_name(where));
		destruct(this_object());
	}

	return 1;
}
****************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp