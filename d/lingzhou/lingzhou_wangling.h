//wangling.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRLingZhou_wangling);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	//add_npc("pub_shiwushi");/////////////////////////

//	add_door("��������Ȫ", "��������Ȫ", "������������");
//	add_door("���ݳ���", "���ݳ���", "������������");

	set("long", "���������������ʵ۵���Ĺ��������������������Χ��ɽ�����������ǳ��ľ�����Χ�����˲��ɴ�أ����е������Ļʵ���Ԫ껵ĸ����Ե�������Ĺ��Ϊ��ΰ���������������Ƴ�������Ȼֱ���γ��Ե����ųƻʵۣ�������Ԫ껳��Ա�Ϊ������ڶ���������������Ĺ����쳣���");  
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
