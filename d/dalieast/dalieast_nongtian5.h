//nongtian5.h

//Sample for room: �����ũ��5
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_nongtian5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ũ��5");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_nongfu2");/////////////////////////
//	add_npc("animal_cow");


	add_door("����ǲ��۲�", "����ǲ��۲�", "�����ũ��5");
	add_door("����Ǹ���3", "����Ǹ���3", "�����ũ��5");

	set("long", "����һС����ͨ��ˮ�������Ϫ�����������ʮ�ַ��㡣Χ��ũ�����һƬƬɣ�֣������˲�ɣ�����ϣ���֯�൱���µ�˿֯Ʒ������������ӡ�" );
};

RESIDENT_END;
