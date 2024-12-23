//jisidawu1.h

//Sample for room: �������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_jisidawu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");

	//add npcs into the room
	add_npc("pub_laojisi");
	
	add_door("������������", "������������", "����Ǽ������");

	set("long", "�����������ļ�����ݣ���Ϊ������������һ����̨��̨�ϰڷ���һ��������λ����������������֮������λ���ǽ�Ϲ��д����Ƥ���ϻ����λ��ƣ����Ǹ����ͼ�ڡ�һλ�ϼ�˾�������ڼ�̨ǰ������ȫ��ļ�˾���" );

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
