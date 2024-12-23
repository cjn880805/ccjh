//wfdating.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_wfdating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("dali_jiading");
	add_npc("dali_gaoshengtai");
	add_npc("dali_zhuwanli");
	add_npc("dali_duanwuwei");
	add_npc("dali_duanyu");       //add by zdn 2001-07-20
	
	add_door("����Ƕ�", "����Ƕ�", "�������������");
	add_door("�������������", "�������������", "�������������");
	add_door("����������ʷ�", "����������ʷ�", "�������������");
	add_door("�������������", "�������������", "�������������");
	add_door("���������������", "���������������", "�������������");
	add_door("������������˾���", "������������˾���", "�������������");

	set("long", "���˴��������ۿ��Ǵ�����ֻ������һ�飬���ң�д�š������ʯ���ĸ����֣��������š���î���ʡ��ĸ�С�֣���������������ֻ���һʱҲ����������ࡣ�������������������˰칫֮�����������ʷ���������һ��ʯ��ͨ����լ��" );

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}

ROOM_END;
