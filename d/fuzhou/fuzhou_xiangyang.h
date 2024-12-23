//xiangyang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRfuzhou_xiangyang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("pub_playboy");  // add by zdn 2001-07-13

	add_door("������", "������", "����������");
	add_door("�����ӻ���", "�����ӻ���", "����������");
	add_door("����������լ", "����������լ", "����������");

    set("long", "�����Ǹ��ݳ��������������һ���ưܵ�լ�ӡ�������һ���ӻ��̣�ר��Ů�˼��õĶ��������˲����Խ�ȥ��" );
	
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
