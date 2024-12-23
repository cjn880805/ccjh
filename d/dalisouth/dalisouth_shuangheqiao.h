//shuangheqiao.h

//Sample for room: ˫����
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_shuangheqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˫����");

	add_npc("pub_playboy");
	add_npc("pub_playboy");    // add by zdn 2001-07-13

	add_door("����Ǵ�·4", "����Ǵ�·4", "�����˫����");
	add_door("���������", "���������", "�����˫����");
	add_door("���������Ϫ�ذ�", "���������Ϫ�ذ�", "�����˫����");

	set("long", "����һ����·�ڣ�����������ʯ��������˫���ţ����ſ�������Ϫ�ϣ��ű����Ǵ���ǣ��ɴ���ȥ��ͨ���Ϸ���ϲ�ݡ����ڵȳ���Ĺٵ�����ȥ�Ĳ�·ͨ��������������Ϫ�ϰ����пɴ��廪¥��" );
	
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
