//feilaifeng.h

//Sample for room: ���ݷ�����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_feilaifeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݷ�����");
	
	add_npc("pub_daoke");
	add_npc("pub_oldwoman");    //add by zdn 2001-07-14


	add_door("�������ֶ�", "�������ֶ�", "���ݷ�����");
	add_door("����������", "����������", "���ݷ�����");
	add_door("������ʯ���1", "������ʯ���1", "���ݷ�����");

	set("long","�������������շ塣������ɽС�������ߣ�ֻ��Ϫ����ʯ�ڼ����һ��̻��¶�أ�ϲЦ���������շ��Ա���һ��������ΰ�Ķ�����������������ɽ��·��С·���������������ߡ�" );

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
