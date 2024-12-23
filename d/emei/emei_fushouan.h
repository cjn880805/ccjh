//fushouan.h

//Sample for room:  ���Ҹ�����
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_fushouan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҹ�����");

	add_npc("pub_girldizi");
	add_npc("emei_zhen");
	

	add_door("������ˮ��", "������ˮ��", "���Ҹ�����");
	add_door("�������ĸ�", "�������ĸ�", "���Ҹ�����");

	set("long","����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ�о������������أ����������ڴ������������۾���ʫ����ӽ��̾����֪Ϧ�ա�������������������ٲ��䣬�ߴ�ʮ���ɡ�");
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
