//shuiledong.h

//Sample for room: ����ˮ�ֶ�
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_shuiledong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ˮ�ֶ�");
	
	add_npc("pub_playboy");
	add_npc("pub_girl1");                  //add by zdn 2001-07-14

	add_door("������ϼ��", "������ϼ��", "����ˮ�ֶ�");
	add_door("��������¤", "��������¤", "����ˮ�ֶ�");

	set("long","ˮ�ֶ����������ڣ���������й�ɽȪ��ʯ����ӿ����Ȫˮ�����ʯ����г�ö������С���Ȼ�����������������١���ʯ���־䡣���������кܶ�����ʯ����������ɽ��·�����ϱ㵽����ϼ����" );
    
    set("resource/water", 1);

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
