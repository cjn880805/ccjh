//yanxiadong.h

//Sample for room: ������ϼ��
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_yanxiadong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������ϼ��");
	
	add_npc("pub_daoke");             //add by zdn 2001-07-14


	add_door("����ɽ·5", "����ɽ·5", "������ϼ��");
	add_door("����ˮ�ֶ�", "����ˮ�ֶ�", "������ϼ��");

	set("long","��˵վ��ɽͷ���峿�ۿ�ɽ�����ƴ��̣��������������ϼ����ɫ�������ʳơ���ϼ�������������о����ġ��������͡��������������������ڵ���Ȼ��Ѩ���и�����ʯ�̡���������ɽ��·��������ȥ������" );
    

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
