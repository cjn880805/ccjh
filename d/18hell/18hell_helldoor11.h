//18hell_helldoor11.h

//Sample for room: ����֮��
//coded by sound
//data: 2001-11-1

//ROOM_BEGIN(CRFoShan_beidimiao);
YEWAIDOOR_BEGIN(CR18hell_helldoor11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name("����֮��11");

	add_npc("dy_master");

	CDoor * a = add_yewaidoor("west", 12, 20);
	CDoor * b = add_yewaidoor("north", 12, 20);
	CDoor * c = add_yewaidoor("east", 12, 20);
	CDoor * d = add_yewaidoor("south", 12, 20);

	a->set_name("ʮ�˵�������");
	b->set_name("ʮ�˵�������");
	c->set_name("ʮ�˵�������");
	d->set_name("ʮ�˵�������");

	set("long", "�������ʮ�˵�������ڣ���������������һ��ϣ����" );
	set("no_fight",  1);

};

YEWAIDOOR_END;